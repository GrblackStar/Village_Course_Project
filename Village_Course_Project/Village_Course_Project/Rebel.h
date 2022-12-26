#pragma once
#include <string>
#include "Person.h"

class Rebel : public Person {
protected:
	int harm;

public:
	Rebel();
	Rebel(std::string name, int age, int harm);
	~Rebel();

	// copy:
	Rebel(const Rebel& rebelObject);
	// move:
	Rebel(Rebel&& rebelObject) noexcept;

	// getters:
	int GetHarm() const;

	// toString() --> just a pring method:
	void PrintRebel() const;

};