#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//��_26

struct movies {
	string title{};          //�������� ������
	int year{};              //��� ������ ������
	string genre{};          //���� ������;
	unsigned int duration{}; //����������������� ������ � �������
	unsigned int price{};    //���� �� ���� ������

};

//������ 26.1
//������� ������ ���������� � ����� ���������. ?? � �������� ������� ������ �����- ������!?
void show_movie(movies& M) {
	cout << "�������� ������:                 " << M.title << '\n';
	cout << "��� ������ ������:               " << M.year << '\n';
	cout << "���� ������:                     " << M.genre << '\n';
	cout << "����������������� ������ � ���.: " << M.duration << '\n';
	cout << "���� �� ���� ������:             " << M.price << '\n';
	
	cout << "----------------------------------\n";
}
//��������� ���� ��������� ������� 1
movies input_movies() {
	movies tmp;
	cout << "������� �������� ������: ";
	cin.ignore();
	getline(cin, tmp.title);
	cout << "������� ��� ������ ������: ";
	cin >> tmp.year;
	cout << "������� ���� ������: ";
	cin.ignore();
	getline(cin, tmp.genre);
	cout << "������� ����������������� ������ � ���.: ";
	cin >> tmp.duration;
	cout << "������� ���� �� ���� ������: ";
	cin >> tmp.price;

	return tmp;
}
//��������� ���� ��������� ������� 2
void fill_pmovies(movies& M) {
	cout << "������� �������� ������: ";
	cin.ignore();
	getline(cin, M.title);
	cout << "������� ��� ������ ������: ";
	cin >> M.year;
	cout << "������� ���� ������: ";
	cin.ignore();
	getline(cin, M.genre);
	cout << "������� ����������������� ������ � ���.: ";
	cin >> M.duration;
	cout << "������� ���� �� ���� ������: ";
	cin >> M.price;
}

//������ 26.2.
//���������� ������ � ����� ������� ����� �� ����.
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


// ������ 26.3.
//��������� �������� �����-������ ���������� �� �������
void update_info(movies& M) {
	cout << "��������, ����� ���������� � ������ ���������� ��������: \n";
	cout << "1. �������� ������: " << '\n';
	cout << "2. ��� ������ ������: " << '\n';
	cout << "3. ���� ������: " << '\n';
	cout << "4. ����������������� ������ � ���.: " << '\n';
	cout << "5. ���� �� ���� ������: " << '\n';
	cout << "���� -> ";
	short answer;
	cin >> answer;
	switch (answer)	{
	case 1:
		cout << "������� ����� �������� ������: \n";
		cin.ignore();
		cout << "���� -> ";
		getline(cin, M.title);
		cout << "���������� ���������!\n";
		break;		
	case 2:
		cout << "������� ����� ��� ������ ������: \n";
		cout << "���� -> ";
		cin >> M.year;
		cout << "���������� ���������!\n";
		break;		
	case 3:
		cout << "������� ����� ���� ������: \n";
		cin.ignore();
		cout << "���� -> ";
		getline(cin, M.genre);
		cout << "���������� ���������!\n";
		break;		
	case 4:
		cout << "������� ����� ����������������� ������ � ���.: \n";
		cout << "���� -> ";
		cin >> M.duration;
		cout << "���������� ���������!\n";
		break;		
	case 5:
		cout << "������� ����� ���� �� ���� � �������: \n";
		cout << "���� -> ";
		cin >> M.price;
		cout << "���������� ���������!\n";
		break;
	default: cout << "������ �����.\n\n";
	}
}



int main() {
	setlocale(LC_ALL, "Russian");
	
	//������ 26.1. �������� ������� show_movie, ������� ��������� ������ ��������� � ������� ��� ���������� � ��(�.�.��������� �������� ����� �������).
	cout << "������ 26.1\n";
	movies f;
	//f1 = input_movies();
	fill_pmovies(f);
	cout << "----------------------------------\n";
	show_movie(f);//������� ������ ����� � �������� ������!!!!������
	cout << "\n\n";


	//������ 26.2. �������� ������� expensive, ������� ��������� ��� ������� ��������� � ���������� ������ � ����� ������� ����� �� ����.
	//��� ������� ������ ������ ���������� ��� �������� ������� ������������ ��� ������ movies ��� ������������� ��������.
	cout << "������ 26.2\n";
	movies f1, f2, f3;
	
	fill_pmovies(f1);
	cout << "----------------------------------\n";
	fill_pmovies(f2);
	cout << "----------------------------------\n";
	fill_pmovies(f3);
	cout << "----------------------------------\n";

	cout << "������(�) � ������������ ����� �� ���� � �������: \n\n";
	expensive(f1, f2, f3);
	cout << "\n\n";

	//������ 26.3. ������ �����-������ ���������� �� �������.
	cout << "������ 26.3\n";
	movies film;
	fill_pmovies(film);
	cout << "----------------------------------\n";
	show_movie(film);
	cout << "----------------------------------\n";
	cout << "\n\n";

	update_info(film);
	
	cout << "����������� ���������� � ������:\n";
	show_movie(film);
	cout << "\n\n";	

	return 0;
}