#include "BST.h"
#include <iostream>
using namespace std;

BST::BST()
{
	m_root = nullptr;
}

TreeNode* BST::getRoot()
{
	return m_root;
}

bool BST::isEmpty(BST& tree)
{
	return (tree.m_root == nullptr);
}

BST BST::makeEmpty()
{
	BST tree;
	tree.m_root = nullptr;
	return tree;
}

int BST::insertNode(Person& data)
{
	int counter = 0;
	if (findNode(data.getId()) != nullptr)
		cout << "Error, key already exists";
	TreeNode* newNode = new TreeNode(data);
	TreeNode* tmp = m_root;
	TreeNode* parent = nullptr;

	while (tmp != nullptr)
	{
		parent = tmp;
		counter++;
		if (data.getId() < tmp->getData().getId())
			tmp = tmp->getLeft();
		else
			tmp = tmp->getRight();
	}
	if (parent == nullptr)
		m_root = newNode;
	else
	{
		counter++;
		if (data.getId() < parent->getData().getId())
			parent->setLeft(newNode);
		else
			parent->setRight(newNode);
	}
	return counter;
}

void BST::deleteNode(TreeNode* root, int id)
{
	TreeNode* toDelete = findNode(id);

}

TreeNode* BST::findNode(int key)
{
	TreeNode* tmp = m_root;
	while (tmp != nullptr)
	{
		if (tmp->getData().getId() == key)
			return tmp;
		else if (key < tmp->getData().getId())
			tmp = tmp->getRight();
		else
			tmp = tmp->getRight();
	}
	return nullptr;
}

BST::~BST()
{
	FreeTreeRec(m_root);
}

void BST::FreeTreeRec(TreeNode *t)
{
	if (t != NULL)
	{
		FreeTreeRec(t->getLeft());
		FreeTreeRec(t->getRight());
		delete t;
	}
}

