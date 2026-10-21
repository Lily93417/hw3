#include <iostream>
#include "heap.h"

int main()
{
    Heap<int> minHeap;

    minHeap.push(8);
    minHeap.push(3);
    minHeap.push(10);
    minHeap.push(1);

    std::cout << "Min-heap: ";

    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " ";
        minHeap.pop();
    }

    std::cout << std::endl;

    Heap<int, std::greater<int> > maxHeap;

    maxHeap.push(8);
    maxHeap.push(3);
    maxHeap.push(10);
    maxHeap.push(1);

    std::cout << "Max-heap: ";

    while (!maxHeap.empty()) {
        std::cout << maxHeap.top() << " ";
        maxHeap.pop();
    }

    std::cout << std::endl;

    Heap<int> ternaryHeap(3);

    ternaryHeap.push(7);
    ternaryHeap.push(2);
    ternaryHeap.push(5);
    ternaryHeap.push(1);

    std::cout << "Ternary heap top: "
              << ternaryHeap.top() << std::endl;

    return 0;
}