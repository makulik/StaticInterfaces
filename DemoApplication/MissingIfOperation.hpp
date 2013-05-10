/**
 * @file MissingIfOperation.hpp
 *
 * Contains the declaration of class MissingIfOperation.
 */

#ifndef MISSINGIFOPERATION_HPP_
#define MISSINGIFOPERATION_HPP_

#include "IDemoInterface.hpp"

namespace Application
{

/**
 * Demonstrates a class that declares to implement IDemoInterface, but
 * misses to implement one of the declared static interface operations.
 */
class MissingIfOperation
: public IDemoInterface
{
public:
	/**
	 * Constructor.
	 */
	MissingIfOperation();
	/**
	 * Destructor.
	 */
	~MissingIfOperation();

	/** Method implementation required by IDemoInterface. */
	void operation1(void);
	/** Method implementation required by IDemoInterface. */
	void operation2(int,bool);

};
}

#endif /* MISSINGIFOPERATION_HPP_ */
