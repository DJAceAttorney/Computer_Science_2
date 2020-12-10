/*****************************************
** File:    ASCII.cpp
** Project: CMSC 202 Project 1, Spring 2019
** Author:  Fardeen Yaqub
** Date:    2/15/19
** Section: 11
** E-mail:  fyaqubl.umbc.edu 
**
** This program allows the user to load a textfile with ASCII 
** characters and displays them on a 75x75 grid. The user
** can also choose to make their own art on the grid.
** When art is on the grid, the user can choose to 
** rotate the art and invert the art horizontally
** or vertically.
**
***********************************************/

#include <iostream>
#include <fstream>
using namespace std;


const int MAX_SIZE = 75;  //Maximum row and column length
const int MAX_CHARACTERS = MAX_SIZE * MAX_SIZE;  //Maximum characters in 2d array


//Prototypes

//-------------------------------------------------------
// Name: loadArt
// PreCondition:  no pre condition
// PostCondition: Loads 2d array with ACSII characters from text file
//---------------------------------------------------------
int loadArt(char[][MAX_SIZE]);


//-------------------------------------------------------
// Name: makeArt
// PreCondition:  no pre condition
// PostCondition: adds character user chose to 2d array
//---------------------------------------------------------
int makeArt(char[][MAX_SIZE]);


//-------------------------------------------------------
// Name: displayArt
// PreCondition:  art is currently loaded to 2d array
// PostCondition: 2d array of art is displayed
//---------------------------------------------------------
int displayArt(char[][MAX_SIZE]);


//-------------------------------------------------------
// Name: rotateArt
// PreCondition:  art is currently loaded to 2d array
// PostCondition: art in 2d array is rotated clockwise 
//---------------------------------------------------------
int rotateArt(char[][MAX_SIZE]);


//-------------------------------------------------------
// Name: invertHorizontal
// PreCondition:  art is currently loaded to 2d array
// PostCondition: art is inverted horizontally
//---------------------------------------------------------
int invertHorizontal(char[][MAX_SIZE]);


//-------------------------------------------------------
// Name: invertVertical
// PreCondition:  Art is currently loaded to 2d array
// PostCondition: art is inverted vertically
//---------------------------------------------------------
int invertVertical(char[][MAX_SIZE]);


int main(){
  
  int userInput;
  
  char myArray[MAX_SIZE][MAX_SIZE];  //2d array that holds ASCII art

   //Creates blank spaces in the 2d Array
   for(int i =0; i < MAX_SIZE; i++){
     for(int j =0 ; j < MAX_SIZE; j++){

       myArray[i][j] = ' ';

     }
   }


  do{
    
    //Menu options
    cout << "What would you like to do?" << endl;
    cout << "1. Load ASCII Art from File" << endl;
    cout << "2. Create ACSII Art Manually" << endl;
    cout << "3. Display Art" << endl;
    cout << "4. Rotate Art" << endl;
    cout << "5. Invert Art" << endl;
    cout << "6. Exit" << endl;

    cin >> userInput;
    cout << endl;
  
    //User Input Validation
    while(userInput < 1 || userInput > 6){
      cout << "What would you like to do?" << endl;
      cout << "1. Load ASCII Art from File" << endl;
      cout << "2. Create ACSII Art Manually" << endl;
      cout << "3. Display Art" << endl;
      cout << "4. Rotate Art" << endl;
      cout << "5. Invert Art" << endl;
      cout << "6. Exit" << endl;

      cin >> userInput;
      cout << endl;
      
    }
  
    switch(userInput){

    //user picks to load art
    case 1:

      loadArt(myArray);

      break;

    //user picks to make art
    case 2:

      makeArt(myArray);
      
      break;

    //user picks to display art
    case 3:

      displayArt(myArray);
      
      break;

    //user chooses to rotate art
    case 4:
     
      rotateArt(myArray);
      break;

    //user chooses to invert art
    case 5:

      cout << "Would you like to rotate it vertically or horizontally?" << endl;
      cout << "1. Vertical" << endl;
      cout << "2. Horizontal" << endl;
      cin >> userInput;
      cout << endl;
      
      //Validates input
      while(userInput < 1 || userInput > 2){
	cout << "Would you like to rotate it vertically or horizontally?" << endl;
	cout << "1. Vertical" << endl;
	cout << "2. Horizontal" << endl;
	cin >> userInput;
	cout << endl;

	
      }

      //User chooses to invert Vertically
      if(userInput == 1){

	invertVertical(myArray);

      }

      //User chooses to invert Horizontally
      else {

	invertHorizontal(myArray);

      }
      
      break;

    //user chooses to exit program
    case 6:
      
      cout << "Thank you for using the ASCII Art Tool" << endl;
      break;

    }

  }while(userInput != 6);
  
  
  return 0;

}


