#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
private:
    unordered_map<string, set<pair<int, string>>> cuisineHighest;
    unordered_map<string, string> cuisineOf;
    unordered_map<string, int> ratingOf;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            cuisineHighest[cuisines[i]].insert({-ratings[i], foods[i]});
            cuisineOf[foods[i]] = cuisines[i];
            ratingOf[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        cuisineHighest[cuisineOf[food]].erase({-ratingOf[food], food});
        ratingOf[food] = newRating;
        cuisineHighest[cuisineOf[food]].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        return (*(cuisineHighest[cuisine].begin())).second;
    }
};

int main() {
    vector<string> foods = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> cuisines = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    vector<int> ratings = {9, 12, 8, 15, 14, 7};
    
    FoodRatings fr(foods, cuisines, ratings);
    
    cout << fr.highestRated("korean") << endl; 
    cout << fr.highestRated("japanese") << endl; 
    
    fr.changeRating("sushi", 16); 
    cout << fr.highestRated("japanese") << endl; 
    
    fr.changeRating("ramen", 16); 
    cout << fr.highestRated("japanese") << endl; 
    
    return 0;
}
