/*Name: Ben Marmoll
 *Date: 6/3/19
 *Section: 3
 *Assignment: #4
 *Due Date: 7/10/19
 *About this project: Class myInt creates an array of integers to create a longer, and usable interger variable
 *Assumptions: Assumes first non-whitespace character is a digit
 *
 * All work below was performed by Ben Marmoll
 */

#include "myInt.h"

//default constructor
MyInt::MyInt()
{
	size = 1;
	num = new int[size];
	num[0] = 0;
	//sets only element of num array to 0, default
}

//paramterized constructor
MyInt::MyInt(int z)
{
	size = 1;
	if (z < 0) //if z is negative, size is 1 and first element is 0
		num[0] = 0;
	else
	{
		for(int i=z; i>10; i/10)
			size++;
		for(int i=1; i<=size; i++)
		{
			num[size-i] = z%10;
			z = z/10;
		}
	}
	//if z is not negative, size is based on the powers of 10, the remainder of each element is found starting at the end of the array
}

//conversion constructor
MyInt::MyInt(char z[])
{
	bool run = true;
	int count = 0;
	size = 1;
	do
	{
		if(z[count] > 47 && z[count] < 58)
			count++;
		else
		{
			run = false;
			count = 0;
		}
	}while(run == true);
	//count equals the number of digit characters in the array
	size = count+1;
	num = new int[size];
	//num is set to the new size
	for(int i=0; i<size; i++)
		num[i] = z[i];
	//each element of the new size is set equal to the digit characters in the array
}

//destructor
MyInt::~MyInt()
{
	delete []num;
	//deletes dynamic array
}

//copy constructor
MyInt::MyInt(const MyInt &i1)
{
	*this = i1;
	//sets calling object equal to the parameter object
}

//assignment operator overload
MyInt& MyInt:: operator= (const MyInt &i1)
{
	size = i1.size;
	//sets calling int size to the parameter's size (elements will match on for loop)
	num = new int[size];
	//recreates num object to new size
	for(int i=0; i<size; i++)
		num[i] = i1.num[i];
	//sets all of the calling object's array's elements to that of the parameter object's
	return *this;
	//returns new calling object;
}

//grow function
void MyInt:: grow()
{
	int count = 0;
	size++;
	//increases size by 1
	for(int i=size-1; i>size-7; i--)
	{
		if(num[i] < 48 && num[i] > 57)
			count++;
	}
	//checks the end of the array for non-digits and/or whitespace
	if(count>4)
		size=size-5;
	//if the last 5 elements are non-digit or whitespace, the size is reduced
	int temp[size];
	//temporary int array of new shorter size, or original size
	for(int i=0; i<size; i++)
		temp[i] = num[i];
	//sets temp int to that of calling object
	num = new int[size];
	//recreates num to new size, or to original size
	for(int i=0; i<size; i++)
		num[i] = temp[i];
	//sets the new num array equal to that of the temp
}

//shrink function
void MyInt:: shrink()
{
	int temp[size];
	//creates temp int array same size as the calling object's
	for(int i=0; i<size;i++)
		temp[i] = num[i];
	//sets temp equal to the calling object's array
	size--;
	//reduces size by 1
	num = new int[size];
	//recrreates num to new size
	for(int i=0; i<size; i++)
		num[i] = temp[i];
	//sets new num array to that of temp
}

//stream operator overloads
ostream& operator<< (ostream &out, const MyInt &i1)
{
	for(int i=0; i<i1.size; i++)
		out << i1.num[i];
}

istream& operator>> (istream &in, MyInt &i1)
{
	for(int i=0; i<i1.size; i++)
		in >> i1.num[i];
}

//comparison operator overloads
bool MyInt:: operator< (const MyInt &i1)
{
	if(size < i1.size)
		return true;
	//if calling object is less, it is the smaller number
	else if(size > i1.size)
		return false;
	else //if size of both objects are equal
	{
		for(int i=0; i<size; i++)
		{
			if(num[i] < i1.num[i])
				return true;
			else if(num[i] > i1.num[i])
				return false;
			if(i == size && num[i-1] == i1.num[i-1])
				return false;
		}
	}
}

