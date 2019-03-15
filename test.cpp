#include "BinaryTreeNode.cpp"
#include "BinaryTree.cpp"
#include<iostream>
using namespace std;
int main()
{
	/*
	BinaryTreeNode<char> *root = new BinaryTreeNode<char>(s[0]);
	BinaryTreeNode<char> *left = new BinaryTreeNode<char>(s[1]);
	BinaryTreeNode<char> *right = new BinaryTreeNode<char>(s[2]);
	BinaryTreeNode<char> *left2 = new BinaryTreeNode<char>(s[3]);
	root->setLeftchild(left);
	root->setRightchild(right);
	left->setRightchild(left2);
	*/
	BinaryTreeNode<char> *root = NULL;
	BinaryTree<char> T(root);
	root = T.CreateTree();
	T.setRoot(root);
	
	//T.PreOrder_no(root);
	cout << endl;
	//T.InOrder_no(root);
	cout << endl;
	BinaryTreeNode<char> *key = T.FindNode(root, 'D');
	if (key)
	{
		BinaryTreeNode<char> *parent = T.Parent_no(root, key); 
		if (parent)
		{
			cout << "父节点为: " << parent->value() << endl;
		}	
		else
			cout << "no parent!" << endl;
		BinaryTreeNode<char> *l = T.LeftSibling(root, key);
		BinaryTreeNode<char> *r = T.RightSibling(root, key);
		if (l)
			cout << "左兄弟为： " << l->value() << endl;
		if(r)
			cout << "右兄弟为： " << r->value() << endl;
	}
	else
		cout << "not found!" << endl;
	system("pause");
}