//
// 3/5/2024
// CS 251 (40573) - Spring 2024
// Project 3
//
// Conor McJannett
//

#include <gtest/gtest.h>

#include "canvaslist.h"
#include "shape.h"

// #############################################################
//
// Shapes Tests
//
//
// TEST 1 - Shape default & parameter constructors
TEST(ShapeTest, ShapeConstructors) {
    Shape s;

    EXPECT_EQ(s.getX(), 0);
    EXPECT_EQ(s.getY(), 0);

    Shape* p = new Shape;

    EXPECT_EQ(p->getX(), 0);
    EXPECT_EQ(p->getY(), 0);

    delete p;
    p = nullptr;

    Shape sh(-5, 2);

    EXPECT_EQ(sh.getX(), -5);
    EXPECT_EQ(sh.getY(), 2);

    Shape* ph = new Shape(16, -47);

    EXPECT_EQ(ph->getX(), 16);
    EXPECT_EQ(ph->getY(), -47);

    delete ph;
    ph = nullptr;
}

// TEST 2 - Shape setX() & setY()
TEST(ShapeTest, Shape_setX_setY) {
    Shape s;
    s.setX(4);
    s.setY(-2);

    EXPECT_EQ(s.getX(), 4);
    EXPECT_EQ(s.getY(), -2);
}

// TEST 3 - Shape copy()
TEST(ShapeTest, Shape_copy) {
    Shape r(6, -7);
    Shape* s = r.copy();

    EXPECT_EQ(s->getX(), r.getX());
    EXPECT_EQ(s->getY(), r.getY());

    delete s;
    s = nullptr;
}

// TEST 4 - Shape as_string()
TEST(ShapeTest, Shape_As_String) {
    Shape s;
    int sample_x = 0;
    int sample_y = 0;
    string s_string = "It's a Shape at x: "+ to_string(sample_x) + ", y: " + to_string(sample_y);

    EXPECT_EQ(s.as_string(), s_string);
}

// TEST 5 - Circle default & parameter constructors
TEST(CircleTest, CircleConstructors) {
    Circle c;

    EXPECT_EQ(c.getX(), 0);
    EXPECT_EQ(c.getY(), 0);
    EXPECT_EQ(c.getRadius(), 0);

    Circle c2(-7);

    EXPECT_EQ(c2.getX(), 0);
    EXPECT_EQ(c2.getY(), 0);
    EXPECT_EQ(c2.getRadius(), -7);

    Circle c3(1, -9, 4);

    EXPECT_EQ(c3.getX(), 1);
    EXPECT_EQ(c3.getY(), -9);
    EXPECT_EQ(c3.getRadius(), 4);

    Circle* p = new Circle();

    EXPECT_EQ(p->getX(), 0);
    EXPECT_EQ(p->getY(), 0);
    EXPECT_EQ(p->getRadius(), 0);

    delete p;
    p = new Circle(9);

    EXPECT_EQ(p->getX(), 0);
    EXPECT_EQ(p->getY(), 0);
    EXPECT_EQ(p->getRadius(), 9);

    delete p;
    p = new Circle(18, 2, -10);

    EXPECT_EQ(p->getX(), 18);
    EXPECT_EQ(p->getY(), 2);
    EXPECT_EQ(p->getRadius(), -10);

    delete p;
    p = nullptr;
}

// TEST 6 - Circle setX(), setY(), & setRadius()
TEST(CircleTest, Circle_setters) {
    Circle* c = new Circle;
    c->setX(16);
    c->setY(-40);
    c->setRadius(21);

    EXPECT_EQ(c->getX(), 16);
    EXPECT_EQ(c->getY(), -40);
    EXPECT_EQ(c->getRadius(), 21);

    delete c;
    c = nullptr;
}

// TEST 7 - Circle copy()
TEST(CircleTest, Circle_ShapeList) {
    Circle c(5, -4, 3);
    Circle* p = c.copy();

    EXPECT_EQ(p->getX(), c.getX());
    EXPECT_EQ(p->getY(), c.getY());
    EXPECT_EQ(p->getRadius(), c.getRadius());

    delete p;
    p = nullptr;
}

