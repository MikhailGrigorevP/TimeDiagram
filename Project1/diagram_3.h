#ifndef _DIAGRAM_3_H_
#define _DIAGRAM_3_H_
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
		const int MAX_TIME = 50;
		int SZ;
		int size = 0;
		int end;
		State* diagram;

	public:

		Diagram(const Diagram&);
		Diagram(Diagram&&);

		~Diagram() { delete[] diagram; }

		Diagram& operator =(const Diagram&);
		Diagram& operator =(Diagram&&);

		int getMaxSize() { return SZ; };
		int getCurrTime() { return size; };
		int getEnd() { return end; };

		// 1 - Empty constructor
		Diagram() : SZ(0), end(0), size(0), diagram(nullptr) {}

		// 2 - MaxInit constructor
		Diagram(int state);

		// 3 -ASCII constructor
		Diagram(const char* diagram);

		// indexation
		char operator[] (const int index);
		const char operator[] (const int index) const;

		// 4 - Input
		friend std::istream& operator >> (std::istream& s, Diagram& r);

		// 4 - Output
		friend std::ostream& operator << (std::ostream&, const Diagram&);

		// 5 - Unit
		Diagram& operator += (const Diagram& diagram);

		// 6 - Change
		int operator()(Diagram n_diagram, int time);

		// 7 - Copy N times
		Diagram& operator()(int N);

		// 8 - shift right
		Diagram& operator >>= (int N);

		// 9 - shift left
		Diagram& operator <<= (int N);
	};
}
#endif