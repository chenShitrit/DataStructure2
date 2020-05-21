#include "TreeNode.h"


TreeNode::TreeNode(Person data)
{
	m_data = data;
	m_left = nullptr;
	m_right = nullptr;
}

Person TreeNode::getData()
{
	return m_data;
}

TreeNode* TreeNode::getLeft()
{
	return m_left;
}

TreeNode* TreeNode::getRight()
{
	return m_right;
}


void  TreeNode::setLeft(TreeNode* left)
{
	m_left = left;
}

void  TreeNode::setRight(TreeNode* right)
{
	m_right = right;
}

void TreeNode::setData(Person data)
{
	m_data = data;
}

TreeNode::~TreeNode()
{
}
