/*
 * Name: Ben Marmoll
 * Date: 7/4/2019
 * Section: 3
 * Assignment: #4
 * Due Date: 7/10/2019
 * About this project: Class myInt creates an array of integers to create a longer integer variable to be used
 * Assumptions: Assumes first non-whitespace character is a digit
 * 
 * All work was performed by Ben Marmoll
 *
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;

#ifndef _myInt_
#define _myInt_

class MyInt
{
	private:
		int size;
		int *num;
	public:
		//default constructor
		MyInt();
		//parameterized constructor
		MyInt(int z);
		//conversion constructor
		MyInt(char z[]);
		//destructor
		~MyInt();
		//copy constructor
		MyInt(const MyInt &i1);	
		//assignment operator overload
		MyInt& operator= (const MyInt &i1);
		//grow and shrink functions
		void grow();
		void shrink(); 
		//stream operator overloads
		friend ostream& operator<< (ostream &out, const MyInt &i1);
		friend istream& operator>> (istream &in, MyInt &i1); 
		//comparsion operator overloads
		bool operator< (const MyInt &i1);
		bool operator> (const MyInt &i1);
		bool operator<= (const MyInt &i1);
		bool operator>= (const MyInt &i1);
		bool operator== (const MyInt &i1);
		bool operator!= (const MyInt &i1);
		//addition operator overload
		MyInt operator+ (const MyInt &i1);
		//multiplication operator overload
		MyInt operator* (const MyInt &i1);
		//pre and post increment operator overloads
		MyInt& operator++ ();
		MyInt operator++ (int);

		//extra credit
		//overload subtraction operator
		MyInt operator- (const MyInt &i1);
		//division and modolus operator overloads
		MyInt operator/ (const MyInt &i1);
		MyInt operator% (const MyInt &i1);
};

#endif

