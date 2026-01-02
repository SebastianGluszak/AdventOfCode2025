//
// Created by Sebastian Gluszak on 12/31/25.
//
#include <iostream>
#include <string>
#include <fstream>

#include "../include/DayOne.h"

Lock::Lock(const std::string& inputFile, bool isPartOne) : mPassword(0), mCurrentNumber(50), mIsPartOne(isPartOne), mInputFile(inputFile) {}

void Lock::turnLock(const std::string& instruction) {
    const char direction = instruction[0];
    const int numRotations = std::stoi(instruction.substr(1));
    if (direction == 'L') {
        turnLeft(numRotations);
    } else {
        turnRight(numRotations);
    }
}

void Lock::turnLeft(int numRotations) {
    for (int i = 0; i < numRotations; i++) {
        mCurrentNumber--;
        if (mCurrentNumber < 0) {
            mCurrentNumber = 99;
        }
        if (!mIsPartOne && mCurrentNumber == 0) {
            mPassword++;
        }
    }
    if (mIsPartOne && mCurrentNumber == 0) {
        mPassword++;
    }
}

void Lock::turnRight(int numRotations) {
    for (int i = 0; i < numRotations; i++) {
        mCurrentNumber++;
        if (mCurrentNumber > 99) {
            mCurrentNumber = 0;
        }
        if (!mIsPartOne && mCurrentNumber == 0) {
            mPassword++;
        }
    }
    if (mIsPartOne && mCurrentNumber == 0) {
        mPassword++;
    }
}

void Lock::resetLock() {
    mPassword = 0;
    mCurrentNumber = 50;
}

void Lock::execute() {
    resetLock();
    std::ifstream inputFile(mInputFile);

    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            turnLock(line);
        }
    } else {
        std::cerr << "Unable to open file " << mInputFile << std::endl;
    }
}

int Lock::getPassword() const {
    return mPassword;
}