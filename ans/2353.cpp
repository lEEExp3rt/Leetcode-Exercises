/**
 * @brief 2353 - Food Ratings
 * @link https://leetcode.cn/problems/design-a-food-rating-system/
 * @author !EEExp3rt
 * @date 2025-02-28
 * @note 使用红黑树存储cuisine数据，使得寻找最高评分的食物的时间复杂度为O(logn)
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <set>

class Food {
public:
    Food() = default;
    Food(std::string name, int rating, std::string cuisine): name(name), rating(rating), cuisine(cuisine) {}
    bool operator<(const Food& other) const {
        return rating < other.rating || (rating == other.rating && name > other.name);
    }
    int rating;
    std::string name;
    std::string cuisine;
};

class FoodRatings {
public:
    FoodRatings(std::vector<std::string>& foods, std::vector<std::string>& cuisines, std::vector<int>& ratings) {
        int len = foods.size();
        for (int i = 0; i < len; i++) {
            Food food = Food(foods[i], ratings[i], cuisines[i]);
            foodList[foods[i]] = food;
            cuisineList[cuisines[i]].insert(food);
        }
    }

    void changeRating(std::string food, int newRating) {
        if (foodList.count(food)) {
            Food& f = foodList[food];
            std::set<Food>& cuisines = cuisineList[f.cuisine];
            cuisines.erase(f);
            f.rating = newRating;
            cuisines.insert(f);
        }
        return ;
    }

    std::string highestRated(std::string cuisine) {
        return cuisineList[cuisine].rbegin()->name;
    }
private:
    std::unordered_map<std::string, Food> foodList;
    std::unordered_map<std::string, std::set<Food>> cuisineList;
};