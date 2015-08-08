//Contestant :			02-0861-0001
//Name:					Jesse Mitchell
//CPP_335_02_0861_0001.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>

using namespace System;
using namespace std;

//Gets the next Leibniz.
// 1/3, 1/5, etc.
double nextLeibniz(int nPos)
{
	
	return (1.0 / (nPos*2+1));
	
}


//Gets the Leibniz Approximation to the Given Terms.
double Leibniz(int values)
{
	double ans = 1;
	for (int i = 1; i < values + 1; i++)
	{
		if (i % 2 == 0) //If even, add, if odd, subtract
		ans += nextLeibniz(i);
		else
		ans -= nextLeibniz(i);

	}

	return ans * 4;

}

//The Main Function that is called when the program is run.
int main(array<System::String ^> ^args)
{
	
	try 
	{
		//Gets the N position to calculate to in the Leibniz Series.
		printf("The value of n in the Leibniz Series:\t\t\t");
		String ^ number = Console::ReadLine()->Replace(",", ""); //Gets a Number to be parsed, gets rid of commas.
		int n = Int32::Parse(number);  
	
		if (n > 0)
		{
			double ans = Leibniz(n); //Gets the Pi Leibniz Approx
			double actualPi = 3.1415926535897925; //Real Pi
			double approx227 = 22.0 / 7; //Approx of 22 and 7
			double approx355 = 355.0 / 113; // Approx of 355 and 113

			//Print F is used to limit and restrict the formatting
			printf("The Leibniz Series approximation of PI at n is: \t%1.15f\n\n", ans);
			
			printf("The known value of PI to 15 decimals points: \t\t%1.15f\n", actualPi);
			printf("The different between PI and the Leibniz series: \t%1.15f\n\n", abs(actualPi - ans)); //Calculated using real values.

			printf("The approximation of PI using 22 / 7: \t\t\t%1.15f\n", approx227);
			printf("The different between PI and the Leibniz series: \t%1.15f\n\n", abs(approx227 - ans)); //Same

			printf("The approximation of PI using 355 / 133: \t\t%1.15f\n", approx355);
			printf("The different between PI and the Leibniz series: \t%1.15f\n", abs(approx355 - ans)); //Same

		}
		else
		{
			//The number was negative.
			Console::WriteLine("You needed to enter a positive number.");
		}
	}
	catch (Exception ^ ex)
	{
		//The number was not added properly.
		Console::WriteLine("You needed to enter a positive number.");
	}
	Console::ReadLine(); //Pauses the program for the judges.
    return 0;
}
