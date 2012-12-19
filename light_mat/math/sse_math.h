/**
 * @file sse_math.h
 *
 * SSE math functions
 * 
 * @author Dahua Lin 
 */

#ifdef _MSC_VER
#pragma once
#endif

#ifndef LIGHTMAT_SSE_MATH_H_
#define LIGHTMAT_SSE_MATH_H_

#include <light_mat/math/sse_ops.h>
#include "internal/sse_math_emulate.h"

#if defined(LMAT_USE_INTEL_SVML) && defined(LMAT_USE_AMD_LIBM)
#error SVML and LIBM cannot be used simultaneously.
#endif


#ifdef LMAT_USE_INTEL_SVML

// External function prototypes

#define LMAT_SVML_SSE_F( name ) __svml_##name##f4
#define LMAT_SVML_SSE_D( name ) __svml_##name##2

#define LMAT_DECLARE_SVML_SSE_EXTERN1( name ) \
	__m128  LMAT_SVML_SSE_F(name)( __m128 ); \
	__m128d LMAT_SVML_SSE_D(name)( __m128d );

#define LMAT_DECLARE_SVML_SSE_EXTERN2( name ) \
	__m128  LMAT_SVML_SSE_F(name)( __m128,  __m128  ); \
	__m128d LMAT_SVML_SSE_D(name)( __m128d, __m128d );

#define LMAT_SSE_F( name ) LMAT_SVML_SSE_F( name )
#define LMAT_SSE_D( name ) LMAT_SVML_SSE_D( name )

extern "C"
{
	// C++ 03

#define LMAT_HAS_EXTERN_SSE_POW
#define LMAT_HAS_EXTERN_SSE_EXPLOG
#define LMAT_HAS_EXTERN_SSE_TRI
#define LMAT_HAS_EXTERN_SSE_ARCTRI
#define LMAT_HAS_EXTERN_SSE_HYPERB

	LMAT_DECLARE_SVML_SSE_EXTERN2( pow )
	LMAT_DECLARE_SVML_SSE_EXTERN1( exp )
	LMAT_DECLARE_SVML_SSE_EXTERN1( log )
	LMAT_DECLARE_SVML_SSE_EXTERN1( log10 )

	LMAT_DECLARE_SVML_SSE_EXTERN1( sin )
	LMAT_DECLARE_SVML_SSE_EXTERN1( cos )
	LMAT_DECLARE_SVML_SSE_EXTERN1( tan )

	LMAT_DECLARE_SVML_SSE_EXTERN1( asin )
	LMAT_DECLARE_SVML_SSE_EXTERN1( acos )
	LMAT_DECLARE_SVML_SSE_EXTERN1( atan )
	LMAT_DECLARE_SVML_SSE_EXTERN2( atan2 )

	LMAT_DECLARE_SVML_SSE_EXTERN1( sinh )
	LMAT_DECLARE_SVML_SSE_EXTERN1( cosh )
	LMAT_DECLARE_SVML_SSE_EXTERN1( tanh )

	// C++ 11

#define LMAT_HAS_EXTERN_SSE_HYPOT
#define LMAT_HAS_EXTERN_SSE_CBRT
#define LMAT_HAS_EXTERN_SSE_EXPLOG2
#define LMAT_HAS_EXTERN_SSE_EXPLOG_EX
#define LMAT_HAS_EXTERN_SSE_ARCHYPERB
#define LMAT_HAS_EXTERN_SSE_ERF
// #define LMAT_HAS_EXTERN_SSE_GAMMA

	LMAT_DECLARE_SVML_SSE_EXTERN2( hypot )
	LMAT_DECLARE_SVML_SSE_EXTERN1( cbrt )

	LMAT_DECLARE_SVML_SSE_EXTERN1( exp2 )
	LMAT_DECLARE_SVML_SSE_EXTERN1( log2 )
	LMAT_DECLARE_SVML_SSE_EXTERN1( expm1 )
	LMAT_DECLARE_SVML_SSE_EXTERN1( log1p )

	LMAT_DECLARE_SVML_SSE_EXTERN1( asinh )
	LMAT_DECLARE_SVML_SSE_EXTERN1( acosh )
	LMAT_DECLARE_SVML_SSE_EXTERN1( atanh )

	LMAT_DECLARE_SVML_SSE_EXTERN1( erf )
	LMAT_DECLARE_SVML_SSE_EXTERN1( erfc )

	// other functions

	LMAT_DECLARE_SVML_SSE_EXTERN1( exp10 )
	LMAT_DECLARE_SVML_SSE_EXTERN1( cdfnorm )
	LMAT_DECLARE_SVML_SSE_EXTERN1( cdfnorminv )

}

