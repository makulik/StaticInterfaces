/**
 * @file StaticInterfaceCheck.hpp
 * Contains helper macros to deal with static interfaces.
 */
#ifndef STATICINTERFACECHECK_HPP_
#define STATICINTERFACECHECK_HPP_

#include <static_isa.h>

/**
 * This macro helps to define a static function to provide a static interface check
 * against a particular interface.
 *
 * @param __T_param_name__ The name of the template parameter specifying the class to
 *                        check for implementation of the static interface.
 * @param __interface_name__
 *                        The name of the static interface to check for.
 */
#define MAKE_INTERFACE_CHECK(__T_param_name__,__interface_name__) \
	inline static void _CheckIsA##__interface_name__() { \
	   StaticConceptCheck::BoolError< StaticConceptCheck::StaticIsA<__T_param_name__,__interface_name__>::valid \
	            > __T_param_name__##_must_implement_##__interface_name__; \
	   (void)__T_param_name__##_must_implement_##__interface_name__; \
	}

/**
 * This macro implements a static interface check using a call to the static function
 * defined using the MAKE_INTERFACE_CHECK macro.
 *
 * @param __interface_name__
 *                        The name of the static interface to check for.
 */
#define DO_INTERFACE_CHECK(__interface_name__) \
	_CheckIsA##__interface_name__();

/**
 * This macro helps declaring a static 'pure' abstract method used with static polymorphism
 * implementation. The compiler will always bail out on this, as soon the method calling
 * this macro needs to be instantiated.
 *
 * @param __abstract_method_name__
 * 				 		  The name of the 'pure' abstract method.
 */
#define DECLARE_ABSTRACT_METHOD(__abstract_method_name__) \
	static StaticConceptCheck::BoolError<false> Illegal_instantiation_of_abstract_method__##__abstract_method_name__; \
	(void)Illegal_instantiation_of_abstract_method__##__abstract_method_name__;

#endif /* STATICINTERFACECHECK_HPP_ */
