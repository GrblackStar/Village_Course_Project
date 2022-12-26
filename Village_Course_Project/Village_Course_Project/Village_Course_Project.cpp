#include <iostream>
#include <string_view>
#include "Person.h"
#include "Peasant.h"
#include "Rebel.h"

int main()
{
    int ageInput = 0;
    std::string nameInput;
    int productivityInput = 0;

    std::cout << "Name: ";
    std::cin >> nameInput;
    std::cout << "Age: ";
    std::cin >> ageInput;
    std::cout << "Productivity: ";
    std::cin >> productivityInput;

    //Person person1(nameInput, ageInput);
    //std::cout << "Person1 name: " << person1.GetName() << std::endl;
    //std::cout << "Person1 age: " << person1.GetAge() << std::endl;
    //person1.Print();

    //Peasant peasant1(nameInput, ageInput, productivityInput);
    //peasant1.PrintPeasant();

    //Rebel rebel(nameInput, ageInput, productivityInput);
    //rebel.PrintRebel();


    
}









// explanations:
// using public inheritance  -->  like the inheritance in other languages:
    // public -> public
    // protected -> protected
    // private -> private



// Copy constructor:
    // The copy constructor is used to initialize the members of a newly created object by copying the members of an already existing object.
    // Copy constructor takes a reference to an object of the same class as an argument.
    // copying the actual data of the object to another object rather than making another object to point the already existing object in the heap


// Move constructor:
    // move semantics involves pointing to the already existing object in the memory
    // Move constructor moves the resources in the heap, i.e., unlike copy constructors 
    // which copy the data of the existing object and assigning it to the new object 
    // move constructor just makes the pointer of the declared object to point to the 
    // data of temporary object and nulls out the pointer of the temporary objects. 
    // Thus, move constructor prevents unnecessarily copying data in the memory.
