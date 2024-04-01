#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream file("a.txt"); // Открываем файл для чтения
    if (!file.is_open()) {
        std::cout << "Не удалось открыть файл." << std::endl;
        return 1;
    }

    std::vector<double> numbers;
    double num;
    while (file >> num) {
        numbers.push_back(num);
    }

    file.close(); // Закрываем файл

    int positiveCount = 0;
    int negativeCount = 0;

    for (double number : numbers) {
        if (number > 0) {
            positiveCount++;
        }
        else if (number < 0) {
            negativeCount++;
        }
    }

    std::cout << "Количество положительных элементов: " << positiveCount << std::endl;
    std::cout << "Количество отрицательных элементов: " << negativeCount << std::endl;

    return 0;
}
