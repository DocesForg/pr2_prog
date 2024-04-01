#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Структура для хранения информации о компьютере
struct Computer {
    string name;
    double cpuFrequency;
    double ramSize;
    double hddSize;
    string monitorType;
    double monitorSize;
    double price;
};

int main() {
    setlocale(LC_ALL, "Russian");
    // Создаем массив из 3 компьютеров
    Computer computers[3] = {
        {"Computer1", 3.2, 4, 1000, "LCD", 23, 500},
        {"Computer2", 2.8, 8, 500, "LED", 21, 700},
        {"Computer3", 3.5, 16, 2000, "OLED", 27, 1000}
    };

    // Открываем файл для записи в бинарном формате
    ofstream file("computers.dat", ios::binary);

    // Записываем информацию о компьютерах в файл
    file.write(reinterpret_cast<char*>(&computers), sizeof(computers));

    // Закрываем файл
    file.close();

    // Открываем файл для чтения
    ifstream inFile("computers.dat", ios::binary);

    // Создаем переменную для хранения информации о компьютере с наибольшей производительностью
    Computer maxPerformanceComputer = { "", 0, 0, 0, "", 0, 0 };

    // Читаем информацию о компьютерах из файла
    for (int i = 0; i < 3; i++) {
        Computer tempComputer;
        inFile.read(reinterpret_cast<char*>(&tempComputer), sizeof(Computer));

        // Проверяем, удовлетворяет ли компьютер условиям наибольшей производительности
        if (tempComputer.cpuFrequency > maxPerformanceComputer.cpuFrequency && tempComputer.ramSize >= 2) {
            maxPerformanceComputer = tempComputer;
        }
    }

    // Выводим информацию о компьютере с наибольшей производительностью
    cout << "Компьютер с наибольшей производительностью:" << endl;
    cout << "Название: " << maxPerformanceComputer.name << endl;
    cout << "Частота CPU: " << maxPerformanceComputer.cpuFrequency << " GHz" << endl;
    cout << "Размер RAM памяти: " << maxPerformanceComputer.ramSize << " GB" << endl;
    cout << "Объем HDD: " << maxPerformanceComputer.hddSize << " GB" << endl;
    cout << "Тип монитора: " << maxPerformanceComputer.monitorType << endl;
    cout << "Размер монитора: " << maxPerformanceComputer.monitorSize << " inches" << endl;
    cout << "Цена: $" << maxPerformanceComputer.price << endl;

    // Закрываем файл
    inFile.close();

    return 0;
}