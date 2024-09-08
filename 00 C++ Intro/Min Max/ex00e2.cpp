#include<iostream>
using namespace std;
int R, N, M, r1, c1, r2, c2, MAX;
int mat[105][105];

int main()
{
	// Make std::cin and std::cout faster
	ios_base::sync_with_stdio(false); cin.tie(0);

	// Input 2D matrix
	cin >> N >> M >> R;
	for(int row=1; row<=N; row++)
	{
		for(int col=1; col<=M; col++)
		{
			cin >> mat[row][col];
		}
	}

	// Find maximum value in (r1,c1) to (r2,c2) region
	for(int i=0; i<R; i++)
	{
		// Input point (r1,c1) and (r2,c2)
		cin >> r1 >> c1 >> r2 >> c2;
		// Check Invalid cases
		if(r1 > r2 || c1 > c2) cout << "INVALID" << endl;
		// Check Outside cases (r1 <= r2 and c1 <= c2 now)
		else if (r2 < 1 || r1 > N || c2 < 1 || c1 > M) cout << "OUTSIDE" << endl;
		// Valid region cases
		else
		{
			// Resize the bound to valid region
			// (r1,c1) or (r2,c1) may be outside of the matrix region
			r1 = max(1, r1);
			c1 = max(1, c1);
			r2 = min(N, r2);
			c2 = min(M, c2);
			// Find maximum value
			MAX = mat[r1][c1];
			for(int row = r1; row <= r2; row++)
			{
				for(int col = c1; col <= c2; col++)
				{
					if(mat[row][col] > MAX) MAX = mat[row][col];
				}
			}
			// Output
			cout << MAX << endl;
		}
	}
	return 0;
}
