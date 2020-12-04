test_that("Kendall tau works", {
  expect_equal(kendall_tau(matrix(rep(1:5,2),5,2)), 1)
  expect_equal(kendall_tau(matrix(c(1:5,5:1),5,2)), -1)
  expect_equal(kendall_tau(matrix(c(4,5,3,1,2,6,8,9,7,10),5,2)), -0.2)
})
