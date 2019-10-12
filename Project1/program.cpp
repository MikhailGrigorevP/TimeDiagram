#include "diagram_3.h"

namespace Electro {
	class RSTrigger {
	private:
		bool state;
		Prog3_1::Diagram S = { 0, 1 };
		Prog3_1::Diagram R = { 0, 1 };
		Prog3_1::Diagram Q = { 0, 1 };
		Prog3_1::Diagram nQ = { 1, 1 };
	public:
		RSTrigger() : state(false) {}
		virtual ~RSTrigger() {}
		void set(int s, int r) {

			if ((s == 1) && (r == 1))
				std::cout << "> prohibited state\n";
			else if ((s == 1) && (r == 0))
				state = 1;
			else if ((s == 0) && (r == 1))
				state = 0;

			S += {s, 1};
			R += {r, 1};
			Q += {state, 1};
			nQ += {!(state), 1};

		}
		Prog3_1::Diagram getR() {
			return R;
		}
		Prog3_1::Diagram getS() {
			return S;
		}
		Prog3_1::Diagram getQ() {
			return Q;
		}
		Prog3_1::Diagram getnQ() {
			return nQ;
		}
	};
};

int main() {

	Electro::RSTrigger rs1;

	bool working(true);
	int st, st1, st2;

	std::cout << ">>> You are working with RS - trigger\n";

	while (working) {

		std::cout << "\n> 1. Set states\n";
		std::cout << "> 2. Show diagrams\n";
		std::cout << "> 3. exit\n";

		std::cin >> st;
		bool input = true;

		switch (st) {
		case 1:
			std::cout << "> Input S and R triggers states\n";
			std::cout << "> Input \"-1\" to stop\n";
			do {
				std::cin >> st1;
				if (st1 == -1) {
					std::cout << "> input ended\n";
					input = false;
				}
				else
					std::cin >> st2;

				if ((st1!= -1)&&((st1 < 0) || (st1 > 1) || (st2 < 0) || (st2 > 1) || std::cin.fail())) {
					std::cout << "> Wrong number. Try again\n";
					Prog3_1::getClear();
				}
				else if(input != false)
					rs1.set(st1, st2);
			} while (input);
			break;
		case 2:
			std::cout << "\n> Diagrams:\n";
			std::cout << "S:  " << rs1.getS();
			std::cout << "R:  " << rs1.getR();
			std::cout << "Q:  " << rs1.getQ();
			std::cout << "!Q: " << rs1.getnQ();
			break;
		case 3:
			working = false;
			break;
		default:
			std::cout << "> Wrong number. Try again\n";
			Prog3_1::getClear();
			break;
		}
	}


	return 0;
}