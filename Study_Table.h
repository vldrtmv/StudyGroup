#pragma once

#ifndef STUDY_GROUP_TABLE_H
#define STUDY_GROUP_TABLE_H

#include "Study_Groups.h"
#include <string>
#include <map>
#include <string>

namespace Study_Table
{
	std::ostream& operator <<(std::ostream&, const std::pair<const std::string, Study_Groups::Group*>&);

	class Table
	{
	private:
		std::map<const std::string, Study_Groups::Group*> arr;
	public:
		Table() {}
		Table(const Table&);
		~Table();
		Table& operator = (const Table&);
		friend class ConstTableIt;
		typedef ConstTableIt Const_Iterator;
		Const_Iterator find(const std::string&) const;
		bool insert(const std::string&, const Study_Groups::Group*);		//Добавление элемента
		bool replace(const std::string&, const Study_Groups::Group*);		//Изменение элемента
		bool remove(const std::string&);										//Удаление элемента
		Const_Iterator begin() const;
		Const_Iterator end() const;

	};

	class ConstTableIt
	{
	private:
		std::map<const std::string, Study_Groups::Group*>::const_iterator cur;
	public:

		ConstTableIt() {}
		ConstTableIt(std::map<const std::string, Study_Groups::Group*>::iterator it) :cur(it) {}
		ConstTableIt(std::map<const std::string, Study_Groups::Group*>::const_iterator it) :cur(it) {}
		int operator !=(const ConstTableIt&) const;
		int operator ==(const ConstTableIt&) const;
		const std::pair<const std::string, Study_Groups::Group*>& operator *();
		const std::pair<const std::string, Study_Groups::Group*>* operator ->();
		ConstTableIt& operator ++();
		ConstTableIt operator ++(int);  
	};
}

#endif