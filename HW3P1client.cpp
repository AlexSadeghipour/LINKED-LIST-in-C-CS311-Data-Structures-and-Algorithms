using namespace std;

#include <iostream>
#include "llist.h"
void CopyTest(llist copiedList)
{
  cout << "in copy test" << endl;
  copiedList.addRear(6);
  copiedList.displayAll();
  cout << "finished" << endl;
}

// PURPOSE: This is the first case test.
void caseOne()
{
  llist L; // linked list L
  int x; // to hold a removed element

  cout << "=============== CASE 1 ==============" << endl;

  //1 check empty and report the result
  cout << "Test " << 1 << endl;
  if (L.isEmpty()) {
    cout << " - The linked List is empty." << endl;
  }
  else {
    cout << " - The linked List is not empty." << endl;
  }
  cout << endl;

  //2 display the list
  cout << "Test " << 2 << endl;
  L.displayAll();
  cout << endl;

  //3 add 4 integers 1,2,3,4
  cout << "Test " << 3 << endl;
  L.addRear(1);
  L.addRear(2);
  L.addRear(3);
  L.addRear(4);
  cout << endl;

  //4 display the list
  cout << "Test " << 4 << endl;
  L.displayAll();
  cout << endl;

  //5 remove from front twice (and display the elements removed)
  cout << "Test " << 5 << endl;
  L.deleteFront(x);
  cout << " - Element " << x << " has been removed." << endl;
  L.deleteFront(x);
  cout << " - Element " << x << " has been removed." << endl;
  cout << endl;

  //6 display the list
  cout << "Test " << 6 << endl;
  L.displayAll();
  cout << endl;

  //7 check empty and report the result
  cout << "Test " << 7 << endl;
  if (L.isEmpty()) {
    cout << " - The linked List is empty." << endl;
  }
  else {
    cout << " - The linked List is not empty." << endl;
  }
  cout << endl;

  //8 remove from the rear twice (display the element removed)
  cout << "Test " << 8 << endl;
  L.deleteRear(x);
  cout << " - Element " << x << " has been removed." << endl;
  L.deleteRear(x);
  cout << " - Element " << x << " has been removed." << endl;
  cout << endl;

  //9 check empty again and report the result
  cout << "Test " << 9 << endl;
  if (L.isEmpty()) {
    cout << " - The linked List is empty." << endl;
  }
  else {
    cout << " - The linked List is not empty." << endl;
  }
  cout << endl;
  
  // add to front 10
  cout << "Test " << 10 << endl;
  L.addFront(5);
  L.addFront(6);
  L.addFront(8);
  L.addFront(9);

  //11 display list
  cout << "Test " << 11 << endl;
  L.displayAll();

  //12
  L.deleteRear(x);
  L.deleteRear(x);
  L.deleteRear(x);
  L.deleteRear(x);

  //13
  cout << "test " << 13 << endl;
  L.displayAll();
} //end of case 1

// PURPOSE: This is the second case test.
void caseTwo()
{
  llist L2; // linked list L2
  int x; // to hold the removed element
  int c = 1; // displayed step number

  cout << "=============== CASE 2 ==============" << endl;

  // 1.add to front once   (element 5)
  cout << "Test " << c++ << endl;
  L2.addFront(9);
  L2.addFront(8);
  L2.addFront(6);
  L2.addFront(5);
  cout << endl;

  // 2.add to front again  (element 4)
  cout << "Test " << c++ << endl;
  L2.displayAll();
  cout << endl;

  // 3.addbeforeith
  cout << "Test " << c++ << endl;
  L2.addbeforeIth(1,4);
  L2.displayAll();
  cout << endl;

  // 4.add to rear 3 times (elements 6,8,9)
  cout << "Test " << c++ << endl;
  L2.addbeforeIth(4,7);
  cout << endl;

  // 5. display all
  cout << "Test " << c++ << endl;
  L2.addbeforeIth(7,10);
  L2.displayAll();
  cout << endl;

  // 6.add before the 1st  (element 4) . 4 5 6 8 9
  cout << "Test " << c++ << endl;
  try{
    L2.addbeforeIth(9,12);}
  catch(llist::OutOfRange){
    cerr << "error (out of range)" << endl;
  }
  cout << endl;

  // 7.add before the 4th  (element 7) . 4 5 6 7 8 9
  cout << "Test " << c++ << endl;
  try{
    L2.addbeforeIth(0, 0);}
  catch(llist::OutOfRange){
    cerr << "error (out of range)" << endl;}
  cout << endl;

  // 8.add before the 7th  (element 10) . 4 5 6 7 8 9 10
  cout << "Test " << c++ << endl;
  L2.displayAll();
  cout << endl;

  // 9.add before the 9th  (element 12) . error (out of range)
  cout << "Test " << c++ << endl;
  L2.deleteIth(1,x);
  cout << "Removed" << x << endl;
  L2.displayAll();
  cout << endl;

  // 10.add before the 0th (element 0) . error (out of range)
  cout << "Test " << c++ << endl;
  try {
    L2.deleteIth(6, x);
  }
  catch (llist::OutOfRange) {
    cerr << " - Error, out of range." << endl;
  }
  cout << endl;

  // 11.displayAll
  cout << "Test " << c++ << endl;
  L2.deleteIth(3,x);
  L2.displayAll();
  cout << endl;

  // 12.delete Ith I==1 (indicate  the element removed) . 5 6 7 8 9 10
  cout << "Test " << c++ << endl;
  try{
    L2.deleteIth(5,x);
  }
  catch (llist::OutOfRange){
    cerr << " - Eroor, out of range." << endl;
  }
  cout << endl;

  // 13.delete Ith I==6 (indicate the element removed)  - 5 6 7 8 9
  cout << "Test " << c++ << endl;
  try{
    L2.deleteIth(0,x);
  }
  catch(llist::OutOfRange){
    cerr << " - Error, out of range." << endl;
  }
  cout << endl;

  // 14.delete Ith I==3 (indicate the element removed)  - 5 6 8 9
  cout << "Test " << c++ << endl;
  L2.displayAll();
  cout << endl;

  // 15.delete Ith I==5 . error (out of range)
  cout << "Test " << c++ << endl;
  while(L2.isEmpty()==false){
    L2.deleteRear(x);
  }
  
  

  // 16.delete Ith I==0 . error (out of range)
  cout << "Test " << c++ << endl;
  L2.displayAll();
  cout << endl;

  // 17.displayAll
  cout << "Test " << c++ << endl;
  try{
    L2.addbeforeIth(0,x);}
  catch(llist::OutOfRange){
    cerr << "Error, out of range" << endl;
  }
  cout << endl;

  // 18.delete from rear until it is empty (indicate the elements removed)
  cout << "Test " << c++ << endl;
  try
    {L2.deleteFront(x);}
  catch(llist::Underflow){
    cerr << "Caused an underflow" << endl;}
  cout << endl;

  // 19.displayAll
  cout << "Test " << c++ << endl;
  try{
    L2.deleteIth(2,x);}
  catch(llist::OutOfRange){
    cerr << "Error, out of range" << endl;}
  cout << endl;

  //20 delete rear
  cout << "Test " << c++ << endl;
  try{
    L2.deleteRear(x);}
  catch(llist::Underflow){
    cerr << "Error, out of range" << endl;}
  cout << endl;
} //end of case 2


