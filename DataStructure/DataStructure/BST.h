#ifndef __BST
#define __BST
#include "TreeNode.h"
class BST
{
public:
	BST();
	~BST();
	bool isEmpty(BST tree);
	BST makeEmpty();
	void insertNode(Person data);
	void deleteNode(TreeNode* root, int id);
	TreeNode* findNode(int key);
	void FreeTreeRec(TreeNode *t);

private:
	TreeNode* m_root;

};

#endif // __BST