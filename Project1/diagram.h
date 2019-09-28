#ifndef _DIAGRAM_H_
#define _DIAGRAM_H_
#include <iostream>
namespace Prog3_1 {

	struct State {
		int state;
		int time;
	};

	void getClear();
	char returnState(int i);
	int returnState(char ch);

	class Diagram {
	private:
		static const int MAX_TIME = 50;
		static const int MAX_SZ = MAX_TIME;
		int size = 0;
		int end;
		State diagram[MAX_SZ];

	public:


		int getMaxSize() { return MAX_SZ; };
		int getCurrTime() { return size; };
		int getEnd() { return end; };

		// 1 - Empty constructor
		Diagram() : end(0), size(0) {}

		// 2 - MaxInit constructor
		Diagram(int state);

		// 3 -ASCII constructor
		Diagram(const char* diagram);

		// 4 -Input
		std::istream& input(std::istream&);

		// 4 -Output
		std::ostream& print(std::ostream&) const;

		// 5 - Unit
		void unit(Diagram diagram);

		// 6 - Change
		int change(State state);

		// 7 - Copy N times
		int copy(int N);

		// 8 - shift right
		int shiftRight(int N);

		// 9 - shift left
		int shiftLeft(int N);
	};
}
#endif