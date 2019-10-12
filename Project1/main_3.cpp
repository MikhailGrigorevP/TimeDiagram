#include "diagram_3.h"
#include <sstream>

using namespace Prog3_1;

Diagram func(Diagram p) {	
//	Diagram a(p);
	std::cout << "func()\n";
	return p;
}


int main()
{
	std::cout << "PROJECT C: \n\n";

	//Diagram diagram_1;
	//std::cout << "1. Diagram without init: ";
	//std::cout << diagram_1;
	//std::cout << std::endl;

	//Diagram diagram_2a(0);
	//std::cout << "2a. Diagram with 0 init: ";
	//std::cout << diagram_2a;
	//std::cout << std::endl;

	//Diagram diagram_2b(1);
	//std::cout << "2b. Diagram with 1 init: ";
	//std::cout << diagram_2b;
	//std::cout << std::endl;

	//int state, sym;

	//std::cin >> sym;
	//std::cin >> state;

	//Diagram diagram_2c(sym, state);
	//std::cout << "2c. Diagram with -1 init: ";
	//std::cout << diagram_2c;
	//std::cout << std::endl;

	//Diagram y(1, 15);
	//std::cout << "y: " << y;
	//Diagram x = func(y);


	//std::cout << "x = func(y)\nx: " << x;

	//Diagram ob1("--___-__-__");
	//Diagram ob2("_---__-___-__");
	//std::cout << "\nob1: " << ob1;
	//std::cout << "ob2: " << ob2;
	//ob1 = ob2;
	//std::cout << "ob1 = ob2\nob1: " << ob1;

	//Diagram diagram_3a("---_____--");
	//Diagram diagram_3b("-_____----__");
	//std::cout << "3. Unit into diagram: max size = " << diagram_3a.getMaxSize() << std::endl;

	//std::cout << "First Diagram. Current size = " << diagram_3a.getEnd() << "; Diagram : ";
	//std::cout << diagram_3a;
	//std::cout << "Second Diagram. Current size = " << diagram_3b.getEnd() << "; Diagram : ";
	//std::cout << diagram_3b;

	//try {
	//	diagram_3a += diagram_3b;
	//}
	//catch (const std::exception& msg)
	//{
	//	std::cout << msg.what() << std::endl;
	//}
	//std::cout << "Unit. Current size = " << diagram_3a.getEnd() << "; Diagram : ";
	//std::cout << diagram_3a;
	//std::cout << std::endl;

	//Diagram diagram_4a, diagram_4b;
	//std::cout << "4. Input diagram to unit: " << std::endl;
	//std::cout << "Input first diagram: ";
	//std::cin >> diagram_4a;
	//std::cout << "Input second diagram: ";
	//std::cin >> diagram_4b;
	//std::cout << std::endl;
	//std::cout << "Your first diagram. Current size = " << diagram_4a.getEnd() << "; Current time = " << diagram_4a.getCurrTime() << "; " << std::endl;
	//std::cout << "Your second diagram. Current size = " << diagram_4b.getEnd() << "; Current time = " << diagram_4b.getCurrTime() << "; " << std::endl;

	//try {
	//	diagram_4a += diagram_4b;
	//}
	//catch (const std::exception& msg)
	//{
	//	std::cout << msg.what() << std::endl;
	//}
	//std::cout << "Unit. Current size = " << diagram_4a.getEnd() << "; Current time = " << diagram_4a.getCurrTime() << "; Diagram: ";
	//std::cout << diagram_4a;
	//std::cout << std::endl;

	//getClear();


	//Diagram diagram_5, diagram;
	//std::cout << "5. Input diagram to change: " << std::endl;
	//std::cin >> diagram_5;
	//std::cout << "Current time = " << diagram_5.getCurrTime() << std::endl;
	//std::cout << "Current size = " << diagram_5.getEnd() << std::endl;
	//std::cout << "Input new diagram and time: ";

	//int time;
	//std::cin >> diagram;

	//std::cin >> time;

	//try {
	//	diagram_5(diagram, time);
	//}
	//catch (std::exception& ex)
	//{
	//	std::cout << ex.what() << std::endl;
	//	std::cout << "\n >>  Try again\n";
	//}

	//std::cout << "Diagram :" << std::endl;
	//std::cout << diagram_5;
	//std::cout << "Current time = " << diagram_5.getCurrTime() << std::endl;
	//std::cout << "Current size = " << diagram_5.getEnd() << std::endl;
	//std::cout << std::endl;
	//getClear();


	//Diagram diagram_6;
	//std::cout << "6. Input diagram to copy: " << std::endl;
	//std::cin >> diagram_6;
	//std::cout << "Input num of copy:";
	//int num;
	//bool good_input = true;

	//do {
	//	std::cin >> num;
	//	if (std::cin.good()||num<0) {
	//		
	//		try {
	//			diagram_6(num);
	//		}
	//		catch (const std::exception& msg)
	//		{
	//			std::cout << msg.what() << std::endl;
	//		}
	//	}
	//	else {
	//		std::cout << " >> Incorrect input. Try again\n";
	//		getClear();
	//		good_input = false;
	//	}
	//} while (!good_input);
	//getClear();
	//std::cout << "Diagram :";
	//std::cout << diagram_6;
	//std::cout << std::endl;

	//Diagram diagram_7;
	//std::cout << "7. Input diagram to shift: " << std::endl;
	//std::cin >> diagram_7;
	//std::cout << "Current size = " << diagram_7.getEnd() << std::endl;
	//std::cout << "Input num for left shift: ";



	//do {
	//	std::cin >> num;
	//	good_input = true;
	//	if (std::cin.good()) {
	//		good_input = true;
	//		try {
	//			diagram_7 <<= num;
	//		}
	//		catch (std::exception& ex)
	//		{
	//			good_input = false;
	//			std::cout << ex.what() << std::endl;
	//			std::cout << "\n >>  Try again\n";
	//		}
	//	}
	//	else {
	//		std::cout << " >> Incorrect input. Try again\n";
	//		getClear();
	//		good_input = false;
	//	}
	//} while (!good_input);
	//getClear();
	//std::cout << "Shift left. Current size = " << diagram_7.getEnd() << "; Diagram : ";
	//std::cout << diagram_7;
	//std::cout << "Input num for right shift: ";

	//do {
	//	std::cin >> num;
	//	good_input = true;
	//	if (std::cin.good()) {
	//		good_input = true;
	//		try {
	//			diagram_7 >>= num;
	//		}
	//		catch (std::exception& ex)
	//		{
	//			good_input = false;
	//			std::cout << ex.what() << std::endl;
	//			std::cout << "\n >>  Try again\n";
	//		}
	//	}
	//	else {
	//		std::cout << " >> Incorrect input. Try again\n";
	//		getClear();
	//		good_input = false;
	//	}
	//} while (!good_input);

	//getClear();
	//std::cout << "Shift right. Current size = " << diagram_7.getEnd() << "; Diagram : ";
	//std::cout << diagram_7;
	//std::cout << std::endl;

	return 0;
}