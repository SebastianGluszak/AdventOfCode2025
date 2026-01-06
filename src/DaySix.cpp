//
// Created by Sebastian Gluszak on 1/4/26.
//

#include "../include/DaySix.h"

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <ranges>
#include <iostream>

Homework::Homework(const std::string &inputFile) {
    std::ifstream input(inputFile);

    if (input.is_open()) {
        std::string line;
        while (std::getline(input, line)) {
            if (isdigit(line[0])) {
                int idx = 0;
                for (const auto& str : line | std::views::split(' ')) {
                    if (str.empty()) continue;
                    if (static_cast<int>(mProblems.size()) <= idx) {
                        mProblems.emplace_back();
                    }
                    mProblems[idx].emplace_back(std::stol(std::string(str.begin(), str.end())));
                    idx++;
                }
            } else {
                for (const auto& str : line | std::views::split(' ')) {
                    if (str.empty()) continue;
                    mOperators.emplace_back(str.begin(), str.end());
                }
            }
        }
    } else {
        std::cerr << "Error opening input file: " << inputFile << std::endl;
    }
}

long Homework::solveHomework() const {
    long result = 0;
    const size_t numProblems = mProblems.size();

    for (size_t i = 0; i < numProblems; i++) {
        if (mOperators[i] == "+") {
            result += std::accumulate(mProblems[i].begin(), mProblems[i].end(), 0l);
        }  else if (mOperators[i] == "*") {
            result += std::accumulate(mProblems[i].begin(), mProblems[i].end(), 1l, std::multiplies<>());
        }
    }

    return result;
}

long Homework::solveHomeworkCephalopod() const {
    long result = 0;
    const size_t numProblems = mProblems.size();

    /*
    * TODO: Transpose the file contents and then read file line by line
    * TODO: The start of each problem will contain the first number and the operator
    * TODO: Then keep reading in new lines/numbers until encountering an empty line
    *
    * Not interested enough to do this at the moment...
    */

    return result;
}
