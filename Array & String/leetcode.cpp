// Basic Problem: 1.1
// #include <iostream>
// #include <string>
// #include <algorithm>
// using namespace std;

// bool isUnique(string s) {
//     sort(s.begin(), s.end()); // O(NlogN)
//     for (int i = 0; i < s.length() - 1; i++) { 
//         if (s[i] == s[i + 1]) 
//             return false;
//     }

//     return true;
// }

// int main() {
//     string s;
//     cin >> s;
//     cout << isUnique(s);
//     return 1;
// }

// Relevant problem: 217, 242, 409, 3