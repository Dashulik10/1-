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
    cout << "��������: " << endl;
    cout << "1. �������� ����� " << endl;
    cout << "2. ���� ������ " << endl;
    cout << "3. ���������� ������ " << endl;
    cout << "4. �������� ������ " << endl;
    cout << "5. �������� ������ " << endl;
    cout << "6. �������� ����� " << endl;
    cout << "7. �������� ���������� " << endl;
    cout << "8. �������� ����� " << endl;
    cout << "9. �������� " << endl;
    cout << "10. �������(����� �� ��������) " << endl;
    cout << "11. ����� " << endl;

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
            cout << "������ ��� �������� �����" << endl;
        }
        fi.close();
        cout << "���� ������" << endl;
    }
    else {
        cout << "������ ��� �������� �����" << endl;
    }
}

void writeToFile() {
    int n, i;
    fi.open("file_n.txt", ios::out | ios::app);
    f.open("file.txt", ios::out | ios::app);
    if (f.is_open()) {
        cout << "������� ���������� �������: " << endl;
        cin >> n;
        for (i = 0; i < n; i++)
        {
        zavod zv;
        cout << "������� ������������: ";
        cin >> zv.name;
        cout << "������� ���������� �������: ";
        cin >> zv.kol_vo;
        cout << "������� ����� ����: ";
        cin >> zv.nomer;

        fi << zv.name << " " << zv.kol_vo << " " << zv.nomer << endl;

        f << "������������: " << zv.name << endl;
        f << "���������� �������: " << zv.kol_vo << endl;
        f << "����� ����: " << zv.nomer << endl;
        f << "----------------------------------------------------------------" << endl;
        }
        f.close();
        fi.close();
    }
    else {
        cout << "������ ��� �������� �����" << endl;
    }
}

void addInfo() {
    f.open("file.txt", ios::out | ios::app);
    fi.open("file_n.txt", ios::out | ios::app);
    if (f.is_open()) {
        zavod zv;
        cout << "������� name: ";
        cin >> zv.name;
        cout << "������� kol_vo: ";
        cin >> zv.kol_vo;
        cout << "������� nomer: ";
        cin >> zv.nomer;

        fi << zv.name << " " << zv.kol_vo << " " << zv.nomer << endl;

        f << "������������: " << zv.name << endl;
        f << "���������� �������: " << zv.kol_vo << endl;
        f << "����� ����: " << zv.nomer << endl;
        f << "----------------------------------------------------------------" << endl;

        f.close();
        fi.close();
    }
    else {
        cout << "������ ��� �������� �����" << endl;
    }
}

void deletel()
{
    ifstream fi("file_n.txt");
    ofstream f("file.txt");
    ofstream temp("temp.txt");

    if (!fi.is_open())
    {
        cout << "������ ��� �������� �����" << endl;
        return;
    }

    if (!f.is_open())
    {
        cout << "������ ��� �������� �����" << endl;
        return;
    }

    int fi_key;
    cout << "������� kol_vo: " << endl;
    cin >> fi_key;

    int kod = 0;
    zavod zv;
    while (fi >> zv.name >> zv.kol_vo >> zv.nomer)
    {
        if (zv.kol_vo == fi_key)
        {
            kod = 1;
            cout << "������� �������." << endl;
        }
        else
        {
            // ���������� ������ �� ��������� ����, �������� ��������� �������
            temp << zv.name << " " << zv.kol_vo << " " << zv.nomer << endl;

            f << "������������: " << zv.name << endl;
            f << "���������� �������: " << zv.kol_vo << endl;
            f << "����� ����: " << zv.nomer << endl;
            f << "----------------------------------------------------------------" << endl;
        }
    }

    fi.close();
    f.close();
    temp.close();

    // ������� �������� �����
    remove("file_n.txt");

    // �������� �������� ���� okno.txt ��������� ������ temp.txt
    rename("temp.txt", "file_n.txt");

    if (kod == 0)
    {
        cout << "�� ������� ���������� ���������� �������." << endl;
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
        cout << "������ ��� �������� �����" << endl;
    }
}

void linposhyk()
{
    ifstream fi;
    fi.open("file_n.txt", ios::in);
    if (!fi.is_open())
    {
        cout << "������ ��� �������� �����" << endl;
        return;
    }

    int fi_key;
    cout << "������� kol_vo: " << endl;
    cin >> fi_key;

    int kod = 0;
    zavod zv;
    while (fi >> zv.name >> zv.kol_vo >> zv.nomer)
    {
        if (zv.kol_vo == fi_key)
        {
            kod = 1;
            cout << "�������." << endl;
            cout << "������������: " << zv.name << endl;
            cout << "���������� �������: " << zv.kol_vo << endl;
            cout << "����� ����: " << zv.nomer << endl;
            cout << "���������������������-" << endl;
        }
    }

    if (kod == 0)
    {
        cout << "�� ������� ���������� ���������� �������." << endl;
    }

    fi.close();
}

