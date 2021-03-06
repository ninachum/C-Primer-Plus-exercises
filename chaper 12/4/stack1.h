#pragma once

typedef unsigned long Item;

class Stack
{
private:
	enum {MAX = 10};
	Item * pitems;
	int size;
	int top;

public:
	Stack(int n = MAX);
	Stack(const Stack & st);
	~Stack();
	bool isEmpty() const;
	bool isFull() const;
	bool push(const Item & item);
	bool pop(Item & item);	// pop and insert the item into the argument.
	Stack & operator=(const Stack & st);
};