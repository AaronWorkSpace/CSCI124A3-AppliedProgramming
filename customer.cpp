//Done by: Aaron Lim
//I did not pass my assignment to anyone in the class
//or copy anyone's work and I am willing to accept
//whatever penalty given to me and also to all the
//related parties involved

#include "Customer.h"

//default constructor
Customer::Customer()
{
	this -> age = 0;
	this -> sex = '0';
}
		
//4 constructors 
//overload constructor
//Senior customer
Customer::Customer(char *n, int age)
{
	name = new char [MAX];
	strcpy (this -> name, n);
	this -> age = age;
	this -> sex = '0';
}
			
//Lady customer
Customer::Customer(char *n, char sex)
{
	name = new char [MAX];
	strcpy (this -> name, n);
	this -> sex = sex;
	this -> age = 0;
}
			
//Other customer
Customer::Customer(char *n)
{
	name = new char [MAX];
	strcpy (this -> name, n);
	this -> sex = 'M';
	this -> age = 0;
}
		
//copy constructor
Customer Customer::copyCust (const Customer& c)
{
	name = new char [MAX];
	strcpy (this -> name, c.name);
	this -> sex = c.sex;
	this -> age = c.age;
}


//to print out the customer
void Customer::printCust () const
{
	if (sex == '0' && age != 0)
		cout << "Senior " << name 
			 << " (age: " << age
			 << ")";
			 
	else if (age == 0)
	{	 
		if (sex == 'F')
		{
			cout << "Miss " << name;
		}
		
		else if (sex == 'M')
		{
			cout << "Mr " << name;
		}	 
	}
}

//destructor
Customer::~Customer()
{

}
		
//accessor
char Customer::getName () const
{
	return *name;
}

int Customer::getAge () const
{
	return age;
}

char Customer::getSex () const
{
	return sex;
}

//mutator
void Customer::setName (char *n)
{
	strcpy (name, n);
}

void Customer::setAge (int a)
{
	age = a;
}

void Customer::setSex (char s)
{
	sex = s;
}
		

