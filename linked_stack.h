//
// Created by guan on 2025/8/19.
//

#ifndef C__PRIME_LINKED_STACK_H
#define C__PRIME_LINKED_STACK_H

template<typename T>
class LinkedStack {
    struct Node {
        T val;
        Node *next{nullptr};
        explicit Node(T val) : val(val) {}
    };
    int size;
    Node *top;
    public:

    //构造 析构
    LinkedStack();

    ~LinkedStack();

    //
    void push(T value);
    T pop();
    T peek() const;

    //
    bool is_empty() const;
    int get_size() const ;
    void display() const;
};


#include <print>
#include <stdexcept>

template<typename T>
LinkedStack<T>::LinkedStack() {
    size=0;
    top=nullptr;
}

template<typename T>
LinkedStack<T>::~LinkedStack() {
    size=0;
    auto curr=top;
    while (top!=nullptr) {
        top=top->next;
        delete curr;
        curr=top;
    }
}

template<typename T>
void LinkedStack<T>::push(T value) {
    auto new_node=new Node(value);
    if (size==0) {
        top=new_node;
    }else {
        new_node->next=top;
        top=new_node;
    }
    size++;
}

template<typename T>
T LinkedStack<T>::pop() {
    if (size==0) {
        throw std::out_of_range("stack is empty");
    }
    auto curr=top;
    top=top->next;
    T temp=curr->val;
    delete curr;
    size--;
    if (size==0) {
        top=nullptr;
    }
    return temp;
}

template<typename T>
T LinkedStack<T>::peek() const {
    if (size==0) {
        throw std::out_of_range("stack is empty");
    }
    return top->val;
}

template<typename T>
bool LinkedStack<T>::is_empty() const{
    return size==0;
}

template<typename T>
void LinkedStack<T>::display() const {
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

template <typename T>
int LinkedStack<T>::get_size() const {
    return size;
}

#endif //C__PRIME_LINKED_STACK_H