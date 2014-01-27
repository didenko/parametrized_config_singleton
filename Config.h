#pragma once


class Config {

public:
  typedef std::function<void(std::string)> DupInitCB;

  static void init(std::string loc, DupInitCB err_cb);
  static Config& instance();

private:
  static std::unique_ptr<Config> cfg;
  static std::mutex init_mutex;

  std::string url;
  
  Config(std::string loc);
  Config(const Config& src);              // not implemented
  Config& operator=(const Config& right); // not implemented

public:
  std::string val(std::string key);
};
