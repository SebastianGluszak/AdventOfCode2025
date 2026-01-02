//
// Created by Sebastian Gluszak on 12/31/25.
//

#ifndef ADVENTOFCODE2025_DAYONE_H
#define ADVENTOFCODE2025_DAYONE_H
#include <string>

class Lock {
private:
    int mPassword;
    int mCurrentNumber;
    bool mIsPartOne;
    std::string mInputFile;

    void turnLock(const std::string& inputFile);
    void turnLeft(int numRotations);
    void turnRight(int numRotations);

public:
    Lock(const std::string& inputFile, bool isPartOne);
    void resetLock();
    void execute();
    int getPassword() const;
};

#endif //ADVENTOFCODE2025_DAYONE_H