#include <gtest/gtest.h>
typedef std::string input;
typedef std::string token;
typedef std::vector<token> output;

std::pair <input, output> paramArguments[6];

void initTestArgs()
{
	#define AMOUNT_OF_PARAM_ARGS 6

	const input inputsArg[AMOUNT_OF_PARAM_ARGS] = 
	{"", "A", "A ", "Aaa ", "A a b", "Aaa aaa bbb"};

	output outputsArg[AMOUNT_OF_PARAM_ARGS];
	outputsArg[1].push_back("A");
	outputsArg[2].push_back("A");
	outputsArg[3].push_back("Aaa");
	outputsArg[4].push_back("A");
	outputsArg[4].push_back("a");
	outputsArg[4].push_back("b");
	outputsArg[5].push_back("Aaa");
	outputsArg[5].push_back("aaa");
	outputsArg[5].push_back("bbb"); 

	for(unsigned int i = 0; i < AMOUNT_OF_PARAM_ARGS; ++i)
		paramArguments[i] = std::make_pair(inputsArg[i], outputsArg[i]);
}

int main(int argc, char** argv)
{
	initTestArgs();
	::testing::InitGoogleTest(&argc, argv);
	int result = RUN_ALL_TESTS();
	system("pause");
	return result;
}