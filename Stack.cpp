#include<iostream>
using namespace std;
#include"Stack.h"
template<typename T>
void Stack<T>::reSize(int cap)
{
	T* temp = new T[cap];
	int i;
	for (i = 0; i < top && i < cap; i++)
	{
		temp[i] = data[i];
	}
	int top1 = top;
	this->~Stack();
	data = temp;
	top = top1;
	capacity = cap;
	//top = i ;
	//capacity  = cap;
}
template<typename T>
Stack<T>::Stack()
{
	data = nullptr;
	top = capacity = 0;
}
template<typename T>
Stack<T>::Stack(const Stack<T> & ref)
{
	if (ref.data == nullptr)
		return ;
	capacity = ref.capacity;
	top = ref.top;
	data = new T[capacity];
	for (int i = 0; i < capacity && i < top; i++)
	{
		data[i] = ref.data[i];
	}
}
template<typename T>
Stack<T> & Stack<T>::operator = (const Stack<T> & ref)
{
	if (this == &ref)
		return *this;
	this->~Stack();
	if (ref.data== nullptr)
		return *this;
	capacity = ref.capacity;
	top = ref.top;
	data = new T[capacity];
	for (int i = 0; i < capacity && i < top; i++)
	{
		data[i] = ref.data[i];
	}
	return *this;
}
template<typename T>
Stack<T>::~Stack()
{
	if (!data)
		return;
	delete[]data;
	data = nullptr;
	capacity = 0;
	top = 0;

}
template<typename T>
void Stack<T>::push(T val)
{
	if (isFull())
	{
		capacity++;
		reSize(capacity* 2);
	}
		
	data[top++] = val;

}
template<typename T>
T Stack<T>::pop()
{
	if (isEmpty())
	{
		cout << "\nStack is empty!!!!\n";
		exit(0);
	}

	/*try
	{
		
			top = -1;
			throw top;
		catch (int x)
		{
			cout << "\nStack is empty!!!";
			cout << "\nTop is giving negative value: Top is:" << x;
		}
	}*/
	//cout << "\nTOP VALUE :" <<"------"<< top << "-------";
	T val = data[--top];
	
	if (top == capacity / 4)//bug found
	{
		reSize(capacity / 2);
	}
	return val;
}
template<typename T>
T Stack<T>::stackTop() const
{
	return data[top - 1];
}
template<typename T>
bool Stack<T>::isFull() const
{
	return top == capacity;
}
template<typename T>
bool Stack<T>::isEmpty() const
{
	return top == 0;
}
template<typename T>
int Stack<T>::getCapacity() const
{
	return capacity;
}
template<typename T>
int Stack<T>::getNumberOfElements() const
{
	int noOfElements = top;
	return noOfElements;
}