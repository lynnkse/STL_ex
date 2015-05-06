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
	LinkedNode* next;
	LinkedNode* last;
	class iterator : std::iterator {}; //can I create class inside struct???
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
	
	//iterator
	class iterator: std::iterator {};

private:
	void destroy();
private:
	LinkedNode* mFirst;
	LinkedNode* mLast;
};

TYP
LinkedList<T>::LinkedList<T>()
{
	mFirst = new LinkedNode();
	mLast = mFirst;
}

TYP
void LinkedList<T>::destroy()
{
	LinkedList<T>::iterator iter = 0;
	for (iter = mFirst; iter != mLast; iter++)
	{
		delete iter;
	}
	mFirst = NULL;
	mLast = NULL;
}

TYP
LinkedList<T>::LinkedList()
{
	destroy();
}

TYP
LinkedList<T>::LinkedList<T>(const LinkedList<T>& rhs)
{
	mFirst = new LinkedNode<T>();
	mFirst->mData = rhs.mFirst->mData;
	mFirst->last = NULL;
	LinkedNode<T>::iterator iter = rhs.mFirst;
	LinkedNode<T>* last = mFirst; //keeps track of the last node
	LinkedNode<T>::iter           //need an iterator here
	for (iter; iter != rhs.mLast; iter++)
	{
		iter->
		last->next = new LinkedNode<T>();
		/*last->next->mData = iter->mData;
		last->next->last = last;
		last = last->next;*/
		last->next->mData = iter->
	}
	mLast = last;
}

TYP
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
	destroy();
	

}
#endif

