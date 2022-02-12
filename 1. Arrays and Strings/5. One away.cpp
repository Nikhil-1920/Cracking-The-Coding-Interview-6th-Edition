#include <iostream>
#include <string>
using namespace std;

// returns true if s2 can be made identical to s1,
// by only one modifiction, i.e. insetion, deletion,
// or replacement in s2.
bool isOneEditAway(string s1, string s2) {
	
	string large = s1.length() >= s2.length() ? s1 : s2;
	string small = s1.length() <  s2.length() ? s1 : s2;

	int l1 = large.length();
	int l2 = small.length();
	
	if(abs(l1 - l2) > 1) return false;
	    
	bool conflict = false;
	int i = 0, j = 0;
	
	while(i < l1 && j < l2) {
		
		if(large[i] != small[j]) {
			
			if(conflict) return false; 
			conflict = true;
			if(l1 == l2) i++, j++;
			else i++;
		} 
		else {
			i++, j++;
		}
	}
	return true;
}


int main(void) {
	
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    
    if(isOneEditAway(s1, s2))
        cout << "One edit away." << endl;
    else 
        cout << "Not one edit away." << endl;
    return 0;
}
