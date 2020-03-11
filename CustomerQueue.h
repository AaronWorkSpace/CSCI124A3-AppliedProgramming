//Done by: Aaron Lim
//I did not pass my assignment to anyone in the class
//or copy anyone's work and I am willing to accept
//whatever penalty given to me and also to all the
//related parties involved

#include "Customer.h"

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

