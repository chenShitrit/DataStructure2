#include "ListNode.h"



ListNode::ListNode(Person& data): m_data(data)
{
	m_next = nullptr;
}

void ListNode::setNext(ListNode* next)
{
	m_next = next;
}
ListNode* ListNode::getNext()
{
	return m_next;
}

Person ListNode::getData()
{
	return m_data;
}

void ListNode::setPerson(Person& person)
{

}