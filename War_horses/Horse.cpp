#include "Horse.h"

// Horse
// horse is created
Horse::Horse(){
  
}

// Horse(name,size,speed,health)
// inputs name,size,speed,health and training is 0
Horse::Horse(string name, Size size, int health, int speed){
  m_size = size;
  m_speed = speed;
  m_health = health;
  m_name = name;
  m_training = UNTRAINED;
}

// ~Horse
// Horse object in memory,dellalocates horse object
Horse::~Horse(){
  
    
}

// getName
// m_name is set, returns horse's stirng name
string Horse::getName(){

  return m_name;
  
}

// getSize
// m_size is set, returns enum size of horse
Size Horse::getSize(){

  return m_size;
}

// getHealth
// m_health is set, returns int health
int Horse::getHealth(){

  return m_health;
}

// getSpeed
// m_speed is set, returns int speed
int Horse::getSpeed(){

  return m_speed;
}

// getTraining
// m_training is set, returns enum training of horse
Training Horse::getTraining(){

  return m_training;
}

void Horse::setHealth(int health){

  m_health = health;
}


// increaseTraining
// variables set valid, returns bool(true increase, false max)
bool Horse::increaseTraining(){

  //if training isn't maxed
  if(m_training < MAX_TRAINING){

    m_training = Training(int(m_training) + MIN_NUM);

    return true;

  }
  else{

    cout << "Can't increase training anymore" << endl;
    return false;
  }
}

// specialize
// variables set valid, returns pointer to new warhorse or NULL
Horse* Horse::specialize(){

  return NULL;
}


// battle
// variables set valid, returns bool if horse won or lost
bool Horse::battle(Horse *enemy){

  cout << "Horse cannot battle" << endl;
  return false;
  
  
}

// randomPercentBased
// given int to pass, returns boolean
bool Horse::randomPercentBased(int random){

  //generates random number from 1 to 100
  srand(time(NULL) ); 
  int randomInt= 0; 
  randomInt = MIN_NUM + rand()%((MAX_NUM + MIN_NUM) -MIN_NUM); 

  
  if(randomInt < random){

    return true;
  }

  else{

    return false;

  }
}

// Overloaded <<
// variables set valid, returns ostream with output horse
ostream &operator<<(ostream &output,Horse &myHorse){
  
  output << setw(NAME_WIDTH) << myHorse.getName() << "\t";  

  output << myHorse.toString() << "\t\t";
  
  output << myHorse.getHealth() << "\t";

  output << myHorse.getSpeed() << "\t";
  
  output <<  myHorse.trainingString(myHorse.getTraining());
    
  
  return output;
}

// trainingString
// pass training level to function, returns string of enum
string Horse::trainingString(Training temp){

  //training is untrained
  if(temp == UNTRAINED){
    return "Untrained";
  }

  //training is saddle
  else if(temp == SADDLE){
    return "Saddle";

  }

  //training is green
  else if(temp == GREEN){
    return "Green";

  }

  //training is intermediate
  else if(temp == INTERMEDIATE){
    return "Intermediate";

  }

  //training is expert
  else if(temp == EXPERT){
    return "Expert";

  }

  //training is master
  else{
    return "Master";

  }
} 
