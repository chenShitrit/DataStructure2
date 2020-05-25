#include "BST.h"
#include <iostream>
using namespace std;
#define RIGHT 1
#define LEFT 2
#define NONE 3

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
	if (findNode(data.getId(), &counter) != nullptr)
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
	TreeNode *toDelete, *parent, *max;
	int count = 0;
	bool leftChild = true;
	toDelete = findNode(id, &count);
	parent = findParent(id);
	if (parent->getData().getId() < id)
		leftChild = false;

	if (toDelete->getLeft() == nullptr && toDelete->getRight() == nullptr)// if leaf
		replaceChiledNode(parent, leftChild, nullptr);

	else if (toDelete->getLeft() == nullptr)// has one chiled from left
		replaceChiledNode(parent, leftChild, toDelete->getLeft());

	else if (toDelete->getRight() == nullptr)// has one chiled from right
		replaceChiledNode(parent, leftChild, toDelete->getRight());

	else // has 2 chileds
	{
		max = findMax(toDelete->getLeft());
		replaceChiledNode(parent, leftChild, max);
	}
	delete toDelete;
}

void BST::replaceChiledNode(TreeNode* parent, bool isLeft, TreeNode* replaceWith)
{
	if (isLeft)
		parent->setLeft(replaceWith);
	else
		parent->setRight(replaceWith);
}

TreeNode* BST::findMax(TreeNode* t)
{
	while (t->getRight() != nullptr)
	{
		t = t->getRight();
	}
	return t;
}

TreeNode* BST::findParent(int key)
{
	TreeNode* parent = nullptr;
	TreeNode* tmp = m_root;
	if (tmp->getData().getId() == key) // if the key is in the root
		return nullptr;
	while (tmp != nullptr)
	{
		if (tmp->getData().getId() == key)
			return parent;
		parent = tmp;
		if (key < tmp->getData().getId())
			tmp = tmp->getRight();
		else
			tmp = tmp->getRight();
	}
	return nullptr;
}


TreeNode* BST::findNode(int key, int* counter)
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
	(*counter)++;
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

