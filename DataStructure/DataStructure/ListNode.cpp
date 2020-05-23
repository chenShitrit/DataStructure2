#include "ListNode.h"


//to check
ListNode::ListNode(Person& data): m_data(data)
{
	//m_data.setId(data.getId());
	//m_data.setFirstName(data.getFirstName());
	//m_data.setLastName(data.getLastName());
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