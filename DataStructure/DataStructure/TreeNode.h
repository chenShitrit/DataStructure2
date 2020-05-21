#ifndef __TREE_NODE
#define __TREE_NODE
#include "Person.h"
class TreeNode
{
public:
	TreeNode(Person data);
	~TreeNode();
	Person getData();
	TreeNode* getLeft();
	TreeNode* getRight();
	void setData(Person data);
	void setLeft(TreeNode* left);
	void setRight(TreeNode* right);
private:
	Person m_data;
	TreeNode* m_left;
	TreeNode* m_right;

};

#endif // __TREE_NODE

