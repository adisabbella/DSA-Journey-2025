// Design Movie Rental System
// 21-09-2025
// Difficulty - Hard (Leetcode - Hard) 

#include <bits/stdc++.h>
using namespace std;

class MovieRentingSystem {
private:
    unordered_map<int, set<pair<int, int>>> movieCopies;
    unordered_map<int, unordered_map<int, int>> prices;
    set<pair<int, pair<int, int>>> rentedCopies;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto entry: entries) {
            movieCopies[entry[1]].insert({entry[2], entry[0]});
            prices[entry[1]][entry[0]] = entry[2];
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        for (auto copy: movieCopies[movie]) {
            ans.push_back(copy.second);
            if (ans.size() == 5) break;
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        int price = prices[movie][shop];
        rentedCopies.insert({price, {shop, movie}});
        movieCopies[movie].erase({price, shop});
    }
    
    void drop(int shop, int movie) {
        int price = prices[movie][shop];
        rentedCopies.erase({price, {shop, movie}});
        movieCopies[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        for (auto copy: rentedCopies) {
            ans.push_back({copy.second.first, copy.second.second});
            if (ans.size() == 5) break;
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> entries = {
        {0, 1, 5},
        {0, 2, 6},
        {1, 1, 4},
        {1, 2, 7},
        {2, 1, 3}
    };
    
    MovieRentingSystem mrs(3, entries);
    
    vector<int> searchResult = mrs.search(1);
    for (int shop : searchResult) cout << shop << " ";
    cout << endl;
    
    mrs.rent(2, 1);
    
    vector<vector<int>> reportResult = mrs.report();
    for (auto &entry : reportResult) {
        cout << entry[0] << " " << entry[1] << endl;
    }
    
    mrs.drop(2, 1);
    
    searchResult = mrs.search(1);
    for (int shop : searchResult) cout << shop << " ";
    cout << endl;
    
    return 0;
}
