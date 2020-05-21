#include "AccessList.h"
#include "Person.h"
#include <iostream>
using namespace std;

AccessList::AccessList()
{
	MakeEmptyList();
}


AccessList::~AccessList()
{
}

ListNode* AccessList::getHead()
{
	return m_head;
}

ListNode* AccessList::getTail()
{
	return m_tail;
}

//Creates a new emtpy list
void AccessList::MakeEmptyList()
{
	m_head = new ListNode();
	m_tail = new ListNode();
	m_head->setPrev(nullptr);
	m_head->setNext(m_tail);
	m_tail->setPrev(m_head);
	m_tail->setNext(nullptr);
}

void AccessList::addNode(Person data)
{

}

void AccessList::addSortedNode(Person data)
{

}

ListNode* AccessList::createNode(Person data)
{
	ListNode* newNode = new ListNode();
	return newNode;
}

void AccessList::printAccessList()
{
	while (m_head->getNext() != m_tail)
	{
		cout << m_head->getNext()->getData().getId();
	}

}
