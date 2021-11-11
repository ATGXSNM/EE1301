#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main()
{
  ifstream fin;
  fin.open("militarySpending.txt");
  if(!fin.is_open()){
    cout << "Could not open militarySpending.txt\n";
    exit(1);
  }
  
  // table format (after first 2 rows of header info):
  // rank(int) country(string) country(string) spending(double) percentGDP(double)
  int rank; 
  string country, garbage;
  double spending;
  
  // ignore the first line
  getline(fin, garbage); 
  
  // 2nd line contains the world total spending
  double worldSpending;
  fin >> garbage >> garbage >> garbage >> worldSpending;
  getline(fin, garbage);  // ignore the rest of the 2nd line
  
  // set formatting flags
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  
  // print the table header
  cout << setw(4) << "Rank" 
       << setw(15) << "County" 
       << setw(15) << "Spending($B)"
       << setw(10) << "% World" << endl;  
  
  // keep reading lines until the end of the file
  while(fin >> rank >> country >> garbage >> spending)
  {
    getline(fin,garbage);     // ignore the rest of the line
    // print the input data to the output table
    cout << setw(4) << rank 
	 << setw(15) << country 
	 << setw(15) << setprecision(1) << spending
	 << setw(10) << setprecision(5) << spending/worldSpending << endl;
  }
  
  return 0;
  
}


























/*
int main()
{
  int rank;
  string countryName, garbage;
  double spent;
  double worldSpent;
  
  ifstream spending;
  spending.open("militarySpending.txt");
  
  getline(spending, garbage); // trash frist line completely
  
  spending >> garbage >> garbage >> garbage;
  spending >> worldSpent;
  getline(spending, garbage); // ignore rest of second line after spent amount
  
  cout << setw(5) << "Rank"
       << setw(25) << "Country Name"
       << setw(10) << setprecision(1) << "Spent (B)"
       << setw(8) << setprecision(2) << "% world" << endl;
  
  spending >> rank >> countryName;
  spending >> garbage;  // get rid of second copy of country name
  spending >> spent;
  getline(spending, garbage);
  
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  
  
  while(!spending.eof())
  {
    cout << setw(5) <<  rank
	 << setw(25) << countryName
	 << setw(10) << setprecision(1) << spent
	 << setw(8) << setprecision(2) << 100*spent/worldSpent << endl;
    
    spending >> rank >> countryName;
    spending >> garbage;  // get rid of second copy of country name
    spending >> spent;
    getline(spending, garbage);
    
  }
}
*/
