
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//----- Basic Problem: 1.1 -----------
// bool isUnique(string s) {
//     sort(s.begin(), s.end()); // O(NlogN)
//     for (int i = 0; i < s.length() - 1; i++) { 
//         if (s[i] == s[i + 1]) 
//             return false;
//     }

//     return true;
// }

//----- Basic Problem: 1.2 -----------
bool isPermutation(string s1, string s2) {
    if (s1.length() != s2.length()) 
        return false;

    sort(s1.begin(), s1.end()); // O(NlogN)
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

// Relevant problem: 217, 242, 409, 3

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << isPermutation(s1, s2);
    return 1;
}
