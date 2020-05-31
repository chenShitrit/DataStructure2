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
	
	if (m_root == nullptr) //Empty tree
	{
		counter++;
		m_root = new TreeNode(data);
		return counter;
	}
	TreeNode *root, *parent = nullptr;
	root = m_root;
	while (root != nullptr)
	{
		counter++;
		if (data.getId() > root->getData().getId())
		{
			parent = root;
			root = root->getRight();
		}
		else if (data.getId() < root->getData().getId())
		{
			parent = root;
			root = root->getLeft();
		}
		else
		{
			cout << "Error, key already exists";
			exit(1);
		}
	}
	root = new TreeNode(data);
	if (parent->getData().getId() > data.getId())
		parent->setLeft(root);
	else
		parent->setRight(root);
	counter++;
	return counter;
}

void BST::deleteNode(TreeNode* root, int id)
{
	TreeNode *toDelete, *parent, *max;
	bool leftChild = true;
	toDelete = findNode(id);
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
		max->setLeft(toDelete->getLeft());
		max->setRight(toDelete->getRight());
		toDelete->setLeft(nullptr);
		toDelete->setRight(nullptr);
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
	TreeNode* parent = nullptr;
	while (t->getRight() != nullptr)
	{
		parent = t;
		t = t->getRight();
	}
	parent->setRight(t->getLeft());
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

