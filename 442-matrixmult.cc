#include <stack>
#include <iostream>
#include <string>

using namespace std;

struct Matrix {
    Matrix()
        :row(0),column(0)
    {}
    unsigned int row;
    unsigned int column;
};

int main()
{
    unsigned int count = 0;
    Matrix M[26];
    char id;
    string expr;
    cin>>count;
    
    while (count) {
        cin>>id;
        unsigned int index = id - 'A';
        cin>>M[index].row>>M[index].column;
        count--;
    }

    while(cin>>expr) {
        Matrix result, m1, m2;
        unsigned long num = 0;
        bool error = false;
        stack<Matrix> s;
        for (unsigned int i=0; i<expr.length(); i++) {
            char ch = expr[i];
            if (ch == ')') {
                m1 = s.top(); s.pop();
                m2 = s.top(); s.pop();

                if (m1.row != m2.column) {
                    error = true;
                    cout<<"error"<<endl;
                    break;
                }
                num+=m2.row*m2.column*m1.column;
                result.row = m2.row;
                result.column = m1.column;
                s.push(result);
            } else if (ch >= 'A' && ch <= 'Z')
                s.push(M[ch-'A']);
        }
        if (!error)
            cout<<num<<endl;
    }

    return 0;
}
