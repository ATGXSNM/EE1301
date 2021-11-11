#include <iostream>
#include <string>

using namespace std;

int *get_frequencies(string s) {
    int *counts = new int[26];
    char ch;
    for (int i = 0; i < 26; i++) {
        counts[i] = 0;
    }
    for(double i = 0; i < s.size(); i++) {
        ch = s[i];
        if (ch >= 'A' && ch <= 'Z')
            ch += 32;
        if (ch >= 'a' && ch <= 'z')
            counts[ch-'a']++;
    }
    return counts;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    int *counts = get_frequencies(s);
    cout << "Letter frequency" << endl;
    for (int i = 0; i < 26; i++) {
        if (counts[i] > 0)
            cout << "  " << (char)('a'+i) << "  " << counts[i] << endl;
    }
    return 0;
} 
