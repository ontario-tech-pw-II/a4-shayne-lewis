#include <iostream>
using namespace std;

class Circle {
  private:  
    int x,y;      // center of circle
    double r;    // radius of circle

  public:
   
    Circle(int =0,int=0, double =1.0);
    void print() const;
    double area() const;

    double operator+(const Circle &) const;

    Circle & operator++();
    Circle operator++(int);

  friend ostream & operator<<(ostream &out, const Circle &);
  friend istream & operator>>(istream &in, Circle &);
};

Circle::Circle(int x,int y, double r)
{
  // Initialize the object here
  this->x = x;
  this->y = y;
  this->r = r;
}

double Circle::area() const 
{
  // Return the area of a circle  
  return (3.14*(r*r));
}

double Circle::operator+(const Circle & c) const
{
   // + Return the area of two circles  
    return 2*(c.area());
}

Circle & Circle::operator++()
{
  // Increment the radius by 1
    r++;
    return *this;
}

Circle Circle::operator++(int)
{
  Circle temp = *this;
  
  //increment the radius by 1
    r++;
    return temp;
}

ostream & operator<<(ostream &out, const Circle &c)
{

  // print a circle in the out stream (the format is the same as print())
    out << "Circle =(" << c.x << "," << c.y << "," << c.r << ")" << endl;
    return out;
}

istream & operator>>(istream &in, Circle &c)
{
 
 // Read a circle information from the in stream
    int tmp_x;
    int tmp_y;
    double tmp_r;

    cout << "\tx: ";
    in >> tmp_x;
    cout << "\ty: ";
    in >> tmp_y;
    cout << "\tr: ";
    in >> tmp_r;

    c = Circle(tmp_x, tmp_y, tmp_r);
    return in;
}


void Circle::print() const
{
  cout << "Circle =(" << x << "," << y << "," << r << ")" << endl;
}



int main()
{
  Circle a;
  Circle b(2,3,3.0);

  a.print();
  b.print();
  
  cout << "The area a + b is: " << a+b << endl;
  ++a;
  a.print();

  a++;
  a.print();

  cout << a;

  cin >> a;
  cout <<a;

  return 0;

}