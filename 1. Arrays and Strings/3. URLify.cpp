// URLify - Replacing all the spaces in a string with '%20'
#include <iostream>
using namespace std;

void URLify(char s[], int length) {
    int spaceCount = 0;
    
    // counting spaces between the words
    for(int i = 0; i < length; i++)
        if(s[i] == ' ') spaceCount++;
  
    int newLength = length + 2 * spaceCount;
    int i = newLength - 1;
    
    for(int j = length - 1; j >= 0; j--) {
        if(s[j] == ' ') {
            s[i--] = '0';
            s[i--] = '2';
            s[i--] = '%';
        }
        else
            s[i--] = s[j];
    }
}

int main(void) {
    // input string with new length
    // inplace modification of input string
    // 4-extra space(2 * length) to avoid overflow
    char s[] = "Mr John Smith    ";     
    cout << "Actual string: " << s << endl;
    URLify(s, 13);
    cout << "URLified string: " << s << endl;
    return 0;
}
