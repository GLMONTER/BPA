// bpa_reg_2016.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <cstdlib>

void generatePerfectNumbers()
{
	//the dynamic arrays for the perfect numbers and the divisors for the perfect numbers.
	std::vector<int> perfectNumbers;
	std::vector<int> divisors;

	//soon to be equal to the sum of all of the divisors, used to check if all divisors is equal to the beginning number.
	int sum = 0;
	//start at 1 for the perfect number to calculate the perfect numbers and go up to 1000
	for (int num = 1; num != 1000; num++)
	{
		//check every number below the perfect number down to zero to see if we find a divisor for the perfect number
		for (int i = num - 1; i != 0; i--)
		{
			//if the number somewhere below the perfect number divided by the perfect number is == 0, then it means we have a divisor,
			//the perfect use for the modulo operator.
			if (num % i == 0)
			{
				//push the divisor back into the divisors vector used for calculations later.
				divisors.push_back(i);
			}
		}
		//add up all of the divisors to see if they equal the perfect number
		for (int nums : divisors)
		{
			sum += nums;
		}
		//if the sum is equal to the perfect number, then push num back into the perfectNumber vector to print them later.
		if (sum == num)
		{
			perfectNumbers.push_back(num);
		}
		//set the sum = 0 and clear the divisor vector to start the next number.
		sum = 0;
		divisors.clear();
	}
	//print this to tell the user we are giving them all of the perfect numbers.
	std::cout << "Here is all of the perfect numbers less than 1000." << std::endl;
	//for every perfect number in the vector, print it.
	for (int pn : perfectNumbers)
	{
		std::cout << pn << std::endl;
	}
}

void generateFibonacciNumbers()
{
	//the number we will print to the console and the front most number.
	int curNUM = 1;
	//the number just behind "curNUM" used in the calculation.
	int front = 0;
	//the number just behind "front", but two behind "curNUM" also used in the calculations.
	int back = 0;

	//calculate the fibonacci number 20 times as stated in the instructions.
	for (int i = 0; i != 20; i++)
	{
		//move everything forward in the sequence after the iteration so we can calculate.
		back = front;
		front = curNUM;
		//print the fib number
		std::cout <<"Fibonacci #"<<i + 1<<" is : "<< curNUM << std::endl;

		//perform the calculation for the next print and flip sequence.
		curNUM = front + back;
	}
}

int main()
{
	std::cout << "Special Number Generator" << std::endl;
	std::cout << "1) Calculate Fibonacci Number" << std::endl;
	std::cout << "2) Calculate Perfect Numbers" << std::endl;
	std::cout << "3) Exit Program" << std::endl;


	std::cout << "Please Select an Option : ";
	int input;
	std::cin >> input;

	std::cout << std::endl;
	if (std::cin.fail())
	{
		std::cerr << "Invalid Operation" << std::endl;
		std::cerr << "Input is not 1, 2, or 3" << std::endl;
		input = 0;
		std::system("cls");
		main();
	}

	if (input > 3 || input < 1)
	{
		std::cerr << "Invalid Operation" << std::endl;
		std::cerr << "Input is not 1, 2, or 3" << std::endl;
		input = 0;
		std::system("cls");
		main();
	}

	if (input == 1)
		generateFibonacciNumbers();
	if (input == 2)
		generatePerfectNumbers();
	if (input == 3)
		exit(EXIT_SUCCESS);
	
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
