
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//----- Basic Problem: 1.1 -----------
bool isUnique(string s) {
    sort(s.begin(), s.end()); // O(NlogN)
    for (int i = 0; i < s.length() - 1; i++) { 
        if (s[i] == s[i + 1]) 
            return false;
    }

    return true;
}

//----- Basic Problem: 1.2 -----------
bool isPermutation(string s1, string s2) {
    if (s1.length() != s2.length()) 
        return false;

    sort(s1.begin(), s1.end()); // O(NlogN)
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

//----- Basic Problem: 1.3 -----------
void URLify(char str[], int trueLength) {
    // Count number of spaces in str
    int numberSpace = 0;
    for (int i = 0; i < trueLength; i++) {
        if (str[i] == ' ') 
            ++numberSpace;
    }

    // Each " " -> "%20" -> increase 2 character
    int endPosition = trueLength + numberSpace * 2;
    str[endPosition] = '\0';
    for (int i = trueLength - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[endPosition - 1] = '%';
            str[endPosition - 2] = '2';
            str[endPosition - 3] = '0';
            endPosition -= 3;
        } else {
            str[endPosition - 1] = str[i];
            endPosition -= 1;
        }
    }
}
// Relevant problem: 217, 242, 409, 3

int main() {
    char str[100] = "Mr John Smith    ";  // assume extra buffer
    int trueLength = 13;
    URLify(str, trueLength);
    cout << str << endl; // Output: Mr%20John%20Smith
    return 0;
}
