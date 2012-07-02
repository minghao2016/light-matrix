/**
 * @file test_rep_vecs.cpp
 *
 * Unit testing of repeat vectors
 *
 * @author Dahua Lin
 */


#include "test_base.h"

#include <light_mat/matrix/const_matrix.h>
#include <light_mat/matrix/dense_matrix.h>
#include <light_mat/matrix/repeat_vecs.h>

using namespace lmat;
using namespace lmat::test;

// explicit instantiation

typedef dense_matrix<double, 0, 1> dcol_t;
typedef dense_matrix<double, 1, 0> drow_t;

template class lmat::repeat_col_expr<dcol_t, DynamicDim>;
template class lmat::repeat_col_expr<dcol_t, 6>;
template class lmat::repeat_row_expr<drow_t, DynamicDim>;
template class lmat::repeat_row_expr<drow_t, 4>;


#ifdef LMAT_USE_STATIC_ASSERT
static_assert(lmat::is_mat_xpr<lmat::repeat_col_expr<dcol_t> >::value, "Interface verification failed.");
static_assert(lmat::is_mat_xpr<lmat::repeat_row_expr<drow_t> >::value, "Interface verification failed.");
#endif


N_CASE( repcols, generic )
{
	const index_t m = N == 0 ? 4 : N;
	const index_t n = 6;

	typedef dense_matrix<double, N, 1> col_t;
	typedef repeat_col_expr<col_t> expr_t;

	col_t a(m, 1);

#ifdef LMAT_USE_STATIC_ASSERT
	static_assert( is_same<decltype(repcol(a, n)), expr_t>::value,
			"Expression type verification failed" );

	static_assert( ct_rows<expr_t>::value == N, "CT-size verification failed." );
	static_assert( ct_cols<expr_t>::value == 0, "CT-size verification failed." );
#endif

	expr_t expr = repcol(a, n);

	ASSERT_EQ( expr.nrows(), m );
	ASSERT_EQ( expr.ncolumns(), n );
	ASSERT_EQ( expr.nelems(), m * n);
	ASSERT_EQ( expr.size(), size_t(m * n) );

	ASSERT_EQ( &(expr.column()), &a );
}


MN_CASE( repcols, generic_fix )
{
	check_arg(N > 0, "N must be positive");

	const index_t m = M == 0 ? 4 : M;
	const index_t n = N;

	typedef dense_matrix<double, M, 1> col_t;
	typedef repeat_col_expr<col_t, N> expr_t;

	col_t a(m, 1);

#ifdef LMAT_USE_STATIC_ASSERT
	static_assert( is_same<decltype(repcol(a, fixed_dim<N>())), expr_t>::value,
			"Expression type verification failed" );

	static_assert( ct_rows<expr_t>::value == M, "CT-size verification failed." );
	static_assert( ct_cols<expr_t>::value == N, "CT-size verification failed." );
#endif

	expr_t expr = repcol(a, fixed_dim<N>());

	ASSERT_EQ( expr.nrows(), m );
	ASSERT_EQ( expr.ncolumns(), n );
	ASSERT_EQ( expr.nelems(), m * n);
	ASSERT_EQ( expr.size(), size_t(m * n) );

	ASSERT_EQ( &(expr.column()), &a );
}


N_CASE( repcols, const )
{
	const index_t m = N == 0 ? 4 : N;
	const index_t n = 6;
	const double val = 12.5;

	typedef const_matrix<double, N, 1> col_t;
	typedef const_matrix<double, N, DynamicDim> expr_t;

	col_t a(m, 1, val);

#ifdef LMAT_USE_STATIC_ASSERT
	static_assert( is_same<decltype(repcol(a, n)), expr_t>::value,
			"Expression type verification failed" );

	static_assert( ct_rows<expr_t>::value == N, "CT-size verification failed." );
	static_assert( ct_cols<expr_t>::value == 0, "CT-size verification failed." );
#endif

	expr_t expr = repcol(a, n);

	ASSERT_EQ( expr.nrows(), m );
	ASSERT_EQ( expr.ncolumns(), n );
	ASSERT_EQ( expr.nelems(), m * n);
	ASSERT_EQ( expr.size(), size_t(m * n) );

	ASSERT_EQ( expr.value(), val );
}


