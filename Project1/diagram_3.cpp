#define _CRT_SECURE_NO_WARNINGS

#include "diagram_3.h"

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

	char* getstr(std::istream& i) {
		char* ptr = (char*)malloc(1);
		char buf[81];
		int len = 0;
		*ptr = '\0';

		i >> buf;
		len += strlen(buf);
		ptr = (char*)realloc(ptr, len + 1);
		strcat(ptr, buf);


		return ptr;
	}

	char Diagram::operator[] (const int index) {


		if ((index < 1) || (index > size)) {
			throw std::exception(" >>> Incorrect index ");
		}

		int currtime = 0;
		int i = 0;

		while (currtime < index) {
			currtime += diagram[i].time;
			if (currtime >= index) {
				return(returnState(diagram[i].state));
			}
			i++;
		}
		return '*';
	}

	const char Diagram::operator[] (const int index) const {


		if ((index < 1) || (index > size)) {
			throw std::exception(" >>> Incorrect index ");
		}

		int currtime = 0;
		int i = 0;

		while (currtime < index) {
			currtime += diagram[i].time;
			if (currtime >= index) {
				return(returnState(diagram[i].state));
			}
			i++;
		}
		return '*';
	}

	//Copy constructor
	Diagram::Diagram(const Diagram& diagram_tmp) : size(diagram_tmp.size), end(diagram_tmp.end), SZ(diagram_tmp.SZ) {
		diagram = new State[SZ];
		for (int i = 0; i < end; ++i)
			diagram[i] = diagram_tmp.diagram[i];
	}

	//Move construct
	Diagram::Diagram(Diagram&& diagram_tmp) : size(diagram_tmp.size), end(diagram_tmp.end), SZ(diagram_tmp.SZ), diagram(diagram_tmp.diagram) {
		diagram_tmp.diagram = nullptr;
	}

	Diagram& Diagram::operator =(const Diagram& diagram_tmp) {
		if (this != &diagram_tmp) {
			end = diagram_tmp.end;
			SZ = diagram_tmp.SZ;
			delete[] diagram;
			diagram = new State[SZ];
			for (int i = 0; i < end; ++i)
				diagram[i] = diagram_tmp.diagram[i];
		}
		return *this;
	}

	Diagram& Diagram::operator =(Diagram&& diagram_tmp) {
		int tmp = end;
		end = diagram_tmp.end;
		diagram_tmp.end = tmp;
		tmp = SZ;
		SZ = diagram_tmp.SZ;
		diagram_tmp.SZ = tmp;
		State* ptr = diagram;
		diagram = diagram_tmp.diagram;
		diagram_tmp.diagram = ptr;
		return *this;
	}

	// 2 - MaxInit constructor
	Diagram::Diagram(int state) : SZ(1), end(1), size(MAX_TIME), diagram(new State[1]) {

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

		SZ = 1;
		for (int i = 1; i < len; ++i) {
			if (diagram[i] != diagram[i - 1])
				++SZ;
			if (returnState(diagram[i]) == 2)
				break;
		}



		this->diagram = new State[SZ];

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

	}

	// 4 -Input
	std::istream& operator >> (std::istream& i, Diagram& _diagram) {

		char* diagram = getstr(i);

		if (i.fail()) {
			i.setstate(std::ios::failbit);
		}

		int len;
		int time = 0;
		_diagram.size = 0;
		bool error1(false), error2(false);

		if (strlen(diagram) <= _diagram.MAX_TIME)
			len = strlen(diagram);
		else {
			len = _diagram.MAX_TIME;
			error2 = true;
		}

		char ch = diagram[0];
		int state;

		if (returnState(ch) == 2) {
			throw std::exception(" >>> Empty diagram");
		}

		_diagram.SZ = 1;
		for (int i = 1; i < len; ++i) {
			if (diagram[i] != diagram[i - 1])
				++_diagram.SZ;
		}

		//if (_diagram.SZ == 0)
		//	++_diagram.SZ;

		_diagram.diagram = new State[_diagram.SZ];

		for (int i = 0; i <= len; ++i) {
			state = returnState(ch);
			if ((diagram[i] != ch) || (i == len)) {
				if (state == 2) {
					error1 = true;
					break;
				}
				_diagram.diagram[_diagram.end] = { state, time };
				_diagram.size += time;
				time = 1;
				ch = diagram[i];
				++_diagram.end;
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
		else if (_diagram.size == 0) {
			throw std::exception(" >>> Empty diagram");
		}

		return i;
	}

	// 4 -Output
	std::ostream& operator << (std::ostream& s, const Diagram& diagram) {
		char state;
		if (diagram.end == 0)
			s << "Stack is empty";
		else
			for (int i = 0; i < diagram.end; ++i) {
				state = returnState(diagram.diagram[i].state);
				for (int j = 0; j < diagram.diagram[i].time; ++j)
					s << state;
			}

		s << std::endl;
		return s;
	}

	// 5 - Unit
	Diagram& Diagram::operator +=(const Diagram& tmp_d) {

		if ((size + tmp_d.size) > MAX_TIME) {
			std::cout << " >>> size overflow\n";
		}


		State* new_diagram = new State[SZ];
		new_diagram = diagram;
		Diagram tmp(tmp_d);

		int new_end = 0;

		for (int i = 0; i < tmp_d.end; ++i) {
			if ((size + tmp.diagram[i].time) >= MAX_TIME) {
				tmp.diagram[i].time = MAX_TIME - size;
				size = MAX_TIME;
				new_end++;
				break;
			}
			size += tmp.diagram[i].time;
			new_end++;
		}

		if (tmp.diagram[0].state == diagram[end - 1].state) {
			SZ = SZ + new_end - 1;
			diagram = new State[SZ];
			for (int i = 0; i < end; ++i) {
				diagram[i] = new_diagram[i];
			}
			diagram[end - 1].time += tmp.diagram[0].time;
			for (int i = end; i < (end + new_end); ++i) {
				diagram[i] = tmp.diagram[i - end + 1];
			}
			end = SZ;
		}
		else {
			SZ = SZ + new_end;
			diagram = new State[SZ];
			for (int i = 0; i < end; ++i) {
				diagram[i] = new_diagram[i];
			}
			for (int i = end; i < (end + new_end); ++i) {
				diagram[i] = tmp.diagram[i - end];
			}
			end = SZ;
		}

		delete[] new_diagram;

		return *this;
	}

	// 6 - Change
	int Diagram::operator()(Diagram n_diagram, int time) {

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

					State* new_diagram = diagram;
					diagram = new State[++SZ];
					for (int k = 0; k < end; ++k)
					{
						diagram[k] = new_diagram[k];
					}
					for (int k = end; k > i; --k)
					{
						diagram[k] = diagram[k - 1];
					}
					delete[] new_diagram;

					//for (int k = end; k > i; k--)
					//{
					//	diagram[k] = diagram[k - 1];
					//}

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

				tmp_diagram.SZ = end - j;
				tmp_diagram.diagram = new State[tmp_diagram.SZ];


				for (int k = j; k < end; k++)
				{
					tmp_diagram.diagram[tmp_diagram.end] = diagram[k];
					size -= diagram[k].time;
					tmp_diagram.size += diagram[k].time;
					++tmp_diagram.end;
				}
				SZ = end = i + 1;
				break;
			}
			++i;
		}

		n_diagram += tmp_diagram;

		*this += n_diagram;

		std::cout << std::endl;
		return 0;
	}

	// 7 - Copy N times
	Diagram& Diagram::operator ()(int n) {

		if (end == 0) {
			return *this;
		}

		if (n < 0) {
			throw std::exception(" >>> N must be more than 0");
		}

		Diagram temp(*this);

		for (int i = 0; i < n; ++i)
		{
			if (size == MAX_TIME)
				break;
			*this += temp;
		}

		return *this;
	}


	// 8 - shift right
	Diagram& Diagram::operator >>= (int time) {

		if (end == 0) {
			return *this;
		}

		if (time < 0) {
			throw std::exception(" >>> Shift must be more than 0");
		}

		while (time != 0) {
			if (diagram[end - 1].time > time) {
				diagram[end - 1].time -= time;
				if (diagram[0].state != diagram[end - 1].state) {

					State* new_diagram = diagram;
					SZ += 1;
					diagram = new State[SZ];
					for (int i = end; i > 0; --i) {
						diagram[i] = new_diagram[i - 1];
					}
					diagram[0] = { new_diagram[end - 1].state, time };
					delete[] new_diagram;
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
					State tmp = diagram[end - 1];
					for (int i = end - 1; i > 0; --i) {
						diagram[i] = diagram[i - 1];
					}
					diagram[0] = tmp;
				}
				else {

					diagram[0].time += diagram[end - 1].time;

					State* new_diagram = diagram;
					SZ -= 1;
					diagram = new State[SZ];
					for (int i = 0; i < end - 1; ++i) {
						diagram[i] = new_diagram[i];
					}
					delete[] new_diagram;
					--end;
				}
			}
		}
		return *this;
	}

	// 9 - shift left
	Diagram& Diagram::operator <<= (int time) {

		if (end == 0) {
			return *this;
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

					State* new_diagram = diagram;
					SZ += 1;
					diagram = new State[SZ];
					for (int i = 0; i < end; ++i) {
						diagram[i] = new_diagram[i];
					}

					diagram[end] = { new_diagram[0].state, time };
					delete[] new_diagram;
					++end;
				}
				time = 0;
			}
			else {
				State tmp = diagram[0];
				time -= tmp.time;

				State* new_diagram = diagram;
				SZ -= 1;
				diagram = new State[SZ];
				for (int i = 0; i < end - 1; ++i) {
					diagram[i] = new_diagram[i + 1];
				}
				delete[] new_diagram;

				--end;

				if (diagram[end - 1].state == tmp.state) {
					diagram[end - 1].time += tmp.time;
				}
				else {
					State* new_diagram = diagram;
					SZ += 1;
					diagram = new State[SZ];
					for (int i = 0; i < end; ++i) {
						diagram[i] = new_diagram[i];
					}
					delete[] new_diagram;

					diagram[end] = tmp;
					++end;
				}
			}
		}
		return *this;

	}

	void getClear()
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}