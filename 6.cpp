#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    setlocale(LC_ALL, "Russian");
    std::ifstream file("f.txt"); // открываем файл для чтения
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
        return 1;
    }

    std::vector<double> numbers;
    double number;

    // считываем числа из файла в вектор
    while (file >> number) {
        numbers.push_back(number);
    }

    // если файл пустой, выводим ошибку и завершаем программу
    if (numbers.empty()) {
        std::cerr << "Файл пустой!" << std::endl;
        return 1;
    }

    // находим разность между первым и последним числом
    double difference = numbers.front() - numbers.back();

    // выводим результат
    std::cout << "Разность первой и последней компонент файла: " << difference << std::endl;

    return 0;
}
