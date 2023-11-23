#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Figure
{
protected:
    int x;
    int y;

public:
    Figure()
    {
        x = get_rand();
        y = get_rand();
    }
    Figure(int x, int y) : x(x), y(y) {}
    virtual ~Figure() {}
    int get_rand() const
    {
        return rand() % 100;
    }
    virtual void input()
    {
        cout << "Enter Coordinates (x, y): ";
        cin >> x >> y;
    }
    virtual void print()
    {
        cout << "Coordinates (x, y): (" << x << ", " << y << ")\n";
    }
    virtual void add_print()
    {
        cout << "Number of objects created";
    }
    virtual void output_print()
    {
        cout << "Number of existing objects";
    }
    virtual double enter_perimeter() const = 0;

    int enter_x() const { return x; }
    int enter_y() const { return y; }
};
class Line : public Figure
{
    static int added;
    static int output;

protected:
    int x2;
    int y2;
    double length;

public:
    Line() : Figure()
    {
        x2 = get_rand();
        y2 = get_rand();
        count_length();
        ++added;
        ++output;
    }
    Line(int x1, int y1, int x2, int y2) : Figure(x1, y1), x2(x2), y2(y2)
    {
        count_length();
        ++added;
        ++output;
    }
    ~Line()
    {
        --output;
    };
    void input()
    {
        Figure::input();
        cout << "Enter Coordinates of the point (x2, y2): ";
        cin >> x2 >> y2;
        count_length();
    }
    void print()
    {
        cout << "\n\tline:\n";
        Figure::print();
        cout << "Coordinates of the point (x2, y2): (" << x2 << ", " << y2 << ")\n";
        cout << "Line length: " << length << endl;
    }
    void add_print()
    {
        Figure::add_print();
        cout << "line: " << added << endl;
    }
    void output_print()
    {
        Figure::add_print();
        cout << "line: " << output << endl;
    }
    double get_length() const { return length; }
    double enter_perimeter() const { return 0; }
    void count_length()
    {
        length = sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));
    }
};
class Square : public Line
{
    static int added;
    static int output;

protected:
    int x3;
    int y3;
    double perimeter;
    double area;

public:
    Square() : Line()
    {
        y2 = y;
        count_length();
        x3 = x2;
        y3 = y2 - length;
        count_perimeter();
        count_area();
        ++added;
        ++output;
    }
    Square(int x, int y, int x2, int y2, int x3, int y3) : Line(x, y, x2, y2), x3(x3), y3(y3)
    {
        count_perimeter();
        count_area();
        ++added;
        ++output;
    }
    ~Square()
    {
        --output;
    }
    void input()
    {
        Line::input();
        cout << "Enter Coordinates of the point (x3, y3): ";
        cin >> x3 >> y3;
        count_perimeter();
        count_area();
    }
    void print()
    {
        cout << "\n\tSquare:\n";
        Line::print();
        cout << "\nCoordinates of the point (x3, y3): (" << x3 << ", " << y3 << ")\n";
        cout << "Coordinates of the point (x4, y4): (" << x << ", " << y3 << ")\n";
        cout << "Side Length: " << length << "\n";
        cout << "Perimeter: " << perimeter << "\n";
        cout << "Square: " << area << endl;
    }
    void add_print()
    {
        Figure::add_print();
        cout << "Square: " << added << endl;
    }
    void output_print()
    {
        Figure::add_print();
        cout << "Square: " << output << endl;
    }
    double enter_perimeter() const { return perimeter; }
    double get_area() const { return area; }
    virtual void count_perimeter()
    {
        perimeter = 4 * length;
    }
    virtual void count_area()
    {
        area = length * length;
    }
};
class Rectangle : public Square
{
    static int added;
    static int output;

protected:
    double height;

public:
    Rectangle() : Square()
    {
        y3 = y2 - get_rand();
        count_height();
        count_perimeter();
        count_area();
        ++added;
        ++output;
    }
    Rectangle(int x, int y, int x2, int y2, int x3, int y3) : Square(x, y, x2, y2, x3, y3)
    {
        y3 = y2 - get_rand();
        count_height();
        count_perimeter();
        count_area();
        ++added;
        ++output;
    }
    ~Rectangle()
    {
        --output;
    };
    void input()
    {
        Square::input();
        count_height();
    }
    void print()
    {
        cout << "\n\tRectangle:\n";
        Line::print();
        cout << "\nCoordinates of the point (x3, y3): (" << x3 << ", " << y3 << ")\n";
        cout << "Coordinates of the point (x4, y4): (" << x << ", " << y3 << ")\n";
        cout << "Width: " << length << "\nHeight: " << height << "\n";
        cout << "Perimeter: " << perimeter << "\n";
        cout << "Square: " << area << endl;
    }
    void add_print()
    {
        Figure::add_print();
        cout << "Rectangle: " << added << endl;
    }
    void output_print()
    {
        Figure::add_print();
        cout << "Rectangle: " << output << endl;
    }
    double get_height() const { return height; }
    void count_height()
    {
        height = fabs(y2 - y3);
    }
    void count_perimeter()
    {
        perimeter = 2 * length + 2 * height;
    }
    void count_area()
    {
        area = length * height;
    }
};
class Circle : public Figure
{
    static int added;
    static int output;

protected:
    int radius;
    double perimeter;
    double area;

public:
    Circle() : Figure()
    {
        radius = get_rand();
        count_perimeter();
        count_area();
        ++added;
        ++output;
    }
    Circle(int x1, int y1, int radius) : Figure(x1, y1), radius(radius)
    {
        count_perimeter();
        count_area();
        ++added;
        ++output;
    }
    ~Circle()
    {
        --output;
    };
    void input()
    {
        Figure::input();
        cout << "Enter radius: ";
        cin >> radius;
        count_perimeter();
        count_area();
    }
    void print()
    {
        cout << "\n\tCircle:\n";
        Figure::print();
        cout << "radius: " << radius << "\n";
        cout << "Perimeter: " << perimeter << "\n";
        cout << "Square: " << area << endl;
    }
    void add_print()
    {
        Figure::add_print();
        cout << "a_circle: " << added << endl;
    }
    void output_print()
    {
        Figure::add_print();
        cout << "a_circle: " << output << endl;
    }
    int get_radius() const { return radius; }
    virtual double enter_perimeter() const { return perimeter; }
    virtual double get_area() const { return area; }
    void count_perimeter()
    {
        perimeter = 2 * M_PI * radius;
    }
    void count_area()
    {
        area = M_PI * radius * radius;
    }
};
class Ellipse : public Circle
{
    static int added;
    static int output;

protected:
    int y_radius;

public:
    Ellipse() : Circle()
    {
        y_radius = get_rand();
        count_perimeter();
        count_area();
        ++added;
        ++output;
    }
    Ellipse(int x1, int y1, int radius, int y_radius) : Circle(x1, y1, radius), y_radius(y_radius)
    {
        count_perimeter();
        count_area();
        ++added;
        ++output;
    }
    ~Ellipse()
    {
        --output;
    };
    void input()
    {
        Figure::input();
        cout << "Enter radius: ";
        cin >> radius;
        count_perimeter();
        count_area();
    }
    void print()
    {
        cout << "\n\tEllipse:\n";
        Figure::print();
        cout << "Large semi - axis: " << radius << "\nSmall half - axis: " << y_radius << "\n";
        cout << "Perimeter: " << perimeter << "\n";
        cout << "Square: " << area << endl;
    }
    void add_print()
    {
        Figure::add_print();
        cout << "Ellipse: " << added << endl;
    }
    void output_print()
    {
        Figure::add_print();
        cout << "Ellipse: " << output << endl;
    }
    int enter_y_radius() const { return y_radius; }
    void count_perimeter()
    {
        perimeter = 2 * M_PI * sqrt((radius * radius + y_radius * y_radius) / 2);
    }
    void count_area()
    {
        area = M_PI * radius * y_radius;
    }
};

