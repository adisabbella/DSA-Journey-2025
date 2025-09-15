// Maximum Number of Words You Can Type
// 15-09-2025
// Difficulty: Hard (Leetcode - Easy)

// Approach:
// 1. Traverse through the given text and at every index, check if the character is broken.
// 2. If broken, use a boolean variable to denote that the particular word is broken.
// 3. Whenever a whitespace comes, if the boolean variable denotes the word is not broken, add 1 to the answer.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool broken = false;
        int ans = 0;
        for (int i = 0; i < text.length(); i++) {
            if (text[i] == ' ') {
                ans += !broken;
                broken = false;
            }           
            for (int j = 0; j < brokenLetters.length(); j++) {
                if (text[i] == brokenLetters[j]) {
                    broken = true;
                }
            }
        }
        ans += !broken;
        return ans;
    }
};

int main() {
    string text, brokenLetters;

    text = "hello world";
    brokenLetters = "ad";

    Solution sol;
    int result = sol.canBeTypedWords(text, brokenLetters);

    cout << "Number of words that can be typed: " << result << endl;

    return 0;
}