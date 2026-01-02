//
// Created by Sebastian Gluszak on 1/1/26.
//

#ifndef ADVENTOFCODE2025_DAYTWO_H
#define ADVENTOFCODE2025_DAYTWO_H

#include <vector>
#include <string>

class GiftShop {
private:
    std::vector<std::string> mProductIDRanges;
    bool isValid(const std::string& id, int tokenLength) const;

public:
    GiftShop(const std::string& inputFile);
    long getInvalidIDScorePart1() const;
    long getInvalidIDScorePart2() const;
};

#endif //ADVENTOFCODE2025_DAYTWO_H