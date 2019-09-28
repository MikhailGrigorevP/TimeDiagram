#include "diagram.h"
#include <sstream>

using namespace Prog3_1;
int main()
{

	std::cout << "PROJECT A: \n\n";

	Diagram diagram_1;
	std::cout << "1. Diagram without init: ";
	diagram_1.print(std::cout);
	std::cout << std::endl;

	Diagram diagram_2a(0);
	std::cout << "2a. Diagram with 0 init: ";
	diagram_2a.print(std::cout);
	std::cout << std::endl;

	Diagram diagram_2b(1);
	std::cout << "2b. Diagram with 1 init: ";
	diagram_2b.print(std::cout);
	std::cout << std::endl;

	Diagram diagram_2c(-1);
	std::cout << "2c. Diagram with -1 init: ";
	diagram_2c.print(std::cout);
	std::cout << std::endl;

	Diagram diagram_3a("---_____--");
	Diagram diagram_3b("-_____----__");
	std::cout << "3. Unit into diagram: max size = " << diagram_3a.getMaxSize() << std::endl;

	std::cout << "First Diagram. Current size = " << diagram_3a.getEnd() << "; Diagram :";
	diagram_3a.print(std::cout);
	std::cout << "Second Diagram. Current size = " << diagram_3b.getEnd() << "; Diagram :";
	diagram_3b.print(std::cout);

	try {
		diagram_3a.unit(diagram_3b);
	}
	catch (const std::exception& msg)
	{
		std::cout << msg.what() << std::endl;
	}
	std::cout << "Unit. Current size = " << diagram_3a.getEnd() << "; Diagram :";
	diagram_3a.print(std::cout);
	std::cout << std::endl;

	Diagram diagram_4a, diagram_4b;
	std::cout << "4. Input diagram to unit: " << std::endl;
	std::cout << "Input first diagram: ";
	diagram_4a.input(std::cin);
	std::cout << "Input second diagram: ";
	diagram_4b.input(std::cin);
	std::cout << std::endl;
	std::cout << "Your first diagram. Current size = " << diagram_4a.getEnd() << "; Current time = " << diagram_4a.getCurrTime() << ";" << std::endl;
	std::cout << "Your second diagram. Current size = " << diagram_4b.getEnd() << "; Current time = " << diagram_4b.getCurrTime() << ";" << std::endl;

	try {
		diagram_4a.unit(diagram_4b);
	}
	catch (const std::exception& msg)
	{
		std::cout << msg.what() << std::endl;
	}
	std::cout << "Unit. Current size = " << diagram_4a.getEnd() << "; Current time = " << diagram_4a.getCurrTime() << "; Diagram : ";
	diagram_4a.print(std::cout);
	std::cout << std::endl;

	Diagram diagram_5;
	std::cout << "5. Input diagram to change: " << std::endl;
	diagram_5.input(std::cin);
	std::cout << "Input new state and time: ";

	State new_state;
	char ch;

	bool good_input(true);
	do {

		std::cin >> ch;
		std::cin >> new_state.time;
		new_state.state = returnState(ch);

		if (std::cin.good()) {
			good_input = true;
			try {
				diagram_5.change(new_state);
			}
			catch (const std::exception& ex)
			{
				good_input = false;
				std::cout << ex.what() << std::endl;
				std::cout << "\n >>>  Try again\n";
			}
		}
		else {
			std::cout << " >>> Incorrect input. Try again\n";
			good_input = false;
			getClear();
		}
	} while (!good_input);

	std::cout << "Diagram :";
	diagram_5.print(std::cout);
	std::cout << std::endl;
	getClear();


	Diagram diagram_6;
	std::cout << "6. Input diagram to copy: " << std::endl;
	diagram_6.input(std::cin);
	std::cout << "Input num of copy:";
	int num;

	do {
		std::cin >> num;
		good_input = true;
		if (std::cin.good()) {
			good_input = true;
			try {
				diagram_6.copy(num);
			}
			catch (std::exception& ex)
			{
				good_input = false;
				std::cout << ex.what() << std::endl;
				std::cout << "\n >>  Try again\n";
			}
		}
		else {
			std::cout << " >> Incorrect input. Try again\n";
			getClear();
			good_input = false;
		}
	} while (!good_input);
	getClear();
	std::cout << "Diagram :";
	diagram_6.print(std::cout);
	std::cout << std::endl;

	Diagram diagram_7;
	std::cout << "7. Input diagram to shift: " << std::endl;
	diagram_7.input(std::cin);
	std::cout << "Current size = " << diagram_7.getEnd() << std::endl;
	std::cout << "Input num for left shift: ";

	do {
		std::cin >> num;
		good_input = true;
		if (std::cin.good()) {
			good_input = true;
			try {
				diagram_7.shiftLeft(num);
			}
			catch (std::exception& ex)
			{
				good_input = false;
				std::cout << ex.what() << std::endl;
				std::cout << "\n >>  Try again\n";
			}
		}
		else {
			std::cout << " >> Incorrect input. Try again\n";
			getClear();
			good_input = false;
		}
	} while (!good_input);
	getClear();
	std::cout << "Shift left. Current size = " << diagram_7.getEnd() << "; Diagram : ";
	diagram_7.print(std::cout);
	std::cout << "Input num for right shift: ";

	do {

		std::cin >> num;
		good_input = true;
		if (std::cin.good()) {
			good_input = true;
			try {
				diagram_7.shiftRight(num);
			}
			catch (std::exception& ex)
			{
				good_input = false;
				std::cout << ex.what() << std::endl;
				std::cout << "\n >>  Try again\n";
			}
		}
		else {
			std::cout << " >> Incorrect input. Try again\n";
			getClear();
			good_input = false;
		}
	} while (!good_input);
	getClear();
	std::cout << "Shift right. Current size = " << diagram_7.getEnd() << "; Diagram : ";
	diagram_7.print(std::cout);
	std::cout << std::endl;

	return 0;
}