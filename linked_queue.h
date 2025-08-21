//
// Created by guan on 2025/8/21.
//

#ifndef C__PRIME_LINKED_QUEUE_H
#define C__PRIME_LINKED_QUEUE_H




template <typename T>
class LinkedQueue {
    //结点 结构
    // val next  val 先用int  后续用模板 泛型
    struct Node {
        T val;
        Node* next{nullptr};
        explicit Node(T value):val(value){}
    };
    Node *front;
    Node *rear;
    int size;
    //构造和析构
    public:
    LinkedQueue();
    ~LinkedQueue();

    LinkedQueue(const LinkedQueue&) = delete;
    LinkedQueue& operator=(const LinkedQueue&) = delete;

    //push pop peek
    void push(T value);
    T pop();
    T peek() const;
    //get size   display
    bool is_empty() const;
    int get_size() const;
    void display() const;
};


#include <print>
#include <stdexcept>
template <typename T>
LinkedQueue<T>::LinkedQueue() {
    size=0;
    front=rear=nullptr;
}


template <typename T>
LinkedQueue<T>::~LinkedQueue() {
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

template <typename T>
void LinkedQueue<T>::push(T value) {
    auto new_node=new Node(value);
    if (this->is_empty()) {
        front=rear=new_node;
    }else {
        rear->next=new_node;
        rear=new_node;
    }
    ++size;
}


template <typename T>
T LinkedQueue<T>::pop() {
    if (this->is_empty()) {
        throw std::runtime_error("Queue is Empty");
    }
    T value=front->val;
    auto curr=front;
    front=front->next;
    delete curr;
    --size;
    if (this->is_empty()) {
        front=rear=nullptr;
    }
    return value;
}

template <typename T>
T LinkedQueue<T>::peek() const{
    if (this->is_empty()) {
        throw std::runtime_error("Queue is Empty");
    }
    return front->val;
}


template <typename T>

bool LinkedQueue<T>::is_empty() const {
    return size==0;
}


template <typename T>

int LinkedQueue<T>::get_size() const{
    return size;
}


template <typename T>
void LinkedQueue<T>::display() const{
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



#endif //C__PRIME_LINKED_QUEUE_H