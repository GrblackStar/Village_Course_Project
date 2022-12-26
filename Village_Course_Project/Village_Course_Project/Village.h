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
	Village(std::string name, std::string location, int resources, std::vector<Peasant> peasantList);
	~Village();


	// copy:
	Village(const Village& villageObject);
	// move:
	Village(Village&& villageObject) noexcept;


	// getters:
	std::string GetName() const;
	std::string GetLocation() const;
	int GetResources() const;
	std::vector<Peasant> GetListPeasants();


	// methods:
	void AddPeasant(Peasant peasant);
	int PassDay();
	std::vector<Peasant>  KillPeasants(int count);
	void PrintVillage() const;

};
