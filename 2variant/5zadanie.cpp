#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

class Figure {
public:
    virtual void input() = 0;
    virtual void output() const = 0;

    virtual ~Figure() {}
};

class Point {
public:
    double x, y;

    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}
    void input() {
        std::cout << "Enter x and y coordinates: ";
        std::cin >> x >> y;
    }
    void output() const {
        std::cout << "Coordinates: (" << x << ", " << y << ")";
    }
};

class Line : public Figure {
protected:
    Point start, end;
    double length;

public:
    Line() : start(), end() {
        calculateLength();
    }
    Line(double x1, double y1, double x2, double y2) : start(x1, y1), end(x2, y2) {
        calculateLength();
    }
    void input() {
        start.input();
        end.input();
        calculateLength();
    }
    void output() const {
        std::cout << "Line ";
        start.output();
        std::cout << " to ";
        end.output();
        std::cout << ", Length: " << length << std::endl;
    }
    void calculateLength() {
        length = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
    }
};

class Square : public Line {
public:
    Square() : Line() {}
    Square(double x, double y, double s) : Line(x, y, x + s, y) {
        side = s;
    }
    void input() {
        Line::input();
        std::cout << "Enter the side length: ";
        std::cin >> side;
    }
    void output() const {
        std::cout << "Square, Top-Left Corner: ";
        start.output();
        std::cout << ", Side Length: " << side << std::endl;
    }
    double perimeter() const {
        return 4 * side;
    }
    double area() const {
        return side * side;
    }
private:
    double side;
};

class Rectangle : public Square {
public:
    Rectangle() : Square() {}
    Rectangle(double x, double y, double w, double h) : Square(x, y, w) {
        width = w;
        height = h;
    }
    void input() {
        Square::input();
        std::cout << "Enter the height: ";
        std::cin >> height;
    }
    void output() const {
        std::cout << "Rectangle, Top-Left Corner: ";
        start.output();
        std::cout << ", Width: " << width << ", Height: " << height << std::endl;
    }
    double perimeter() const {
        return 2 * (width + height);
    }
    double area() const {
        return width * height;
    }
private:
    double width, height;
};

class Circle : public Figure {
protected:
    Point center;
    double radius;

public:
    Circle() : center(), radius(0) {}
    Circle(double x, double y, double r) : center(x, y), radius(r) {}
    void input() {
        center.input();
        std::cout << "Enter the radius: ";
        std::cin >> radius;
    }
    void output() const {
        std::cout << "Circle, Center: ";
        center.output();
        std::cout << ", Radius: " << radius << std::endl;
    }
    double perimeter() const {
        return 2 * M_PI * radius;
    }
    double area() const {
        return M_PI * radius * radius;
    }
};

class Ellipse : public Circle {
protected:
    double minorAxis;

public:
    Ellipse() : Circle() {}
    Ellipse(double x, double y, double major, double minor) : Circle(x, y, major) {
        minorAxis = minor;
    }
    void input() {
        Circle::input();
        std::cout << "Enter the minor axis length: ";
        std::cin >> minorAxis;
    }
    void output() const {
        std::cout << "Ellipse, Center: ";
        center.output();
        std::cout << ", Major Axis: " << radius << ", Minor Axis: " << minorAxis << std::endl;
    }
    double perimeter() const {
        return 4 * (M_PI * radius * minorAxis + abs(radius - minorAxis)) / (radius + minorAxis);
    }
    double area() const {
        return M_PI * radius * minorAxis;
    }
};

int main() {
    std::srand(static_cast<unsigned>(std::time(0)));

    Line line1(1.0, 2.0, 4.0, 6.0);
    Line line2;
    Square square1(2.0, 3.0, 5.0);
    Square square2;
    Rectangle rectangle1(2.0, 3.0, 4.0, 6.0);
    Rectangle rectangle2;
    Circle circle1(5.0, 5.0, 3.0);
    Circle circle2;
    Ellipse ellipse1(7.0, 7.0, 4.0, 2.0);
    Ellipse ellipse2;

    line1.output();
    line2.output();

    square1.output();
    std::cout << "Perimeter: " << square1.perimeter() << ", Area: " << square1.area() << std::endl;

    square2.input();
    square2.output();
    std::cout << "Perimeter: " << square2.perimeter() << ", Area: " << square2.area() << std::endl;

    rectangle1.output();
    std::cout << "Perimeter: " << rectangle1.perimeter() << ", Area: " << rectangle1.area() << std::endl;

    rectangle2.input();
    rectangle2.output();
    std::cout << "Perimeter: " << rectangle2.perimeter() << ", Area: " << rectangle2.area() << std::endl;

    circle1.output();
    std::cout << "Perimeter: " << circle1.perimeter() << ", Area: " << circle1.area() << std::endl;

    circle2.input();
    circle2.output();
    std::cout << "Perimeter: " << circle2.perimeter() << ", Area: " << circle2.area() << std::endl;

    ellipse1.output();
    std::cout << "Perimeter: " << ellipse1.perimeter() << ", Area: " << ellipse1.area() << std::endl;

    ellipse2.input();
    ellipse2.output();
    std::cout << "Perimeter: " << ellipse2.perimeter() << ", Area: " << ellipse2.area() << std::endl;


    Rectangle* rectangles = new Rectangle[3];

    for (int i = 0; i < 3; i++) {
        rectangles[i].input();
    }

    for (int i = 0; i < 3; i++) {
        rectangles[i].output();
        std::cout << "Perimeter: " << rectangles[i].perimeter() << ", Area: " << rectangles[i].area() << std::endl;
    }

    delete[] rectangles;
    return 0;
}