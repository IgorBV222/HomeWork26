#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//ДЗ_26

struct movies {
	string title{};          //название фильма
	int year{};              //год выхода фильма
	string genre{};          //жанр фильма;
	unsigned int duration{}; //продолжительность фильма в минутах
	unsigned int price{};    //цена за диск фильма

};

//Задача 26.1
//Выводит полную информацию о полях структуры. ?? В названии удаляет первую букву- ПОЧЕМУ!?
void show_movie(movies& M) {
	cout << "Название фильма:                 " << M.title << '\n';
	cout << "Год выхода фильма:               " << M.year << '\n';
	cout << "Жанр фильма:                     " << M.genre << '\n';
	cout << "Продолжительность фильма в мин.: " << M.duration << '\n';
	cout << "Цена за диск фильма:             " << M.price << '\n';
	
	cout << "----------------------------------\n";
}
//Заполняет поля структуры вариант 1
movies input_movies() {
	movies tmp;
	cout << "Введите название фильма: ";
	cin.ignore();
	getline(cin, tmp.title);
	cout << "Введите год выхода фильма: ";
	cin >> tmp.year;
	cout << "Введите жанр фильма: ";
	cin.ignore();
	getline(cin, tmp.genre);
	cout << "Введите продолжительность фильма в мин.: ";
	cin >> tmp.duration;
	cout << "Введите цену за диск фильма: ";
	cin >> tmp.price;

	return tmp;
}
//Заполняет поля структуры вариант 2
void fill_pmovies(movies& M) {
	cout << "Введите название фильма: ";
	cin.ignore();
	getline(cin, M.title);
	cout << "Введите год выхода фильма: ";
	cin >> M.year;
	cout << "Введите жанр фильма: ";
	cin.ignore();
	getline(cin, M.genre);
	cout << "Введите продолжительность фильма в мин.: ";
	cin >> M.duration;
	cout << "Введите цену за диск фильма: ";
	cin >> M.price;
}

//Задача 26.2.
//Возвращает объект с самой высокой ценой за диск.
movies expensive(movies& M1, movies& M2, movies& M3) {
	movies max;
	movies tmp;
	max.price = M1.price > (M2.price > M3.price ? M2.price : M3.price) ? M1.price : (M2.price > M3.price ? M2.price : M3.price);
	
	if (M1.price == max.price) {
		//tmp = M1;
		//show_movie(tmp);
		show_movie(M1);
	}		
	if (M2.price == max.price) {
		//tmp = M2;
		//show_movie(tmp);
		show_movie(M2);
	}
	if (M3.price == max.price) {
		//tmp = M3;
		//show_movie(tmp);
		show_movie(M3);
	}		
	return tmp;
}


// Задача 26.3.
//Позволяет поменять какую-нибудь информацию об объекте
void update_info(movies& M) {
	cout << "Выберите, какую информацию о фильме необходимо обновить: \n";
	cout << "1. Название фильма: " << '\n';
	cout << "2. Год выхода фильма: " << '\n';
	cout << "3. Жанр фильма: " << '\n';
	cout << "4. Продолжительность фильма в мин.: " << '\n';
	cout << "5. Цена за диск фильма: " << '\n';
	cout << "Ввод -> ";
	short answer;
	cin >> answer;
	switch (answer)	{
	case 1:
		cout << "Введите новое название фильма: \n";
		cin.ignore();
		cout << "Ввод -> ";
		getline(cin, M.title);
		cout << "Информация обновлена!\n";
		break;		
	case 2:
		cout << "Введите новый год выхода фильма: \n";
		cout << "Ввод -> ";
		cin >> M.year;
		cout << "Информация обновлена!\n";
		break;		
	case 3:
		cout << "Введите новый жанр фильма: \n";
		cin.ignore();
		cout << "Ввод -> ";
		getline(cin, M.genre);
		cout << "Информация обновлена!\n";
		break;		
	case 4:
		cout << "Введите новую продолжительность фильма в мин.: \n";
		cout << "Ввод -> ";
		cin >> M.duration;
		cout << "Информация обновлена!\n";
		break;		
	case 5:
		cout << "Введите новую цену за диск с фильмом: \n";
		cout << "Ввод -> ";
		cin >> M.price;
		cout << "Информация обновлена!\n";
		break;
	default: cout << "Ошибка ввода.\n\n";
	}
}



int main() {
	setlocale(LC_ALL, "Russian");
	
	//Задача 26.1. Создайте функцию show_movie, которая принимает объект структуры и выводит всю информацию о нём(т.е.выводятся значения полей объекта).
	cout << "Задача 26.1\n";
	movies f;
	//f1 = input_movies();
	fill_pmovies(f);
	cout << "----------------------------------\n";
	show_movie(f);//Удаляет первую букву в названии фильма!!!!ПОЧЕМУ
	cout << "\n\n";


	//Задача 26.2. Создайте функцию expensive, которая принимает три объекта структуры и возвращает объект с самой высокой ценой за диск.
	//Для решения данной задачи необходимо при создании функции использовать тип данных movies для возвращаемого значения.
	cout << "Задача 26.2\n";
	movies f1, f2, f3;
	
	fill_pmovies(f1);
	cout << "----------------------------------\n";
	fill_pmovies(f2);
	cout << "----------------------------------\n";
	fill_pmovies(f3);
	cout << "----------------------------------\n";

	cout << "Объект(ы) с максимальной ценой за диск с фильмом: \n\n";
	expensive(f1, f2, f3);
	cout << "\n\n";

	//Задача 26.3. Замена какой-нибудь информации об объекте.
	cout << "Задача 26.3\n";
	movies film;
	fill_pmovies(film);
	cout << "----------------------------------\n";
	show_movie(film);
	cout << "----------------------------------\n";
	cout << "\n\n";

	update_info(film);
	
	cout << "Обновленная информация о фильме:\n";
	show_movie(film);
	cout << "\n\n";	

	return 0;
}