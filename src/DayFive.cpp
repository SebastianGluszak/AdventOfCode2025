//
// Created by Sebastian Gluszak on 1/2/26.
//

#include <fstream>
#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <ranges>

#include "../include/DayFive.h"

Kitchen::Kitchen(const std::string &inputFile) {
    std::ifstream input(inputFile);

    if (input.is_open()) {
        bool isReadingRanges = true;
        std::string line;
        while (std::getline(input, line)) {
            if (line.empty()) {
                isReadingRanges = false;
                continue;
            }
            if (isReadingRanges) {
                mFreshRanges.emplace_back(std::stol(line.substr(0, line.find('-'))), std::stol(line.substr(line.find('-') + 1)));
            } else {
                mIngredients.push_back(std::stol(line));
            }
        }
    } else {
        std::cerr << "Could not open file: " << inputFile << std::endl;
    }
}

int Kitchen::getFreshIngredientCount() const {
    int freshIngredientCount = 0;

    for (const long ingredient : mIngredients) {
        if (isFreshIngredient(ingredient)) freshIngredientCount++;
    }

    return freshIngredientCount;
}

bool Kitchen::isFreshIngredient(long ingredient) const {
    return std::ranges::any_of(mFreshRanges, [ingredient](const auto& range) { return range.first <= ingredient && range.second >= ingredient; });
}

bool compare(std::pair<long, long> a, std::pair<long, long> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

long Kitchen::getFreshIngredientRangeCount() {
    long count = 0;
    std::sort(mFreshRanges.begin(), mFreshRanges.end());

    long currentEnd = -1;
    for (const auto& [begin, end] : mFreshRanges) {
        if (begin > currentEnd) {
            count += (end - begin + 1);
            currentEnd = end;
        } else if (end > currentEnd) {
            count += (end - currentEnd);
            currentEnd = end;
        }
    }

    return count;
}