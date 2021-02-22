#include "LinkedList.h"

LinkedList::LinkedList()
{
	first = nullptr;
	mySize = 0;
}


LinkedList::LinkedList(const LinkedList& origList)
{
	mySize = origList.mySize;//el size b2a nfs el tany
	
	if (mySize == 0)//mfesh 7aga ten2lha
	{
		return ;
	}
			//f-> 1  2->  3-> 4->  5-> nullptr
			//f-> 1->2-> 3
		first = new Node(origList.first->data);
		NodePointer origptr = origList.first->next;
		NodePointer predptr = first;
		for (int i = 0; origptr != 0; i++)
		{

			predptr->next = new Node(origptr->data);
			predptr = predptr->next;
			origptr = origptr->next;
		}

}


LinkedList::~LinkedList()
{
	NodePointer pred = first , ptr;
	
	while (pred!=0)
	{
		ptr = pred->next;
		delete pred;
		pred = ptr;

	}

}


const LinkedList& LinkedList::operator=(const LinkedList& rightSide)
{
	mySize = rightSide.mySize;
	
	if (mySize == 0)
	{
		return *this;
	}
	if (this !=&rightSide)
	{
		this->~LinkedList();

	
	first = new Node(rightSide.first->data);
	NodePointer origptr = rightSide.first->next;
	NodePointer predptr = first;
	for (int i = 0; origptr != 0; i++)
	{
		
		predptr->next = new Node(origptr->data);
		predptr = predptr->next;
		origptr = origptr->next;
	}

	}
	return *this;
}


bool LinkedList::empty()
{
	if (mySize==0)
	{
		return true;
	}
	return false;
}


void LinkedList::insert(ElementType dataVal, int index)
{
	if (index>mySize||index<0)
	{
		cerr << "invalid position";
		return;
	}
	NodePointer preddptr=first;
	NodePointer newn = new Node(dataVal);
	//0
	// 1 2 0 3 4 
	if (index==0)
	{
		newn->next = first;
		first = newn;

	}
	else{
	for (int i = 0; i < index-1; i++)
	{
		preddptr = preddptr->next;
	}
	newn->next = preddptr->next;
	preddptr->next = newn;}
	mySize++;
}


void LinkedList::erase(int index)
{
	// 1 2 3 4
	NodePointer erasing=first->next;
	NodePointer predptr= first;
	if (index==0)
	{
		
		erasing = first;
		first = erasing->next;
		delete erasing;


	}
	else {
		//1 2 3 4
		//
	for (int i = 1; i < index; i++)
	{
		predptr = predptr->next;
		erasing = predptr->next;
		

	}
		predptr->next = erasing->next;
		delete erasing;
	
	}
	mySize--;
}


void LinkedList::display(ostream& out) const
{
	NodePointer current = first;
	for (int i =0 ; i < mySize; i++)
	{
		
		out << current->data << " ";
		current = current->next;
	}
	out<<endl;
}


int LinkedList::search(ElementType dataVal)
{
	// 1 2 2 3 4
	NodePointer current = first;
	for (int i = 0; i < mySize; i++)
	{
		if (current->data==dataVal)
		{
			return i;
		}
		current = current->next;
	}
	return -1;
}

int LinkedList::nodeCount()
{
	NodePointer current = first;
	int count = 0;
	for (int i = 0; i < mySize; i++)
	{
		count++;
		current = current->next;
	}
	return count;
}

void LinkedList::reverse()
{

	LinkedList copy(*this);

	//i =3
	for (int i = 0; i < mySize; i++)
	{
		NodePointer current = copy.first;
		NodePointer current2 = first;
		// 1 2 3 4
		// 4 3 2 1

		// counts from top to bottom
		for (int j = i; j < mySize-1; j++)
		{
			current = current->next;
		}

		// counts from botoom to top
		// 1 2 3 4
		for (int j = 0; j < i; j++)
		{
			current2 = current2->next;
		}

		//fills to the new 
		current2->data = current->data;
	}
	
}

bool LinkedList::ascendingOrder()
{
	NodePointer current = first;
	// 1 2 3 4 
	for (int i = 0; i < mySize; i++)
	{
		if (current < current->next) 
		{
			return false;
		}
		current = current->next;
	}
	return true;
	
}

double LinkedList::avg()
{
	double sum = 0;
	NodePointer ptr = first;
	for (int i = 0; i < mySize; i++)
	{
		sum += ptr->data;
		ptr = ptr->next;
	}
	return (sum / mySize);
}

int LinkedList::predptr(int item)
{
	NodePointer precurrent = first;
	NodePointer current = precurrent->next;
	if (precurrent->data==item)
	{
		cout << "no pre";
		return -1;
	}
	for (int i = 0; i < mySize; i++)
	{
		if (current->data == item)
		{
			return precurrent->data;
		}
		precurrent = precurrent->next;
		current = current->next;
	}
	return -1;
}

LinkedList LinkedList::shufflem(const LinkedList& rightSide)
{
	LinkedList l3;
	NodePointer ptr1, ptr2;
	ptr1 = first->next;
	ptr2 = rightSide.first->next;
	l3.first = new Node(first->data);
	l3.first->next = new Node(rightSide.first->data);
	l3.mySize+=2;
	int size = mySize;
	for (int j= 1; j< size; j++)
	{
		for (int i = 0; i < 2; i++)
		{
			if (i == 0) 
			{
				l3.insert(ptr1->data, l3.mySize);
				ptr1 = ptr1->next;
			}
			else 
			{
				l3.insert(ptr2->data, l3.mySize);
				ptr2 = ptr2->next;
			}
		}
	}
	return l3;
}

ostream& operator<<(ostream& out, const LinkedList& aList)
{
	aList.display(cout);
	return out;
}


