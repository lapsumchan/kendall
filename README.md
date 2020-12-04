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
Given a matrix `X` with 2 columns, we implemented `kendall_tau` function that first rearranges the rows of the entire matrix based on its second column `X[,2]`. Since the second column of matrix `X` is rearranged in ascending order, it is true that `X[i,2] < X[j,2]` if `i < j` because of the no ties assumption.
