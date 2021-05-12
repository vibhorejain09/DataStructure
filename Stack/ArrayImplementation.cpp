#include<bits/stdc++.h>
using namespace std;
#define max 1000
class Stack
{
	public:
	 int top;
	 int arr[max];
     Stack() { top = -1; }
	void push(int x) 
	{
		if (top >= (max-1)) {
			cout<<"Error: Stack Overflow\n";
		}
		else {
			top++;
			arr[top] = x;
			cout<<x<<" pusheed succesfully\n";
		}
	}
	int pop()
	{
    	if (top < 0) 
    	{
        	cout << "Error: Stack Underflow\n";
        	return 0;
    	}
    	else 
    	{
    		int x = arr[top];
    		top--;
        	return x;
    	}
	}
	int peek()
	{
    	if (top < 0) 
    	{
        	cout << "Stack is Empty\n";
        	return 0;
    	}
    	else 
    	{
        	int x = arr[top];
        	return x;
    	}
	}
	bool empty() {
		if (top < 0)
			return true;
		else
			return false;
	}
};
int main()
{
    class Stack s;
    s.peek();
    s.push(100);
    s.push(200);
    s.push(3000);
    cout << s.pop() << " Popped succesfully\n";
    cout<< s.peek() << " is top element\n";
    cout<<"Elements present in stack : ";
    for (int i=0;i<=s.top;i++)
    {
    	cout<<s.arr[i]<<" ";
    }
    while(!s.empty())
    {
        cout<<s.peek()<<" ";
        s.pop();
    }
 
    return 0;
}