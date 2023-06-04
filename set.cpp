//by Branislav Bajic
#include <iostream>
#include "set.h"

using namespace std;

int Set::ID = 0;

Set::Set() {

    head = nullptr;
    tail = nullptr;
    elem_count = 0;

}

Set::~Set() {

    Elem* temp;

    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

}

bool Set::addElement(int e) {

    Elem *curr = head, *prev = nullptr, *temp;
    bool found = false;

    while (curr != nullptr) {
        if (curr->value == e) {
            found = true;
            break;
        }
        if (curr->value > e) {
            break;
        }
        curr = curr->next;
    }

    if (found == false) {
        temp = new Elem(e);
        curr = head;

        while (curr != nullptr) {
            if (curr->value > e) {
                break;
            }
            prev = curr;
            curr = curr->next;
        }

        if (prev == nullptr) {
            temp->next = head;
            head = temp;
        }
        else {
            temp->next = curr;
            prev->next = temp;
        }
        elem_count++;
    }

    return !found;
}

bool Set::removeElement(int e) {

    Elem *curr = head, *prev = nullptr;
    bool found = false;

    while (curr != nullptr) {
        if (curr->value == e) {
            prev->next = curr->next;
            found = true;
            break;
        }

        if (curr->value > e) {
            break;
        }

        prev = curr;
        curr = curr->next;
    }

    if (found == true) {
        prev->next = curr->next;
        delete curr;
        elem_count--;
    }

    return found;

}

Set* Set::_union(Set* set1, Set* set2) {

    Set* temp = new Set();
    Elem *p = set1->head, *q = set2->head;

    while (true) {

        if (p != nullptr && q != nullptr) {
            if (p->value == q->value) {
                temp->addElement(p->value);
                p = p->next;
                q = q->next;
            }
            if (p->value < q->value) {
                temp->addElement(p->value);
                p = p->next;
            }
            else {
                temp->addElement(q->value);
                q = q->next;
            }
        }
        else if (p != nullptr && q == nullptr) {
            temp->addElement(p->value);
            p = p->next;
        }
        else if (p == nullptr && q != nullptr) {
            temp->addElement(q->value);
            q = q->next;
        }
        else {
            break;
        }

    }

    return temp;
}

Set* Set::_intersection(Set* set1, Set* set2) {

    Set* temp = new Set();
    Elem *p = set1->head, *q = set2->head;

    while (p != nullptr && q != nullptr) {

        if (p->value == q->value) {
            temp->addElement(p->value);
            p = p->next;
            q = q->next;
        }
        else if (p->value < q->value) {
            p = p->next;
        }
        else if (p->value > q->value) {
            q = q->next;
        }

    }

    return temp;
}

Set* Set::_difference(Set* set1, Set* set2) {

    Set* temp = new Set();
    Elem *p = set1->head, *q = set2->head;

    while (true) {

        if (p != nullptr && q != nullptr) {
            if (p->value == q->value) {
                p = p->next;
                q = q->next;
            }
            if (p->value < q->value) {
                temp->addElement(p->value);
                p = p->next;
            }
            else {
                q = q->next;
            }
        }
        else if (p != nullptr && q == nullptr) {
            temp->addElement(p->value);
            p = p->next;
        }
        else if (p == nullptr && q != nullptr) {
            q = q->next;
        }
        else {
            break;
        }

    }

    return temp;
}

int Set::getID() const {
    return id;
}

int Set::getNumberOfElements() const {

    return elem_count;

}

void Set::printElements() const {

    Elem* temp;

    if (head == nullptr) {
        cout << "Lista je prazna!" << endl;
    }
    else {
        temp = head;

        cout << "Elementi: ";
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

}


