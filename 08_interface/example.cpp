/* An interface describes the behavior or capabilities of a C++ class without 
 * committing to a particular implementation of that class.
 *
 * The C++ interfaces are implemented using abstract classes. 
 * A class is made abstract by declaring at least one of its functions as pure 
 * virtual function. A pure virtual function is specified by placing "= 0" in 
 * its declaration
 *
 * ref: https://www.tutorialspoint.com/cplusplus/cpp_interfaces.htm
 */

#include <iostream>

using namespace std;

// Base class
class Shape {
public:
  // pure virtual function providing interface framework.
  virtual int getArea() = 0;
  void setWidth(int w) { width = w; }

  void setHeight(int h) { height = h; }

protected:
  int width;
  int height;
};

// Derived classes
class Rectangle : public Shape {
public:
  int getArea() { return (width * height); }
};

class Triangle : public Shape {
public:
  int getArea() { return (width * height) / 2; }
};

int main(void) {
  Rectangle Rect;
  Triangle Tri;

  Rect.setWidth(5);
  Rect.setHeight(7);

  // Print the area of the object.
  cout << "Total Rectangle area: " << Rect.getArea() << endl;

  Tri.setWidth(5);
  Tri.setHeight(7);

  // Print the area of the object.
  cout << "Total Triangle area: " << Tri.getArea() << endl;

  return 0;
}
