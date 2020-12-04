test_that("Merge Sort works", {
  expect_equal(mergeSort(1:10, 0, 10), 0)
  expect_equal(mergeSort(10:1, 0, 10), 45)
  expect_equal(mergeSort(c(4,1,5,3,2), 0, 5), 6)
  expect_equal(mergeSort(c(2,6,3,7,4,5,1), 0, 7), 11)
})
