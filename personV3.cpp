#include <iostream>
#include <string>
using namespace std;

class person {
public:
  person(string n){name = n;}
  string name;
  person* father;
  person* mother;
};

int main()
{
  person me = person("John");
  person* current = &me;
  
  for(int i=0; i < 40; i++)
  {
    string gen = "generation ";
    //gen+= (i+1)+'0';
    gen += to_string(i+1);
      
    current->mother = new person(gen);
    current = current->mother;
  }
  //                                               mom     grandma  great grandma   great great grandma
	cout << "My great great grand mother is " << me.mother->mother-> mother->        mother->name << endl;
}