MN_CASE( repcols, const_fix )
{
	check_arg(N > 0, "N must be positive");

	const index_t m = M == 0 ? 4 : M;
	const index_t n = N;
	const double val = 12.5;

	typedef const_matrix<double, M, 1> col_t;
	typedef const_matrix<double, M, N> expr_t;

	col_t a(m, 1, val);

#ifdef LMAT_USE_STATIC_ASSERT
	static_assert( is_same<decltype(repcol(a, fixed_dim<N>())), expr_t>::value,
			"Expression type verification failed" );

	static_assert( ct_rows<expr_t>::value == M, "CT-size verification failed." );
	static_assert( ct_cols<expr_t>::value == N, "CT-size verification failed." );
#endif

	expr_t expr = repcol(a, fixed_dim<N>());

	ASSERT_EQ( expr.nrows(), m );
	ASSERT_EQ( expr.ncolumns(), n );
	ASSERT_EQ( expr.nelems(), m * n);
	ASSERT_EQ( expr.size(), size_t(m * n) );

	ASSERT_EQ( expr.value(), val );
}


N_CASE( reprows, generic )
{
	const index_t m = 4;
	const index_t n = N == 0 ? 6 : N;

	typedef dense_matrix<double, 1, N> row_t;
	typedef repeat_row_expr<row_t> expr_t;

	row_t a(1, n);

#ifdef LMAT_USE_STATIC_ASSERT
	static_assert( is_same<decltype(reprow(a, m)), expr_t>::value,
			"Expression type verification failed" );

	static_assert( ct_rows<expr_t>::value == 0, "CT-size verification failed." );
	static_assert( ct_cols<expr_t>::value == N, "CT-size verification failed." );
#endif

	expr_t expr = reprow(a, m);

	ASSERT_EQ( expr.nrows(), m );
	ASSERT_EQ( expr.ncolumns(), n );
	ASSERT_EQ( expr.nelems(), m * n);
	ASSERT_EQ( expr.size(), size_t(m * n) );

	ASSERT_EQ( &(expr.row()), &a );
}


MN_CASE( reprows, generic_fix )
{
	check_arg(M > 0, "M must be positive");

	const index_t m = M;
	const index_t n = N == 0 ? 6 : N;

	typedef dense_matrix<double, 1, N> row_t;
	typedef repeat_row_expr<row_t, M> expr_t;

	row_t a(1, n);

#ifdef LMAT_USE_STATIC_ASSERT
	static_assert( is_same<decltype(reprow(a, fixed_dim<M>())), expr_t>::value,
			"Expression type verification failed" );

	static_assert( ct_rows<expr_t>::value == M, "CT-size verification failed." );
	static_assert( ct_cols<expr_t>::value == N, "CT-size verification failed." );
#endif

	expr_t expr = reprow(a, fixed_dim<M>());

	ASSERT_EQ( expr.nrows(), m );
	ASSERT_EQ( expr.ncolumns(), n );
	ASSERT_EQ( expr.nelems(), m * n);
	ASSERT_EQ( expr.size(), size_t(m * n) );

	ASSERT_EQ( &(expr.row()), &a );
}


N_CASE( reprows, const )
{
	const index_t m = 4;
	const index_t n = N == 0 ? 6 : N;
	const double val = 12.5;

	typedef const_matrix<double, 1, N> row_t;
	typedef const_matrix<double, 0, N> expr_t;

	row_t a(1, n, val);

#ifdef LMAT_USE_STATIC_ASSERT
	static_assert( is_same<decltype(reprow(a, m)), expr_t>::value,
			"Expression type verification failed" );

	static_assert( ct_rows<expr_t>::value == 0, "CT-size verification failed." );
	static_assert( ct_cols<expr_t>::value == N, "CT-size verification failed." );
#endif

	expr_t expr = reprow(a, m);

	ASSERT_EQ( expr.nrows(), m );
	ASSERT_EQ( expr.ncolumns(), n );
	ASSERT_EQ( expr.nelems(), m * n);
	ASSERT_EQ( expr.size(), size_t(m * n) );

	ASSERT_EQ( expr.value(), val );
}

