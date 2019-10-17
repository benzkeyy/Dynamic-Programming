// Minimum path grid..
#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int dp[3][3];
int matrix[3][3] = { {1, 3, 1},{1, 5, 1},{4 ,2, 1} };
int main() 
{ 
    dp[0][0] = matrix[0][0];
    for (int i = 1; i < 3; i++) // Filling first row..
    {
      dp[0][i] = matrix[0][i] + dp[0][i - 1];
    }
    for (int i = 1; i < 3; i++) // First column..
    {
        dp[i][0] = matrix[i][0] + dp[i - 1][0];
    }
    for(int i = 1; i < 3; i++)
    {
      for(int j = 1; j < 3; j++)
      {
        dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + matrix[i][j];
      }
    }
    for(auto& a : dp)
    {
      for(auto& b : a)
      {
        cout << b << " ";
      }
    cout << endl;
    }
    return 0; 
} 
