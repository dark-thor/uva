#include<iostream>

using namespace std;

unsigned *cycleLength;
unsigned maxLength;

unsigned cycle_length(unsigned n)
{
    unsigned length;
    if (n <= 1000000 && cycleLength[n])
        return cycleLength[n];

    if (n == 1)
        return 1;
    else if (n % 2)
        length = 1 + cycle_length(3 * n + 1);
    else
        length = 1 + cycle_length(n / 2);
    if (n <= 1000000)
      cycleLength[n] = length;

    return length;
}

int main()
{
    unsigned start=0, end=0, currLength=0, i,j;
    cycleLength = new unsigned [1000001];
    cycleLength[1] = 1;
    while(cin>>start)
    {
        cin>>end;
        maxLength = 0;
        if (start>end) {
            i = end;
            j = start;
        } else {
            i = start;
            j = end;
        }
        for (; i<=j; i++) {
            currLength = cycle_length(i);
            if (maxLength < currLength)
               maxLength = currLength;
        }
        cout<<start<<' '<<end<<' '<<maxLength<<endl;
    }
    delete cycleLength;
    return 0;
}
