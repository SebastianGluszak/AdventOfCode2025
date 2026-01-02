//
// Created by Sebastian Gluszak on 1/1/26.
//

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <array>
#include <ranges>

#include "../include/DayThree.h"

PowerSupply::PowerSupply(const std::string &inputFile) {
    std::ifstream input(inputFile);

    if (input.is_open()) {
        std::string line;
        while (std::getline(input, line)) {
            mPowerBanks.push_back(line);
        }
    } else {
        std::cerr << "Error opening input file " << inputFile << std::endl;
    }
}

int PowerSupply::getTotalJoltagePart1() const {
    int totalJoltage = 0;

    for (std::string bank : mPowerBanks) {
        int firstDigit = findBestBattery(bank, 0, 2);
        int secondDigit = findBestBattery(bank, firstDigit + 1, 1);

        totalJoltage += std::stoi(std::string{bank[firstDigit], bank[secondDigit]});
    }

    return totalJoltage;
}

long PowerSupply::getTotalJoltagePart2() const {
    long totalJoltage = 0;

    for (std::string bank : mPowerBanks) {
        std::array<int, 12> joltageIndices;
        for (size_t i = 0; i < 12; i++) {
            if (i == 0) {
                joltageIndices[i] = findBestBattery(bank, 0, 12);
            } else {
                joltageIndices[i] = findBestBattery(bank, joltageIndices[i - 1] + 1, 12 - i);
            }
        }
        std::string bankJoltage(12, '0');
        for (size_t i = 0; i < bankJoltage.size(); i++) {
            bankJoltage[i] = bank[joltageIndices[i]];
        }
        totalJoltage += std::stol(bankJoltage);
    }

    return totalJoltage;
}

int PowerSupply::findBestBattery(const std::string& bank, int startIndex, int batteriesRemaining) const {
    int bestBattery = startIndex;

    for (size_t i = startIndex; i < bank.size() - batteriesRemaining + 1; i++) {
        if (bank[i] - '0' > bank[bestBattery] - '0') {
            bestBattery = static_cast<int>(i);
        }
    }

    return bestBattery;
}
