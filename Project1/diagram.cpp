#define _CRT_SECURE_NO_WARNINGS

#include "diagram.h"

namespace Prog3_1 {

	int returnState(char ch) {
		switch (ch) {
		case '-':
			return 1;
		case '_':
			return 0;
		case '*':
			return -1;
		default:
			return 2;
		}
	}

	char returnState(int i) {
		switch (i) {
		case  0:
			return '_';
		case  1:
			return '-';
		case  -1:
			return '*';
		}
	}

	char* getstr(std::istream& i)
	{
		char* ptr = (char*)malloc(1);
		char buf[81];
		int n, len = 0;
		*ptr = '\0';

		i >> buf;
		len += strlen(buf);
		ptr = (char*)realloc(ptr, len + 1);
		strcat(ptr, buf);


		return ptr;
	}

	// 2 - MaxInit constructor
	Diagram::Diagram(int state) :end(1), size(MAX_TIME) {

		if ((state < -1) || (state > 1)) {
			throw std::exception(" >>> Undefuned state");
		}
		else
			diagram[0] = { state, MAX_TIME };
	}

	// 3 - ASCII constructor
	Diagram::Diagram(const char* diagram) {

		end = 0;

		int len;
		int time = 0;
		size = 0;
		bool error1(false), error2(false);

		if (strlen(diagram) <= MAX_TIME)
			len = strlen(diagram);
		else {
			len = MAX_TIME;
			error2 = true;
		}

		char ch = diagram[0];
		int state;

		if (returnState(ch) == 2) {
			throw std::exception(" >>> Empty diagram");
		}

		for (int i = 0; i <= len; ++i) {
			state = returnState(ch);
			if ((diagram[i] != ch) || (i == len)) {
				if (state == 2) {
					error1 = true;
					break;
				}
				this->diagram[end] = { state, time };
				size += time;
				time = 1;
				ch = diagram[i];
				++end;
			}
			else if (state != 2)
				++time;
		}

		if (error1) {
			std::cout << " >> Undefined symbols used, diagram was cutted\n";
		}
		else if (error2) {
			std::cout << " >> Size of diagram more than max, diagram was cutted\n";
		}

	}

	// 4 -Input
	std::istream& Diagram::input(std::istream& i) {

		char* diagram = getstr(i);

		int len;
		int time = 0;
		size = 0;
		bool error1(false), error2(false);

		if (strlen(diagram) <= MAX_TIME)
			len = strlen(diagram);
		else {
			len = MAX_TIME;
			error2 = true;
		}

		char ch = diagram[0];
		int state;

		for (int i = 0; i <= len; ++i) {
			state = returnState(ch);
			if ((diagram[i] != ch) || (i == len)) {
				if (state == 2) {
					error1 = true;
					break;
				}
				this->diagram[end] = { state, time };
				size += time;
				time = 1;
				ch = diagram[i];
				++end;
			}
			else if (state != 2)
				++time;
		}

		if (error1) {
			std::cout << " >> Undefined symbols used, diagram was cutted\n";
		}
		else if (error2) {
			std::cout << " >> Size of diagram more than max, diagram was cutted\n";
		}
		else if (size == 0) {
			throw std::exception(" >>> Empty diagram");
		}

		return i;
	}

	// 4 -Output
	std::ostream& Diagram::print(std::ostream& s) const
	{
		char state;
		if (end == 0)
			s << "Stack is empty";
		else
			for (int i = 0; i < end; ++i) {
				state = returnState(diagram[i].state);
				for (int j = 0; j < diagram[i].time; ++j)
					s << state;
			}

		s << std::endl;
		return s;
	}

	// 5 - Unit
	void Diagram::unit(Diagram diagram) {
		int time;
		Diagram tmp(diagram);
		bool first = true;


		for (int i = 0; i < tmp.getEnd(); ++i) {
			if (first) {
				first = false;
				if ((end > 0) && (tmp.diagram[0].state == this->diagram[end - 1].state)) {
					time = ((size + tmp.diagram[i].time) <= MAX_TIME) ? tmp.diagram[i].time : MAX_TIME - size;
					size += time;
					this->diagram[end - 1].time += time;
					continue;
				}
			}
			time = ((size + tmp.diagram[i].time) <= MAX_TIME) ? tmp.diagram[i].time : MAX_TIME - size;
			if (time != 0) {
				this->diagram[end] = { tmp.diagram[i].state, time };
				size += time;
				++end;
			}
			if (time != tmp.diagram[i].time) {
				std::cout << " >>> Unit of diagrams is bigger than allowed time. Second diagram was cutted\n";
				break;
			}
		}
	}

