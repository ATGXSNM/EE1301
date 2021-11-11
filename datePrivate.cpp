#include <iostream>

using namespace std;

class date
{
private:
	int day;
	int month;
	int year;
public:
	void print() const;
	void setDate(int day, int month, int year);
};

// public member function of the date class
void date::print() const
{
	cout << month<<"/"<<day<<"/"<<year;
}

// public member function of the date class
void date::setDate(int day, int month, int year)
{
	date::day = day;
	date::month = month; // better way, but haven't talked about
	date::year = year;	
}


// not a member of the date class, but does take a date object as input
void print(date today)
{
  cout << today.month<<"/"<<today.day<<"/"<<today.year;  // these private members of the object today cannot be accessed here!
}


int main()
{
	date today;
	today.setDate(14, 4, 2016);
	
	cout << "Today is: ";
	today.print();
	//print(today);
	//cout << today.month<<"/"<<today.day<<"/"<<today.year;
	cout << endl;
	
	//cout << today.day << endl;  // CANNOT touch private variables -- this wouldn't work
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
	void print();
	void setDate(int day, int month, int year);
};

// not related to "date" class
void print() {
	cout << "Hello!\n";
}

// class "date"'s version of print
void date::print() {
	cout << month << "/" << day << "/" << year;
}

void date::setDate(int day, int month, int year) {
	date::day=day; 
	// date::day is the one in the class above
	// day is the one from the function parameter
	this->month=month;
	// we will learn what "this" is later, but it is a better way
	date::year=year;
}


int main()
{
	date today;
	today.setDate(3, 11, 2015);
	
	today.print(); cout << endl;
	today.setDate(24, 11, 2015); 
	// Midterm #2
	today.print(); cout << endl;
	
	cout << today.month; // bad touch, computer no like
	
	return 0;
}
*/
