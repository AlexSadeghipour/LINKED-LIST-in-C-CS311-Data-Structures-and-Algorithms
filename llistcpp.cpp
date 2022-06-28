//HW#: HW3P1 llist
//Your name: Alexander Sadeghipour
//Complier:  g++
//CS311 Yoshii Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes

//EMACS HINT:
//  You can copy from a Word document to emacs (contrl-right click)
//  cntr-K cuts and cntr-Y pastes
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C// ====================================================
using namespace std;
#include <iostream>
#include "llist.h" 

// PURPOSE: Default constructor
llist::llist() {
  Front = NULL;
  Rear = NULL;
  Count = 0;
}
  

// PURPOSE: Deconstructor for llist
llist::~llist() {
  el_t temp; // variable to hold deleted nodes element.

  cout << "~ Calling the llist deconstructor ~" << endl;
  
  while (!isEmpty()) {
    deleteFront(temp);
  }

  cout << "=====================================" << endl << endl;
}

// PURPOSE: Checks if empty
bool llist::isEmpty() {
  
  if ((Front == NULL) && (Rear == NULL) && (Count == 0)) {
    return true;
  }
  
  //else list is not empty, return false.
  else {
    return false;
  }
}


// PURPOSE: This displays the nodes in a linked list.
// ALGORITHM: if the list is empty, print empty.
void llist::displayAll() {
  Node *p = Front; // pointer to traverse list.

  
  if (isEmpty()) {
    cout << " - [ empty ]" << endl;
  }

  
  else {
    cout << " - ";

    
    while (p != NULL) {
      cout << " " << p->Elem << " ";

      p = p->Next;
    }
    cout << endl;
  }
}

// PURPOSE: This adds a new node to the front of the linked list.
// PARAMETER: NewNum = element to assign to  the new node.
void llist::addFront(el_t NewNum) {

  if (isEmpty()) {
    
    Node *mynode = new Node; // creates new node
    Front = mynode;//initizaling front
    Rear = mynode;// initizaling rear
    Front->Elem = NewNum;
    Rear->Elem = NewNum;
    Rear->Next = NULL;
    Count++;
  }

  // 2) regular case
  else {
    Node *P = new Node; // creates new node
   P->Next = Front;
   Front = P;//front element is 
   P->Elem = NewNum;
    Count++;
  }
}

// PURPOSE: This adds a new node to the rear of the linked list.
// PARAMETER: NewNum = the element to assign to the new node.
void llist::addRear(el_t NewNum) {
  // 1) special case
  if (isEmpty()) {
    Node *mynode = new Node; // creates new node.
    Front = mynode;
    Rear = mynode;
    Front->Elem=NewNum;
    Rear->Elem=NewNum;
    Rear->Next = NULL;
    Count++;
  }

  // 2) regular case
  else {
    Rear->Next = new Node; // creates new node.
    // P->Elem = NewNum;
    Rear = Rear->Next;
    Rear->Elem = NewNum;
    Rear->Next = NULL;
    Count++;
  }
}

// PURPOSE: This deletes a node in front of the linked list.
// PARAMETER: OldNum = variable to hold deleted nodes element
void llist::deleteFront(el_t& OldNum) {
  // 1) error case
  // if empty, throw underflow.
  if (isEmpty()) {
    throw Underflow();
  }
  
  // 2) special case
  else if (Count == 1) {
    OldNum = Front->Elem;
    Node*first;
    first= NULL;
    delete Front;
    Front = NULL;
    Rear = NULL;
    Count--;
  }

  // 3) regular case
 
  else {
    OldNum = Front->Elem;
    Node* second = Front->Next; // pointer points to node after front.
    delete Front;
    Front = second;
    Count--;
  }
}

