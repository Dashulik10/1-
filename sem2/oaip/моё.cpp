#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <Windows.h>


using namespace std;

struct zavod {
    string name;
    int kol_vo;
    int nomer;
};

fstream f, fi, fl, fq, fr;

int menu()

{
    cout << "Выберите: " << endl;
    cout << "1. Создание файла " << endl;
    cout << "2. Ввод данных " << endl;
    cout << "3. Добавление данных " << endl;
    cout << "4. Удаление данных " << endl;
    cout << "5. Просмотр данных " << endl;
    cout << "6. Линейный поиск " << endl;
    cout << "7. Линейная сортировка " << endl;
    cout << "8. Бинарный поиск " << endl;
    cout << "9. Квиксорт " << endl;
    cout << "10. Решение(вывод по убыванию) " << endl;
    cout << "11. Выход " << endl;

    int i;
    cin >> i;
    return i;

}

void createFile() {
    fi.open("file_n.txt", ios::out | ios::app);
    fl.open("Sorted.txt", ios::out | ios::app);
    fr.open("Reshenie.txt", ios::out | ios::app);
    f.open("file.txt", ios::out);
    fq.open("Quicksort.txt", ios::out | ios::app);
    if (fi.is_open()) {
        if (f.is_open()) {
            f.close();
        }
        else {
            cout << "Ошибка при создании файла" << endl;
        }
        fi.close();
        cout << "Файл создан" << endl;
    }
    else {
        cout << "Ошибка при создании файла" << endl;
    }
}

void writeToFile() {
    int n, i;
    fi.open("file_n.txt", ios::out | ios::app);
    f.open("file.txt", ios::out | ios::app);
    if (f.is_open()) {
        cout << "Введите количество изделий: " << endl;
        cin >> n;
        for (i = 0; i < n; i++)
        {
        zavod zv;
        cout << "Введите наименование: ";
        cin >> zv.name;
        cout << "Введите количество деталей: ";
        cin >> zv.kol_vo;
        cout << "Введите номер цеха: ";
        cin >> zv.nomer;

        fi << zv.name << " " << zv.kol_vo << " " << zv.nomer << endl;

        f << "Наименование: " << zv.name << endl;
        f << "Количество деталей: " << zv.kol_vo << endl;
        f << "номер цеха: " << zv.nomer << endl;
        f << "----------------------------------------------------------------" << endl;
        }
        f.close();
        fi.close();
    }
    else {
        cout << "Ошибка при открытии файла" << endl;
    }
}

void addInfo() {
    f.open("file.txt", ios::out | ios::app);
    fi.open("file_n.txt", ios::out | ios::app);
    if (f.is_open()) {
        zavod zv;
        cout << "Введите name: ";
        cin >> zv.name;
        cout << "Введите kol_vo: ";
        cin >> zv.kol_vo;
        cout << "Введите nomer: ";
        cin >> zv.nomer;

        fi << zv.name << " " << zv.kol_vo << " " << zv.nomer << endl;

        f << "Наименование: " << zv.name << endl;
        f << "Количество деталей: " << zv.kol_vo << endl;
        f << "Номер цеха: " << zv.nomer << endl;
        f << "----------------------------------------------------------------" << endl;

        f.close();
        fi.close();
    }
    else {
        cout << "Ошибка при открытии файла" << endl;
    }
}

void deletel()
{
    ifstream fi("file_n.txt");
    ofstream f("file.txt");
    ofstream temp("temp.txt");

    if (!fi.is_open())
    {
        cout << "Ошибка при открытии файла" << endl;
        return;
    }

    if (!f.is_open())
    {
        cout << "Ошибка при открытии файла" << endl;
        return;
    }

    int fi_key;
    cout << "Введите kol_vo: " << endl;
    cin >> fi_key;

    int kod = 0;
    zavod zv;
    while (fi >> zv.name >> zv.kol_vo >> zv.nomer)
    {
        if (zv.kol_vo == fi_key)
        {
            kod = 1;
            cout << "Позиция удалена." << endl;
        }
        else
        {
            // Записываем данные во временный файл, исключая удаляемую позицию
            temp << zv.name << " " << zv.kol_vo << " " << zv.nomer << endl;

            f << "Наименование: " << zv.name << endl;
            f << "Количество деталей: " << zv.kol_vo << endl;
            f << "Номер цеха: " << zv.nomer << endl;
            f << "----------------------------------------------------------------" << endl;
        }
    }

    fi.close();
    f.close();
    temp.close();

    // Удаляем исходные файлы
    remove("file_n.txt");

    // Заменяем исходный файл okno.txt временным файлом temp.txt
    rename("temp.txt", "file_n.txt");

    if (kod == 0)
    {
        cout << "Не найдено введенного количества изделий." << endl;
    }
}


