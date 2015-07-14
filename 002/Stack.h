template <typename T>
class Stack
{
public:
	Stack();
	virtual ~Stack();
	bool push(T *element);
	bool pop();
	void clear();
	T *top;
private:
	int size;//the size of the stsck array
	int lenght;//the number of elements of stack
	T *elements;//array to storage
};

template <typename T>
void Stack<T>::clear()
{
	if (elements)
	{
		delete[] elements;
		size = 10;
		lenght = 0;
		top = NULL;
	}
}

template <typename T>
Stack<T>::Stack()
{
	size = 10;
	elements = new T[size];
	top = NULL;
}

template <typename T>
bool Stack<T>::pop()
{
	if (lenght > 0)
	{

		if (size > (2 * lenght + 2))
		{
			T *t = new T[lenght - 1];
			for (int i = 0; i < lenght - 1; i++)
			{
				t[i] = elements[i];
			}
			delete[] elements;
			elements = t;
		}
		else
		{
			elements[lenght - 1] = NULL;
		}
		top = elements[lenght - 2];
		lenght--;

	}
	return true;


}

template <typename T>
bool Stack<T>::push(T *element)
{
	if (lenght == size)
	{
		size = size * 2 + 2;
		T *t = new T[size * 2 + 2];
		for (int i = 0; i < size; i++)
		{
			t[i] = elements[i];
		}
		t[size] = *element;
		delete[]elements;
		elements = t;

	}
	else
	{
		elements[lenght] = *element;
	}
	lenght++;
	top = elements[lenght - 1];
}

template <typename T>
Stack<T>::~Stack()
{
	if (elements)
	{
		delete[] elements;
	}
	if (top)
	{
		delete top;
	}
}
