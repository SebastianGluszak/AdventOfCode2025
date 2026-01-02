//
// Created by Sebastian Gluszak on 1/1/26.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ranges>

#include "../include/DayTwo.h"

GiftShop::GiftShop(const std::string& inputFile) {
    std::ifstream file(inputFile);

    if (file.is_open()) {
        std::string line;
        std::getline(file, line);
        for (const auto& range : line | std::views::split(',')) {
            mProductIDRanges.emplace_back(range.begin(), range.end());
        }
    } else {
        std::cerr << "Unable to open file " << inputFile << std::endl;
    }
}

long GiftShop::getInvalidIDScorePart1() const {
    long score = 0;
    for (const std::string& range : mProductIDRanges) {
        const long begin = stol(range.substr(0, range.find('-')));
        const long end = stol(range.substr(range.find('-') + 1));
        for (long current = begin; current <= end; current++) {
            const std::string id = std::to_string(current);
            if (isValid(id, id.size() / 2)) {
                score += current;
            }
        }
    }
    return score;
}

long GiftShop::getInvalidIDScorePart2() const {
    long score = 0;
    for (const std::string& range: mProductIDRanges) {
        const long begin = stol(range.substr(0, range.find('-')));
        const long end = stol(range.substr(range.find('-') + 1));
        for (long current = begin; current <= end; current++) {
            const std::string id = std::to_string(current);
            for (size_t i = 1; i <= id.size() / 2; i++) {
                if (isValid(id, i)) {
                    score += current;
                    break;
                }
            }
        }
    }
    return score;
}

bool GiftShop::isValid(const std::string& id, int tokenLength) const {
    if (id.size() % tokenLength != 0) {
        return false;
    }

    std::string token = id.substr(0, tokenLength);

    for (size_t i = 1; i < id.size() / tokenLength; i++) {
        std::string otherToken = id.substr(i * tokenLength, tokenLength);
        if (token != otherToken) {
            return false;
        }
    }

    return true;
}
