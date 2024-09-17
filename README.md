# Project 3: Canvas List with Shapes
**CS 251 - Spring 2024**  
**Conor McJannett**  
**Date**: 03/04/2024

## Project Overview
This project implements a dynamic canvas using a linked list to manage various shapes such as circles, rectangles, and right triangles. The primary data structure, `CanvasList`, stores shapes and provides operations for manipulating and displaying them.

The project showcases how to manage complex objects (shapes) within a linked list, ensuring proper memory handling and dynamic behavior. It also demonstrates polymorphism by allowing different types of shapes to share a common interface while each shape has its own unique properties.

## Code Components

### `main.cpp`
This file tests the functionality of the `CanvasList` and `Shape` classes. The following operations are tested:
1. **Adding Shapes**: Different shapes (`Shape`, `Circle`, `Rect`, and `RightTriangle`) are dynamically allocated and added to the canvas at both the front and back.
2. **Removing Shapes**: Shapes can be removed from the canvas using the `pop_back()` method.
3. **Inserting Shapes**: Shapes can be inserted after specific indices within the canvas.
4. **Displaying and Memory Management**: The canvas's contents are printed using the `draw()` method, and memory addresses of each node and shape are shown using `print_addresses()`.

The program dynamically allocates memory for each shape using `new` and ensures proper memory management by deleting nodes when they are removed.

### `canvaslist.h`
This file defines the core data structure, `CanvasList`, which stores shapes in a singly linked list using `ShapeNode`.

**Key Methods**:
1. **push_front()** and **push_back()**: Add shapes to the front and back of the list.
2. **pop_front()** and **pop_back()**: Remove and return shapes from the front or back of the list.
3. **insert_after()**: Insert a shape after a specific index.
4. **remove_every_other()**: Removes every other element in the list, starting at index 1.
5. **size()** and **empty()**: Return the size of the list and check if it is empty.
6. **draw()**: Outputs the shapes in the list.
7. **print_addresses()**: Displays the memory addresses of each node and shape.

### `shape.h`
This file defines the base `Shape` class and its derived classes: `Circle`, `Rect`, and `RightTriangle`.

#### **Shape Class**
The `Shape` class is the base class for all shapes in this project. It stores the common properties `x` and `y` coordinates and provides the following key methods:
- **as_string()**: Converts the shape into a string representation.
- **getX()/getY()** and **setX()/setY()**: Get and set the shape's coordinates.
- **copy()**: Returns a deep copy of the shape.

#### **Circle Class**
The `Circle` class extends `Shape` by adding a `radius` property and includes:
- **getRadius()** and **setRadius()**: Get and set the radius of the circle.
- **as_string()**: Returns a string representation of the circle in the format:  
  `"It's a Circle at x: 2, y: 4, radius: 3"`.

#### **Rect Class**
The `Rect` class adds `width` and `height` properties to the base `Shape`:
- **getWidth()** and **getHeight()**: Get the dimensions of the rectangle.
- **as_string()**: Returns a string representation of the rectangle:  
  `"It's a Rectangle at x: 0, y: 0 with width: 0 and height: 10"`.

#### **RightTriangle Class**
The `RightTriangle` class extends `Shape` by adding `base` and `height` properties:
- **getBase()** and **getHeight()**: Get and set the triangle's base and height.
- **as_string()**: Returns a string representation of the right triangle:  
  `"Right Triangle at x: 1, y: 2 with base: 3 and height: 4"`.

## How to Run the Project
1. **Compilation**: Compile the project using `g++`:
    ```bash
    g++ -o project main.cpp canvaslist.cpp shape.cpp
    ```
2. **Execution**: Run the compiled project:
    ```bash
    ./project
    ```

The program will output the list of shapes on the canvas, along with addresses and memory management details.

## Future Work
- Additional shapes can be added by extending the `Shape` class.
- More complex canvas operations, such as grouping and transforming shapes, could be implemented.

## Conclusion
This project demonstrates how to manage a dynamic collection of objects (shapes) using linked lists. The modular design allows easy extension for additional shape types, showcasing the power of polymorphism and proper memory management in C++.
