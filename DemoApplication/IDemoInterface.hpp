/**
 * @file IDemoInterface.hpp
 * Contains the declaration of the IDemoInterface static interface
 */
#ifndef IDEMOINTERFACE_HPP_
#define IDEMOINTERFACE_HPP_

#include "StaticInterfaceCheck.hpp"

namespace Application
{
/**
 * @anchor declare_static_interface_step_1
 * (Step 1) Declare a static concept check for the IDemoInterface static interface
 */
struct IDemoInterface
{

	/**
	 * Needed by static_isa.h
	 */
	MAKE_TRAITS;

	/**
	 * @anchor declare_static_interface_step_2
	 * (Step 2) Declares operation names and signatures for the static interface IDemoInterface
	 * @note The name 'check_structural' is required by static_isa.h
	 * @tparam Self Used by StaticConceptCheck::StaticIsA To bind this type to the
	 *         check_structural method.
	 */
	template<class Self> void check_structural(Self)
	{
		// Declare a function pointer on the left hand side and the operation name reference
		// on the right hand side for each operation of the static interface

		void (Self::*op1)(void) = &Self::operation1;
		bool (Self::*op2)(const Self&) const = &Self::operator<;
		void (Self::*op3)(int,bool) = &Self::operation2;
		(void)op1; // Suppress compiler warnings about unused vaiables
		(void)op2; // ...
	    (void)op3;
	}

protected:
	/**
	 * Define a protected destructor, to prevent direct instantiation (this makes
	 * IDemoInterface abstract).
	 */
	~IDemoInterface() {}
};


/**
 * @anchor declare_static_interface_step_3
 * (Step 3) Declare a proxy class to check correct implementation of the interface and to make the use
 * of the static interface IDemoInterface reference easier (e.g. with IDE support for operation
 * calls).
 *
 * @anchor declare_static_interface_step_3_1
 * (Step 3.1) Implement a static check method for IDemoInterface
 * @code
 * ...
 *     MAKE_INTERFACE_CHECK(T,IDemoInterface);
 * ...
 * @endcode
 *
 * @tparam T Specifies the type implementing the static interface IDemoInterface
 */
template<class T>
class IDemoInterfaceProxy
{
	MAKE_INTERFACE_CHECK(T,IDemoInterface);

public:
	/**
	 * @anchor declare_static_interface_step_3_2
	 * (Step 3.2) Declare a constructor that takes a reference to an implementation of the static
	 * interface IDemoInterface.
	 *
	 * @param argImpl A pointer to a class instance implementing the
	 *                static interface IDemoInterface
	 */
	IDemoInterfaceProxy(T* argImpl)
	: pImpl(argImpl)
	{
		// Call the static interface check as early as possible
		DO_INTERFACE_CHECK(IDemoInterface);
	}

	/**
	 * @defgroup interface_proxy_op Define interface proxy operations
	 * @anchor declare_static_interface_step_3_3
	 * @details (Step 3.3) Define operations that delegate to the implementation reference
	 */
	/**
	 * @ingroup interface_proxy_op
	 * @ref declare_static_interface_step_3_3 "(Step 3.3)"
	 */
	inline void operation1(void)
	{
		pImpl->operation1();
	}
	/**
	 * @ingroup interface_proxy_op
	 * @ref declare_static_interface_step_3_3 "(Step 3.3)"
	 */
	inline bool operator<(const T& rhs) const
	{
		return *pImpl < rhs;
	}
	/**
	 * @ingroup interface_proxy_op
	 * @ref declare_static_interface_step_3_3 "(Step 3.3)"
	 */
	inline void operation2(int par1,bool par2)
	{
		pImpl->operation2(par1,par2);
	}

private:
	/**
	 * Holds the reference to the implementation of the static IDemoInterface
	 */
	T* pImpl;

};

/**
 * @anchor declare_static_interface_step_4
 * (Step 4) Declare an abstract implementation class to implement the static interface and to make static polymorphism
 * implementation for the static interface IDemoInterface reference easier.
 *
 * @anchor declare_static_interface_step_4_1
 * (Step 4.1) Implement the operations required for IDemoInterface by delegating the calls to statically polymorphic
 * methods.
 *
 * @anchor declare_static_interface_step_4_2
 * (Step 4.2) Declare statically polymorphic methods as abstract using the DECLARE_ABSTRACT_METHOD macro.
 * @tparam T Specifies the type finally implementing the static interface IDemoInterface
 */
template<class T>
class IDemoInterfaceImpl
{
public:
	/**
	 * @ingroup interface_impl_op
	 * @ref declare_static_interface_step_4_1 "(Step 4.1)"
	 */
	inline void operation1(void)
	{
		static_cast<T*>(this)->operation1_Impl();
	}
	/**
	 * @ingroup interface_impl_op
	 * @ref declare_static_interface_step_4_1 "(Step 4.1)"
	 */
	inline bool operator<(const T& rhs) const
	{
		return static_cast<const T*>(this)->operatorLess_Impl(rhs);
	}
	/**
	 * @ingroup interface_impl_op
	 * @ref declare_static_interface_step_4_1 "(Step 4.1)"
	 */
	inline void operation2(int par1,bool par2)
	{
		static_cast<T*>(this)->operation2_Impl(par1,par2);
	}

protected:
	/**
	 * @ingroup interface_impl_op
	 * @ref declare_static_interface_step_4_2 "(Step 4.2)"
	 * Provides a statically overidable abstract method for the implementation of operation1.
	 */
	inline void operation1_Impl(void)
	{
		DECLARE_ABSTRACT_METHOD(operation1_Impl);
	}
	/**
	 * @ingroup interface_impl_op
	 * @ref declare_static_interface_step_4_2 "(Step 4.2)"
	 * Provides a statically overidable abstract method for the implementation of operator<.
	 */
	inline bool operatorLess_Impl(const T& rhs) const
	{
		DECLARE_ABSTRACT_METHOD(operatorLess_Impl);
		return false;
	}
	/**
	 * @ingroup interface_impl_op
	 * @ref declare_static_interface_step_4_2 "(Step 4.2)"
	 * Provides a statically overidable abstract method for the implementation of operator<.
	 */
	inline void operation2_Impl(int par1,bool par2)
	{
		DECLARE_ABSTRACT_METHOD(operatorLess_Impl);
	}

};
}

#endif /* IDEMOINTERFACE_HPP_ */
