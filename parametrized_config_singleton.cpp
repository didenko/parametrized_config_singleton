// parametrized_config_singleton
//

#include "stdafx.h"
#include "Config.h"

int _tmain(int argc, _TCHAR* argv[])
{

  if (Config::instance() != nullptr) {
    std::cerr << "Returned a non-null pointer when called an uninitialized Config." << std::endl;
    return 1;
  }

  if (! Config::init("http://cnf.local/dev")) {
    std::cerr << "Failed to initialize Config for the first time." << std::endl;
    return 1;
  };

  if (Config::init("http://cnf.local/prod")) {
    std::cerr << "Improperly initialized Config for the second time." << std::endl;
    return 1;
  };

  std::cout << Config::instance()->val("Upstream") << std::endl;
	return 0;
}
