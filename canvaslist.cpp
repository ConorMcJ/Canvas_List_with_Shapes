//
// 3/4/2024
// CS 251 (40573) - Spring 2024
// Project 3
//
// Conor McJannett
//

#include "canvaslist.h"

#include <iostream>

using namespace std;

CanvasList::CanvasList() : list_size(0), list_front(nullptr) {}

// Copy Constructor, creates COPIES of Shapes and ShapeNodes
CanvasList::CanvasList(const CanvasList& other) : list_front(nullptr), list_size(0) {
    *this = other;
}

CanvasList& CanvasList::operator=(const CanvasList& other) {
    if (this == &other) { return *this; }
    clear();
    ShapeNode* currNode = other.list_front;
    while (currNode != nullptr && currNode->value != nullptr) {
        push_back(currNode->value->copy());
        currNode = currNode->next;
    }
    return *this;
}

CanvasList::~CanvasList() {
    clear();
}

void CanvasList::clear() {
    ShapeNode* currNode = list_front;
    ShapeNode* temp;
    while (currNode != nullptr) {
        temp = currNode->next;
        delete currNode->value;
        delete currNode;
        currNode = temp;
    }
    list_front = nullptr;
    list_size = 0;
}

// Ownership TAKEN
void CanvasList::insert_after(int index, Shape* s) {
    if (index < 0 || index >= list_size || empty() || s == nullptr) { return; }
    if (index == list_size - 1) {
        push_back(s);
        return;
    }
    ShapeNode* temp = new ShapeNode;
    temp->value = s;
    ShapeNode* currNode = list_front;
    for (int i = 0; i < index; i++) {
        if (currNode == nullptr) { return; }
        currNode = currNode->next;
    }
    temp->next = currNode->next;
    currNode->next = temp;
    list_size++;
}

// Ownership TAKEN
void CanvasList::push_front(Shape* s) {
    if (s == nullptr) { return; }
    list_size++;
    if (empty()) {
        list_front = new ShapeNode;
        list_front->value = s;
        list_front->next = nullptr;
        return;
    }
    ShapeNode* temp = list_front;
    list_front = new ShapeNode;
    list_front->value = s;
    list_front->next = temp;
}

// Ownership TAKEN
void CanvasList::push_back(Shape* s) {
    if (s == nullptr ) { return; }
    if (empty()) {
        push_front(s);
        return;
    }
    ShapeNode* currNode = list_front;
    while (currNode->next != nullptr) {
        currNode = currNode->next;
    }
    ShapeNode* temp = new ShapeNode;
    temp->value = s;
    temp->next = nullptr;
    currNode->next = temp;
    list_size++;
}

void CanvasList::remove_at(int index) {
    if (index < 0 || index >= list_size || empty()) { return; }
    if (index == 0) {
        Shape* s = pop_front();
        delete s;
        return;
    }
    if (index == list_size - 1) {
        Shape* s = pop_back();
        delete s;
        return;
    }
    ShapeNode* prevNode = list_front;
    ShapeNode* currNode = list_front->next;
    for (int i = 1; i < index; i++) {
        if (currNode->next == nullptr) { return; }
        currNode = currNode->next;
        prevNode = prevNode->next;
    }
    prevNode->next = currNode->next;
    delete currNode->value;
    delete currNode;
    list_size--;
}

void CanvasList::remove_every_other() {
    if (empty() || list_front->next == nullptr) { return; }
    for (int i = 1; i < size(); i++) {
        remove_at(i);
    } 
    // ShapeNode* prevNode = list_front;
    // ShapeNode* currNode = list_front->next;
    // while (currNode != nullptr && currNode->value != nullptr) {
    //     prevNode->next = currNode->next;
    //     delete currNode->value;
    //     delete currNode;
    //     list_size--;
    //     if (prevNode->next == nullptr) { break; }
    //     prevNode = prevNode->next;
    //     currNode = prevNode->next;
    // }
}

// Ownership TRANSFERRED (Given Up)
Shape* CanvasList::pop_front() {
    if (empty()) { return nullptr; }
    Shape* s = list_front->value;
    ShapeNode* temp = list_front->next;
    delete list_front;
    list_front = temp;
    list_size--;
    return s;
}

// Ownership TRANSFERRED (Given Up)
Shape* CanvasList::pop_back() {
    if (empty()) { return nullptr; }
    if (list_front->next == nullptr) {
        return pop_front();
    }
    ShapeNode* prevNode = list_front;
    while (prevNode->next->next != nullptr) {
        prevNode = prevNode->next;
    }
    ShapeNode* currNode = prevNode->next;
    prevNode->next = nullptr;
    Shape* s = currNode->value;
    delete currNode;
    list_size--;
    return s;
}

// Ownership Retained (Constant)
ShapeNode* CanvasList::front() const {
    return list_front;
}

bool CanvasList::empty() const {
    return list_front == nullptr;
}

int CanvasList::size() const {
    return list_size;
}

int CanvasList::find(int x, int y) const {
    int index = 0;
    ShapeNode* currNode = list_front;
    while (currNode != nullptr) {
        if (currNode->value->getX() == x 
                && currNode->value->getY() == y) {
            return index;
        }
        currNode = currNode->next;
        index++;
    }
    return -1;
}

// Ownership Retained (Constant)
Shape* CanvasList::shape_at(int index) const {
    if (index < 0) { return nullptr; }
    ShapeNode* currNode = list_front;
    for (int i = 0; i < index; i++) {
        if (currNode == nullptr) { return nullptr; }
        currNode = currNode->next;
    }
    if (currNode == nullptr) { return nullptr; }
    return currNode->value;
}

void CanvasList::draw() const {
    ShapeNode* currNode = list_front;
    while (currNode != nullptr) {
        cout << currNode->value->as_string() << endl;
        currNode = currNode->next;
    }
}

void CanvasList::print_addresses() const {
    ShapeNode* currNode = list_front;
    while (currNode != nullptr) {
        cout << "Node Address: " << currNode
             << " Shape Address: " << currNode->value
             << endl;
        currNode = currNode->next;
    }
}
