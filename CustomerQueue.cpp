//Done by: Aaron Lim
//I did not pass my assignment to anyone in the class
//or copy anyone's work and I am willing to accept
//whatever penalty given to me and also to all the
//related parties involved

#include "QueueException.h"
#include "CustomerQueue.h"

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

