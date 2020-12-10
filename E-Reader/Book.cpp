/*****************************************
** File:    Book.cpp
** Project: CMSC 202 Project 5, Spring 2019
** Author:  Fardeen Yaqub
** Date:    4/24/19
** Section: 18
** E-mail:  fyaqub1@umbc.edu
**
** This file contains the function implementations
** of the functions in Book.h. Those include mutators
** and setters for member variables, overloaded operator
** to print book details, and overloaded operator to compare
** books
***********************************************/


#include "Book.h"

// Book
// Creates a default book
Book::Book(){}

// Book - Overloaded constructor
// Requires title, author, rank and price (in dollars), Creates a book based on passed parameters
Book::Book(string title, string author, int rank, double price){

  setTitle(title);
  setAuthor(author);
  setRank(rank);
  setPrice(price);
  
}

// getTitle
// returns m_title
string Book::getTitle() const{
  return m_title;

}

// getAuthor
// returns m_author
string Book::getAuthor() const{
  return m_author;
}

// getRank
// returns m_rank
int Book::getRank() const{
  return m_rank;

}

// getPrice
// returns m_price
double Book::getPrice() const{
  return m_price;
}

// setTitle
// sets m_title
void Book::setTitle(string title){
  m_title = title;
}

// setAuthor
// sets m_author
void Book::setAuthor(string author){
  m_author = author;
}

// setRank
// sets m_rank
void Book::setRank(int rank){
  m_rank = rank;
}

// setPrice
// sets m_price
void Book::setPrice(double price){
  m_price = price;
}

// Overloaded <<
// all variables are set valid, returns an ostream with details of a book
ostream& operator<<(ostream &output, Book &book){
  
  output << setw(40) << book.getTitle();
  output << setw(30) << book.getAuthor();

  //formats decimals to 2 places
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  
  
  output << '\t' << "($" << book.getPrice() << ")" << endl;

  return output;
}

// Overloaded
// all variables are set valid, returns true if the lhs price is less than rhs price
bool operator< (Book const &lhrs, Book const &rhs){

  //if left hand side is less than right hand side
  if(lhrs < rhs){
    
    return true;
  }
  else{
    
    return false;

  }
}