bool MyInt:: operator> (const MyInt &i1)
{
	if(size > i1.size)
		return true;
	else if(size < i1.size)
		return false;
	else
	{
		for(int i=0; i<size; i++)
		{
			if(num[i] > i1.num[i])
				return true;
			else if(num[i] < i1.num[i])
				return false;
			if(i == size && num[i-1] == i1.num[i-1])
				return false;
		}
	}
}

bool MyInt:: operator<= (const MyInt &i1)
{
	if (size < i1.size)
		return true;
	else if(size > i1.size)
		return false;
	else
		for(int i=0; i<size; i++)
		{
			if(num[i] < i1.num[i])
				return true;
			else if(num[i] > i1.num[i])
				return false;
			if(i == size && num[i-1] == i1.num[i-1])
				return true;
		}
}

bool MyInt:: operator>= (const MyInt &i1)
{
	if (size > i1.size)
		return true;
	else if (size <i1.size)
		return false;
	else
	{
		for(int i=0; i<size; i++)
		{
			if(num[i] > i1.num[i])
				return true;
			else if(num[i] < i1.num[i])
				return false;
			if(i == size && num[i-1] == i1.num[i-1])
				return true;
		}
	}
}

bool MyInt:: operator== (const MyInt &i1)
{
	int count = 0;
	if(size != i1.size)
		return false;
	else
	{
		for(int i=0; i<size; i++)
		{
			if(num[i] != i1.num[i])
				return false;
			else
				count++;
		}
		if(size == count)
			return true;
	}
}

bool MyInt:: operator!= (const MyInt &i1)
{
	int count = 0;
	if(size != i1.size)
		return true;
	else
	{
		for(int i=0; i<size; i++)
		{
			if(num[i] != i1.num[i])
				return true;
			else
				count++;
		}
		if(size == count)
			return false;
	}
}

//addition operator overload
MyInt MyInt:: operator+ (const MyInt &i1)
{
	MyInt number; //creates new int
	if(size < i1.size)
		size = i1.size; //determines bigger number
	for(int i=0; i<size; i++)
	{
		number.num[i] = this->num[i] + i1.num[i]; 
		if(number.num[i] > 9)
		{
			number.num[i] = number.num[i] - 10;
			if(i == 0)
				size++;
		}
	}
	return number;
}

//multiplication operator overload
MyInt MyInt:: operator* (const MyInt &i1)
{
	MyInt number; //creates new int
	if(*this < i1)
		size = i1.size; //determines bigger number
	for(int i=0; i<size; i++)
	{
		number.num[i] = this->num[i] * i1.num[i];
		if(number.num[i] > 9)
		{
			number.num[i] = number.num[i] - 10;
			if(i == 0)
				size++;
		}
	}
	return number;
}

//pre and post increment operator overloads
MyInt& MyInt:: operator++ ()
{
	if(num[size-1] == 9)
	{
		size++;
		num[size-1] = 1;
		num[size] = 0;
	}
	else
		num[size-1]++;
	return *this;
}

MyInt MyInt:: operator++ (int)
{
	MyInt temp(*this);
	++(*this);
	return temp;
}

//extra credit

//subtraction operator overload
MyInt MyInt:: operator- (const MyInt &i1)
{
	MyInt number; //creates newint
	if (*this < i1)
		size = i1.size; //determines larger number
	for(int i=0; i<size; i++)
	{
		number.num[i] = number.num[i] - i1.num[i];
		if(number < 0)
			number = 0;
		else if(number.num[i] < 0)
		{
			number.num[i] +10;
			number.num[i-1] -1;
		}
	}
	return number;
}

//division and modolus operator overloads
MyInt MyInt:: operator/ (const MyInt &i1)
{
	MyInt temp;
	MyInt temp2;
	if (*this < i1)
		size = i1.size;
	for(int i=size-1; i>=0; i--)
	{
		//temp = temp + (*this->num[i]*(size-i * i);
		//temp2 = temp2 + (i1.num[i]*(size-i * i);	
	}
}

MyInt MyInt:: operator% (const MyInt &i1)
{
	MyInt temp = *this/i1;
	temp = temp*i1;
	MyInt remainder = *this-temp;
	return remainder;
}


