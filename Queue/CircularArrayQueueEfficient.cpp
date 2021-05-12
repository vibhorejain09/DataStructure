#include<bits/stdc++.h>
using namespace std;
class Queue
{
        public:
        int size,cap;
        int front=0,rear=-1;
        int *arr;
        Queue(int c)
        {
            cap = c;
            size = 0;
            arr = new int[cap];
        }
        bool isFull()
        {
            return (size==cap);
        }
        bool isEmpty()
        {
            return (size==0);
        }
        void Enqueue(int x)
        {
            if(isFull())
            {
                cout<<"Queue Full\n";
                return;
            }
            rear=(rear+1)%cap;//also (front+size-1)%cap
            arr[rear]=x;
            size++;
            cout<<x<<" Added successfully\n";
        }
        void Dequeue()
        {
            if(isEmpty())
            {
                cout<<"Empty Queue\n";
                return;
            }
            int x=arr[0];
            front=front+1;
            size--;
            cout<<x<<" Removed\n";
        }
        int getFront()
        {
            if(isEmpty())
            {
                return -1;
            }
            return arr[front];
        }
        int getRear()
        {
            if(isEmpty())
            {
                return -1;
            }
            return arr[rear];
        }
};
int main()
{
    class Queue q(4);
    q.Dequeue();
    q.Enqueue(10);
    q.Enqueue(20);
    q.Dequeue();
    q.Enqueue(40);
    q.Enqueue(50);
    q.Enqueue(60);
    q.Enqueue(70);
    cout<<q.getFront()<<" "<<q.getRear()<<" "<<q.size<<"\n";
    //Improper
    for(int i=0;i<q.cap;i++)
    {
        cout<<q.arr[i]<<" ";
    }
    cout<<"\n";
    //Proper order
    for(int i=q.front;i<q.cap || i<=q.rear;i++)
    {
        cout<<q.arr[i]<<" ";
        if(i==q.size-1)
        {
            for(int j=0;j<=q.rear;j++)
            {
                cout<<q.arr[j]<<" ";
            }
        }
    }
    return 0;
}