#include "pch.h"
#include "..\Study_Groups\Study_Groups.h"
#include "..\Study_Groups\Study_Table.h"
#include "..\Study_Groups\Study_Groups.cpp"
#include "..\Study_Groups\Study_Table.cpp"

using namespace Study_Groups;
using namespace Study_Table;
using namespace std;

TEST(GroupDay, IndDayGroup)
{
	Study_Groups::Day gr;
	ASSERT_EQ(0, gr.get_Group_count());
	ASSERT_EQ(1, gr.outinf());
	ASSERT_EQ(0, gr.Group_kaf());
}

TEST(GroupNight, IndNightGroup)
{
	Study_Groups::Night gr;
	ASSERT_EQ(0, gr.get_Group_count());
	ASSERT_EQ(0, gr.outinf());
	ASSERT_EQ(0, gr.Group_kaf());
}

TEST(GroupPay, IndPayGroup)
{
	Study_Groups::Pay gr;
	ASSERT_EQ(0, gr.get_Group_count());
	ASSERT_EQ(0, gr.outinf());
	ASSERT_EQ(0, gr.Group_kaf());
}