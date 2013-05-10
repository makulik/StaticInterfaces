/*
 * DemoInterfaceImplB.cpp
 *
 *  Created on: 27.10.2011
 *      Author: Admin
 */

#include "../DemoInterfaceImplB.hpp"

using namespace Application;
using Application::DemoInterfaceImplB;

DemoInterfaceImplB::DemoInterfaceImplB()
: IDemoInterface()
{
}

DemoInterfaceImplB::~DemoInterfaceImplB()
{
}

void DemoInterfaceImplB::operation1()
{

}

bool DemoInterfaceImplB::operator<(const DemoInterfaceImplB& rhs) const
{
	return false;
}

void DemoInterfaceImplB::operation2(int a, bool b)
{

}

