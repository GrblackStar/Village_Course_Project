#include "Village.h"
#include <iostream>

// constructors:

Village::Village() {
	//std::cout << "Default constructor for Village Class called" << std::endl;
	//throw std::logic_error("Empty constructor registered in Village class");
}


Village::Village(const std::string& name, const std::string& location) : name(name), location(location), resources(0) {
	if (name.length() <= 2 || name.length() >= 40) {
		throw std::invalid_argument("Name should be between 2 and 40 characters!");
	}
	if (location.length() <= 3 || location.length() >= 45) {
		throw std::invalid_argument("Location should be between 3 and 45 characters!");
	}

	this->name = name;
	this->location = location;
	this->resources = resources;
}


// copy:
Village::Village(const Village& villageObject) : Village(villageObject.name, villageObject.location) {
	//std::cout << "Village copy constructor called" << std::endl;

}

// move:
Village::Village(Village&& villageObject) noexcept : Village(villageObject.name, villageObject.location) {
	//std::cout << "Village move constructor called" << std::endl;
}


// destructor:
Village::~Village() {
	//std::cout << "Village destructor constructor called" << std::endl;
}


/*
// getters:

std::string Village::GetName() const {
	return name;
}

std::string Village::GetLocation() const {
	return location;
}

std::vector<Peasant> Village::GetListPeasants() {
	return peasantList;
}
*/


int Village::GetResources() const {
	return resources;
}

void Village::SetResources(int newResources) {
	this->resources = newResources;
}



// methods:
void Village::AddPeasant(const Peasant& peasant) {
	peasantList.push_back(peasant);
}


int Village::PassDay() {
	// sum all the productivity and add it to the resources:
	int sumresources = 0;
	for (auto peasant : peasantList) {
		sumresources += peasant.GetProductivity();
	}
	resources += sumresources;
	return sumresources;
}

std::vector<Peasant> Village::KillPeasants(int count) {
	std::vector<Peasant> killedPeasants;
	if (count > peasantList.size())
	{
		killedPeasants = peasantList;
		peasantList.clear();
	}
	else
	{
		killedPeasants.insert(killedPeasants.begin(), peasantList.begin(), peasantList.begin() + count);
		peasantList.erase(peasantList.begin(), peasantList.begin() + count);
	}
	return killedPeasants;
}


void Village::Print() const {
	std::cout << "Village - " << name << '(' << location << ')' << std::endl;
	std::cout << "Resources - " << resources << std::endl;
	std::cout << "Peasants - " << peasantList.size() << std::endl;
	for (Peasant peasant : peasantList) {
		peasant.Print();
	}
}


Village& Village::operator=(const Village& villageObject) {
	if (this == &villageObject) {
		return *this;
	}
	name = villageObject.name;
	location = villageObject.location;
	resources = villageObject.resources;
	peasantList = villageObject.peasantList;
	return *this;
}