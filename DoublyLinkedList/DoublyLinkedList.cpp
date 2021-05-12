#include<bits/stdc++.h>
using namespace std;
#define max 1000
struct Node {
    int data;
    Node *next;
    Node *prev;
    Node(int x) {
        data = x;
        next=prev=NULL;
    }
} ;
Node *insertAtHead(Node *head, int x)
{
    Node *temp =new Node(x);
    temp->next=head;
    if(head!=NULL)
    {
        head->prev=temp;
    }
    return temp;
}
Node *insertAtEnd(Node *head, int x)
{
    Node *temp =new Node(x);
    if(head==NULL)
    {
        return temp;
    }
    Node *curr=head;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=temp;
    temp->prev=curr;
    return head;
}
Node *rev(Node *head)
{
    if (head->next == NULL)
            return head;
        Node *curr = head;
        while (curr->next != NULL) {
            Node *temp = curr->next;
            curr->next = curr->prev;
            curr->prev = temp;
            curr = curr->prev;
        }
        Node *temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        return curr;
}
Node *deleteFromHead(Node *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        return NULL;   
    }
    else
    {
        Node *temp= head;
        head=head->next;
        head->prev=NULL;
        delete temp;
        return head;
    }
}
Node *deleteFromEnd(Node *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        delete head;
        return NULL;   
    }
    Node *curr= head;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->prev->next=NULL;
    delete curr;
    return head;
}
void display(Node *head)
{
    Node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<"\n";
        curr=curr->next;
    }
    cout<<"________________________";
}
int main()
{
        Node *head = NULL; 
        display(head);
        cout<<"\n";
        head = insertAtHead(head,20);
        display(head);
        cout<<"\n";
        head = insertAtHead(head,10);
        display(head);
        cout<<"\n";
        head = insertAtHead(head, 30);
        display(head);
        cout<<"\n";
        head = insertAtHead(head, 40);
        display(head);
        cout<<"\n";
        head = rev(head);
        display(head);
        cout<<" Head changed so reversed\n";
        head = deleteFromHead(head);
        display(head);
        cout<<"\n";
        head = deleteFromEnd(head);
        display(head);
        cout<<"\n";
       head = insertAtEnd(head,20);
        display(head);
        
}