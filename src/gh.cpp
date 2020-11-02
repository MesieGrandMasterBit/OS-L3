#include <iostream>
#include "../../2/src/Lab2.cpp"
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main()
{
	pid_t l;
	char command;
        string path, fileName;
        cout << "Шо?" << endl;
	cout << "m - 2 лаба" << endl;
	cout << "d - дочерний процесс" << endl;
        do {
		cout << "Введите аргумент: ";
		cin >> command;
		switch(command)
		{
			case 'm' : cout << "Введите папку и файл: " << endl; 
				cin >> path >> fileName;
				moveFile(path, fileName);
					break;

			case 'd' : cout << "Hi, zyabls" << endl;
				l = fork ();
				 cout << "ld: " << l << endl;
				//cout << "ld: %d" << l << endl;
					break;

			default :  cout << "Каво?" << endl;
		}
			cout << "Продолжить? (y)";
			cin >> command;
	} while (command == 'y' || command == 'Y');
	return 0;
}
