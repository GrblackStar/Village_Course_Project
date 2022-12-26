#include "Village.h"
#include <iostream>

// constructors:
Village::Village() {
	std::cout << "Default constructor for Village Class called" << std::endl;
	throw std::logic_error("Empty constructor registered in Village class");
}

Village::Village(std::string name, std::string location, int resources, std::vector<Peasant> peasantList) {
	if (name.length() <= 2 || name.length() >= 40) {
		throw std::invalid_argument("Name should be between 2 and 40 characters!");
	}
	if (location.length() <= 3 || location.length() >= 45) {
		throw std::invalid_argument("Location should be between 3 and 45 characters!");
	}
	if (peasantList.size() == 0) {
		throw std::invalid_argument("You must have Peasants");
	}

	this->name = name;
	this->location = location;
	this->resources = resources;
	this->peasantList = peasantList;
}


// copy:
Village::Village(const Village& villageObject) : Village(villageObject.name, villageObject.location, villageObject.resources, villageObject.peasantList) {
	std::cout << "Village copy constructor called" << std::endl;
}

// move:
Village::Village(Village&& villageObject) noexcept : Village(villageObject.name, villageObject.location, villageObject.resources, villageObject.peasantList) {
	std::cout << "Village move constructor called" << std::endl;
}


// destructor:
Village::~Village() {
	std::cout << "Village destructor constructor called" << std::endl;
}



// getters:

std::string Village::GetName() const {
	return name;
}

std::string Village::GetLocation() const {
	return location;
}

int Village::GetResources() const {
	return resources;
}

std::vector<Peasant> Village::GetListPeasants() {
	return peasantList;
}




// methods:
void Village::AddPeasant(Peasant peasant) {

}

int Village::PassDay() {

}

std::vector<Peasant> Village::KillPeasants(int count) {

}

void Village::PrintVillage() const {
	std::cout << "printing village" << std::endl;
}
