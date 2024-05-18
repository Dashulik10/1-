#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <Windows.h>
#include <string>
using namespace std;

struct date {
	int year;
	int month;
	int day;
	int all_in_days;
};

struct product {
	string prod_name;
	int prod_count;
	double price;
	date get_prod;
};

void CreateFile(string&);
bool IsLeapYear(int);
int MaxDays(int, int);
date InputDate();
void ViewFile(string&);
void AddInfo(string&);
void LinearSearchName(string&);
void DirectSelectionSort(product[], int);
void DirectSelectionSortShow(string&);
int FirstNotDigit(string&);
void GetFileIntoStruct(string&, int&, product[]);
void StructIntoFileAndConsole(string&, int, product[]);
void QuickSort(int, int, product[]);
void QuickSortShow(string&);
int BinarySearchName(product[], int, int, string);
void BinarySearchShow(string&);
void SeeResult(string&);
void ChooseSortingMethod(int, product[]);
void ChooseFunction(string&);

void CreateFile(string& filename) {
	ofstream file(filename);
	if (file.is_open()) {
		file.close();
		cout << "Файл создан! " << filename << endl;
	}
	else {
		cout << "Ошибка!" << filename << "\n";
	}
};

bool IsLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int MaxDays(int year, int month) {
	switch (month) {
	case 2:
		return IsLeapYear(year) ? 29 : 28;
	case 4: case 6: case 9: case 11:
		return 30;
	default:
		return 31;
	}
}

date InputDate() {
	date input_date;
	do {
		cout << "Год: ";
		cin >> input_date.year;
	} while (input_date.year < 1900 || input_date.year>2024);
	do {
		cout << "Месяц: ";
		cin >> input_date.month;
	} while (input_date.month <= 0 || input_date.month > 12);

	int max_days = MaxDays(input_date.year, input_date.month);
	do {
		cout << "День: ";
		cin >> input_date.day;
	} while (input_date.day<1 || input_date.day>max_days);
	input_date.all_in_days = input_date.day + ((input_date.month - 1) * MaxDays(input_date.year, input_date.month)) + (input_date.year * (365 + IsLeapYear(input_date.year)));
	return input_date;
}

void ViewFile(string& filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "There is no such file!" << filename << endl;
		return;
	}
	cout << "\n\nFILE  " << filename << "  INSIDE\n\n";
	string line;
	while (getline(file, line)) {
		cout << line << endl;
	}
	file.close();
}

void AddInfo(string& filename) {


	ofstream file(filename, ios_base::app);
	if (!file.is_open()) {
		cout << "There is no such file, try to create it!\n";
		return;
	}
	else {
		int tov;
		cout << "Введите количество товаров, которые вы хотите добавить: ";
		cin >> tov;
		product* spisok = new product[tov];
		for (int i = 0; i < tov; i++) {
			cout << "----------------------------------------------------------------\n";
			cout << setw(15) << "Товар № " << i + 1 << endl;
			cout << setw(5) << "Введите название товара: ";
			cin >> spisok[i].prod_name;
			cout << setw(5) << "Введите кол-во единиц товара: ";
			cin >> spisok[i].prod_count;
			cout << setw(5) << "Введите единичную стоимость: ";
			cin >> spisok[i].price;
			cout << setw(5) << "Введите дату поступления товара: " << endl;
			spisok[i].get_prod = InputDate();

			file << "\n----------------------------------------------------------------\n";
			file << "\nНаименование: " << spisok[i].prod_name << endl;
			file << "Количество единиц: " << spisok[i].prod_count << endl;
			file << "Цена: " << spisok[i].price << endl;
			file << "Дата получения: " << spisok[i].get_prod.day << "." << spisok[i].get_prod.month << "." << spisok[i].get_prod.year << endl;
			file << "\n----------------------------------------------------------------\n";
		}
		file.close();
		delete[] spisok;
	}

}

void LinearSearchNameArray(string& filename) {
	string find_name;
	cout << "Введите наименование товара: ";
	cin >> find_name;

	ifstream file(filename);
	if (!file.is_open()) {
		cout << "Ошибка открытия файла :(\n";
		return;
	}

	string str;
	bool found_name = false;

	while (getline(file, str)) {
		if (str.find("Наименование: " + find_name) != string::npos) {
			found_name = true;
			cout << "\nТовар " << find_name << " имеется на складе!\n";
			cout << str << endl;
			for (int i = 0; i < 3; ++i) {
				getline(file, str);
				cout << str << endl;
			}
			break;
		}

	}
	if (!found_name) {
		cout << "На складе нет товара с таким наименованием!\n";
	}

	file.close();
}