// PURPOSE: This is the third case
void caseThree()
{
  cout << "Case 3: Copy Constructor and = -------" << endl;
  llist L1, L2; // two lists needed
  int x;        // local for removed element
  int counter = 1;  // step number
    
  //1. Create a 5 element list with  1,2,3,4,5 (L1)
  cout << "Step" << counter << endl; counter++;
  L1.addRear(1);
  L1.addRear(2);
  L1.addRear(3);
  L1.addRear(4);
  L1.addRear(5);
    
    
  //2. Simply pass L1  to a client function called CopyTest to
  //test your copy constructor.
  cout << "Step" << counter << endl; counter++;
  CopyTest(L1);
  cout << "-- After copytest --- " << endl;
    
  //3. Display L1 (this should still be a 5 element list)
  cout << counter << endl; counter++;
  L1.displayAll();
  cout << "-- Testing operator overloading ---" << endl;
    
  //4. Do L1 = L1;
  cout << "Step " << counter << endl; counter++;
  L1 = L1;
    
  //5. Display L1    (this should still be 1 2 3 4 5)
  cout << "Step " << counter << endl; counter++;
  L1.displayAll();
    
  //6. Create a 4 element list L2 with 7,8,9,10.
  cout << "Step " << counter << endl; counter++;
  L2.addRear(7);
  L2.addRear(8);
  L2.addRear(9);
  L2.addRear(10);
    
  //7. Display L2
  cout << "Step " << counter << endl; counter++;
  L2.displayAll();
    
  //8. Do L2 = L1;  (L2 becomes 5 elements 1,2,3,4,5)
  cout << "Step " << counter << endl; counter++;
  L2 = L1;
    
  //9. Display L2.
  cout << "Step " << counter << endl; counter++;
  L2.displayAll();
    
  //10. Remove a rear node from L1. (This should not affect L2).
  cout << "Step " << counter << endl; counter++;
  L1.deleteRear(x);
    
  //11. Display L1.   (L1 is 1,2,3,4)
  cout << "Step " << counter << endl; counter++;
  L1.displayAll();
    
  //12. Display L1 again. (4 elements just to make sure)
  cout << "Step " << counter << endl; counter++;
  L1.displayAll();
    
  //13. Display L2 again. (still 5 elements 1,2,3,4,5)
  cout << "Step " << counter << endl; counter++;
  L2.displayAll();
}

// PURPOSE: This program tests the implementation of linked lists.
  // ALGORITHM: Four case tests are split into four functions. A menu is used to select which case to test.
int main()
{
  cout << "//Alexander Sadeghipour" << endl;
  cout << "//Assignment: HW3P1" << endl;
  cout << "//Date: 3/4/2021" << endl << endl;

  int selection; // this will indicate what the user wants to do

  do {
    cout << " - 1 Case 1  " << endl;
    cout << " - 2 Case 2  " << endl;
    cout << " - 3 Case 3  " << endl;
    cout << " - 0 to quit " << endl;
    cout << endl;

    cout << "Select [?]: ";
    cin >> selection;

    // checks validity of input.
    while (cin.fail() || selection < 0 || selection > 4) {
      cin.clear();
      cin.ignore(25, '\n');

      cout << "Invalid selection, enter again: ";
      cin >> selection;
    }

    cout << "---------------------------------------" << endl << endl;

    //switch statement to switch to different cases.
    switch (selection) {
    case 1:
      caseOne();
      break;
    case 2:
      caseTwo();
      break;
    case 3:
      caseThree();
      break;
    }
  } while (selection != 0); //menu loop ends when user enters 0.

} // end of main