#elif defined(LMAT_USE_AMD_LIBM)

#define LMAT_LIBM_SSE_F( name ) amd_vrs4_##name##f
#define LMAT_LIBM_SSE_D( name ) amd_vrd2_##name

#define LMAT_DECLARE_LIBM_SSE_EXTERN1( name ) \
	__m128  LMAT_LIBM_SSE_F(name)( __m128 ); \
	__m128d LMAT_LIBM_SSE_D(name)( __m128d );

#define LMAT_DECLARE_LIBM_SSE_EXTERN2( name ) \
	__m128  LMAT_LIBM_SSE_F(name)( __m128,  __m128  ); \
	__m128d LMAT_LIBM_SSE_D(name)( __m128d, __m128d );

#define LMAT_SSE_F( name ) LMAT_LIBM_SSE_F( name )
#define LMAT_SSE_D( name ) LMAT_LIBM_SSE_D( name )

extern "C"
{
	// C++ 03

#define LMAT_HAS_EXTERN_SSE_POW
#define LMAT_HAS_EXTERN_SSE_EXPLOG
#define LMAT_HAS_EXTERN_SSE_TRI
// #define LMAT_HAS_EXTERN_SSE_ARCTRI
// #define LMAT_HAS_EXTERN_SSE_HYPERB

	DECLARE_LIBM_SSE_EXTERN2( pow )
	DECLARE_LIBM_SSE_EXTERN1( exp )
	DECLARE_LIBM_SSE_EXTERN1( log )
	DECLARE_LIBM_SSE_EXTERN1( log10 )

	DECLARE_LIBM_SSE_EXTERN1( sin )
	DECLARE_LIBM_SSE_EXTERN1( cos )
	DECLARE_LIBM_SSE_EXTERN1( tan )

	// C++ 11

// #define LMAT_HAS_EXTERN_SSE_HYPOT
#define LMAT_HAS_EXTERN_SSE_CBRT
#define LMAT_HAS_EXTERN_SSE_EXPLOG2
#define LMAT_HAS_EXTERN_SSE_EXPLOG_EX
// #define LMAT_HAS_EXTERN_SSE_ARCHYPERB
// #define LMAT_HAS_EXTERN_SSE_ERF
// #define LMAT_HAS_EXTERN_SSE_GAMMA

	DECLARE_LIBM_SSE_EXTERN1( cbrt )

	DECLARE_LIBM_SSE_EXTERN1( exp2 )
	DECLARE_LIBM_SSE_EXTERN1( log2 )
	DECLARE_LIBM_SSE_EXTERN1( expm1 )
	DECLARE_LIBM_SSE_EXTERN1( log1p )

	// other

	DECLARE_LIBM_SSE_EXTERN1( exp10 )
}

#endif  // vector library choice


#define LMAT_ACTIVATE_SSE_EXTERN_1( Name ) \
	LMAT_ENSURE_INLINE \
	inline sse_f32pk Name( const sse_f32pk& a ) { \
		return LMAT_SSE_F(Name)(a); } \
	LMAT_ENSURE_INLINE \
	inline sse_f64pk Name( const sse_f64pk& a ) { \
		return LMAT_SSE_D(Name)(a); } \
	struct has_sse_##Name { static const bool value = true; };

