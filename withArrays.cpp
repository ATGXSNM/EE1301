#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define LENGTH 100

int main() 
{
  int resistance[LENGTH];
  float average;
  int min = 10000; // bigger than all input values
  int max = 0;    // smaller than all input values

  ifstream fin;
  fin.open("resistors.txt");

  if(!fin.is_open()){
    cout << "Couldn't open file resistors.txt\n";
  }

  // read all the resistors into the array
  for(int i=0; i<LENGTH; i++){
    fin >> resistance[i];
  }
  fin.close();

  // calculate the average, min, and max values
  for(int i=0; i<LENGTH; i++){
    // update running sum
    average += resistance[i];
    // check if this is the new min
    if(resistance[i] < min){
      min = resistance[i];
    }
    // check if this is the new max
    if(resistance[i] > max){
      max = resistance[i];
    }
  } 
 
  // finalize the average by dividing by number of samples
  average /= (float)LENGTH;

  cout << "Average, Min, Max resistance: " << average << ", " << min << ", "<< max << endl;

  return 0;
}
