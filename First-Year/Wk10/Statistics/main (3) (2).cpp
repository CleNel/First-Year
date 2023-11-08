/**
* Week 10 P2
Statistical Functions 
*
* This program reads in an unknown number of values, and then
* computes the mean, variance, standard deviation and the 
* number of zero crossing for these values.
*
*/

#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

void read_to_sentinel(double array[], int capacity, int& size, double sentinel);

//declare the statistical functions ...
double mean(double array[], int size);
double variance(double array[], int size, double avg);
double standard_dev(double array[], int size, double variance);
int zeros(double array[], int size);


int main()
{
	const int CAPACITY = 100;
	double array[CAPACITY];
	int size;
	double sentinel = 9999;
  double avg, var, stddev;
  int zer;
  
  
	//call read_to_sentinel ...
  read_to_sentinel(array, CAPACITY, size, sentinel);

	//call the functions to compute stats, 
  //passing in the size value provided by read_to_sentinel ...
  avg = mean(array, size);
  var = variance(array, size, avg);
  stddev = standard_dev(array, size, var);
  zer = zeros(array, size);
  
  //Print the output
  cout << "Count:" << size << endl;
	cout << "Mean:" << avg << endl;
	cout << "Variance:" << var << endl;
	cout << "Std. Dev.:" << stddev << endl;
	cout << "Zero Xs:" << zer << endl;

  return 0;
}

// read_to_sentinel is as in lectures and in squarearbseq.cpp
// capacity is the maximum capacity (declared size) of the array;
// size (changed within the function, hence the &) becomes the number of values actually added
// sentinel is the number that marks the end of the sequence;
void read_to_sentinel (double array[], int capacity, int& size, double sentinel)
{
	size = 0;
	double x;
	cin >> x;
	while(size < capacity && x != sentinel)
	{
		array[size] = x;
		size = size+1;
		cin >> x;
	}
  if (size == capacity)
    cout << "\nWARNING OVERFLOW Only first " << capacity << " numbers handled.\n";
}

// define the statistical functions ...

//Mean
double mean(double array[], int size){

  double mean = 0;
  for(int i = 0; i < size; i++){
    mean = mean + array[i];
  }
  mean = mean / size;
  return mean;
}

//Variance
double variance(double array[], int size, double avg){

  double var = 0;
  for(int i = 0; i < size; i++){
    var = var + pow((array[i]-avg), 2);
  }
  var = var / (size - 1);
  return var;
}

//Standard Deviation
double standard_dev(double array[], int size, double variance){

  return sqrt(variance);
  
}

//Number of Zero Crossings
int zeros(double array[], int size){

  int zeros = 0;
  for(int i = 0; i < size-1; i++){
    if(array[i] * array[i+1] < 0){
      zeros++;
    }
  }
  return zeros;
  
}