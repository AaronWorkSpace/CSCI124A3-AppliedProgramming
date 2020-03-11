//Done by: Aaron Lim
//I did not pass my assignment to anyone in the class
//or copy anyone's work and I am willing to accept
//whatever penalty given to me and also to all the
//related parties involved

#include "QueueException.h"

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

