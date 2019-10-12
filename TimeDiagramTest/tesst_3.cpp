#include "pch.h"
#include "../Project1/diagram_3.cpp"

TEST(TimeDiagramConstructors, EmptyConstractor) {

	////StandartEmpty

	//Prog3_1::Diagram diagram_empty;
	//std::ostringstream output;
	//output << diagram_empty;

	//ASSERT_EQ(0, diagram_empty.getCurrTime());
	//ASSERT_EQ(0, diagram_empty.getEnd());
	//EXPECT_EQ("Stack is empty\n", output.str());

	Prog3_1::Diagram diagram("--___-________--");

	Prog3_1::Diagram a2 = func(diagram);
	std::ostringstream output_1;
	output_1 << a2;

	EXPECT_EQ("--___-________--\n", output_1.str());
}


//TEST(TimeDiagramConstructors, InitConstractor) {
//
//	//X init
//
//	Prog3_1::Diagram diagram_init1(-1, 10);
//	std::ostringstream output_1;
//	output_1 << diagram_init1;
//	ASSERT_EQ(50, diagram_init1.getCurrTime());
//	ASSERT_EQ(1, diagram_init1.getEnd());
//	EXPECT_EQ("**********\n", output_1.str());
//
//	//"_" init
//
//	Prog3_1::Diagram diagram_init2(0, 50);
//	std::ostringstream output2;
//	output2 << diagram_init2;
//	ASSERT_EQ(50, diagram_init2.getCurrTime());
//	ASSERT_EQ(1, diagram_init2.getEnd());
//	EXPECT_EQ("__________________________________________________\n", output2.str());
//
//	//"-" init
//
//	Prog3_1::Diagram diagram_init3(1, 50);
//	std::ostringstream output3;
//	output3 << diagram_init3;
//	ASSERT_EQ(50, diagram_init3.getCurrTime());
//	ASSERT_EQ(1, diagram_init3.getEnd());
//	EXPECT_EQ("--------------------------------------------------\n", output3.str());
//
//	//ASCII init
//
//	Prog3_1::Diagram diagram_init4("-----_______--__---_____****--____");
//	std::ostringstream output4;
//	output4 << diagram_init4;
//	ASSERT_EQ(34, diagram_init4.getCurrTime());
//	ASSERT_EQ(9, diagram_init4.getEnd());
//	EXPECT_EQ("-----_______--__---_____****--____\n", output4.str());
//
//	//ASCII error init
//
//	Prog3_1::Diagram diagram_init6("-----_______--__---_____****--____&&&&&----___");
//	std::ostringstream output6;
//	output6 << diagram_init6;
//	ASSERT_EQ(34, diagram_init6.getCurrTime());
//	ASSERT_EQ(9, diagram_init6.getEnd());
//	EXPECT_EQ("-----_______--__---_____****--____\n", output6.str());
//
//	//ASCII overflow init
//
//	Prog3_1::Diagram diagram_init5("-----_______--__---_____****--____-----_______--__---_____****--____");
//	std::ostringstream output5;
//	output5 << diagram_init5;
//	ASSERT_EQ(50, diagram_init5.getCurrTime());
//	ASSERT_EQ(13, diagram_init5.getEnd());
//	EXPECT_EQ("-----_______--__---_____****--____-----_______--__---_____****--____\n", output5.str());
//
//}
//
//TEST(TimeDiagramMethods, input) {
//
//	//With error input
//
//	Prog3_1::Diagram diagram_input1;
//
//	std::istringstream input1("----------__________---***::::::::\n");
//	std::cin.rdbuf(input1.rdbuf());
//	std::cin >> diagram_input1;
//
//	std::ostringstream output1;
//
//	ASSERT_EQ(26, diagram_input1.getCurrTime());
//	ASSERT_EQ(4, diagram_input1.getEnd());
//	output1 << diagram_input1;
//	EXPECT_EQ("----------__________---***\n", output1.str());
//
//	//Overflow input
//
//	Prog3_1::Diagram diagram_input2;
//
//	std::istringstream input2("-----_______--__---_____****--____-----_______--__---_____****--____\n");
//	std::cin.rdbuf(input2.rdbuf());
//	std::cin >> diagram_input2;
//
//	std::ostringstream output2;
//
//	ASSERT_EQ(50, diagram_input2.getCurrTime());
//	ASSERT_EQ(13, diagram_input2.getEnd());
//	output2 << diagram_input2;
//	EXPECT_EQ("-----_______--__---_____****--____-----_______--__\n", output2.str());
//
//}
//
//TEST(TimeDiagramMethods, unit) {
//
//	//Unit with same elements
//
//	Prog3_1::Diagram diagram_unit1("-----_______-_");
//	Prog3_1::Diagram diagram_unit2("____---");
//
//	ASSERT_EQ(14, diagram_unit1.getCurrTime());
//	ASSERT_EQ(4, diagram_unit1.getEnd());
//
//	ASSERT_EQ(7, diagram_unit2.getCurrTime());
//	ASSERT_EQ(2, diagram_unit2.getEnd());
//
//	diagram_unit1 += diagram_unit2;
//
//	std::ostringstream output;
//	output << diagram_unit1;
//	ASSERT_EQ(21, diagram_unit1.getCurrTime());
//	ASSERT_EQ(5, diagram_unit1.getEnd());
//	EXPECT_EQ("-----_______-_____---\n", output.str());
//
//	//Standart init
//
//	Prog3_1::Diagram diagram_unit3("-_-_-_");
//	Prog3_1::Diagram diagram_unit4("-_-_-_");
//
//	diagram_unit3 += diagram_unit4;
//
//	std::ostringstream output2;
//	output2 << diagram_unit3;
//	ASSERT_EQ(12, diagram_unit3.getCurrTime());
//	ASSERT_EQ(12, diagram_unit3.getEnd());
//	EXPECT_EQ("-_-_-_-_-_-_\n", output2.str());
//
//
//}
//
//TEST(TimeDiagramMethods, unitOverFlow) {
//
//	//Unit with overflow
//
//	Prog3_1::Diagram diagram_unit5("--------");
//	Prog3_1::Diagram diagram_unit6("___________________________________________________________");
//
//	diagram_unit5 += diagram_unit6;
//
//	std::ostringstream output3;
//	output3 << diagram_unit5;
//	ASSERT_EQ(50, diagram_unit5.getCurrTime());
//	ASSERT_EQ(2, diagram_unit5.getEnd());
//	EXPECT_EQ("--------__________________________________________\n", output3.str());
//
//}
//
//TEST(TimeDiagramMethods, change) {
//
//	Prog3_1::Diagram diagram_change("---___---");
//	diagram_change("*", 5);
//
//	std::ostringstream output;
//	output << diagram_change;
//	EXPECT_EQ("---_*_---\n", output.str());
//	ASSERT_EQ(5, diagram_change.getEnd());
//	ASSERT_EQ(9, diagram_change.getCurrTime());
//
//	//
//	Prog3_1::Diagram diagram_change2("--__--___-_-__-________---");
//	diagram_change2("---", 6);
//	std::ostringstream output2;
//
//	output2 << diagram_change2;
//	EXPECT_EQ("--__----_-_-__-________---\n", output2.str());
//	ASSERT_EQ(11, diagram_change2.getEnd());
//	ASSERT_EQ(26, diagram_change2.getCurrTime());
//
//	//
//	Prog3_1::Diagram diagram_change3("-__--_______--_-_");
//	diagram_change3("------", 1);
//	std::ostringstream output3;
//
//	output3 << diagram_change3;
//	EXPECT_EQ("------______--_-_\n", output3.str());
//	ASSERT_EQ(6, diagram_change3.getEnd());
//	ASSERT_EQ(17, diagram_change3.getCurrTime());
//
//	//
//	Prog3_1::Diagram diagram_change4("-___--___---___--___-_--_");
//	diagram_change4("-", 25);
//	std::ostringstream output4;
//
//	output4 << diagram_change4;
//	EXPECT_EQ("-___--___---___--___-_---\n", output4.str());
//	ASSERT_EQ(11, diagram_change4.getEnd());
//	ASSERT_EQ(25, diagram_change4.getCurrTime());
//
//	//
//	Prog3_1::Diagram diagram_change5("__--__--__--__--__--__--");
//	diagram_change5("_--_", 4);
//	std::ostringstream output5;
//
//	output5 << diagram_change5;
//	EXPECT_EQ("__-_--_-__--__--__--__--\n", output5.str());
//	ASSERT_EQ(14, diagram_change5.getEnd());
//	ASSERT_EQ(24, diagram_change5.getCurrTime());
//
//	//
//	Prog3_1::Diagram diagram_change6("-__--__--");
//	diagram_change6("_--__--__", 1);
//	std::ostringstream output6;
//
//	output6 << diagram_change6;
//	EXPECT_EQ("_--__--__\n", output6.str());
//	ASSERT_EQ(5, diagram_change6.getEnd());
//	ASSERT_EQ(9, diagram_change6.getCurrTime());
//
//	//
//	Prog3_1::Diagram diagram_change7("_---_----_---_-___---___--_--");
//	diagram_change7("-----", 10);
//	std::ostringstream output7;
//
//	output7 << diagram_change7;
//	EXPECT_EQ("_---_----------___---___--_--\n", output7.str());
//	ASSERT_EQ(10, diagram_change7.getEnd());
//	ASSERT_EQ(29, diagram_change7.getCurrTime());
//
//	//
//	Prog3_1::Diagram diagram_change8("-___---__--___---___--___-__--");
//	diagram_change8("---___", 2);
//	std::ostringstream output8;
//
//	output8 << diagram_change8;
//	EXPECT_EQ("----_____--___---___--___-__--\n", output8.str());
//	ASSERT_EQ(11, diagram_change8.getEnd());
//	ASSERT_EQ(30, diagram_change8.getCurrTime());
//
//	//
//	Prog3_1::Diagram diagram_change9("-___---__--___---___--___-__--");
//	diagram_change9("-__-", 9);
//	std::ostringstream output9;
//
//	output9 << diagram_change9;
//	EXPECT_EQ("-___---_-__-__---___--___-__--\n", output9.str());
//	ASSERT_EQ(15, diagram_change9.getEnd());
//	ASSERT_EQ(30, diagram_change9.getCurrTime());
//}
//
//TEST(TimeDiagramMethods, copy) {
//
//	//Standart copy
//	Prog3_1::Diagram diagram_copy("--__--");
//	diagram_copy(5);
//
//	std::ostringstream output;
//	output << diagram_copy;
//	ASSERT_EQ(13, diagram_copy.getEnd());
//	ASSERT_EQ(36, diagram_copy.getCurrTime());
//	EXPECT_EQ("--__----__----__----__----__----__--\n", output.str());
//
//	//Copy with overflow
//	Prog3_1::Diagram diagram_copy2("-----_____");
//	diagram_copy2(5);
//
//	std::ostringstream output2;
//	output2 << diagram_copy2;
//	ASSERT_EQ(10, diagram_copy2.getEnd());
//	ASSERT_EQ(50, diagram_copy2.getCurrTime());
//	EXPECT_EQ("-----_____-----_____-----_____-----_____-----_____\n", output2.str());
//}
//
//TEST(TimeDiagramMethods, shift) {
//
//	//Shift Left
//	Prog3_1::Diagram diagram_copy("-----__-----");
//	ASSERT_EQ(3, diagram_copy.getEnd());
//	ASSERT_EQ(12, diagram_copy.getCurrTime());
//
//	diagram_copy <<= 5;
//
//	ASSERT_EQ(2, diagram_copy.getEnd());
//	ASSERT_EQ(12, diagram_copy.getCurrTime());
//
//	std::ostringstream output;
//	output << diagram_copy;
//
//	EXPECT_EQ("__----------\n", output.str());
//
//	//Shift Right
//	Prog3_1::Diagram diagram_copy2("-----_____");
//
//	ASSERT_EQ(2, diagram_copy2.getEnd());
//	ASSERT_EQ(10, diagram_copy2.getCurrTime());
//
//	diagram_copy2 >>= 4;
//
//	std::ostringstream output2;
//	output2 << diagram_copy2;
//	ASSERT_EQ(3, diagram_copy2.getEnd());
//	ASSERT_EQ(10, diagram_copy2.getCurrTime());
//	EXPECT_EQ("____-----_\n", output2.str());
//}
//
//TEST(TimeDiagramMethods, index) {
//
//	Prog3_1::Diagram diagram_copy("--__-_-____--_--");
//
//	ASSERT_EQ('-', diagram_copy[2]);
//	ASSERT_EQ('_', diagram_copy[3]);
//
//}
//
//TEST(TimeDiagramMethods, exeptions) {
//
//	//Try to create diagram with undefined symbols
//	ASSERT_ANY_THROW(Prog3_1::Diagram diagram_exp(-2));
//	ASSERT_ANY_THROW(Prog3_1::Diagram diagram_exp(24));
//
//	//Try to create empty diagram
//	ASSERT_ANY_THROW(Prog3_1::Diagram diagram_exp("&&&-___----___-"));
//
//	Prog3_1::Diagram diagram_exp(1);
//
//	//Try to copy negative times
//	ASSERT_ANY_THROW(diagram_exp(-3));
//
//	//Try to shift diagram left negative times
//	ASSERT_ANY_THROW(diagram_exp <<= -4);
//
//	//Try to shift diagram right negative times
//	ASSERT_ANY_THROW(diagram_exp <<= -5);
//
//	Prog3_1::Diagram diagram_exp2(1);
//
//	//Try to change wrong diagram
//	ASSERT_ANY_THROW(diagram_exp2("--------", 55));
//	ASSERT_ANY_THROW(diagram_exp2("_", 102));
//	ASSERT_ANY_THROW(diagram_exp2("*", -6));
//
//	//Test indexation
//	ASSERT_ANY_THROW(diagram_exp2[-25]);
//	ASSERT_ANY_THROW(diagram_exp2[585]);
//
//}
