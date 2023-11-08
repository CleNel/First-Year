#include <iostream>
using namespace std;

// declare a read function that reads size chars into array a ...
void read (char array[], int MCQsize);

//declare a score function that takes two arrays of chars, correct answers and student answers, and their size, and returns the score ...
int score (char solution[], char answers[], int MCQsize);


int main ()
{
    const int MCQsize = 20;
    int studentID;
    int grade;
    char solution[MCQsize], answers[MCQsize];
        
    //read the model/correct answers ...
    read(solution, MCQsize);
    
    //read the first student id
    cin >> studentID;
    
    //read, score and report each student's answers ...
    while(studentID != -1){
      read(answers, MCQsize);
      grade = score(solution, answers, MCQsize);
      cout << studentID << ": " << grade << " " << endl;
      cin >> studentID;
    }
  
    return 0;
}

//define the functions ...
void read (char array[], int MCQsize){
  for(int i = 0; i < MCQsize; i++){
    cin >> array[i];
  }
}

int score (char solution[], char answers[], int MCQsize){
  int grade = 0;
  for(int i = 0; i < MCQsize; i++){
    if(solution[i] == answers[i]){
      grade = grade + 2;
    }else if(answers[i] == 'x'){
      grade = grade + 0;
    }else{
      grade--;
    }
  }
  return grade;
}