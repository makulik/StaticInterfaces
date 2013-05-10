/*
 * DemoInterfaceImplA.cpp
 *
 *  Created on: 27.10.2011
 *      Author: Admin
 */

#include "../DemoInterfaceImplA.hpp"

using namespace Application;
using Application::DemoInterfaceImplA;

DemoInterfaceImplA::DemoInterfaceImplA()
: IDemoInterface()
{
}

DemoInterfaceImplA::~DemoInterfaceImplA()
{
}

void DemoInterfaceImplA::operation1_Impl()
{

}

bool DemoInterfaceImplA::operatorLess_Impl(const DemoInterfaceImplA& rhs) const
{
	return false;
}

void DemoInterfaceImplA::operation2_Impl(int a, bool b)
{

}

