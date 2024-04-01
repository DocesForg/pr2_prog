#include <iostream>
#include <fstream>
#include <cctype> // Библиотека для работы с символами

int main() {
    // Создаем файл для записи с автоматическим созданием или перезаписью
    std::ofstream outputFile("output.txt", std::ios::trunc);
    if (!outputFile.is_open()) {
        std::cout << "Не удалось создать/открыть файл для записи." << std::endl;
        return 1;
    }

    // Открываем исходный файл для чтения
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cout << "Не удалось открыть файл для чтения." << std::endl;
        return 1;
    }

    char ch;
    while (inputFile.get(ch)) {
        // Проверяем, является ли символ буквой
        if (isalpha(ch)) {
            outputFile << '*'; // Заменяем букву на '*'
        }
        else {
            outputFile << ch; // Записываем остальные символы без изменений
        }
    }

    std::cout << "Успешно заменены все буквы на '*' и записаны в новый файл output.txt." << std::endl;

    // Закрываем файлы
    inputFile.close();
    outputFile.close();

    return 0;
}
