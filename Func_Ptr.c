#include <stdio.h>

int add (int a, int b)
{
	return a+b;
}
int function (int (*somefun)(int a, int b))
{
	int c= somefun(2,3);
	return c;
}
int main()
{
	int c =function(add);
	printf("\n ...............C Code for passing function Pointer as an Argument to a function..............");
	printf ("\n Adding Using Function Pointer \n ");
	printf ("%d",c);
}
