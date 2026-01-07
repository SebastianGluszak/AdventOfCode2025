//
// Created by Sebastian Gluszak on 1/5/26.
//

#include <vector>
#include <utility>
#include <fstream>
#include <queue>
#include <set>

#include "../include/DaySeven.h"

#include <iostream>
#include <set>

Tachyon::Tachyon(const std::string &inputFile) {
    std::ifstream input(inputFile);
    if (input.is_open()) {
        std::string line;
        for (size_t i = 0; std::getline(input, line); ++i) {
            std::vector<int> row;
            for (size_t j = 0; j < line.size(); ++j) {
                if (line[j] == '.') {
                    row.push_back(0);
                } else if (line[j] == '^') {
                    row.push_back(1);
                } else if (line[j] == 'S') {
                    mStart = std::make_pair(i, j);
                }
            }
            mGrid.push_back(std::move(row));
        }
    } else {
        std::cerr << "Unable to open file: " << inputFile << std::endl;
    }
}

int Tachyon::shootBeam() const {
    int numSplits = 0;

    std::queue<std::pair<size_t, size_t>> queue;
    queue.push(mStart);
    std::set<std::pair<size_t, size_t>> set { mStart };

    while (!queue.empty()) {
        std::pair<size_t, size_t> current = queue.front();
        size_t row = current.first;
        size_t col = current.second;
        queue.pop();



        if (row < mGrid.size() - 1 && col < mGrid[0].size()) {
            if (auto next = std::make_pair(row + 1, col); mGrid[row + 1][col] == 0) {
                // Empty space
                if (!set.contains(next)) {
                    queue.push(next);
                    set.insert(next);
                }
            } else {
                // Splitter
                if (auto next = std::make_pair(row + 1, col - 1); col > 0 && !set.contains(next)) {
                    queue.push(next);
                    set.insert(next);
                }
                if (auto next = std::make_pair(row + 1, col + 1); col < mGrid[0].size() - 1 && !set.contains(next)) {
                    queue.push(next);
                    set.insert(next);
                }
                numSplits++;
            }
        }
    }

    return numSplits;
}

int Tachyon::simulateTimelines() const {
    int numTimelines = 1;
    simulateTimelinesHelper(mStart, numTimelines);
    return numTimelines;
}

void Tachyon::simulateTimelinesHelper(const std::pair<size_t, size_t>& mStart, int& numTimelines) const {
    size_t row = mStart.first;
    size_t col = mStart.second;

    if (row >= mGrid.size() || col >= mGrid[0].size()) {
        return;
    }

    // Insert logic and recursively call function to update numTimelines
}
