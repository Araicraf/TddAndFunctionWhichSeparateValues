#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <vector>
#include <utility> 

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

class SeparateValuesWithInputSeparatorTest: public ::testing::TestWithParam<const std::string>
{
protected:
	std::vector<std::string> result;
	std::string input;
};

TEST_P(SeparateValuesWithInputSeparatorTest, FromEmptyInputToDiffrentStringsInput)
{
	input = GetParam(); // string wejsciowy
	result = separateValuesWithInputSeparator(input); // zapisuje wynik funkcji
	std::vector<std::string> expected; // vector ktory wyglada tak jak wektor ktorego sie spodziewamy
	ASSERT_EQ(expected.size(), result.size()); // czy otrzymany wektor ma rozmiar jaki powinien miec?
	for (int i = 0; i < expected.size(); ++i)
		EXPECT_EQ(expected[i], result[i]); // sprawdza kazdy el w wektorze
}

const std::string input[6] = {"", "A", "A ", "Aaa ", "A a b", "Aaa aaa bbb"};

const std::vector<std::string> output[6];
output[1].push_back("A");
output[2].push_back("A");
output[3].push_back("Aaa");
output[4].push_back("A");
output[4].push_back("a");
output[4].push_back("b");
output[5].push_back("Aaa");
output[5].push_back("aaa");
output[5].push_back("bbb"); // najpierw tworze 6 wektorow a potem tablice wektorow i przypisac w klamrach { }

std::pair <std::string, std::vector<std::string> > paramArguments[6];
for(unsigned int i = 0; i < 6; ++i)
	paramArguments[i] = std::make_pair(input[i], output[i]);


// tablica par
INSTANTIATE_TEST_CASE_P(InstantiationName,
                        SeparateValuesWithInputSeparatorTest,
                        ::testing::ValuesIn(paramArguments));




//TEST_P(SeparateValuesWithInputSeparatorTest, ThreeWordInputWithSpaceSeparator)
//{
//
//
//}
	//input ""

	//input = "A";
	//expected.push_back("A");

	//input = "A ";
	//expected.push_back("A");

	//input = "Aaa ";
	//expected.push_back("Aaa");

	//input = "A a b";
	//expected.push_back("A");
	//expected.push_back("a");
	//expected.push_back("b");

 //"Aaa aaa bbb";
	//expected.push_back("Aaa");
	//expected.push_back("aaa");
	//expected.push_back("bbb");