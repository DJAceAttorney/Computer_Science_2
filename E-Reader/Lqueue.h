/*****************************************
** File:    Lqueue.h
** Project: CMSC 202 Project 5, Spring 2019
** Author:  Fardeen Yaqub
** Date:    4/24/19
** Section: 18
** E-mail:  fyaqub1@umbc.edu
**
** This file contains the function prototypes and
** implementations for Lqueue. That includes the 
** getters and setters for the member variables, 
** constructor, destructor, copy constructor, 
** overloaded =, push function, pop function,display
** front which returns first data, function to check
** if empty, getter for size, swap, clear linked list,
** prints head and tail node, friend ostream, and 
** overloaded []
***********************************************/

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

template <class T>
class Node {
public:
  Node( const T& data ); //Node Constructor
  T& GetData(); //Node Data Getter
  void SetData( const T& data ); //Node Data Setter
  Node<T>* GetNext(); //Node m_next getter
  void SetNext( Node<T>* next ); //Node m_next setter
private:
  T m_data; //Holds templated data
  Node<T>* m_next; //Pointer to next node
};

template <class T>
Node<T>::Node( const T& data ) {
   m_data = data;
   m_next = nullptr;
}

template <class T>
T& Node<T>::GetData() {
   return m_data;
}

template <class T>
void Node<T>::SetData( const T& data ) {
   m_data = data;
}

template <class T>
Node<T>* Node<T>::GetNext() {
   return m_next;
}

template <class T>
void Node<T>::SetNext( Node<T>* next ) {
   m_next = next;
}

template <class T>
class Lqueue {
 public:
  // Name: Lqueue() (Linked List Queue) - Default Constructor
  // Desc: Used to build a new linked queue (as a linked list)
  // Preconditions: None
  // Postconditions: Creates a new lqueue where m_head and m_tail point to nullptr
  Lqueue();
  // Name: ~Lqueue() - Destructor
  // Desc: Used to destruct a Lqueue
  // Preconditions: There is an existing lqueue with at least one node
  // Postconditions: An lqueue is deallocated (including dynamically allocated nodes)
  //                 to have no memory leaks!
 ~Lqueue();
  // Name: Lqueue (Copy Constructor)
  // Preconditions: Creates a copy of existing LQueue
  //                Requires a Lqueue
  // Postconditions: Copy of existing Lqueue
  Lqueue(const Lqueue&);
  // Name: operator= (Overloaded Assignment Operator)
  // Preconditions: Copies an Lqueue into an existing Lqueue
  //                Requires a Lqueue
  // Postconditions: Copy of existing Lqueue
  Lqueue<T>& operator= (const Lqueue&);
  // Name: Push
  // Preconditions: Takes in data. Creates new node. 
  //                Requires a Lqueue
  // Postconditions: If the bool = false, adds to front else adds a new node to the
  //                 end of the lqueue.
  void Push(const T&, bool);
  // Name: Pop
  // Preconditions: Lqueue with at least one node. 
  // Postconditions: Removes first node in the lqueue, returns data from first node.
  T Pop();
  // Name: Display
  // Preconditions: Outputs the lqueue.
  // Postconditions: Displays the data in each node of lqueue
  void Display();
  // Name: Front
  // Preconditions: Requires a populated lqueue
  // Postconditions: Returns whatever data is in front 
  T Front();
  // Name: IsEmpty
  // Preconditions: Requires a lqueue
  // Postconditions: Returns if the lqueue is empty.
  bool IsEmpty();
  // Name: GetSize
  // Preconditions: Requires a lqueue
  // Postconditions: Returns m_size
  int GetSize();
  // Name: Swap(int)
  // Preconditions: Requires a lqueue
  // Postconditions: Swaps the nodes at the index with the node prior to it.
  void Swap(int);
  // Name: Clear
  // Preconditions: Requires a lqueue
  // Postconditions: Removes all nodes in a lqueue
  void Clear();
  // Name: TestHeadTail() (Optional test function)
  // Preconditions: Requires a lqueue
  // Postconditions: Returns the value of the head and the tail (used for main below)
  void TestHeadTail();
  // Name: operator<< (Overloaded << operator)
  // Preconditions: Requires a lqueue
  // Postconditions: Returns an ostream with the data from each node on different line
  template <class U>
  friend ostream& operator<<(ostream& output, const Lqueue<U>&);
  //Name: Overloaded [] operator
  //Precondition: Existing Lqueue
  //Postcondition: Returns object from Lqueue using []
  T& operator[] (int x);//Overloaded [] operator to pull data from Lqueue
private:
  Node <T> *m_head; //Node pointer for the head
  Node <T> *m_tail; //Node pointer for the tail
  int m_size; //Number of nodes in queue
};
//*****************************************************************
//Implement Lqueue here

// Lqueue
// creates a new lqueue where m_head and m_tail point to nullptr
template <class T>
Lqueue<T>::Lqueue(){
  m_head = nullptr;
  m_tail = nullptr;
  m_size =0;
}


