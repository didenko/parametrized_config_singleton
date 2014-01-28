#pragma once


class Config {

public:

  static bool init(std::string loc);
  static std::shared_ptr<Config> instance();

private:
  static std::shared_ptr<Config> cfg;
  static std::mutex init_mutex;

  std::string url;
  
  Config(std::string loc);
  Config(const Config& src);              // not implemented
  Config& operator=(const Config& right); // not implemented

public:
  std::string val(std::string key);
};
