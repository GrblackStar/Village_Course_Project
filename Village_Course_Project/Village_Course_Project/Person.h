#pragma once
//#include <string_view>
#include <string>

// Base class Person: cannot be instanciated
class Person {
protected:
	std::string name;
	int age;

public:
	Person();
	Person(const std::string& name, int age);
	virtual ~Person();

	// copy:
	Person(const Person& personObject);
	// move:
	Person(Person&& persontObject) noexcept;

	// getters:
	std::string GetName() const;
	int GetAge() const;

	// toString() --> just a pring method:
	virtual void Print();

};