// TEST 8 - Circle as_string()
TEST(CircleTest, Circle_As_String) {
    Circle c;
    int sample_x = 0;
    int sample_y = 0;
    int sample_Radius = 0;
    string circleStr = "It's a Circle at x: " + to_string(sample_x) + ", y: " + to_string(sample_y) + ", radius: " + to_string(sample_Radius);
    
    EXPECT_EQ(c.as_string(), circleStr);

    Circle c2(10, -12, -3);
    sample_x = 10;
    sample_y = -12;
    sample_Radius = -3;
    circleStr = "It's a Circle at x: " + to_string(sample_x) + ", y: " + to_string(sample_y) + ", radius: " + to_string(sample_Radius);

    EXPECT_EQ(c2.as_string(), circleStr);
}

// TEST 9 - Rect default & parameter constructors
TEST(RectTest, RectConstructors) {
    Rect r;

    EXPECT_EQ(r.getX(), 0);
    EXPECT_EQ(r.getY(), 0);
    EXPECT_EQ(r.getWidth(), 0);
    EXPECT_EQ(r.getHeight(), 0);

    Rect r2(4, -3);

    EXPECT_EQ(r2.getX(), 0);
    EXPECT_EQ(r2.getY(), 0);
    EXPECT_EQ(r2.getWidth(), 4);
    EXPECT_EQ(r2.getHeight(), -3);

    Rect r3(-3, 5, -6, 7);

    EXPECT_EQ(r3.getX(), -3);
    EXPECT_EQ(r3.getY(), 5);
    EXPECT_EQ(r3.getWidth(), -6);
    EXPECT_EQ(r3.getHeight(), 7);

    Rect* p = new Rect;

    EXPECT_EQ(p->getX(), 0);
    EXPECT_EQ(p->getY(), 0);
    EXPECT_EQ(p->getWidth(), 0);
    EXPECT_EQ(p->getHeight(), 0);

    delete p;
    p = new Rect(4, -3);

    EXPECT_EQ(p->getX(), 0);
    EXPECT_EQ(p->getY(), 0);
    EXPECT_EQ(p->getWidth(), 4);
    EXPECT_EQ(p->getHeight(), -3);

    delete p;
    p = new Rect(-3, 5, -6, 7);

    EXPECT_EQ(p->getX(), -3);
    EXPECT_EQ(p->getY(), 5);
    EXPECT_EQ(p->getWidth(), -6);
    EXPECT_EQ(p->getHeight(), 7);

    delete p;
    p = nullptr;
}

// TEST 10 - Rect setX(), setY(), setWidth(), & setHeight()
TEST(RectTest, Rect_setters) {
    Rect* r = new Rect;
    r->setX(16);
    r->setY(-40);
    r->setWidth(21);
    r->setHeight(-19);

    EXPECT_EQ(r->getX(), 16);
    EXPECT_EQ(r->getY(), -40);
    EXPECT_EQ(r->getWidth(), 21);
    EXPECT_EQ(r->getHeight(), -19);

    delete r;
    r = nullptr;
}

// TEST 11 [PART 1] - Rect copy()
TEST(RectTest, Rect_copy) {
    Rect r(1, -14, -7, 16);
    Rect* p = r.copy();

    EXPECT_EQ(p->getX(), r.getX());
    EXPECT_EQ(p->getY(), r.getY());
    EXPECT_EQ(p->getWidth(), r.getWidth());
    EXPECT_EQ(p->getHeight(), r.getHeight());

    delete p;
    p = nullptr;
}

// TEST 11 [PART 2] - Rect as_string()
TEST(RectTest, Rect_AsString) {
    Rect joe(3, 6, 9, -12);
    int x = 3;
    int y = 6;
    int Width = 9;
    int Height = -12;
    string rectStr = "It's a Rectangle at x: " + to_string(x) + ", y: " + to_string(y) + " with width: " + to_string(Width) + " and height: " + to_string(Height);

    EXPECT_EQ(joe.as_string(), rectStr);
}

