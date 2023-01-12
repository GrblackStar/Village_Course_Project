#pragma once

#include "Peasant.h"
#include "Rebel.h"

// this class inherits from both the peasant and the rebel class
// it takes the harm from the rebel and the productivity from the peasant

class Soldier : public Peasant, public Rebel {
private:
	Soldier();

public:
	Soldier(Peasant* peasantObject, Rebel* rebelObject);

	std::string GetName();
	int GetAge();
	int GetHarm();
	int GetProductivity();
};