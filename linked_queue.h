//
// Created by guan on 2025/8/19.
//

#ifndef C__PRIME_LINKED_QUEUE_H
#define C__PRIME_LINKED_QUEUE_H


//结点 结构
// val next  val 先用int  后续用模板 泛型
struct Node {
    int val;
    Node* next{nullptr};
    explicit Node(int value):val(value){}
};


class LinkedQueue {
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
    void push(int value);
    int pop();
    int peek() const;
    //get size   display
    bool is_empty() const;
    int get_size() const;
    void display() const;
};





#endif //C__PRIME_LINKED_QUEUE_H