// Design Spreadsheet
// 19-09-2025
// Difficulty: Hard (Leetcode - Medium)

#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
private:
    vector<vector<int>> vec;
public:
    Spreadsheet(int rows) {
        vec.resize(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        int row = decode(cell) - 1;
        int col = cell[0] - 'A';
        vec[row][col] = value;
    }

    void resetCell(string cell) {
        setCell(cell, 0);
    }

    int getValue(string formula) {
        int indexOfPlus = formula.find('+');
        string num1 = formula.substr(1, indexOfPlus - 1);
        string num2 = formula.substr(indexOfPlus + 1);
        int ans = 0;
        if (num1[0] >= 'A' && num1[0] <= 'Z') {
            ans += vec[decode(num1) - 1][num1[0] - 'A'];
        } else {
            ans += decode(num1);
        }
        if (num2[0] >= 'A' && num2[0] <= 'Z') {
            ans += vec[decode(num2) - 1][num2[0] - 'A'];
        } else {
            ans += decode(num2);
        }
        return ans;
    }

    int decode(string cell) {
        if (cell[0] >= 'A' && cell[0] <= 'Z') {
            return stoi(cell.substr(1));
        } else {
            return stoi(cell);
        }
    }
};

int main() {
    Spreadsheet spreadsheet(3);
    cout << spreadsheet.getValue("=5+7") << "\n";
    spreadsheet.setCell("A1", 10);
    cout << spreadsheet.getValue("=A1+6") << "\n";
    spreadsheet.setCell("B2", 15);
    cout << spreadsheet.getValue("=A1+B2") << "\n";
    spreadsheet.resetCell("A1");
    cout << spreadsheet.getValue("=A1+B2") << "\n";

    return 0;
}
