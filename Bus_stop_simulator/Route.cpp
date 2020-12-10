/*****************************************
** File:    Route.cpp
** Project: CMSC 202 Project 3, Spring 2019
** Author:  Fardeen Yaqub
** Date:    3/25/19
** Section: 18
** E-mail:  fyaqub1@umbc.edu 
**
** This file contains the function implementations
** of the functions in Route.h. These functions include
** the constructor Route, destructor ~Route, function to
** insert stops into linked list, display route(s),
** get route earnings, get route expenses, clearing
** the linked list, optimize the route(s), remove
** stops, display data of stops, get the size of
** the linked list, and the overloaded function
** that prints the routes
***********************************************/

#include "Route.h"

// Route
// Creates a new bus route
Route::Route(){

  m_start = NULL;
  m_size = 0;
 
   
}

// ~Route
// route with stop(s) exist, route deallocated
Route::~Route(){
  
  Clear();
  
}

// InsertAt()
// route exists with stop, puts name,locatio,riders,and costs into stop
void Route::InsertAt(string name, int location, int riders, double costs){

  //creates a new stop with parameters
  Stop *newStop = new Stop(name,location,riders,costs);

  m_size++;
  
  //Inserts at beginning
  if(IsEmpty() == true){
  
    m_start = newStop;
    
    
    return;
  }

  
  Stop *nextStop = m_start;
  Stop *prevStop = NULL;

  //while the stop isn't null
  while(nextStop != NULL){

    //checks to see if stop should be entered 
    if(newStop -> m_location < nextStop -> m_location){

      //if previous stop is null
      if(prevStop == NULL){

	m_start = newStop;
      }
      else{

	prevStop -> m_next = newStop;
      }

      //moves to next stop
      newStop -> m_next = nextStop;
      
      return;
      
    }

    //can't enter so move stop to next route
    prevStop = nextStop;
    nextStop = nextStop ->m_next;
    
    
  }

  //changes the end
  prevStop -> m_next = newStop;
  
}

// DisplayRoute
// Outputs route, returns numbered list of all stops in route
void Route::DisplayRoute(){

  Stop *temp = m_start;
  
  //traverses linked list
  for(int i =0; i < m_size; i++){
    
    cout << "Stop " << i+1 << " - " << temp -> m_name << "(" << temp -> m_location << ")" << endl;
    
    //moves to next node
    temp=temp->m_next;
  }

  cout << "END" << endl;

}

// IsEmpty
// route exists, returns if route is empty
bool Route::IsEmpty(){

  //first stop is empty
  if(m_start == NULL){
    
    return true;
  }

  else{
    
    return false;
  }
}

// GetRouteEarnings
// bus route exists, sums total earnings per month
double Route::GetRouteEarnings(double riderFare){

  Stop *earnings = m_start;
  double routeEarnings = 0;

  //iterates through linked list
  for(int i = 0; i < m_size; i++){

    //adds earnings
    routeEarnings += ((earnings-> m_riders) * riderFare);
    
    //moves to next stop
    earnings=earnings->m_next;
   
  }

  
  return routeEarnings;

}

// GetRouteExpenses
// bus route exists, sums total costs per station per month
double Route::GetRouteExpenses(){
  
  Stop *expense = m_start;
  double totalCost = 0;

  //itertates through linked list
  for(int i = 0; i < m_size; i++){

    //adds expenses
    totalCost += expense -> m_cost;

    //moves to next stop
    expense = expense-> m_next;

  }


  return totalCost;
}

// route exists, removes all stops
void Route::Clear(){

  Stop *clearList = m_start;
  Stop *prevStop;

  if(m_size != 0){
  
    //while there are still Stops
    while(clearList != NULL){
  
      prevStop = clearList -> m_next;
  
      delete clearList;
    
      clearList = prevStop;
    }
  
    clearList = nullptr;
  
    m_size = 0;
  }
  
  //deallocates dynamically added memory
  while(clearList != nullptr){

    clearList = clearList->m_next;

    delete prevStop;

    prevStop = clearList;
    
    m_size--;
  }
  clearList = nullptr;
  prevStop = nullptr;
  m_start = nullptr;

  

}

// OptimizeRoute
// Bus route exists, removes stop where (fare *riders) < monthly cost for station
void Route::OptimizeRoute(double rideFare){

  Stop *route = m_start;
  double earning;
  

  //itertates through linked list
  for(int i = 0; i < m_size; i++){

    //earnings of stop
    earning = rideFare * route ->m_riders;

    //if earnings is less than expense of stop
    if(earning < route -> m_cost){

      //removes stop
      RemoveStop(route -> m_location);

    }
    
    //moves to next stop
    route = route-> m_next;

  }

}

// RemoveStop
// Bus route exists, removes specific stop
void Route::RemoveStop(int stopLocation){
  
  Stop *removeStop = m_start;
  Stop *prevStop = NULL;

 
  
  //iterates through linked list
  for(int i = 0; i < m_size; i++){
    
    //if the stop is the one to be removed
    if(removeStop -> m_location == stopLocation){
      
      //removes first stop
      if(stopLocation == 1){

	prevStop = removeStop -> m_next;
	
	delete removeStop;
	
	removeStop = nullptr;
	
	m_size--;

	m_start = m_start -> m_next;

	return;
	
      }
      
      prevStop ->m_next = removeStop ->m_next;        

      //gets rid of removeStop
      delete removeStop;
      removeStop = nullptr;
      
      m_size--;
      
      return;
      
    }

    else{

      prevStop = removeStop;
      
      //moves to next stop
      removeStop = removeStop -> m_next;
      
    }
      
  }
  
  
}

// DisplayStopData
// bus route passed riderFare
void Route::DisplayStopData(double riderFare){


  //formats decimals to 2 places
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  
  Stop *newStop = m_start;
  
  int size = GetSize();
 

  //prints total earnings
  cout <<"Earnings: " << GetRouteEarnings(riderFare) << endl;

  //prints total expenses
  cout <<"Expenses: " << GetRouteExpenses() << endl;

  //loops through linked list
  for(int i =0; i < size; i++){
        
    double stopEar = newStop ->m_riders * riderFare;
    double stopExp = newStop ->m_cost;
    double stopTotal = stopEar - stopExp;

    
    //name
    cout << newStop -> m_name << endl;
    
    //earnings
    cout << "  Earnings: " << newStop ->m_riders << "@" << riderFare << " = $" << stopEar << endl;
    
    //Expenses
    cout << "  Expenses: $" << stopExp << endl;
    
    //Total (Earnings - Expenses)
    cout << "  Total: $" << stopTotal << endl;

    //Moves to next stop
    newStop = newStop ->m_next;


  }
}

// GetSize
// bus stop route exists, returns int number of stops in route 
int Route::GetSize(){
 
  return m_size;
}

// operator<<
// route exists, returns route with stops
ostream &operator<<(ostream &output, Route &myRoute){

  Stop *temp = myRoute.m_start;

  int size = myRoute.GetSize();
  
  //traverses linked list
  for(int i =0; i < size; i++){

    output << "Stop " << i+1 << " - ";

    output << temp -> m_name << "(" << temp->m_location << ")" << endl;

    //moves to next stop
    temp = temp ->m_next;
  }

  output << "END" << endl;
  
  return output;
}