void LinearSearchName(string& filename) {
	string find_name;
	cout << "Введите наименование товара : ";
	cin >> find_name;

	int products_amount = 0;
	product SKLAD[123];
	GetFileIntoStruct(filename, products_amount, SKLAD);

	bool found_n = false;
	for (int i = 0; i < products_amount; i++) {
		if (SKLAD[i].prod_name == find_name) {
			found_n = true;
			cout << "\nТовар " << find_name << " имеется на складе!\n";
			cout << "" << SKLAD[i].prod_name << endl;
			cout << "" << SKLAD[i].prod_count << endl;
			cout << "" << SKLAD[i].price << endl;
			cout << "" << SKLAD[i].get_prod.day << "." << SKLAD[i].get_prod.month << "." << SKLAD[i].get_prod.year << endl;
			break;
		}
		if (!found_n)
			cout << "На складе нет товара с таким наименованием!\n";
	}
}

void DirectSelectionSort(product SKLAD[], int products_amount) {
	int min;
	product t;
	for (int i = 0; i < products_amount; i++) {
		min = i;
		for (int j = i + 1; j < products_amount; j++) {
			if (SKLAD[j].prod_name < SKLAD[min].prod_name)
				min = j;
		}
		if (min == i)
			continue;
		t = SKLAD[i];
		SKLAD[i] = SKLAD[min];
		SKLAD[min] = t;
	}
}

void DirectSelectionSortShow(string& filename) {
	int products_amount = 0;
	product SKLAD[123];
	GetFileIntoStruct(filename, products_amount, SKLAD);
	DirectSelectionSort(SKLAD, products_amount);
	string q_result = "DirectSelectionSortResult.txt";
	StructIntoFileAndConsole(q_result, products_amount, SKLAD);
	delete[] SKLAD;
}

int FirstNotDigit(string& str) {
	for (int i = 0; i < str.size(); ++i) {
		if (!(str[i] >= '0' && str[i] <= '9'))
			return i;
	}
	return -1;
}

void GetFileIntoStruct(string& filename, int& products_amount, product SKLAD[]) {
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "Ошибка открытия файла :(\n";
		return;
	}
	string str;

	while (getline(file, str)) {
		if (str.find("Наименование: ") != string::npos)
			SKLAD[products_amount].prod_name = str.substr(14);

		if (str.find("Количество единиц: ") != string::npos) {
			string count_str = str.substr(19);
			int count_end = FirstNotDigit(count_str) - 1;
			if (count_end != -1) {
				count_str = count_str.substr(0, count_end);
				SKLAD[products_amount].prod_count = stoi(count_str);
			}

		}
		if (str.find("Цена: ") != string::npos) {
			string count_str = str.substr(6);
			int count_end = FirstNotDigit(count_str) - 1;
			if (count_end != -1) {
				count_str = count_str.substr(0, count_end);
				SKLAD[products_amount].price = stod(count_str);
			}
		}

		if (str.find("Дата получения: ") != string::npos) {
			string count_str = str.substr(16);
			int day_end = FirstNotDigit(count_str);
			if (day_end != -1) {
				string day_str = count_str.substr(0, day_end);
				SKLAD[products_amount].get_prod.day = stoi(day_str);
			}
			count_str = count_str.substr(day_end + 1);
			int month_end = FirstNotDigit(count_str);
			if (month_end != -1) {
				string month_str = count_str.substr(0, month_end);
				SKLAD[products_amount].get_prod.month = stoi(month_str);
			}
			count_str = count_str.substr(month_end + 1);
			string year_str = count_str.substr(0, 4);
			SKLAD[products_amount].get_prod.year = stoi(year_str);
			products_amount++;
		}
	}
	file.close();
}

void StructIntoFileAndConsole(string& filename, int products_amount, product SKLAD[]) {
	CreateFile(filename);
	ofstream result(filename);
	if (!result.is_open()) {
		cout << "Ошибка открытия файла с результатом \n";
		return;
	}
	else {
		cout << "\n----------------------------------------------------------------\n";
		result << "\n----------------------------------------------------------------\n";
		for (int i = 0; i < products_amount; i++) {
			cout << "\nНаименование: " << SKLAD[i].prod_name << endl;
			cout << "Количество единиц: " << SKLAD[i].prod_count << endl;
			cout << "Цена: " << SKLAD[i].price << endl;
			cout << "Дата получения: " << SKLAD[i].get_prod.day << "." << SKLAD[i].get_prod.month << "." << SKLAD[i].get_prod.year << endl;
			cout << "\n----------------------------------------------------------------\n";
			result << "\nНаименование: " << SKLAD[i].prod_name << endl;
			result << "Количество единиц: " << SKLAD[i].prod_count << endl;
			result << "Цена: " << SKLAD[i].price << endl;
			result << "Дата получения: " << SKLAD[i].get_prod.day << "." << SKLAD[i].get_prod.month << "." << SKLAD[i].get_prod.year << endl;
			result << "\n----------------------------------------------------------------\n";
		}
	}

	result.close();
}