void viewInfo() {
    ifstream inFile("file.txt");
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }
    else {
        cout << "Ошибка при открытии файла" << endl;
    }
}

void linposhyk()
{
    ifstream fi;
    fi.open("file_n.txt", ios::in);
    if (!fi.is_open())
    {
        cout << "Ошибка при открытии файла" << endl;
        return;
    }

    int fi_key;
    cout << "Введите kol_vo: " << endl;
    cin >> fi_key;

    int kod = 0;
    zavod zv;
    while (fi >> zv.name >> zv.kol_vo >> zv.nomer)
    {
        if (zv.kol_vo == fi_key)
        {
            kod = 1;
            cout << "Найдено." << endl;
            cout << "Наименование: " << zv.name << endl;
            cout << "Количество изделий: " << zv.kol_vo << endl;
            cout << "Номер цеха: " << zv.nomer << endl;
            cout << "—————————————————————-" << endl;
        }
    }

    if (kod == 0)
    {
        cout << "Не найдено введенного количества изделий." << endl;
    }

    fi.close();
}

void lineynaysortirovka() {
    fi.open("file_n.txt", ios::in);
    fl.open("Sorted.txt", ios::out | ios::trunc);
    if (!fi.is_open())
    {
        cout << "Ошибка при открытии файла" << endl;
        return;
    }

    if (!fl.is_open())
    {
        cout << "Ошибка при открытии файла" << endl;
        return;
    }

    vector<zavod> data;

    zavod zv;
    while (fi >> zv.name >> zv.kol_vo >> zv.nomer) {
        data.push_back(zv);
    }

    fi.close();

    // Линейная сортировка по полю 'kol_vo'
    for (int i = 0; i < data.size() - 1; i++) {
        int m = i;
        for (int j = i + 1; j < data.size(); j++) {
            if (data[j].kol_vo < data[m].kol_vo) {
                m = j;
            }
        }

        // Обмен значениями
        zavod temp = data[i];
        data[i] = data[m];
        data[m] = temp;
    }

    // Вывод отсортированных данных на консоль
    for (const auto& item : data) {
        cout << "Наименование: " << item.name << endl;
        cout << "Количество деталей: " << item.kol_vo << endl;
        cout << "Номер цеха: " << item.nomer << endl;
        cout << "----------------------------------------------------------------" << endl;

        fl << "Наименование: " << item.name << endl;
        fl << "Количество деталей: " << item.kol_vo << endl;
        fl << "Номер цеха: " << item.nomer << endl;
        fl << "----------------------------------------------------------------" << endl;
    }
    fl.close();
}

void reshenie() {
    fi.open("file_n.txt", ios::in);
    fr.open("Reshenie.txt", ios::out | ios::trunc);
    if (!fi.is_open())
    {
        cout << "Ошибка при открытии файла" << endl;
        return;
    }

    if (!fr.is_open())
    {
        cout << "Ошибка при открытии файла" << endl;
        return;
    }

    vector<zavod> data;

    zavod zv;
    while (fi >> zv.name >> zv.kol_vo >> zv.nomer) {
        data.push_back(zv);
    }

    fi.close();

    // Линейная сортировка по полю 'kol_vo' в убывающем порядке
    for (int i = 0; i < data.size() - 1; i++) {
        int m = i;
        for (int j = i + 1; j < data.size(); j++) {
            if (data[j].kol_vo > data[m].kol_vo) {  // Измененное условие сравнения
                m = j;
            }
        }

        // Обмен значениями
        zavod temp = data[i];
        data[i] = data[m];
        data[m] = temp;
    }

    // Вывод отсортированных данных на консоль
    for (const auto& item : data) {
        cout << "Наименование: " << item.name << endl;
        cout << "Количество деталей: " << item.kol_vo << endl;
        cout << "Номер цеха: " << item.nomer << endl;
        cout << "----------------------------------------------------------------" << endl;

        fr << "Наименование: " << item.name << endl;
        fr << "Количество деталей: " << item.kol_vo << endl;
        fr << "Номер цеха: " << item.nomer << endl;
        fr << "----------------------------------------------------------------" << endl;
    }
    fr.close();
}



