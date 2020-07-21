#include <opencv2/tracking.hpp>

#include "Detector.h"
#include "Model.h"

using std::string;
using std::vector;

int main() {
  const string video_file{"../data/hotdogs.mp4"};
  const string window_name{"Hotdog Detector"};
  const string net_classes_path{"../data/coco.names"};
  const string model_config_path{"../data/yolov3-tiny.cfg"};
  const string model_path{"../data/yolov3-tiny.weights"};

  auto detector = Detector(video_file);

  try {
    auto cap = detector.openVideo();
    auto model = Model(net_classes_path, model_config_path, model_path);
    cv::namedWindow(window_name, cv::WINDOW_NORMAL);

    while (true) {
      auto frame = detector.getFrame(cap);
      if (frame.empty()) break;

      cv::Mat input = cv::dnn::blobFromImage(
          frame, 1.0 / 255, cv::Size(416, 416), cv::Scalar(), true, false);
      model.setInput(input);

      vector<cv::Mat> outs;
      model.getOutput(outs);

      // Process network outs
      vector<cv::Rect> boxes;
      vector<int> class_ids;
      vector<float> confidences;
      for (size_t i{0}; i < outs.size(); ++i) {
        float* data = (float*)outs[i].data;
        for (size_t j{0}; j < outs[i].rows; ++j, data += outs[i].cols) {
          cv::Mat scores = outs[i].row(j).colRange(5, outs[i].cols);
          cv::Point classIdPoint;
          double confidence;
          cv::minMaxLoc(scores, 0, &confidence, 0, &classIdPoint);
          if (confidence >= 0.1) {
            int centerX = (int)(data[0] * frame.cols);
            int centerY = (int)(data[1] * frame.rows);
            int width = (int)(data[2] * frame.cols);
            int height = (int)(data[3] * frame.rows);
            int left = centerX - width / 2;
            int top = centerY - height / 2;

            class_ids.push_back(classIdPoint.x);
            confidences.push_back(static_cast<float>(confidence));
            boxes.push_back(cv::Rect(left, top, width, height));
          }
        }
      }

      // Draw network outs
      vector<int> indices;
      cv::dnn::NMSBoxes(boxes, confidences, 0.1, 0.05, indices);
      for (size_t i{0}; i < indices.size(); ++i) {
        int idx = indices[i];
        cv::Rect box = boxes[idx];
        string className = model.classes[class_ids[idx]];
        if (className.compare("hot dog")) continue;
        cv::putText(frame, "Hot dog", box.tl(), cv::FONT_HERSHEY_COMPLEX, 1.0,
                    cv::Scalar(255, 0, 0), 1, 16);
        cv::rectangle(frame, box, cv::Scalar(0, 0, 255), 1, 16, 0);
      }

      cv::imshow(window_name, frame);

      if (cv::waitKey(16) >= 0) break;
    }

  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  return 0;
}