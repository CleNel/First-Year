//5 points of 20 for this week
//Indicate which pizza is better value
//Complete this program so that the if statement provided will print "FIRST", "SECOND or "SAME" as appropriate.
//Reuse your previous ppsi code
#include <iostream>
using namespace std;

int main() {
  //declare variables ...
double diameter1, diameter2, ppsi1, ppsi2, price1, price2, area, radius;
const double PI = 3.1415;
  //read in data
  cout << "Enter the diameter and price of the first pizza:";
  cin >> diameter1 >> price1;
  //similarly for second pizza ...
cout << "Enter the diameter and price of the second pizza:";
cin >> diameter2 >> price2;
  //compute ppsi1 and ppsi2...
radius = diameter1 / 2;
area = PI * radius * radius;
ppsi1 = price1 / area;

radius = diameter2 / 2;
area = PI * radius * radius;
ppsi2 = price2 / area;

   // INCLUDE the next lines FOR YOUR OWN TESTING; comment out again FOR SUBMISSION; and do the same for the second pizza
  //cout << "The " << diameter1 << " inch pizza costing " << price1;
  // cout << " is " << ppsi1 << " euros per square inch.\n";
  
  //workout and print the answer
  if (ppsi1 < ppsi2) {
    cout << "FIRST";
  }
  else if (ppsi1 > ppsi2) {
    //...
    cout << "SECOND";
  } else {
    //...
    cout << "SAME";
  }

  cout << endl;
  
  return 0;
}