#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void getRowColumn(int p, int& row, int& col)
{
  int r=1,c=1;
  for (; r+c<=p; r+=c++);
  col = p-r;
  row = c+1;
}

bool isValidTriangle(int r[], int c[])
{
  if (r[0] == r[1]) {
    int l=c[1]-c[0];
    return (l > 0 && c[1] == c[2] && (l == r[2]-r[1]) && (l == r[2]-r[0]) && (l == c[2]-c[0]));
  } else if (r[1] == r[2]) {
    int l=c[2]-c[1];
    return (l>0 && c[0] == c[1] && (l == r[1]-r[0]) && (l == c[2]-c[0]) && (l == r[2]-r[0]));
  }
  return false;
}

bool isValidParallelogram(int r[], int c[])
{
  if (r[0] == r[1] && r[2] == r[3]) {
    int l = c[1]-c[0];
    if (c[0] == c[2] && c[1] == c[3])
      return (l>0 && l == r[2] - r[0]);
    else if (c[1] == c[2])
      return (l>0 && l == r[2] - r[1]) && (l == c[3]-c[2]);
  }
  else if (r[1] == r[2] && c[0] == c[1] && c[2] == c[3]) {
    int l = r[1]-r[0];
    return (l>0 && l == c[2]-c[1] && (l == c[2]-c[0]) && (l==r[3]-r[1]));
  }
  return false;
}

bool isValidHexagon(int r[], int c[])
{
  int l = c[1]-c[0];
  return (l>0 && r[0] == r[1] && r[2] == r[3] && r[4] == r[5] && c[0] == c[2] && c[1] == c[4] && c[3] == c[5] &&
      l == r[2]-r[0] && l == c[3]-c[1] && l == r[4]-r[2]);
}

int main()
{
  string line;
  while (getline(cin, line)) {
    istringstream mystream(line);
    vector<int> v;
    int i,r[6],c[6], count=0;
    bool valid=false;
    while (mystream >> i) {
      v.push_back(i);
      cout<<i<<' ';
    }

    sort(v.begin(), v.end());
    count = v.size();
    for (int i=0; i<count; i++) {
      getRowColumn(v[i], r[i], c[i]);
    }
    switch(count) {
      case 3:
      if (valid = isValidTriangle(r,c))
          cout<<"are the vertices of a triangle";
      break;
      case 4:
      if (valid = isValidParallelogram(r,c))
        cout<<"are the vertices of a parallelogram";
      break;
      case 6:
      if (valid = isValidHexagon(r,c))
        cout<<"are the vertices of a hexagon";
      break;
      default:
      valid = false;
      break;
    }
    if (!valid)
      cout<<"are not the vertices of an acceptable figure";
    cout<<endl;

  }
  return 0;
}