#define LMAT_ACTIVATE_SSE_EXTERN_2( Name ) \
	LMAT_ENSURE_INLINE \
	inline sse_f32pk Name( const sse_f32pk& a, const sse_f32pk& b ) { \
		return LMAT_SSE_F(Name)(a, b); } \
	LMAT_ENSURE_INLINE \
	inline sse_f64pk Name( const sse_f64pk& a, const sse_f64pk& b ) { \
		return LMAT_SSE_D(Name)(a, b); } \
	struct has_sse_##Name { static const bool value = true; };


namespace lmat { namespace math {

	// C++ 03

#ifdef LMAT_HAS_EXTERN_SSE_POW
	LMAT_ACTIVATE_SSE_EXTERN_2( pow )
#elif (defined(LMAT_ENABLE_SIMD_EMULATE))
	LMAT_ACTIVATE_SSE_MATH_EMULATE_2( pow )
#endif


#ifdef LMAT_HAS_EXTERN_SSE_EXPLOG
	LMAT_ACTIVATE_SSE_EXTERN_1( exp )
	LMAT_ACTIVATE_SSE_EXTERN_1( log )
	LMAT_ACTIVATE_SSE_EXTERN_1( log10 )

	LMAT_ENSURE_INLINE
	inline sse_f32pk xlogy(const sse_f32pk& a, const sse_f32pk& b)
	{
		sse_f32pk z = sse_f32pk::zeros();
		return cond(a > z, log(b), z) * a;
	}

	LMAT_ENSURE_INLINE
	inline sse_f64pk xlogy(const sse_f64pk& a, const sse_f64pk& b)
	{
		sse_f64pk z = sse_f64pk::zeros();
		return cond(a > z, log(b), z) * a;
	}

	struct has_sse_xlogy { static const bool value = true; };


#elif (defined(LMAT_ENABLE_SIMD_EMULATE))
	LMAT_ACTIVATE_SSE_MATH_EMULATE_1( exp )
	LMAT_ACTIVATE_SSE_MATH_EMULATE_1( log )
	LMAT_ACTIVATE_SSE_MATH_EMULATE_1( log10 )
	LMAT_ACTIVATE_SSE_MATH_EMULATE_2( xlogy )
#endif


#ifdef LMAT_HAS_EXTERN_SSE_TRI
	LMAT_ACTIVATE_SSE_EXTERN_1( sin )
	LMAT_ACTIVATE_SSE_EXTERN_1( cos )
	LMAT_ACTIVATE_SSE_EXTERN_1( tan )
#elif (defined(LMAT_ENABLE_SIMD_EMULATE))
	LMAT_ACTIVATE_SSE_MATH_EMULATE_1( sin )
	LMAT_ACTIVATE_SSE_MATH_EMULATE_1( cos )
	LMAT_ACTIVATE_SSE_MATH_EMULATE_1( tan )
#endif


#ifdef LMAT_HAS_EXTERN_SSE_ARCTRI
	LMAT_ACTIVATE_SSE_EXTERN_1( asin )
	LMAT_ACTIVATE_SSE_EXTERN_1( acos )
	LMAT_ACTIVATE_SSE_EXTERN_1( atan )
	LMAT_ACTIVATE_SSE_EXTERN_2( atan2 )
#elif (defined(LMAT_ENABLE_SIMD_EMULATE))
	LMAT_ACTIVATE_SSE_MATH_EMULATE_1( asin )
	LMAT_ACTIVATE_SSE_MATH_EMULATE_1( acos )
	LMAT_ACTIVATE_SSE_MATH_EMULATE_1( atan )
	LMAT_ACTIVATE_SSE_MATH_EMULATE_2( atan2 )
#endif


#ifdef LMAT_HAS_EXTERN_SSE_HYPERB
	LMAT_ACTIVATE_SSE_EXTERN_1( sinh )
	LMAT_ACTIVATE_SSE_EXTERN_1( cosh )
	LMAT_ACTIVATE_SSE_EXTERN_1( tanh )
#elif (defined(LMAT_ENABLE_SIMD_EMULATE))
	LMAT_ACTIVATE_SSE_MATH_EMULATE_1( sinh )
	LMAT_ACTIVATE_SSE_MATH_EMULATE_1( cosh )
	LMAT_ACTIVATE_SSE_MATH_EMULATE_1( tanh )
#endif

