#include<bits/stdc++.h>
#include"List.h"
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //for getting input from input.txt
	freopen("output.txt", "w", stdout); // for getting output from output.txt
#endif
	List l;
	l.push_front(10);
	l.push_front(30);
	l.push_back(50);
	l.push_back(110);
	l.push_back(70);
	l.insert(90, 2);
	l.insert(80, 0);

	Node* head = l.begin();
	while (head != NULL)
	{
		cout << head->getData() << "->";
		head = head -> next;
	}

	cout << endl;

	l.pop_front();
	Node* head2 = l.begin();
	while (head2 != NULL)
	{
		cout << head2->getData() << "->";
		head2 = head2 -> next;
	}

	cout << endl;

	l.pop_back();
	Node* head3 = l.begin();
	while (head3 != NULL)
	{
		cout << head3->getData() << "->";
		head3 = head3->next;
	}

	cout << endl;

	l.remove(2);
	Node* head4 = l.begin();
	while (head4 != NULL)
	{
		cout << head4->getData() << "->";
		head4 = head4->next;
	}

	cout << endl;
	int key;
	cin >> key;
	cout <<  l.recursiveSearch(key) << endl;
}