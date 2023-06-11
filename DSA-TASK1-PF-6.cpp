#include<iostream>
#include<cstring>
#include "Stack.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;


 char[] convertToCharArray(string);
char[] convertToCharArray(string a1)
{
	//int size = a1.length();
	char array[20];
	strcpy(array, a1.c_str());
	return array;

}
bool sameStringInOrderAndNumber(string a)
{
	
	char array[20];
	strcpy_s(array, a.c_str());
	Stack<char> s;
	int i = 0;
	while (array[i] == 'a')
	{
		s.push(array[i]);
		i++;
	}
	while (array[i] == 'b')
	{
		s.pop();
		i++;
	}
	//cout << s.stackTop();
	if (s.isEmpty())
	{
		cout << "\nStrings are same in size and order!!!";
		return true;
	}
	else
	{
		cout << "\nStrings are not same in size and order!!!!";
		return false;
	}
	return false;
}
int main()
{

	sameStringInOrderAndNumber("aaaaaabbbbbb");
}