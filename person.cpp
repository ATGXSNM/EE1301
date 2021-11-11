#include <iostream>
#include <string>

using namespace std;

class person {
public:
	person(string n);
	string name;
	person* father;
	person* mother;
};

person::person(string n)
{
	name = n;
}

int main()
{
	person me = person("John");
	// person me;
	
	person mom = person("Nancy");
	
	
	me.mother = &mom;
	
	cout << "My mother's name is: " << (*(me.mother)).name << endl;
	cout << "My mother's name is: " << me.mother->name << endl;

	return 0;
}



















// "correct version"
/* 
#include <iostream>
#include <string>



using namespace std;

class Person{
private:
	string name;
	Person *mother;
	Person *father;

public:
	Person(string name);
	Person* getMother();
	void setMother(Person *p);
	Person* getFather();
	void setFather(Person *p);
	string getName();
};

int main()
{
	Person me("James");
	cout << "I am: " << me.getName() << endl;
	Person mom("Margery");
	me.setMother(&mom);
	cout << "My mother is: " << me.getMother()->getName() << endl;
	
}


Person::Person(string s)
{
	name = s;
	mother = nullptr;
	father = nullptr;
}


Person* Person::getMother()
{
	return mother;
}

void Person::setMother(Person *p)
{
	mother = p;
}

Person* Person::getFather()
{
	return father;
}

void Person::setFather(Person *p)
{
	father = p;
}

string Person::getName()
{
	return name;
}
*/
