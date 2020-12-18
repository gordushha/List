#include <../gtest/gtest.h>
#include "List.h"

TEST(list, can_create_default_list)
{
	ASSERT_NO_THROW(List<int> a);
}

TEST(list, can_pop_front)
{
	List<int> A;
	int x1 = 1, x2 = 2, x3 = 3;
	A.push_front(x1);
	A.push_front(x2);
	A.push_back(x3);

	A.pop_front();
	ListIterator<int> i = A.begin();
	EXPECT_EQ(1, i.GetData());
}

TEST(list, can_pop_back)
{
	List<int> A;
	int x1 = 1, x2 = 2, x3 = 3;
	A.push_front(x1);
	A.push_front(x2);
	A.push_back(x3);
	A.pop_back();
	ListIterator<int> i = A.end();
	EXPECT_EQ(1, i.GetData());
}

TEST(list, can_copy)
{
	List<int> a;
	a.push_back(5);

	List<int> b(a);

	ListIterator<int> i = a.begin();
	EXPECT_EQ(5, i.GetData());
}

TEST(list, can_push_back)
{
	List<int> a;
	a.push_back(1);

	ListIterator<int> i = a.begin();
	EXPECT_EQ(1, i.GetData());
}


TEST(list, can_push_front)
{

	List<int> a;
	a.push_front(2);
	a.push_front(1);

	ListIterator<int> i = a.begin();
	EXPECT_EQ(1, i.GetData());
}



TEST(list, can_insert)
{
	List<int> a;
	a.push_back(1);
	a.push_back(3);
	a.insert(2, 1);

	ListIterator<int> i = a.begin();
	i++;
	EXPECT_EQ(2, i.GetData());
}

TEST(list, can_remove)
{
	List<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.remove(1);

	ListIterator<int> i = a.begin();
	i++;
	EXPECT_EQ(3, i.GetData());
}

TEST(list, cant_insert)
{
	List<int> a;
	ASSERT_ANY_THROW(a.insert(0, 195));
}

TEST(list, cant_remove)
{
	List<int> a;
	ASSERT_ANY_THROW(a.remove(5));
}

TEST(list, can_not_delete_in_empty_list)
{
	List<int> A;

	ASSERT_ANY_THROW(A.pop_front());
	ASSERT_ANY_THROW(A.pop_back());
}