#include "Peasant.h"
#include <iostream>

// constructors:
Peasant::Peasant() {
	//std::cout << "Default constructor for Peasant Class called" << std::endl;
	//throw std::logic_error("Empty constructor registered in Peasant class");
}

Peasant::Peasant(const std::string& name, int age, int productivity) : Person(name, age), productivity(productivity) {
	if (age > 110) {
		throw std::invalid_argument("Age cannot be greater than 110!");
	}
	if (productivity <= 0) {
		throw std::invalid_argument(" Productivity cannot be less or equal to 0!");
	}

	this->productivity = productivity;
}


// public destructor:
Peasant::~Peasant() {
	//std::cout << "The destructor for Peasant " << this->GetName() << " was called" << std::endl;
}



// Copy constructor:
Peasant::Peasant(const Peasant& peasantObject) : Peasant(peasantObject.name, peasantObject.age, peasantObject.productivity) {
	//std::cout << "Peasant " << GetName() << " - copy constr." << std::endl;
}

// Move constructor:
Peasant::Peasant(Peasant&& peasantObject) noexcept : Peasant(peasantObject.name, peasantObject.age, peasantObject.productivity) {
	//std::cout << "Peasant " << GetName() << " - move constr." << std::endl;
}


int Peasant::GetProductivity() const {
	return this->productivity;
}


void Peasant::Print() {
	Person::Print();
	std::cout << "Productivity: " << this->productivity << std::endl;
}



Peasant& Peasant::operator=(const Peasant& peasantObject) {
	if (this == &peasantObject) {
		return *this;
	}

	name = peasantObject.name;
	age = peasantObject.age;
	productivity = peasantObject.productivity;
	return *this;

}