// loadArt
// art is loaded to 2d array
int loadArt(char myArray[][MAX_SIZE]){

  ifstream inputStream;
  int xPOS;
  int yPOS;
  char symbol;
  char inputFile[MAX_SIZE];

  
  cout << "What is the name of the data file to import?" << endl;
 
  if (cin.peek() == '\n')
    cin.ignore();

  cin.getline(inputFile,sizeof(inputFile));
  
  cout << endl;

  //Opens file
  inputStream.open(inputFile);
 

  //Creates blank spaces in the 2d Array
    for(int i =0; i < MAX_SIZE; i++){
      for(int j =0 ; j < MAX_SIZE; j++){

	myArray[i][j] = ' ';
      
      }
    }
  
 

    //Checks if user opened a valid file
    if(inputStream.is_open()){

      //Adds ASCII characters to the 2d array
       for(int i =0; i < MAX_CHARACTERS; i++){
      
	inputStream >> xPOS >> yPOS >> symbol;

	myArray[xPOS][yPOS] = symbol;

      }

    //User didn't enter a valid file name
    }else{

      cout << "Unable to open file" << endl;

      inputStream.close();

      return 0;
    }
      
    
    cout << "Done" << endl;
    cout << endl;
    
  inputStream.close();
   
  return 0;
 
  }


// makeArt
// art is added to 2d array
int makeArt(char myArray[][MAX_SIZE]){

  int xVal;
  int yVal;
  char userSymbol;

  
  cout << "This will modify the current art" << endl;
  cout << "Enter the x coordinate between 0 and 75" << endl;
  cin >> xVal;

  //Validates x value entered by user
  while(xVal < 0 || xVal > 75){
    cout << "Enter the x coordinate between 0 and 75" << endl;
    cin >> xVal;
    
  }

  cout << "Enter the y coordinate between 0 and 75" << endl;
  cin >> yVal;

  //Validates y value entered by user
  while(yVal < 0 || yVal > 75){
    cout << "Enter the y coordinate between 0 and 75" << endl;
    cin >> yVal;

  }

  cout << "Enter the character for that location:" << endl;
  cin >> userSymbol;
 
  //Adds symbol to coordinates user chose
  myArray[xVal][yVal] = userSymbol;


  return 0;
  
}


// displayArt
// art is in 2d array, art is displayed
int displayArt(char myArray[][MAX_SIZE]){


  //prints out the 2d Array
  for(int i = 0; i < MAX_SIZE; i++){
    for(int j = 0; j < MAX_SIZE; j++){

      cout << myArray[i][j];

    }
    cout << endl;

  }


  return 0;

}


// rotateArt
// art is in 2d array, art is rotated clockwise 
int rotateArt(char myArray[][MAX_SIZE]){
  
  char tempArray[MAX_SIZE][MAX_SIZE];

  //sets value of tempArray to blank chars
  for(int i = 0; i < MAX_SIZE; i++){
    for(int j = 0; j < MAX_SIZE; j++){

      tempArray[i][j] = ' ';

    }
  }


  //rotates values of original array into tempArray
  for(int i = 0; i < MAX_SIZE; i++){
    for(int j = 0; j < MAX_SIZE; j++){

      tempArray[j][MAX_SIZE-1-i] = myArray[i][j];

    }
  }

  
  //clears original array
  for(int i = 0; i < MAX_SIZE; i++){
    for(int j = 0; j < MAX_SIZE; j++){

      myArray[i][j] = ' ';

    }
  }

  
  //copies rotation to original array
  for(int i = 0; i < MAX_SIZE; i++){
    for(int j = 0; j < MAX_SIZE; j++){

      myArray[i][j] = tempArray[i][j];

    }
  }

  

  return 0;
}


// invertHorizontal
// art is in 2d array, art is inverted horizontally 
int invertHorizontal(char myArray[][MAX_SIZE]){

   char tempArray[MAX_SIZE][MAX_SIZE];

  //sets value of tempArray to blank chars
  for(int i = 0; i < MAX_SIZE; i++){
    for(int j = 0; j < MAX_SIZE; j++){

      tempArray[i][j] = ' ';

    }
  }


  //inverts values of original array into tempArray
  for(int i = 0; i < MAX_SIZE; i++){
    for(int j = 0; j < MAX_SIZE; j++){

      tempArray[i][MAX_SIZE-1-j] = myArray[i][j];

    }
  }


  //clears original array
  for(int i = 0; i < MAX_SIZE; i++){
    for(int j = 0; j < MAX_SIZE; j++){

      myArray[i][j] = ' ';
  
   }
  }


  //copies inverted values to original array
  for(int i = 0; i < MAX_SIZE; i++){
    for(int j = 0; j < MAX_SIZE; j++){

      myArray[i][j] = tempArray[i][j];

    }
  }



  return 0;
}


// invertVertical
// art is in 2d array, art is inverted vertically
int invertVertical(char myArray[][MAX_SIZE]){

   char tempArray[MAX_SIZE][MAX_SIZE];

  //sets value of tempArray to blank chars
  for(int i = 0; i < MAX_SIZE; i++){
    for(int j = 0; j < MAX_SIZE; j++){

      tempArray[i][j] = ' ';

    }
  }


  //inverts values of original array to tempArray
  for(int i = 0; i < MAX_SIZE; i++){
    for(int j = 0; j < MAX_SIZE; j++){

      tempArray[MAX_SIZE -1-i][MAX_SIZE -1- j] = myArray[i][j];

    }
  }


  //clears original array
  for(int i = 0; i < MAX_SIZE; i++){
    for(int j = 0; j < MAX_SIZE; j++){

      myArray[i][j] = ' ';

   }
  }


  //copies inverted values to original array
  for(int i = 0; i < MAX_SIZE; i++){
    for(int j = 0; j < MAX_SIZE; j++){

      myArray[i][j] = tempArray[i][j];

    }
  }



  return 0;
}
