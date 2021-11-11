#include <iostream>
#include <limits>
using namespace std;

void reverse(char input[], int length)
{
  for(int i=0; i < length/2; i++)
  {
    char temp;
    cout << "Swapping '"<<input[i]<<"' with '"<<input[length-1-i]<<"'\n";
    temp = input[i];
    input[i] = input[length-1-i];
    input[length-1-i] = temp;
  }
  return;
}

void print_string(char str[], int length)
{
  for(int i=0; i<length; i++){
    cout << str[i];
  }
  return;
}

int main()
{
  char word[8] = {'s', 't', 'r', 'e', 's', 's', 'e', 'd'};
  int length = sizeof(word)/sizeof(char);
  
  cout << "The password is ";
  print_string(word, length);
  cout << endl;

  reverse(word, length);
  
  cout << "The reversed password is ";
  print_string(word, length);
  cout << endl;
  
  return 0;
}


































/*
void reverse(char w[], const int length);

int main() // NOTE: null terminator, next week
{
	char word[] = {'l', 'l', 'a', 'm', 'a'};
	
	//reverse(word, sizeof(word)/sizeof(char));
	
	cout << word << endl;
}

void reverse(char w[], const int length)
{
	char temp[length];
	
	
	//for(int i=length-1; i >= 0; i--)
	//{
	//	temp[length-1-i] = w[i]
	//}
	

	for(int i=0; i < length-1; i++)
	{
		temp[i] = w[length-2-i];
	}
	
	//w=temp; // DOES NOT COPY ARRAY
	for(int i=0; i < length; i++)
	{
		w[i] = temp[i];
	}

}
*/