// TEST 12 - Right Triangle default & parameter constructors
TEST(RightTriangleTest, RightTriangle_constructors) {
    RightTriangle* p = new RightTriangle;

    EXPECT_EQ(p->getX(), 0);
    EXPECT_EQ(p->getY(), 0);
    EXPECT_EQ(p->getBase(), 0);
    EXPECT_EQ(p->getHeight(), 0);

    delete p;
    p = new RightTriangle(4, -3);

    EXPECT_EQ(p->getX(), 0);
    EXPECT_EQ(p->getY(), 0);
    EXPECT_EQ(p->getBase(), 4);
    EXPECT_EQ(p->getHeight(), -3);

    delete p;
    p = new RightTriangle(-3, 5, -6, 7);

    EXPECT_EQ(p->getX(), -3);
    EXPECT_EQ(p->getY(), 5);
    EXPECT_EQ(p->getBase(), -6);
    EXPECT_EQ(p->getHeight(), 7);

    delete p;
    p = nullptr;
}

// TEST 13 - RightTriangle setX(), setY(), setBase(), & setHeight()
TEST(RightTriangleTest, RightTriangle_setters) {
    RightTriangle* r = new RightTriangle;
    r->setX(16);
    r->setY(-40);
    r->setBase(21);
    r->setHeight(-19);

    EXPECT_EQ(r->getX(), 16);
    EXPECT_EQ(r->getY(), -40);
    EXPECT_EQ(r->getBase(), 21);
    EXPECT_EQ(r->getHeight(), -19);

    delete r;
    r = nullptr;
}

// TEST 14 [PART 1] - RightTriangle copy()
TEST(RightTriangleTest, RightTriangle_copy) {
    RightTriangle r(-20, 7, 14, -2);
    RightTriangle* p = r.copy();

    EXPECT_EQ(p->getX(), r.getX());
    EXPECT_EQ(p->getY(), r.getY());
    EXPECT_EQ(p->getBase(), r.getBase());
    EXPECT_EQ(p->getHeight(), r.getHeight());

    delete p;
    p = nullptr;
}

// TEST 14 [PART 2] - RightTriangle as_string()
TEST(RightTriangleTest, RightTriangle_AsString) {
    RightTriangle joe(-9, 2, -13, 5);
    int x = -9;
    int y = 2;
    int Base = -13;
    int Height = 5;
    string RTStr = "It's a Right Triangle at x: " + to_string(x) + ", y: " + to_string(y) + " with base: " + to_string(Base) + " and height: " + to_string(Height);

    EXPECT_EQ(joe.as_string(), RTStr);
}

// #############################################################
// 
// CanvasList Tests
//
//
// TEST 15 - Default constructor
TEST(CanvasListTest, CanvasList_default_constructor) {
    CanvasList c;

    EXPECT_EQ(c.front(), nullptr);
    EXPECT_EQ(c.size(), 0);
}

// TESTS 16 & 17 - Copy constructor
TEST(CanvasListTest, CanvasList_copy_constructor) {
    CanvasList c;
    c.push_back(new Shape(1, 2));
    CanvasList c_copy(c);
    bool notSameShapeAddress = (c.shape_at(0) != c_copy.shape_at(0));

    EXPECT_EQ(notSameShapeAddress, true);
    EXPECT_EQ(c.shape_at(0)->getX(), 1);
    EXPECT_EQ(c.shape_at(0)->getY(), 2);
}

// TEST 18 - Assignment operator=
TEST(CanvasListTest, CanvasList_assignment_operator) {
    CanvasList c;
    c.push_back(new Shape(-3, 5));
    c.push_back(new Shape);
    c.push_back(new Shape(1, 2));
    CanvasList c2;

    c2 = c;
    bool notSameShapeAddress = true;
    for (int i = 0; i < c.size(); i++) {
        if (c.shape_at(i) == c2.shape_at(i)) {
            notSameShapeAddress = false;
            break;
        }
    }

    EXPECT_EQ(notSameShapeAddress, true);
    for (int i = 0; i < c2.size(); i++) {
        EXPECT_EQ(c.shape_at(i)->as_string(), c2.shape_at(i)->as_string());
    }
}

