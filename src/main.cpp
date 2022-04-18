#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <random>

std::array<int, 5> compare(std::string _sol, std::string _sup);
void eliminate_supports(std::string _guess, std::array<int, 5> _result);

int main()
{
	std::ifstream ifs_w_sol("D:/Code/Wordle-Bot/resources/wordle_answers.txt");
	std::ifstream ifs_w_sup("D:/Code/Wordle-Bot/resources/wordle_guesses.txt");
	std::vector<std::string> wordle_solutions;
	std::vector<std::string> wordle_supports;
	std::string word;

	if (ifs_w_sol.is_open() == false)
	{
		std::cout 
			<< "Wordle answers file not found!" 
			<< std::endl;
	}

	if (ifs_w_sup.is_open() == false)
	{
		std::cout 
			<< "Wordle guesses file not found!" 
			<< std::endl;
	}
	
	while (ifs_w_sol >> word)
	{
		wordle_solutions.push_back(word);
	}

	while (ifs_w_sup >> word)
	{
		wordle_supports.push_back(word);
	}

	std::vector<int> wdl_sup(wordle_supports.size());


	/*
		Select a random solution and starting support.
	*/
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr_sol(0, wordle_solutions.size());
	std::uniform_int_distribution<> distr_sup(0, wordle_supports.size());
	std::string answer = wordle_solutions[distr_sol(gen)];
	std::string guess = wordle_supports[distr_sup(gen)];

	std::cout 
		<< "Solution is: "
		<< answer 
		<< std::endl;

	std::cout 
		<< "Support is: "
		<< guess 
		<< std::endl;

	std::array<int, 5> comparison_result = compare(answer, guess);
	//std::array<int, 5> comparison_result = compare("abbaq", "babqx");

	for (int i = 0; i < comparison_result.size(); i++)
	{
		std::cout
			<< comparison_result[i]
			<< " ";
	}

	std::cout << std::endl;

	return 0;
}

std::array<int, 5> compare(std::string _sol, std::string _sup)
{
	std::array<int, 5> _compare { 0, 0, 0, 0, 0 };

	// Check for matching letters.
	for (int sol = 0; sol < 5; sol++)
	{
		for (int sup = 0; sup < 5; sup++)
		{
			if (_sol[sol] == _sup[sup])
			{
				_compare[sup] = 1;
			}
		}
	}

	// Check for matching letters in correct position.
	for (int i = 0; i < 5; i++)
	{
		if (_sol[i] == _sup[i])
		{
			_compare[i] = 2;
		}
	}

	return _compare;
}

void eliminate_supports(std::string _guess, std::array<int, 5> _result)
{
	/*
		Example result 01002:
			First letter is not used.
			Second letter is used, but in another position.
			Third letter is not used.
			Fourth letter is not used.
			Fifth letter is used in this position.

		If there are any "2" results in _result, eliminate all supports that do not
		have this letter in this position.

		Take in string
		Take in _result array
		if any position in _result contains 2, remove all words that do not have letters in the same places
		if any position in _result contains 1, remove all words that do not contain those letters
		if any position in _result contains 0, remove all words that contain those letters

		For string.size -> loop through each char	
	*/
}