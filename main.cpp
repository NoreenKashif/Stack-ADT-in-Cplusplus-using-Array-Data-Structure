#include<iostream>
using namespace std;
#include"Stack.h"
int main()
{
	Stack<int>s;
	s.push(21);
	s.push(22);
	//cout << s.stackTop()<<"\n";
	//cout << s.getNumberOfElements()<<"\n";
	s.push(67);
	s.push(90);
	s.push(298);
	s.push(33);
	s.push(61);
	s.push(32);
	cout << s.getNumberOfElements()<<"\n";
	cout << s.getCapacity() << "\n";
	s.pop();
	//cout << s.getNumberOfElements();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	cout<<s.stackTop()<<"\n";
	cout<<s.getCapacity();
	
}
