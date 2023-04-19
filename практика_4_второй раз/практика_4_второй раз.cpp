#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <fstream>

using namespace std;
struct Date {
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct Record
{
	char surName[17];
	char teamcode[6];
	float points;
	int place;
	struct Date date;
};

void printDate(unsigned short day, unsigned short month, unsigned short year, int wLine) {
	int w = 10;
	int delta = (wLine - w) / 2 - 1;
	cout << left;
	cout.width(delta); cout << " ";
	if (day > 9) {
		cout << day;
	}
	else {
		cout << "0" << day;
	}
	cout << ".";
	if (month > 9) {
		cout << month;
	}
	else {
		cout << "0" << month;
	}
	cout << ".";
	cout << year;
	cout.width(delta); cout << " ";
}

void Draw(Record* records,int num) {
	cout << endl;	cout.width(90); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(89); cout << left << "|Ведомость спортивнхы состязаний"; cout << "|" << endl;
	cout.width(89); cout.fill('-'); cout << "|"; cout << "|" << endl;
	cout.fill(' ');
	cout.width(20); cout << "| Фамилия участника";
	cout.width(14); cout << "| Код команды";
	cout.width(20); cout << "| Количество баллов";
	cout.width(16); cout << "| Место в итоге";
	cout.width(19); cout << "| Дата выступления";
	cout << '|' << endl;
	cout.width(89); cout.fill('-'); cout << "|"; cout << "|" << endl;
	cout.fill(' ');
	for (int i = 0; i < num; i++) {
		cout << left << "|"; cout.width(20); cout << left << records[i].surName;
		cout << left << "|"; cout.width(14); cout << left << records[i].teamcode;
		cout << left << "|"; cout.width(16); cout << left << records[i].points;
		std::cout.precision(2);
		cout << left << "|"; cout.width(16); cout << left << fixed << records[i].place;
		cout << left << "|";
		printDate(records[i].date.day, records[i].date.month, records[i].date.year, 20);
		cout << "|" << endl;
	}
	cout.width(89); cout.fill('-'); cout << "|"; cout << "|" << endl;
	cout.fill(' '); cout.width(89);  cout << left << "|Примечание: Д - Динамо, С - Спартак, Ш - Шахтер"; cout << "|" << endl;
	cout.width(90); cout.fill('-'); cout << "-" << endl;

}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//Записать 3 записи(три строки(records) из таблицы практики 0) в файл в текстовом формате
	Record records[10];
	records[0] = { "Баладин", "С",123.7000 ,2 , {06,06,2022} };
	records[1] = { "Шишков", "Ш",79.9800 , 3, {07,07,2022} };
	records[2] = { "Кравченко", "Д",134.8000 ,2 , {07,06,2022} };
	//Draw(records, 3);
	//FILE* file;
	//fopen_s(&file, "Фамилия", "w+");
	/*ofstream file("Фамилия.txt");
	for (int i = 0; i < 3; i++) {
		
		file << records[i].surName << " " << records[i].teamcode << " " << records[i].points << " " << records[i].place << " " << records[i].date.day << " " << records[i].date.month << " " << records[i].date.year << endl;
			
	}
	file.close();


	//Считать 3 записи из файла в текстовом формате и отобразить
	//fopen_s(&file, "Фамилия", "r");
	ifstream file2("Фамилия.txt");
	Record readRecords[3];
	for (int i = 0; i < 3; i++) {
		file2 >> readRecords[i].surName >> readRecords[i].teamcode >> readRecords[i].points >> readRecords[i].date.day >> readRecords[i].date.month >> readRecords[i].date.year;
		
	}
	
	Draw(readRecords, 3);
	file2.close();*/
	

	FILE* textfile;
	fopen_s(&textfile, "textfile.txt", "w+");
	for (int i = 0; i < 3; i++) {
		fprintf(textfile, "%s %s %f %d %d %d %d \n", \
			records[i].surName, \
			records[i].teamcode, \
			records[i].points, \
			records[i].place	, \
			records[i].date.day, records[i].date.month, records[i].date.year);
	}
	fclose(textfile);
	fopen_s(&textfile, "textfile.txt", "r");
	Record readrecords[3];
	for (int i = 0; i < 3; i++) {
		fscanf_s(textfile, "%s", readrecords[i].surName,_countof(readrecords[i].surName));
		fscanf_s(textfile, "%s", readrecords[i].teamcode,_countof(readrecords[i].teamcode));
		fscanf_s(textfile, "%f", &readrecords[i].points);
		fscanf_s(textfile, "%d", &readrecords[i].place);
		fscanf_s(textfile, "%d", &readrecords[i].date.day);
		fscanf_s(textfile, "%d", &readrecords[i].date.month);
		fscanf_s(textfile, "%d", &readrecords[i].date.year);
	}

	fclose(textfile);
	Draw(readrecords, 3);
	




















	//Record inRecord;
	/*char surName[17];
	char teamcode[6];
	float points;
	int place;
	Date date;
	cout << "Введите фамилию:";
	cin >> inRecord.surName;
	cout << "---------";
	cin >> inRecord.teamcode;
	cout << "---------";
	cin >> inRecord.points;
	cout << "---------";
	cin >> inRecord.place;
	cout << "---------:";
	cin >> inRecord.date.day;
	cout << "---------:";
	cin >> inRecord.date.month;
	cout << "---------";
	cin >> inRecord.date.year;*/
	//добавляем новый рекорд
	//Record inRecord = { "Франк", "А",145.32,2,{21,03,2023} };
	//fopen_s(&file, "Фамилия", "a");
	//fprintf(file, "%s %s %f %d \n", inRecord.surName, \
	//	inRecord.teamcode, \
	//	inRecord.points, \
	//	inRecord.place, \
	//	inRecord.date.day, inRecord.date.month, inRecord.date.year);
	//fclose(file);
	////проверка считование данных из файла
	//Record newrecord[4];
	//fopen_s(&file, "Фамилия", "r");
	//for (int i = 0; i < 3; i++) {
	//	fscanf_s(file, "%s", newrecord[i].surName, _countof(newrecord[i].surName));
	//	fscanf_s(file, "%s", newrecord[i].teamcode, _countof(newrecord[i].teamcode));
	//	fscanf_s(file, "%f", newrecord[i].points);
	//	fscanf_s(file, "%d", newrecord[i].date.day);
	//	fscanf_s(file, "%d", newrecord[i].date.month);
	//	fscanf_s(file, "%d", newrecord[i].date.year);

	//}
	//fclose(file);
	//Draw(newrecord, 4);
}
