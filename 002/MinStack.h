#include "Stack.h"
template <typename T>
class MinStack
{
public:
	MinStack();
	~MinStack();
	bool push(T *element);
	bool pop();
	T *min();
	T *top;
private: 
	Stack *minStack;//save min values in a stsck
	Stack *elements;//current minStack's array
	int size;
	int minSize;
};

template <typename T>
T * MinStack<T>::min()
{
	return minStack[minSize - 1];
}

template <typename T>
bool MinStack<T>::pop()
{
	 elements.pop();
	 if (top==min())
	 {
		 minStack.pop();
		 minSize--;
	 }
	 size--;

}

template <typename T>
bool MinStack<T>::push(T *element)
{
	elements->push(element);
	size++;
	top = element;
	if (element<min())
	{
		minStack->push(element);
		minSize++;
	}
}

template <typename T>
MinStack<T>::~MinStack()
{
	if (minStack)
	{
		delete minStack;
	}
	if (top)
	{
		delete top;
	}
	if (elements)
	{
		delete elements;
	}
}

template <typename T>
MinStack<T>::MinStack()
{
	size = 0;
	minSize = 0;
	minStack = NULL;
	elements = NULL;
	top = NULL;
}


