/**
 * @file main.cpp
 *
 * Contains the demo applications main function definition.
 */

#include "../Configuration.hpp"
using namespace Application;

int main(int argc, char** argv)
{
	Configuration config;

	if(config.init())
	{
		return config.run(argc,argv);
	}

	return 1;
}
