#include "Rebel.h"
#include <iostream>

// constructors:
Rebel::Rebel() {
	std::cout << "Default constructor for Rebel Class called" << std::endl;
	throw std::logic_error("Empty constructor registered in Rebel class");
}

Rebel::Rebel(std::string name, int age, int harm) : Person(name, age) {
	if (age > 50) {
		throw std::invalid_argument("Age should be less or equal to 50!");
	}
	if (harm <= 0) {
		throw std::invalid_argument("Harm should be greater than 0!");
	}

	this->harm = harm;
}


// public destructor:
Rebel::~Rebel() {
	std::cout << "The destructor for Rebel " << this->GetName() << " was called" << std::endl;
}



// Copy constructor:
Rebel::Rebel(const Rebel& rebelObject) : Rebel(rebelObject.name, rebelObject.age, rebelObject.harm) {
	std::cout << "Rebel " << GetName() << " - copy constr." << std::endl;
}

// Move constructor:
Rebel::Rebel(Rebel&& rebelObject) noexcept : Rebel(rebelObject.name, rebelObject.age, rebelObject.harm) {
	std::cout << "Rebel " << GetName() << " - move constr." << std::endl;
}


int Rebel::GetHarm() const {
	return harm;
}


void Rebel::PrintRebel() const {
	std::cout << "Name: " << this->GetName() << std::endl;
	std::cout << "Age: " << this->GetAge() << std::endl;
	std::cout << "Harm: " << this->GetHarm() << std::endl;
}
