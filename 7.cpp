#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// Функция для загрузки матриц из файла
vector<vector<vector<int>>> loadMatricesFromFile(const string& filename) {
    ifstream file(filename);
    vector<vector<vector<int>>> matrices;
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line.find("Matrix") != string::npos) {
                vector<vector<int>> matrix;
                while (getline(file, line) && !line.empty()) {
                    stringstream ss(line);
                    vector<int> row;
                    int num;
                    while (ss >> num) {
                        row.push_back(num);
                    }
                    matrix.push_back(row);
                }
                matrices.push_back(matrix);
            }
        }
        file.close();
    }
    return matrices;
}

// Функция для сохранения матриц в файл
void saveMatricesToFile(const string& filename, const vector<vector<vector<int>>>& matrices) {
    ofstream file(filename);
    if (file.is_open()) {
        for (size_t i = 0; i < matrices.size(); ++i) {
            file << "Matrix " << i + 1 << ":\n";
            for (const auto& row : matrices[i]) {
                for (int num : row) {
                    file << num << " ";
                }
                file << "\n";
            }
            file << "\n";
        }
        file.close();
    }
}

// Функция для обмена матриц между списками матриц
void swapMatrices(vector<vector<vector<int>>>& matrices1, vector<vector<vector<int>>>& matrices2) {
    size_t minLen = min(matrices1.size(), matrices2.size());
    for (size_t i = 0; i < minLen; ++i) {
        swap(matrices1[i], matrices2[i]);
    }
}

// Функция для вывода матриц
void printMatrices(const vector<vector<vector<int>>>& matrices) {
    for (size_t i = 0; i < matrices.size(); ++i) {
        cout << "Matrix " << i + 1 << ":\n";
        for (const auto& row : matrices[i]) {
            for (int num : row) {
                cout << num << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    const string file1 = "file1.txt";
    const string file2 = "file2.txt";

    // Загрузка матриц из файлов
    vector<vector<vector<int>>> matrices1 = loadMatricesFromFile(file1);
    vector<vector<vector<int>>> matrices2 = loadMatricesFromFile(file2);

    cout << "Содержимое первого файла до замены:\n";
    printMatrices(matrices1);

    cout << "\nСодержимое второго файла до замены:\n";
    printMatrices(matrices2);

    // Обмен матриц между списками матриц
    swapMatrices(matrices1, matrices2);


    cout << "\nСодержимое первого файла после замены:\n";
    printMatrices(matrices1);

    cout << "\nСодержимое второго файла после замены:\n";
    printMatrices(matrices2);

    return 0;
}
