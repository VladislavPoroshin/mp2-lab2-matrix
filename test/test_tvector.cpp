#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
	ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
	TDynamicVector<int> v(10);

	ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> m(v);
	EXPECT_EQ(1, m == v);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> v(10);
	TDynamicVector<int> m(v);
	EXPECT_EQ(0, &m == &v);
}

TEST(TDynamicVector, can_get_size)
{
	TDynamicVector<int> v(4);

	EXPECT_EQ(4, v.size());
}

//TEST(TDynamicVector, can_set_and_get_element)
//{
//  TDynamicVector<int> v(4);
//  v[0] = 4;
//
//  EXPECT_EQ(4, v[0]);
//}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	ASSERT_ANY_THROW(TDynamicVector<int> v(2); v.at(-1) = 6);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	ASSERT_ANY_THROW(TDynamicVector<int> v(2); v.at(6) = 6);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	ASSERT_NO_THROW(TDynamicVector<TDynamicVector<int>> m(5));
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> B(5), A(5);
	EXPECT_EQ(1, A.GetSize() == B.GetSize());
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> B(7), A(5);
	A = A.ReSizeV(7);
	EXPECT_EQ(1, A.GetSize() == B.GetSize());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> B(5), A(6);
	EXPECT_EQ(0, A.GetSize() == B.GetSize());
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> a(5), b(5);
	int j;
	for (j = 0; j < 5; j++)
	{
		a[j] = 10 + j;
		b[j] = 10 + j;
	}
	EXPECT_EQ(1, a == b);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> a(5);
	EXPECT_EQ(1, a == a);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> B(7), A(5);
	EXPECT_EQ(0, A == B);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> B(7);
	B = B + 7;
	TDynamicVector<int> A(7);
	for (int i = 0; i < A.GetSize(); i++)
		A[i] = 7;
	EXPECT_EQ(1, A == B);
	ASSERT_NO_THROW(B + 9);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> B(7);
	B = B - 7;
	TDynamicVector<int> A(7);
	for (int i = 0; i < A.GetSize(); i++)
		A[i] = -7;
	EXPECT_EQ(1, A == B);
	ASSERT_NO_THROW(B - 9);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int> B(7);
	B = B * 7;
	TDynamicVector<int> A(7);
	EXPECT_EQ(1, A == B);
	ASSERT_NO_THROW(B * 9);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> a(5), b(5), c(5);
	int j;
	for (j = 0; j < 5; j++)
	{
		a[j] = 10 + j;
		b[j] = 10 + j;
	}
	ASSERT_NO_THROW(a + b);
	c = a + b;
	EXPECT_EQ(c, a * 2);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> a(5), b(7);
	ASSERT_ANY_THROW(a + b);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> a(5), b(5), c(5);
	int j;
	for (j = 0; j < 5; j++)
	{
		a[j] = 10 + j;
		b[j] = 10 + j;
	}
	ASSERT_NO_THROW(a - b);
	c = a - b;
	EXPECT_EQ(c, a * 0);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> a(5), b(7);
	ASSERT_ANY_THROW(a - b);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> a(5), b(5);
	int m;
	int j;
	for (j = 0; j < 5; j++)
	{
		a[j] = 1;
		b[j] = 1;
	}
	ASSERT_NO_THROW(a * b);
	m = a * b;
	EXPECT_EQ(5, m);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> a(5), b(7);
	ASSERT_ANY_THROW(a * b);
}