MN_CASE( reprows, const_fix )
{
	check_arg(M > 0, "M must be positive");

	const index_t m = M;
	const index_t n = N == 0 ? 6 : N;
	const double val = 12.5;

	typedef const_matrix<double, 1, N> row_t;
	typedef const_matrix<double, M, N> expr_t;

	row_t a(1, n, val);

#ifdef LMAT_USE_STATIC_ASSERT
	static_assert( is_same<decltype(reprow(a, fixed_dim<M>())), expr_t>::value,
			"Expression type verification failed" );

	static_assert( ct_rows<expr_t>::value == M, "CT-size verification failed." );
	static_assert( ct_cols<expr_t>::value == N, "CT-size verification failed." );
#endif

	expr_t expr = reprow(a, fixed_dim<M>());

	ASSERT_EQ( expr.nrows(), m );
	ASSERT_EQ( expr.ncolumns(), n );
	ASSERT_EQ( expr.nelems(), m * n);
	ASSERT_EQ( expr.size(), size_t(m * n) );

	ASSERT_EQ( expr.value(), val );
}


MN_CASE( repcols, eval )
{
	const index_t m = M == 0 ? 4 : M;
	const index_t n = N == 0 ? 6 : N;

	typedef dense_matrix<double, M, 1> col_t;

	col_t col(m, 1);
	for (index_t i = 0; i < m; ++i) col[i] = double(i + 2);

	typedef repeat_col_expr<col_t, N> expr_t;
	expr_t expr(col, n);

	ASSERT_EQ( expr.nrows(), m );
	ASSERT_EQ( expr.ncolumns(), n );

	dense_matrix<double, M, N> R( expr );

	dense_matrix<double, M, N> R_r(m, n);
	for (index_t j = 0; j < n; ++j)
	{
		for (index_t i = 0; i < m; ++i) R_r(i, j) = col(i, 0);
	}

	ASSERT_TRUE( is_equal(R, R_r) );
}


MN_CASE( reprows, eval )
{
	const index_t m = M == 0 ? 4 : M;
	const index_t n = N == 0 ? 6 : N;

	typedef dense_matrix<double, 1, N> row_t;

	row_t row(1, n);
	for (index_t j = 0; j < n; ++j) row[j] = double(j + 2);

	typedef repeat_row_expr<row_t, M> expr_t;
	expr_t expr(row, m);

	ASSERT_EQ( expr.nrows(), m );
	ASSERT_EQ( expr.ncolumns(), n );

	dense_matrix<double, M, N> R( expr );

	dense_matrix<double, M, N> R_r(m, n);
	for (index_t j = 0; j < n; ++j)
	{
		for (index_t i = 0; i < m; ++i) R_r(i, j) = row(0, j);
	}

	ASSERT_TRUE( is_equal(R, R_r) );
}



BEGIN_TPACK( repcols_generic )
	ADD_N_CASE( repcols, generic, 0 )
	ADD_N_CASE( repcols, generic, 1 )
	ADD_N_CASE( repcols, generic, 4 )
END_TPACK

BEGIN_TPACK( repcols_generic_fix )
	ADD_MN_CASE( repcols, generic_fix, 0, 1 )
	ADD_MN_CASE( repcols, generic_fix, 1, 1 )
	ADD_MN_CASE( repcols, generic_fix, 4, 1 )
	ADD_MN_CASE( repcols, generic_fix, 0, 6 )
	ADD_MN_CASE( repcols, generic_fix, 1, 6 )
	ADD_MN_CASE( repcols, generic_fix, 4, 6 )
END_TPACK

BEGIN_TPACK( repcols_const )
	ADD_N_CASE( repcols, const, 0 )
	ADD_N_CASE( repcols, const, 1 )
	ADD_N_CASE( repcols, const, 4 )
