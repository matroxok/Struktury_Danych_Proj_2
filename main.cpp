#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "PriorityQueueInHeap.h"
#include "PriorityQueueInArray.h"

int main() {
    std::vector<int> sizes = {1000, 5000, 10000, 50000, 100000};
    int minPriority = 1;
    int p, elem, p1, p2;
    int priorityQueueType;
    std::string priorityQueueTypeStr;

    std::cout << "Wybierz implementacje: " << std::endl <<
                 "1 -> Kopiec" << std::endl <<
                 "2 -> Tablica Dynamiczna" << std::endl;
    std::cin >> priorityQueueType;

    switch (priorityQueueType) {
        case 1:
            priorityQueueTypeStr = "kopiec";
            break;
        case 2:
            priorityQueueTypeStr = "tablica";
            break;
        default:
            std::cout << "error: niepoprawny wybór";
            return 1;
    }

    int methodType;
    std::string methodTypeStr;

    std::cout << "Co chcesz zrobić? " << std::endl <<
                 "1. Dodawanie elementu o priorytecie - p" << std::endl <<
                 "2. Usuwanie elementu o najwyzszym priorytecie - p" << std::endl <<
                 "3. Zwracanie rozmiaru kolejki" << std::endl <<
                 "4. Podglad kolejnego elementu" << std::endl <<
                 "5. Zmiana priorytetu" << std::endl;
    std::cin >> methodType;

    switch (methodType) {
        case 1:
            methodTypeStr = "insert";
            std::cout << "Podaj element do dodania: ";
            std::cin >> elem;
            std::cout << "Podaj jego priorytet: ";
            std::cin >> p;
            break;
        case 2:
            methodTypeStr = "removeMax";
            break;
        case 3:
            methodTypeStr = "size";
            break;
        case 4:
            methodTypeStr = "peek";
            break;
        case 5:
            methodTypeStr = "modifyPriority";
            std::cout << "Podaj priorytet, ktory chcesz zmienic: ";
            std::cin >> p1;
            std::cout << "Podaj nowy priorytet: ";
            std::cin >> p2;
            break;
        default:
            std::cout << "error: niepoprawny wybor funkcji." << std::endl;
            return 1; 
    }

    std::string fileName = priorityQueueTypeStr + " " + methodTypeStr + ".txt";
    std::ofstream outFile(fileName);

    for (int size : sizes) {
        int maxPriority = size;
        long long totalTime = 0;
        int repetitions = 100;

        for (int rep = 0; rep < repetitions; ++rep) {
            if (priorityQueueType == 1) {
                auto priorityQueue = PriorityQueueInHeap<int, int>::randomGenerate(size, minPriority, maxPriority);
                auto start = std::chrono::high_resolution_clock::now();

                switch (methodType) {
                    case 1:
                        priorityQueue.insert(elem, p);
                        break;
                    case 2:
                        priorityQueue.removeMax();
                        break;
                    case 3:
                        priorityQueue.size();
                        break;
                    case 4:
                        priorityQueue.peek();
                        break;
                    case 5:
                        priorityQueue.modifyPriority(p1, p2);
                        break;
                }

                auto stop = std::chrono::high_resolution_clock::now();
                totalTime += std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
            }
            else if (priorityQueueType == 2) {
                auto priorityQueue = PriorityQueueInArray<int, int>::randomGenerate(size, minPriority, maxPriority);
                auto start = std::chrono::high_resolution_clock::now();

                switch (methodType) {
                    case 1:
                        priorityQueue.insert(elem, p);
                        break;
                    case 2:
                        priorityQueue.removeMax();
                        break;
                    case 3:
                        priorityQueue.size();
                        break;
                    case 4:
                        priorityQueue.peek();
                        break;
                    case 5:
                        priorityQueue.modifyPriority(elem, p2);
                        break;
                }

                auto stop = std::chrono::high_resolution_clock::now();
                totalTime += std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
            }
        }

        long long averageTime = totalTime / repetitions;
        outFile << size << " " << averageTime << std::endl;
    }
    outFile.close();

    return 0;
}
