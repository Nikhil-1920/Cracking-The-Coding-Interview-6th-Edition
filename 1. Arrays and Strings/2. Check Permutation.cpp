// checking permutation between strings
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// using sort algorithm
bool arePermutation1(string s1, string s2) {
    int l1 = s1.length();
    int l2 = s2.length();
    
    // condition for anagram
    if(l1 != l2) return false;
  
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    
    for(int i = 0; i < l1; i++) {
        if(s1[i] != s2[i])
            return false;
    }
    return true;
}

// using character counting
bool arePermutation2(const string &s1, const string &s2) {
    int l1 = s1.length();
    int l2 = s2.length();
    
    // condition for anagram
    if(l1 != l2) return false;
    
    int count[256] = {0};
    
    // keeping count of each character of s1
    for(int i = 0; i < l1; i++) {
        int val = s1[i];
        count[val]++;
    }
    
    // decrementing and comparing each character's count of s2
    for(int i = 0; i < l2; i++) {
        int val = s2[i];
        count[val]--;
        if(count[val] < 0) return false;
    }
    return true;
}

int main(void) {
    // Test Method 1 - Using sort algorithm
    cout << "Test Method 1 - Using sort algorithm" << endl;
    string s1 = "heart";
    string s2 = "earth";
  
    if(arePermutation1(s1, s2)) 
        cout << s1 << " and " << s2 << " are permutations of each other." << endl;
    else
        cout << s1 << " and " << s2 << " are not permutations of each other." << endl;
  
    s1 = "night";
    s2 = "thing";
  
    if(arePermutation1(s1, s2)) 
        cout << s1 << " and " << s2 << " are permutations of each other." << endl;
    else
        cout << s1 << " and " << s2 << " are not permutations of each other." << endl;
  
    // Test Method 2 - Using character count
    cout << endl << "Test Method 2 - Using character count" << endl;
    s1 = "heart";
    s2 = "earth";
  
    if(arePermutation2(s1, s2)) 
        cout << s1 << " and " << s2 << " are permutations of each other." << endl;
    else
        cout << s1 << " and " << s2 << " are not permutations of each other." << endl;
    
    s1 = "night";
    s2 = "thing";
    if(arePermutation2(s1, s2)) 
        cout << s1 << " and " << s2 << " are permutations of each other." << endl;
    else
        cout << s1 << " and " << s2 << " are not permutations of each other." << endl;
  
    return 0;
}
