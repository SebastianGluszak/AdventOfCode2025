//
// Created by Sebastian Gluszak on 1/2/26.
//

#ifndef ADVENTOFCODE2025_DAYFIVE_H
#define ADVENTOFCODE2025_DAYFIVE_H

#include <utility>
#include <vector>

class Kitchen {
public:
    Kitchen(const std::string& inputFile);
    int getFreshIngredientCount() const;
    long getFreshIngredientRangeCount();

private:
    std::vector<std::pair<long, long>> mFreshRanges;
    std::vector<long> mIngredients;

    bool isFreshIngredient(long ingredient) const;
};

#endif //ADVENTOFCODE2025_DAYFIVE_H