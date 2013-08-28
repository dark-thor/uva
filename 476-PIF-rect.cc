#include <iostream>
#include <vector>

using namespace std;

struct Rect {
    Rect (float l, float t, float r, float b)
        : left(l), top(t), right(r), bottom(b)
    {}

    bool contains (float x, float y) {
        if (x <= left || x >= right || y <= bottom || y>= top) return false;
        return true;
    }
    float left;
    float top;
    float right;
    float bottom;
};

int main()
{
    float left, top, right, bottom;
    float x, y;
    char ch;
    vector <Rect> rects;
    unsigned int point = 1;

    while (cin>>ch && ch != '*') {
        cin>>left>>top>>right>>bottom;
        if (ch != 'r')
            cout<<"error invalid input"<<endl;
        rects.push_back(Rect(left, top, right, bottom));
    }

    while (cin>>x>>y && x != 9999.9f && y != 9999.9f) {
        bool contained = false;
        for (unsigned int i = 0; i < rects.size(); i++)
            if (rects[i].contains(x, y)) {
                cout<<"Point "<<point<<" is contained in figure "<<i+1<<endl;
                contained = true;
            }
        if (!contained)
            cout<<"Point "<<point<<" is not contained in any figure"<<endl;
        point++;
    }

    return 0;
}
