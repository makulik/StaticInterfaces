/**
 * @file DemoInterfaceImplB.hpp
 *
 * Contains the declaration of class DemoInterfaceImplB.
 */

#ifndef DEMOINTERFACEIMPLB_HPP_
#define DEMOINTERFACEIMPLB_HPP_

#include "IDemoInterface.hpp"

namespace Application
{
/**
 * Demonstrates an alternative class implementing the static interface IDemoInterface.
 */
class DemoInterfaceImplB
: public IDemoInterface
{
public:
	/**
	 * Constructor.
	 */
	DemoInterfaceImplB();
	/**
	 * Destructor.
	 */
	~DemoInterfaceImplB();

	/** Method implementation required by IDemoInterface. */
	void operation1();
	/** Method implementation required by IDemoInterface. */
	bool operator<(const DemoInterfaceImplB& rhs) const;
	/** Method implementation required by IDemoInterface. */
	void operation2(int a, bool b);
};
}
#endif /* DEMOINTERFACEIMPLB_HPP_ */