	// C++ 11

#ifdef LMAT_HAS_CXX11_MATH

#ifdef LMAT_HAS_EXTERN_SSE_HYPOT
	LMAT_ACTIVATE_SSE_EXTERN_2( hypot )
#elif (defined(LMAT_ENABLE_SIMD_EMULATE))
	LMAT_ACTIVATE_SSE_MATH_EMULATE_2( hypot )
#endif


#ifdef LMAT_HAS_EXTERN_SSE_CBRT
	LMAT_ACTIVATE_SSE_EXTERN_1( cbrt )
#elif (defined(LMAT_ENABLE_SIMD_EMULATE))
	LMAT_ACTIVATE_SSE_MATH_EMULATE_1( cbrt )
#endif


#ifdef LMAT_HAS_EXTERN_SSE_EXPLOG2
	LMAT_ACTIVATE_SSE_EXTERN_1( exp2 )
	LMAT_ACTIVATE_SSE_EXTERN_1( log2 )
#elif (defined(LMAT_ENABLE_SIMD_EMULATE))
	LMAT_ACTIVATE_SSE_MATH_EMULATE_1( exp2 )
	LMAT_ACTIVATE_SSE_MATH_EMULATE_1( log2 )
#endif


#ifdef LMAT_HAS_EXTERN_SSE_EXPLOG_EX
	LMAT_ACTIVATE_SSE_EXTERN_1( expm1 )
	LMAT_ACTIVATE_SSE_EXTERN_1( log1p )
#elif (defined(LMAT_ENABLE_SIMD_EMULATE))
	LMAT_ACTIVATE_SSE_MATH_EMULATE_1( expm1 )
	LMAT_ACTIVATE_SSE_MATH_EMULATE_1( log1p )
#endif


#ifdef LMAT_HAS_EXTERN_SSE_ARCHYPERB
	LMAT_ACTIVATE_SSE_EXTERN_1( asinh )
	LMAT_ACTIVATE_SSE_EXTERN_1( acosh )
	LMAT_ACTIVATE_SSE_EXTERN_1( atanh )
#elif (defined(LMAT_ENABLE_SIMD_EMULATE))
	LMAT_ACTIVATE_SSE_MATH_EMULATE_1( asinh )
	LMAT_ACTIVATE_SSE_MATH_EMULATE_1( acosh )
	LMAT_ACTIVATE_SSE_MATH_EMULATE_1( atanh )
#endif


#ifdef LMAT_HAS_EXTERN_SSE_ERF
	LMAT_ACTIVATE_SSE_EXTERN_1( erf )
	LMAT_ACTIVATE_SSE_EXTERN_1( erfc )
#elif (defined(LMAT_ENABLE_SIMD_EMULATE))
	LMAT_ACTIVATE_SSE_MATH_EMULATE_1( erf )
	LMAT_ACTIVATE_SSE_MATH_EMULATE_1( erfc )
#endif

#ifdef LMAT_HAS_EXTERN_SSE_GAMMA
	LMAT_ACTIVATE_SSE_EXTERN_1( lgamma )
	LMAT_ACTIVATE_SSE_EXTERN_1( tgamma )
#elif (defined(LMAT_ENABLE_SIMD_EMULATE))
	LMAT_ACTIVATE_SSE_MATH_EMULATE_1( lgamma )
	LMAT_ACTIVATE_SSE_MATH_EMULATE_1( tgamma )
#endif

#endif // has C++11 math





} }


#endif 
