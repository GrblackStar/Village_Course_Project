#include "Soldier.h"

//std::string name, int age, int harm)


Soldier::Soldier(Peasant* peasantObject, Rebel* rebelObject)
	: Peasant(peasantObject->GetName(), peasantObject->GetAge(), peasantObject->GetProductivity()),
	Rebel(rebelObject->GetName(), rebelObject->GetAge(), rebelObject->GetHarm())
{ }

// the two methods need to be overriten, because they exist in both classes, so the compiler will get confused
std::string Soldier::GetName() {
	return Peasant::name;
	// we are taking only hte name from the peasant
	// alternitevely we could get the name from the rebel class
}

int Soldier::GetAge() {
	return Rebel::age;
	// we get the age from the rebel class, because it is more logical the soldier to be under 50 y.o.
}

int Soldier::GetHarm() {
	return Rebel::harm;
}
int Soldier::GetProductivity() {
	return Peasant::productivity;
}