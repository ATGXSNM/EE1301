#include <iostream>
#include <string>

using namespace std;

class Person{
public:
	string name;
	Person* mother;
	Person* father;
	Person(string n);
};
Person::Person(string n)
{
	name = n;
}

int main()
{
	Person me = Person("John"); 
	Person dad = Person("Mark");
	Person grandpa = Person("Mario");

	me.father = &dad;
	
	// option 1:
	dad.father = &grandpa;
	
	// option 2: (same as option 1)
	//(*(me.father)).father = &grandpa;
	
	cout << "My name is: "<< me.name << endl;
	cout << "My father's name is: " << me.father->name << endl;
	cout << "My father's name is: " << (*(me.father)).name << endl;
	
	// option 1:
	cout << "My grandfather's name is: " << (*(dad.father)).name << endl;
	// option 2:
	cout << "My grandfather's name is: " << (*((*(me.father)).father)).name << endl;
	// option 3: please never use option 2
	cout << "My grandfather's name is: " << me.father->father->name << endl;
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
	Person me("Jacob");
	cout << "I am: " << me.getName() << endl;
	Person dad("Isaac");
	me.setFather(&dad);
	cout << "My father is: " << me.getFather()->getName() << endl;
	Person grandPa("Abraham");
	me.getFather()->setFather(&grandPa);
	cout << "My grandfather is: " <<me.getFather()->getFather()->getName() << endl;
	
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
