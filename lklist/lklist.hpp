#include <iostream>
#include <stdlib.h>

#define LOG(x) std::cout << x << std::endl;

class LkList {
public:
    LkList() : val(0), next(nullptr) {
        initialize();
    }

    void print_list() {
        LkList *current = head->next;
        while (current != nullptr) {
            LOG(current->val);
            current = current->next;
        }
    }

    void append(int val) {
        LkList *temp = (LkList *)malloc(sizeof(LkList));
        temp->val  = val;
        tail->next = temp;
        tail       = tail->next;
    }

    void insert(int val, int index) {
        LkList *temp = (LkList *)malloc(sizeof(LkList));
        temp->val = val;
        LkList *current = head->next;
        int i = 0;
        if (index == 0) {
            temp->next = current;
            head->next = temp;
        }
        else if (index > this->size()) {
            std::cout << "index[" << index << "]: Out of bounds nigga!" << std::endl;
        }
        else {
            while (i < index - 1 && current != nullptr) {
                current = current->next;
                i++;
            }
            temp->next = current->next;
            current->next = temp;
        }
    }

    void pop() {
        LkList *current = head->next;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        current->next = nullptr;
    }

    void pop(int index) {
        LkList *current = head->next;
        if (index == 0) {
            head->next = head->next->next;
        }
        else if (index >= this->size()) {
            std::cout << "index[" << index << "]: Out of bounds nigga!" << std::endl;
        }
        else {
            int i = 0;
            while (i < index - 1 && current != nullptr) {
                current = current->next;
                i++;
            }
            current->next = current->next->next;
        }
    }

    int size() {
        LkList *current = head->next;
        int i = 0;
        while (current != nullptr) {
            current = current->next;
            i++;
        }
        return i;
    }
private:
    int val = 0;
    LkList *next = nullptr;
    LkList *head = (LkList *)malloc(sizeof(LkList));
    LkList *tail = head;
    void initialize() {
        while (tail->next != nullptr) {
            tail->val = 0;
            tail = tail->next;
        }
    }
};