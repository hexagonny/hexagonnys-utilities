#include "hutils.h"

#include <iostream>
#include <iomanip>
#include <algorithm>

constexpr int BAR_LENGTH = 40;

namespace hUtils {
    Bar bar;
    
    void Bar::printBar(double value, double maxPoints, int filledColor, int emptyColor)
    {
        double percentage = value / maxPoints;
        int filled = static_cast<int>(percentage * BAR_LENGTH);
        int empty = BAR_LENGTH - filled;

        std::cout << "\033[38;5;" + std::to_string(filledColor) + "m";
        for (int i = 0; i < filled; ++i) {
            std::cout << "█";
        }
        std::cout << "\033[0m";

        std::cout << "\033[38;5;" + std::to_string(emptyColor) + "m";
        for (int i = 0; i < empty; ++i) {
            std::cout << "▒";
        }
        std::cout << "\033[0m";

        std::cout << "\n";
        std::cout << std::fixed << std::setprecision(1);
        hUtils::text.toCentered(hUtils::text.toStr(percentage * 100, 1) + "/100.0 % ("
                                + hUtils::text.toStr(value, 1) + "/" + hUtils::text.toStr(value, 1) + ")\n");
    }

    void Bar::setBar(double value, double maxPoints, int filledColor, int emptyColor)
    {
        value = std::clamp(value, 0.0, maxPoints);
        printBar(value, maxPoints, filledColor, emptyColor);
        sleep(200);
    }
}