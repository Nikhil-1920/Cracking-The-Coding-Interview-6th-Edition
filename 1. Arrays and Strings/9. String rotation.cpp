#include <iostream>
#include <cstring>
using namespace std;

// returns true if s2 is rotated form of s1,
// this method checks if s2 is substring of 
// s1s1, since rotated string will always be 
// substring of s1s1 regardless of divison
// point of original string
bool isSubstring(string s1, string s2) {
    
    size_t l1 = s1.length();
    size_t l2 = s2.length();
    
    if(l1 == 0 || l1 != l2)
        return false;
    
    string concatS1 = s1 + s1;
    if(concatS1.find(s2) != string :: npos)
        return true;
    else return false;
}

int main(void) {
    string s1, s2;
  
    cout << "Enter string1: ";
    cin >> s1;
    cout << "Enter string2: ";
    cin >> s2;
    
    if(isSubstring(s1, s2)) 
        cout << "Yes! " << s2 << " is rotation of " << s1 << endl;
    else {
        cout << "No! " << s2 << " is not the rotation of " << s1;
        cout << endl;
    }
    return 0;
}
