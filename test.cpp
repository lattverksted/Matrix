/** @file test.cpp 
	@brief		code to test matrix class
 	@author		Colombe M'boungou
   	@date		January 2020
 */

#include "Matrix.h"
#include <stdio.h>
#include <iostream>

using namespace std;



int main()
{
	
	std::cout << "start" << endl;

	Matrix ones =  Matrix(4, 3, 1);
	cout << "m\t";
	ones.display();

	Matrix i = i.Identity(3, 4) * 5.0 ;
	cout << "i\t";
	i.display();

	Matrix s = ones * i;
	cout << "i * m\t";
	s.display();
	cout << "end" << endl;
}