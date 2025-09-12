// Vowels Game in a string
// 12-09-2025
// Difficulty: Advanced (Leetcode medium)

// Approach:
// 1. If there are odd no of vowels in the string, alice will remove the whole string in first turn and win
// 2. If there are even no of vowels in it, alice will remove 1 vowel (or any odd value less than total vowels) from it.
// 3. Then, since total no of vowels are even, even - odd = odd. So, Bob cannot pick in his turn and alice wins.
// 4. So the only way alice loses, is when there are no vowels in the string.

#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    bool doesAliceWin(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                return true;
            }
        }
        return false;
    }
};