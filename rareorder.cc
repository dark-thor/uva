#include <iostream>
#include <string>

using namespace std;

bool map[26][26];
char result[26];
bool degree[26];

int main()
{
  string s1,s2;
  cin>>s1;
  while (cin>>s2 && s2[0] != '#')
  {
    for (int i=0; i<min(s1.length(),s2.length()); i++) {
      if (s1[i] != s2[i]) {
        map[s1[i]-'A'][s2[i]-'A'] = true;
        degree[s1[i]-'A']=degree[s2[i]-'A'] = true;
        break;
      }
    }
    s1=s2;
  }

  for (int k=0; k<26; k++)
    for (int i=0; i<26; i++)
      for (int j=0; j<26; j++)
        map[i][j] |= map[i][k] && map[k][j];

  int num = 0;
  for (int i=0; i<26; i++) {
    if (degree[i]) {
      int count = 0;
      for (int j=0; j<26; j++)
        if (map[i][j])
          count++;
      result[count] = 'A' + i;
      num++;
    }
  }

  for (int i=num-1; i>=0; i--)
    cout<<result[i];
  cout<<endl;
  return 0;
}
