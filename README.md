# kendall

<!-- badges: start -->
[![Travis build status](https://travis-ci.com/lapsumchan/kendall.svg?branch=master)](https://travis-ci.com/lapsumchan/kendall)
[![Codecov test coverage](https://codecov.io/gh/lapsumchan/kendall/branch/master/graph/badge.svg)](https://codecov.io/gh/lapsumchan/kendall?branch=master)
<!-- badges: end -->

## Overview

kendall is an efficient R package that calculates the [Kendall Tau](https://en.wikipedia.org/wiki/Kendall_rank_correlation_coefficient) between two continuous variables, assuming that each of the variables does not have ties.

## Installation
``` r
# kendall can be installed using:
if(!require(devtools)) {
  install.packages("devtools")
  library(devtools)
}
devtools::install("lapsumchan/kendall", build_vignettes = TRUE)
```

## Details
Given a matrix `X` with 2 columns, we implemented `kendall_tau` function that first rearranges the rows of the entire matrix based on its second column `X[,2]`. Since the second column of matrix `X` is now rearranged in ascending order, it is true that `X[i,2] < X[j,2]` if `i < j` because of the no ties assumption. In the context of sorting, two elements `a[i]` and `a[j]` form an [inversion](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)) if `a[i] > a[j]` and `i < j`. Applying this concept, the number of inversions we end up finding in `X[,1]` is indeed the same as [discordance](https://en.wikipedia.org/wiki/Kendall_rank_correlation_coefficient#Definition) used in calculating Kendall Tau. Thus, instead of using traditional `O(n^2)` time algorithms that tries to count the concordance and discordance, we find discordance based on merge sort by divide-and-conquer, which has time complexity `O(n*log n)`.
Notice that, merge sort was written in Rcpp for an enhanced efficiency. It can be shown that our `kendall_tau` function is more efficient than the base R `cor` function. Examples illustrating the efficiency be found at our Vignettes using `browseVignettes("kendall")` after installing our `kendall` package with the above code.
