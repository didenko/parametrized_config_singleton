#include "stdafx.h"
#include "Config.h"

std::shared_ptr<Config> Config::cfg;
std::mutex Config::init_mutex;

bool Config::init(std::string loc) {
  std::lock_guard<std::mutex> lock(init_mutex);
  if (cfg != nullptr) return false;
  cfg.reset(new Config(loc));
  return true;
};

std::shared_ptr<Config> Config::instance() {
  return cfg;
}

Config::Config(std::string loc) : url(loc) {};

std::string Config::val(std::string key) {
  return key + " key requested at the location " + url;
}
