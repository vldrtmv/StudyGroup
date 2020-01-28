#include <iostream>
#include <string>
#include "..\Study_Groups\Study_Groups.h"
#include "..\Study_Groups\Study_Groups.cpp"
#include "..\Study_Groups\Study_Table.h"
#include "..\Study_Groups\Study_Table.cpp"

const char* MENU[] =  {"1. Daily Budget Group","2. Evening Budget Group","3. Paid Group", "0. Exit"};
const char* MENUD[] = {"1. Input the information","2. Output the information","3. Output the form of training",
					   "4. Output the number of students in the group","5. Output the department numberф","6. Output the specialization name",
					   "7. Student scholarship","8. Number of students with scholarships"};
const char* MENUN[] = {"1. Input the information","2. Output the information","3. Output the form of training",
					   "4. Output the number of students in the group","5. Output the department number",
					   "6. Output the specialization name"};
const char* MENUP[] = {"1. Input the information","2. Output the information","3. Output the form of training",
					   "4. Output the number of students in the group","5. Output the department number",
					   "6. The semester's fee"};

const unsigned menuSZ = sizeof(MENU) / sizeof(MENU[0]);
const unsigned menuSZD = sizeof(MENUD) / sizeof(MENUD[0]);
const unsigned menuSZN = sizeof(MENUN) / sizeof(MENUN[0]);
const unsigned menuSZP = sizeof(MENUP) / sizeof(MENUP[0]);
using namespace Study_Groups;
using namespace Study_Table;