// TEST 21 - Clear
TEST(CanvasListTest, CanvasList_clear) {
    CanvasList c;
    c.push_back(new Shape);
    c.push_back(new Shape(-6, -9));
    c.push_back(new Shape(1, 1));
    c.clear();

    EXPECT_EQ(c.empty(), true);
}

// TESTS 22-25 - Insert after
TEST(CanvasListTest, CanvasList_insert_after) {
    CanvasList c;
    Shape* myShape = new Shape(3, 3);
    c.insert_after(0, myShape);

    EXPECT_EQ(c.empty(), true);

    c.push_front(myShape);

    EXPECT_EQ(c.size(), 1);
    EXPECT_EQ(c.shape_at(0), myShape);
    EXPECT_EQ(c.shape_at(0)->as_string(), myShape->as_string());

    myShape = new Shape(-1, -2);
    c.insert_after(0, myShape);

    EXPECT_EQ(c.size(), 2);
    EXPECT_EQ(c.shape_at(1), myShape);
    EXPECT_EQ(c.shape_at(1)->as_string(), myShape->as_string());

    c.push_front(new Shape);
    c.push_front(new Shape);
    myShape = new Shape(5, 5);
    c.insert_after(2, myShape);

    EXPECT_EQ(c.size(), 5);
    EXPECT_EQ(c.shape_at(3), myShape);
    EXPECT_EQ(c.front()->next->next->next->next->value, c.shape_at(4));

    myShape = nullptr;
}

// TEST 26 - Remove at
TEST(CanvasListTest, CanvasList_remove_at) {
    CanvasList c;

    c.push_back(new Shape);
    c.remove_at(1);

    EXPECT_EQ(c.size(), 1);

    c.remove_at(0);

    EXPECT_EQ(c.empty(), true);

    c.push_back(new Shape);
    c.push_back(new Shape(1, 1));
    c.push_back(new Shape(2, 2));

    c.remove_at(2);

    EXPECT_EQ(c.size(), 2);
    EXPECT_EQ(c.find(2, 2), -1);
}

// TEST 29 - Remove every other
TEST(CanvasListTest, CanvasList_remove_every_other) {
    CanvasList c;
    int MAX_SIZE = 10;
    for (int i = 0; i < MAX_SIZE; i++) {
        c.push_back(new Shape(i, -i));
    }

    c.remove_every_other();

    EXPECT_EQ(c.size(), (MAX_SIZE+1)/2);
    for (int i = 0; i < c.size(); i++) {
        EXPECT_EQ(c.find(i*2, -i*2), i);
    }
}

// TEST 31 - pop front & pop back
TEST(CanvasListTest, CanvasList_pops) {
    CanvasList c;
    int MAX_SIZE = 10;
    for (int i = 0; i < MAX_SIZE; i++) {
        c.push_back(new Shape(-i, i));
    }
    Shape* myShape;
    for (int i = 0; i < (MAX_SIZE+1)/2; i++) {
        myShape = c.pop_front();

        EXPECT_EQ(myShape->getX(), -i);
        EXPECT_EQ(myShape->getY(), i);
        EXPECT_EQ(c.size(), MAX_SIZE-i-1);

        delete myShape;
    }
    for (int i = 0; i < MAX_SIZE/2; i++) {
        myShape = c.pop_back();

        EXPECT_EQ(myShape->getX(), -(MAX_SIZE-i-1));
        EXPECT_EQ(myShape->getY(), MAX_SIZE-i-1);
        EXPECT_EQ(c.size(), (MAX_SIZE/2)-i-1);

        delete myShape;
    }

    myShape = nullptr;
}
