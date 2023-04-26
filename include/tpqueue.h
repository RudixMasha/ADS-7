// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>

template<typename T>
class TPQueue {
 private:
    struct QItem {
        T x;
        QItem* next;
    };
    QItem* head;

 public:
  TPQueue() : head(nullptr) {}
  bool isEmpty() const {
    return head == nullptr;
  }
  void push(const T& value) {
    if (isEmpty()) {
      QItem* temp = new QItem;
      temp->x = value;
      temp->next = nullptr;
            head = temp;
        } else if (head->x.prior < value.prior) {
         QItem* temp = new QItem;
         temp->x = value;
         temp->next = head;
         head = temp;
        } else {
         QItem* cur = head;
         while (cur->next != nullptr && value.prior <= cur->next->x.prior)
           cur = cur->next;
         QItem* temp = new QItem;
         temp->x = value;
         temp->next = cur->next;
         cur->next = temp;
        }
    }
    T pop() {
        if (isEmpty()) {
            throw std::string("Empty!");
        } else {
            QItem* temp = head->next;
            T value = head->x;
            delete(head);
            head = temp;
            return value;
        }
    }
    ~TPQueue() {
        while (head != nullptr)
            pop();
    }
};
struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
