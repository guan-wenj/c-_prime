//
// Created by guan on 2025/8/19.
//
#include <print>
#include "linked_queue.h"

#include <stdexcept>

LinkedQueue::LinkedQueue() {
    size=0;
    front=rear=nullptr;
}

LinkedQueue::~LinkedQueue() {
    size=0;
    auto curr=front;
    while (front!=rear) {
        front=front->next;
        delete curr;
        curr=front;
    }
    delete front;
    front = rear = nullptr;
}

void LinkedQueue::push(int value) {
    auto new_node=new Node(value);
    if (this->is_empty()) {
        front=rear=new_node;
    }else {
        rear->next=new_node;
        rear=new_node;
    }
    ++size;
}

int LinkedQueue::pop() {
    if (this->is_empty()) {
        throw std::runtime_error("Queue is Empty");
    }
    int value=front->val;
    auto curr=front;
    front=front->next;
    delete curr;
    --size;
    if (this->is_empty()) {
        front=rear=nullptr;
    }
    return value;
}

int LinkedQueue::peek() const{
    if (this->is_empty()) {
        throw std::runtime_error("Queue is Empty");
    }
    return front->val;
}

bool LinkedQueue::is_empty() const {
    return size==0;
}

int LinkedQueue::get_size() const{
    return size;
}

void LinkedQueue::display() const{
    if (this->is_empty()) {
        std::println("Queue is Empty");
        return;
    }
    auto curr=front;
    while (curr!=rear) {
        std::print("{}->", curr->val);
        curr=curr->next;
    }
    std::println("{}", curr->val);
}
