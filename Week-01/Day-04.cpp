// Sort Vowels in a string
// 11-09-2025
// Difficulty: Hard in Code Everyday (Leetcode medium)

// Approach:
// 1. Traverse through the string and calculate frequencies of vowels, both uppercase and lowercase ones
// 2. Then, traverse the string once more.
// 3. If a character is consonant, add it to result string.
// 4. If it is a vowel, go through the frequency array of vowels and add the least vowel with least possible ascci available.


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string sortVowels(string s) {
        string ans = "";
        vector<int> cnt(128, 0);
        for (int i = 0; i < s.length(); i++) {
            char ch = toupper(s[i]);
            if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                cnt[s[i]]++;
            }
        }
        int index = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = toupper(s[i]);
            if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                while (cnt[index] == 0) {
                    index++;
                }
                cnt[index]--;
                ans += (char)index;
            }
            else {
                ans += s[i];
            }
        }
        return ans;
    }
};