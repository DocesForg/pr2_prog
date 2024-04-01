
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <locale.h>
#include <Windows.h>
#include <iomanip>


using namespace std;
struct internet
{
    int zaplatil, zaplatilvpered, j; float stoimost;
    char FIO[100];
};

int n, i;
internet* g;
using namespace std;



int func1()
{

    int n = 0, size = sizeof(internet);
    FILE* fp;

    cout << "Введите колличество клиентов =";
    cin >> n;
    g = new internet[n];
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    fp = fopen("D:\\klient.dat", "wb");
    cout << "Введите стоимость оплаты услуг кабельной сети за месяц: ";
    cin >> g[0].stoimost;

    for (i = 1; i < n; i++)
    {
        g[i].stoimost = g[0].stoimost;
    }

    for (i = 0; i < n; i++)
    {
        g[i].j = i + 1;
        cout << "__________________________________________________________" << endl;
        cout << "Введите фамилию, имя и отчество " << i + 1 << " клиента кабельной сети: ";
        cin.ignore();
        cin.getline(g[i].FIO, 100);
        cout << "Количество месяцев, за которые заплатил " << i + 1 << " клиент: ";
        cin >> g[i].zaplatil;
        cout << "Количество месяцев, за которые клиент " << i + 1 << " хочет заплатить вперёд: ";
        cin >> g[i].zaplatilvpered;
        cout << "_________________________________________________________/" << endl;
        fwrite((char*)&g, size, n, fp);
    }
    fclose(fp);
    fp = fopen("D:\\klient.dat", "rb");
    if (fp == NULL)
    {
        cout << "Не удалось открыть файл" << endl;
        return 0;
    }
    cout << endl;

    for (i = 0; i < n; i++)
    {
        fread((char*)&g, n, size, fp);
        cout << g[i].j << " " << g[i].FIO << " " << g[i].stoimost << " " << g[i].zaplatil << " " << g[i].zaplatilvpered << endl;
    }
    fclose(fp);
    cout << endl;
    cout << "После изменений...";

    for (i = 0; i < n; i++)
        if (g[i].zaplatilvpered > 3)
            g[i].stoimost *= 0.95;

    fp = fopen("D:\\klient.dat", "wb");
    if (fp == NULL)
    {
        cout << "Не удалось окрыть файл" << endl;
        return 0;
    }
    fwrite((char*)&g, size, n, fp);
    fclose(fp);

    cout << endl;
    cout << "Если клиент хочет заплатить вперед больше, чем за 3 месяца, то стоимость услуг кабельной сети будет снижена на 5% " << endl;
    fp = fopen("D:\\klient.dat", "rb");
    for (i = 0; i < n; i++)
    {
        cout << setprecision(0) << fixed << g[i].j << " " << g[i].FIO;
        cout << setprecision(2) << fixed << " " << g[i].stoimost;
        cout << setprecision(0) << fixed << " " << g[i].zaplatil << " " << g[i].zaplatilvpered << endl;

    }
    fclose(fp);
    cout << "ИНФОРМАЦИЯ ЗАПИСАНА В БИНАРНЫЙ ФАЙЛ" << endl;

    system("pause");
    return 0;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    func1();
    char choise;

}