#include <iostream>
#include <string>
using namespace std;


int main()
{
	char word1[] = {'h', 'i', '\0'};
	char word2[] = "hi"; // should be the same as word1
	
	cout << word1 << endl;
	cout << word2 << endl;

	cout << "Are the words equal? ";
	if(word1 == word2){
	  cout << "YES!\n";
	} else{
	  cout << "No :(\n";
	}

	cout << &word1 << endl;
	cout << &word2 << endl;

	cout << "Are their contents equal? ";
	if(strcmp(word1, word2) == 0){
	  cout << "YES!\n";
	} else{
	  cout << "No :(\n";
	}

	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*

#include <iostream>
using namespace std;

int main() 
{
	char word[] = {'t', 'm', 'i', '\0'};
	cout << word << endl;
	
	char anotherWord[] = "i like this string now";
	cout << anotherWord << endl;
	
	char originalWord[] = "omg";
	
	cout << "same? " << (word == originalWord) << endl;
	
	return 0;
}
*/
