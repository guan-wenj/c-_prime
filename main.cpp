#include "linked_queue.h"
#include <print>
#include "linked_stack.h"


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
    std::println("------------------------------------------------" );
    auto stack = LinkedStack();
    stack.display();
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.display();
    std::println("{}", stack.pop());  // 3
    std::println("{}", stack.peek()); // 2
    std::println("{}", stack.pop());  // 2
    std::println("{}", stack.peek()); // 1
    stack.display();
    std::println("{}", stack.get_size());  // 1
    return 0;
}

