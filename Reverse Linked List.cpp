#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *insert(Node *head, int data)
{
	Node *p = head;
	while (p->next != NULL)
		p = p->next;
	p->next = new Node(data);
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

Node *reverseiterative(Node *head)
{
	Node *current = head;
	Node *ahead = NULL, *behind = NULL;
	while (current != NULL)
	{
		ahead = current->next;
		current->next = behind;
		behind = current;
		current = ahead;
	}
	return head = behind;
}

Node *reverserecursive(Node *head)
{
	if (head == NULL || head->next == NULL)
		return head;
	Node *rest = reverserecursive(head->next);
	head->next->next = head;
	head->next = NULL;
	return rest;
}

int main()
{
	int n, a;
	cout << "Number of Nodes: " << endl;
	cin >> n;
	cout << "Enter head: " << endl;
	cin >> a;
	Node *head = new Node(a);
	for (int i = 0; i < n; i++)
	{
		cout << "Enter node value: " << endl;
		cin >> a;
		insert(head, a);
	}
	cout << "Linked List: ";
	print(head);
	cout << endl
		 << "Reversed Iterative: ";
	head = reverseiterative(head);
	print(head);
	cout << endl
		 << "Reversed Recursive: ";
	head = reverserecursive(head);
	print(head);
	cout << endl;
}