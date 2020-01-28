#pragma once

#ifndef STUDY_GROUPS_H
#define STUDY_GROUPS_H
#include <string>
#include <iostream>

namespace Study_Groups
{
	class Group
	{
	protected:
		virtual std::ostream& show(std::ostream&) const = 0;
		virtual std::istream& get(std::istream&) = 0;
	public:
		virtual Group* clone() const = 0;
		friend std::ostream& operator<<(std::ostream& s, const Group& G) { return G.show(s);}
		friend std::istream& operator>>(std::istream& s, Group& G) { return G.get(s); }
		virtual int get_ind() const = 0;
		virtual int sborinf() = 0;//Сбор информации
		virtual int outinf() = 0;//Вывод информации
		virtual int Group_form()const = 0;//Форма обучения
		virtual int set_Group_count() = 0;//Изменить численность группы
		virtual int get_Group_count()const = 0;//Получить численность группы
		virtual int Group_kaf()const = 0;//Номер профилирующей кафедры
		virtual void IAmSpecial() = 0;//Специализация
	//**************************************************************************************
		virtual ~Group() {};//Деструктор
	};

	class Day: public Group
	{
	protected:
		virtual std::ostream& show(std::ostream&) const;
		virtual std::istream& get(std::istream&);
	//**************************************************************************************
		int day_index;
		int day_count;
		int day_kaf, day_time, day_grants, day_grants_count;
		std::string day_spec;

	public:
		virtual Day* clone() const { return new Day(*this); }//Описатель типа группы
		virtual int get_ind() const { return day_index; }
		virtual int sborinf();//Сбор информации
		virtual int outinf();//Вывод информации
		virtual int Group_form()const;//Форма обучения
		virtual int get_Group_count()const;//Вывод численность группы
		virtual int set_Group_count();//Изменение численности группы
		virtual int Group_kaf()const;//Номер профилирующей кафедры
		virtual void IAmSpecial();//Специализация
	//**************************************************************************************
		int out_grant()const;//Вывод размера стипендии
		int ch_grant();//Изменение размера стипендии
		int out_count_grant() const;//Вывод количества студиков, получающих стипендию
		int ch_count_grant();//Изменение количества студиков, получающих стипендию
};

	class Night : public Group
	{
	protected:
		virtual std::ostream& show(std::ostream&) const;
		virtual std::istream& get(std::istream&);
		//******************************************************************************
		int na_count, na_kaf, na_time, na_index;
		std::string na_spec, na_kont;
	public:
		virtual Night* clone() const { return new Night(*this); }//Описатель типа группы
		virtual int get_ind() const { return na_index; }
		virtual int sborinf();//Сбор информации
		virtual int outinf();//Вывод информации
		virtual int Group_form()const;//Форма обучения
		virtual int get_Group_count()const;//Вывод численность группы
		virtual int set_Group_count();//Изменение численности группы
		virtual int Group_kaf()const;//Номер профилирующей кафедры
		virtual void IAmSpecial();//Специализация
		//******************************************************************************
		void kontingent() const;//Контингент учащихся
	};

	class Pay: public Group
	{
	protected:
		virtual std::ostream& show(std::ostream&) const;
		virtual std::istream& get(std::istream&);
		//******************************************************************************
		int pa_count, pa_kaf, pa_time, pa_index;
		int pa_term, pa_number, pa_money;
	public:
		virtual Pay* clone() const { return new Pay(*this); }//Описатель типа группы
		virtual int get_ind() const { return pa_index; }
		virtual int sborinf();//Сбор информации
		virtual int outinf();//Вывод информации
		virtual int Group_form()const;//Форма обучения
		virtual int get_Group_count()const;//Вывод численность группы
		virtual int set_Group_count();//Изменение численности группы
		virtual int Group_kaf()const;//Номер профилирующей кафедры
		virtual void IAmSpecial() {};//Специализация
		//******************************************************************************
		int ch_money_sem();//Ввод размера платы за семестр
		int out_money_sem() const;//Вывод размера платы за семестр
	};
}

#endif