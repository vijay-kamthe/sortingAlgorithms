sortingAlgorithms
=================

C Sorting algorithms

## Marek's suggestions
* Use `struct` instead of `typedef` (needs to make corresponding changes in mergesort and heapsort)
* Use static when better
* Make `swap` and `parent` funtions MACROS
* Reintroduce `assert` statements we removed
* Stop reinitializing seed because of side effects
* In merge sort, use 3 while loops instead of a single, big one
* make signatures of our sort functions the same as qsort and msort, with polymorphic compare fn

