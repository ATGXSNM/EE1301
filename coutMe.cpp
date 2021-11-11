#include <iostream>

using namespace std;


template <typename insertTypeHere>
insertTypeHere generalCout(insertTypeHere x);

void coutMe(int x);
void coutMe(string x);



int main()
{
	int a = 7;
	coutMe(a);
	
	string w = "hi";
	coutMe(w);
	
	generalCout<int>(a);
	generalCout<string>(w);
	
	
	//~ int x = 2;
	//~ int y = 3;
	//~ 
	//~ cout << x/y << endl;
	//~ 
	//~ cout << static_cast<double>(x)/static_cast<double>(y) << endl;
	
	return 0;
}

void coutMe(int x)
{
	cout << x << endl;
}

void coutMe(string x)
{
	cout << x << endl;
}

template <typename insertTypeHere>
insertTypeHere generalCout(insertTypeHere x)
{
	if(is_same<insertTypeHere,string>::value) // check if "insertTypeHere" is a "string"
	{
		cout << "Ima string: ";
	}
	
	cout << x << endl;
	return x;
}


















/*
template <typename insertTypeHere>
void coutMe(insertTypeHere x);

template <typename variableType>
void addMe(variableType x);


int main()
{
	coutMe<string>("hello");
	coutMe<int>(12345);
}

template <typename insertTypeHere> 
void coutMe(insertTypeHere x)
{
	cout << x << endl;
}

template <typename variableType>
void addMe(variableType x)
{
	cout << x << endl;
}
*/























/*
 * 
#include <iostream>

using namespace std;

template <typename T>
void coutMe(T x);

int main()
{
	string x="hi";
	coutMe<string>(x);
}


template <typename T>
void coutMe(T x)
{
	cout << x << endl;
}
*/
