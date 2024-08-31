#include<iostream>
using namespace std;
int N,M,K,A[1005][1005], SUM[1005][1005];
int main()
{
    cin >> N >> M >> K;
    for(int row = 0; row < N; row++)
    {
        for(int col = 0; col < M; col++)
        {
            cin >> A[row][col];
            if(row == 0 && col == 0)
            {
                SUM[0][0] = A[0][0];
            }
            else if(row == 0)
            {
                SUM[0][col] = SUM[0][col-1] + A[0][col];
            }
            else if(col == 0)
            {
                SUM[row][0] = SUM[row-1][0] + A[row][0];
            }
            else
            {
                SUM[row][col] = SUM[row-1][col] + SUM[row][col-1] - SUM[row-1][col-1] + A[row][col];
            }
        }
    }
    
    for(int i = 0; i < K; i++)
    {
        int r1,c1,r2,c2;
        cin >> r1 >> c1 >> r2 >> c2;
        if(r1 == 0 && c1 == 0)
        {
            cout << SUM[r2][c2] << endl;
        }
        else if(r1 == 0)
        {
            cout << SUM[r2][c2] - SUM[r2][c1-1] << endl;
        }
        else if(c1 == 0)
        {
            cout << SUM[r2][c2] - SUM[r1-1][c2] << endl;
        }
        else
        {
            cout << SUM[r2][c2] - SUM[r1-1][c2] - SUM[r2][c1-1] + SUM[r1-1][c1-1] << endl;
        }
    }
}