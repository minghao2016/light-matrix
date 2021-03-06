/**
 * @file test_avx_round.cpp
 *
 * Test AVX rounding functions
 * 
 * @author Dahua Lin 
 */


#include "simd_test_base.h"
#include <light_mat/simd/avx_arith.h>

using namespace lmat;
using namespace lmat::test;


using lmat::math::floor;
using lmat::math::ceil;
using lmat::math::trunc;
using lmat::math::round;

static float sa[8] = { -1.2f, -1.5f, -1.7f, -2.0f, 2.2f, 2.5f, 2.7f, 3.0f };
static double da1[4] = { -1.2, -1.5, -1.7, -2.0 };
static double da2[4] = { 2.2, 2.5, 2.7, 3.0 };


SIMPLE_CASE( avx_floor_f32 )
{
	avx_f32pk a; a.load_u(sa);

	float r[8] = { -2.0f, -2.0f, -2.0f, -2.0f, 2.0f, 2.0f, 2.0f, 3.0f };

	ASSERT_SIMD_EQ( floor(a), r );
}

SIMPLE_CASE( avx_floor_f64 )
{
	avx_f64pk a1; a1.load_u(da1);
	avx_f64pk a2; a2.load_u(da2);

	double r1[4] = { -2.0, -2.0, -2.0, -2.0 };
	double r2[4] = { 2.0, 2.0, 2.0, 3.0 };

	ASSERT_SIMD_EQ( floor(a1), r1 );
	ASSERT_SIMD_EQ( floor(a2), r2 );
}


SIMPLE_CASE( avx_ceil_f32 )
{
	avx_f32pk a; a.load_u(sa);

	float r[8] = { -1.0f, -1.0f, -1.0f, -2.0f, 3.0f, 3.0f, 3.0f, 3.0f };

	ASSERT_SIMD_EQ( ceil(a), r );
}

SIMPLE_CASE( avx_ceil_f64 )
{
	avx_f64pk a1; a1.load_u(da1);
	avx_f64pk a2; a2.load_u(da2);

	double r1[4] = { -1.0, -1.0, -1.0, -2.0 };
	double r2[4] = { 3.0, 3.0, 3.0, 3.0 };

	ASSERT_SIMD_EQ( ceil(a1), r1 );
	ASSERT_SIMD_EQ( ceil(a2), r2 );
}


SIMPLE_CASE( avx_trunc_f32 )
{
	avx_f32pk a; a.load_u(sa);

	float r[8] = { -1.0f, -1.0f, -1.0f, -2.0f, 2.0f, 2.0f, 2.0f, 3.0f };

	ASSERT_SIMD_EQ( trunc(a), r );
}

SIMPLE_CASE( avx_trunc_f64 )
{
	avx_f64pk a1; a1.load_u(da1);
	avx_f64pk a2; a2.load_u(da2);

	double r1[4] = { -1.0, -1.0, -1.0, -2.0 };
	double r2[4] = { 2.0, 2.0, 2.0, 3.0 };

	ASSERT_SIMD_EQ( trunc(a1), r1 );
	ASSERT_SIMD_EQ( trunc(a2), r2 );
}


SIMPLE_CASE( avx_round_f32 )
{
	avx_f32pk a; a.load_u(sa);

	float r[8] = { -1.0f, -2.0f, -2.0f, -2.0f, 2.0f, 2.0f, 3.0f, 3.0f };

	ASSERT_SIMD_EQ( round(a), r );
}

SIMPLE_CASE( avx_round_f64 )
{
	avx_f64pk a1; a1.load_u(da1);
	avx_f64pk a2; a2.load_u(da2);

	double r1[4] = { -1.0, -2.0, -2.0, -2.0 };
	double r2[4] = { 2.0, 2.0, 3.0, 3.0 };

	ASSERT_SIMD_EQ( round(a1), r1 );
	ASSERT_SIMD_EQ( round(a2), r2 );
}


AUTO_TPACK( avx_round )
{
	ADD_SIMPLE_CASE( avx_floor_f32 )
	ADD_SIMPLE_CASE( avx_floor_f64 )
	ADD_SIMPLE_CASE( avx_ceil_f32 )
	ADD_SIMPLE_CASE( avx_ceil_f64 )
	ADD_SIMPLE_CASE( avx_trunc_f32 )
	ADD_SIMPLE_CASE( avx_trunc_f64 )
	ADD_SIMPLE_CASE( avx_round_f32 )
	ADD_SIMPLE_CASE( avx_round_f64 )
}


