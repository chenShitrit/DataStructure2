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
	Person p;
	m_head = new ListNode(p);
	m_tail = new ListNode(p);
	m_head->setNext(m_tail);
	m_tail->setNext(nullptr);
}

void AccessList::addNode(Person data)
{

}

void AccessList::addSortedNode(Person data)
{
	ListNode* curr = m_head;
	ListNode* newNode = createNode(data);
	while (curr->getNext() != m_tail && curr->getNext()->getData().getId() < data.getId())
		curr = curr->getNext();
	newNode->setNext(curr->getNext());
	curr->setNext(newNode);

}

ListNode* AccessList::createNode(Person data)
{
	ListNode* newNode = new ListNode(data);
	return newNode;
}

void AccessList::printAccessList()
{
	ListNode* curr = m_head->getNext();
	while (curr != m_tail)
	{
		cout << m_head->getNext()->getData().getId();
		cout << endl;
		curr = curr->getNext();
	}

}
