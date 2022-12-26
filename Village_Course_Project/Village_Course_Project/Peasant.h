#pragma once
#include <string>
#include "Person.h"

class Peasant : public Person {
protected:
	int productivity;

public:
	Peasant();
	Peasant(std::string name, int age, int productivity);
	~Peasant();

	// copy:
	Peasant(const Peasant& peasantObject);
	// move:
	Peasant(Peasant&& peasantObject) noexcept;

	// getters:
	int GetProductivity() const;

	// toString() --> just a pring method:
	void PrintPeasant() const;

};
