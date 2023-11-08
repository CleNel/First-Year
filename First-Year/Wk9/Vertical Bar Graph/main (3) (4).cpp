#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	//declare constants, variables and the array ...
  const int SIZE = 70;
  int rows = 20;
  int integers [SIZE];
  int num;
  
	//read the numbers into the array ...
	for(int i = 0; i < SIZE; i++){
    cin >> integers [i];
  }

  //print lines starting from top of the graph ...
	for(int j = rows; j > 0; j--){
    cout << right << setw(2) << rows;
    cout << right << setw(3) << "|";

    for(int k = 0;k < SIZE; k++){
      num = integers[k];
      if(num >= rows){
        cout << "*";
      }else{
        cout << " ";
      }
      
    }

    cout << endl;
      rows--;
    
  }
	
	//print the x-axis ...
	cout << "----|";
  for(int l = 0; l < (SIZE/10); l++){
    cout << "----+----|";
  }
  
	return 0;
}