// parametrized_config_singleton
//

#include "stdafx.h"
#include "Config.h"

int _tmain(int argc, _TCHAR* argv[])
{

  try {
    std::cout << Config::instance().val("Upstream") << std::endl;
    std::cerr << "Did not trow an exception when called an uninitialized Config." << std::endl;
    return 1;
  }
  catch (std::logic_error e) {
    std::cout << "Properly thrown an error when called an uninitialized Config." << std::endl;
  }
  catch (...) {
    std::cerr << "Thrown an unexpected exception when called an uninitialized Config." << std::endl;
    return 1;
  }

  Config::init(
    "http://cnf.local/dev",
    [](std::string loc){ std::cout << "Duplicate Config init (" << loc << ")" << std::endl; }
  );

  Config::init(
    "http://cnf.local/prod",
    [](std::string loc){
      std::cout <<
        "Duplicate Config init (" << loc << ")" << std::endl;
  });

  std::cout << Config::instance().val("Upstream") << std::endl;
	return 0;
}

