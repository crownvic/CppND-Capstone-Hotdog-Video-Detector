#include "Detector.h"

#include "Model.h"

cv::VideoCapture Detector::openVideo() {
  cv::VideoCapture cap{file_path};
  if (!cap.isOpened()) {
    throw std::runtime_error{"Can't open a video file."};
  }
  return cap;
}

cv::Mat Detector::getFrame(cv::VideoCapture& capture) {
  cv::Mat frame;
  capture >> frame;
  return frame;
}