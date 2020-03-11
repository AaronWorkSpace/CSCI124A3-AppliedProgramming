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

enum CustomerType {Senior, Lady, Other};

class CustomerQueue
{
	public:
		//default customer
		CustomerQueue ();
		
		//Destructor
		~CustomerQueue ();
		
		//Overloaded constructor
		CustomerQueue (Customer);
		
		// enqueue function
		void enqueue(Customer, CustomerType);
		
		// dequeue function
		int removeFromTail();
		int removeFromHead();
		Customer dequeue(CustomerType);
			   
		// four isEmpty functions
		bool genIsEmpty () const;
		bool senIsEmpty () const;
		bool ladIsEmpty () const;
		bool othIsEmpty () const;
		
		// four printQueue functions
		void genPrintQueue () const;
		void senPrintQueue () const;
		void ladPrintQueue () const;
		void othPrintQueue () const;
		
		// some other useful functions
		
	private:
		struct Node;
		typedef Node* NodePtr;
		struct Node
		{
			CustomerType ct;
			Customer cust;
			NodePtr next;
		};
		
		NodePtr head, tail; 

		bool findNode (NodePtr&, NodePtr&, int) const;
};


class QueueException
{
	public:
		//default constructor
		QueueException ();
		
		//overload constructor
		QueueException (char *);
		
		//return the message
		const char* what () const;
		
	private:
		const char *message;
};

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
		
CustomerQueue::CustomerQueue()
{
	head = NULL;
	tail = NULL;
}
		
CustomerQueue::~CustomerQueue()
{
	
}
		
CustomerQueue::CustomerQueue (Customer)
{
	
}

bool CustomerQueue::genIsEmpty () const
{
	NodePtr temp = new Node;
	temp = head;
	
	if (head == NULL)
		return true;
		
	else
	{
		while (temp != NULL)
		{
			if (temp -> ct == 0 || temp -> ct == 1 || temp -> ct == 2)
				return false;
			
			else 
				temp = temp -> next;
		}
	}
	
	return true;
}

bool CustomerQueue::senIsEmpty () const
{
	NodePtr temp = new Node;
	temp = head;
	if (head == NULL)
		return true;	
			
	else
	{
		while (temp != NULL)
		{
			if (temp -> ct == 0)
				return false;
			
			else 
				temp = temp -> next;
		}
	}
	
	return true;
}

bool CustomerQueue::ladIsEmpty () const
{	
	NodePtr temp = new Node;
	temp = head;
		
	if (head == NULL)
		return true;
			
	else
	{
		while (temp != NULL)
		{
			if (temp -> ct == 1)
				return false;
			
			else 
				temp = temp -> next;
		}
	}
	
	return true;
}

bool CustomerQueue::othIsEmpty () const
{
	NodePtr temp = new Node;
	temp = head;	
	if (head == NULL)
		return true;
		
	else
	{
		while (temp != NULL)
		{
			if (temp -> ct == 2)
				return false;
			
			else 
				temp = temp -> next;
		}
	}
	
	return true;
}
		
void CustomerQueue::genPrintQueue () const
{
	int i = 1;
	Customer c;
	NodePtr temp = new Node;
	temp = head;
	
	cout << "-----------------------------------------------------------"
		 << endl;
		 	   
	cout << "Whole queue information" << endl;

	while (temp != NULL)
	{
		if (temp -> ct == Senior)
		{
			c = temp -> cust;
			cout << i << ": ";
			c.printCust();
			cout << endl;
			
			i++;
		}   
		temp = temp -> next;
	}
	
	temp = head;
	while (temp != NULL)
	{
		if (temp -> ct == Lady)
		{
			c = temp -> cust;
			cout << i << ": ";
			c.printCust();
			cout << endl;
			
			i++;
		}
		
		temp = temp -> next;
	}
	
	temp = head;
	while (temp != NULL)
	{
		if (temp -> ct == Other)
		{
			c = temp -> cust;
			cout << i << ": ";
			c.printCust();
			cout << endl;
			
			i++;
		}
			
		temp = temp -> next;
	}
	
	cout << "-----------------------------------------------------------"
		 << endl;
}

void CustomerQueue::senPrintQueue () const
{
	NodePtr temp = new Node;
	temp = head;
	int i = 1;
	Customer c;
	
	cout << "-----------------------------------------------------------"
		 << endl;
		 	   
	cout << "Senior queue information" << endl;
	
	while (temp != NULL)
	{
		if (temp -> ct == Senior)
		{
			c = temp -> cust;
			cout << i << ": ";
			c.printCust();
			cout << endl;
			
			i++;
		}
		
		temp = temp -> next;
	}
	
	cout << "-----------------------------------------------------------"
		 << endl;
}

