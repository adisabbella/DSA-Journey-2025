// Convert Integer to the Sum of Two No-Zero Integers
// 08-09-2025
// Difficulty: Advanced
// Time taken: 20 min(Brute force approach is easy, took 5 min)

// Approach
// 1. Extract each digit from given number
// 2. If the digit is greater than 1, then we can split it into sum of two non zero digits i.e 4 = 2 + 2 or 1 + 3, 5 = 2 + 3 etc.
// 3. If the digit is 0 or 1, we cannot split it like that i.e 0 = 0 + 0, 1 = 0 + 1. Atleast one '0' would be there.
// 4. So, if the digit is 1, we should borrow a carry and make it 11. Then we can make 11 = 5 + 6 or 9 + 2 etc.
// 5. In the same way, if the digit is zero, we should borrow a carry from left and then, make 10 = 5 + 5 or 9 + 1 etc.
// 6. When bought carry, reduce its effect from remaining number.

// Time Complexity: O(log10 n)
// Space Complexity: O(1)

// Solution
#include<bits/stdc++.h>
using namespace std;

vector<int> getNoZeroIntegers(int n) {
    int a = 0, b = 0, place = 1;
    while (n) {
        int digit = n % 10;
        if (digit == 0) {
            a += 9 * place;
            b += place;
            n -= 10;
        }
        else if (digit == 1 && n >= 10) {
            a += 9 * place;
            b += 2 * place;
            n -= 10;
        }
        else {
            a += (digit - 1) * place;
            b += place;
        }
        place *= 10; n /= 10;
    }
    return {a, b};
}
