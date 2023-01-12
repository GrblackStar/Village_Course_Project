#include "Person.h"
#include <iostream>
#include <string>

// constructors:
Person::Person() {
	//std::cout << "Default constructor for Person Class called" << std::endl;
	//throw std::logic_error("Empty constructor registered in Person class");
}

Person::Person(const std::string& name, int age) : name(name), age(age) {
	if (name.length() < 3 || name.length() > 30) {
		throw std::invalid_argument("Name should be between 3 and 30 characters!");
	}
	if (age < 0) {
		throw std::invalid_argument(" Age should be 0 or positive!");
	}

	//std::cout << "Custom constructor for Person Class called" << std::endl;

	this->name = name;
	this->age = age;
}



// copy:
Person::Person(const Person& peasantObject) : Person(peasantObject.name, peasantObject.age) {
	//std::cout << "Person " << GetName() << " - copy constr." << std::endl;
}

// move:
Person::Person(Person&& peasantObject) noexcept : Person(peasantObject.name, peasantObject.age) {
	//std::cout << "Person " << GetName() << " - move constr." << std::endl;
}





// public destructor:
Person::~Person() {
	//std::cout << "The destructor for Person " << GetName() << " was called" << std::endl;
}


// getters:
std::string Person::GetName() const {
	return name;
}

int Person::GetAge() const {
	return age;
}


// print function:
void Person::Print() {
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Age: " << this->age << std::endl;
}