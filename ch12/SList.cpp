#include "SList.hpp"
#include <stdexcept>

SLinkedList::SLinkedList():
    head_{nullptr}
{}

bool SLinkedList::empty() const {
    return head_==nullptr;
}

const std::string& SLinkedList::front() const {
    if (empty()) {
        throw std::runtime_error{"front() - list empty"};
    }

    return head_->elem;
}

void SLinkedList::removeFront() {
    if (empty()) {
        throw std::runtime_error{"removeFront() - list empty"};
    }

    Node* p = head_;
    head_ = head_->next;

    delete p;
}

SLinkedList::~SLinkedList() {
    while (!empty()) removeFront();
}

void SLinkedList::addFront(const std::string& value) {
    Node* p = new Node{value, head_};
    head_ = p;
}

std::ostream& operator<<(std::ostream& out, const SLinkedList& sl) {
    Node* p = sl.head_;
    while (p) {
        out << p->elem << " ";
        p = p->next;
    }
    out << "NULL";

    return out;
}
