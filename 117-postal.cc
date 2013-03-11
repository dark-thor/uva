#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

unsigned adj[26][26];
unsigned degree[26];

void reset()
{
  for (int i=0; i<26; i++){
    for (int j=0; j<26; j++)
      adj[i][j] = 0;
    degree[i] = 0;
  }
}

unsigned sumOfEdges()
{
  unsigned sum=0;
  for (int i=0; i<26; i++)
    for (int j=0; j<i; j++)
      sum+=adj[i][j];
  return sum;
}

unsigned shortestPath(int start, int end)
{
  bool color[26]={false};
  unsigned distance[26];
  fill_n(distance, 26, UINT_MAX);
  vector<int> v;
  for (int i=0; i<26; i++)
    if (!degree[i])
      color[i] = true;

  v.push_back(start);
  distance[start]=0;
  while (!v.empty()) {
    int index=0;
    for (int i=1; i<v.size(); i++) {
      if (distance[v[i]]<distance[v[index]])
        index=i;
    }
    int curr=v[index];
    v.erase(v.begin()+index);
    if (color[curr])
      continue;
    color[curr] = true;

    for (int i=0; i<26; i++)
      if (adj[curr][i] && !color[i]) {
        distance[i] = min(distance[i], distance[curr]+adj[curr][i]);
        v.push_back(i);
      }
  }
  return distance[end];
}

int main()
{
  string str;
  while (cin>>str) {
    if (!str.compare("deadend")) {
      unsigned tourLength = 0;
      int oddNodes[2]={-1,-1};
      for (int i=0,j=0; i<26 && j<2; i++) {
        if (degree[i]%2) {
          oddNodes[j]=i;
          j++;
        }
      }
      tourLength = sumOfEdges();
      if (oddNodes[1] != -1)
        tourLength+=shortestPath(oddNodes[0], oddNodes[1]);
      cout<<tourLength<<endl;
      reset();
    } else {
      unsigned length = str.length();
      unsigned i=str[0]-'a';
      unsigned j=str[length-1]-'a';
      adj[i][j]=adj[j][i]=length; //undirected graph
      degree[i]++;
      degree[j]++;
    }
  }
  return 0;
}
