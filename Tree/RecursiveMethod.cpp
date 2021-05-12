#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int key;
	Node *left;
	Node *right;
	Node(int k)
	{
		key=k;
		left=NULL;
		right=NULL;
	}
};
void recinoredr(Node *root)
{
	if(root!=NULL)
	{
		recinoredr(root->left);
		cout<<root->key<<" ";
		recinoredr(root->right);
	}
	
}
void recpreoredr(Node *root)
{
	if(root!=NULL)
	{
		cout<<root->key<<" ";
		recpreoredr(root->left);
		recpreoredr(root->right);
	}
	
}
void recpostoredr(Node *root)
{
	if(root!=NULL)
	{
		recpostoredr(root->left);
		recpostoredr(root->right);
		cout<<root->key<<" ";
	}
	
}
int sizeofBT(Node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		return (1+sizeofBT(root->left)+sizeofBT(root->right));
	}

}
int heightTree(Node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		return max(1+heightTree(root->left),1+heightTree(root->right));
	}

}
int maxTree(Node *root)
{
	if(root==NULL)
	{
		return INT_MIN;
	}
	else
	{
		return max(root->key,max(maxTree(root->left),maxTree(root->right)));
	}

}
int main()
{
	Node *root = new Node(10); // for empty tree Node *root = NULL;          10
	root->left = new Node(20);										//20          30
	root->right = new Node(30);									//40    50	   60    70
	root->left->left = new Node(40);
	root->left->right = new Node(50);
	root->right->left = new Node(60);
	root->right->right = new Node(70);	
	recinoredr(root);
	cout<<"\n";
	recpreoredr(root);
	cout<<"\n";
	recpostoredr(root);
	cout<<"\n";
	cout<<"Size of Binary Tree is "<<sizeofBT(root)<<"\n";
	cout<<"Max of tree  "<<maxTree(root)<<"\n";
	cout<<"Height of tree  "<<heightTree(root)<<"\n";
}
