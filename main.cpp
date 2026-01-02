#include <iostream>

#include "include/DayOne.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "~ Please supply a number 1 - 12 to denote the day" << std::endl;
        std::cerr << "~ Please supply a number 1 - 2 to denote the part" << std::endl;
        std::cerr << "~ Usage: ./main <day> <part>" << std::endl;
        return 0;
    }

    int day = 0;
    int part = 0;

    try {
        day = std::stoi(argv[1]);
        part = std::stoi(argv[2]);
    } catch (...) {
        std::cerr << "~ Invalid arguments supplied!" << std::endl;
        std::cerr << "~ Usage: ./main <day> <part>" << std::endl;
    }

    if (day == 1) {
        if (part == 1) {
            Lock northPoleLock("/Users/sebastiangluszak/Dev/AdventOfCode2025/data/DayOneInputPartOne.txt", true);
            northPoleLock.execute();
            std::cout << "The password to open the door is: " << northPoleLock.getPassword() << std::endl;
        } else if (part == 2) {
            Lock northPoleLock("/Users/sebastiangluszak/Dev/AdventOfCode2025/data/DayOneInputPartTwo.txt", false);
            northPoleLock.execute();
            std::cout << "The password to open the door is: " << northPoleLock.getPassword() << std::endl;
        }
    }

    return 0;
}