void QuickSort(int left, int right, product SKLAD[]) {
	product t;
	int i = left;
	int j = right;
	string x = SKLAD[(left + right) / 2].prod_name;
	while (i <= j) {
		while (SKLAD[i].prod_name < x)
			i++;
		while (SKLAD[j].prod_name > x)
			j--;
		if (i <= j) {
			t = SKLAD[i];
			SKLAD[i] = SKLAD[j];
			SKLAD[j] = t;
			i++;
			j--;
		}
	}
	if (left < j)
		QuickSort(left, j, SKLAD);
	if (i < right)
		QuickSort(i, right, SKLAD);
}

void QuickSortShow(string& filename) {

	int products_amount = 0;
	product SKLAD[123];
	GetFileIntoStruct(filename, products_amount, SKLAD);

	int left = 0;
	int right = products_amount - 1;
	QuickSort(left, right, SKLAD);
	string q_result = "QuickSortResult.txt";
	StructIntoFileAndConsole(q_result, products_amount, SKLAD);
	delete[] SKLAD;
}

int BinarySearchName(product SKLAD[], int left, int right, string key) {
	int mid = 0;
	while (1) {
		mid = (left + right) / 2;
		if (key < SKLAD[mid].prod_name)
			right = mid - 1;
		else {
			if (key > SKLAD[mid].prod_name)
				left = mid + 1;
			else
				return mid;
		}
		if (left > right)
			return -1;
	}
}

void BinarySearchShow(string& filename) {
	int products_amount = 0;
	product SKLAD[123];
	GetFileIntoStruct(filename, products_amount, SKLAD);
	int left = 0;
	int right = products_amount - 1;
	QuickSort(left, right, SKLAD);

	string key;
	cout << "Введите наименование товара: ";
	cin >> key;
	int idx = BinarySearchName(SKLAD, left, right, key);
	if (idx == -1) {
		cout << "Такого товара нет на складе! " << endl;
		return;
	}
	else {
		cout << "Порядковый номер товара " << key << ": " << idx << endl;
		cout << "\nНаименование: " << SKLAD[idx].prod_name << endl;
		cout << "Количество единиц: " << SKLAD[idx].prod_count << endl;
		cout << "Цена: " << SKLAD[idx].price << endl;
		cout << "Дата получения: " << SKLAD[idx].get_prod.day << "." << SKLAD[idx].get_prod.month << "." << SKLAD[idx].get_prod.year << endl;
	}
	delete[] SKLAD;
}

void SeeResult(string& filename) {
	int products_amount = 0;
	product SKLAD[123];
	GetFileIntoStruct(filename, products_amount, SKLAD);


	ChooseSortingMethod(products_amount, SKLAD);
	cout << "----------------------------------------------------------------" << endl;
	cout << setw(5) << "Введите контрольную дату: " << endl;
	date curr_prod = InputDate();
	cout << setw(15) << "Контрольная дата: " << curr_prod.day << "." << curr_prod.month << "." << curr_prod.year << endl;
	int days = curr_prod.day + (curr_prod.month - 1) * 30 + curr_prod.year * 365;
	cout << "----------------------------------------------------------------" << endl;
	cout << setw(20) << "Результат: " << endl;
	product OTBOR[123];
	int ot_idx = 0;
	for (int i = 0; i < products_amount; i++) {
		if ((days - SKLAD[i].get_prod.all_in_days) > 30 && SKLAD[i].price > 100000) {
			OTBOR[ot_idx] = SKLAD[i];
			ot_idx++;
		}
	}
	string result = "Result.txt";
	StructIntoFileAndConsole(result, products_amount, OTBOR);
	delete[] OTBOR;
	delete[] SKLAD;
}

void ChooseSortingMethod(int products_amount, product SKLAD[]) {
	int choose;
M: cout << "Выберите метод сортировки: " << endl << setw(3) << "1 - Быстрая сортировка\n" << setw(3) << "2 - Сортировка методом прямого выбора\n";
	cin >> choose;
	int left = 0;
	int right = products_amount - 1;
	switch (choose) {
	case 1:

		QuickSort(left, right, SKLAD);
		break;
	case 2:
		DirectSelectionSort(SKLAD, products_amount);
	default: cout << "\nError!\n"; goto M;
	}
}

