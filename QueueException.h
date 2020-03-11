//Done by: Aaron Lim
//I did not pass my assignment to anyone in the class
//or copy anyone's work and I am willing to accept
//whatever penalty given to me and also to all the
//related parties involved

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


