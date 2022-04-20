#include <cassert>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Gap
{
  Gap(int x, int y, int l, bool acr) : row(x), col(y), len(l), across(acr) {}
  
  int row;
  int col;
  int len;
  bool across;
};

bool operator==(const Gap& lhs, const Gap& rhs)
{
  return ((lhs.row == rhs.row) &&
          (lhs.col == rhs.col) && 
          (lhs.len == rhs.len) && 
          (lhs.across == rhs.across));
}

ostream& operator<<(ostream& os, const Gap& g)
{
  return os << "{" << g.row << ", " << g.col << ", " << g.len << ", " << g.across << "}";
}

pair<vector<vector<char>>, bool> solve(vector<vector<char>> M, vector<Gap> g, vector<string> w)
{
  if (w.empty())
    return make_pair(M, true);
  
  // Over all gaps
  for (int i = 0; i < g.size(); ++i)
  {
    // Try every remaining word
    for (int j = 0; j < w.size(); ++j)
    {
      Gap gg = g[i];
      if (gg.len != w[j].size())
        continue;
      
      // Make a copy of M
      vector<vector<char>> MM = M;
      
      // Every character of the gap
      if (gg.across)
      {
        bool success = true;
        for (int k = 0; k < gg.len; ++k)
        {
          if (MM[gg.row][gg.col + k] == '-')
            MM[gg.row][gg.col + k] = w[j][k];
          
          else if (MM[gg.row][gg.col + k] != w[j][k])
            success = false;
        }
        
        if (success)
        {
          vector<Gap> gg = g;
          gg.erase(gg.begin() + i);
          vector<string> ww = w;
          ww.erase(ww.begin() + j);
          pair<vector<vector<char>>, bool> x = solve(MM, gg, ww);
          if (x.second == true)
            return x;
        }
      }
      else
      {
        bool success = true;
        for (int k = 0; k < gg.len; ++k)
        {
          if (MM[gg.row + k][gg.col] == '-')
            MM[gg.row + k][gg.col] = w[j][k];
          
          else if (MM[gg.row + k][gg.col] != w[j][k])
            success = false;
        }
        
        if (success)
        {
          vector<Gap> gg = g;
          gg.erase(gg.begin() + i);
          vector<string> ww = w;
          ww.erase(ww.begin() + j);
          pair<vector<vector<char>>, bool> x = solve(MM, gg, ww);
          if (x.second == true)
            return x;
        }
      }
      
    }
  }
  
  return make_pair(M, false);
}

vector<Gap> find_gaps(const vector<vector<char>>& M)
{
  vector<Gap> gaps;
  
  // row wise iteration
  for (int row = 0; row < M.size(); ++row)
  {
    int start = -1;
    int stop = -1;
    if (M[row][0] == '-')
    {
      start = 0; stop = 0;
    }
    
    int col = 1;
    for (col = 1; col < M[row].size(); ++col)
    {
      if ((M[row][col] != M[row][col - 1]) && (start == -1))
      {
        start = col;
      }
      else if (M[row][col] != M[row][col - 1])
      {
        stop = col - 1;
        if (stop > start)
        {
          gaps.push_back(Gap(row, start, stop - start + 1, true));
        }
        
        start = -1;
        stop = -1;
      }
    }
    
    stop = col - 1;
    if ((M[row][stop] == '-') && (stop > start))
    {
      gaps.push_back(Gap(row, start, stop - start + 1, true));
    }
  }
  
  // column wise iteration
  for (int col = 0; col < M[0].size(); ++col)
  {
    int start = -1;
    int stop = -1;
    if (M[0][col] == '-')
    {
      start = 0; stop = 0;
    } 
    
    int row = 1;
    for (row = 1; row < M.size(); ++row)
    {
      if ((M[row][col] != M[row - 1][col]) && (start == -1))
      {
        start = row;
      }
      else if (M[row][col] != M[row - 1][col])
      {
        stop = row - 1;
        if (stop > start)
        {
          gaps.push_back(Gap(start, col, stop - start + 1, false));
        }
        
        start = -1;
        stop = -1;
      }
    }
    
    stop = row - 1;
    if ((start > -1) && (M[stop][col] == '-') && (stop > start))
    {
      gaps.push_back(Gap(start, col, stop - start + 1, false));
    }
    
  }
  
  return gaps;
}

vector<string> vectorize(const string& words)
{
  int start = 0; 
  int stop = 0;
  vector<string> out;
  
  for (int stop = 0; stop < words.size(); ++stop)
  {
    if (words[stop] == ';')
    {
      out.push_back(words.substr(start, stop - start));
      start = stop + 1;
      stop = stop + 2;
    }
  }
  
  // Push the last word
  out.push_back(words.substr(start, stop - start));
  
  return out;
}

int main() 
{
  {
    // Test vectorize words
    string x = "LONDON;DELHI;ICELAND;ANKARA";
    vector<string> w = vectorize(x);
    assert(w.size() == 4);
    assert(w[0] == "LONDON");
    assert(w[1] == "DELHI");
    assert(w[2] == "ICELAND");
    assert(w[3] == "ANKARA");
  }
  
  {
    // Test find_gaps
    vector<vector<char>> M = 
      { //0    1    2    3    4    5
        {'+', '-', '+', '-', '-', '+'}, // 0,3,2,true; 0,1,3,false; 0,3,3,false
        {'-', '-', '-', '-', '+', '+'}, // 1,0,4,true
        {'+', '-', '+', '-', '+', '+'}, // 
        {'+', '+', '+', '+', '+', '+'}, //
        {'+', '-', '+', '-', '-', '-'}, // 4,3,3,true; 4,1,2,false
        {'+', '-', '+', '+', '+', '+'}
      };
    
    vector<Gap> gaps = find_gaps(M);
    assert(gaps.size() == 6);
    assert(gaps[0] == Gap(0, 3, 2, true));
    assert(gaps[1] == Gap(1, 0, 4, true));
    assert(gaps[2] == Gap(4, 3, 3, true));
    assert(gaps[3] == Gap(0, 1, 3, false));
    assert(gaps[4] == Gap(4, 1, 2, false));
    assert(gaps[5] == Gap(0, 3, 3, false));
  }
  
  vector<vector<char>> M(10, vector<char>(10, ' '));
  for (int i = 0; i < 10; ++i)
    for (int j = 0; j < 10; ++j)
      cin >> M[i][j];  
  
  vector<Gap> gaps = find_gaps(M);

  string words;
  cin >> words;
  vector<string> w = vectorize(words);

  pair<vector<vector<char>>, bool> x = solve(M, gaps, w);
  if (x.second == true)
  {
    vector<vector<char>>& m = x.first;
    for (auto v : m)
    {
      for (auto c : v)
        cout << c;
      cout << endl;
    }
  }
}
