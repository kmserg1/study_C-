#include <iostream>
#include "constants.h"

double calculateHeight(double initialHeight, int seconds) {
    double distanceFallen = (constants::gravity * seconds * seconds) / 2;
    double currentHeight = initialHeight - distanceFallen;

    return currentHeight;
}

void hout(double height, int time) {
    if (height > 0.0) {
    std::cout << "Через "<< time << " секуд мяч будет на высоте " << height << "м." << std::endl;
    } else {
        std::cout << "Через "<< time << " секуд мяч будет на земле" << std::endl;
    }
}

int main() {
    std::cout << "Введите начальную высоту в метрах" << std::endl;
    double initialHeight;
    std::cin >> initialHeight;
    int time(0);
    hout(calculateHeight(initialHeight, time), time);
    time = 1;
    hout(calculateHeight(initialHeight, time), time);
    time = 2;
    hout(calculateHeight(initialHeight, time), time);
    time = 3;
    hout(calculateHeight(initialHeight, time), time);
    time = 4;
    hout(calculateHeight(initialHeight, time), time);
    time = 5;
    hout(calculateHeight(initialHeight, time), time);
    return 0;
}