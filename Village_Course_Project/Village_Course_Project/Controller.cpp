#include "Controller.h"

Controller::Controller() : attacks(0) {}

std::string Controller::ProcessVillageCommand(std::list<std::string>& args) {
    if (args.size() != 2)
    {
        return "";
    }

    // Extract the name and location from the arguments
    std::string name = args.front();
    args.pop_front();
    std::string location = args.front();

    // Create a new village and add it to the map
    Village village(name, location);
    villages[name] = village;

    return ">>>>>>>>>>  Created Village  " + name;
}

std::string Controller::ProcessSettleCommand(std::list<std::string>& args) {
    // Check that there are the correct number of arguments
    if (args.size() != 4)
    {
        return "";
    }

    // Extract the name, age, productivity, and village name from the arguments
    std::string name = args.front();
    args.pop_front();
    int age = std::stoi(args.front());
    args.pop_front();
    int productivity = std::stoi(args.front());
    args.pop_front();
    std::string villageName = args.front();

    // Check that the village exists
    if (villages.find(villageName) == villages.end())
    {
        return "";
    }

    // Create a new peasant and add it to the village
    Peasant peasant(name, age, productivity);
    villages[villageName].AddPeasant(peasant);

    return ">>>>>>>>   Settled Peasant " + name + " in Village " + villageName;
}

std::string Controller::ProcessRebelCommand(std::list<std::string>& args) {
    // Check that there are the correct number of arguments
    if (args.size() != 3)
    {
        return "";
    }

    // Extract the name, age, and harm from the arguments
    std::string name = args.front();
    args.pop_front();
    int age = std::stoi(args.front());
    args.pop_front();
    int harm = std::stoi(args.front());

    // Create a new rebel and add it to the list
    Rebel rebel(name, age, harm);
    rebels.push_back(rebel);

    return ">>>>>>>>>>>   Rebel " + name + " joined the gang!";
}

std::string Controller::ProcessDayCommand(std::list<std::string>& args) {
    // Check that there is the correct number of arguments
    if (args.size() != 1)
    {
        return "";
    }

    // Extract the village name from the arguments
    std::string villageName = args.front();

    // Check that the village exists
    if (villages.find(villageName) == villages.end())
    {
        return "Error: Village " + villageName + " does not exist";
    }

    // Pass a day in the village and get the resources for the day
    int dayresources = villages[villageName].PassDay();

    return ">>>>>>>>>    Village " + villageName + "resource increased with " + std::to_string(dayresources);
}

std::string Controller::ProcessAttackCommand(std::list<std::string>& args) {
    // Check that there are the correct number of arguments
    if (args.size() != 2)
    {
        return "";
    }

    // Extract the rebel count and village name from the arguments
    int rebelCount = std::stoi(args.front()); 
    args.pop_front();
    std::string villageName = args.front(); 
    args.pop_front();

    // Check that the village exists
    if (villages.find(villageName) == villages.end())
    {
        return "";
    }

    // Check that there are enough rebels to attack
    if ((int)rebels.size() <= 0) {
        return ">>>>>>>>>>   No rebels to perform raid...";
    }
    int totalharm = 0;
    for (int i = 0; i < rebelCount; i++) {
        totalharm += rebels[i].GetHarm();
    }

    // increasing the attacks:
    attacks++;

    // killing peasants:
    int peasantCount = rebelCount / 2;
    villages[villageName].KillPeasants(peasantCount);
    villages[villageName].SetResources((villages[villageName].GetResources()) - totalharm);
    return ">>>>>>>>>>>    Village " + villageName + " lost " + std::to_string(totalharm) + " resources and " + std::to_string(peasantCount) + " peasants!";
}

std::string Controller::ProcessInfoCommand(std::list<std::string>& args) {
    std::string side = args.front(); args.pop_front();
    if (side == "Rebel") {
        if (rebels.size() <= 0) {
            return ">>>>>>>>>>>    No Rebels";
        }
        std::cout << "Rebels: " << std::endl;
        for (Rebel rebel : rebels) {
            rebel.Print();
        }
    }
    else if (side == "Village") {
        std::cout << "Villages: " << std::endl;
        if (villages.size() <= 0) {
            return ">>>>>>>>>>>    No Villages";
        }
        for (auto village : villages) {
            village.second.Print();
        }
    }

    else {
        return "";
    }
    return "";
}

std::string Controller::ProcessEndCommand() {
    std::cout << "Villages count: " << villages.size() << std::endl;
    std::cout << "Rebels count: " << rebels.size() << std::endl;
    std::cout << "Attacks count: " << attacks << std::endl;
    return "Program ended";
}




