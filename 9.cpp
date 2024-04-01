#include <iostream>
#include <fstream>

int main() {
    setlocale(LC_ALL, "Russian");
    char ch;
    std::ofstream outputFile("input.bin", std::ios::binary);

    // Проверка, удалось ли открыть файл для записи
    if (!outputFile.is_open()) {
        std::cerr << "Ошибка открытия файла для записи." << std::endl;
        return 1;
    }

    // Ввод символов с клавиатуры и запись в бинарный файл
    std::cout << "Введите символы английского алфавита (Ctrl+Z для завершения ввода):\n";
    while (std::cin >> ch) {
        outputFile.write(&ch, sizeof(ch));
    }

    outputFile.close();

    // Открытие файла для чтения и перезапись символов
    std::ifstream inputFile("input.bin", std::ios::binary);
    std::ofstream tempFile("temp.bin", std::ios::binary);

    // Проверка, удалось ли открыть файлы для чтения и записи
    if (!inputFile.is_open() || !tempFile.is_open()) {
        std::cerr << "Ошибка открытия файлов." << std::endl;
        return 1;
    }

    // Переписать бинарный файл, заменяя символы 'f' или 'F' на 'd'
    while (inputFile.read(&ch, sizeof(ch))) {
        if (ch == 'f' || ch == 'F') {
            ch = 'd';
        }
        tempFile.write(&ch, sizeof(ch));
    }

    inputFile.close();
    tempFile.close();

    // Открытие временного файла для чтения и печать символов до изменения
    std::ifstream tempFileRead("temp.bin", std::ios::binary);

    // Проверка, удалось ли открыть временный файл для чтения
    if (!tempFileRead.is_open()) {
        std::cerr << "Ошибка открытия временного файла." << std::endl;
        return 1;
    }

    std::cout << "Символы после изменения в файле:\n";
    while (tempFileRead.read(&ch, sizeof(ch))) {
        std::cout << ch;
    }
    std::cout << std::endl;

    tempFileRead.close();
    return 0;
}
