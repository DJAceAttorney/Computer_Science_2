#include "War.h"

// War
// seeds srand
War::War(){

  srand(time(NULL) );
}

// ~War
// m_myStable and/or m_enemyStable is populated, deallocates horse objects in vectors
War::~War(){
  
  int size = int(m_myStable.size());

  //loops through vector
  for(int i =0; i < size; i++){

    //deletse horse pointers
    delete m_myStable.at(i);
    m_myStable.at(i) = nullptr;
  }
  
  size = int(m_enemyStable.size());

  //loops through vector
  for(int i =0; i < size; i++){

    //deletes horse pointers
    delete m_enemyStable.at(i);
    m_enemyStable.at(i) = nullptr;
    
  }
  
}

// loadHorses
// requires file with valid horse data, m_enemyStable is populated with enemy horse pointers
void War::loadHorses(char *horses){

  ifstream inputStream;
  inputStream.open(horses);

  string name;
  int size;
  int health;
  int speed;
  Horse *horse;


  //loops through the text file
  for(int i =0; i < ENEMY_HORSES; i++){

    inputStream >> name >> size >> health >> speed;

    //enemy horse is small
    if(size == SMALL){

      horse = new Light(name,Size(size),health,speed);
    }

    //enemy horse is medium
    else if(size == MEDIUM){
   
      horse = new Medium(name,Size(size),health,speed);
      
    }

    //enemy horse is heavy
    else{
    
      horse = new Heavy(name,Size(size),health,speed);

    }

    m_enemyStable.push_back(horse);    

  }

  inputStream.close();

}

// mainMenu
// m_enemyStable populated from file, exits if user enters 6
void War::mainMenu(){

  int userChoice =0;
  
  cout << "Welcome to UMBC War" << endl;
  cout << endl;

  //while the user doesn't want to quit
  while(userChoice !=6){
    cout << "What would you like to do?" << endl;
    cout << "1. Display Friendly Stable" << endl;
    cout << "2. Display Enemy Stable" << endl;
    cout << "3. Aquire Horse" << endl;
    cout << "4. Train Horse" << endl;
    cout << "5. Battle" << endl;
    cout << "6. Quit" << endl;

    cin >> userChoice;

    //validates user input
    while(userChoice <1 || userChoice >6){

      cout << "What would you like to do?" << endl;
      cout << "1. Display Friendly Stable" << endl;
      cout << "2. Display Enemy Stable" << endl;
      cout << "3. Aquire Horse" << endl;
      cout << "4. Train Horse" << endl;
      cout << "5. Battle" << endl;
      cout << "6. Quit" << endl;

      cin >> userChoice;

     
    }

    //user wants to display their stable
    if(userChoice == DISPLAY_HORSES){
      displayMyHorses();
    }

    //user wants to display enemy stable
    else if(userChoice == DISPLAY_ENEMY){
      displayEnemyHorses();

    }

    //user wants a new horse
    else if(userChoice == ACQUIRE_HORSE){

      acquireHorse();

    }

    //user wants to train a horse
    else if(userChoice == TRAIN_HORSE){
      
      trainHorse();
    }

    //user wants to battle
    else if(userChoice ==  START_BATTLE){
      startBattle();

    }

    //user quits
    else{

      cout << "Thanks for playing" << endl;
    }    
  
  }

}

// acquireHorse
// new horse is added to m_myStable
void War::acquireHorse(){

  string name;
  int size;
  int health;
  int speed;
  
  cout << "What would you like to name this horse" << endl;
  cin >> name;
  
  //generates random size from 0 to 2  
  size = SMALL + rand()%((LARGE+1) -SMALL);

  
  //LIGHT HORSE
  if(size == SMALL){
    
    //generates random health from 60 to 80
    health = LT_MIN_HEALTH + rand()%((LT_MAX_HEALTH +1) -LT_MIN_HEALTH);

    //generates a random speed from 2 to 3
    speed =  LT_MIN_SPEED + rand()%((LT_MAX_SPEED +1) -LT_MIN_SPEED);
	
  }
  
  //MEDIUM HORSE
  else if(size ==MEDIUM){

    //generates random health from 70 to 90
    health = MD_MIN_HEALTH + rand()%((MD_MAX_HEALTH  +1) -MD_MIN_HEALTH );
    
    //generates random speed from 3 to 4
    speed = MD_MIN_SPEED + rand()%((MD_MAX_SPEED +1) -MD_MIN_SPEED );
	
    }

  //HEAVY HORSE
  else{

    //generates random health from 80 to 100
    health = HV_MIN_HEALTH + rand()%((HV_MAX_HEALTH +1) -HV_MIN_HEALTH);
    
    //generates random speed from 4 to 5
    speed = HV_MIN_SPEED + rand()%((HV_MAX_SPEED +1) -HV_MIN_SPEED);
    
  }

  //makes new horse
  Horse *horse = new Untrained(name,Size(size),health,speed);
  
  //adds horse to stable
  m_myStable.push_back(horse);
  
  cout << "You have acquired a new horse" << endl;


}