void quicksort(zavod zv[30], int l, int r)
{
    int l_h = l;
    int r_h = r;
    int take, take3;
    char take2[50];
    take = zv[l].kol_vo;
    take3 = zv[l].nomer;
    strcpy_s(take2, sizeof(take2), zv[l].name.c_str());
    while (l < r)
    {
        while ((zv[r].kol_vo > take) && (l < r))
            r--;
        if (l != r)
        {
            zv[l] = zv[r];
            l++;
        }

        while ((zv[l].kol_vo < take) && (l < r))
            l++;
        if (l != r)
        {
            zv[r] = zv[l];
            r--;
        }
    }

    zv[l].kol_vo = take;
    zv[l].nomer = take3;
    zv[l].name = take2;
    take = l;
    if (l_h < take)
        quicksort(zv, l_h, take - 1);
    if (r_h > take)
        quicksort(zv, take + 1, r_h);
}

void qssf(){
    fi.open("file_n.txt", ios::in);
    fq.open("Quicksort.txt", ios::out | ios::trunc);  // Используем режим ios::trunc
    if (!fi.is_open())
    {
        cout << "Ошибка при открытии файла" << endl;
        return;
    }

    if (!fi.is_open())
    {
        cout << "Ошибка при открытии файла" << endl;
        return;
    }

    if (!fq.is_open())
    {
        cout << "Ошибка при открытии файла" << endl;
        return;
    }

    zavod data[30];
    int n = 0;

    while (fi >> data[n].name >> data[n].kol_vo >> data[n].nomer) {
        n++;
    }
    fi.close();
    quicksort(data, 0, n - 1);
    // Вывод отсортированных данных на консоль
    for (int i = 0; i < n; i++) {
        cout << "Наименование: " << data[i].name << endl;
        cout << "Количество деталей: " << data[i].kol_vo << endl;
        cout << "Номер цеха: " << data[i].nomer << endl;
        cout << "----------------------------------------------------------------" << endl;

        fq << "Наименование: " << data[i].name << endl;
        fq << "Количество деталей: " << data[i].kol_vo << endl;
        fq << "Номер цеха: " << data[i].nomer << endl;
        fq << "----------------------------------------------------------------" << endl;
    }
    fq.close();

    cout << "Сортировка завершена. Отсортированные данные записаны в файл Quick.txt." << endl;
}



void binaryposhyk()
{
    ifstream fi;
    fi.open("file_n.txt", ios::in);
    if (!fi.is_open())
    {
        cout << "Ошибка при открытии файла" << endl;
        return;
    }

    vector<zavod> data; // Вектор для хранения данных из файла
    zavod zv;
    while (fi >> zv.name >> zv.kol_vo >> zv.nomer)
    {
        data.push_back(zv); // Заполнение вектора данными из файла
    }

    fi.close();

    sort(data.begin(), data.end(), [](const zavod& a, const zavod& b) {
        return a.kol_vo < b.kol_vo; // Сортировка по количеству изделий
        });

    int fi_key;
    cout << "Введите kol_vo: " << endl;
    cin >> fi_key;

    bool found = false;

    for (const auto& item : data)
    {
        if (item.kol_vo == fi_key)
        {
            found = true;
            cout << "Наименование: " << item.name << endl;
            cout << "Количество изделий: " << item.kol_vo << endl;
            cout << "Номер цеха: " << item.nomer << endl;
            cout << "----------------------------------------------------------------" << endl;
        }
    }

    if (!found)
    {
        cout << "Не найдено введенного количества изделий." << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RU");
    while (true)
    {
        switch (menu())
        {
        case 1: createFile(); break;
        case 2: writeToFile(); break;
        case 3: addInfo(); break;
        case 4: deletel(); break;
        case 5: viewInfo(); break;
        case 6: linposhyk(); break;
        case 7: lineynaysortirovka(); break;
        case 8: binaryposhyk(); break;
        case 9: qssf(); break;
        case 10: reshenie(); break;
        case 11: return 0;
        default:cout << "Неверный выбор" << endl;
        }

        puts("Press any key to continue");
        system("pause"); system("cls");

    }


    return 0;
}