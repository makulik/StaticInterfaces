/**
 * @file DemoInterfaceImplA.hpp
 *
 * Contains the declaration of class DemoInterfaceImplA.
 */

#ifndef DEMOINTERFACEIMPLA_HPP_
#define DEMOINTERFACEIMPLA_HPP_

#include "IDemoInterface.hpp"

namespace Application
{

/**
 * Demonstrates a class implementing the static interface IDemoInterface.
 * @anchor declare_static_interface_step_4
 * @details (Step 5) Implement a class specifying conformance to IDemoInterface by inheritance.
 */
class DemoInterfaceImplA
: public IDemoInterfaceImpl<DemoInterfaceImplA>
, public IDemoInterface
{
	friend class IDemoInterfaceImpl<DemoInterfaceImplA>;
public:
	/**
	 * Constructor.
	 */
	DemoInterfaceImplA();
	/**
	 * Destructor.
	 */
	~DemoInterfaceImplA();

protected:
	/** Method implementation required by IDemoInterfaceImpl. */
	void operation1_Impl();
	/** Method implementation required by IDemoInterfaceImpl. */
	bool operatorLess_Impl(const DemoInterfaceImplA& rhs) const;
	/** Method implementation required by IDemoInterfaceImpl. */
	void operation2_Impl(int a, bool b);
};
}
#endif /* DEMOINTERFACEIMPLA_HPP_ */
