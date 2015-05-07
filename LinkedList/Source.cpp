#include<iostream>
#include"llist.h"

int main()
{
	bool end = false;
	LinkedList<int> list;
	while (!end)
	{
		cout << "Linked List menu:" << endl;
		int choice = 0;
		cout << "3) Get first node; 4) Get last node; 5) Insert last; 6) Insert first; 7) Insert after; 8) Remove last; 9) Remove first; 10) Remove by value; 11) Display list; 12)Quit" << endl;
		int i;
		cin >> i;
		switch (i)
		{
		case 3://get first node
			cout << list.getFirst() << endl;
			break;
		case 4://get last node
			cout << list.getLast() << endl;
			break;
		case 5://insert last
			cout << "Enter value: " << endl;
			int val;
			cin >> val;
			list.insertLast(val);
			break;
		case 6://insert first
			cout << "Enter value: " << endl;
			int value;
			cin >> value;
			list.insertFirst(value);
			break;
		case 7://insert after
			cout << "Enter value: " << endl;
			int v;
			cin >> v;
			cout << "Enter position, after which to insert: " << endl;
			int pos;
			cin >> pos;
			list.insertAfter(pos, v);
			break;
		case 8://remove last
			list.removeLast();
			break;
		case 9://remove first
			list.removeFirst();
			break;
		case 10://remove by value
			cout << "Enter value to remove: " << endl;
			int va;
			cin >> va;
			list.remove(va);
			break;
		case 11://display list
			list.print();
			break;
		case 12://quit
			end = true;
			break;
		}
	}
}