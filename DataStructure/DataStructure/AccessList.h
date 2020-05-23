#ifndef __ACCESS_LIST
#define __ACCESS_LIST
#include "ListNode.h"
class AccessList
{
public:
	AccessList();
	~AccessList();
	void MakeEmptyList();
	void addSortedNode(Person& data, int* counter);
	ListNode* getHead();
	ListNode* getTail();
	ListNode* createNode(Person& data);
	void printAccessList();

private:
	ListNode* m_head;
	ListNode* m_tail;

};

#endif // __ACCESS_LIST