// trainHorse
// new horse added to m_stable
void War::trainHorse(){
  
  int size = int(m_myStable.size());

  //user's stable is empty
  if(size ==0){
    cout << "You have no horses to train" << endl;
    cout << endl;
    return;
  }

  int horseChoice = chooseHorse();
  
  //new pointer to specialized horse
  Horse* temp = m_myStable.at(horseChoice) ->specialize();

  //horse can be trained
  if(temp == NULL){
    
    m_myStable.at(horseChoice) -> train();

  }

  //horse can be specialized
  else{

    //deletes old horse
    delete m_myStable.at(horseChoice);
    m_myStable.at(horseChoice) = nullptr;
    
    //adds new horse to stable
    m_myStable.at(horseChoice) = temp;
    
  }
    
}

// startBattle
// user has at least one horse and it's specialized, m_myStable or m_enemyStable has loser removed
void War::startBattle(){

  int size = int(m_myStable.size());
  
  //user's stable is empty
  if(size ==0){

    cout << endl;
    cout << "You have no horse to battle" << endl;
    
    return;
  }

  int userHorse = chooseHorse();
  
  //if the horse can't fight
  if(m_myStable.at(userHorse) -> getTraining() == UNTRAINED){

    cout << endl;
    cout << "That horse is not ready for battle yet" << endl;
    cout << endl;
    
    return;    
  }

  //All enemy horses are defeated
  if(int(m_enemyStable.size()) == 0){

    cout << endl;
    cout << "You defeated all enemy horses!" << endl;
    return;
  }
  
  
  //gets winner of battle
  bool horseWon = m_myStable.at(userHorse) -> battle(m_enemyStable.at(0));
  
  
  //user horse won
  if(horseWon == true){

    //deletes horse pointer
    delete m_enemyStable.at(0);
    m_enemyStable.at(0) = nullptr;
    
    //removes horse from stable
    m_enemyStable.erase(m_enemyStable.begin()+0);

    
    cout << "Congrats you won!" << endl;
    cout << endl;
    
  }

  //enemy horse won
  else{

    //deletes horse pointer
    delete m_myStable.at(userHorse);
    m_myStable.at(userHorse) = nullptr;

    //removes horse from stable
    m_myStable.erase(m_myStable.begin()+userHorse);

    cout << "Your horse perished in the battle" << endl;
    cout << endl;
    
  }
  
}

// displayMyHorses
// m_myStable is populated
void War::displayMyHorses(){

  int size = int(m_myStable.size());

  cout << "My Horses" << endl;
  
  //if the user's stable is empty
  if(size == 0){
    cout << "Your stable is currently empty" << endl;
    cout << endl;
    
    return;
  }
  
  cout <<"Num" << "\t" << "\t" <<  "Horse" << " \t"<< "Size" << "\t"<< "\t" << "Health" << "\t" << "Speed" << "\t"<< "Training" << endl;

  //displays all the horses in m_myStable
  for(int i=0; i< size; i++){

    //calls overloaded function
    cout << i+1 << *(m_myStable.at(i)) << endl;

  }
}

// displayEnemyHorses
// m_enemyStable is populated
void War::displayEnemyHorses(){

  int size = int(m_enemyStable.size());

  //if the enemy stable is empty
  if(size == 0){
    cout << "You defeated all the enemy horses!" << endl;

    return;
  }
  
  cout << "Enemy Horses" << endl;

  cout <<"Num" << "\t" << "\t" <<  "Horse" << " \t"<< "Size" << "\t"<< "\t" << "Health" << "\t" << "Speed" << "\t"<< "Training" << endl;

  //displays all the horses in m_enemyStable
  for(int i=0; i< size; i++){

    //calls overloaded function
    cout << i+1 << *(m_enemyStable.at(i)) << endl;
    
  }
 
}

// chooseHorse
// none
int War::chooseHorse(){

  int size = int(m_myStable.size());
  int userChoice;

  //user's stable is empty
  if(size == 0){
    
    cout << "Your stable is empty" << endl;
  }
  else{
    
    displayMyHorses();

    cout << "Which horse would you like to work with? " << endl;
    cin >> userChoice;

    while(userChoice <= 0 || userChoice > size){

      cout << "Which horse would you like to work with? " << endl;
      cin >> userChoice;

    }
  }
  
  return userChoice-1;
  
}
