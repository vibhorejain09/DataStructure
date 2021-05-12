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
void itrinorder(Node *root)
{
	stack<Node *> s;
	Node *curr=root;
	while(curr!=NULL || s.empty()==false)
	{
		while(curr!=NULL)
		{
			s.push(curr);
			curr=curr->left;
		}
		curr=s.top();
		s.pop();
		cout<<curr->key<<" ";
		curr=curr->right;
	}
}
Node *getsucc(Node *curr)
{
	curr=curr->right;
	while(curr!=NULL && curr->left!=NULL)
	{
		curr=curr->left;
	}
	return curr;
}
Node *deleteinBST(Node *root, int x)
{
	if(root==NULL)
	{
		return root;
	}
	else if(root->key > x)
	{
		root->left = deleteinBST(root->left, x);
	}
	else if(root->key < x)
	{
		root->right = deleteinBST(root->right, x);
	}
	else
	{
		if(root->left==NULL)
		{
			Node *temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right==NULL)
		{
			Node *temp = root->left;
			delete root;
			return temp;
		}
		else
		{
			Node *greatersucc = getsucc(root);
			root->key = greatersucc->key;
			root->right = deleteinBST(root->right, greatersucc->key);
		}
		return root;
	}
}
int main()
{
	Node *root = new Node(15);
	root->left = new Node(5);
	root->left->left = new Node(3);
	root->right = new Node(20);
	root->right->left = new Node(18);
	root->right->right = new Node(80);
	root->right->left->left = new Node(16);
	itrinorder(root);
	deleteinBST(root, 15);
	cout<<"\n";
	itrinorder(root);
}