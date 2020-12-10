/*****************************************
** File:    Game.cpp
** Project: CMSC 202 Project 2, Spring 2019
** Author:  Fardeen Yaqub
** Date:    3/8/2019
** Section: 18
** E-mail:  fyaqub1@.umbc.edu 
** This file contains the function implementations
** of the functions in Game.h. The functions 
** include the constructor for Game, load in 
** elements from textfile, start the game, display
** elements, prompt main menu, combine elements,
** request element to validate, search recipe,
** and calculate and display the Alchemist's score
**
***********************************************/


#include "Game.h"

// Game
// loads elements into m_elements and gets user name
Game::Game(){

  string playerName;

  //loads elements for game
  LoadElements();

  //prints game title
  GameTitle();

  cout << PROJ2_SIZE << " elements loaded." << endl;

  cout << "What is the name of the Alchemist?" << endl;
  getline(cin,playerName);

  //stores player's name
  m_myAlchemist.SetName(playerName);




}


// LoadElements
// file with valid element data, m_element is populated with element structs
void Game::LoadElements(){

  ifstream inputStream;
  string tempVar;

  inputStream.open(PROJ2_DATA);

  //loads textfile into array
  for(int i = 0; i < PROJ2_SIZE; i++){
    
    getline(inputStream,m_elements[i].m_name,',');
    getline(inputStream,m_elements[i].m_element1,',');
    getline(inputStream,m_elements[i].m_element2,'\n');
    
  }
  
  inputStream.close();
  
}


// Name: StartGame()
// player is in game, keeps checking to see if player quits
void Game::StartGame(){

  int userChoice;
  
  //play game while user does not want to quit
  while(userChoice != MENU_QUIT){
    
    //gets user choice for menu options
    userChoice = MainMenu();

    //user chooses to Display elements
    if(userChoice == MENU_DISPLAY){
      DisplayElements();
    }
      
    //user chooses to combine elements
    else if(userChoice == MENU_COMBINE){

      CombineElements();

    }
    //user chooses to see score
    else if(userChoice == MENU_SCORE){

      CalcScore();
      
    }
    //user chooses to quit
    else if(userChoice == MENU_QUIT){

      cout << "Thanks for playing the Alchemist" << endl;
    }
    

  }
}


// DisplayMyElements
// player has elements, displays numbered list of elements
void Game::DisplayElements(){


  m_myAlchemist.DisplayElements();
}


// MainMenu
// player has an alchemist, returns number including exit
int Game::MainMenu(){
  
  int userChoice;

  cout << endl;

  cout << "What would you like to do?" << endl;
  
  cout << "1. Display the Alchemist's Elements" << endl;
  cout << "2. Attempts to Merge Elements" << endl;
  cout << "3. See Score" << endl;
  cout << "4. Quit" << endl;

  cin >> userChoice;
  cout << endl;
  
  while(userChoice < MENU_DISPLAY || userChoice > MENU_QUIT){

    cout << "1. Display the Alchemist's Elements" << endl;
    cout << "2. Attempts to Merge Elements" << endl;
    cout << "3. See Score" << endl;
    cout << "4. Quit" << endl;
    
    cin >> userChoice;
    cout << endl;
    
  }
  
  
  return userChoice;

  
}


