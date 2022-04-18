/*
 * main.cpp
 *
 *  Created on: 31 ���. 2022 �.
 *      Author: ����
 */
#include <iostream>
#include <limits>
#include <iomanip>
#include <fstream>
#include <vector>
/* ������� � ���������
 * print_table_header
 * print_table_row
 * read_file
 * write_file
 * input_employee
 * change_employee
 *
 */
const char *DB_FILE_NAME = "empl_roster.db";

struct Employee
{
	char name[21];
	char job [16];
	int salary;
};

void print_table_header(){
	std::cout <<
			"  �  |       Employee     |      Job      |Salary|\n"
			"-----+--------------------+---------------+------|\n";
}

void print_table_row(const Employee &empl, int row){
	std::cout <<
		std::setw(4) <<std::right << row << " |" <<
		std::setw(20) << std::left  << empl.name   << "|" <<
		std::setw(15) << std::left  << empl.job    << "|"<<
		std::setw(6)  << std::right << empl.salary << "|"<<
		std::endl;
}

void read_file(const char*filename, std::vector <Employee> &list)
{
	list.clear();
	std::ifstream data_file {filename, std::ios::binary};
	if (not data_file) return;
	Employee empl;
	while(data_file.read( reinterpret_cast<char*>(&empl), sizeof(empl)))
		list.push_back(empl);
	data_file.close();
}

void write_file(const char*filename, std::vector <Employee> &list){
	std::ofstream data_file{filename, std::ios::binary };
	for(auto &&e : list) data_file.write(reinterpret_cast<char*>(&e), sizeof(e));
	data_file.close();
}

void input_employee(std::vector <Employee> &list){
	Employee empl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "������� ���: ";
	std::cin.getline(empl.name, sizeof(empl.name));
	std::cout << "������� ���������     : ";
	std::cin.getline(empl.job, sizeof(empl.job));
	std::cout << "������� ��������      : ";
	std::cin >> empl.salary;
	list.push_back(empl);
}

void change_employee(std::vector <Employee> &list){
	Employee empl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "������� ����� ����������:\n--->";
	long n;
	std::cin >> n;
	if ( n<0 or n>list.size())
	{
		std::cout << "������ ������ �� ����������!" << std::endl;
	}else{
		list.erase(list.begin() + n);

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "������� ���: ";
		std::cin.getline(empl.name, sizeof(empl.name));

		std::cout << "������� ���������: ";
		std::cin.getline(empl.job, sizeof(empl.job));

		std::cout << "������� ��������: ";
		std::cin >> empl.salary;

		list.emplace(list.begin()+n, empl);
	}
}

void delete_employee(std::vector <Employee> &list)
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "������� ����� ����������:\n--->";
	long n;
	std::cin >> n;
	if ( n<0 or n>list.size())
	{
		std::cout << "������ ������ �� ����������!" << std::endl;
	}else
	{
		list.erase(list.begin() + n);
	}
}

int main(){

	std::vector <Employee> empl_roster;
	read_file(DB_FILE_NAME, empl_roster);
	int choice;
	do{
		menu:
		std::cout <<
				"�������� ��� �������:\n"
				"---------------------\n"
				"1. ������� ������\n"
				"2. �������� ����������\n"
				"3. �������� ������\n"
				"4. ������� ������\n"
				"\n"
				"0. �����\n"
				"---->";
		if(not(std::cin >> choice)){
			if(std::cin.eof()){
				std::cerr << "������ �����/������" << std::endl;
				return 1;
			}
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			goto menu;
		}
		int i = 0;
		switch(choice){
		case 0:
			std::cout <<"�� ��������!" << std::endl;
			break;
		case 1:
			print_table_header();
			for(auto &&e : empl_roster)
					print_table_row(e, i++);
			break;
		case 2:
			input_employee(empl_roster);
			break;
		case 3:
			change_employee(empl_roster);
			break;
		case 4:
			delete_employee(empl_roster);
			break;
		default:
			std::cout << "������ �������� ���!" << std::endl;
		}
	}while (choice != 0);
	write_file(DB_FILE_NAME, empl_roster);
	return 0;
}




