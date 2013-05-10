/**
 * @file StaticInterfaces.hpp
 *
 */

/*! \mainpage StaticInterfaces Framework
 *
 * \section intro_sec 1 Introduction
 *
 * \subsection intro_motivatiovn_sec 1.1 Motivation
 *
 * Using traditional polymorphism with virtual inheritance has several drawbacks that may affect
 * a programs size and performance. Two aspects that are primarily important for small embedded
 * systems with very limited resources regarding the memory available (ROM for program code, RAM
 * for runtime data allocation).\n
 * The overhead introduced with the vtable implementation (which will be compiler specific) applies
 * to:
 *
 * \li Code size, as a vtable needs to be added for every class in a virtual inheritance tree.
 * \li Class instance size on stack or heap, as an additional pointer to the vtable needs to be
 *     specified additionally to the this pointer.
 * \li Performance, since a function call against a virtual function needs the extra lookup in the
 *     class vtable.
 *
 * For small embedded systems the system configuration regarding the components to use is usually
 * done anyway at compile time of the program. Often selection of target system specific
 * implementations regarding hardware or OS platform is made using \c #ifdef clauses scattered over
 * the implementation code, which can become quite a mess for maintenance and portability.
 *
 * C++ templates can help a lot to select configurable components of a specific system by providing
 * the component implementations as template parameters. However, this should also allow to specify
 * the component interfaces similarly to the traditional 'pure abstract class' approach, this includes:
 *
 * \li Check compliance of interfaces at compile time
 * \li Allow static polymorphism to dispatch method calls at compile time
 *
 * \subsection intro_cpp_static_interfaces 1.2 C++ static interfaces
 * A static C++ interface is at least defined by it's use within a template classes reference to a
 * specific accessible member of one of its template parameters. A compiler error will be generated,
 * if the template parameter type doesn't support the required member. But the error description will
 * rarely be pointing to this circumstance directly, and at the right place for the real error source.\n
 * So called C++ static concept checks can help to generate more readable error messages for required
 * attributes and operations of a template parameter class. For instance the STL uses some concept
 * checks.\n
 * The basic idea is to define a set of function pointers that specify the operation signatures of an
 * interface. A static instantiation of these function pointers forces the compiler to check the
 * existence of these so called 'constraints'. Doing so in a (static) method of a class, can be used to
 * check a template parameter, if all the function pointers can be instantiated with it.\n
 * There's an article that makes a proposal how to provide a small template framework to declare a
 * static interface and perform a compile time check against given template parameters with a client
 * template class: <a href="http://www.oonumerics.org/tmpw00/mcnamara.pdf">[Static interfaces in C++,
 * Brian McNamara and Yannis Smaragdakis]</a>
 *
 * The StaticInterfaces framework makes use of this proposal to provide a way to check and implement
 * static interface definitions in an easy and convenient way.
 *
 * \section using_sec 2. Using the StaticInterfaces framework
 * The declaration of a static interface with the StaticInterfaces framework is a bit different vs.
 * the 'pure abstract class' approach.
 *
 * \section using_sec 2 Using the StaticInterfaces framework
 * \subsection using_sec_declare 2.1 Declaring static interfaces
 * An interface is declared using its implementation of the 'check_structural' method
 * (see \ref declare_static_interface_step_1 "Step 1" and \ref declare_static_interface_step_2 "Step 2").
 *
 * Additionally the following helper classes should be implemented along the interface
 * declaration:
 * \li An interface proxy class for use of the interface in client template classes
 * (see \ref declare_static_interface_step_3 "Step 3"
 * , \ref declare_static_interface_step_3_1 "Step 3.1"
 * , \ref declare_static_interface_step_3_2 "Step 3.2"
 * , \ref declare_static_interface_step_3_3 "Step 3.3"
 * )
 * \li An abstract interface implementation class for use as base class for an interface implementation
 * (see \ref declare_static_interface_step_4 "Step 4"
 * , \ref declare_static_interface_step_4_1 "Step 4.1"
 * , \ref declare_static_interface_step_4_2 "Step 4.2"
 * )
 *
 * \subsection using_sec_declare 2.2 Referring to static interfaces
 */
#ifndef STATICINTERFACES_HPP_
#define STATICINTERFACES_HPP_


#endif /* STATICINTERFACES_HPP_ */
