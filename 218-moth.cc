#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Point {
  public:
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

vector <Point> points;

// returns anti-clockwise > 0, clockwise < 0, collinear = 0
double cross(Point o, Point a, Point b)
{
  return (a.x - o.x)*(b.y-o.y) - (a.y-o.y)*(b.x-o.x);
}

vector<Point> Hull()
{
  const int size = points.size();

  if (size <= 1)
    return points;
  sort(points.begin(),points.end());

  vector <Point> lower;
  vector <Point> upper;
  // lower hull
  for (int i=0,k=0; i<size; i++) {
    while (k>=2 && cross(lower[k-2], lower[k-1], points[i])<=0) {
      lower.pop_back();
      k--;
    }
    lower.push_back(points[i]);
    k++;
  }
  lower.pop_back();

  // upper hull
  for (int i=size-1, k=0; i>=0; i--) {
    while (k>=2 && cross(upper[k-2], upper[k-1], points[i])<=0) {
      upper.pop_back();
      k--;
    }
    upper.push_back(points[i]);
    k++;
  }
  upper.pop_back();

  lower.insert(lower.end(), upper.begin(), upper.end());
  return lower;
}


int main()
{
  unsigned int size, count=0;
  double x,y, perimeter = 0;
  vector <Point> hull;
  while (cin>>size && size !=0) {
    if (count)
      cout<<endl;
    count++;
    for (unsigned int i=0; i<size; i++) {
      cin>>x>>y;
      points.push_back(Point(x,y));
    }

    hull = Hull();

    cout<<"Region #"<<count<<':'<<endl;
    cout.precision(1);
    cout<<'('<<fixed<<hull[0].x<<','<<fixed<<hull[0].y<<")";
    for (int i=hull.size()-1; i>=0; i--)
      cout<<"-("<<fixed<<hull[i].x<<','<<fixed<<hull[i].y<<')';
    cout<<endl;

    for (int i=1; i<hull.size(); i++)
      perimeter += hull[i].distance(hull[i-1]);
    perimeter+=hull[0].distance(hull[hull.size()-1]);
    cout<<setprecision(2)<<"Perimeter length = "<<perimeter<<endl;
    hull.clear();
    points.clear();
    perimeter = 0;
  }
}
