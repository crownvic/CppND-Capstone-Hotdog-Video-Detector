#include "Model.h"

#include <fstream>

Model::Model(const std::string classes_path,
             const std::string model_config_path, const std::string model_path)
    : classes_path(classes_path),
      model_config_path(model_config_path),
      model_path(model_path) {
  neuro_net = cv::dnn::readNetFromDarknet(model_config_path, model_path);
  neuro_net.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
  neuro_net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);
  outs = neuro_net.getUnconnectedOutLayersNames();

  std::ifstream classes_file(classes_path);
  if (classes_file.is_open()) {
    std::string cls_name{};
    while (std::getline(classes_file, cls_name)) {
      classes.push_back(cls_name);
    }
  } else {
    throw std::runtime_error{"Can't open Coco classes file"};
  }
}

void Model::setInput(cv::Mat& input) { neuro_net.setInput(input); }

void Model::getOutput(std::vector<cv::Mat>& output) {
  neuro_net.forward(output, outs);
}