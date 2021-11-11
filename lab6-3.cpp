#include <iostream>
using namespace std;

void append(char arr1[], int len1, char arr2[], int len2, char result[]) {

for (int i = 0; i < len1; i++) {
result[i] = arr1[i];
}

for (int i = 0; i < len2; i++) {
result[i + len1] = arr2[i];
}

}

int main() {
char first[] = { 'I', ' ', 'a', 'm', ' ' };
char second[] = { 'i', 'r', 'o', 'n', 'm', 'a', 'n', '\0' };
char result[200];
append(first, 5, second, 8, result);
cout << result << endl;
return 0;
}
