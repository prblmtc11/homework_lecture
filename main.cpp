#include <iostream>

template<class T>
struct BiList {
    T val;
    BiList<T>* next;
    BiList<T>* prev;
};

template<class T>
BiList<T>* createNode(const T& value) {
    BiList<T>* node = new BiList<T>;
    node->val  = value;
    node->next = nullptr;
    node->prev = nullptr;
    return node;
}

template<class T>
void pushBack(BiList<T>*& head, BiList<T>*& tail, const T& value) {
    BiList<T>* node = createNode(value);
    if (tail == nullptr) {
        head = tail = node;
    } else {
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
}

template<class T>
void freeList(BiList<T>*& head, BiList<T>*& tail) {
    BiList<T>* cur = head;
    while (cur != nullptr) {
        BiList<T>* next = cur->next;
        delete cur;
        cur = next;
    }
    head = tail = nullptr;
}

template<class T>
void printForward(BiList<T>* head) {
    for (BiList<T>* cur = head; cur != nullptr; cur = cur->next) {
        std::cout << cur->val;
        if (cur->next) std::cout << " <-> ";
    }
    std::cout << "\n";
}

template<class T>
void printBackward(BiList<T>* tail) {
    for (BiList<T>* cur = tail; cur != nullptr; cur = cur->prev) {
        std::cout << cur->val;
        if (cur->prev) std::cout << " <-> ";
    }
    std::cout << "\n";
}