void ChooseFunction(string& filename) {
CF: cout << "Выберите, что вы хотите сделать: " << endl;
	int main_choose;
	cout << setw(3) << "1 - Работа с файлом\n" << setw(3) << "2 - Поиск в файле\n" << setw(3) << "3 - Сортировка\n ";
	cin >> main_choose;
	switch (main_choose) {
	case 1:
		int file_choose;
		cout << "Выберите,что вы хотите сделать с файлом:\n";
	m: cout << setw(3) << "1 - Создать файл\n" << setw(3) << "2 - Добавить в файл новую запись\n" << setw(3) << "3 - Просмотреть содержимое файла\n" << "4 - Вывести результат отбора товаров\n" << "5 - Exit\n";
		cin >> file_choose;
		switch (file_choose) {
		case 1:
			CreateFile(filename);
			break;
		case 2:
			AddInfo(filename);
			break;
		case 3:
			ViewFile(filename);
			break;
		default: cout << "Error"; goto m;
		}
		break; goto CF;
	case 2:
		cout << "Выберите метод поиска в файле:\n";
		int search_choose;
	s:cout << setw(3) << "1 - Линейный поиск\n" << setw(3) << "2 - Бинарный поиск\n";
		cin >> search_choose;
		switch (search_choose) {
		case 1:
			LinearSearchName(filename);
			break;
		case 2:
			BinarySearchShow(filename);
			break;
		default: cout << "Error"; goto s;
		}
		break;
		goto CF;
	case 3:
		int sort_choose;
		cout << "Выберите метод сортировки: " << endl;
	se: cout << setw(3) << "1 - Быстрая сортировка (метод )\n" << setw(3) << "2 - Метод сортировки прямого выбора\n";
		cin >> sort_choose;
		switch (sort_choose) {
		case 1:
			QuickSortShow(filename);
			break;
		case 2:
			DirectSelectionSortShow(filename);
			break;
		default: cout << "Error"; goto se;
		}
		break; goto CF;
	case 4:
		SeeResult(filename);
		break; goto CF;
	case 5:
		break;
	default: cout << "Error\n";
	}

}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	string filename = "file.txt";
	ChooseFunction(filename);

	//CreateFile(filename);
	//AddInfo(filename);
	/*ViewFile(filename);*/


	//LinearSearchName(filename);

	//DirectSelectionSort(filename);
	/*QuickSortShow(filename);*/
	/*BinarySearchShow(filename);*/
}

//
//void DirectSelectionSortShowArray(string& filename) {
//	ifstream file(filename);
//
//	if (!file.is_open()) {
//		cout << "Ошибка открытия файла :(\n";
//		return;
//	}
//
//	string str;
//	int products_amount = 0;
//	string* arr_name = new string[123];
//	while (getline(file, str)) {
//		if (str.find("Наименование: ") != string::npos) {
//			arr_name[products_amount] = str.substr(14);
//			products_amount++;
//		}
//	}
//
//	int min;
//	string t;
//	for (int i = 0; i < products_amount; i++) {
//		min = i;
//		for (int j = i + 1; j < products_amount; j++) {
//			if (arr_name[j] < arr_name[min])
//				min = j;
//		}
//		if (min == i)
//			continue;
//		t = arr_name[i];
//		arr_name[i] = arr_name[min];
//		arr_name[min] = t;
//
//	}
//
//	string f_result = "DirectSelectionSortResult.txt";
//	CreateFile(f_result);
//	ofstream result(f_result);
//	if (!result.is_open()) {
//		cout << "Ошибка открытия файла с результатом сортировки методом прямого выбора\n";
//		return;
//	}
//	else {
//		cout << "\nОТСОРТИРОВАННЫЙ СКЛАД\n";
//		file.clear();
//		file.seekg(0);
//		cout << "\n----------------------------------------------------------------\n";
//		result << "\n----------------------------------------------------------------\n";
//		for (int i = 0; i < products_amount; i++) {
//			while (getline(file, str)) {
//				if (str.find(arr_name[i]) != string::npos) {
//					cout << str << endl;
//					result << str << endl;
//					for (int j = 0; j < 3; j++) {
//						getline(file, str);
//						cout << str << endl;
//						result << str << endl;
//					}
//					cout << "\n----------------------------------------------------------------\n";
//					result << "\n----------------------------------------------------------------\n";
//					break;
//				}
//			}
//			file.clear();
//			file.seekg(0);
//		}
//	}
//	delete[] arr_name;
//	file.close();
//	result.close();
//}
