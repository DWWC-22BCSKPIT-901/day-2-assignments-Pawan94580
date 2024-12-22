//Ques 4. Write a program to calculate the area of different shapes using
function overloading. Implement overloaded functions to compute the area
of a circle, a rectangle, and a triangle.

#include <iostream>
#include <cmath>
using namespace std;
class ShapeArea {
public:
double area(double radius) {
return M_PI * radius * radius;
}
double area(double length, double breadth) {
return length * breadth;
}
double area(double base, double height, bool isTriangle) {

return 0.5 * base * height; 
}
};
int main() {
ShapeArea shape;
double radius;
cout << "Enter the radius of the circle: ";
cin >> radius;
cout << "Area of the circle: " << shape.area(radius) << endl;
double length, breadth;
cout << "\nEnter the length and breadth of the rectangle: ";
cin >> length >> breadth;
cout << "Area of the rectangle: " << shape.area(length, breadth) << endl;
double base, height;
cout << "\nEnter the base and height of the triangle: ";
cin >> base >> height;
cout << "Area of the triangle: " << shape.area(base, height, true) << endl;
return 0;
}
