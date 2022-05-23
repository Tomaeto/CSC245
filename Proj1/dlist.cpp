#include <cstddef> 
#include <iostream>

using namespace std;

template<class ItemType>
struct NodeType
{
	ItemType info;
	NodeType<ItemType>*	next;
	NodeType<ItemType>*	back;
};

template <class ItemType>		
DList<ItemType>::DList()		// Class constructor
{
    length = 0;
    head = NULL;
}

template <class ItemType>
DList<ItemType>::~DList   ()		
{
	// Post: List is empty; All items have been deallocated.
	makeEmpty();
}

template <class ItemType>
void DList<ItemType>::makeEmpty()
{
    // Post: List is empty; all items have been deallocated.
	NodeType<ItemType>* locdata = new NodeType<ItemType>;
	locdata = head;
	ItemType item;
	while (locdata != NULL)
	{
		item = locdata -> info;
		deleteItem(item);
		locdata = locdata -> next;
	}

}

template <class ItemType>
void DList<ItemType>::deleteItem (ItemType item)	
{
	//  Pre :  item to be deleted is passed in via parameter 
        // Post :  item is deleted if it exists in list 
	NodeType<ItemType>* locdata = new NodeType<ItemType>;
	locdata = location(item);	
	deleteLocation(locdata);
	locdata = NULL;
}

template <class ItemType>
bool DList<ItemType>::inList (ItemType item) const
{
	//  Pre :  item to be located is passed in via parameter 
        // Post :  function returns bool value if item is found 
	NodeType<ItemType>* itemLoc = new NodeType<ItemType>;
	itemLoc = location(item);
	if (itemLoc != NULL)
	{
		itemLoc = NULL;
		return true;
	}
	else
	{
		itemLoc = NULL;
		return false;
	}
}

template <class ItemType>
bool DList<ItemType>::isEmpty() const		
{
	// Post : function returns true if list is empty, false otherwise
	if (head == NULL)
		return true;
	else
		return false;
}

template <class ItemType>
void DList<ItemType>::print() const	
{
	// Pre  : List is not empty 
	// Post : Items in List have been printed to screen

 	NodeType<ItemType>* locdata = new NodeType<ItemType>;
	locdata = head;
	int nodeCount = 1;
	while (locdata != NULL)
	{
		cout << nodeCount << ":\t\t";
		cout << locdata -> info << endl;
		locdata = locdata -> next;
		nodeCount++;
	}
	cout << endl;
	locdata = NULL;

}
	
template <class ItemType>
void DList<ItemType>::insertHead(ItemType item)	
{
	//  Pre : item to be inserted is passed in via parameter
        // Post : item is inserted at head of list;  Former first node is 
        //        linked back to this new one via double link;
        //        Length incremented;  Special case handled if list is empty 
	NodeType<ItemType>* newNode = new NodeType<ItemType>;
	newNode -> info = item;
	newNode -> back = NULL;
	if (isEmpty() == true)
	{
		newNode -> next = NULL;
		head = newNode;
	}
	else
	{
		newNode -> next = head;
		head -> back = newNode;
		head = newNode;
		
	}
	length++;
	newNode = NULL;
}

template <class ItemType>
void DList<ItemType>::appendTail(ItemType item)
{
	//  Pre :  item to be inserted is passed in via parameter
        // Post :  item is added to tail of list; Former last node
        //         is linked to this new one via double link 
	NodeType<ItemType>* newNode = new NodeType<ItemType>;
	newNode -> info = item;
	newNode -> next = NULL;
	if (isEmpty() == true)
	{
		newNode -> back = NULL;
		head = newNode;
	}
	else
	{
		newNode -> back = last();
		last() -> next = newNode;
	}
	length++;
	newNode = NULL;
}

template <class ItemType>
int DList<ItemType>::lengthIs() const	
{
	// Post : Function returns current length of list  
	return length;
}

template <class ItemType>
NodeType<ItemType>* DList<ItemType>::location(ItemType item) const	
{
	//  Pre : item to be located is passed in via parameter 
        // Post : function returns address of item being searched for --
        //        if not found, NULL is returned  
	NodeType<ItemType>* itemloc = new NodeType<ItemType>;
	itemloc = head;
	bool inList = false;
	for (int i = 0; i < length; i++)
	{
		if (itemloc -> info == item)
		{
			inList = true;
		}
		else
			itemloc = itemloc -> next;
	}
	if (inList == true)
		return itemloc;
	else
		return NULL;
}

template <class ItemType>
NodeType<ItemType>* DList<ItemType>::last() const	
{
	// Post : Function returns location of current last item in list
	NodeType<ItemType>* locdata = new NodeType<ItemType>;
	locdata = head;
	while (locdata -> next != NULL)
	{
		locdata = locdata -> next;
	}

	return locdata;

}

template <class ItemType>
void DList<ItemType>::deleteLocation (NodeType<ItemType>* delPtr)	
{

	//  Pre : Item to be deleted exits in list and its location
        //        is passed in via parameter
                   
	// Post : Location passed in is removed from list;  Length
        //        is decremented, and location is deallocated 

        // Special Cases Handled for Deleting Only One Item in List,
        // The Head Item of List, and the Tail Item of List

	if (delPtr -> next == NULL && delPtr -> back == NULL)
	{
		head = NULL;
	}
	else if (delPtr -> back == NULL)
	{
		head -> next -> back = NULL;
		head = head -> next;
	}
	else if (delPtr -> next == NULL)
	{
		delPtr -> back -> next = NULL;
	}
	else if (delPtr -> next != NULL && delPtr -> back != NULL)
	{	
		delPtr -> next -> back = delPtr -> back;
		delPtr -> back -> next = delPtr -> next;
	}
	delete delPtr;
	delPtr = NULL;
	length--;

}