// CombineElements
// Alchemist is populated with elements, may add element to list of elements
void Game::CombineElements(){

  int choiceOne;
  int choiceTwo;
  int elementIndex;

  string elementOne;
  string elementTwo;
  string elementName;

  Element name;
  

  //gets first element
  cout << "Which elements would you like to merge?" << endl;
  cout << "To list known elements enter " << LIST_ELEMENTS << endl;

  cin >> choiceOne;
  
  //Validates user choice or displays list of elements
  RequestElement(choiceOne);

  //gets element at index
  name = m_myAlchemist.GetElement(choiceOne);

  elementOne = name.m_name;

  
  //gets second element
  cout << endl;
  cout << "Which elements would you like to merge?" << endl;
  cout << "To list known elements enter " << LIST_ELEMENTS << endl;

  cin >> choiceTwo;
 
  //Validates user choice or displays list of elements
  RequestElement(choiceTwo);

  //gets element at index
  name = m_myAlchemist.GetElement(choiceTwo);

  elementTwo = name.m_name;

  //gets index of element with recipe chosen by user
  elementIndex = SearchRecipes(elementOne,elementTwo);

  if(elementIndex != NO_ELEMENT){
    
    elementName = m_elements[elementIndex].m_name;

    //puts element at index into element object
    name.m_name = elementName;

    //Checks if element has already been made
    if(m_myAlchemist.CheckElement(name) == 0){
      m_myAlchemist.AddElement(name);

      cout << endl;
      
      cout << elementOne << " combined with " << elementTwo << " to make " << elementName << "!" << endl;

      cout << "The Alchemist now knows " << elementName << "." << endl;
      
      m_myAlchemist.AddAttempt();
      
    //Player repeats element they already made
    }else{

      cout << "You already made " << elementName << endl;

      m_myAlchemist.AddAttempt();

      m_myAlchemist.AddRepeat();
      
    }

    
  //Combination fails  
  }else{
    
    cout << "Nothing happened when you tried to combine " << elementOne << " and " << elementTwo << endl;

    m_myAlchemist.AddAttempt();
  }
}

  
// RequestElement
// Alchemist has elements to merge, validates elements
void Game::RequestElement(int &choice){

  cout << endl;
  
   
  int numElements = m_myAlchemist.GetNumElements();
  
  //Validates choice
  while(choice <= MIN_ELEMENTS || choice == LIST_ELEMENTS || choice > numElements){

    //user entered an invalid choice
    if((choice <= MIN_ELEMENTS && choice != LIST_ELEMENTS) || choice > numElements){ 

      
      cout << "Which elements would you like to merge?" << endl;
      cout << "To list known elements enter " << LIST_ELEMENTS << endl;
      
      cin >> choice;
            
    }
      
  
    
    //user wants to view list of elements
    else if(choice == LIST_ELEMENTS){

      //Displays elements the user has
      DisplayElements();
      cout << endl;

      cout << "Which elements would you like to merge?" << endl;
      cout << "To list known elements enter " << LIST_ELEMENTS << endl;
      
      cin >> choice;
      
      
    }
  }
  
  
  //gets correct index for array
  choice -=1;

}
 

// SearchRecipes
// m_elements is populated, returns index of matching recipe
int Game::SearchRecipes(string element1, string element2){

  int elementIndex;

  
  //gets recipe index
  for(int i = 0; i < PROJ2_SIZE; i++){


    if(element1 == m_elements[i].m_element1 && element2 == m_elements[i].m_element2){
      elementIndex = i;

      return elementIndex;
      
	}
    else if(element2 == m_elements[i].m_element1 && element1 == m_elements[i].m_element2){
      elementIndex = i;
      
      return elementIndex;
    
    }
  }


  //Return this when combination is not possible
  return NO_ELEMENT;

}


// CalcScore
// alchemist is populated with elements
void Game::CalcScore(){

  //formats decimals to 2 places
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);


  cout << "***The Alchemist***" << endl;

  cout << "The Great Alchemist " << m_myAlchemist.GetName() << endl;
  
  cout << "The Alchemist has tried to combine " << m_myAlchemist.GetAttempts() << " elements" <<  endl;
  
  cout << "The Alchemist has repeated attempts " << m_myAlchemist.GetRepeats() << " times" << endl;
  
  cout << "The Alchemist found " << m_myAlchemist.GetNumElements() << " out of " << PROJ2_SIZE << " elements" << endl;

  double percentElements = (double(m_myAlchemist.GetNumElements())/PROJ2_SIZE)*100;

  cout << "You have completed " << percentElements << "% of the elements" << endl;

  
}

