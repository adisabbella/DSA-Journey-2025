// Replace Non-Coprime Numbers in Array
// 16-09-2025
// Difficulty: Hard (Leetcode - Hard)

#include <bits/stdc++.h>
#include<numeric>
using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            while (!ans.empty() && gcd(curr, ans.back()) > 1) {
                curr = lcm(curr, ans.back());
                ans.pop_back();
            }
            ans.push_back(curr);
        }
        return ans;
    }
};


int main() {
    Solution sol;

    vector<int> nums = {6, 4, 3}; 
    vector<int> result = sol.replaceNonCoprimes(nums);

    cout << "Result: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