void lineynaysortirovka() {
    fi.open("file_n.txt", ios::in);
    fl.open("Sorted.txt", ios::out | ios::trunc);
    if (!fi.is_open())
    {
        cout << "������ ��� �������� �����" << endl;
        return;
    }

    if (!fl.is_open())
    {
        cout << "������ ��� �������� �����" << endl;
        return;
    }

    vector<zavod> data;

    zavod zv;
    while (fi >> zv.name >> zv.kol_vo >> zv.nomer) {
        data.push_back(zv);
    }

    fi.close();

    // �������� ���������� �� ���� 'kol_vo'
    for (int i = 0; i < data.size() - 1; i++) {
        int m = i;
        for (int j = i + 1; j < data.size(); j++) {
            if (data[j].kol_vo < data[m].kol_vo) {
                m = j;
            }
        }

        // ����� ����������
        zavod temp = data[i];
        data[i] = data[m];
        data[m] = temp;
    }

    // ����� ��������������� ������ �� �������
    for (const auto& item : data) {
        cout << "������������: " << item.name << endl;
        cout << "���������� �������: " << item.kol_vo << endl;
        cout << "����� ����: " << item.nomer << endl;
        cout << "----------------------------------------------------------------" << endl;

        fl << "������������: " << item.name << endl;
        fl << "���������� �������: " << item.kol_vo << endl;
        fl << "����� ����: " << item.nomer << endl;
        fl << "----------------------------------------------------------------" << endl;
    }
    fl.close();
}

void reshenie() {
    fi.open("file_n.txt", ios::in);
    fr.open("Reshenie.txt", ios::out | ios::trunc);
    if (!fi.is_open())
    {
        cout << "������ ��� �������� �����" << endl;
        return;
    }

    if (!fr.is_open())
    {
        cout << "������ ��� �������� �����" << endl;
        return;
    }

    vector<zavod> data;

    zavod zv;
    while (fi >> zv.name >> zv.kol_vo >> zv.nomer) {
        data.push_back(zv);
    }

    fi.close();

    // �������� ���������� �� ���� 'kol_vo' � ��������� �������
    for (int i = 0; i < data.size() - 1; i++) {
        int m = i;
        for (int j = i + 1; j < data.size(); j++) {
            if (data[j].kol_vo > data[m].kol_vo) {  // ���������� ������� ���������
                m = j;
            }
        }

        // ����� ����������
        zavod temp = data[i];
        data[i] = data[m];
        data[m] = temp;
    }

    // ����� ��������������� ������ �� �������
    for (const auto& item : data) {
        cout << "������������: " << item.name << endl;
        cout << "���������� �������: " << item.kol_vo << endl;
        cout << "����� ����: " << item.nomer << endl;
        cout << "----------------------------------------------------------------" << endl;

        fr << "������������: " << item.name << endl;
        fr << "���������� �������: " << item.kol_vo << endl;
        fr << "����� ����: " << item.nomer << endl;
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
    fq.open("Quicksort.txt", ios::out | ios::trunc);  // ���������� ����� ios::trunc
    if (!fi.is_open())
    {
        cout << "������ ��� �������� �����" << endl;
        return;
    }

    if (!fi.is_open())
    {
        cout << "������ ��� �������� �����" << endl;
        return;
    }

    if (!fq.is_open())
    {
        cout << "������ ��� �������� �����" << endl;
        return;
    }

    zavod data[30];
    int n = 0;

    while (fi >> data[n].name >> data[n].kol_vo >> data[n].nomer) {
        n++;
    }
    fi.close();
    quicksort(data, 0, n - 1);
    // ����� ��������������� ������ �� �������
    for (int i = 0; i < n; i++) {
        cout << "������������: " << data[i].name << endl;
        cout << "���������� �������: " << data[i].kol_vo << endl;
        cout << "����� ����: " << data[i].nomer << endl;
        cout << "----------------------------------------------------------------" << endl;

        fq << "������������: " << data[i].name << endl;
        fq << "���������� �������: " << data[i].kol_vo << endl;
        fq << "����� ����: " << data[i].nomer << endl;
        fq << "----------------------------------------------------------------" << endl;
    }
    fq.close();

    cout << "���������� ���������. ��������������� ������ �������� � ���� Quick.txt." << endl;
}



void binaryposhyk()
{
    ifstream fi;
    fi.open("file_n.txt", ios::in);
    if (!fi.is_open())
    {
        cout << "������ ��� �������� �����" << endl;
        return;
    }

    vector<zavod> data; // ������ ��� �������� ������ �� �����
    zavod zv;
    while (fi >> zv.name >> zv.kol_vo >> zv.nomer)
    {
        data.push_back(zv); // ���������� ������� ������� �� �����
    }

    fi.close();

    sort(data.begin(), data.end(), [](const zavod& a, const zavod& b) {
        return a.kol_vo < b.kol_vo; // ���������� �� ���������� �������
        });

    int fi_key;
    cout << "������� kol_vo: " << endl;
    cin >> fi_key;

    bool found = false;

    for (const auto& item : data)
    {
        if (item.kol_vo == fi_key)
        {
            found = true;
            cout << "������������: " << item.name << endl;
            cout << "���������� �������: " << item.kol_vo << endl;
            cout << "����� ����: " << item.nomer << endl;
            cout << "----------------------------------------------------------------" << endl;
        }
    }

    if (!found)
    {
        cout << "�� ������� ���������� ���������� �������." << endl;
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
        default:cout << "�������� �����" << endl;
        }

        puts("Press any key to continue");
        system("pause"); system("cls");

    }


    return 0;
}