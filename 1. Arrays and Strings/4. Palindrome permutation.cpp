// checking whether any permutations of given strings are palindrome
#include <iostream>
using namespace std;

// function returning char-index of frequency table
int getIndex(char ch) {
    int index = -1;
    if(ch >= 'A' && ch <= 'Z') index = ch - 'A';
    else if(ch >= 'a' && ch <= 'z') 
        index = ch - 'a';
    return index;
}

// function to store frequency count of each char
void countFrequency(const string &s, int freq[]) {
    int index;
    
    for(const char &ch : s) {
        index = getIndex(ch);
        
        if(index != -1) 
            freq[index]++;
    }
}

// Method-1 returns true, when any one permutation
// of string is palindrome or it will return false
bool isPermutationOfPalindrome1(const string &s) {
    int freq[26] = {0};
    countFrequency(s, freq);
    
    // only one char with odd frequency is allowed
    // for permutation of string to be palindrome
    bool oddAppeared = false;
    for(int i = 0; i < 26; i++) {
        
        if(freq[i] % 2 && oddAppeared) return false;
        else if(freq[i] % 2 && !oddAppeared)
            oddAppeared = true;
    }
    return true;
}

// Method-2, optimized version of Method-1
bool isPermutationOfPalindrome2(const string &s) {
    int oddCount = 0, index = 0;
    
    int freq[26] = {0};
    for(const char &ch : s) {
        
        index = getIndex(ch);
        if(index != -1) {
            freq[index]++;
            if(freq[index] % 2) oddCount++;
            else oddCount--;
        }
    }
    return (oddCount <= 1);
}

// toggles the respective bit each time that,
// char appears in the string
int toggle(int bitVector, int index) {
    
    if(index < 0) return bitVector;
    
    int mask = 1 << index;
    if((bitVector & mask) == 0) bitVector |= mask;
    
    else return bitVector &= ~mask;
    
    return bitVector;
}

// returns true, if single bit is set or,
// if bitVector is multiple of power of 2
bool isExactlyOneBitset(int bitVector) {
    return ((bitVector & bitVector - 1) == 0);
}

// Method-3, here each char is represented by a bit,
// on each occurence of char in string, bit is toggled
// if bitVector is left with more than 1 bit, string
// cannot have palindrome-permutation
bool isPermutationOfPalindrome3(const string &s) {
    int bitVector = 0;
    int index = 0;
    for(const char &ch : s) {
        index = getIndex(ch);
        bitVector = toggle(bitVector, index);
    }
    return (bitVector == 0 || isExactlyOneBitset(bitVector));
}

int main(void) {
    string s1 = "Tact Coa";
    cout << "Does \"" << s1 << "\" has string whose permutation is palindrome?\n";
    cout << "Method-1: " << boolalpha << isPermutationOfPalindrome1(s1);
    cout << endl;
    cout << "Method-2: " << boolalpha << isPermutationOfPalindrome2(s1);
    cout << endl;
    cout << "Method-3: " << boolalpha << isPermutationOfPalindrome3(s1);
    cout << endl << endl;
    
    string s2 = "Black Dog";
    cout << "Does \"" << s2 << "\" has string whose permutation is palindrome?\n";
    cout << "Method-1: " << boolalpha << isPermutationOfPalindrome1(s2);
    cout << endl;
    cout << "Method-2: " << boolalpha << isPermutationOfPalindrome2(s2);
    cout << endl;
    cout << "Method-3: " << boolalpha << isPermutationOfPalindrome3(s2);
    cout << endl << endl;
    
    string s3 = "Abc cba";
    cout << "Does \"" << s3 << "\" has string whose permutation is palindrome?\n";
    cout << "Method-1: " << boolalpha << isPermutationOfPalindrome1(s3);
    cout << endl;
    cout << "Method-2: " << boolalpha << isPermutationOfPalindrome2(s3);
    cout << endl;
    cout << "Method-3: " << boolalpha << isPermutationOfPalindrome3(s3);
    cout << endl << endl;
    
    return 0;
}
