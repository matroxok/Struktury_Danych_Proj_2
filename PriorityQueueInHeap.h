#ifndef PRIORITY_QUEUE_IN_HEAP_H
#define PRIORITY_QUEUE_IN_HEAP_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
#include <ctime>
#include <functional>

template<typename E, typename C>
class PriorityQueueInHeap {
private:
    std::vector<std::pair<E, C>> heap;

    void heapifyDown(size_t idx);
    void heapifyUp(size_t idx);

public:
    static PriorityQueueInHeap<E, C> randomGenerate(int size, C minPriority, C maxPriority);

    void insert(E elem, C p);
    bool isEmpty() const;
    E peek() const;
    void removeMax();
    int size() const;
    void modifyPriority(C oldPriority, C newPriority);
};

#endif // PRIORITY_QUEUE_IN_HEAP_H
