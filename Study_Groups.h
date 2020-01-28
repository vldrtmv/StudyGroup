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
		virtual int sborinf() = 0;//���� ����������
		virtual int outinf() = 0;//����� ����������
		virtual int Group_form()const = 0;//����� ��������
		virtual int set_Group_count() = 0;//�������� ����������� ������
		virtual int get_Group_count()const = 0;//�������� ����������� ������
		virtual int Group_kaf()const = 0;//����� ������������� �������
		virtual void IAmSpecial() = 0;//�������������
	//**************************************************************************************
		virtual ~Group() {};//����������
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
		virtual Day* clone() const { return new Day(*this); }//��������� ���� ������
		virtual int get_ind() const { return day_index; }
		virtual int sborinf();//���� ����������
		virtual int outinf();//����� ����������
		virtual int Group_form()const;//����� ��������
		virtual int get_Group_count()const;//����� ����������� ������
		virtual int set_Group_count();//��������� ����������� ������
		virtual int Group_kaf()const;//����� ������������� �������
		virtual void IAmSpecial();//�������������
	//**************************************************************************************
		int out_grant()const;//����� ������� ���������
		int ch_grant();//��������� ������� ���������
		int out_count_grant() const;//����� ���������� ��������, ���������� ���������
		int ch_count_grant();//��������� ���������� ��������, ���������� ���������
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
		virtual Night* clone() const { return new Night(*this); }//��������� ���� ������
		virtual int get_ind() const { return na_index; }
		virtual int sborinf();//���� ����������
		virtual int outinf();//����� ����������
		virtual int Group_form()const;//����� ��������
		virtual int get_Group_count()const;//����� ����������� ������
		virtual int set_Group_count();//��������� ����������� ������
		virtual int Group_kaf()const;//����� ������������� �������
		virtual void IAmSpecial();//�������������
		//******************************************************************************
		void kontingent() const;//���������� ��������
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
		virtual Pay* clone() const { return new Pay(*this); }//��������� ���� ������
		virtual int get_ind() const { return pa_index; }
		virtual int sborinf();//���� ����������
		virtual int outinf();//����� ����������
		virtual int Group_form()const;//����� ��������
		virtual int get_Group_count()const;//����� ����������� ������
		virtual int set_Group_count();//��������� ����������� ������
		virtual int Group_kaf()const;//����� ������������� �������
		virtual void IAmSpecial() {};//�������������
		//******************************************************************************
		int ch_money_sem();//���� ������� ����� �� �������
		int out_money_sem() const;//����� ������� ����� �� �������
	};
}

#endif