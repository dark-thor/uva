#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Point {
  public:
    Point ()
      : x(0), y(0)
    {}
    Point (double a, double b)
      : x(a) ,y(b)
    {}
    bool operator < (Point a) const
    {
      if (x != a.x)
        return x<a.x;
      return y<a.y;
    }
    double distance(Point a)
    {
      return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));
    }
    double x;
    double y;
};

// returns anti-clockwise > 0, clockwise < 0, collinear = 0
double cross(Point o, Point a, Point b)
{
  return (a.x - o.x)*(b.y-o.y) - (a.y-o.y)*(b.x-o.x);
}

vector<Point> Hull(vector<Point>& points)
{
  const int size = points.size();

  if (size <= 1)
    return points;
  sort(points.begin(),points.end());

  vector<Point> hull(2*size);
  int k=0;
  // lower hull
  for (int i=0; i<size; i++) {
    while (k>=2 && cross(hull[k-2], hull[k-1], points[i])<=0) k--;
    hull[k++] = points[i];
  }

  // upper hull
  for (int i=size-1, t=k+1; i>=0; i--) {
    while (k>=t && cross(hull[k-2], hull[k-1], points[i])<=0) k--;
    hull[k++] = points[i];
  }

  hull.resize(k);
  return hull;
}


int main()
{
  unsigned int size, count=0;
  double x,y, perimeter = 0;
  vector <Point> hull;
  vector <Point> points;
  while (cin>>size && size !=0) {
    if (count)
      cout<<endl;
    count++;
    for (unsigned int i=0; i<size; i++) {
      cin>>x>>y;
      points.push_back(Point(x,y));
    }

    hull = Hull(points);

    cout<<"Region #"<<count<<':'<<endl;
    cout.precision(1);
    cout<<'('<<fixed<<hull[0].x<<','<<fixed<<hull[0].y<<")";
    for (int i=hull.size()-2; i>=0; i--)
      cout<<"-("<<fixed<<hull[i].x<<','<<fixed<<hull[i].y<<')';
    cout<<endl;

    for (int i=1; i<hull.size(); i++)
      perimeter += hull[i].distance(hull[i-1]);
    cout<<setprecision(2)<<"Perimeter length = "<<perimeter<<endl;
    hull.clear();
    points.clear();
    perimeter = 0;
  }
}
