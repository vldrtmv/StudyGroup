#include "pch.h"
#include "framework.h"
#include "Study_Groups.h"
#include <iostream>
#include <string>


namespace Study_Groups
{
	unsigned getnum(const char* msg)
	{
		while (true) {
			std::cout << msg;
			int a;
			std::cin >> a;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(32000, '\n');
				std::cout << "Incorrect input. Try again." << std::endl;
			}
			else {
				std::cin.ignore(32767, '\n');
				return a;
			}

		}
	}
	//Day~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	std::ostream& Day::show(std::ostream& os) const
	{
		return os<<"Daily Budget Group\nEnter the number of students of the Day group"<< day_count <<"The number of profiling department"<< day_kaf <<"Training period"<< day_time <<"Student Specialization"<< day_spec <<"The Student Scholarship Size"<< day_grants <<"Number of students with scholarships"<< day_grants_count;
	}

	std::istream& Day::get(std::istream& is)
	{
		return is >> day_count >> day_kaf >> day_time >> day_spec >> day_grants >> day_grants_count;
	}

	int Day::sborinf()
	{
		int day_index = getnum("Enter the index grop");
		this->day_index = day_index;
		int day_count = getnum("Enter the number of students of the Day group  ~> ");
		this->day_count = day_count;
		int day_kaf = getnum("Enter the number of profiling department  ~> ");
		this->day_kaf = day_kaf;
		int day_time = getnum("Enter the training time  ~> ");
		this->day_time = day_time;
		std::cout<<"Enter the specialization  ~> ";
		std::getline(std::cin, day_spec);
		int day_grants = getnum("Enter the scholarship size  ~> ");
		this->day_grants = day_grants;
		int day_grants_count = getnum("Enter the number of scholars  ~> ");
		this->day_grants_count = day_grants_count;
		return 0;
	}
	int Day::outinf()
	{
		std::cout << "~~~~~~Daily Budget Group~~~~~~\n";
		std::cout << "Enter the number of students of the Day group ~> " << day_count << std::endl << "The number of profiling department ~> " << day_kaf << std::endl << "Training period ~> " << day_time << std::endl << "Student Specialization ~> " << day_spec << std::endl << "The Student Scholarship Size ~> " << day_grants << std::endl << "Number of students with scholarships ~> " << day_grants_count <<"\n\n" << std::endl;
		return 1;
	}
	int Day::Group_form() const
	{
		std::cout << "Daily Budget Group" << std::endl;
		return 1;
	}
	int Day::get_Group_count() const
	{
		std::cout << "The number of students of the Day group  ~> " << day_count << std::endl;
		return 0;
	}
	int Day::set_Group_count()
	{
		int day_count = getnum("Enter the number of students of the Day group  ~> ");
		this->day_count = day_count;
		return 0;
	}
	int Day::Group_kaf() const
	{
		std::cout << "The number of profiling department  ~> " << day_kaf << std::endl;
		return 0;
	}
	void Day::IAmSpecial()
	{
		std::cout << "Student Specialization  ~> "<<day_spec << std::endl;
	}
	int Day::out_grant() const
	{
		std::cout << "The Student Scholarship Size  ~> " << day_grants << std::endl;
		return 0;
	}
	int Day::ch_grant()
	{
		int day_grants = getnum("Enter the Student Scholarship Size  ~> ");
		this->day_grants = day_grants;
		return 0;
	}
	int Day::out_count_grant() const
	{
		std::cout << "Number of students with scholarships  ~> " << day_grants_count <<std::endl;
			return 0;
	}
	int Day::ch_count_grant()
	{
		int day_grants_count = getnum("Enter the number of students with scholarships  ~> ");
		this->day_grants_count = day_grants_count;
		return 0;
	}


	//Night~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	std::ostream& Night::show(std::ostream& os) const
	{
		return os << "Evening study group\nEnter the number of students of the Night group" << na_count << "The number of profiling department" << na_kaf << "Training period" << na_time << "Student Specialization" << na_spec;
	}
	std::istream& Night::get(std::istream& is)
	{
		return is >> na_count >> na_kaf >> na_time >> na_spec;
	}

	int Night::sborinf()
	{
		int na_index = getnum("Enter the index grop");
		this->na_index = na_index;
		int na_count = getnum("Enter the number of students of the evening group  ~> ");
		this->na_count = na_count;
		int na_kaf = getnum("Enter the number of profiling department  ~> ");
		this->na_kaf = na_kaf;
		int na_time = getnum("Enter the training time  ~> ");
		this->na_time = na_time;
		std::cout << "Enter the specialization  ~> ";
		std::getline(std::cin, na_spec);
		std::cout << "Enter the student population  ~> ";
		std::getline(std::cin, na_kont);
		return 0;
	}

	int Night::outinf()
	{
		std::cout << "~~~~~~Night study group~~~~~~\n";
		std::cout << "Enter the number of students of the evening group ~> " << na_count << std::endl << "The number of profiling department ~> " << na_kaf << std::endl << "Training period ~> " << na_time << std::endl << "Student Specialization ~> " << na_spec << std::endl << "The student population  ~> " << na_kont << std::endl;
		return 0;
	}
	int Night::Group_form() const
	{
		std::cout << "Night study group" << std::endl;
		return 1;
	}
	int Night::get_Group_count() const
	{
		std::cout << "The number of students of the evening group  ~> " << na_count << std::endl;
		return 0;
	}
	int Night::set_Group_count()
	{
		int na_count = getnum("Enter the number of students of the evening group  ~> ");
		this->na_count = na_count;
		return 0;
	}
	int Night::Group_kaf() const
	{
		std::cout << "The number of profiling department  ~> " << na_kaf << std::endl;
		return 0;
	}
	void Night::IAmSpecial()
	{
		std::cout << "Student Specialization  ~> " << na_spec << std::endl;
	}

	void Night::kontingent() const
	{
		std::cout << "Student population  ~> " << na_kont << std::endl;
	}


