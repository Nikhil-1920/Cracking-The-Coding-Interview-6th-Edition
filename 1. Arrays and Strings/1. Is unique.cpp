// checking presence of unique characters in strings

#include <iostream>
#include <vector>
#include <bitset>
#include <string>
using namespace std;


// using simple vector, time complexity = O(n)
// space complexity = O(n)
bool isUniqueChars(const string &s) {
    
    if(s.length() > 128) return false;
    vector<bool> charSet(128);
    for(int i = 0; i < s.length(); i++) {
        
        int val = s[i];
        if(charSet[val]) return false;
        charSet[val] = true;
    }
    return true;
}


// using bit vector, time complexity = O(n)
// space complexity = O(n), but reduced as 
// compared to above case
bool isUniqueCharsBitVector(const string &s) {
    
    bitset<256> bits(0);
    for(int i = 0; i < s.length(); i++) {
        
        int val = s[i];
        if(bits.test(val))  return false;
        bits.set(val);
    }
    return true;
}


// using no data structures, time complexity = O(2^n)
// space complexity = no space taken
bool isUniqueCharsNoDS(const string &s) {
    
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == s[i + 1]) return false;
    }
    return true;
}


int main(void) {
    
    vector<string> words = {"abcde", "apple", "padle", "hello"};
    cout << "Testing - Using simple vector" << endl;
    for(auto word : words) {
        
        cout << word << string(": ") << boolalpha << isUniqueChars(word);
        cout << endl;
    }
    
    cout << endl << "Testing - Using bit vector" << endl;
    for(auto word : words) {
        
        cout << word << string(": ") << boolalpha << isUniqueCharsBitVector(word);
        cout << endl;
    }
    
    cout << endl << "Testing - Using no data structures" << endl;
    for(auto word : words) {
        
        cout << word << string(": ") << boolalpha << isUniqueCharsNoDS(word);
        cout << endl;
    }
    return 0;
}
