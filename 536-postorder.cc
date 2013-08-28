#include <iostream>
#include <string>

using namespace std;

void postOrder(string preOrder, string inOrder)
{
    if (!preOrder.length()|| !inOrder.length())
        return;

    size_t pos = inOrder.find(preOrder[0]);
    string leftPre = preOrder.substr(1, pos);
    string rightPre = preOrder.substr(pos+1);
    string leftIn = inOrder.substr(0, pos);
    string rightIn = inOrder.substr(pos+1);

    postOrder(leftPre, leftIn);
    postOrder(rightPre, rightIn);
    cout<<preOrder[0];
}

int main()
{
    string preOrder, inOrder;

    while (cin>>preOrder>>inOrder) {
        postOrder(preOrder, inOrder);
        cout<<endl;
    }
    return 0;
}
