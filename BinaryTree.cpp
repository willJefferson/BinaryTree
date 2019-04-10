#include<iostream>
#include "BinaryTree.h"

template<class T>
bool BinaryTree<T>::isEmpty() const
{
	if (root == NULL)
		return true;
	return false;
}
template<class T>
BinaryTreeNode<T>* BinaryTree<T>::Parent(BinaryTreeNode<T> *root, BinaryTreeNode<T> *current)
{
	BinaryTreeNode<T> *temp = NULL;
	if (root == NULL)
		return NULL;
	if (current == root->leftchild()|| current == root->rightchild())
		return root;
	if((temp=Parent(root->leftchild(),current))!=NULL)
		return temp;
	if ((temp = Parent(root->rightchild(), current)) != NULL)
		return temp;
	return temp;
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::Parent_no(BinaryTreeNode<T>* root, BinaryTreeNode<T>* current)
{
	if (root == NULL)
		return NULL;
	BinaryTreeNode<T>* stack[STACK_MAX_SIZE];
	BinaryTreeNode<T>* q = root;
	int top = 1;
	stack[0] == NULL;
	while (q)
	{
		if (current == q->leftchild() || current == q->rightchild())
		{
			return q;
		}
		if (q->rightchild())
			stack[top++] = q->rightchild();
		if (q->leftchild())
			q = q->leftchild();
		else
		{
			q = stack[--top];
		}
	}
	return NULL;
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::LeftSibling(BinaryTreeNode<T>*root, BinaryTreeNode<T> *current)
{
	BinaryTreeNode<T> *parent = Parent(root,current);
	if(parent==NULL)
		return NULL;
	if (parent->leftchild() != NULL&&parent->rightchild() == current)
		return parent->leftchild();
	return NULL;
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::RightSibling(BinaryTreeNode<T>*root, BinaryTreeNode<T> *current)
{
	BinaryTreeNode<T> *parent = Parent(root,current);
	if (parent == NULL)
		return NULL;
	if (parent->rightchild() != NULL&&parent->leftchild() == current)
		return parent->rightchild();
	return NULL;
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::CreateTree()
{
	T c;
	BinaryTreeNode<T> *cur=NULL;
	std::cin >> c;
	if (c == '#')
		return NULL;
	else
	{
		cur = new BinaryTreeNode<T>(c);
		cur->setLeftchild(CreateTree());
		cur->setRightchild(CreateTree());
		return cur;
	}
}

template<class T>
void BinaryTree<T>::PreOrder(BinaryTreeNode<T>* root)
{
	if (root == NULL)
		return;
	std::cout << root->value() << ' ';
	PreOrder(root->leftchild());
	PreOrder(root->rightchild());
}

template<class T>
void BinaryTree<T>::InOrder(BinaryTreeNode<T>* root)
{
	if (root == NULL)
		return;
	PreOrder(root->leftchild());
	std::cout << root->value() << ' ';
	PreOrder(root->rightchild());
}

template<class T>
void BinaryTree<T>::PostOrder(BinaryTreeNode<T>* root)
{
	if (root == NULL)
		return;
	PreOrder(root->leftchild());
	PreOrder(root->rightchild());
	std::cout << root->value() << ' ';
}

template<class T>
void BinaryTree<T>::LevelOrder(BinaryTreeNode<T>* root)
{
	BinaryTreeNode<T>*q[QUEUE_MAX_SIZE],*p;
	int front = 0, rear = 0;
	if (root != NULL)
	{
		rear = (rear + 1) % QUEUE_MAX_SIZE;
		q[rear] = root;
	}
	while (front != rear)
	{
		front = (front + 1) % QUEUE_MAX_SIZE;
		p = q[front];
		std::cout << p->value() << ' ';
		if (p->leftchild() != NULL)
		{
			rear = (rear + 1) % QUEUE_MAX_SIZE;
			q[rear] = p->leftchild();
		}
		if (p->rightchild() != NULL)
		{
			rear = (rear + 1) % QUEUE_MAX_SIZE;
			q[rear] = p->rightchild();
		}
	}
	return;
}

template<class T>
void BinaryTree<T>::DeleteBinaryTree(BinaryTreeNode<T>* root)
{
	if (root == NULL)
		return;
	DeleteBinaryTree(root->leftchild());
	DeleteBinaryTree(root->rightchild());
	delete root;
}

template<class T>
int BinaryTree<T>::LeafSize(BinaryTreeNode<T>* root)
{
	if(root==NULL)
		return 0;
	if (root->leftchild() == NULL || root->rightchild() == NULL)
		return 1;
	return LeafSize(root->leftchild()) + LeafSize(root->rightchild());
}

template<class T>
bool BinaryTree<T>::FindKey(BinaryTreeNode<T>* root, const T & key)
{
	if(root==NULL)
		return false;
	if (root->value() == key)
		return true;
	if (FindKey(root->leftchild(), key))
		return true;
	if (FindKey(root->rightchild(), key))
		return true;
	return false;
}

template<class T>
bool BinaryTree<T>::IsBalanced(BinaryTreeNode<T>* root, int & depth)
{
	if(root==NULL)
		return true;
	int left = 0, right = 0;
	if (IsBalanced(root->leftchild(), left) && IsBalanced(root->rightchild(), right))
	{
		if(abs(left-right)>1)
			return false;
		depth = (left>right?left:right)+1;
		return true;
	}
	return false;
}

template<class T>
int BinaryTree<T>::getHeight(const BinaryTreeNode<T>* root) const
{
	if(root==NULL)
		return 0;
	int lh, rh, height;
	lh = getHeight(root->leftchild());
	rh = getHeight(root->rightchild());
	height = (lh > rh ? lh : rh) + 1;
	return height;
}

template<class T>
int BinaryTree<T>::NodeCount(const BinaryTreeNode<T>* root) const
{
	int count;
	if(root==NULL)
		return 0;
	count = NodeCount(root->leftchild()) + NodeCount(root->rightchild()) + 1;
	return count;
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::FindNode(BinaryTreeNode<T>* root, const T & key)
{
	BinaryTreeNode<T>* temp = NULL;
	if (root == NULL)
		return NULL;
	if (root->value() == key)
		return root;
	if((temp = FindNode(root->leftchild(), key))!=NULL)
		return temp;
	if ((temp = FindNode(root->rightchild(), key))!= NULL)
		return temp;
	return temp;
}

template<class T>
void BinaryTree<T>::PreOrder_no(BinaryTreeNode<T>* root)
{
	if (root == NULL)
		return;
	BinaryTreeNode<T>* stack[STACK_MAX_SIZE];
	BinaryTreeNode<T>* q = root;
	int top = 0;
	while (q||top)
	{
		if (q)
		{
			std::cout << q->value() << ' ';
			if (top + 1 > STACK_MAX_SIZE)
			{
				std::cout << "overflow!" << std::endl;
				return;
			}
			stack[top++] = q->rightchild();
			q = q->leftchild();
		}
		else
		{
			q = stack[--top];
		}
	}
}

template<class T>
void BinaryTree<T>::InOrder_no(BinaryTreeNode<T>* root)
{
	if (root == NULL)
		return;
	BinaryTreeNode<T>* stack[STACK_MAX_SIZE];
	BinaryTreeNode<T>* q = root;
	int top = 0;
	while (q||top)
	{
		if (q)
		{
			if (top + 1 > STACK_MAX_SIZE)
			{
				std::cout << "overflow!" << std::endl;
				return;
			}
			stack[top++] = q;
			q = q->leftchild();
		}
		else
		{
			q = stack[--top];
			std::cout << q->value() << ' ';
				q = q->rightchild();
		}
	}
}

template<class T>
void BinaryTree<T>::PostOrder_no(BinaryTreeNode<T>* root)
{
	if (root == NULL)
		return;
	BinaryTreeNode<T>* stack[STACK_MAX_SIZE];
	bool status[STACK_MAX_SIZE];
	BinaryTreeNode<T>* q = root;
	int top1 = 0, top2 = 0;
	while (q || top1)
	{
		while (q)
		{
			if (top1 + 1 > STACK_MAX_SIZE)
			{
				std::cout << "overflow!" << std::endl;
				return;
			}
			stack[top1++] = q;
			status[top2++] = 0;
			q = q->leftchild();
		}
		
			q = stack[--top1];
			bool flag = status[--top2];
			if (flag == 0)
			{
				stack[top1++] = q;
				status[top2++] = 1;
				q = q->rightchild();
			}
			else
			{
				std::cout << q->value() << ' ';
				q = NULL;
			}
		}
}
