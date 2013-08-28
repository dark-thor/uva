#include <iostream>
#include <cmath>
#include <iomanip>

#define PI 3.141592653589793

using namespace std;

int main()
{
    double x1, y1, x2, y2, x3, y3;
    double a, b, c, area, cradius, circumference;

    while (cin>>x1>>y1>>x2>>y2>>x3>>y3) {
        a = sqrt(pow((x2 - x1), 2.0)+pow((y2 - y1), 2.0));
        b = sqrt(pow((x3 - x2), 2.0)+pow((y3 - y2), 2.0));
        c = sqrt(pow((x1 - x3), 2.0)+pow((y1 - y3), 2.0));
        area = 0.5* fabs(x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3);
        
        cradius = a * b * c / (4.0 * area);
        circumference = 2 * PI * cradius;

        cout<<fixed<<setprecision(2)<<circumference<<endl;
    }
    return 0;
}
