#include <iostream>
#include <cstring>

using namespace std;

class Graph {
    unsigned int* minDist;
    public:
    Graph() {
        minDist = new unsigned int[100*100];
    }
    ~Graph() {
        delete minDist;
    }
    void reset() {
        memset(minDist, 10000, sizeof(unsigned int)*10000);
    }

    unsigned int& operator () (unsigned int i, unsigned int j) {
        return minDist[100*i+j];
    }
};

int main()
{
    bool* pageNum = new bool[100];
    unsigned int x,y;
    Graph G;
    unsigned int caseNum = 1;

    while (cin>>x>>y && x!=0 && y!=0) {
        G.reset();
        memset(pageNum, false, sizeof(bool)*100);
        do {
            G(x-1,y-1) = 1;
            pageNum[x-1] = true;
            pageNum[y-1] = true;
        } while (cin>>x>>y && x!=0 && y!=0);

        for (unsigned int k=0; k<100; k++) {
            if (!pageNum[k]) continue;
            for (unsigned int i=0; i<100; i++) {
                if (!pageNum[i]) continue;
                for (unsigned int j=0; j<100; j++) {
                    if (!pageNum[j] || i==j || i==k || j==k) continue;
                    if (G(i, j) > G(i, k) + G(k, j)) {
                        G(i, j) = G(i ,k)+G(k, j);
                    }
                }
            }
        }

        unsigned int count = 0;
        double distance = 0;
        for (unsigned int i=0; i < 100; i++) {
            if (!pageNum[i]) continue;
            for (unsigned int j=0; j < 100; j++) {
                if (!pageNum[j] || i == j) continue;
                count++;
                distance += G(i ,j);
            }
        }
        cout.precision(3);
        cout<<fixed;
        cout<<"Case "<<caseNum++<<": average length between pages = "<<distance/count<<" clicks"<<endl;
    }
    return 0;
}
