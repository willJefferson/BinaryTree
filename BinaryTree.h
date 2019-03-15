#pragma once
#include "BinaryTreeNode.h"
#define STACK_MAX_SIZE 50
#define QUEUE_MAX_SIZE 50
template <class T>
class BinaryTree
{
private:
	BinaryTreeNode<T> *root;
public:
	BinaryTree() 
	{
		root = nullptr;
	};
	BinaryTree(BinaryTreeNode<T> *r)
	{
		root = r;
	};
	~BinaryTree()
	{
		DeleteBinaryTree(root);
	};
	bool isEmpty() const;
	BinaryTreeNode<T> *Root()
	{
		return root;
	};
	void setRoot(BinaryTreeNode<T> *current)
	{
		root=current;
	};
	BinaryTreeNode<T> *Parent(BinaryTreeNode<T> *root, BinaryTreeNode<T> *current);
	BinaryTreeNode<T> *Parent_no(BinaryTreeNode<T> *root, BinaryTreeNode<T> *current);
	BinaryTreeNode<T> *LeftSibling(BinaryTreeNode<T>*root, BinaryTreeNode<T> *current);
	BinaryTreeNode<T> *RightSibling(BinaryTreeNode<T>*root, BinaryTreeNode<T> *current);
	BinaryTreeNode<T>* CreateTree();
	void PreOrder(BinaryTreeNode<T>*root);
	void InOrder(BinaryTreeNode<T>*root);
	void PostOrder(BinaryTreeNode<T>*root);
	void LevelOrder(BinaryTreeNode<T>*root);
	void DeleteBinaryTree(BinaryTreeNode<T>*root);
	int LeafSize(BinaryTreeNode<T>*root);   //Ҷ�ڵ����
	bool FindKey(BinaryTreeNode<T>*root,const T& key);  //Ѱ��ֵΪk�Ľڵ�
	bool IsBalanced(BinaryTreeNode<T>*root, int &depth);    //�ж��Ƿ�Ϊ����ƽ����
	int getHeight(const BinaryTreeNode<T>*root) const;    //��߶�
	int NodeCount(const BinaryTreeNode<T>*root) const;    //��ڵ���
	BinaryTreeNode<T> *FindNode(BinaryTreeNode<T>*root, const T& key);//Ѱ��ֵΪk�Ľڵ㲢����

	void PreOrder_no(BinaryTreeNode<T>*root);
	void InOrder_no(BinaryTreeNode<T>*root);
	void PostOrder_no(BinaryTreeNode<T>*root);
};



