#' Calculating Kendall Tau using merge sort
#'
#' @param X        A matrix with two columns of real numbers with no ties within the same column
#'
#' @return \code{tau}       : Kendall Tau correlation between the two columns
#' 
#' @examples 
#' # 5 x 2 matrix
#' X <- matrix(c(4,5,3,1,2,6,8,9,7,10),5,2)
#' # Find Kendall tau
#' kendall_tau(X)
#' @export
kendall_tau <- function(X) {
  n <- dim(X)[1] 
  total <- n * (n-1) / 2
  
  #Rearrange the rows according to the second column
  X <- X[order(X[,2]),]
  
  #Find inversion count of the reordered first column by mergeSort()
  inv <- mergeSort(X[,1], 0, n)
  
  #Inversion count is the same as discordance
  tau <- 1 - (2 * inv) / total
  return(tau)
}
