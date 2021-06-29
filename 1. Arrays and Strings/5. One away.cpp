#include <iostream>
#include  <string>
using namespace std;

// returns true if s2 can be made identical to s1,
// by only one modifiction, i.e. insetion, deletion,
// or replacement in s2.
bool isOneEditAway(string s1, string s2) {
	string a = s1.length() >= s2.length() ? s1 : s2;
	string b = s1.length() <  s2.length() ? s1 : s2;

	int l1 = a.length();
	int l2 = b.length();
	
	if(abs(l1 - l2) > 1) return false;
	    
	bool flag = false;
	for(int i = 0, j = 0; i < l1 && j < l2;) {
		if(a[i] != b[j]) {
			if(flag) return false; 
			flag = true;
			if(l1 == l2) i++, j++;
			else i++;
		}
		else i++, j++;
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
