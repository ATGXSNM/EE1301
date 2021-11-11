// The .h file contains the class definition
#ifndef DATE
#define DATE
#include <iostream>

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
  void setDate(int day, int month, int year);
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

void date::setDate(int day, int month, int year)
{
  date::day = day;
  date::month = month;
  date::year = year;	
}

// end of class definition
#endif

