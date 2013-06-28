#include <iostream>
#include <string>
#include <map>

using namespace std;
map<string,int> m;
unsigned int pos = 1;

void create_map(string str, unsigned int n)
{
    if (str.length() == n) {
        m[str] = pos++;
        return;
    }

    char ch;
    if (str == "")
        ch='a';
    else 
        ch = str[str.length()-1] + 1;

    for (char i=ch; i<='z'; i++)
        create_map(str+i, n);
}

int main()
{
    for (unsigned int i=1; i<=5; i++)
        create_map("", i);

    string str;
    while (cin>>str)
        cout<<m[str]<<endl;
    return 0;
}

