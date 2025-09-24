class FoodRatings {
private:
    unordered_map<string, string> foodToCuisine;   // food -> cuisine
    unordered_map<string, int> foodToRating;       // food -> rating
    unordered_map<string, set<pair<int,string>>> cuisineSets; // cuisine -> foods (sorted)

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
            cuisineSets[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        int oldRating = foodToRating[food];
        
        // remove old rating
        cuisineSets[cuisine].erase({-oldRating, food});
        // insert new rating
        cuisineSets[cuisine].insert({-newRating, food});
        // update map
        foodToRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisineSets[cuisine].begin()->second;
    }
};


/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */