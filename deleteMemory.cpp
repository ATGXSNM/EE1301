#include <iostream>
#include <string>

using namespace std;

int main()
{
  int *p;
  p = new int;
  *p = 7;
  
  cout << "p points to " << p << endl;
  cout << "The value stored at " << p << " is " << *p << endl;
  
  delete p;
  cout << "After delete, p points to " << p << endl;
  //p = NULL;
  
  *p = 7; // p still has its old address
  cout << "The value stored at " << p << " is " << *p << endl;
  
  return 0;
}

















/*
#include <iostream>
#include <string>

using namespace std;


int main()
{
	int *imaPointer; // pointer box (holds address)
	imaPointer = new int; // point here!
	*imaPointer = 3; // put number 3 there!
	cout << imaPointer << endl; // verification

	delete imaPointer; // goodbye pointer
	cout << imaPointer << endl; // wait... what?
	
	return 0;
}
*/
