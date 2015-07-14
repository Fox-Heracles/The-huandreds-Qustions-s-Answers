#include<stdlib.h>
template <typename T>
class BTNode
{
public:
	BTNode();
	BTNode(T value);
	virtual ~BTNode(){
		this->value = 0;
		left = 0;
		right = 0;
	};
	BTNode *left;
	BTNode *right;
	T value;
	//inorder traversal
	void InOrderPrintTree(BTNode<T>* pRoot);
	void printBinaryTree(BTNode<T> *root);
	//output doublelist
	void PrintList(BTNode<T>* pRoot);
	BTNode<T>* Convert(BTNode<T> *root);
	//void BTNode<T>::push(BTNode<T> *root, BTNode<T> *t);
	//void BTNode<T>::InsertPosition(BTNode<T> *root, BTNode<T> t);
	BTNode<T>* Transfer(BTNode<T> *root);
	BTNode<T>* BTNode<T>::BSTreeToDoubleList(BTNode<T> *root);
};

template <typename T>
BTNode<T>* BTNode<T>::BSTreeToDoubleList(BTNode<T> *root)
{
	//root will be trnsfered to the center node of the list(which is the root of original binary tree)
	if (root)
	{
		root = Transfer(root);
		while (root->left)
		{
			root = root->left;
		}
		return root;
	}
	return 0;
}

template <typename T>
BTNode<T>* BTNode<T>::Transfer(BTNode<T> *root)
{
	if (NULL == root) return root;
	if (root->left != NULL)
	{
		//return the root left subtree
		BTNode<T> *left = Transfer(root->left);
		//get the tail of the trnsfered doublelist(from left subtree),pointer move right ,at last the "left" is tail.
		while (left->right != NULL)
		{
			left = left->right;
		}
		//add root to the next position of left-subtree-transfered doublelist's tail
		left->right = root;
		root->left = left;

	}
	if (root->right != NULL)
	{
		//return the root right subtree
		BTNode<T> *right = Transfer(root->right);
		//get the tail of the trnsfered doublelist(from right subtree),pointer move left ,at last the "right" is head.
		
		while (right->left != NULL)
		{
			right = right->left;
		}
		//add root to the next position of left-subtree-transfered doublelist's tail
		right->left = root;
		root->right = right;
	}
	return root;
}

//template <typename T>
//void BTNode<T>::push(BTNode<T> *root, BTNode<T> *t)
//{
//	if (!root)
//	{
//		this->value = t->value;
//		this->left = t->left;
//		this->right = t->right;
//	}
//	if (root->value > t->value)
//	{
//		if (left)
//		{
//			push(left, t);
//		}
//		else
//		{
//			left = t;
//		}
//	}
//	else
//	{
//		if (right)
//		{
//			push(right, t);
//		}
//		else
//		{
//			right = t;
//		}
//	}
//}

//the same as Transfer
template <typename T>
BTNode<T>* BTNode<T>::Convert(BTNode<T> *root)
{
	// Base case
	if (root == NULL)
		return root;

	// Convert the left subtree and link to root
	if (root->left != NULL)
	{
		// Convert the left subtree
		BTNode* left = Convert(root->left);

		// Find inorder predecessor. After this loop, left
		// will point to the inorder predecessor
		for (; left->right != NULL; left = left->right);

		// Make root as next of the predecessor
		left->right = root;

		// Make predecssor as previous of root
		root->left = left;
	}

	// Convert the right subtree and link to root
	if (root->right != NULL)
	{
		// Convert the right subtree
		BTNode* right = Convert(root->right);

		// Find inorder successor. After this loop, right
		// will point to the inorder successor
		for (; right->left != NULL; right = right->left);

		// Make root as previous of successor
		right->left = root;

		// Make successor as next of root
		root->right = right;
	}

	return root;
}

template <typename T>
void BTNode<T>::PrintList(BTNode<T>* pRoot)
{
	while (pRoot != NULL && pRoot->left != NULL)
		pRoot = pRoot->left;
	cout << "\nDouble List:\n";
	while (pRoot)
	{
		cout << pRoot->value << " ";
		pRoot = pRoot->right;
	}
}

template <typename T>
void BTNode<T>::printBinaryTree(BTNode<T> *root)
{
	if (root)
	{
		std::cout << static_cast<int>(root->value) << " ";
		if (root->left)
			BTNode<T>::printBinaryTree(root->left);
		if (root->right)
			BTNode<T>::printBinaryTree(root->right);
	}
}

template <typename T>
void BTNode<T>::InOrderPrintTree(BTNode<T>* pRoot)
{

}

template <typename T>
BTNode<T>::BTNode(T value)
{
	left = 0;
	right = 0;
	this->value = value;
}

