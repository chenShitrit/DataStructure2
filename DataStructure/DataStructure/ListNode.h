#ifndef __LIST_NODE
#define __LIST_NODE
#include "Person.h"
class ListNode
{
public:
	ListNode(Person& data);
	void setNext(ListNode* next);
	ListNode* getNext();
	Person getData();
	void setPerson(Person& person);

private:
	Person m_data;
	ListNode* m_next;
	ListNode* m_prev;
};

#endif // __LIST_NODE