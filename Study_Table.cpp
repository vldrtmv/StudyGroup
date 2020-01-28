#include "pch.h"
#include "Study_Table.h"
#include <iostream>

namespace Study_Table
{
	std::ostream& operator<<(std::ostream& os, const std::pair<const std::string, Study_Groups::Group*>& p)
	{
		return os << '"' << p.first << '"' << " - " << (*p.second);
	}

	Table::Table(const Table&a)
	{
		std::map<const std::string, Study_Groups::Group*>::const_iterator p;
		for (p = a.arr.begin(); p != a.arr.end(); ++p)
			arr.insert(std::make_pair(p->first, p->second->clone()));
	}

	Table::~Table()
	{
		std::map<const std::string, Study_Groups::Group*>::iterator p;
		for (p = arr.begin(); p != arr.end(); ++p)
		{
			delete p->second;
			p->second = nullptr;
		}
	}

	Table& Table::operator=(const Table&a)
	{
		std::map<const std::string, Study_Groups::Group*>::iterator p;
		if (this != &a)
		{
			// Рсвобождение памяти, занятой объектом слева от присванивания
			for (p = arr.begin(); p != arr.end(); ++p)
				delete p->second;
			arr.clear();
			// Копирование фигур из контейнера справа от присванивания (a.arr)
			// в контейнер слева от присваивания (arr)
			std::map<const std::string, Study_Groups::Group*>::const_iterator pp;
			for (pp = a.arr.begin(); pp != a.arr.end(); ++pp)
				arr.insert(std::make_pair(pp->first, pp->second->clone()));
		}
		return *this;
	}

	Table::Const_Iterator Table::find(const std::string&s) const
	{
		std::map<const std::string, Study_Groups::Group*>::const_iterator p = arr.find(s);
		return ConstTableIt(p);
	}

	bool Table::insert(const std::string&s, const Study_Groups::Group*f)
	{
		bool res = false;
		std::map<const std::string, Study_Groups::Group*>::iterator p = arr.find(s);
		if (p == arr.end())	// Поиск неуспешен
		{
			std::pair<std::map<const std::string, Study_Groups::Group*>::iterator, bool> pp =
				arr.insert(std::make_pair(s, f->clone()));
			if (!pp.second)
				throw std::exception("can't insert new item into map");
			res = true;
		}
		return res;
	}

	bool Table::replace(const std::string&s, const Study_Groups::Group*f)
	{
		bool res = false;
		std::map<const std::string, Study_Groups::Group*>::iterator p = arr.find(s);

		if (p != arr.end())	// Поиск успешен
		{
			delete p->second;
			p->second = f->clone();
			res = true;
		}
		return res;
	}

	bool Table::remove(const std::string&s)
	{
		bool res = false;
		std::map<const std::string, Study_Groups::Group*>::iterator p = arr.find(s); //arr.erase(s);
		if (p != arr.end())	// Поиск успешен
		{
			delete p->second;
			p->second = nullptr;
			arr.erase(p); // Удаление элемента из контейнера (по значению итератора)
			res = true;
		}
		return res;
	}

	Table::Const_Iterator Table::begin() const
	{
		return ConstTableIt(arr.begin());
	}

	Table::Const_Iterator Table::end() const
	{
		return ConstTableIt(arr.end());
	}


	// Сеиоды класса AssocIt

	int ConstTableIt::operator!=(const ConstTableIt& it) const
	{
		return cur != it.cur;
	}

	int ConstTableIt::operator ==(const ConstTableIt& it) const
	{
		return cur == it.cur;
	}

	const std::pair<const std::string, Study_Groups::Group*>& ConstTableIt::operator *()
	{
		return *cur;
	}

	const std::pair<const std::string, Study_Groups::Group*>* ConstTableIt::operator ->()
	{
		return &*cur;
	}

	ConstTableIt& ConstTableIt::operator ++()
	{
		++cur;
		return *this;
	}

	ConstTableIt ConstTableIt::operator ++(int)
	{
		ConstTableIt res(*this);
		++cur;
		return res;
	}
};
