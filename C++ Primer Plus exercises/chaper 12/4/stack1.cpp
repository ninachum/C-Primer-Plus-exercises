#include "stack1.h"
#include <iostream>

Stack::Stack(int n)
{
	if (n > MAX)
		size = MAX;
	else if (n < 0) {
		std::cout << "you cannot have negative length for stack.\n"
			<< "the stack size is set to 0.\n";
		size = 0;
	}
	else
		size = n;
	pitems = new Item[n];
	top = 0;
}

Stack::Stack(const Stack & st)
{
	pitems = new Item[st.size];
	for (int i = 0; i < st.size; i++) 
		pitems[i] = st.pitems[i];
	size = st.size;
	top = st.top;
}

Stack::~Stack()
{
	delete[] pitems;
}

bool Stack::isEmpty() const
{
	return top == 0;
}

bool Stack::isFull() const
{
	return top == MAX;
}

bool Stack::push(const Item & item)
{
	if (!isFull())
	{
		pitems[top++] = item;
		return true;
	}
	else
		return false;
}

bool Stack::pop(Item & item)
{
	if (!isEmpty())
	{
		item = pitems[--top];
		return true;
	}
	else
		return false;
}

Stack & Stack::operator=(const Stack & st)
{
	if (this == &st)
		return *this;
	delete[] pitems;
	pitems = new Item[st.size];
	for (int i = 0; i < st.size; i++) 
		pitems[i] = st.pitems[i];
	size = st.size;
	top = st.top;
	return *this;
}