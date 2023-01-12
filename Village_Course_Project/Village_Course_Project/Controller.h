#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <map>

#include "Person.h"
#include "Peasant.h"
#include "Rebel.h"
#include "Village.h"

// the class, that has all the methods 
class Controller {
private:
    std::map<std::string, Village> villages;
    std::vector<Rebel> rebels;
    int attacks;

public:
    // empty constructor with default zero attacks:
    Controller();

    // Processes the "Village" command
    // creates a village and saves it to the system
    std::string ProcessVillageCommand(std::list<std::string>& args);

    // Processes the "Settle" command
    // creates a peasant and adds it to the village with the villageName
    std::string ProcessSettleCommand(std::list<std::string>& args);

    // Processes the "Rebel" command
    // creates a rebel and saves it for later
    std::string ProcessRebelCommand(std::list<std::string>& args);

    // Processes the "Day" command
    // finds the village with the corresponding name and calls its PassDay() function
    std::string ProcessDayCommand(std::list<std::string>& args);

    // Processes the "Attack" command
    // it takes the firs N rebels, where N is the first parameter of the function. 
    // After that it sums their harm and finds the village by name (that name is the 
    // second parameter of the function). After that it decreases the village’s 
    // resources with the summed harm of the rebels. Every 2 rebels kill 1 peasant, 
    // which means o call the KillPeasant function with a paramether (number of rebels / 2). 
    // if there are no rebels, the function doesn’t do anything
    std::string ProcessAttackCommand(std::list<std::string>& args);

    // Process the Info command
    // if the parameter is “Rebel”, print the information for all rebels. if the parameter is “Village”, 
    // print the information for all villages
    std::string ProcessInfoCommand(std::list<std::string>& args);

    // Process the "End" command:
    // the command stops the program and returns the number of villages, the number of rebels and the 
    // number of attacks (how many times the Attack command has been called)
    std::string ProcessEndCommand();


};
