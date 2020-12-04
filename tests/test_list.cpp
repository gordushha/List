#include <../gtest/gtest.h>
#include "List.h"

TEST(list, can_create_list)
{
	ASSERT_NO_THROW(List<int> a);
}

TEST(list, can_copy)
{
	List<int> a;
	ASSERT_NO_THROW(List<int> b(a));
}

TEST(list, can_push_back)
{
	List<int> a;
	ASSERT_NO_THROW(a.push_back(1));
}

TEST(list, can_pop_back)
{
	List<int> a;
	a.push_back(1);
	ASSERT_NO_THROW(a.pop_back());
}

TEST(list, cant_pop_in_empty_list)
{
	List<int> a;
	ASSERT_ANY_THROW(a.pop_back());
}

TEST(list, can_push_front)
{
	List<int> a;
	a.push_back(2);
	ASSERT_NO_THROW(a.push_front(1));
}

TEST(list, can_pop_front)
{
	List<int> a;
	a.push_back(1);
	ASSERT_NO_THROW(a.pop_front());
}

TEST(list, can_insert)
{
	List<int> a;
	a.push_back(1);
	a.push_back(3);
	ASSERT_NO_THROW(a.insert(2, 1));
}

TEST(list, can_remove)
{
	List<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	ASSERT_NO_THROW(a.remove(1));
}

TEST(list, can_insert_at_end)
{
	List<int> a;
	a.push_back(1);
	a.push_back(2);
	ASSERT_NO_THROW(a.insert(3, 2));
}

TEST(list, cant_insert_beyond_border)
{
	List<int> a;
	ASSERT_ANY_THROW(a.insert(1, 1));
}

TEST(list, cant_remove_beyond_border)
{
	List<int> a;
	ASSERT_ANY_THROW(a.remove(1));
}