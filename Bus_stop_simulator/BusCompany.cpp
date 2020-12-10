/*****************************************
** File:    BusCompany.cpp
** Project: CMSC 202 Project 3, Spring 2019
** Author:  Fardeen Yaqub
** Date:    3/27/19
** Section: 18
** E-mail:  fyaqub1@umbc.edu
**
** This file contains the function implementations
** of the functions in BusCompany.h. These functions
** include the constructor and overloaded constructor
** BusCompany, destructor Buscompany, read in the text
** file, display the menu, display routes, optimize
** routes, and display route data
***********************************************/



#include "BusCompany.h"

//Constants
const int DISPLAY_ROUTES = 1; //display routes
const int EARNINGS_EXPENSES =2; //displays earnings vs expenses by route
const int OPTIMIZE_ROUTE = 3; //optimizes the route
const int EXIT = 4; //exits the program



// BusCompany
// makes a new bus company
BusCompany::BusCompany(){
    
  
}

// BusCompany(string)
// file name included, new bus company is made and routes are made from file
BusCompany::BusCompany(string fileName){

  ReadFile(fileName);
  MainMenu();

}

// ~BusComapny
// all linked lists are destroyed
BusCompany::~BusCompany(){

  int routeSize = m_routes.size();
  
  //traverses linked list
  for(int i =0; i < routeSize; i++){

    //deletes routes in vector
    delete m_routes.at(i);
 
    m_routes.at(i) =nullptr;

  }

  
  delete m_newRoute; 

  m_newRoute = nullptr;
  
}

// ReadFile
// valid file name of routes, creates a route
void BusCompany::ReadFile(string fileName){

  ifstream inputStream;

  string name;
  int location;
  int riders;
  double cost;

  int counter = 0;
    
  m_newRoute = new Route();
  
  inputStream.open(fileName);
  
  while(getline(inputStream,name,',')){
    

    //if the route isn't over
    if(name != "\nEnd Route"){     


      //removes new line from input
      if(counter >0){
	name = name.substr(1);

      }

      inputStream >> location >> riders >> cost;

      
      //inserts name, location, riders, and cost to route
      m_newRoute -> InsertAt(name, location, riders, cost);
      
    }

    else{

      //adds route to vector
      m_routes.push_back(m_newRoute);

      
      m_newRoute = new Route();

    }

    counter++;
  }  
   
  inputStream.close();

  
}

// MainMenu
// displays main menu
void BusCompany::MainMenu(){

  int userChoice = 0;

  //gets number of routes
  int numRoutes = m_routes.size();


  cout << endl;
  
  //traverses through number of routes
  for(int i =0; i < numRoutes; i++){
    
    cout << "Route " << i+1 << " loaded with " << m_routes.at(i) ->GetSize() << " stops" << endl;

  }

  
  cout << "************************************" << endl;
  
  cout << "Welcome to UMBC Transit Simulator" << endl;

  //while user doesn't quit
  while(userChoice != EXIT){
    cout << "What would you like to do?: " << endl;
    cout << "1. Display Routes" << endl;
    cout << "2. Display Earnings vs Expenses by Route" << endl;
    cout << "3. Optimize Route" << endl;
    cout << "4. Exit" << endl;
    cin >> userChoice;


    //validates user input
    while(userChoice < DISPLAY_ROUTES || userChoice > EXIT){

      cout << "1. Display Routes" << endl;
      cout << "2. Display Earnings vs Expenses by Route" << endl;
      cout << "3. Optimize Route" << endl;
      cout << "4. Exit" << endl;
      cin >> userChoice;

    }

    //user wants to display route
    if(userChoice == DISPLAY_ROUTES){

      cout << endl;
      
      DisplayRoutes();
    }

    //user wants to Display Earnings vs Expenses by Route
    else if(userChoice == EARNINGS_EXPENSES){

      cout << endl;
      DisplayRouteData();

    }

    //user wants to optimize a route
    else if(userChoice == OPTIMIZE_ROUTE){
      
      OptimizeRoute();
    
    }

    //user wants to quit
    else if(userChoice == EXIT){

      cout <<"GOOD BYE " << endl;
    
    }
    
    
  }

}

// DisplayRoutes
// route is in m_routes, displays route(s) in m_routes
void BusCompany::DisplayRoutes(){

  int size = m_routes.size();
  
  //traverses linked list
  for(int i =0; i < size; i++){
    
    cout << "*** " <<"ROUTE " << i+1 << " ***" << endl;
    
    //calls the overloaded function
    cout << *(m_routes.at(i)) << endl;
  }
  
}


// OptimizeRoute
// had route, removes all stops that lose money
void BusCompany::OptimizeRoute(){ 

  int routeNum;
  int totalRoutes = m_routes.size();


  //if there is more than one route
  if(totalRoutes !=1){
  
    cout << "Which route would you like to optimize" << endl;
    cin >> routeNum;

    //validates user input
    while(routeNum <= 0 || routeNum > totalRoutes){

      cout << "Which route would you like to optimize" << endl;
      cin >> routeNum;
    }
  }

  else{

    routeNum =1;
  }
  
  //optimizes the first route
  m_routes.at(routeNum-1) -> OptimizeRoute(RIDER_FARE);
    
  }
  
// DisplayRouteData
// had route, displays stop data in route
void BusCompany::DisplayRouteData(){

  int size = m_routes.size();

  
  //traverses linked link to display data
  for(int i =0; i < size; i++){
    
    cout << "*** "<< "ROUTE " << i+1 << " ***"<< endl;
    m_routes.at(i) -> DisplayStopData(RIDER_FARE);

    cout << endl;
  }


  cout << endl;
  
}
