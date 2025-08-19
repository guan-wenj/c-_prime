//
// Created by guan on 2025/8/19.
//

#include "linked_stack.h"
#include <print>
#include <stdexcept>

LinkedStack::LinkedStack() {
    size=0;
    top=nullptr;
}

LinkedStack::~LinkedStack() {
    size=0;
    auto curr=top;
    while (top!=nullptr) {
        top=top->next;
        delete curr;
        curr=top;
    }
}

void LinkedStack::push(int value) {
    auto new_node=new Node(value);
    if (size==0) {
        top=new_node;
    }else {
        new_node->next=top;
        top=new_node;
    }
    size++;
}

int LinkedStack::pop() {
    if (size==0) {
        throw std::out_of_range("stack is empty");
    }
    auto curr=top;
    top=top->next;
    int temp=curr->val;
    delete curr;
    size--;
    if (size==0) {
        top=nullptr;
    }
    return temp;
}

int LinkedStack::peek() const {
    if (size==0) {
        throw std::out_of_range("stack is empty");
    }
    return top->val;
}

bool LinkedStack::is_empty() const{
    return size==0;
}

void LinkedStack::display() const {
    if (size==0) {
        std::println("empty stack");
        return;
    }
    auto curr=top;
    while (curr->next!=nullptr) {
        std::print("{}->", curr->val);
        curr=curr->next;
    }
    std::println("{}", curr->val);
}

int LinkedStack::get_size() const{
    return size;
}
