#include <iostream>
#include "Model.h"
#include "Agent.h"
#include "Thug.h"
#include "Structure.h"
#include "Sim_object.h"

int main(int argc, char** argv)
{
	// std::cout << "Hello, World!" << std::endl;//testhere___
	Model::Get().run(argc, argv);
	return 0;
}
