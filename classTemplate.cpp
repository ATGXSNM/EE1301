#include <iostream>

using namespace std;

template <class T>
class holdinStuff
{
public:
	T stuff;
};


int main()
{
	holdinStuff<int> x;
	holdinStuff<string> y;
	
	x.stuff = 99;
	y.stuff = "blah";
	
	cout << x.stuff << endl;
	cout << y.stuff << endl;
	
	
	return 0;
}












/*
template <typename T>
class storeStuff
{
public:
	T x;
};

int main()
{
	storeStuff<int> a;
	a.x = 10;
	
	cout << a.x << endl;
	
	
	storeStuff<string> b;
	b.x = "laksdjfklaherioajsd;f";
	
	cout << b.x << endl;
}
*/































/*
template <typename T>
class holdinStuff {
public:
	T stuff;
};

int main()
{
	holdinStuff<int> x;
	x.stuff = 20;
	
	holdinStuff<string> word;
	word.stuff = "i like stoof\n";
	
	cout << x.stuff << endl;
	
	cout << word.stuff << endl;
	
	return 0;
}
*/
