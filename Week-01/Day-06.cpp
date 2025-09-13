// Find Most Frequent Vowel and Consonant
// 13-09-2025
// Difficulty: Advanced in Code Everyday (leetcode easy)

// Approach:
// 1. Simple brute force.
// 2. Traverse the string and maintain frequency of each character.
// 3. Traverse through frequency array for getting most frequent vowel and consonant.
// 4. Return their frequencies sum.

#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        int vowelMax = 0;
        int consonantMax = 0;
        for (int i = 0; i < 26; i++) {
            if (isVowel('a' + i)) {
                vowelMax = max(vowelMax, freq[i]);
            }
            else {
                consonantMax = max(consonantMax, freq[i]);
            }
        }
        return vowelMax + consonantMax;
    }
};