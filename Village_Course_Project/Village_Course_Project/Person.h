#pragma once
#include <string_view>
#include <string>


class Person {
protected:
	std::string name;
	int age;

public:
	Person();
	Person(std::string name, int age);
	~Person();

	// copy:
	Person(const Person& personObject);
	// move:
	Person(Person&& persontObject) noexcept;

	// getters:
	std::string GetName() const;
	int GetAge() const;

	// toString() --> just a pring method:
	void Print() const;

};


