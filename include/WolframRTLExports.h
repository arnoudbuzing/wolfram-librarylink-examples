/*************************************************************************
                        Mathematica source file

        Copyright 1986 through 2000 by Wolfram Research Inc.

This material contains trade secrets and may be registered with the
U.S. Copyright Office as an unpublished work, pursuant to Title 17,
U.S. Code, Section 408.  Unauthorized copying, adaptation, distribution
or display is prohibited.

$Id$

*************************************************************************/

#ifndef WOLFRAMRTLEXPORTS_H
#define WOLFRAMRTLEXPORTS_H

#if !(defined(MATHEMATICA_KERNEL) || defined(MATHEMATICA_RUNTIME))

typedef unsigned int UBIT32;

#endif

#include "rtl_processor_count.h"

/* Utilities and globals for increments */

#include "machfunc_increments.h"

#ifdef __cplusplus
extern "C" {
#endif

/* 
   One argument Listable function prototypes.
   These functions all return an errorflag
   On success, the first argument reference is modified with the result 
*/

extern RTL_DLL_EXPORT errcode_t machfunc_d_vectornorm(mreal *, const mint, const mreal *, const mint, const mint, const UBIT32);
extern RTL_DLL_EXPORT errcode_t machfunc_c_vectornorm(mreal *, const mint, const mcomplex *, const mint, const mint, const UBIT32);

extern RTL_DLL_EXPORT errcode_t machfunc_d_weightedvectornorm(mreal *, const mint, const mreal *, const mreal *, const mint, const mbool, const UBIT32);
extern RTL_DLL_EXPORT errcode_t machfunc_c_weightedvectornorm(mreal *, const mint, const mcomplex *, const mreal *, const mint, const mbool, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_d_vectornormweights(mreal *, const mreal, const mreal, const mreal *, const mint, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_vectornormweights(mreal *, const mreal, const mreal, const mcomplex *, const mint, const UBIT32);

extern RTL_DLL_EXPORT errcode_t machfunc_d_scaledvectornorm(mreal *, const mint, const mreal, const mreal, const mreal *, const mreal *, const mint, const mbool, const UBIT32);
extern RTL_DLL_EXPORT errcode_t machfunc_c_scaledvectornorm(mreal *, const mint, const mreal, const mreal, const mcomplex *, const mcomplex *, const mint, const mbool, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_i_total(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_total(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_total(void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_i_min(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_min(void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_i_max(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_max(void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_i_maxabs(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_maxabs(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_maxabs(void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_i_fibonacci(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_i_lucasl(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_i_log2(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_i_log10(void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_d_round(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_floor(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_iteratorfloor(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_ceiling(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_intpart(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_fracpart(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_fracpart(void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_d_fibonacci(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_lucasl(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_sqrt(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_rsqrt(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_cbrt(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_exp(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_expm1(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_log(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_log1p(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_log2(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_log10(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_sin(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_asin(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_cos(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_acos(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_tan(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_atan(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_sinh(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_asinh(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_cosh(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_acosh(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_tanh(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_atanh(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_recip(void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_c_fibonacci(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_lucasl(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_recip(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_sqrt(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_rsqrt(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_cbrt(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_arg(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_sin(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_cos(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_tan(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_sinh(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_cosh(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_tanh(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_asin(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_acos(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_atan(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_asinh(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_acosh(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_atanh(void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_i_abs(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_abs(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_abs(void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_i_abssquare(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_abssquare(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_abssquare(void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_i_copy(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_copy(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_copy(void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_i_conj(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_conj(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_conj(void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_i_minus(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_minus(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_minus(void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_i_square(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_square(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_square(void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_i_zero(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_zero(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_zero(void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_c_log(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_log1p(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_log2(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_log10(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_exp(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_expm1(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_root(mcomplex *, const mcomplex *, const mint *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_d_sinc(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_sinc(void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_d_gudermannian(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_gudermannian(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_inversegudermannian(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_inversegudermannian(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_haversine(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_haversine(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_inversehaversine(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_inversehaversine(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_erf(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_erfc(void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_i_gamma(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_d_gamma(void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_d_loggamma(void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_d_logistic(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_c_logistic(void *, const void *, const mint, const mint *, const UBIT32);

/* 
   Two argument Listable function prototypes.
   These functions all return an errorflag
   On success, the first argument reference is modified with the result 
*/

extern RTL_DLL_EXPORT mint machfunc_ii_dot(void *, const void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_dd_quotient(void *, const void *, const void *, const mint, const mint *, const UBIT32); 
extern RTL_DLL_EXPORT mint machfunc_dd_mod(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_ii_mod(void *, const void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_ii_bitand(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_ii_bitor(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_ii_bitxor(void *, const void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_ii_plus(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_dd_plus(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_id_plus(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_dc_plus(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_ic_plus(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_cc_plus(void *, const void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_ii_subtract(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_dd_subtract(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_id_subtract(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_di_subtract(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_ic_subtract(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_ci_subtract(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_dc_subtract(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_cd_subtract(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_cc_subtract(void *, const void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_ii_times(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_dd_times(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_id_times(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_di_times(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_ic_times(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_ci_times(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_dc_times(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_cd_times(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_cc_times(void *, const void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_id_div(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_di_div(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_dd_div(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_ic_div(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_ci_div(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_dc_div(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_cd_div(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_cc_div(void *, const void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_ii_pow(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_id_pow(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_di_pow(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_dd_pow(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_ic_pow(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_ci_pow(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_dc_pow(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_cd_pow(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_cc_pow(void *, const void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_ii_abserr(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_dd_abserr(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_cc_abserr(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_dd_relerr(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_cc_relerr(void *, const void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_ii_maxabs(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_dd_maxabs(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_cc_maxabs(void *, const void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_i_intexp(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_ii_intexp(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_i_intlen(void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_ii_intlen(void *, const void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_ii_bitshiftleft(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_ii_bitshiftright(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_di_bitshiftleft(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_di_bitshiftright(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_ci_bitshiftleft(void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_ci_bitshiftright(void *, const void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_bb_bitxor(void *, const void *, const void *, const mint, const mint *, const UBIT32);

/* Three argument machine functions */

extern RTL_DLL_EXPORT mint machfunc_iii_axpy(void *, const void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_ddd_axpy(void *, const void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_ccc_axpy(void *, const void *, const void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_iii_axmy(void *, const void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_ddd_axmy(void *, const void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_ccc_axmy(void *, const void *, const void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_iii_ymax(void *, const void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_ddd_ymax(void *, const void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_ccc_ymax(void *, const void *, const void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_ddd_adxmy(void *, const void *, const void *, const void *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_ccc_adxmy(void *, const void *, const void *, const void *, const mint, const mint *, const UBIT32);

extern RTL_DLL_EXPORT mint machfunc_ddd_compplus(mreal *, const mreal *, const mreal *, mreal *, const mint, const mint *, const UBIT32);
extern RTL_DLL_EXPORT mint machfunc_ccc_compplus(mcomplex *, const mcomplex *, const mcomplex *, mcomplex *, const mint, const mint *, const UBIT32);

#ifdef __cplusplus
}
#endif

#endif
