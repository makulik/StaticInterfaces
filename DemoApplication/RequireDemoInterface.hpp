/*
 * RequireDemoInterface.hpp
 *
 *  Created on: 27.10.2011
 *      Author: Admin
 */

#ifndef REQUIREDEMOINTERFACE_HPP_
#define REQUIREDEMOINTERFACE_HPP_

#include "IDemoInterface.hpp"

namespace Application
{
/**
 * Demonstrates a static interface independent base class for a client of a
 * static interface.
 */
class RequireDemoInterfaceBase
{
public:
	/**
	 * Constructor.
	 */
	RequireDemoInterfaceBase();
	/**
	 * Destructor.
	 */
	~RequireDemoInterfaceBase();

protected:
	/**
	 * A method that can be used by the inheriting classes.
	 */
	void doSthIndependentOfInterface();
};

/**
 * Demonstrates a client class, that uses an implementation of IDemoInterface
 *
 * @tparam DemoInterfaceImpl The implementation of IDemoInterface to use.
 * @anchor declare_static_interface_step_5
 * @details (Step 5) Define a client class tat refers to IDemoInterface
 */
template<class DemoInterfaceImpl>
class RequireDemoInterface
: public RequireDemoInterfaceBase
{
public:
	/**
	 * Defines the type of the IDemoInterface implementation.
	 * @anchor declare_static_interface_step_5_1
	 * @details (Step 5.1) Define a typedef for the intended implementor of IDemoInterface
	 */
	typedef DemoInterfaceImpl DI;

	/**
	 * Constructor.
	 */
	RequireDemoInterface() {}
	/**
	 * Destructor.
	 */
	~RequireDemoInterface() {}

	/**
	 * Initializes the client class with a pointer to a valid implementation
	 * of IDemoInterface.
	 *
	 * @param argDemoInterface A pointer to an instance of IDemoInterface.
	 * @anchor declare_static_interface_step_5_2
	 * @details (Step 5.2) Define an operation to initialize the client class with the particular
	 *          implementation of IDemoInterface
	 */
	void init(DI* argDemoInterface)
	{
		pDemoInterface = argDemoInterface;
	}

	void doSomething();
private:
	DI* pDemoInterface;

	/**
	 * @anchor declare_static_interface_step_5_3
	 * (Step 5.3) Use IDemoInterfaceProxy to access IDemoInterface
	 */
	void doSthDependentOfInterface()
	{
		// Use the proxy definition to make calls against the interface implementation
		IDemoInterfaceProxy<DI> proxy(pDemoInterface);
		proxy.operation2(42,false);
	}

};

template<class DemoInterfaceImpl>
void RequireDemoInterface<DemoInterfaceImpl>::doSomething()
{
	doSthDependentOfInterface();
	doSthIndependentOfInterface();
}
}
#endif /* REQUIREDEMOINTERFACE_HPP_ */
