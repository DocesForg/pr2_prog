#include <iostream>
#include <fstream>
#include <climits>

int main() {
    setlocale(LC_ALL, "Russian");
    std::ifstream inputFile("a.txt");
    if (!inputFile.is_open()) {
        std::cout << "Не удалось открыть файл для чтения." << std::endl;
        return 1;
    }

    int number;
    int minPositive = INT_MAX;
    int position = 1;

    while (inputFile >> number) {
        if (position % 2 != 0 && number > 0 && number < minPositive) {
            minPositive = number;
        }
        position++;
    }

    inputFile.close();

    if (minPositive == INT_MAX) {
        std::cout << "В файле нет положительных чисел на нечетных позициях." << std::endl;
    }
    else {
        std::cout << "Наименьший положительный компонент на нечетной позиции: " << minPositive << std::endl;
    }

    return 0;
}
