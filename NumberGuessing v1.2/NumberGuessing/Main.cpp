#include "Main.h"

int main()



{
	char searchChoice;
	int validChoiceChecker = 0;


	// Ask the user for the range in which the computer will guess. and they will be stored in minNumber and maxNumber.
	std::cout << "Please input a range for me to guess." << "\n\n";
	std::cout << "First, please give me the minimum number of the range." << "\n\n";
	std::cin >> minNumber;
	std::cout << "Now, please give me the maximum number of the range." << "\n\n";
	std::cin >> maxNumber;

	// asks the use which search they would like to use out of a linear or a binary search using
	// l for linear or b for binary.

	std::cout << "Would you like to use a binary search or a linear search?" << "\n\n";
	while (validChoiceChecker == 0)
	{
		std::cout << "Please input l for linear or b for binary." << "\n\n";
		std::cin >> searchChoice;


		// if the input is valid choice for a binary search 
		// preform the binarySearch function.
		if (searchChoice == 'b' || searchChoice == 'B')
		{

			// this preforms a search for the correct number based upon a binary search.
			validChoiceChecker++;
			binarySearch(minNumber, maxNumber);
		}

		// if the input is valid choice for a binary search 
		// preform the binarySearch function.
		else if (searchChoice == 'l' || searchChoice == 'L')
		{
			// this preforms a search for the correct number based upon a linear search.
			validChoiceChecker++;
			linearSearch(minNumber, maxNumber);
			
		}

		// if the input is valid, prompt the user that its wrong.
		else
		{
			std::cout << "Please input either l for linear or b for binary search." << "\n\n";
		}
	}
}