int Line::added = 0;
int Line::output = 0;

int Square::added = 0;
int Square::output = 0;

int Rectangle::added = 0;
int Rectangle::output = 0;

int Circle::added = 0;
int Circle::output = 0;

int Ellipse::added = 0;
int Ellipse::output = 0;

int main()
{
    srand((time(NULL)));
    Line line1(20, 10, 10, 20);
    Line line2;
    Square square1(0, 7, 7, 7, 7, 0);
    Square square2;
    Rectangle rectangle1(0, 20, 7, 20, 7, 0);
    Rectangle rectangle2;
    Circle circle1(4, 7, 20);
    Circle circle2;
    Ellipse ellipse1(4, 7, 20, 7);
    Ellipse ellipse2;

    rectangle2.add_print();
    rectangle2.output_print();

    Rectangle *rect_ptr;

    rectangle2.add_print();
    rectangle2.output_print();

    Figure *figures[4];
    figures[0] = new Square();
    figures[1] = new Rectangle();
    figures[2] = new Circle();
    figures[3] = new Ellipse();

    rectangle2.add_print();
    rectangle2.output_print();

    cout << "Array of shapes: " << endl;
    for (int i = 0; i < 4; ++i)
    {
        cout << " Perimeter shape " << i + 1 << ": " << figures[i]->enter_perimeter() << endl;
    }
    for (int i = 0; i < 4; ++i)
    {
        delete figures[i];
    }
    rectangle2.add_print();
    rectangle2.output_print();

    return 0;
}