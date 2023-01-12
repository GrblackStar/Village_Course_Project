# Village_Course_Project

Problem description:
Create a program that represents the growth of a village. The main functionalities are the grow of the village and it’s ability to get attacked by rebels. 

Class structure:
1.Person (base class, that cannot be instanciated)
 - Data: 
-> name (type string)
-> age (type int)
- Constructor parameters: string name, int age
- Behavior: include a function to print the members of the class

2.Village
 - Data: 
-> name (type string)
-> location (type string)
-> resources (type int)
-> peasantList (type std::vector<Peasant>)
- Constructor parameters: string name, string location
- Behavior: 
	-> void AddPeasant (const Peasant& peasant) 
		The method is used to add instances of class Peasant to the peasantList
	-> int PassDay () 
		The method sums the productivity of the peasants of the village and ads it to the resources of the village. Return the resources for the day
	-> std::vector<Peasant> KillPeasants (int count)
		The method removes the first N number of peasants from the vector and returns them as a result. In case there are not enough peasants, return everyone.
	-> include a function to print the members of the class

Child classes:
3.Peasant (inherits from class Person)
 - Data: 
-> name (type string)
-> age (type int)
-> productivity (type int)
- Constructor parameters: string name, int age, int productivity
- Behavior: include a function to print the members of the class

4.Rebel (inherits from class Person)
 - Data: 
-> name (type string)
-> age (type int)
-> harm(type int)
- Constructor parameters: string name, int age, int harm
- Behavior: include a function to print the members of the class

Business Logic:
The Controller class: the logic/functionality of the program will be written here
-> public string ProcessVillageCommand(std::list<string> args)
-> public string ProcessSettleCommand(std::list<string> args)
-> public string ProcessRebelCommand(std::list<string> args)
-> public string ProcessDayCommand(std::list<string> args)
-> public string ProcessAttackCommand(std::list<string> args)
-> public string ProcessInfoCommand(std::list<string> args)
-> public string ProcessEndCommand()
Explanation of the commands:
- Village command:
	-> creates a village and saves it fot later
	-> parameters: string name, string location
- Settle command:
-> creates a peasant and adds it to the village with the villageName
	-> parameters: string name, int age, int productivity, string villageName
- Rebel command:
-> creates a rebel and saves it for later
	-> parameters: string name, int age, int harm
- Day command:
	-> finds the village with the corresponding name and calls its PassDay() function
	->  parameters: string villageName
- Attack command:
	-> it takes the firs N rebels, where N is the first parameter of the function. After that it sums their harm and finds the village by name (that name is the second parameter of the function). After that it decreases the village’s resources with the summed harm of the rebels. Every 2 rebels kill 1 peasant, which means o call the KillPeasant function with a paramether (number of rebels / 2). if there are no rebels, the function doesn’t do anything 
->  parameters: int rebelCount, string villageName
- Info command:
	-> if the parameter is “Rebel”, print the information for all rebels. if the parameter is “Village”, print the information for all villages
->  parameters: string side
- End command:
	-> the command stops the program and returns the number of villages, the number of rebels and the number of attacks (how many times the Attack command has been called)
 Input and output:
Input:
-> read the lines one by one until receiving the “End” command
-> possible commands:
Village {name} {location}
Settle {name} {age} {productivity} {villageName}
Rebel {name} {age} {harm}
Day {villageName}
Attack {rebelCount} {villageName}
Info {side}
End
Output:
- Village command: when added successfully, print:  Created Village {villageName}!
- Settle command: when added successfully, print:  Settled Peasant {peasantName} in Village {villageName}!
- Rebel command: when added successfully, print:  Rebel {rebelName} joined the gang!
- Day command: when called, print:   Village {villageName} resource increased with {dailyResource}!
- Attack command: when called successfully, print:  Village {villageName} lost {takenResource} resources and {deadPeasants} peasants!
- Info command:
	-> when parameter is “Rebel”, print:  Rebels:
Name: {Rebel1.Name}
Age: {Rebel1.Age}
Harm: {Rebel1.Harm}
Name: {Rebel2.Name}
Age: {Rebel2.Age}
Harm: {Rebel2.Harm}
…
If there are no rebels, print: No Rebels

	-> when parameter is “Village”, print: 
Villages:
Village - {Village1.Name} ({Village1.Location})
Resources: {Village1.Resource}
Peasants: ({Village1.PeasantsCount})
Name: {Peasant1.Name}
Age: {Peasant1.Age}
Productivity: {Peasant1.Productivity}
Name: {Peasant2.Name}
Age: {Peasant2.Age}
...
Village - {Village2.Name} ({Village2.Location})
Resources: {Village2.Resource}
Peasants: ({Village2.PeasantsCount})
...

If there are no villages, print: No Villages

- End command: when called, print: Villages: {totalVillagesCount}
Rebels: {totalRebelsCount}
Attacks on Villages: {totalAttacksPerformed}
