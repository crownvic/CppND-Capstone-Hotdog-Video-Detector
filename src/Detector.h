#ifndef DETECTOR_H
#define DETECTOR_H

#include <opencv2/opencv.hpp>

class Detector {
 public:
  Detector(const std::string path) : file_path{path} {}

  cv::VideoCapture openVideo();
  cv::Mat getFrame(cv::VideoCapture& capture);

 private:
  const std::string file_path;
};

#endif