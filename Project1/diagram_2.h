#ifndef _DIAGRAM_2_H_
#define _DIAGRAM_2_H_
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

		//Prepare
		State& operator[] (const int index) { return diagram[index]; }
		const State& operator[] (const int index) const { return diagram[index]; };

		// 4 -Input
		friend std::istream& operator >> (std::istream& s, Diagram& r);

		// 4 -Output
		friend std::ostream& operator << (std::ostream&, const Diagram&);

		// 5 - Unit
		Diagram& operator +=(const Diagram& diagram);
		Diagram& operator +(const Diagram& diagram);

		// 6 - Change
		int operator()(State state);

		// 7 - Copy N times
		Diagram& operator * (int N);
		Diagram& operator *= (int N);

		// 8 - shift right
		Diagram& operator > (int N);

		// 9 - shift left
		Diagram& operator < (int N);
	};
}
#endif