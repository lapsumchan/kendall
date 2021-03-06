% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{merge}
\alias{merge}
\title{Finding inversion count by merging the left and right subset}
\usage{
merge(x, l, m, r)
}
\arguments{
\item{x}{A vector containing real numbers with no ties}

\item{l}{Index of the beginning (inclusive) of left subset}

\item{m}{Index of the end (exclusive) of left subset and start (inclusive) of right subset}

\item{r}{Index of the end (exclusive) of right subset}
}
\value{
\code{inv} Inversion count
}
\description{
Finding inversion count by merging the left and right subset
}
