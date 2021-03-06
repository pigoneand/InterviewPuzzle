/*
 There is a matrix A,
 1 2 3 
 4 5 6
 
 And a lot of queries, x, y, r, c:
 return the sum of the elements in the submatrix: [x, y, r, c]
 
 Hint:
 init(): initialize the matrix and calculate the sum of the submatrixes [0, 0, i, j]
 
 query: return the sum of the submatrix
 
 */


//n rows, m cols
void init(int **a, int n, int m)
{
  for (int i = 1; i < n; i ++) {
    a[i][0] = a[i - 1][0] + a[i][0];
    
    for (int j = 1; j < m; j ++) {
      a[i][j] = a[i - 1][j] + a[i][j - 1] + a[i][j] - a[i-1][j-1]; 
    }
  }
}

int query(int **a, int x, int y, int r, int c)
{
  if (x == 0 && y == 0) {
    return a[r - 1][c - 1];
  }
  
  if (x == 0) {
    return a[x + r - 1][y + c - 1] - a[x + r - 1][y - 1];
  }
  
  if (y == 0) {
    return a[x + r - 1][y + c - 1] - a[x - 1][y + c - 1];
  }
  
  return a[x + r - 1][y + c - 1] + a[x - 1][y - 1] - a[x + c - 1][y - 1] - a[x - 1][y + c - 1];
}