/*****************************************
** File:    Alchemist.cpp
** Project: CMSC 202 Project 2, Spring 2019
** Author:  Fardeen Yaqub
** Date:    3/8/2019
** Section: 18
** E-mail:  fyaqub1@umbc.edu 
**
** This file contains the function implementations 
** of the functions in Alchemist.h. The functions 
** include the constructor for Alchemist, the 
** overloading Alchemist that builds 
** a new Alchemist, the getter and setter for 
** the alchemist's name,  display elements,
** get number of elements, check if Alchemist has an 
** element, add element to Alchemist's element list,
** get an element at an index, add attempt, get
** number of attempts, add repeats, and get number
** of retreats.
**
***********************************************/


#include "Alchemist.h"

// Alchemist
// Given default value and loads in air earth fire and water, makes new alchemist
Alchemist::Alchemist(){

  Element myElement;

  //Starting elements
  myElement.m_name = "Air";
  AddElement(myElement);

  myElement.m_name = "Earth";
  AddElement(myElement);

  myElement.m_name = "Fire";
  AddElement(myElement);

  myElement.m_name = "Water";
  AddElement(myElement);
  
}


// Alchemist(name)
// given name, makes new alchemist
Alchemist::Alchemist(string name){
  SetName(name);
}


// GetName
// alchemist exists, returns name of element 
string Alchemist::GetName(){
  return m_myName;
}


// SetName
// Alchemist exists, sets name of alchemist
void Alchemist::SetName(string name){
  m_myName = name;
}


// DisplayElements
// Alchemist exists
void Alchemist::DisplayElements(){

  int counter = 0;

  //displays Alchemist's elements
  while(m_myElements[counter].m_name != ""){
    cout << counter+1 << "." << m_myElements[counter].m_name << endl;
    counter ++;
  }
  
}


// GetNumElements
// Alchemist exists
int Alchemist::GetNumElements(){
  return m_numElements;
}


// CheckElement
// Alchemist has elements, returns true or false if alchemist has element
bool Alchemist::CheckElement(Element myElement){

  //loops through array to see if element is in array
  for(int i =0; i < PROJ2_SIZE; i++){

    if(myElement.m_name == m_myElements[i].m_name){
      return true;
    }
  }

  return false;
}


// AddElement
// Alchemist exists and new element not known, adds element to m_myElements
void Alchemist::AddElement(Element myElement){

  //loops through the array to find an empty index to put element
  for(int i =0; i < PROJ2_SIZE; i++){

    if(m_myElements[i].m_name == ""){

      m_myElements[i].m_name = myElement.m_name;
      i = PROJ2_SIZE;

      m_numElements ++;
    }
  }
}


// GetElement
// Alchemist has elements, return element at index
Element Alchemist::GetElement(int index){

  return m_myElements[index];
  
}


// Name: AddAttempt
// alchemist exists, increments every time a merge is attempted
void Alchemist::AddAttempt(){
  m_attempts++;
}


// GetAttempts
// alchemist exists, returns number of attempts
int Alchemist::GetAttempts(){
  return m_attempts;
}


// AddRepeat
// Alchemist attempts a merge, increment when a merge yields an already found element
void Alchemist::AddRepeat(){
  m_repeats++;
}


// GetRepeats
// Alchemist exists, returns number of repeats
int Alchemist::GetRepeats(){
  return m_repeats;
}
