#include <iostream>

using namespace std;

bool G[5][5];
bool used[5][5];
int path[9];
int length;

void traverse()
{
    if (length == 8) {
        for (unsigned int i=0; i<9; i++)
            cout<<path[i]+1;
        cout<<endl;
        return;
    }

    for (unsigned int i=0; i<5; i++) {
        if (G[path[length]][i] && !used[path[length]][i]) {
            used[path[length]][i]=true;
            used[i][path[length]]=true;
            path[++length]=i;

            traverse();
            length--;
            used[path[length]][i]=false;
            used[i][path[length]]=false;
        }
    }
}

int main()
{

    G[0][1]=G[1][0]=G[0][4]=G[4][0]=G[0][2]=G[2][0]=true;
    G[1][2]=G[2][1]=G[1][4]=G[4][1]=true;
    G[2][3]=G[3][2]=G[2][4]=G[4][2]=true;
    G[3][4]=G[4][3]=true;

    traverse();

#if 0
    // list of 44 possible paths
123153452
123154352
123451352
123453152
123513452
123543152
125134532
125135432
125315432
125345132
125431532
125435132
132153452
132154352
132534512
132543512
134512352
134512532
134521532
134523512
134532152
134532512
135123452
135125432
135215432
135234512
135432152
135432512
152134532
152135432
152345312
152354312
153123452
153125432
153213452
153254312
153452132
153452312
154312352
154312532
154321352
154325312
154352132
154352312
#endif
    return 0;
}
