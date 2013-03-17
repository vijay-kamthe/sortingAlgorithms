sortingAlgorithms
=================

## Build
` $ make`

## Usage
` $ ./run -t`
to run test suite,
` $ ./run -b`
to run benchmarks or
` $ ./run -t -b`
to run both.

## What to expect:

<pre>

$ ./run -b -t

Testing quicksort algorithm, integers array #1... test passed 
Testing quicksort algorithm, integers array #2... test passed 
Testing quicksort algorithm, integers array #3... test passed 
Testing quicksort algorithm, integers array #4... test passed 
Testing quicksort algorithm, integers array #5... test passed 
Testing quicksort algorithm, double array #1... test passed 
Testing quicksort algorithm, char array #1... test passed 
Testing stdlib qsort algorithm, integers array #1... test passed 
Testing stdlib qsort algorithm, integers array #2... test passed 
Testing stdlib qsort algorithm, integers array #3... test passed 
Testing stdlib qsort algorithm, integers array #4... test passed 
Testing stdlib qsort algorithm, integers array #5... test passed 
Testing stdlib qsort algorithm, double array #1... test passed 
Testing stdlib qsort algorithm, char array #1... test passed 
Testing mergesort algorithm, integers array #1... test passed 
Testing mergesort algorithm, integers array #2... test passed 
Testing mergesort algorithm, integers array #3... test passed 
Testing mergesort algorithm, integers array #4... test passed 
Testing mergesort algorithm, integers array #5... test passed 
Testing mergesort algorithm, double array #1... test passed 
Testing mergesort algorithm, char array #1... test passed 
Testing heapsort algorithm, integers array #1... test passed 
Testing heapsort algorithm, integers array #2... test passed 
Testing heapsort algorithm, integers array #3... test passed 
Testing heapsort algorithm, integers array #4... test passed 
Testing heapsort algorithm, integers array #5... test passed 
Testing heapsort algorithm, double array #1... test passed 
Testing heapsort algorithm, char array #1... test passed 

Benchmarking quicksort algorithm on shuffled array of 200000 chars (10 trials), best time: 960 milliseconds
Benchmarking stdlib qsort algorithm on shuffled array of 200000 chars (10 trials), best time: 210 milliseconds
Benchmarking mergesort algorithm on shuffled array of 200000 chars (10 trials), best time: 160 milliseconds
Benchmarking heapsort algorithm on shuffled array of 200000 chars (10 trials), best time: 180 milliseconds

Benchmarking quicksort algorithm on sorted array of 200000 chars (10 trials), best time: 950 milliseconds
Benchmarking stdlib qsort algorithm on sorted array of 200000 chars (10 trials), best time: 90 milliseconds
Benchmarking mergesort algorithm on sorted array of 200000 chars (10 trials), best time: 110 milliseconds
Benchmarking heapsort algorithm on sorted array of 200000 chars (10 trials), best time: 160 milliseconds

</pre>

