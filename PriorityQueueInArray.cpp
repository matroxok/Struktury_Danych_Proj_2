#include <algorithm>
#include <random>
#include <iostream>
#include "PriorityQueueInArray.h"

template<typename E, typename C>
PriorityQueueInArray<E, C> PriorityQueueInArray<E, C>::randomGenerate(int size, C minPriority, C maxPriority) {
    PriorityQueueInArray<E, C> pq;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(minPriority, maxPriority);

    for (int i = 0; i < size; ++i) {
        E elem = static_cast<E>(i);
        C pri = dist(gen);
        pq.insert(elem, pri);
    }
    return pq;
}

template<typename E, typename C>
void PriorityQueueInArray<E, C>::insert(E elem, C p) {
    array.push_back(std::make_pair(elem, p));
}

template<typename E, typename C>
E PriorityQueueInArray<E, C>::removeMax() {
    if (array.empty()) {
        throw std::runtime_error("Array is empty");
    }
    auto it = std::max_element(array.begin(), array.end(), 
                               [](const std::pair<E, C>& a, const std::pair<E, C>& b) {
                                   return a.second < b.second;
                               });
    E maxElement = it->first;
    array.erase(it);
    return maxElement;
}

template<typename E, typename C>
E PriorityQueueInArray<E, C>::peek() const {
    if (array.empty()) {
        throw std::runtime_error("Array is empty");
    }
    return std::max_element(array.begin(), array.end(), 
                            [](const std::pair<E, C>& a, const std::pair<E, C>& b) {
                                return a.second < b.second;
                            })->first;
}

template<typename E, typename C>
int PriorityQueueInArray<E, C>::size() const {
    return array.size();
}

template<typename E, typename C>
void PriorityQueueInArray<E, C>::modifyPriority(E elem, C newPriority) {
    auto it = std::find_if(array.begin(), array.end(), [&](const std::pair<E, C>& item) {
        return item.first == elem;
    });

    if (it != array.end()) {
        it->second = newPriority;
    }
}

// Explicit template instantiation
template class PriorityQueueInArray<int, int>;
