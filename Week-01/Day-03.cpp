// Minimum Number of People to Teach
// 10-09-2025
// Difficulty: Advanced

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> learnSomething;
        for (auto pair : friendships) {
            int u = pair[0];
            int v = pair[1];
            vector<bool> lan(n);
            bool canCommunicate = false;
            for (auto i : languages[u - 1]) {
                lan[i - 1] = true;
            }
            for (auto i : languages[v - 1]) {
                if (lan[i - 1]) {
                    canCommunicate = true;
                }
            }
            if (canCommunicate) {
                continue;
            }
            learnSomething.insert(u - 1);
            learnSomething.insert(v - 1);
        }
        int ans = INT_MAX, users = learnSomething.size();
        vector<int> cnt(n, 0);
        for (auto i : learnSomething) {
            for (auto lan : languages[i]) {
                cnt[lan - 1]++;
            }
        }
        for (auto i : cnt) {
            ans = min(ans, users - i);
        }
        return ans;
    }
};