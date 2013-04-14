/*
--------------------------------------------------
cvtest3.c

This is the simple nachos user program to test 
if wait and broadcast sys calls.

--------------------------------------------------
*/

#include "syscall.h"

int c1;
int c2;
int l1;


int counter=0;

void clt2()
{
	AcquireLock(l1);
	while(counter<3)
	{
		Write("\n Calling wait clt2",19,1);
		WaitCondition(c1,l1);		
	}
	ReleaseLock(l1);
	Write("\n Out of wait clt2...",21,1);
	Exit(0);
}


void clt1()
{
	AcquireLock(l1);
	while(counter<3)
	{
		Write("\n Calling wait clt1",19,1);
		WaitCondition(c1,l1);		
	}
	ReleaseLock(l1);
	Write("\n Out of wait clt1...",21,1);
	Exit(0);
}


int main()
{
	unsigned int i=0;
	Write("\nTESTING WAIT AND BROADCAST",27,1);
	l1=CreateLock();
	c1=CreateCondition();
	c2=CreateCondition();
	Fork(clt1);
	Fork(clt2);
	Yield();
	Yield();
	Yield();
	Yield();
	Yield();
	Yield();
	/*for(i=0;i<100000;i++){}*/
	AcquireLock(l1);
	counter=counter+3;
	BroadcastCondition(c1,l1);
	ReleaseLock(l1);
	Exit(0);
}