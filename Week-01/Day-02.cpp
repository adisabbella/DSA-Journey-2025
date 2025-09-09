// Number of People Aware of a Secret
// 09-09-2025
// Difficulty: Advanced(Leetcode Medium)
// Time taken: 30 min(15 min for brute force, another 15 min for optimal)

// Approach
// 1. Brute force is nothing but, for each day, new people will know the secret.
// 2. How many new people will know the secret on a particular day? Question yourself.
// 3. The answer is nothing but, the number of people who had their delay time completed and also have not forgot the secret.
// 4. These guys, each will share the secret with one person on that day.
// 5. So, we will loop from (day - forget + 1) to (day - delay) and add them to get new people who know secret on that day
// 6. In Optimal, one observation from brute force is needed.
// 7. We should observe that, new people on a day is nothing but sum of elements in a moving sliding window from (day - forget + 1) to (day - delay)
// 8. So, we can keep a variable and add new element and subtract the old elements dynamically, bringing down time complexity from O(n^2) to O(n)
// 9. At the end, calculate no of people who know secret at the end (not forgotten)

#include<bits/stdc++.h>
using namespace std;

// brute force O(n^2) 

const int MOD = 1e9 + 7;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> newPeople(n, 1);
        for (int i = 1; i < n; i++) {
            int shares = 0;
            for (int j = i - delay; j >= max(0, i - forget + 1); j--) {
                shares = (shares + newPeople[j]) % MOD;
            }
            newPeople[i] = shares;
        }
        int ans = 0;
        for (int i = max(0, n - forget); i < n; i++) {
            ans = (ans + newPeople[i]) % MOD;
        }
        return ans;
    }
};

// Optimal O(n)

const int MOD = 1e9 + 7;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> newPeople(n, 1);
        int shares = 0;
        for (int i = 1; i < n; i++) {
            if (i - delay >= 0) {
                shares = (shares + newPeople[i - delay]) % MOD;
            }
            if (i - forget >= 0) {
                shares = (shares - newPeople[i - forget] + MOD) % MOD;
            }
            newPeople[i] = shares;
        }
        int ans = 0;
        for (int i = max(0, n - forget); i < n; i++) {
            ans = (ans + newPeople[i]) % MOD;
        }
        return ans;
    }
};