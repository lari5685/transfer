#include <iostream>
#include <fstream> 
using namespace std;

int main(int argc, char const* argv[])
{
	ifstream fin; 
	ofstream fout;
	fin.open("INPUT.txt");	// Имя исходного файла
	char buff[100];			// Определяем размер буфера
	if (!fin.is_open()){	// Если не удалось открыть файл
		cout << "file not open\n\n";
		return -1; // Сообщаем и выходим из программы
	}

	char ans;		// Переменная для хранения ответа
	char name[100]; // Переменная для имени файла
	cout << "Input to new file? (Y/N): ";
	cin >> ans;		// Получаем ответ
	if (ans == 78 || ans == 110)	// Если да
		cout << "OK\n\n";			// Сообщаем, что увидели
	else if (ans == 89 || ans == 121) {	// Если нет
		cout << "OK\tWrite name file: ";// Просим ввести имя файла
		cin >> name;
		fout.open(name);				// Создаем этот файл
		cout << "OK\n\n";				// Сообщаем об успехе
	}
	else {
		cout << "I don`t understand";
	}


	while (!fin.eof()) // Пока не конец файла
	{
		fin.getline(buff, 100, '\n'); // Получаем строку до 100 символов
		if (buff[0] >= 97 && buff[0] <= 122)// Для первого симвла
			buff[0] -= 32; // Делаем заглавную
		for (int i = 0; buff[i] != 0; i++) { // Цикл пока не конец строки
			if (buff[i+1] >= 97 && buff[i+1] <= 122 && buff[i]==32)// Если буква после пробела
				buff[i+1] -= 32; // Делаем ее заглавной
		}
		cout << buff << endl; // Выводим полученную строку 
		if (fout.is_open()) { // Если мы до этого открыли файл
			fout << buff << "\n"; // Записываем и туда 
		}
	}
	return 0;
}
