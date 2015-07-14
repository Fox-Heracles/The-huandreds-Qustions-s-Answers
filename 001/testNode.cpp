#include "BTNode.h"
#include<iostream>
#include<stdlib.h>
using namespace std;
//          10
//         /  \
//        6   14
//       /\   /\
//      4  8 12 16
//create tree node
//void main()
int testNode()
{
	BTNode<int> *bt10 = new BTNode<int>(10);
	BTNode<int> *bt6 = new BTNode<int>(6);
	BTNode<int> *bt14 = new BTNode<int>(14);
	bt10->left = bt6;
	bt10->right = bt14;
	BTNode<int> *bt4 = new BTNode<int>(4);
	BTNode<int> *bt8 = new BTNode<int>(8);
	bt6->left = bt4;
	bt6->right = bt8;
	BTNode<int> *bt12 = new BTNode<int>(12);
	BTNode<int> *bt16 = new BTNode<int>(16);
	bt14->left = bt12;
	bt14->right = bt16;
	cout << "inorder traversal:\n";
	bt10->printBinaryTree(bt10);
	BTNode<int> *head = bt10->BSTreeToDoubleList(bt10);
	bt10->PrintList(head);
	system("pause");
	return 0;
}
