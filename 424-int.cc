#include <iostream>
#include <string>

using namespace std;

#define MAX_LENGTH 100

int result[MAX_LENGTH+2];
int main()
{
    string num;
    unsigned int size=0;
    while(cin>>num && num != "0")
    {
        unsigned int length = num.length();
        unsigned int carry = 0;
        for (int i=length-1; i>=0;i--) {
            carry+=result[length-i-1]+ (num[i]-'0');
            result[length-i-1]=carry%10;
            carry/=10;
        }
        for (int i=length; carry && i < size; i++) {
            carry+=result[i];
            result[i]=carry%10;
            carry/=10;
        }
        if (size < length)
            size = length;
        if (carry == 1)
            result[size++]=1;
    }

    for (int i=size-1; i>=0; i--)
        cout<<result[i];
    cout<<endl;
    return 0;
}
