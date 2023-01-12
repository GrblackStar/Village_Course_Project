#pragma once
#include <string>
#include <vector>
#include "Peasant.h"

class Village {
private:
	std::string name;
	std::string location;
	int resources;

	std::vector<Peasant> peasantList;

public:
	Village();
	Village(const std::string& name, const std::string& location);
	~Village();


	// copy:
	Village(const Village& villageObject);
	// move:
	Village(Village&& villageObject) noexcept;

	std::string getName() const { return name; }
	std::string getLocation() const { return location; }
	int GetResources() const;
	void SetResources(int newResources);

	// methods:
	// add peasant to the list:
	void AddPeasant(const Peasant& peasant);
	// pass a day: The method sums the productivity of the peasants of the village and adds it to the resources of the village. 
	// Return the resources for the day:
	int PassDay();
	// The method removes the first N number of peasants from the vector and returns them as a result. In case there are not 
	// enough peasants, return everyone.
	std::vector<Peasant>  KillPeasants(int count);
	void Print() const;

	// override '=' opperator:
	Village& operator=(const Village& villageObject);

};
