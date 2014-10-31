#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <vector>

std::vector<std::string> separateValuesWithInputSeparator(std::string input, char separator = ' ')
{
	std::vector<std::string> values;

	for (int i = 0; i < input.size(); ++i)
	{	
		std::string value;
		for ( ; i < input.size() && input.at(i) != separator; ++i)
			value += input.at(i);
		if(!value.empty())
			values.push_back(value);
	}

	return values;
}

class SeparateValuesWithInputSeparatorTest: public ::testing::Test
{
protected:
	std::vector<std::string> result;
	std::string input;
};

TEST_F(SeparateValuesWithInputSeparatorTest, EmptyInput)
{
	input = "";
	result = separateValuesWithInputSeparator(input);
	std::vector<std::string> expected;
	ASSERT_EQ(expected.size(), result.size());
	for (int i = 0; i < expected.size(); ++i)
		EXPECT_EQ(expected[i], result[i]);
}

TEST_F(SeparateValuesWithInputSeparatorTest, OneLetterInput)
{
	input = "A";
	result = separateValuesWithInputSeparator(input);
	std::vector<std::string> expected;
	expected.push_back("A");
	ASSERT_EQ(expected.size(), result.size());
	for (int i = 0; i < expected.size(); ++i)
		EXPECT_EQ(expected[i], result[i]);
}

TEST_F(SeparateValuesWithInputSeparatorTest, OneLetterInputWithSpaceSeparator)
{
	input = "A ";
	result = separateValuesWithInputSeparator(input);
	std::vector<std::string> expected;
	expected.push_back("A");
	ASSERT_EQ(expected.size(), result.size());
	for (int i = 0; i < expected.size(); ++i)
		EXPECT_EQ(expected[i], result[i]);
}

TEST_F(SeparateValuesWithInputSeparatorTest, ThreeLetterInputWithSpaceSeparator)
{
	input = "Aaa ";
	result = separateValuesWithInputSeparator(input);
	std::vector<std::string> expected;
	expected.push_back("Aaa");
	ASSERT_EQ(expected.size(), result.size());
	for (int i = 0; i < expected.size(); ++i)
		EXPECT_EQ(expected[i], result[i]);
}

TEST_F(SeparateValuesWithInputSeparatorTest, ThreeOneLetterInputWithSpaceSeparator)
{
	input = "A a b";
	result = separateValuesWithInputSeparator(input);
	std::vector<std::string> expected;
	expected.push_back("A");
	expected.push_back("a");
	expected.push_back("b");
	ASSERT_EQ(expected.size(), result.size());
	for (int i = 0; i < expected.size(); ++i)
		EXPECT_EQ(expected[i], result[i]);
}

TEST_F(SeparateValuesWithInputSeparatorTest, ThreeWordInputWithSpaceSeparator)
{
	input = "Aaa aaa bbb";
	result = separateValuesWithInputSeparator(input);
	std::vector<std::string> expected;
	expected.push_back("Aaa");
	expected.push_back("aaa");
	expected.push_back("bbb");
	ASSERT_EQ(expected.size(), result.size());
	for (int i = 0; i < expected.size(); ++i)
		EXPECT_EQ(expected[i], result[i]);
}

TEST_F(SeparateValuesWithInputSeparatorTest, ThreeWordInputWithSpaceSeparator)
{


}