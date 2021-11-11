#include <iostream>
using namespace std;

class date
{
private:
  int day;
  int month;
  int year;
public:
  date();  // This is a constructor
  date(int day, int month, int year);  // This is another constructor
  void print() const;
  //void setDate(int day, int month, int year);
};

void date::print() const
{
  cout << month<<"/"<<day<<"/"<<year;
}

// This constructor initializes the private members of a date with a month, day, and year
date::date(int day, int month, int year)
{
  date::day = day;
  date::month = month;
  date::year = year;	
}

// This is a default constructor to provide a default initialization
date::date()
{
  day = 0;
  month = 0;
  year = 0;
}

/* 
void date::setDate(int day, int month, int year)
{
  date::day = day;
  date::month = month;
  date::year = year;	
}*/


int main()
{
  date today;
  
  // use constructor to initialize today's date
  today = date(14,4,2016);

  // another way to call the constructor
  date xmas(25, 12, 2016);
  
  cout << "Today is: ";
  today.print();
  cout << endl;

  // This calls the default constructor
  date hoy;

  cout << "Hoy es: ";
  hoy.print();
  cout << endl;

  hoy = today;

  cout << "Ahora, hoy es: ";
  hoy.print();
  cout << endl;

  return 0;
  
}





















/*
#include <iostream>

using namespace std;

class date
{
private:
	int day;
	int month;
	int year;
public:
	date(int day, int month, int year);
	// ^^ constructor has same name as class
	void print();
};

// not related to "date" class
void print() {
	cout << "Hello!\n";
}

// class "date"'s version of print
void date::print() {
	cout << month << "/" << day << "/" << year;
}

date::date(int day, int month, int year) {
	date::day=day; 
	// date::day is the one in the class above
	// day is the one from the function parameter
	this->month=month;
	// we will learn what "this" is later, but it is a better way
	date::year=year;
}

int main()
{
	date today(3, 11, 2015);
	date tomorrow=today;
	today.print(); cout << endl;	
	tomorrow.print(); cout << endl;	
		
	return 0;
}
*/
