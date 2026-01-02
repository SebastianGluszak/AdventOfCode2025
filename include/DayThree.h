//
// Created by Sebastian Gluszak on 1/1/26.
//

#ifndef ADVENTOFCODE2025_DAYTHREE_H
#define ADVENTOFCODE2025_DAYTHREE_H

#include <string>
#include <vector>

class PowerSupply {
private:
    std::vector<std::string> mPowerBanks;
    int findBestBattery(const std::string& bank, int startIndex, int batteriesRemaining) const;

public:
    PowerSupply(const std::string& inputFile);
    int getTotalJoltagePart1() const;
    long getTotalJoltagePart2() const;
};

#endif //ADVENTOFCODE2025_DAYTHREE_H