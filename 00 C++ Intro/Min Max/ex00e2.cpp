#include<iostream>
using namespace std;
int R, N, M, r1, c1, r2, c2, mx;
int mat[105][105];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M >> R;
	for(int row=1; row<=N; row++)
	{
		for(int col=1; col<=M; col++)
		{
			cin >> mat[row][col];
		}
	}
	for(int i=0; i<R; i++)
	{
		cin >> r1 >> c1 >> r2 >> c2;
		if(r1 > r2 || c1 > c2)
		{
			cout << "INVALID" << endl;
		}
		else if ((r1 < 1 && r2 < 1) || (r1 > N && r2 > N))
		{
			cout << "OUTSIDE" << endl;
		}
		else if((c1 < 1 && c2 < 1) || (c1 > M && c2 > M))
		{
			cout << "OUTSIDE" << endl;
		}
		else
		{
			r1 = max(1, r1);
			c1 = max(1, c1);
			r2 = min(N, r2);
			c2 = min(M, c2);
			mx = mat[r1][c1];
			for(int row = r1; row <= r2; row++)
			{
				for(int col = c1; col <= c2; col++)
				{
					if(mat[row][col] > mx)
					{
						mx = mat[row][col];
					}
				}
			}
			cout << mx << endl;
		}
	}
	return 0;
}
