#include "ListNode.h"



ListNode::ListNode() //need to initialize person
{
	m_prev = nullptr;
	m_next = nullptr;
}


ListNode::~ListNode()
{
}

void ListNode::setNext(ListNode* next)
{
	m_next = next;
}
ListNode* ListNode::getNext()
{
	return m_next;
}

ListNode* ListNode::getPrev()
{
	return m_prev;
}

void ListNode::setPrev(ListNode* prev)
{
	m_prev = prev;
}

Person ListNode::getData()
{
	return m_data;
}

void ListNode::setPerson(Person person)
{

}