// Lqueue(const Lqeue&)
// Creates a copy of existing LQueue Requires a Lqueue, Copy of existing Lqueue
template <class T>
Lqueue<T>::Lqueue(const Lqueue& source){

  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;

  //source head is not nullptr
  if(source.m_head != nullptr){

    Node <T> *temp = source.m_head;

    //while there is a node
    while(temp != nullptr){

      Push(temp -> GetData(), 1);

      temp = temp -> GetNext();
	
    }    
  }  
}

// operator=
// Takes in data. Creates new node.Requires a Lqueue, If the bool = false, adds to front else adds a new node to the end of the lqueue.
template <class T>
Lqueue<T>& Lqueue<T>::operator=(const Lqueue& source){

  //clears list
  if(&source != this){

    Clear();

    
    Node <T> *temp = source.m_head;

    //while there is a node
    while(temp != nullptr){
      
      Push(temp -> GetData(), 1);
      
      temp = temp -> GetNext();
      
    }
  }
  
  return *this;

}

// ~Lqueue
// There is an existing lqueue with at least one node, An lqueue is deallocated (including dynamically allocated nodes) to have no memory leaks!
template <class T>
Lqueue<T>::~Lqueue(){

  Clear();
}


// Push
// Takes in data. Creates new node. Requires a Lqueue, If the bool = false, adds to front else adds a new node to the end of the lqueue.
template <class T>
void Lqueue<T>::Push(const T& elem, bool check){  

  //head is null
  if(m_head == nullptr){
    
    Node <T> *temp = new Node<T>(elem);
    m_head = temp;

    m_tail = temp;
    m_size++;

    cout << GetSize() << endl;
  }

  //check is false
  else if(check ==false){

    Node <T> *temp = new Node<T>(elem);
    
    temp ->SetNext(m_head);
    m_head = temp;

    m_size++;

    cout << GetSize() << endl;
  }

  //check is true
  else if(check == true){
    
    Node <T> *newNode = new Node<T>(elem);

    m_tail ->SetNext(newNode);
    m_tail = newNode;
   
    m_size++;
    cout << GetSize() << endl;

    
  }

}

// Pop
// Lqueue with at least one node., Removes first node in the lqueue, return data from first node.
template <class T>
T Lqueue<T>::Pop(){

  Node <T> *removeNode = m_head;

  T data;

  //if the second node isn't nullptr
  if(m_head -> GetNext() != nullptr){


    m_head = removeNode ->GetNext();

    data = removeNode ->GetData();

    delete removeNode;
    removeNode = nullptr;
   
    
  }

  else{

    data = m_head -> GetData();
    
    delete removeNode;
    removeNode = nullptr;

    m_head = nullptr;
    m_tail = nullptr;

    
  }

  m_size--;
  return data;
  

}

// Display
// Outputs the Lqueue, Displays the data in each node of Lqueue
template <class T>
void Lqueue<T>::Display(){

  Node <T> *temp = m_head;

  //while there is a node
  while(temp != nullptr){
  
    cout << temp ->GetData() << endl;
    temp = temp -> GetNext();
    
  }

}


// Front
// Requires an Lqueue, Returns is the Lqueue is empty
template <class T>
T Lqueue<T>::Front(){

  return m_head ->GetData();

}


// IsEmpty
// Returns a Lqueue, Returns if the Lqueue is empty
template <class T>
bool Lqueue<T>::IsEmpty(){

  //linked list is empty
  if(GetSize() == 0){

    return true;
  }
}


// GetSize
// Requires a Lqueue, returns m_size
template <class T>
int Lqueue<T>::GetSize(){

  return m_size;
}

// Swap
// Requires a Lqueue, Swaps the nodes at the index with the node prior to it
template <class T>
void Lqueue<T>::Swap(int index){

  Node <T> *temp = m_head;
  Node <T> *prevStop = m_head;
  Node <T> *swap = m_head;
  
  
  //if node cannot be swapped
  if(index == 0 || m_head == nullptr){
    
    cout << "You can't swap any books" << endl;
    return;
  }

  //node to be swapped is at index 1
  else if(index == 1){

    temp = temp -> GetNext();
    m_head = temp;

    swap -> SetNext(temp ->GetNext());
    temp -> SetNext(swap);

    //last position equals size, set m_tail
    if(index +1 == GetSize()){

      m_tail = swap;
    }
  }

  else{

    int counter = 0;

    //while there is a node and not at last index
    while(temp != nullptr && counter != index ){
      
      prevStop = swap;
      
      swap = temp;
      
      temp = temp -> GetNext();
      
      counter++;
      
    }
    
    prevStop -> SetNext(temp);
    swap -> SetNext(temp ->GetNext());
    temp -> SetNext(swap);

    //last position equals size, set m_tail
    if(index+1 == GetSize()){
      
      m_tail = swap;
      
    }
    
  }
  
}

   
// Clear
// Requires a Lqueue, removes all nodes in a Lqueue
template <class T>
void Lqueue<T>::Clear(){
  Node <T> *clearList = m_head;
  Node <T> *prevStop;

  //linked list is empty
  if(m_head != nullptr){
    
    //while there are nodes
    while(clearList != nullptr){
      prevStop = clearList -> GetNext();
      
      delete clearList;
      clearList = prevStop;
    }

    clearList = nullptr;
    m_size =0;
  }

  //deallocates dynamically allocated memory
  while(clearList != nullptr){
    
    clearList = clearList-> GetNext();    
    delete prevStop;
    prevStop = clearList;
  }

  clearList = nullptr;
  prevStop = nullptr;
  m_head = nullptr;
  m_tail = nullptr;
  
  
  
}  