END_TPACK

BEGIN_TPACK( repcols_const_fix )
	ADD_MN_CASE( repcols, const_fix, 0, 1 )
	ADD_MN_CASE( repcols, const_fix, 1, 1 )
	ADD_MN_CASE( repcols, const_fix, 4, 1 )
	ADD_MN_CASE( repcols, const_fix, 0, 6 )
	ADD_MN_CASE( repcols, const_fix, 1, 6 )
	ADD_MN_CASE( repcols, const_fix, 4, 6 )
END_TPACK

BEGIN_TPACK( repcols_eval )
	ADD_MN_CASE( repcols, eval, 0, 0 )
	ADD_MN_CASE( repcols, eval, 0, 1 )
	ADD_MN_CASE( repcols, eval, 0, 6 )
	ADD_MN_CASE( repcols, eval, 1, 0 )
	ADD_MN_CASE( repcols, eval, 1, 1 )
	ADD_MN_CASE( repcols, eval, 1, 6 )
	ADD_MN_CASE( repcols, eval, 4, 0 )
	ADD_MN_CASE( repcols, eval, 4, 1 )
	ADD_MN_CASE( repcols, eval, 4, 6 )
END_TPACK


BEGIN_TPACK( reprows_generic )
	ADD_N_CASE( reprows, generic, 0 )
	ADD_N_CASE( reprows, generic, 1 )
	ADD_N_CASE( reprows, generic, 6 )
END_TPACK

BEGIN_TPACK( reprows_generic_fix )
	ADD_MN_CASE( reprows, generic_fix, 1, 0 )
	ADD_MN_CASE( reprows, generic_fix, 1, 1 )
	ADD_MN_CASE( reprows, generic_fix, 1, 6 )
	ADD_MN_CASE( reprows, generic_fix, 4, 0 )
	ADD_MN_CASE( reprows, generic_fix, 4, 1 )
	ADD_MN_CASE( reprows, generic_fix, 4, 6 )
END_TPACK

BEGIN_TPACK( reprows_const )
	ADD_N_CASE( reprows, const, 0 )
	ADD_N_CASE( reprows, const, 1 )
	ADD_N_CASE( reprows, const, 6 )
END_TPACK

BEGIN_TPACK( reprows_const_fix )
	ADD_MN_CASE( reprows, const_fix, 1, 0 )
	ADD_MN_CASE( reprows, const_fix, 1, 1 )
	ADD_MN_CASE( reprows, const_fix, 1, 6 )
	ADD_MN_CASE( reprows, const_fix, 4, 0 )
	ADD_MN_CASE( reprows, const_fix, 4, 1 )
	ADD_MN_CASE( reprows, const_fix, 4, 6 )
END_TPACK


BEGIN_TPACK( reprows_eval )
	ADD_MN_CASE( reprows, eval, 0, 0 )
	ADD_MN_CASE( reprows, eval, 0, 1 )
	ADD_MN_CASE( reprows, eval, 0, 6 )
	ADD_MN_CASE( reprows, eval, 1, 0 )
	ADD_MN_CASE( reprows, eval, 1, 1 )
	ADD_MN_CASE( reprows, eval, 1, 6 )
	ADD_MN_CASE( reprows, eval, 4, 0 )
	ADD_MN_CASE( reprows, eval, 4, 1 )
	ADD_MN_CASE( reprows, eval, 4, 6 )
END_TPACK


BEGIN_MAIN_SUITE
	ADD_TPACK( repcols_generic )
	ADD_TPACK( repcols_generic_fix )
	ADD_TPACK( repcols_const )
	ADD_TPACK( repcols_const_fix )
	ADD_TPACK( repcols_eval )

	ADD_TPACK( reprows_generic )
	ADD_TPACK( reprows_generic_fix )
	ADD_TPACK( reprows_const )
	ADD_TPACK( reprows_const_fix )
	ADD_TPACK( reprows_eval )
END_MAIN_SUITE





