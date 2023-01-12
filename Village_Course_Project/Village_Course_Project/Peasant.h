#pragma once
#include <string>
#include "Person.h"

class Peasant : public Person {
protected:
	int productivity;

public:
	// when we initialize our own constructor, the compiler no longer will generate a default one
	// if we still want to create objects with an empty constructor, we must declare one as default:
	Peasant();
	Peasant(const std::string& name, int age, int productivity);
	~Peasant();

	// copy:
	Peasant(const Peasant& peasantObject);
	// move:
	Peasant(Peasant&& peasantObject) noexcept;

	// getters:
	int GetProductivity() const;

	// toString() --> just a print method:
	void Print() override;

	// override '=' opperator:
	Peasant& operator=(const Peasant& peasantObject);

};
