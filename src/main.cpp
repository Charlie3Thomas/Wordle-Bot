#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main()
{
	std::string word;
	std::vector<std::string> wordle_answers;
	std::vector<std::string> wordle_guesses;
	std::ifstream ifs_w_ans("D:/Code/Wordle-Bot/resources/wordle_answers.txt");
	std::ifstream ifs_w_gss("D:/Code/Wordle-Bot/resources/wordle_guesses.txt");

	if (ifs_w_ans.is_open() == false)
	{
		std::cout << "Wordle answers file not found!" << std::endl;
	}
	else
	{
		std::cout << "Wordle answers file found!" << std::endl;
	}

	if (ifs_w_gss.is_open() == false)
	{
		std::cout << "Wordle guesses file not found!" << std::endl;
	}
	else
	{
		std::cout << "Wordle guesses file found!" << std::endl;
	}

	
	while (ifs_w_ans >> word)
	{
		wordle_answers.push_back(word);
	}

	while (ifs_w_gss >> word)
	{
		wordle_guesses.push_back(word);
	}

	std::cout << "PRINTING ANSWERS" << std::endl;
	for (std::string answer : wordle_answers)
	{		
		std::cout << answer << std::endl;
	}

	std::cout << "PRINTING GUESSES" << std::endl;
	for (std::string guess : wordle_guesses)
	{		
		std::cout << guess << std::endl;
	}

	return 0;
}