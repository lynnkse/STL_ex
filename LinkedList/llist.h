#ifndef LLIST
#define LLIST

#include<algorithm>
#include<iterator>

#define TYP template<typename T>

using namespace std;

TYP
struct LinkedNode
{
	T mData;
	LinkedNode<T>* next;
	LinkedNode<T>* last;
};

TYP
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList& rhs);
	LinkedList& operator=(const LinkedList& rhs);

	bool isEmpty();
	LinkedNode<T>* getFirst();
	LinkedNode<T>* getLast();

	void insertFirst(T data);
	void insertLast(T data);
	void insertAfter(T tKey, T tData);
	void removeFirst();
	void removeLast();
	void remove(T removalCandidate);
	void print();
	
private:
	void destroy();
private:
	LinkedNode<T>* mFirst;
	LinkedNode<T>* mLast;
};

TYP
LinkedList<T>::LinkedList<T>()
{
	mFirst = NULL;
	mLast = NULL;
}

TYP
void LinkedList<T>::destroy()
{
	LinkedNode<T>* current = mFirst;
	while (current)
	{
		LinkedNode<T>* old = current;
		current = current->next;
		delete old;
		old = NULL;
	}
	mFirst = NULL;
	mLast = NULL;
}

TYP
LinkedList<T>::~LinkedList()
{
	destroy();
}

TYP
LinkedList<T>::LinkedList<T>(const LinkedList<T>& rhs)
{
	if (rhs.isEmpty())
		return;
	mFirst = new LinkedNode<T>;
	mFirst->mData = rhs->mFirst->mData;
	mFirst->last = NULL;
	LinkedNode<T>* currnew = mFirst;
	LinkedNode<T>* currold = rhs->mFirst;
	while (currold->next)
	{
		currnew->next = new LinkedNode<T>;
		currnew->next->last = currnew;
		currnew = currnew->next;
		currold = currold->next;
		currnew->mData = currold->mData;
	}
	mLast = currnew;
	mLast->next = NULL;
}

TYP
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
	if (*this == rhs)
		return *this;
	destroy();
	if (rhs.isEmpty())
		return;
	mFirst = new LinkedNode<T>;
	mFirst->mData = rhs->mFirst->mData;
	mFirst->last = NULL;
	LinkedNode<T>* currnew = mFirst;
	LinkedNode<T>* currold = rhs->mFirst;
	while (currold->next)
	{
		currnew->next = new LinkedNode<T>;
		currnew->next->last = currnew;
		currnew = currnew->next;
		currold = currold->next;
		currnew->mData = currold->mData;
	}
	mLast = currnew;
	mLast->next = NULL;
	return *this;
}

TYP
void LinkedList<T>::insertFirst(T data)
{
	LinkedNode<T>* newnode = new LinkedNode<T>;
	newnode->mData = data;
	newnode->next = mFirst;
	newnode->last = NULL;
	mFirst->last = newnode;
	mFirst = newnode;
}

TYP
void LinkedList<T>::insertLast(T data)
{
	LinkedNode<T>* newnode = new LinkedNode<T>;
	newnode->next = NULL;
	newnode->last = mLast;
	newnode->mData = data;
	mLast->next = newnode;
	mLast = newnode;
}

TYP
bool LinkedList<T>::isEmpty()
{
	if (!mFirst)
		return true;
	else
		return false;
}

TYP
LinkedNode<T>* LinkedList<T>::getFirst()
{
	return mFirst;
}

TYP
LinkedNode<T>* LinkedList<T>::getLast()
{
	return mLast;
}

TYP
void LinkedList<T>::insertAfter(T tKey, T tData)
{
	LinkedNode<T>* curr = mFirst;
	for (int i = 0; i < tKey; i++)
	{
		curr = curr->next;
		if (curr == NULL)
			return;
	}
	LinkedNode<T>* newnode = new LinkedNode<T>;
	newnode->mData = tData;
	newnode->next = curr->next;
	newnode->next->last = newnode;
	curr->next = newnode;
	newnode->last = curr;
}

TYP
void LinkedList<T>::removeFirst()
{
	mFirst = mFirst->next;
	delete mFirst->last;
	mFirst->last = NULL;
}

TYP
void LinkedList<T>::removeLast()
{
	mLast = mLast->last;
	delete mLast->next;
	mLast->next = NULL;
}

TYP
void LinkedList<T>::remove(T removalCandidate)
{
	LinkedNode<T>* curr = mFirst;
	int i = 0;
	while (curr->mData != removalCandidate)
	{
		curr = curr->next;
	}
	curr->next->last = curr->last;
	curr->last->next = curr->next;
	delete curr;
	curr = NULL;
}

TYP
void LinkedList<T>::print()
{
	LinkedNode<T>* curr = mFirst;
	do
	{
		cout << curr->mData << ", ";
		curr = curr->next;
	} while (curr);
	cout << endl;
}
#endif

