#include "stdafx.h"
#include "Config.h"

std::unique_ptr<Config> Config::cfg;
std::mutex Config::init_mutex;

void Config::init(std::string loc) {
  std::lock_guard<std::mutex> lock(init_mutex);
  if (cfg != nullptr) {
    throw std::logic_error("Improper duplicate Config init: " + loc);
  } else {
    cfg.reset(new Config(loc));
  };
};

Config& Config::instance() {
  if (cfg == nullptr) throw std::logic_error("Requested uninitialized Config");
  return *cfg.get();
}

Config::Config(std::string loc) : url(loc) {};

std::string Config::val(std::string key) {
  return key + " key requested at the location " + url;
}
