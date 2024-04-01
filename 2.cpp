#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream inputFile("a.txt"); // Открываем файл для чтения
    if (!inputFile.is_open()) {
        std::cout << "Не удалось открыть файл a.txt." << std::endl;
        return 1;
    }

    std::ofstream outputFile("a2.txt"); // Открываем файл для записи
    if (!outputFile.is_open()) {
        std::cout << "Не удалось открыть файл a2.txt." << std::endl;
        return 1;
    }

    double num;
    while (inputFile >> num) {
        if (num > 0) {
            outputFile << num * 5 << std::endl; // Пишем в новый файл умноженные на 5 положительные числа
        }
    }

    std::cout << "Успешно записаны в файл a2.txt положительные элементы файла a.txt, умноженные на 5." << std::endl;

    inputFile.close(); // Закрываем файл a.txt
    outputFile.close(); // Закрываем файл a2.txt

    return 0;
}
