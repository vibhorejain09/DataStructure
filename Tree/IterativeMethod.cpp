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
void spacepreorder(Node *root)
{
	stack<Node *> s;
	Node *curr=root;
	while(curr!=NULL || s.empty()==false)
	{
		while(curr!=NULL)
		{
			cout<<curr->key<<" ";
			if(curr->right!=NULL)
			{
				s.push(curr->right);
			}
			curr=curr->left;
		}
		if(s.empty()==false)
		{
			curr=s.top();
			s.pop();
		}
	}
}
void itrpreorder(Node *root)
{
	if(root==NULL)
	{
		return;
	}
	stack<Node *> s;
	s.push(root);
	while(s.empty()==false)
	{
		Node *curr=s.top();
		cout<<curr->key<<" ";
		s.pop();
		if(curr->right!=NULL)
		{
			s.push(curr->right);
		}
		if(curr->left!=NULL)
		{
			s.push(curr->left);
		}

	}
}
void itrpostorder(Node* root)
{
    if (root == NULL)
        return;
    // Create two stacks
    stack<Node *> s1, s2;
  	// push root to first stack
    s1.push(root);
    Node* curr;
  	// Run while first stack is not empty
    while (!s1.empty()) {
        // Pop an item from s1 and push it to s2
        curr = s1.top();
        s1.pop();
        s2.push(curr);
  
        // Push left and right children
        // of removed item to s1
        if (curr->left)
            s1.push(curr->left);
        if (curr->right)
            s1.push(curr->right);
    }
  	// Print all elements of second stack
    while (!s2.empty()) {
        curr = s2.top();
        s2.pop();
        cout << curr->key << " ";
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
	itrinorder(root);
	cout<<"\n";
	itrpostorder(root);
	cout<<"\n";
	itrpreorder(root);
	cout<<"\n";
	spacepreorder(root);
}
