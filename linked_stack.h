//
// Created by guan on 2025/8/19.
//

#ifndef C__PRIME_LINKED_STACK_H
#define C__PRIME_LINKED_STACK_H


class LinkedStack {
    struct Node {
        int val;
        Node *next{nullptr};
        explicit Node(int val) : val(val) {}
    };
    int size;
    Node *top;
    public:

    //构造 析构
    LinkedStack();
    ~LinkedStack();

    //
    void push(int value);
    int pop();
    int peek() const;

    //
    bool is_empty() const;
    int get_size() const ;
    void display() const;
};



#endif //C__PRIME_LINKED_STACK_H