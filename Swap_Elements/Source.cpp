#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::getline;
using std::istringstream;
using std::vector;
using std::stoi;
using std::swap;

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	string line;
	while (getline(ifs, line))
	{
		vector<int> list_of_numbers;
		istringstream iss(line);
		string temp1, temp2;

		// Get list of numbers
		getline(iss, temp1, ':');

		// Convert each number to int, and store in vector
		istringstream iss_num(temp1);
		while (getline(iss_num, temp2, ' '))
		{
				int number = stoi(temp2);
				list_of_numbers.push_back(number);
		}

		// Get position numbers and swap numbers in vectors accordingly
		while (getline(iss, temp1, ','))
		{
			// Remove space at beginning of string
			temp1.erase(0, 1);

			istringstream iss_swap(temp1);
			string temp2;
			int position1 = 0, position2 = 0;

			// Get first position value and store into position1
			getline(iss_swap, temp2, '-');
			position1 = stoi(temp2);

			// Get second position value and store into position1;
			getline(iss_swap, temp2, '-');
			position2 = stoi(temp2);

			//Swap values in vector according to position values
			swap(list_of_numbers[position1], list_of_numbers[position2]);
		}
		// Print list of numbers
		for (auto &n : list_of_numbers)
		{
			cout << n << " ";
		}
		cout << endl;
	}

	return 0;
}