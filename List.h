#include<bits/stdc++.h>
using namespace std;

class List;

class Node
{
	int data;

public:
	Node* next;
	Node(int d): data(d), next(NULL)
	{
		//We have used initialisation list here as it helps if we have any constant data member in our function
	}

	int getData()
	{
		return data; // We have made getData function because the data variable is private in class Node
	}

	// ~Node()
	// {
	// 	if (next != NULL)
	// 	{
	// 		delete next;
	// 	}
	// 	cout << "Deleting Node with Data : " << data << endl;
	// }
	friend class List;
};

class List
{
	Node* head;
	Node* tail;

	//Creating a helper function for Recursive Search(scroll down for that)
	int searchHelper(Node* start, int key)
	{
		//base case
		if (start == NULL)
			return -1; // this means that we have reached the end of linked list and still have NOT found our key
		//value matches
		if (start->data == key)
			return 0;

		//remaining part of linked list
		int subIdx = searchHelper(start->next, key);
		if (subIdx == -1)
		{
			return -1;
		}
		else
			return subIdx + 1;

	}
public:
	List(): head(NULL), tail(NULL)
	{

	}

	Node* begin()
	{
		return head;
	}

	//Insertion of Node before head
	void push_front(int data)
	{
		// Case 1 : Where we have empty linked list so after insertion head and tail will point to the same node
		if (head == NULL)
		{
			Node* n = new Node(data); // Using new to create a node because we want the node to persist even after the function call gets over
			head = tail = n;
			return;
		}
		// Case 2 : Already a node exists in the given linked list so we have to adjust the head
		else
		{
			Node* n = new Node(data);
			n->next = head;
			head = n;
		}
	}

	//Insertion of Node after tail
	void push_back(int data)
	{
		if (head == NULL)
		{
			Node* n = new Node(data);
			head = tail = n;
			return;
		}
		else
		{
			Node* n = new Node(data);
			tail -> next = n;
			tail = n;
		}
	}

	//Insertion of Node at a particular position
	void insert(int data, int pos)
	{
		if (pos == 0)
		{
			push_front(data);
			return;
		}
		else
		{
			Node* temp = head;
			for (int jump = 1; jump <= pos - 1; jump++)
			{
				temp = temp->next;
			}

			Node* n = new Node(data);
			n->next = temp->next;
			temp->next = n;
		}
	}

	//Normal Search
	int search(int key)
	{
		Node* temp = head;
		int idx = 0;

		while (temp != NULL)
		{
			if (temp->data == key)
			{
				return idx;
			}
			else
			{
				idx++;
				temp = temp->next;
			}
		}
		return -1;
	}

	//Recursive Search : For this we will need a helper function created above
	int recursiveSearch(int key)
	{
		int idx = searchHelper(head, key);
		return idx;
	}

	//Deleting a Node from front of the Linked List
	void pop_front()
	{
		Node* temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}

	void pop_back()
	{
		if (head == NULL)
			cout << "Empty Linked List";

		if (head->next == NULL)
		{
			delete head;
		}

		// Find the second last node
		Node* second_last = head;
		while (second_last->next->next != NULL)
			second_last = second_last->next;

		// Delete last node
		delete second_last->next;

		// Change next of second last
		second_last->next = NULL;
	}

	void remove(int pos)
	{
		if (head == NULL)
			cout << "Empty Linked List";

		// Store head node
		Node* temp = head;

		// If head needs to be removed
		if (pos == 0)
		{
			// Change head
			head = temp->next;

			// Free old head
			delete temp;
		}

		// Find previous node of the node to be deleted
		for (int i = 0; temp != NULL && i < pos - 2; i++)
			temp = temp->next;

		// If position is more than number of nodes
		if (temp == NULL || temp->next == NULL)
			cout << "Invalid position" << endl;

		// Node temp->next is the node to be deleted
		// Store pointer to the next of node to be deleted
		Node* temp2 = temp->next->next;

		// Unlink the node from linked list
		delete temp->next; // Free memory

		// Unlink the deleted node from list
		temp->next = temp2;
	}

	// ~List()
	// {
	// 	if (head != NULL)
	// 	{
	// 		delete head;
	// 		head = NULL;
	// 	}
	// }
};