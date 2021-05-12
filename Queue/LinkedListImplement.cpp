#include<bits/stdc++.h>
using namespace std;
#define max 1000
struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next=NULL;
    }
} ;
class Queue
{
	public:
	Node *front=NULL,*rear=NULL;
    int size=0;
    /*Queue()
    {
        front=NULL;
        rear=NULL;
    }*/
	void Enqueue(int x)
    {
        Node *temp=new Node(x);
        if(front==NULL)
        {
            front=temp;
            rear=temp;
        }
        rear->next=temp;
        rear=temp;
        size++;
        cout<<x<<" added successfully\n";
    }
    void Dequeue()
    {
        if(front==NULL)
        {
            cout<<"Queue Empty\n";
            return;
        }
        Node *temp= front;
        front=front->next;
        if(front==NULL)
        {
            rear=NULL;
        }
        cout<<temp->data<<" removed successfully\n";
        delete temp;    
    }
    int getFront() 
    {
        return front->data;
    }
    int getRear() 
    {
        return rear->data;
    }
};
int main()
{
    class Queue q;
    q.Dequeue();
    q.Enqueue(10);
    q.Enqueue(20);
    q.Dequeue();
    q.Enqueue(40);
    q.Enqueue(50);
    q.Enqueue(60);
    q.Enqueue(70);
    cout<<q.getFront()<<" "<<q.getRear()<<" "<<q.size<<"\n";
    for(Node *curr=q.front;curr!=NULL;curr=curr->next)
    {
        cout<<curr->data<<" ";
    }
 
    return 0;
}