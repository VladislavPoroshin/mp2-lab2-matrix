#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
	TDynamicMatrix<int> m(5);

	ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> A;
	TDynamicMatrix<int> B(A);
	EXPECT_EQ(1, B == A);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> A;
	TDynamicMatrix<int> B(A);
	EXPECT_EQ(0, &B == &A);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> A(6);
	EXPECT_EQ(6, A.GetSize());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> A(6);
	A[5][5] = 6;
	EXPECT_EQ(6, A[5][5]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> A(6);
	ASSERT_ANY_THROW((A.at(-5)).at(5) = 6);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> A(6);
	ASSERT_ANY_THROW((A.at(7)).at(5) = 6);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	ASSERT_NO_THROW(TDynamicMatrix<TDynamicMatrix<int>> m(5));
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> B(5), A(5);
	EXPECT_EQ(1, A.GetSize() == B.GetSize());
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> B(7), A(5);
	A = A.ReSizeM(7);
	EXPECT_EQ(1, A.GetSize() == B.GetSize());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> B(5), A(6);
	EXPECT_EQ(0, A.GetSize() == B.GetSize());
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> a(5), b(5);
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = i; j < 5; j++)
		{
			a[i][j] = i * 10 + j;
			b[i][j] = i * 10 + j;
		}
	EXPECT_EQ(1, a == b);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> a(5);
	EXPECT_EQ(1, a == a);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> B(7), A(5);
	EXPECT_EQ(0, A == B);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> a(5), b(5), c(5);
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = i; j < 5; j++)
		{
			a[i][j] = i * 10 + j;
			b[i][j] = i * 10 + j;
		}
	ASSERT_NO_THROW(a + b);
	c = a + b;
	EXPECT_EQ(c, a * 2);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> a(5), b(7);
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = i; j < 5; j++)
		{
			a[i][j] = i * 10 + j;
			b[i][j] = i * 10 + j;
		}
	ASSERT_ANY_THROW(a + b);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> a(5), b(5), c(5);
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = i; j < 5; j++)
		{
			a[i][j] = i * 10 + j;
			b[i][j] = i * 10 + j;
		}
	ASSERT_NO_THROW(a - b);
	c = a - b;
	EXPECT_EQ(c, a * 0);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> a(5), b(7);
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = i; j < 5; j++)
		{
			a[i][j] = i * 10 + j;
			b[i][j] = i * 10 + j;
		}
	ASSERT_ANY_THROW(a - b);
}

