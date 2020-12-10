#include "Horse.h"
#include "Untrained.h"
#include "Untrained.cpp"
#include "Horse.cpp"
#include "Light.h"
#include "Light.cpp"
#include "Medium.h"
#include "Medium.cpp"
#include "Heavy.h"
#include "Heavy.cpp"
#include "Warhorse.h"
#include "Warhorse.cpp"
#include "War.cpp"
#include "War.h"



using namespace std;

int main(){
  
  //  Horse *horse = new Untrained("Horse",Size(2),12,50);

  //cout << horse << endl;
  
  //Horse *B = horse -> specialize();

  //  B = B -> specialize();

  //cout << "AFTER SECOND SPECIALIZE" << endl;
  
  //horse -> increaseTraining();

  //cout << horse << endl;
  //horse -> increaseTraining();

  //  horse -> attack("Horse",12);
  
  //cout << horse << endl;

  //Horse *light = new Light();

  //Horse *temp = light -> specialize();

  //  if(B == NULL){

  //cout << "ITS NULL" << endl;
  // }



  War war;

  char file[] = "proj4_data.txt";
  war.loadHorses(file);
  
  //  war.displayEnemyHorses();

  //war.acquireHorse();

  //war.displayMyHorses();

  //war.trainHorse();
  //war.trainHorse();
  
  // war.startBattle();
  
  //  war.trainHorse();


  war.mainMenu();

  
  return 0;

}
