#pragma once
#include <iostream>
#include "String.h"
#include "Vector.h"
#include "TicketSystem.h"

bool isOpened = false;

class Terminal {

	String command_name;
	Vector<String> arguments;


	void clear_command();
public:
	void waiting_for_command();
	void start_session();
	template<typename T> void execute_command(T& object, void (T::* f)(Vector<String>));

	void setCommand(const String&);
	String get_command_name() const;
};



String Terminal::get_command_name() const {
	return command_name;
}


void Terminal::waiting_for_command() {
	String command;
	cin >> command;

	setCommand(command);

}


//Starting current session
void Terminal::start_session() {
	TicketSystem obj;
	Terminal T;

	obj.welcomeWindow();

	while (true) {
		T.waiting_for_command();

		//Open function
		if (T.get_command_name() == "open" && isOpened == false) {
			T.execute_command(obj, &TicketSystem::menuOpen);
			isOpened = true;
		}
		//Open function
		else if (T.get_command_name() == "open" && isOpened) {
			std::cout << "File already opened" << std::endl;
		}

		//Close function
		else if (T.get_command_name() == "close") {
			T.execute_command(obj, &TicketSystem::menuClose);
			isOpened = false;
		}

		//Save function
		else if (T.get_command_name() == "save") {
			T.execute_command(obj, &TicketSystem::menuSave);
		}

		//Saveas function
		else if (T.get_command_name() == "saveas") {
			T.execute_command(obj, &TicketSystem::menuSaveAs);
		}

		//Help function
		else if (T.get_command_name() == "help" && isOpened) {
			T.execute_command(obj, &TicketSystem::menuHelp);
		}

		//Exit function
		else if (T.get_command_name() == "exit") {
			std::cout << "Exiting the program..." << std::endl;
			break;
		}

		//Adding Hall
		else if (T.get_command_name() == "addhall" && isOpened) {
			T.execute_command(obj, &TicketSystem::addHall);
		}

		//Adding Event
		else if (T.get_command_name() == "addevent" && isOpened) {
			T.execute_command(obj, &TicketSystem::addEvent);
		}

		//Free seats of event on date
		else if (T.get_command_name() == "freeseats" && isOpened) {
			T.execute_command(obj, &TicketSystem::freeSeats);
		}

		//Booking function
		else if (T.get_command_name() == "book" && isOpened) {
			T.execute_command(obj, &TicketSystem::book);
		}

		//Unbooking function
		else if (T.get_command_name() == "unbook" && isOpened) {
			T.execute_command(obj, &TicketSystem::unbook);
		}

		//Unbooking function
		else if (T.get_command_name() == "buy" && isOpened) {
			T.execute_command(obj, &TicketSystem::buy);
		}

		//Bookings function
		else if (T.get_command_name() == "bookings" && isOpened) {
			T.execute_command(obj, &TicketSystem::bookings);
		}

		//Check function
		else if (T.get_command_name() == "check" && isOpened) {
			T.execute_command(obj, &TicketSystem::check);
		}

		//Report function
		else if (T.get_command_name() == "report" && isOpened) {
			T.execute_command(obj, &TicketSystem::report);
		}

		else {
			std::cout << "Invalid Command!" << std::endl;
		}
	}


}


template<typename T>
inline void Terminal::execute_command(T& object, void(T::* f)(Vector<String>))
{
	(object.*f)(arguments);
}



void Terminal::clear_command() {
	command_name.clear();
	arguments.clear();
}

//Function that takes a specific word from user's input
const char* nthword(char* command, int num)
{
	char* result = new char[strlen(command) + 1];

	int i = 0;

	// Counter for the command number. 
	int strnum = 0;


	char* previous;//It is the pointe before command's character
	previous = NULL; //I'm using it to find the first character of the string

	while (*command != '\0') //till the end of the command
	{
		if (*command != ' ')
		{
			if ((previous == NULL) || (*previous == ' ')) strnum++; //The main purpose of the function is to miss all the spaces in the result
			if (strnum == num) { result[i] = *command; i++; } //After hard working I have managed to return only the wanted word
			command++;
			previous = command - 1;
		}
		else if (*command == ' ')
		{
			command++;
			previous = command - 1;
		}
	}

	result[i] = '\0';


	return result;
}

//Counting words
int countWords(const char* command) {
	int numWords = 0; //starting from zero words
	int len = 0;

	if (command == nullptr) { //We are checking if it is a valid pointer
		return 0;
	}

	while (*command) { //Scanning every character of our command 
		if (*command == ' ') { //when we hit the space character we reset the length to zero
			len = 0;
		}
		else if (++len == 1) { //if it is not a space we increment numWords
			numWords++;
		}
		command++;
	}

	return numWords;
}


void Terminal::setCommand(const String& cmd) {
	clear_command();

	this->command_name = nthword(cmd.c_str(), 1);

	for (int i = 2; i <= countWords(cmd.c_str()); i++) {
		arguments.push_back(nthword(cmd.c_str(), i));
	}

}