//Pay~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	std::ostream& Pay::show(std::ostream& os) const
	{
		return os << "Evening study group\nEnter the number of students of the Paid group" << pa_count << "The number of profiling department" << pa_kaf << "Training period" << pa_time << std::endl;
	}

	std::istream& Pay::get(std::istream& is)
	{
		return is >> pa_count >> pa_kaf >> pa_time;
	}

	int Pay::sborinf()
	{
		int pa_index = getnum("Enter the index grop");
		this->pa_index = pa_index;
		int pa_count = getnum("Enter the number of students of the evening group ~> ");
		this->pa_count = pa_count;
		int pa_kaf = getnum("Enter the number of profiling department ~> ");
		this->pa_kaf = pa_kaf;
		int pa_time = getnum("Enter the training time ~> ");
		this->pa_time = pa_time;
		int pa_money = getnum("Enter the semester's fee ~> ");
		this->pa_money = pa_money;
		int pa_number = getnum("Enter the contract number ~> ");
		this->pa_number = pa_number;
		int pa_term = getnum("Enter the training period ~> ");
		this->pa_term = pa_term;
		return 0;
	}

	int Pay::outinf()
	{
		std::cout << "~~~~~~Paid study group~~~~~~\n";
		std::cout 
			<< "The number of students of the Paid group ~> " << pa_count << std::endl
			<< "The number of profiling department ~> " << pa_kaf << std::endl
			<< "Training period ~> " << pa_time << std::endl
			<< "The training period ~> " << pa_term << std::endl
			<< "The contract number ~> " << pa_number << std::endl
			<< "The semester's fee ~> " << pa_money << std::endl;
		return 0;
	}

	int Pay::Group_form() const
	{
		std::cout << "Paid study group" << std::endl;
		return 1;
	}

	int Pay::get_Group_count() const
	{
		std::cout << "The number of students of the evening group  ~> " << pa_count << std::endl;
		return 0;
	}

	int Pay::set_Group_count()
	{
		int pa_count = getnum("Enter the number of students of the evening group  ~> ");
		this->pa_count = pa_count;
		return 0;
	}

	int Pay::Group_kaf() const
	{
		std::cout << "The number of profiling department  ~> " << pa_kaf << std::endl;
		return 0;
	}


	int Pay::ch_money_sem()
	{
		int pa_money = getnum("Change the semestr's fee ~> ");
		this->pa_money = pa_money;
		return 0;
	}

	int Pay::out_money_sem() const
	{
		std::cout << "The semestr's fee ~> " << pa_money<<std::endl;
		return 0;
	}
}