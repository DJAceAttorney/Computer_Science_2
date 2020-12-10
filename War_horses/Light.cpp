#include "Light.h"

// Light
// none
Light::Light(){}

// Light(name,size,health,speed)
// valid inputs
Light::Light(string name, Size size, int health, int speed):Warhorse(name,size,health,speed){
  
}

// attack
// passed string name of traget and attacker's health, returns damage as integer
int Light::attack(string name, int health){

  cout << "The " << toString() << " warhorse " << getName() << " " << "hits " << name << endl;

  
  int trainLevel = int(getTraining());

  //calculates horse's attack
  int horseAttack = (health/6)+trainLevel;

  return horseAttack;
  
}

// toString
// variables set valid, returns string light
string Light::toString(){

  return "Light";

}