void CustomerQueue::ladPrintQueue () const
{
	NodePtr temp = new Node;
	temp = head;
	int i = 1;
	Customer c;
	
	cout << "-----------------------------------------------------------"
		 << endl;
		 
	cout << "Lady queue information" << endl;
	
	while (temp != NULL)
	{
		if (temp -> ct == Lady)
		{
			c = temp -> cust;
			cout << i << ": ";
			c.printCust();
			cout << endl;
			
			i++;
		}
		
		temp = temp -> next;
	}
	
	cout << "-----------------------------------------------------------"
		 << endl;
}

void CustomerQueue::othPrintQueue () const
{
	NodePtr temp = new Node;
	temp = head;
	int i = 1;
	Customer c;

	cout << "-----------------------------------------------------------"
		 << endl;
		 
	cout << "Other queue information" << endl;
	
	while (temp != NULL)
	{
		if (temp -> ct == Other)
		{
			c = temp -> cust;
			cout << i << ": ";
			c.printCust();
			cout << endl;
			
			i++;
		}
		
		temp = temp -> next;
	}
	
	
	cout << "-----------------------------------------------------------"
		 << endl;
}

Customer CustomerQueue::dequeue(CustomerType custType)
{
	NodePtr prev, curr;
	QueueException e;
	Customer c;
	
	bool found = findNode (prev, curr, custType);
	
	if (found)
	{
		if (prev == NULL)
		{
			c = head -> cust;
			
			removeFromHead();

			return c;
		}
		else if (curr == NULL)
		{
			c = curr -> cust;
			removeFromTail();
		
			return c;
		}
		else
		{
			c = curr -> cust;
			prev -> next = curr -> next;
			
			delete curr;
			
			return c;
		}
	}
}

int CustomerQueue::removeFromHead()
{
	Customer c;
	CustomerType cType;
	
	try
	{
		if(head == NULL)
			throw exception();
		
		NodePtr temp = head;
		head = head -> next;
		
		if (head == NULL)
			tail = NULL;
		
		c = temp -> cust;
		cType = temp -> ct;
		delete temp;
	}	 
	catch (QueueException e)
	{
		cout << "Exception caught: "
			 << e.what()
			 << endl;
	}
	
	return 0;
}


int CustomerQueue::removeFromTail()
{
	CustomerQueue c;
	
	try
	{
		if(tail == NULL)
			throw exception();
		
		NodePtr temp = tail;
		
		if (head == tail)
		{
			tail = NULL;
			head = NULL;
		}
		else
		{
			NodePtr curr = head;
			
			while (curr -> next != tail)
				curr = curr -> next;
				
			tail = curr;
		}
		
		delete temp;
	}
	
	catch (QueueException e)
	{
		cout << "Exception caught: "
			 << e.what()
			 << endl;
	}
	
	return 0;
}

bool CustomerQueue::findNode (NodePtr& prev, NodePtr& curr, int custType) const
{
	bool found = false;
	prev = NULL;
	curr = head;
	
	while (!found && curr != NULL)
	{
		if (curr -> ct == custType)
			found = true;
			
		else
		{
			prev = curr;
			curr = curr -> next;
		}
	}
	
	return found;
}

void CustomerQueue::enqueue (Customer c, CustomerType custType)
{	 
	NodePtr temp = new Node;
	temp -> cust = c;
	temp -> ct = custType;
	
	NodePtr prev = NULL;
	NodePtr curr = head;
	
	while (curr != NULL && temp -> ct >= curr -> ct)
	{
		prev = curr;
		curr = curr -> next;
	}
	
	if (prev == NULL && head == NULL)
	{
		head = temp;
		tail = temp;
	}
		
	else if (prev == NULL)
	{
		temp -> next = head;
		head = temp;
	}
	
	else if (curr == NULL)
	{
		tail -> next = temp;
		tail = temp;
	}
	
	else
	{
		prev -> next = temp;
		temp -> next = curr;
	}	 
}

QueueException::QueueException ()
{
	message = "Whole queue empty";
}

QueueException::QueueException (char *message)
{
	this -> message = message;
}

const char* QueueException::what () const
{
	return message;
}


