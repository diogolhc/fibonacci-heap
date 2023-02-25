#include <bits/stdc++.h>
#include "FibonacciHeap/FibonacciHeapViz.hpp"

using namespace std;

int main() {
    FibonacciHeapViz<int> heap;
    heap.insert(2);
    heap.insert(3);
    heap.insert(4);
    heap.insert(1);
    heap.insert(5);
    auto six = heap.insert(6);
    auto seven = heap.insert(7);
    heap.insert(8);
    heap.insert(9);
    heap.insert(10);
    heap.insert(11);
    heap.insert(12);
    heap.insert(13);
    heap.insert(14);
    heap.insert(15);
    heap.insert(16);
    heap.insert(17);
    heap.insert(18);
    heap.insert(19);
    auto twenty = heap.insert(20);
    auto twentyOne = heap.insert(21);
    heap.insert(22);
    heap.insert(23);
    heap.extractMin();
    heap.extractMin();
    heap.extractMin();
    heap.decreaseKey(six, 1);
    heap.decreaseKey(seven, 0);
    heap.extractMin();
    heap.deleteElement(twenty);
    heap.deleteElement(twentyOne);
    heap.exportDOT();
    return 0;
}
