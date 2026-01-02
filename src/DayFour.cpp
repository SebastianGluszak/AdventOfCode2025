//
// Created by Sebastian Gluszak on 1/1/26.
//

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <mdspan>

#include "../include/DayFour.h"

PrintingDepartment::PrintingDepartment(const std::string &inputFile) {
    std::ifstream input(inputFile);

    if (input.is_open()) {
        const int numRows = static_cast<int>(std::count(std::istreambuf_iterator<char>(input), std::istreambuf_iterator<char>(), '\n'));
        input.clear();
        input.seekg(0);
        std::string line;
        bool initGrid = false;
        size_t row = 0;
        while (std::getline(input, line)) {
            if (!initGrid) {
                const int numCols = static_cast<int>(line.size());
                mData = std::vector<int>(numRows * numCols, 0);
                mGrid = std::mdspan<int, std::dextents<size_t, 2>>(mData.data(), numRows, numCols);
                initGrid = true;
            }
            for (size_t col = 0; col < line.size(); col++) {
                if (line[col] == '@') {
                    mGrid[row, col] = 1;
                }
            }
            row++;
        }
    } else {
        std::cerr << "Unable to open file " << inputFile << std::endl;
    }
}

int PrintingDepartment::getAccessiblePaperRolls() const {
    int numAccessiblePaperRolls = 0;
    size_t numRows = mGrid.extent(0);
    size_t numCols = mGrid.extent(1);

    for (size_t row = 0; row < numRows; row++) {
        for (size_t col = 0; col < numCols; col++) {
            if (mGrid[row, col] == 1 && isAccessible(row, col)) numAccessiblePaperRolls++;
        }
    }

    return numAccessiblePaperRolls;
}

bool PrintingDepartment::isAccessible(size_t row, size_t col) const {
    int adjacentPaperRolls = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0) continue;
            if (isPaperRoll(static_cast<int>(row) + i, static_cast<int>(col) + j)) { adjacentPaperRolls++; }
        }
    }
    if (adjacentPaperRolls < 4) {
        return true;
    } else {
        return false;
    }
}

bool PrintingDepartment::isPaperRoll(int row, int col) const {
    if (row < 0 || col < 0 || row >= static_cast<int>(mGrid.extent(0)) || col >= static_cast<int>(mGrid.extent(1))) return false;
    return mGrid[static_cast<size_t>(row), static_cast<size_t>(col)] == 1;
}

int PrintingDepartment::removePaperRolls() {
    int removedPaperRolls = 0;

    while (true) {
        int numRemoved = 0;

        for (size_t row = 0; row < mGrid.extent(0); row++) {
            for (size_t col = 0; col < mGrid.extent(1); col++) {
                if (mGrid[row, col] == 1 && isAccessible(row, col)) {
                    numRemoved++;
                    removedPaperRolls++;
                    mGrid[row, col] = 0;
                }
            }
        }

        if (numRemoved == 0) {
            break;
        }
    }

    return removedPaperRolls;
}


