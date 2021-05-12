#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
    }
} ;
Node *insertAtHead(Node *head,int x)
{
    Node *temp=new Node(x);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else{
        temp->next=head->next;
        head->next=temp;
        int t= head->data;
        head->data=temp->data;
        temp->data = t;
        return head;
    }
}
Node *insertAtEnd(Node *head,int x)
{
    Node *temp=new Node(x);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else{
        temp->next=head->next;
        head->next=temp;
        int t= temp->data;
        temp->data=head->data;
        head->data = t;
        return temp;
    }
}
Node *deleteHead(Node *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==head)
    {
        delete head;
        return NULL;
    }
    head->data=head->next->data;
    Node *temp=head->next;
    head->next=head->next->next;
    delete temp;
    return head;
}
Node *deleteKthNode(Node *head, int k)
{
    if(head==NULL)
    {
        return head;
    }
    if(k==1)
    {
        return deleteHead(head);
    }
    Node *curr=head;
    for(int i=0;i<k-2;i++)
    {
        curr=curr->next;
    }
    Node *temp=curr->next;
    curr->next=curr->next->next;
    delete temp;
    return head;
}
void display(Node *head)
{
    if(head==NULL)
    {
        return;
    }
    Node *p =head;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
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
        head = insertAtEnd(head, 40);
        display(head);
        cout<<"\n";
        head = insertAtEnd(head, 50);
        display(head);
        cout<<"\n";       
        head = deleteHead(head);
        display(head);
        cout<<"\n";
        head = deleteHead(head);
        display(head);
        cout<<"\n";
        head = deleteKthNode(head, 2);
        display(head);
        cout<<"\n";         
}