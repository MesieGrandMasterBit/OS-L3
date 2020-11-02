
#include <iostream>
#include "Lab3.hpp"
#include "../2/src/Lab2.hpp"
#include "../2/src/Lab2.cpp"

using namespace std;

void Menu()
{
	cout << "==========================" << endl;
	cout << "Сделайте ваш выбор:" << endl;
	cout << " a - Разработчики" << endl;
	cout << " u - Доступные аргументы" << endl;
	cout << " r - Описание" << endl;
	cout << " e - Пример" << endl;
	cout << "==========================" << endl;
	cout << "Введите аргумент: ";
}

void prArguments()
{
	cout << "==============================================================" << endl;
	cout << " 2 - Команды из лабораторной работы №2" << endl;
	cout << " p - Порождение процесса по его имени и возвращение с втроку ввода команд после завершения дочернего процесса" << endl;
	cout << " f - Перевод запускаемого процесса в фоновый режим" << endl;
	cout << " g - Получение и обрабатывание сигналов от внешних программ и ОС" << endl;
	cout << "==============================================================" << endl;
}

void prArguments2()
{
	cout << "==============================================================" << endl;
	cout << " m - Перемещение файла" << endl;
	cout << " c - Копирование файла" << endl;
        cout << " d - Удаление файла из данной папки" << endl;
	cout << " D - Удаление файла из другой папки" << endl;
	cout << " s - Подсчёт общего размера указанной файла" << endl;
	cout << " S - Подсчёт общего размера указанной директории" << endl;
	cout << " f - Отображение всех файлов в указанной директории" << endl;
	cout << " p - Отображение всех процессов из файловой системы procfs" << endl;
	cout << "==============================================================" << endl;
	cout << "ЕСЛИ ФАЙЛ НА УРОВЕНЬ ВЫШЕ, ТО ИСПОЛЬЗУЙТЕ В В НАЧАЛЕ ../" << endl;
}

void prReadme()
{
	cout << "==============================================================" << endl;
	cout << "Данная программа включает в себя:"<< endl;
	cout << "-Вызов команд из Лабораторной работы №2;" << endl;
	cout << "-Порождение процесса по его имени и возвращение с втроку ввода команд после завершения дочернего процесса;" << endl;
	cout << "-Перевод запускаемого процесса в фоновый режим;" << endl;
	cout << "-Получение и обрабатывание сигналов от внешних программ и ОС" << endl;
	cout << "==============================================================" << endl;
}

void CretFile()
{
	char* name;
	name = (char*)malloc(sizeof(char) * 256);
	cout << "Введите название файла: ";
	cin >> name;
	ofstream File;
	File.open(name);
	File.close();
}

int main()
{
	char command, camm, camm2;
	string path, fileName;
	int S, kf;
	char* dir;
	char* file;
	dir = (char*)malloc(sizeof(char) * 256);
	file = (char*)malloc(sizeof(char) * 256);
	do {
		cout << "\033c";
		Menu();
		cin >> command;
		switch(command)
		{
			case 'a' : cout << " Высотин Кирилл Евгеньевич \n Пахомов Илья Максимович \n Юрьев Юрий 		Вадимович"<< endl; 
				break;

			case 'u' : prArguments();
				do {
					cout << "Введите аргумент: " ;
     cin >> camm;
     switch(camm)
     {
     case '2' : prArguments2();
      do {
       cout << "Сколько хотите создать файлов: ";
       cin >> kf;
       for (int i=0;i<kf;i++) {
        CretFile();
       }
       cout << "Введите аргумент: ";
       cin >> camm2;
       switch(camm2)
       {
       case 'm' : cout << "Введите название папки: ";
        cin >> path;
        cout << "Введите имя файла: ";
        cin >> fileName;
        cout << endl;
        moveFile(path,fileName);
        break;

       case 'c' : cout << "Введите название папки: ";
        cin >> path;
        cout << "Введите имя файла: ";
        cin >> fileName;
        cout << endl;
        copyFile(path,fileName);
        break;


       case 'd' : cout << "Введите название файла: ";
        cin >> fileName;
        deleteFile(fileName);
        break;

       case 'D' : cout << "Введите название папки: ";
        cin >> path;
        cout << "Введите имя файла: ";
        cin >> fileName;
        DeleteFile(path, fileName);
        break;

       case 's' : cout << "Введите название файла: ";
        cin >> file;
        cout << getFileSize(file) << " Kb" << endl;
        break;

       case 'S' : cout << "Введите имя папки: ";
        cin >> dir;
        cout << getDirSize(dir) << " Kb" << endl;
        break;


       case 'f' : cout << "Введите имя папки: ";
        cin >> dir;
        displayAllFiles(dir);
        break;

       case 'p' : displayProc();
        break;

       default : cout << "Не понял. Попробуйте ещё раз" << endl;

       }
      cout << "Продолжить работу с аргументом '2'? (y)";
      cin >> camm2;
     } while(camm2 == 'y' || camm2 == 'Y');

     case 'p' :
      spawnPr();
      break;

     case 'f' :
      spawnPrFone();
      break;

     case 'g' :
      catchSignal();
      break;

    default : cout << "Не понял. Попробуйте ещё раз" << endl;
    }
    cout << "Продолжить работу с аргументом 'u'? (y)";
    cin >> camm;
   } while (camm == 'y' || camm == 'Y');

   case 'r' : prReadme();
    break;

   case 'e' : cout << "Всем ку, уважаемые дамы и господа" << endl;
    break;

   default : cout << "Каво? \n";
  }
  cout << "Продолжить работу? (y) ";
  cin >> command;
 } while (command == 'y' || command == 'Y');
 return 0;
}
