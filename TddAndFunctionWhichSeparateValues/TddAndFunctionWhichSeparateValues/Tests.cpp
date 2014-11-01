#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
typedef std::string input;
typedef std::string token;
typedef std::vector<token> output;

extern std::pair <input, output> paramArguments[6];

output separateValuesWithInputSeparator(input inputArg, char separator = ' ')
{
	output values;

	for (unsigned int i = 0; i < inputArg.size(); ++i)
	{	
		token value;
		for ( ; i < inputArg.size() && inputArg.at(i) != separator; ++i)
			value += inputArg.at(i);
		if(!value.empty())
			values.push_back(value);
	}

	return values;
}

class SeparateValuesWithInputSeparatorTest
	: public ::testing::TestWithParam< std::pair <input, output > >
{

};

INSTANTIATE_TEST_CASE_P(InstantiationName,
                        SeparateValuesWithInputSeparatorTest,
                        ::testing::ValuesIn(paramArguments));

TEST_P(SeparateValuesWithInputSeparatorTest, FromEmptyInputToDiffrentStringsInput)
{
	input inputArg = GetParam().first;
	output result = separateValuesWithInputSeparator(inputArg);
	output expected(GetParam().second);
	ASSERT_EQ(expected.size(), result.size());
	for (unsigned int i = 0; i < expected.size(); ++i)
		EXPECT_EQ(expected[i], result[i]);
}




//TEST_P(SeparateValuesWithInputSeparatorTest, ThreeWordInputWithSpaceSeparator)
//{
//
//
//}
