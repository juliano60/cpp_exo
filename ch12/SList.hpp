#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include <string>
#include <iostream>

// implementation of a singly linked list

struct Node {
    std::string elem;
    Node* next;
};

class SLinkedList {
public:
    friend std::ostream& operator<<(std::ostream& out, const SLinkedList&);

    SLinkedList();
    ~SLinkedList();

    bool empty() const;
    const std::string& front() const;

    void addFront(const std::string& value);
    void removeFront();

private:
    Node* head_;
};

#endif
