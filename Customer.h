//Done by: Aaron Lim
//I did not pass my assignment to anyone in the class
//or copy anyone's work and I am willing to accept
//whatever penalty given to me and also to all the
//related parties involved

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>

const int MAX = 20;

using namespace std;

class Customer
{
	public:
		//default constructor
		Customer();
		
		//4 constructors 
			//overload constructor
			//Senior customer
		Customer(char *, int);
			
			//Lady customer
		Customer(char *, char);
			
			//Other customer
		Customer(char *);
		
			//copy constructor
		Customer copyCust (const Customer&);
	
		//to print out the customer
		void printCust () const;
		
		//destructor
		~Customer();
		
		//accessor
		char getName () const;
		int getAge () const;
		char getSex () const;
		
		//mutator
		void setName (char *);
		void setAge (int);
		void setSex (char);
		
	private:
		char *name;
		int age;
		char sex;
};	

