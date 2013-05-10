/**
 * @file Configuration.hpp
 *
 * Contains the declaration of class Configuration.
 */

#ifndef CONFIGURATION_HPP_
#define CONFIGURATION_HPP_
#include "RequireDemoInterface.hpp"

// Choose the configuration to use here
#define CONFIG_A
// #define CONFIG_B
// #define CONFIG_MISSINGIFOPERATION
// #define CONFIG_MISSINGINTERFACE

#if defined(CONFIG_A)
#include "DemoInterfaceImplA.hpp"
#elif defined(CONFIG_B)
#include "DemoInterfaceImplB.hpp"
#elif defined(CONFIG_MISSINGIFOPERATION)
#include "MissingIfOperation.hpp"
#elif defined(CONFIG_MISSINGINTERFACE)
#include "MissingInterface.hpp"
#endif

/**
 * @namespace Application
 * @brief Demonstrates the usage of the StaticInterfaces framework.
 */
namespace Application
{
/**
 * This class is used to instantiate a particular implementation of a static interface
 * and to configure a client class with this implementation.
 */
class Configuration
{
public:
	/**
	 * Constructor.
	 */
	Configuration();
	/**
	 * Destructor.
	 */
	~Configuration();

	/**
	 * Initializes the instantiated classes.
	 * @return
	 */
	bool init();

	/**
	 * Runs the configured application.
	 */
	int run(int argc, char** argv);

private:

#if defined(CONFIG_A)
	typedef Application::DemoInterfaceImplA DemoInterfaceImpl;
#elif defined(CONFIG_B)
	typedef Application::DemoInterfaceImplB DemoInterfaceImpl;
#elif defined(CONFIG_MISSINGIFOPERATION)
	typedef Application::MissingIfOperation DemoInterfaceImpl;
#elif defined(CONFIG_MISSINGINTERFACE)
	typedef Application::MissingInterface DemoInterfaceImpl;
#endif

	DemoInterfaceImpl demoInterfaceImpl;
	RequireDemoInterface<DemoInterfaceImpl> demoInterfaceClient;
};
}
#endif /* CONFIGURATION_HPP_ */
