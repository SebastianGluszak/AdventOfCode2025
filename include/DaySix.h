//
// Created by Sebastian Gluszak on 1/4/26.
//

#ifndef ADVENTOFCODE2025_DAYSIX_H
#define ADVENTOFCODE2025_DAYSIX_H

#include <string>
#include <vector>

class Homework {
public:
    Homework(const std::string& inputFile);
    long solveHomework() const;
    long solveHomeworkCephalopod() const;

private:
    std::vector<std::vector<long>> mProblems;
    std::vector<std::string> mOperators;
};

#endif //ADVENTOFCODE2025_DAYSIX_H