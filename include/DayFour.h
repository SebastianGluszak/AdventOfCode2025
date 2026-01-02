//
// Created by Sebastian Gluszak on 1/1/26.
//

#ifndef ADVENTOFCODE2025_DAYFOUR_H
#define ADVENTOFCODE2025_DAYFOUR_H

#include <vector>
#include <string>
#include <mdspan>

class PrintingDepartment {
private:
    std::vector<int> mData;
    std::mdspan<int, std::dextents<size_t, 2>> mGrid;
    bool isAccessible(size_t row, size_t col) const;
    bool isPaperRoll(int row, int col) const;

public:
    PrintingDepartment(const std::string& inputFile);
    int getAccessiblePaperRolls() const;
    int removePaperRolls();
};

#endif //ADVENTOFCODE2025_DAYFOUR_H