#include<bits/stdc++.h>
using namespace std;
#define max 1000
struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
    }
} ;
class StackList
{
	public:
	Node *head = NULL;
	void push(int data) 
	{
		Node *temp = new Node(data);
        temp->next=head;
        head=temp;
        cout<<data<<" pusshed succesfully\n";
	}
	int pop()
	{
    	if(head==NULL)
        {
            cout<<"Stack empty\n";
            return 0;
        }
        int res=head->data;
        Node *temp=head;
        head=head->next;
        delete temp;
        return res;
	}
	int peek()
	{
    	if (head==NULL)
        {
            cout<<"Stack is Empty";
            return 0;
        }
        return head->data; 
	}
	bool empty() {
		if (head==NULL)
			return true;
		else
			return false;
	}
};
int main()
{
    class StackList s;
    s.peek();
    s.push(100);
    s.push(200);
    s.peek();
    s.push(300);
    cout<< s.peek() << " is top element\n";
    cout<<"Elements present in stack : ";
    while(!s.empty())
    {
        cout<<s.peek()<<" ";
        s.pop();
    }
 
    return 0;
}