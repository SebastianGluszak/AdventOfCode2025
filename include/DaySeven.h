//
// Created by Sebastian Gluszak on 1/5/26.
//

#ifndef ADVENTOFCODE2025_DAYSEVEN_H
#define ADVENTOFCODE2025_DAYSEVEN_H

#include <utility>
#include <vector>

class Tachyon {
public:
    explicit Tachyon(const std::string& inputFile);
    [[nodiscard]] int shootBeam() const;
    [[nodiscard]] int simulateTimelines() const;
    void simulateTimelinesHelper(const std::pair<size_t, size_t>& position, int& numTimelines) const;
private:
    std::vector<std::vector<int>> mGrid;
    std::pair<size_t, size_t> mStart;
};

#endif //ADVENTOFCODE2025_DAYSEVEN_H