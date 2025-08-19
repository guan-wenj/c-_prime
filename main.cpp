#include "linked_queue.h"
#include <print>
int main() {
    auto queue=LinkedQueue();
    queue.display();
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.display();
    std::println("{}", queue.pop());//1
    std::println("{}", queue.peek());//2
    std::println("{}", queue.pop());//2
    std::println("{}", queue.peek());//3
    queue.display();
    std::println("{}", queue.get_size());
}