// TestHeadTail
// Requires a Lqueue, returns the value of the head and the tail
template <class T>
void Lqueue<T>::TestHeadTail(){

  //displays data from head and tail
  cout << m_head -> GetData() << endl;
  cout << m_tail -> GetData() << endl;
}


// operator<< (Overloaded << operator)
// requires a lqueue, returns an ostream with the data from each node on a different line
template <class U>
ostream &operator<<(ostream &output, const Lqueue<U> &node){
  
  Node <U> *temp = node.m_head;

  //head is nullptr
  if(temp ==nullptr){

    output << "The list is empty" << endl;
    return output;
  }

  //while there is a node
  while(temp != nullptr){

    output << temp ->GetData() << endl;
    temp = temp -> GetNext();
  }
  
  return output;
}

// Overloaded [] operator
// Existing Lqueue, returns object from Lqueue using []
template <class T>
T& Lqueue<T>:: operator[] (int x){

  int counter = 0;

  Node <T> *temp = m_head;

  //while there is a node and counter isn't equal to parameter
  while(temp != nullptr && counter != x){

    temp = temp -> GetNext();
    counter++;
  }

  return temp ->GetData(); 

  
}


//****************************************************************
// To test just Lqueue follow these instructions:
//   1.  mv Lqueue.h Lqueue.cpp
//   2.  Uncomment out int main below
//   3.  make Lqueue
//   4.  ./Lqueue (try valgrind too!)

/*
int main () {
  //Test 1 - Default Constructor and Push
  cout << "Test 1 - Default Constructor and Push Running" << endl;
  //Test Default Constructor
  Lqueue <int> newLQ1;
  
  //Push 4 nodes into Lqueue
  newLQ1.Push(10, 1);
  newLQ1.Push(11, 1);
  newLQ1.Push(12, 1);
  newLQ1.Push(13, 1);
  cout << endl;

  
  
  //Test 2 - Copy Constructor and Assignment Operator
  cout << "Test 2 - Copy Constructor and Assignment Operator Running" << endl;
  //Test Copy constructor
  Lqueue <int> newLQ2(newLQ1);
  //Test Overloaded Assignment Operator
  Lqueue <int> newLQ3;
  newLQ3 = newLQ1;
  cout << endl;
  
  
  //Test 3 - Test Display and Overloaded <<
  cout << "Test 3 - Display and Overloaded << Running" << endl;
  cout << "newLQ1" << endl;
  newLQ1.Display();
  cout << "newLQ2" << endl;
  newLQ2.Display();
  cout << "newLQ3" << endl;
  newLQ3.Display();
  cout << "newLQ1" << endl;
  cout << newLQ1;
  cout << "newLQ2" << endl;
  cout << newLQ2;
  cout << "newLQ3" << endl;
  cout << newLQ3;
  cout << endl;
  
  
  
  //Test 4 - Test Front and Pop
  cout << "Test 4 - Front and Pop Running" << endl;
  //Test Front()
  cout << "Testing Front - Output 10" << endl;
  cout << newLQ1.Front() << endl;
  //Test Pop with Display of Pop
  cout << "Popping one node and displaying it" << endl;
  cout << newLQ1.Pop() << endl;
  //Test Pop with Display of Pop
  cout << "Popping one node and displaying it" << endl;
  cout << newLQ1.Pop() << endl;
  cout << endl;

  
  //Test 5 - Test GetSize and Clear
  cout << "Test 5 - GetSize and Clear Running" << endl;
  //Test GetSize()
  cout << "Outputting the size" << endl;
  cout << newLQ1.GetSize() << endl;
  //Test Clear()
  cout << "Clearing all nodes" << endl;
  newLQ1.Clear();
  cout << endl;
  

  //Test 6 - Test Swap
  cout << "Test 6 - Swap Running" << endl;
  newLQ2.Swap(2);
  cout << "Swap 2 - Should display 10->12->11->13->END" << endl;
  newLQ2.Display();
  //Testing to make sure head and tail point at the correct node
  newLQ2.TestHeadTail();
  cout << "Should display head 10 and tail 13" << endl;
  cout << endl;  

  
  return 0;
}

*/

