#include <iostream>

using namespace std;

// note: multiply ... no work for strings

template <typename T>
void addMe(T x, T y);

template <typename T>
void multiplyMe(T x, T y);

int main()
{
	addMe<int>(3,4);
	addMe<string>("hi","there");
	
	multiplyMe<int>(3,4);
//	multiplyMe<string>("hi","there");
	
	return 0;
}

template <typename T>
void addMe(T x, T y)
{
	cout << x+y << endl;
}


template <typename T>
void multiplyMe(T x, T y)
{
	cout << x*y << endl;
}











/*
template <typename T>
void doStuff(T x, T y);

int main()
{	
	doStuff<int>(5,10);
//	doStuff<string>("hello","cat");
	return 0;
}

template <typename T>
void doStuff(T x, T y)
{
	cout << x*y << endl;
}
*/






































/*
template <typename T>
T multiply (T x, T y);

int main()
{
	int a=2, b=3;
	
	cout << multiply<int>(a,b) << endl; // works!
	
	string c="cat", d="dog";
	
	//cout << multiply<string>(c,d) << endl; // uhhh...
	
	return 0;
}


template <typename T>
T multiply (T x, T y)
{
	return x*y;
}
*/
