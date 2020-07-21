#ifndef MODEL_H
#define MODEL_H

#include <opencv2/dnn.hpp>

class Model {
 public:
  Model(const std::string classes_path, const std::string model_config_path,
        const std::string model_path);

  void setInput(cv::Mat& input);
  void getOutput(std::vector<cv::Mat>& output);
  std::vector<std::string> classes;

 private:
  const std::string classes_path;
  const std::string model_config_path;
  const std::string model_path;
  std::vector<std::string> outs;
  cv::dnn::Net neuro_net;
};

#endif