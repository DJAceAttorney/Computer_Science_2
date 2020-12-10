#include "Heavy.h"

// Heavy
// none
Heavy::Heavy(){}

// Heavy(name,size,health,speed)
// valid inputs
Heavy::Heavy(string name, Size size, int health, int speed):Warhorse(name,size,health,speed){

}

// attack
// passed string name of target and attacker's health, returns int damage
int Heavy::attack(string name, int health){

  cout << "The " << toString() << " warhorse " << getName() << " " << "hits " << name << endl;
  
  int trainLevel = int(getTraining());

  //calculates horse's attack
  int horseAttack = (health/6)+trainLevel;

  return horseAttack + kick();

}

// toString
// variables set valid, returns string heavy
string Heavy::toString(){

  return "Heavy";
}

// kick
// variables set valid, returns int between 1 and 3 of more damage
int Heavy::kick(){

  //gerneates random number between 1 and 3
  srand(time(NULL) );
  int randomInt = MIN_KICK + rand()%((MAX_KICK + MIN_KICK) - MIN_KICK);

  cout << "The heavy warhorse spins and kicks the enemy!" << endl;

  
  return randomInt;
}