int main()
{
	Day a; Night b; Pay c;
	std::cout << "Program Name: 'Study Group' " << std::endl;
	unsigned menu = 1;
	unsigned menu1 = 1, menu11 = 1, menu12 = 1, menu13 = 1;
	unsigned menu2 = 1, menu21 = 1;
	unsigned menu3 = 1, menu31 = 1, menu32 = 1;
	unsigned menu4 = 1, menu41 = 1;

	do
	{
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << std::endl;
		if (menu)
			for (size_t i = 0; i < menuSZ; ++i)
				std::cout << MENU[i] << std::endl;
		std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

		std::cout << std::endl;
		menu = getnum("Make your choice ~~~>>> ");
		std::cout << std::endl;
		switch (menu)
		{
		case 1://~~~Реализация для дневной группы
			do {
				std::cout << "***************************************************\n" << std::endl;
				for (size_t i = 0; i < menuSZD; ++i)
					std::cout << MENUD[i] << std::endl;
				std::cout << "\n***************************************************" << std::endl;
				std::cout << std::endl;
				menu1 = getnum("Make your choice ~~>> ");
				std::cout << std::endl;
				switch (menu1)
				{
				case 1://Ввод Информации
					a.sborinf();
					break;
				case 2://Вывод информации
					a.outinf();
					break;
				case 3://Форма обучения
					a.Group_form();
					break;
				case 4://Численность:Ввод и вывод.
					do {
						std::cout << "***************************************************\n" << std::endl;
						std::cout << "1. Change student numbers" << std::endl;
						std::cout << "2. Print the number of students" << std::endl;
						std::cout << "\n***************************************************" << std::endl;
						std::cout << std::endl;
						menu11 = getnum("Make your choice ~> ");
						std::cout << std::endl;
						switch (menu11)
						{
						case 1://Ввод численности
							a.set_Group_count();
							break;
						case 2://Вывод численности на экран
							a.get_Group_count();
							break;
						case 0:
							break;
						default:
							std::cout << "Something went wrong. Try it again!" << std::endl;
							break;
						}
					} while (menu11 != 0);
					break;
				case 5://Номер кафедры
					a.Group_kaf();
					break;
				case 6://Специализация
					a.IAmSpecial();
					break;
				case 7://Стипендия:Ввод и Вывод
					do {
						std::cout << "***************************************************\n" << std::endl;
						std::cout << "1. Change the scholarship amount" << std::endl;
						std::cout << "2. Print the scholarship amount" << std::endl;
						std::cout << "\n***************************************************" << std::endl;
						std::cout << std::endl;
						menu12 = getnum("Make your choice ~> ");
						std::cout << std::endl;
						switch (menu12)
						{
						case 1://Ввод стипендии
							a.ch_grant();
							break;
						case 2://Вывод стипендии
							a.out_grant();
							break;
						case 0:
							break;
						default:
							std::cout << "Something went wrong. Try it again!" << std::endl;
							break;
						}
					} while (menu12 != 0);
					break;
				case 8://Количетсво на стипендии
					do {
						std::cout << "***************************************************\n" << std::endl;
						std::cout << "1. Change the number of students on scholarships" << std::endl;
						std::cout << "2. Print the number of students on scholarships" << std::endl;
						std::cout << "\n***************************************************" << std::endl;
						std::cout << std::endl;
						menu13 = getnum("Make your choice ~> ");
						std::cout << std::endl;
						switch (menu13)
						{
						case 1://Ввод стипендии
							a.ch_count_grant();
							break;
						case 2://Вывод стипендии
							a.out_count_grant();
							break;
						case 0:
							break;
						default:
							std::cout << "Something went wrong. Try it again!" << std::endl;
							break;
						}
					} while (menu13 != 0);
					break;
				case 0:break;
				}
			} while (menu1 != 0);
			break;
		case 2://~~~Реализация для вечерней группы
			do {
				std::cout << "***************************************************\n" << std::endl;
				for (size_t i = 0; i < menuSZN; ++i)
					std::cout << MENUN[i] << std::endl;
				std::cout << "\n***************************************************" << std::endl;
				std::cout << std::endl;
				menu2 = getnum("Make your choice ~~>> ");
				std::cout << std::endl;
				switch (menu2)
				{
				case 1://Ввод Информации
					b.sborinf();
					break;
				case 2://Вывод информации
					b.outinf();
					break;
				case 3://Форма обучения
					b.Group_form();
					break;
				case 4://Численность:Ввод и вывод.
					do {
						std::cout << "***************************************************\n" << std::endl;
						std::cout << "1. Change student numbers" << std::endl;
						std::cout << "2. Print the number of students" << std::endl;
						std::cout << "\n***************************************************" << std::endl;
						std::cout << std::endl;
						menu21 = getnum("Make your choice ~> ");
						std::cout << std::endl;
						switch (menu21)
						{
						case 1://Ввод численности
							b.set_Group_count();
							break;
						case 2://Вывод численности на экран
							b.get_Group_count();
							break;
						case 0:
							break;
						default:
							std::cout << "Something went wrong. Try it again!" << std::endl;
							break;
						}
					} while (menu21 != 0);
					break;
				case 5://Номер кафедры
					b.Group_kaf();
					break;
				case 6://Специализация
					b.IAmSpecial();
					break;
				}
			} while (menu2 != 0);
			break;
		case 3://~~~Реализация для платной группы
			do {
				std::cout << "***************************************************\n" << std::endl;
				for (size_t i = 0; i < menuSZP; ++i)
					std::cout << MENUP[i] << std::endl;
				std::cout << "\n***************************************************" << std::endl;
				std::cout << std::endl;
				menu3 = getnum("Make your choice ~~>> ");
				std::cout << std::endl;
				switch (menu3)
				{
				case 1://Ввод Информации
					c.sborinf();
					break;
				case 2://Вывод информации
					c.outinf();
					break;
				case 3://Форма обучения
					c.Group_form();
					break;
				case 4://Численность:Ввод и вывод.
					do {
						std::cout << "***************************************************\n" << std::endl;
						std::cout << "1. Change student numbers" << std::endl;
						std::cout << "2. Print the number of students" << std::endl;
						std::cout << "\n***************************************************" << std::endl;
						std::cout << std::endl;
						menu31 = getnum("Make your choice ~> ");
						std::cout << std::endl;
						switch (menu31)
						{
						case 1://Ввод численности
							c.set_Group_count();
							break;
						case 2://Вывод численности на экран
							c.get_Group_count();
							break;
						case 0:
							break;
						default:
							std::cout << "Something went wrong. Try it again!" << std::endl;
							break;
						}
					} while (menu31 != 0);
					break;
				case 5://Номер кафедры
					c.Group_kaf();
					break;
				case 6://Размер платы за семестр
					do
					{
						std::cout << "***************************************************\n" << std::endl;
						std::cout << "1. Change semestr's fee" << std::endl;
						std::cout << "2. Print the semestr's fee" << std::endl;
						std::cout << "\n***************************************************" << std::endl;
						std::cout << std::endl;
						menu32 = getnum("Make your choice ~> ");
						std::cout << std::endl;
						switch (menu32)
						{
						case 1:
							c.ch_money_sem();
							break;
						case 2:
							c.out_money_sem();
							break;
						default:
							std::cout << "Something went wrong. Try it again!" << std::endl;
						case 0:
							break;
						}

					} while (menu32 != 0);
					break;
				}
			} while (menu3 != 0);
			break;
		case 4://~~~Реализация для работы с таблицей
			do {
			
			} while (menu4 != 0);
			break;
		case 0:break;
		default:
			std::cout << "Something went wrong. Try it again!" << std::endl;
			break;
		}
	}while (menu != 0);
	return 0;

}
