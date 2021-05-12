#include<bits/stdc++.h>
using namespace std;
class Queue
{
        public:
        int size,cap;
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
            arr[size]=x;
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
            for(int i=0;i<size-1;i++)
            {
                arr[i]=arr[i+1];
            }
            size--;
            cout<<arr[0]<<" New Front\n";
        }
        int getFront()
        {
            if(isEmpty())
            {
                return -1;
            }
            return arr[0];
        }
        int getRear()
        {
            if(isEmpty())
            {
                return -1;
            }
            return arr[size-1];
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
    for(int i=0;i<q.cap;i++)
    {
        cout<<q.arr[i]<<" ";
    }
    return 0;
}