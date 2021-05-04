#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	Node(int data)
	{
		this->data=data;
		next=NULL;
	}
};

struct LinkedList
{
	Node* head;
	LinkedList()	
	{
		head=NULL;
	}
	void reverse()
	{
		Node* current=head;
		Node* prev=NULL, *next=NULL;
		while(current!=NULL)
		{
			next=current->next;
			current->next=prev;
			prev=current;
			current=next;	
		}
		head=prev;
	}
	void print()
	{
		struct Node* temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
	void push(int data)
	{
		Node* temp=new Node(data);
		temp->next=head;
		head=temp;
	}
};

int main()
{
	LinkedList ll;
	ll.push(1);
	ll.push(2);
	ll.push(3);
	ll.push(4);
	cout<<"original:"<<endl;
	ll.print();
	cout<<endl;
	ll.reverse();
	cout<<"reversed:"<<endl;
	ll.print();
}

