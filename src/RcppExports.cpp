// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// merge
int merge(NumericVector x, int l, int m, int r);
RcppExport SEXP _kendall_merge(SEXP xSEXP, SEXP lSEXP, SEXP mSEXP, SEXP rSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type l(lSEXP);
    Rcpp::traits::input_parameter< int >::type m(mSEXP);
    Rcpp::traits::input_parameter< int >::type r(rSEXP);
    rcpp_result_gen = Rcpp::wrap(merge(x, l, m, r));
    return rcpp_result_gen;
END_RCPP
}
// mergeSort
int mergeSort(NumericVector x, int l, int r);
RcppExport SEXP _kendall_mergeSort(SEXP xSEXP, SEXP lSEXP, SEXP rSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type l(lSEXP);
    Rcpp::traits::input_parameter< int >::type r(rSEXP);
    rcpp_result_gen = Rcpp::wrap(mergeSort(x, l, r));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_kendall_merge", (DL_FUNC) &_kendall_merge, 4},
    {"_kendall_mergeSort", (DL_FUNC) &_kendall_mergeSort, 3},
    {NULL, NULL, 0}
};

RcppExport void R_init_kendall(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
