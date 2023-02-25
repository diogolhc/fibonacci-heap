# Fibonacci Heap

Fibonacci Heaps were introduced in [Fibonacci heaps and their uses in improved network optimization algorithms](https://dl.acm.org/doi/10.1145/28869.28874) by Fredman and Tarjan in 1987.

This implementation in C++ was guided by the [Introduction to Algorithms](https://mitpress.mit.edu/books/introduction-algorithms-third-edition) book by Cormen, Leiserson, Rivest and Stein.


## Usage

The Fibonacci Heap is implemented in the [FibonacciHeap.hpp](./src/FibonacciHeap/FibonacciHeap.hpp) header file. It is templated on the type of the elements it stores. The Fibonacci Heap is a min-heap, i.e. the element with the smallest key is always at the top. This implementation supports the following operations:

* `insert(key)`: Inserts a new element with the given key into the heap.
* `unite(other_heap)`: Unites the heap with the given heap. The other heap is empty afterwards.
* `getMin()`: Returns the smallest key in the heap.
* `extractMin()`: Returns the smallest key in the heap and removes it from the heap.
* `decreaseKey(element, new_key)`: Decreases the key of the given element to the new key. The new key must be smaller than the old key.
* `deleteElement(element)`: Deletes the given element from the heap.
* `isEmpty()`: Returns whether the heap is empty.

## Visualization

The Fibonacci Heap can be visualized using the inherited class implemented in [FibonacciHeapViz.hpp](./src/FibonacciHeap/FibonacciHeapViz.hpp). The visualization is done using the [GraphViz](https://www.graphviz.org/) library in the `dot` format. The `FibonacciHeapViz` class has a method that dumps the current state of the heap to the given `std::ostream`, which can be a file or the standard output:

* `exportDot(ostream)`: Exports the current state of the heap to the given `std::ostream`.


## Example

Refer to the [main.cpp](./src/main.cpp) file for an example on how to use the Fibonacci Heap with the following final result visualized using GraphViz:

![Example Visualization](example/fibheap.png)


## References

Michael L. Fredman and Robert Endre Tarjan. 1987. Fibonacci heaps and their uses in improved network optimization algorithms. J. ACM 34, 3 (July 1987), 596–615. https://doi.org/10.1145/28869.28874

Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein. 2009. Introduction to Algorithms, Third Edition (3rd. ed.). The MIT Press.
