#include "Untrained.h"

// Untrained
// none
Untrained::Untrained(){
  
}

// Overloaded constructor
// valid inputs
Untrained::Untrained(string name, Size size, int health, int speed):Horse(name,size,health,speed){

}

// specialize
// variables set valid, returns pointer to a new warhorse or NULL
Horse* Untrained::specialize(){

  //horse is small
  if(getSize() == SMALL){
    
    Horse *newLight = new Light(getName(),getSize(),getHealth(),getSpeed());
    
    cout << "Your horse is now a " << newLight ->toString() << " warhorse" << endl;
    cout << endl;
    
    return newLight;
  }

  //horse is medium
  else if(getSize() == MEDIUM){
    
    Horse *newMedium = new Medium(getName(),getSize(),getHealth(),getSpeed());

    
    cout << "Your horse is now a " << newMedium ->toString() << " warhorse" << endl;
    cout << endl;
    
    return newMedium;
  }

  //horse is heavy
  else{
    
    Horse *newHeavy = new Heavy(getName(),getSize(),getHealth(),getSpeed());

    
    cout << "Your horse is now a " << newHeavy ->toString() << " warhorse" << endl;
    cout << endl;
    
    return newHeavy;
    
  }
  
}

// train
// variables are set valid, says horses cannot be trained
bool Untrained::train(){
  
  cout << "Horses cannot be trained" << endl;
  
  return false;
  
}

// toString
// variables set valid, returns string describing horse
string Untrained::toString(){

  return "Unknown";
}


int Untrained::attack(string horse, int health){

  cout << "Untrained horses can't attack" << endl;
  
  return health;
}

