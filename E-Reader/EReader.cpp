/*****************************************
** File:    EReader.cpp
** Project: CMSC 202 Project 5, Spring 2019
** Author:  Fardeen Yaqub
** Date:    4/24/19
** Section: 18
** E-mail:  fyaqub1@umbc.edu
**
** This file contains the function implementations
** of the functions in EReader.h. Those include
** EReader constructor, overloaded constructor,
** destructor, function to load in file data,
** display Main menu and run program, Display books
** add a book, display read list, and sort read list
***********************************************/

#include "EReader.h"

//CONSTANTS
int MAX_BOOKS = 150; //Max books in file
int DISPLAY_BOOKS = 1; //displays all books
int ADD_BOOK = 2; //adds book to read list
int DISPLAY_LIST = 3; //displays read list
int SORT_LIST = 4; //sorts read list
int QUIT = 5; //quits program
int MIN_CHOICE = 1; //minimum book number

// EReader
// creates a new EReader
EReader::EReader(){

  LoadCatalog("proj5_books.txt");
}

// EReader - Overloaded operator
// Creates a new EReader and passes the book filename
EReader::EReader(string filename){

  LoadCatalog(filename);
  
  
}

// ~EReader
// deallocates dynamically allocated memory
EReader::~EReader(){

  int size = int(m_bookCatalog.size());

  //loops through vector
  for(int i =0; i < size; i++){
    
    //deletse book pointers
    delete m_bookCatalog.at(i);
    m_bookCatalog.at(i) = nullptr;
  }

}

// LoadCatalog
// Requires filename, loads the file into the m_bookCatalog
void EReader::LoadCatalog(string filename){
  
  Book *newBook;
  ifstream inputStream;

  string name;
  string author;
  string rank;
  string cost;

  int bookRank;
  double bookCost;  
  inputStream.open(filename);

  //reads in data from file
  for(int i =0; i < MAX_BOOKS; i++){

    //reads data into variables
    getline(inputStream,name,',');
    getline(inputStream,author,',');
    getline(inputStream,rank,',');
    getline(inputStream,cost,'\n');

    
    //makes rank and cost int and double
    bookRank = stoi(rank);
    bookCost = stod(cost);

    //makes new book
    newBook = new Book(name,author,bookRank,bookCost);

    //adds book to catalog
    m_bookCatalog.push_back(newBook);
   
  }

  inputStream.close();
  
}

// MainMenu
// Manages the application and the menu
void EReader::MainMenu(){

  int userChoice =0;
  
  cout << "Catalog populated with 150 books" << endl;

  cout << endl;
  
  //while the user doesn't want to quit
  while(userChoice != QUIT){
    cout << "What would you like to do?" << endl;
    cout << "1. Display All Books" << endl;
    cout << "2. Add Book to Readlist" << endl;
    cout << "3. Display ReadList" << endl;
    cout << "4. Sort Readlist by Price" << endl;
    cout << "5. Quit" << endl;
    
    cin >> userChoice;

    //validates input
    while(userChoice < DISPLAY_BOOKS || userChoice > QUIT){
      cout << "What would you like to do?" << endl;
      cout << "1. Display All Books" << endl;
      cout << "2. Add Book to Readlist" << endl;
      cout << "3. Display ReadList" << endl;
      cout << "4. Sort Readlist by Price" << endl;
      cout << "5. Quit" << endl;
      
      cin >> userChoice;
    }

    //user wants to display all books
    if(userChoice == DISPLAY_BOOKS){
      DisplayBooks();

      cout << endl;
    }

    //user wants to add book to read list
    else if(userChoice == ADD_BOOK){
      AddBook();

      cout << endl;
    }

    //user wants to display read list
    else if(userChoice == DISPLAY_LIST){
      DisplayReadlist();
      
    }

    //user wants to sort read list by price
    else if(userChoice == SORT_LIST){
      SortReadlist();

      cout << endl;
    }

    //user quits
    else{
      cout << "Thank you for using the UMBC E-Reader" << endl;
    }

  }
}


// DisplayBooks
// Displays all 150 books, lists all books (numbered)
void EReader::DisplayBooks(){

  //gets size of book catalog
  int size = int(m_bookCatalog.size());

  //loops through book catalog
  for(int i =0; i < size; i++){

    cout << i+1 << ". " << *m_bookCatalog.at(i) << endl;

  }

}

// AddBook
// m_bookCatalog is populated, Displays the current list and adds a book to the m_readlist
void EReader::AddBook(){

  int userChoice =0;

  cout << "Choose the book you would like to add to your reading list." << endl;
  DisplayBooks();

  cout << "Enter the number of the book you would like to add" << endl;
  cin >> userChoice;

  //validates user input
  while(userChoice < MIN_CHOICE || userChoice > MAX_BOOKS){

    cout << "Enter the number of the book you would like to add" << endl;
    cin >> userChoice;
  }

  //adds book to read list
  m_readList.Push(*m_bookCatalog.at(userChoice-1),true);

}


// DisplayReadlist
// displays the readlist
void EReader::DisplayReadlist(){

  //gets size of read list
  int size = m_readList.GetSize();

  //read list is empty
  if(size == 0){
    cout << "You have no books in your read list" << endl;
    cout << endl;
    
  }
  else{
  
    //loops through read list
    for(int i =0; i < size; i++){
    
      cout << i+1 << ". " << m_readList[i] << endl;

    }
  }
  
}


// SortReadlist
// Requires Readlist, Uses the overloaded < operator in Book to sort the prices from high to low in the m_readlist
void EReader::SortReadlist(){

  int counter = 1;
  int size = int(m_readList.GetSize());

  if(size ==0 || size == 1){
    m_readList.Swap(0);
    
    return;
  }
  
  //loops through reading list
  while(counter < size){
    
    //if the book's price is not less than the book prior to it and books prices aren't the same
    if(!(m_readList[counter].getPrice() < m_readList[counter-1].getPrice()) && m_readList[counter].getPrice() != m_readList[counter-1].getPrice()){

      //swaps books
      m_readList.Swap(counter);
      
      counter =1;
    }
    else{
      
      counter++;
    }
  }

  cout << "Done Sorting List" << endl;
  
}