	// 6 - Change

	int Diagram::change(Diagram n_diagram, int time) {

		if (end == 0) {
			return 0;
		}

		if (time < 0) {
			throw std::exception(" >>> Time must be more than 0 ");
		}

		if (time > size) {
			throw std::exception(" >>> Time must be low than current diagram size ");
		}

		int currtime = 0;
		int fulltime = n_diagram.size;

		if ((time + fulltime) >= MAX_TIME) {
			throw std::exception(" >>> Size overflow ");
		}

		Diagram tmp_diagram;
		int i = 0;
		while (currtime < time) {
			currtime += diagram[i].time;
			if (currtime >= time) {
				int losttime = currtime - time + 1;
				diagram[i].time -= losttime;
				size -= losttime;
				int j = i + 1;
				if (diagram[i].time == 0)
					--i;

				time += fulltime - 1;

				if (fulltime < losttime) {
					for (int k = end; k > i; k--)
					{
						diagram[k] = diagram[k - 1];
					}
					++end;
					diagram[i + 1].time = losttime - fulltime;
					size += diagram[i + 1].time;
					time = 0;
				}

				while (currtime < time) {
					currtime += diagram[j].time;
					if (currtime >= time) {
						int losttime = diagram[j].time - (currtime - time);
						diagram[j].time -= losttime;
						size -= losttime;
						if (diagram[j].time == 0)
							++j;
						break;
					}
					size -= diagram[j].time;
					j++;
				}

				for (int k = j; k < end; k++)
				{
					tmp_diagram.diagram[tmp_diagram.end] = diagram[k];
					size -= diagram[k].time;
					tmp_diagram.size += diagram[k].time;
					++tmp_diagram.end;
				}
				end = i + 1;
				break;
			}
			++i;
		}

		n_diagram.unit(tmp_diagram);
		this->unit(n_diagram);

		std::cout << std::endl;
		return 0;
	}

	// 7 - Copy N times
	int Diagram::copy(int n) {

		if (end == 0) {
			return 0;
		}

		if (n < 0) {
			throw std::exception(" >>> N must be more than 0");
		}

		Diagram temp(*this);

		for (int i = 0; i < n; ++i)
		{
			if (size == MAX_TIME)
				break;
			this->unit(temp);
		}
		return 0;
	}

	// 8 - shift right
	int Diagram::shiftRight(int time) {

		if (end == 0) {
			return 0;
		}

		if (time < 0) {
			throw std::exception(" >>> Shift must be more than 0");
		}

		while (time != 0) {
			if (diagram[end - 1].time > time) {
				diagram[end - 1].time -= time;
				if (diagram[0].state != diagram[end - 1].state) {
					for (int i = end; i > 0; --i) {
						diagram[i] = diagram[i - 1];
					}
					diagram[0] = { diagram[end].state, time };
					++end;
				}
				else {
					diagram[0].time += time;
				}
				time = 0;
			}
			else {
				time -= diagram[end - 1].time;
				if (diagram[0].state != diagram[end - 1].state) {
					for (int i = end; i > 0; --i) {
						diagram[i] = diagram[i - 1];
					}
					diagram[0] = diagram[end];
				}
				else {
					diagram[0].time += diagram[end - 1].time;
					--end;
				}
			}
		}
		return 0;
	}

	// 9 - shift left
	int Diagram::shiftLeft(int time) {

		if (end == 0) {
			return 0;
		}
		if (time < 0) {
			throw std::exception(" >>> Shift must be more than 0");
		}

		while (time != 0) {
			if (diagram[0].time > time) {
				diagram[0].time -= time;
				if (diagram[end - 1].state == diagram[0].state)
					diagram[end - 1].time += time;
				else {
					diagram[end] = { diagram[0].state, time };
					++end;
				}
				time = 0;
			}
			else {
				State tmp = diagram[0];
				time -= tmp.time;
				for (int i = 0; i < end - 1; ++i) {
					diagram[i] = diagram[i + 1];
				}
				--end;

				if (diagram[end - 1].state == tmp.state) {
					diagram[end - 1].time += tmp.time;
				}
				else {
					diagram[end] = tmp;
					++end;
				}
			}
		}
		return 0;

	}

	void getClear()
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}