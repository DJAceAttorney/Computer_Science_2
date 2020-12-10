#include "Medium.h"

// Medium
// none
Medium::Medium(){}

// Medium(name,size,speed,health)
// valid inputs
Medium::Medium(string name, Size size, int health,int speed):Warhorse(name,size,health,speed){

}

// attack
// passed string name of trager and attacker's health
int Medium::attack(string name, int health){

  cout << "The " << toString() << " warhorse " << getName() << " " << "hits " << name << endl;
  
  int trainLevel = int(getTraining());

  //calculates horse's attack
  int horseAttack = (health/6)+trainLevel;

  return horseAttack;
}

// toString
// variables set valid, returns string Medium
string Medium::toString(){

  return "Medium";
}
