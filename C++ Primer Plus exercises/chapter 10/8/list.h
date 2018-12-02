#pragma once


typedef unsigned long Item;

class List
{
private:
	static const int MAX = 50;
	int size;
	int top;
	Item contents[MAX];
public:
	List();
	void add(Item item);
	bool isFull() const;
	bool isEmpty() const;
	void doThis(void(*pf) (Item &));

};