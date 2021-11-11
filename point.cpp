#include <iostream>

using namespace std;

class Point{
  float x;
  float y;
public:
  Point(float a, float b){x=a;y=b;}
  void print(){cout << "("<<x<<","<<y<<")"<<endl;}
};

Point::Point(){
}

int main(){
  Point z(2,4);
  z.print();
  Point w;
  w.print();

  return 0;
}
