#include <iostream>
#include <string>
#include <sstream>

#include "Person.h"
#include "Peasant.h"
#include "Rebel.h"
#include "Controller.h"


int main()
{
    // Create an instance of the controller
    Controller controller;

    // Read lines of input until the "End" command is encountered
    std::string line;
    while (std::getline(std::cin, line))
    {
        // Split the line into space-separated tokens
        std::istringstream iss(line);
        std::vector<std::string> lineArguments{ std::istream_iterator<std::string>{iss},std::istream_iterator<std::string>{} };

        // Extract the command and arguments
        std::string command = lineArguments.front();
        lineArguments.erase(lineArguments.begin());
        std::list<std::string> args(lineArguments.begin(), lineArguments.end());

        // Execute the command
        if (command == "Village")
        {
            std::cout << controller.ProcessVillageCommand(args) << std::endl;
        }
        else if (command == "Settle")
        {
            std::cout << controller.ProcessSettleCommand(args) << std::endl;
        }
        else if (command == "Rebel")
        {
            std::cout << controller.ProcessRebelCommand(args) << std::endl;
        }
        else if (command == "Day")
        {
            std::cout << controller.ProcessDayCommand(args) << std::endl;
        }
        else if (command == "Attack")
        {
            std::cout << controller.ProcessAttackCommand(args) << std::endl;
        }
        else if (command == "Info")
        {
            std::cout << controller.ProcessInfoCommand(args) << std::endl;
        }
        else if (command == "End")
        {
            std::cout << controller.ProcessEndCommand() << std::endl;
            break;
        }
    }
    
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


// Virtual keyword:
// The keyword virtual is used in the Person class in the print() method to indicate that this method may be overridden in derived classes.
// This is known as polymorphism in object - oriented programming.Using virtual allows the program to determine the correct version of the 
// method to call at runtime, based on the actual type of the object, rather than the type of the reference or pointer used to call the method.
// Without the virtual keyword, the program would always call the version of the method defined in the base class.