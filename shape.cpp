//
// 3/4/2024
// CS 251 (40573) - Spring 2024
// Project 3
//
// Conor McJannett
//

#include "shape.h"

#include <string>

using namespace std;

// Shape member function definitions
Shape::Shape() : x(0), y(0) {}

Shape::Shape(int x, int y) {
    // TODO_STUDENT
    setX(x);
    setY(y);
}

Shape::~Shape() {
    // TODO_STUDENT
}

Shape* Shape::copy() {
    // TODO_STUDENT
    return new Shape(x, y);
}

int Shape::getX() const {
    // TODO_STUDENT
    return x;
}

int Shape::getY() const {
    // TODO_STUDENT
    return y;
}

void Shape::setX(int x) {
    // TODO_STUDENT
    this->x = x;
}

void Shape::setY(int y) {
    // TODO_STUDENT
    this->y = y;
}

string Shape::as_string() const {
    // TODO_STUDENT
    string shapeString;
    shapeString += "It's a Shape at x: ";
    shapeString += to_string(x);
    shapeString += ", y: ";
    shapeString += to_string(y);
    return shapeString;
}

// Circle member function definitions
Circle::Circle() : Shape(), radius(0) {}

Circle::Circle(int r) : Shape() {
    setRadius(r);
}

Circle::Circle(int x, int y, int r) : Shape(x, y) {
    setRadius(r);
}

Circle::~Circle() {}

Circle* Circle::copy() {
    return new Circle(x, y, radius);
}

int Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(int r) {
    radius = r;
}

string Circle::as_string() const {
    string circleString;
    circleString += "It's a Circle at x: ";
    circleString += to_string(x);
    circleString += ", y: ";
    circleString += to_string(y);
    circleString += ", radius: ";
    circleString += to_string(radius);
    return circleString;
}

// Rect member function definitions
Rect::Rect() : Shape(), width(0), height(0) {}

Rect::Rect(int w, int h) : Shape() {
    setWidth(w);
    setHeight(h);
}

Rect::Rect(int x, int y, int w, int h) : Shape(x, y) {
    setWidth(w);
    setHeight(h);
}

Rect::~Rect() {}

Rect* Rect::copy() {
    return new Rect(x, y, width, height);
}

int Rect::getWidth() const {
    return width;
}

int Rect::getHeight() const {
    return height;
}

void Rect::setWidth(int w) {
    width = w;
}

void Rect::setHeight(int h) {
    height = h;
}

string Rect::as_string() const {
    string rectString;
    rectString += "It's a Rectangle at x: ";
    rectString += to_string(x);
    rectString += ", y: ";
    rectString += to_string(y);
    rectString += " with width: ";
    rectString += to_string(width);
    rectString += " and height: ";
    rectString += to_string(height);
    return rectString;
}

// RightTriangle member function definitions
RightTriangle::RightTriangle() : Shape(), base(0), height(0) {}

RightTriangle::RightTriangle(int b, int h) : Shape() {
    setBase(b);
    setHeight(h);
}

RightTriangle::RightTriangle(int x, int y, int b, int h) : Shape(x, y) {
    setBase(b);
    setHeight(h);
}

RightTriangle::~RightTriangle() {}

RightTriangle* RightTriangle::copy() {
    return new RightTriangle(x, y, base, height);
}

int RightTriangle::getBase() const {
    return base;
}

int RightTriangle::getHeight() const {
    return height;
}

void RightTriangle::setBase(int b) {
    base = b;
}

void RightTriangle::setHeight(int h) {
    height = h;
}

string RightTriangle::as_string() const {
    string RTString;
    RTString += "It's a Right Triangle at x: ";
    RTString += to_string(x);
    RTString += ", y: ";
    RTString += to_string(y);
    RTString += " with base: ";
    RTString += to_string(base);
    RTString += " and height: ";
    RTString += to_string(height);
    return RTString;
}

