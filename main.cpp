#include <iostream>

#include "include/DayOne.h"
#include "include/DayTwo.h"
#include "include/DayThree.h"
#include "include/DayFour.h"
#include "include/DayFive.h"
#include "include/DaySix.h"

static std::string DATA_PATH{"/Users/sebastiangluszak/Dev/AdventOfCode2025/data/"};

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
            Lock northPoleLock(DATA_PATH + "DayOneInputPartOne.txt", true);
            northPoleLock.execute();
            std::cout << "The password to open the door is: " << northPoleLock.getPassword() << std::endl;
        } else if (part == 2) {
            Lock northPoleLock(DATA_PATH + "DayOneInputPartTwo.txt", false);
            northPoleLock.execute();
            std::cout << "The password to open the door is: " << northPoleLock.getPassword() << std::endl;
        }
    } else if (day == 2) {
        GiftShop giftShop(DATA_PATH + "DayTwoInput.txt");
        if (part == 1) {
            std::cout << "The invalid ID score is: " << giftShop.getInvalidIDScorePart1() << std::endl;
        } else if (part == 2) {
            std::cout << "The invalid ID score is: " << giftShop.getInvalidIDScorePart2() << std::endl;
        }
    } else if (day == 3) {
        PowerSupply powerSupply(DATA_PATH + "DayThreeInput.txt");
        if (part == 1) {
            std::cout << "The total joltage is: " << powerSupply.getTotalJoltagePart1() << std::endl;
        } else if (part == 2) {
            std::cout << "The total joltage is: " << powerSupply.getTotalJoltagePart2() << std::endl;
        }
    } else if (day == 4) {
        PrintingDepartment printingDepartment(DATA_PATH + "DayFourInput.txt");
        if (part == 1) {
            std::cout << "The number of inaccessible paper rolls is: " << printingDepartment.getAccessiblePaperRolls() << std::endl;
        } else if (part == 2) {
            std::cout << "The number of paper rolls that can be removed is: " << printingDepartment.removePaperRolls() << std::endl;
        }
    } else if (day == 5) {
        Kitchen kitchen(DATA_PATH + "DayFiveInput.txt");
        if (part == 1) {
            std::cout << "The number of fresh ingredients is: " << kitchen.getFreshIngredientCount() << std::endl;
        }
        else if (part == 2) {
            std::cout << "The total sum of range lengths is: " << kitchen.getFreshIngredientRangeCount() << std::endl;
        }
    } else if (day == 6) {
        Homework homework(DATA_PATH + "DaySixInput.txt");
        if (part == 1) {
            std::cout << "The homework solution is: " << homework.solveHomework() << std::endl;
        }
        else if (part == 2) {
            std::cout << "The homework solution using cephalopod math is: " << homework.solveHomeworkCephalopod() << std::endl;
        }
    } else {
        std::cout << "~ Invalid day supplied! Enter an integer 1 - 12" << std::endl;
    }

    return 0;
}