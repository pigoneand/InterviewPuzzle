#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/// 8 Quene Puzzle
const int N = 8;
int columnUsed, diagonalUsed1, diagonalUsed2;
int columnPosiForRow[N];
int ans;

void output()
{
  ans++;
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
      if (columnPosiForRow[i] == j)
        cout << "*";
      else
        cout << "-";
    cout << endl;
  }
  cout << endl;
}

void search(int curRow)
{
  if (curRow == N)
    return output();
  
  for (int c = 0; c < N; ++c)
  {
    if (!(columnUsed & (1 << c)) && !(diagonalUsed1 & (1 << (c + curRow))) && !(diagonalUsed2 & (1 << (c - curRow + N - 1))))
    {
      columnUsed |= 1 << c;
      diagonalUsed1 |= 1 << (c + curRow);
      diagonalUsed2 |= 1 << (c - curRow + N - 1);
      search(curRow + 1);
      columnUsed &= (~(1 << c));
      diagonalUsed1 &= (~(1 << (c + curRow)));
      diagonalUsed2 &= (~(1 << (c - curRow + N - 1)));
    }
  }
}

int main()
{
  ans = 0;
  search(0);
  columnUsed = diagonalUsed1 = diagonalUsed2 = 0;
  cout << "Total = " << ans << endl;
}