#ifndef __BST
#define __BST
#include "TreeNode.h"
class BST
{
public:
	BST();
	~BST();
	TreeNode* getRoot();
	bool isEmpty(BST& tree);
	BST makeEmpty();
	int insertNode(Person& data);
	void deleteNode(TreeNode* root, int id);
	TreeNode* findNode(int key, int* counter);
	TreeNode* findParent(int key);
	TreeNode* findMax(TreeNode* t);
	void replaceChiledNode(TreeNode* parent, bool isLeft, TreeNode* replaceWith);
	void FreeTreeRec(TreeNode *t);


private:
	TreeNode* m_root;

};

#endif // __BST