//
// Created by SP on 2022/7/12.
//

#ifndef SERIES_H
#define SERIES_H

struct node {
    void (*f)();

    node *last;
    node *next;
};

class Series {
private:
    node left = {[]() {}, nullptr, nullptr};
    node right = {[]() {}, nullptr, nullptr};
public:
    Series();

    void add(void (*f)());

    void run();
};

Series::Series() {
    this->left.next = &this->right;
    this->right.last = &this->left;
}

void Series::add(void (*f)()) {
    node *cur = new node();
    cur->f = f;
    this->right.last->next = cur;
    cur->last = this->right.last;
    cur->next = &this->right;
    this->right.last = cur;
}

void Series::run() {
    node *cur = this->left.next;
    while (cur != &this->right) {
        cur->f();
        cur = cur->next;
    }
}


#endif //SERIES_H
