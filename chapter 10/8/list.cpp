#include "list.h"

List::List()
{
	size = 0;
	top = 0;
}

void List::add(Item item)
{
	if (!isFull())
		contents[top++] = item;
}

bool List::isEmpty() const
{
	return top == 0;
}

bool List::isFull() const
{
	return top == MAX;
}

void List::doThis(void(*pf) (Item &))
{
	for (int i = 0; i < top; i++) {
		pf(contents[i]);
	}
}