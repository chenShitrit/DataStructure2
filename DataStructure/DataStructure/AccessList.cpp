#include "AccessList.h"
#include "Person.h"
#include "ListNode.h"
#include <iostream>
using namespace std;

AccessList::AccessList()
{
	MakeEmptyList();
}


AccessList::~AccessList()
{
	ListNode *p, *tmp;
	p = m_head;
	while (p != m_tail)
	{
		tmp = p;
		p = p->getNext();
		delete tmp;
	}
	delete m_tail;
}

ListNode* AccessList::getHead()
{
	return m_head;
}

ListNode* AccessList::getTail()
{
	return m_tail;
}

//Creates a new emtpy list with dummy head and dummy tail
void AccessList::MakeEmptyList()
{
	Person p;
	m_head = new ListNode(p);
	m_tail = new ListNode(p);
	m_head->setNext(m_tail);
	m_tail->setNext(nullptr);
}

void AccessList::addSortedNode(Person& data, int* counter) //to add if the node exists
{
	ListNode* curr = m_head;
	ListNode* newNode = createNode(data);
	while (curr->getNext() != m_tail && curr->getNext()->getData().getId() < data.getId())
	{
		curr = curr->getNext();
		(*counter)++;
	}
	(*counter)++;
	if (curr->getNext()->getData().getId() == data.getId())
	{
		cout << "The node is already exist!\n";
		exit(1);
		return;
	}
	newNode->setNext(curr->getNext());
	curr->setNext(newNode);
}

ListNode* AccessList::createNode(Person& data)
{
	ListNode* newNode = new ListNode(data);
	return newNode;
}

void AccessList::printAccessList()
{
	ListNode* curr = m_head->getNext();
	while (curr != m_tail)
	{
		cout << curr->getData();
		cout << endl;
		curr = curr->getNext();
	}
}
