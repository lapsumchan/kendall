#include <Rcpp.h>
using namespace Rcpp;

//' Finding inversion count by merging the left and right subset
//'
//' @param x       A vector containing real numbers with no ties
//' @param l       Index of the beginning (inclusive) of left subset
//' @param m       Index of the end (exclusive) of left subset and start (inclusive) of right subset
//' @param r       Index of the end (exclusive) of right subset
//' @return \code{inv} Inversion count
// [[Rcpp::export]]
int merge(NumericVector x, int l, int m, int r) {
  NumericVector tmp(r-l+1);
  int i, j, k;
  int inv = 0;
  
  // Index for left vector
  i = l;
  
  // Index for right vector
  j = m;
  
  // Index for merged vector
  k = 0;
  
  while ((i < m) && (j < r)) {
    if (x[i] < x[j]) {
      tmp[k++] = x[i++];
    }
    else {
      tmp[k++] = x[j++];
      // Count inversion
      inv += m - i;
    }
  }
  
  // Copy the remaining elements of left vector to tmp (if any)
  while (i < m) {
    tmp[k++] = x[i++];
  }
  
  // Copy the remaining elements of right vector to tmp (if any)
  while (j < r) {
    tmp[k++] = x[j++];
  }
  
  // Copy back to the original vector to reflect sorted order
  for (i = l; i < r; i++) {
    x[i] = tmp[i-l];
  }
  return inv;
}

//' Finding inversion count of a vector using merge sort by divide-and-conquer
//'
//' @param x       A vector containing real numbers with no ties
//' @param l       Index of the beginning (inclusive) of the subset to be sorted
//' @param r       Index of the end (exclusive) of the subset to be sorted
//' @return \code{inv} Inversion count
// [[Rcpp::export]]
int mergeSort(NumericVector x, int l, int r) {
  int m, inv = 0;
  if (l < r - 1) {
    // Create the mid index m to divide vector x into two halves
    m = (l + r) / 2;
    
    // Split and find inversion count in left half
    inv += mergeSort(x, l, m);
    
    // Split and find inversion count in right half
    inv += mergeSort(x, m, r);
    
    // Find inversion count by merging the two halves
    inv += merge(x, l, m, r);
  }
  return inv;
}