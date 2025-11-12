#include "queue.hpp"

int main() {
    Queue cafeteria;

    cafeteria.enqueue("Alice");
    cafeteria.enqueue("Bob");
    cafeteria.enqueue("Charlie");
    cafeteria.printQueue();

    cafeteria.dequeue();
    cafeteria.printQueue();

    cafeteria.enqueue("David");
    cafeteria.enqueue("Emma");
    cafeteria.enqueue("Frank");
    cafeteria.enqueue("Grace");
    cafeteria.enqueue("Helen");
    cafeteria.enqueue("Ian");
    cafeteria.enqueue("Jack");
    cafeteria.enqueue("Kate"); // triggers compaction
    cafeteria.printQueue();

    return 0;
}