// PURPOSE: This deletes a node at the rear of a linked list.
// PARAMETER: OldNum = variable to hold deleted nodes element.
// ALGORITHM: Three cases must be checked
void llist::deleteRear(el_t& OldNum) {
  // 1) error case
  // if empty throw underflow
  if (isEmpty()) {
    throw Underflow();
  }

  // 2) special case
  // front and rear set to null.
  else if (Count == 1) {
    OldNum = Rear->Elem;
    delete Front;
    Front = NULL;
    Rear = NULL;
    Count--;
  }
  
  // 3) regular case

  else {
    OldNum = Rear->Elem;
    Node *p = Front; // pointer to traverse list.

    // loop to point to node before rear.
    while (p->Next != Rear) {
      p = p->Next;
    }

    delete Rear;
    Rear = p;
    Rear->Next = NULL;
    Count--;
  }
}

// PURPOSE: This deletes a node at the ith position in the linked list.
// PARAMETER: OldNum = variable to hold deleted nodes elemen.
void llist::deleteIth(int I, el_t& OldNum) {
  // 1) error case
  // if out of range, throw outofrange.
  if (I > Count || I < 1) {
    throw OutOfRange();
  }

  // 2) special case
  // if I equals 1, call deleteFront.
  else if (I == 1) {
    deleteFront(OldNum);
  }

  // 3) special case
  // if I equal Count, call deleteRear.
  else if (I == Count) {
    deleteRear(OldNum);
    Count--;
  }

  // 4) regular case
  else {
    Node *p = Front; // lead pointer to traverse list
    Node *lag = new Node; //lag pointer

    // loop to point to ith node.
    for(int k = 1; k <= I - 1; k++)
      {
	lag = p;
	p = p->Next;
      }

    lag->Next = p->Next;
    OldNum = p->Elem;
    delete p;
    Count--;
  }
}
// PURPOSE: .
// PARAMETER:
//  I = position to add new node.
// ALGORITHM: Four cases much be checked.
void llist::addbeforeIth(int I, el_t newNum) {
  // 1) error case
  // if out of range, throw outofrange.
  if (I > Count + 1 || I < 1) {
    throw OutOfRange();
  }

  // 2) special case
  // if I equals 1, call addFront.
  else if (I == 1) {
    addFront(newNum);
  }

  // 3) special case
  // if I equals count + 1, call addRear.
  else if (I == Count + 1) {
    addRear(newNum);
  }

  // 4) regular case
  else {
    Node *myNode = new Node; // add new ndoe
    Node *p = Front; 
    Node *lag = new Node;
    for (int k = 1; k <= I - 1; k++)
      {
	lag = p;
	p = p->Next;
      }

    lag->Next = myNode;
    myNode->Elem = newNum;
    myNode->Next = p;
    Count++;
  }
}

llist::llist(const llist& Original) {
  this->Front = NULL; this->Rear = NULL; this->Count = 0;
    
  Node* P;  // local pointer for OtherOne
  P = Original.Front;
  while (P != NULL)  // This uses a loop which repeats until you reach the end of OtherOne.
    {
      this->addRear(P->Elem);    //P’s element is added to this->
      P = P->Next;               // Go to the next node in OtherOne
    }
}

//PURPOSE: Allows the client to use "=" to linked lists
//PARAMETER: Other list passed by reference
llist& llist::operator=(const llist& OtherOne) {
  // First make sure this-> and OtherOne are not the same object.
  // To do this, compare the pointers to the objects .
  el_t x;
  if (&OtherOne != this)  // if not the same
    {
      // this-> object has to be emptied first.
      while (!this->isEmpty() )
	this->deleteRear(x);
      // this-> object has to be built up by allocating new cells with OtherOne elements (**)
      Node* P;  // local pointer for OtherOne
      P = OtherOne.Front;
      while (P != NULL)  // a loop which repeats until you reach the end of OtherOne.
        {
	  this->addRear(P->Elem);    //P’s element is added to this->
	  P = P->Next;                         // Go to the next node in OtherOne
        }
    }// end of if
  return *this;    // return the result unconditionally.  Note that the result is returned by reference.
}