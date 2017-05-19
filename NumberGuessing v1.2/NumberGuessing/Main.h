#pragma once
#include <iostream>

//these are the global variables.
int minNumber;
int maxNumber;
int guessNumber;
char isCorrect;
int winner;
char higherOrLower;
int validTurnChecker;




// this function takes in the parameters minNumber and maxNumber
// and preforms the binary search based on this range.
void binarySearch(int minNumber, int maxNumber)
{
	// this varibale is used as a condition for a while loop,
	int winner = 0;

	// while the computer doesnt win, keep performing the binary search.
	while (winner == 0)
	{
		// this parameter is used for a while loop to ensure that the user has the correct input, once for selecting if the guessNumber is correct or not
		// and one for the input of asking if its higher or lower.
		validTurnChecker = 0;
		// determines the number that the computer has guessed.
		guessNumber = (maxNumber + minNumber) / 2;
			
			//while the input is not Y or N, then keep asking the human for valid input.
			while (validTurnChecker == 0)
			{
			std::cout << "Is your guess number..." << guessNumber << "\n\n";
	
			std::cout << "Please input Y for yes and N for no." << "\n\n";

			std::cin >> isCorrect;
			// if the human says Yes, then tell the human that the computer wins.
			if (isCorrect == 'Y' || isCorrect == 'y')
			{
				winner = 1;
				system("cls");
				std::cout << "I win!";
				validTurnChecker++;
				system("pause");
				break;

			}

			
			// if the user says that its not the right number, then check first if they are lying. and then ask them if its higher or lower.
			if (isCorrect == 'N' || isCorrect == 'n')
			{
				// If the user lies twice, then the computer will automatically win and tell the player they are lying.
				if (guessNumber == maxNumber || guessNumber == minNumber)
				{
					system("cls");
					std::cout << "You cant lie. be honest." << "\n\n" ;
					winner = 1;
				}
				// increments this variable so that it can then be used to check the input of whether or not the number is higher or lower.
				validTurnChecker++;

				//Once the human gives the computer valid input for yes or no, then test if the input is valid for higher or lower.
				while (validTurnChecker == 1)
				{
					// ask the human for appropirate input
					std::cout << "Is your number higher or lower then the selected number?" << "\n\n";
					std::cout << "Please input H for higher or L for lower." << "\n\n";
					std::cin >> higherOrLower;


					// if its higher, make the minimum number equal to the guess number
					// then default the minimum number to be 0 and increment validTurnChecker so that this loop doesnt happen.
					if (higherOrLower == 'H' || higherOrLower == 'h')
					{
						minNumber = guessNumber;
						guessNumber = 0;
						validTurnChecker++;
					}

					// if its higher, make the maximum number equal to the guess number
					// then default the maximum number to be 0 and increment validTurnChecker so that this loop doesnt happen.
					else if (higherOrLower == 'L' || higherOrLower == 'l')
					{
						maxNumber = guessNumber;
						guessNumber = 0;
						validTurnChecker++;

					}
					
					// this output shows the human that their input was invalid for higher or lower.
					else
					{
						std::cout << "Please input H for higher or L for lower. Invalid input.";
					}
				}
			}
			// this output shows the human that their input was invalid for yes or no.
			else
			{
				std::cout << "Please input Y for yes or N for no. Invalid input." << "\n\n";
			}

		}
	}



	
}

// this function takes in the parameters minNumber and maxNumber
// and preforms the linear search based on this range.
void linearSearch(int minNumber, int maxNumber)
{
	
	for (minNumber; minNumber <= maxNumber;)
	{
		guessNumber = minNumber;
		std::cout << "Is your guess number..." << guessNumber << "\n\n";
		std::cout << "Please input Y for yes and N for no." << "\n\n";
		std::cin >> isCorrect;

		if (isCorrect == 'Y' || isCorrect == 'y')
		{
			winner = 1;
			system("cls");
			std::cout << "I win!";
			validTurnChecker++;
			system("pause");
			break;

		}
		else if (isCorrect == 'N' || isCorrect == 'n')
		{
			minNumber++;
			
		}
		else
		{
			std::cout << "Please input Y for yes or N for no. Invalid input." << "\n\n";
		}
	
		if ((guessNumber == maxNumber) && (isCorrect == 'N' || isCorrect == 'n'))
		{
			winner = 1;
			system("cls");
			std::cout << "You are lying." << "\n\n";
			std::cout << "I win!";
			validTurnChecker++;
			system("pause");
			break;
		}
	}

}