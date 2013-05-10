/*
 * Configuration.cpp
 *
 *  Created on: 30.10.2011
 *      Author: Admin
 */

#include "../Configuration.hpp"
using namespace Application;
using Application::Configuration;

Configuration::Configuration()
{
}

Configuration::~Configuration()
{
}

bool Configuration::init()
{
	demoInterfaceClient.init(&demoInterfaceImpl);
	return true;
}

int Configuration::run(int argc, char** argv)
{
	demoInterfaceClient.doSomething();
	return 0;
}
