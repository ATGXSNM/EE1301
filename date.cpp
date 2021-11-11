#include <iostream>

using namespace std;

class date
{
 public:
  int day;
  int month;
  int year;
  void print() const;
};

// This print function is a member of the date class
void date::print() const
{
  cout << month<<"/"<<day<<"/"<<year;
}

// This print function is not a member of a class, just a regular old function
void print(date today)
{
  cout << today.month<<"/"<<today.day<<"/"<<today.year;
}


int main()
{
	date today;
	today.day = 14;
	today.month=4;
	today.year=2016;
	
	cout << "Today is: ";
	today.print();
	cout << endl;

	cout << "Now using regular function: ";
	print(today);
	//cout << today.month<<"/"<<today.day<<"/"<<today.year;
	cout << endl;
}












/*
#include <iostream>

using namespace std;

class date
{
public:
	int day;
	int month;
	int year;
	void print() const;
};

// not related to "date" class
void print() {
	cout << "Hello!\n";
}

// class "date"'s version of print
void date::print() const {
	cout << month << "/" << day << "/" << year;
}


int main()
{
	date today = {3, 11, 2015};
	
	print();
	today.print();
	
	cout << "Hi" << endl;	
	std::cout << "Hi" << endl; // same as above
	
	return 0;
}
*/
