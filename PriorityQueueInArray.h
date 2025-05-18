#ifndef PRIORITY_QUEUE_IN_ARRAY_H
#define PRIORITY_QUEUE_IN_ARRAY_H

#include <vector>
#include <stdexcept>

template<typename E, typename C>
class PriorityQueueInArray {
private:
    std::vector<std::pair<E, C>> array;

public:
    static PriorityQueueInArray<E, C> randomGenerate(int size, C minPriority, C maxPriority);
    void insert(E elem, C p);
    E removeMax();
    E peek() const;
    int size() const;
    void modifyPriority(E elem, C newPriority);
};

#endif // PRIORITY_QUEUE_IN_ARRAY_H
