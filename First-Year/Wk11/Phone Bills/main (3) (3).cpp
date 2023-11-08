#include <iostream>
#include <iomanip>
#include <string> 

using namespace std;

const string SENTINEL = "X0000";

//Ideally use constants for all fixed charges values, and for free mins etc.

//Regular
const double R_FIXED_FEE = 10.00;
const int R_FREE_MINS = 50;
const double R_FEE_PER_MIN = 0.20;

//Premium
const double P_FIXED_FEE = 25.00;

const int P_FREE_MINS_DAYTIME = 75;
const double P_DAYTIME_FEE_PER_MIN = 0.10;

const int P_FREE_MINS_OFF_PEAK = 100;
const double P_OFF_PEAK_FEE_PER_MIN = 0.05;


void read (string &name, char &code, int &mins1, int &mins2, double &bal);
//does not handle the account number because this has to be read separately to allow sentinel to be noticed before this function is called
//if code is "R" one of the parameters is not used

double reg_charge (int mins);
//Computes charge for regular service accounts

double prem_charge (int peak_mins, int off_mins);
//Computes charges for premium service accounts

void print_bill (string acc, string name, char code, double bal, double tot);

int main() {
  string acc,name;
  char code;
  int mins1, mins2;
  double bal, tot;

  cin >> acc;
  
  cout << setw(8) << "Account" << setw(15) << "Name" << setw(11) << "Act. Type" << setw(10) << "Charge" << setw(10) << "Balance" << endl;

while(acc != SENTINEL){

  read (name, code, mins1, mins2, bal);

  if(code == 'R'){

    tot = reg_charge(mins1);
    bal = bal + tot;
    
  }else if(code == 'P'){

    tot = prem_charge(mins1, mins2);
    bal = bal + tot;
    
  }

  print_bill(acc, name, code, bal, tot);
  
  cin >> acc;
  
}

    return 0;
}	
    
void read (string &name, char &code, int &mins1, int &mins2, double &bal) {

//read in the data for one record,//does not handle the account number because this 
//has to be read separately to allow sentinel to be noticed before this function is called
//if code is "R" one of the parameters is not used

  cin >> name;
  cin >> bal;
  cin >> code;

  if(code == 'R'){
    cin >> mins1;
  }else if(code == 'P'){
    cin >> mins1;
    cin >> mins2;
  }
  
}   
    

//Define a function to compute and return the fee for the regular service and used minutes

double prem_charge (int peak_mins, int off_mins) {
//Computes charges for premium service accounts
	double total = P_FIXED_FEE;
  
  double free_mins_daytime = P_FREE_MINS_DAYTIME;
  double daytime_rate = P_DAYTIME_FEE_PER_MIN;
  
  double free_mins_off_peak = P_FREE_MINS_OFF_PEAK;
  double off_peak_rate = P_OFF_PEAK_FEE_PER_MIN;

	//now add on fees for the used minutes

  if((peak_mins + off_mins) - (free_mins_daytime + free_mins_off_peak) <= 0){
    return total;
  }else if(peak_mins - free_mins_daytime > 0 || off_mins - free_mins_off_peak > 0){
    if(peak_mins - free_mins_daytime > 0){
      peak_mins = peak_mins - free_mins_daytime;
      total = total + (peak_mins * daytime_rate);
    }
    if(off_mins - free_mins_off_peak > 0){
      off_mins = off_mins - free_mins_off_peak;
      total = total + (off_mins * off_peak_rate);
    }
  }
  
	return total;
}

double reg_charge (int mins){

  double total = R_FIXED_FEE; 
  double free_mins = R_FREE_MINS;
  double rate = R_FEE_PER_MIN;
  
  if(mins - free_mins <= 0){
    return total;
  }else{
    mins = mins - free_mins;
    return (mins * rate) + total;
    
  }
  
}

void print_bill (string acc, string name, char code, double bal, double tot){
	cout << fixed << showpoint << setprecision (2);
	//copy setw numbers from the header in main 

  cout << setw(8) << acc << setw(15) << name << setw(11);

  if(code == 'R'){
    cout << "Regular";
  }else if(code == 'P'){
    cout << "Premium";
  }

  cout << setw(10) << tot << setw(10) << bal << endl;
  
}
