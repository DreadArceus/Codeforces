#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int maximiseScore(string s)
{
  int score = 0;
  // Assuming non-decreasing order of 1-blocks:
  {
  // int locBlock = 0;
  // bool block = 0;
  // bool turn = 1;
  // for(char c : s)
  // {
  //   if(c == '1')
  //   {
  //     if(!block)
  //     {
  //       block = 1;
  //     }
  //     locBlock++;
  //   }
  //   else if(block)
  //   {
  //     block = 0;
  //     if(turn)
  //     {
  //       score += locBlock;
  //       turn = 0;
  //     }
  //     else
  //     {
  //       turn = 1;
  //     }
  //     locBlock = 0;
  //   }
  // }
  // if(block && turn)
  // {
  //   score += locBlock;
  }
  vector<int> blocks;
  int locBlock = 0;
  for(char c : s)
  {
    if(c == '1')
    {
      locBlock++;
    }
    else if(locBlock)
    {
      blocks.push_back(locBlock);
      locBlock = 0;
    }
  }
  if(locBlock)
  {
    blocks.push_back(locBlock);
    locBlock = 0;
  }
  sort(blocks.begin(), blocks.end(), greater<int>());
  bool turn = 1;
  for(auto it : blocks)
  {
    if(turn)
    {
      score += it;
      turn = 0;
    }
    else
    {
      turn = 1;
    }
  }
  return score;
}
int main()
{
  int t = 0;
  cin >> t;
  while(t--)
  {
    string s = "";
    cin >> s;
    int ans = maximiseScore(s);
    cout << ans << "\n";
  }
}
