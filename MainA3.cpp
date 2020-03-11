//Done by: Aaron Lim
//I did not pass my assignment to anyone in the class
//or copy anyone's work and I am willing to accept
//whatever penalty given to me and also to all the
//related parties involved

#include "CustomerQueue.h"

char displayMain(char);
void displayEnqueue(CustomerQueue&);
void displayDequeue(CustomerQueue&);
void displayPrint(CustomerQueue&);

int main()
{
	srand(time(NULL));
	CustomerQueue s;
	
	char ok;
	do
	{
		ok = displayMain(ok);
		char *name;
		name = new char [MAX];
		char sex;
		int age = 0;
		
		ok = tolower(ok);
		
		switch (ok)
		{
			case 'e': displayEnqueue(s);
					  break;
			case 'd': displayDequeue(s);
					  break;
			case 'p': displayPrint(s);
					  break;
			case 'q': cout << "\nAaron bank closed for service"
						   << endl;
		}
			
	}while (ok != 'q');
}

char displayMain(char ok)
{
	cout << "Welcome to Aaron Bank"
		 << "\n\n\t(E)nqueue"
		 << "\n\t(D)equeue"
		 << "\n\t(P)rint queue"
		 << "\n\t(Q)uit"
		 << "\n\nYour option: ";
	cin >> ok;
	return ok;
}
void displayEnqueue(CustomerQueue& s)
{
	char n[MAX];
	char sex;
	int age;
		 	  	   	       
	cout << "----------------------------------------"
		 << endl;	
	do
	{	    	    	   	      	      
		cout << "Queue services"
			 << endl;

		cin.clear();
		cin.ignore(100, '\n');

		cout << "\nMay I have your name: ";
		cin.getline(n, MAX);

		cout << "Enter customer type"
			 << "\n\t(S)enior"
			 << "\n\t(L)ady"
			 << "\n\t(O)ther"
			 << "\n\t(Q)uit"
			 << "\n\nYour Type: ";
		cin >> sex;
		
		sex = toupper(sex);
		
		if (sex == 'S' && age != 0)
		{
			cout << "Your age: ";
			cin >> age;
			Customer c (n, age);
			CustomerType ct = Senior;
			s.enqueue(c, ct);
			c.printCust();
			cout << " added to queue"
				 << "\n----------------------------------------"
				 << endl;
		}
		
		else if (sex == 'L')
		{
			Customer c (n, 'F');
			CustomerType ct = Lady;
			s.enqueue(c, ct);
			c.printCust();
			cout << " added to queue"
				 << "\n----------------------------------------"
				 << endl;
		}
		
		else if (sex == 'O')
		{
			Customer c (n);
			CustomerType ct = Other;
			s.enqueue(c, ct);
			c.printCust();
			cout << " added to queue"
				 << "\n----------------------------------------"
				 << endl;
		}
		
		else if (sex == 'Q')
		{
			cout << "\n----------------------------------------"
				 << endl;	   	   	   	       	     
		}	 	 
	}while(sex != 'Q');
}

void displayDequeue(CustomerQueue& s)
{
	cout << "----------------------------------------"
		 << endl;
	
	Customer c;	    	
	
	int custType = rand() % 3;
	
	if (custType == 0)
	{
		try
		{
			cout << "Serving Senior"
				 << endl;
			CustomerType type = Senior;
			
			if (!s.senIsEmpty())
			{
				c = s.dequeue(type);
				c.printCust();
				cout << " was served";
			}
			else
				throw exception();
		}
		catch (exception e)
		{
			cout << "Senior queue empty exception caught";
		}
	}
	
	else if (custType == 1)
	{
		try
		{
			cout << "Serving Lady"
				 << endl;
			CustomerType type = Lady;
			
			if (!s.ladIsEmpty())
			{
				c = s.dequeue(type);
				c.printCust();
				cout << " was served";
			}
			else
				throw exception();
		}
		catch (exception e)
		{
			cout << "Lady queue empty exception caught";
		}
	}
	
	else if (custType == 2)
	{
		try
		{
			cout << "Serving Other"
				 << endl;
			CustomerType type = Other;
			
			if (!s.othIsEmpty())
			{
				c = s.dequeue(type);
				c.printCust();
				cout << " was served";
			}
			else
				throw exception();
		}
		catch (exception e)
		{
			cout << "Other queue empty exception caught";
		}
	}	  	  
	
	cout << "\n----------------------------------------"
		 << endl;	   	   	   
}

void displayPrint(CustomerQueue& s)
{
	char printOption;
	
	cout << "-----------------------------------------------------------------------"
		 << endl;
	do
	{
		cout << "Queue information"
			 << "\n\n\t(W)hole queue info"
			 << "\n\t(S)enior queue info"
			 << "\n\t(L)ady queue info"
			 << "\n\t(O)ther queue info"
			 << "\n\t(Q)uit"
			 << "\n\nYour option: ";
		cin >> printOption;
		
		printOption = tolower(printOption);
		
		if (printOption == 'w')
		{
			if (!s.genIsEmpty())
				s.genPrintQueue();
			
			else
				cout << "General queue is empty"
					 << "\n------------------------------------------------------------------"
					 << endl;
		}
		
		else if (printOption == 's')
		{
			if (!s.senIsEmpty())
				s.senPrintQueue();
			
			else
				cout << "Senior queue is empty"
					 << "\n------------------------------------------------------------------"
					 << endl;	   	   
		}
		
		else if (printOption == 'l')
		{
			if (!s.ladIsEmpty())
				s.ladPrintQueue();
			
			else
				cout << "Lady queue is empty"
					 << "\n------------------------------------------------------------------"
					 << endl;	   	   
		}
		
		else if (printOption == 'o')
		{
			if (!s.othIsEmpty())
				s.othPrintQueue();
			
			else
				cout << "Other queue is empty"
					 << "\n------------------------------------------------------------------"
					 << endl;	   	   
		}	
		
		else if (printOption == 'q')
		{
			cout << "-----------------------------------------------------------------------"
				 << endl;
		}   	    	
		
	}while (printOption != 'q');	 	 	 
}

