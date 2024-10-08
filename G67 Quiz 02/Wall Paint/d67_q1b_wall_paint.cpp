#include<bits/stdc++.h>
using namespace std;
int N, M, maxThick = 0;
set<pair<int,int>> paintInterval;
vector<int> thickness = {0}, startPos, endPos;
int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input wall length (N) and times painting wall (M)
    cin >> N >> M;
    // Input position of painting on a wall
    startPos.resize(M);
    endPos.resize(M);
    for(int i = 0; i < 2*M; i++)
    {
        int pos,c,d;
        cin >> pos >> c >> d;
        // Start position
        if(d == 0) { startPos[c-1] = pos - 1; }
        // End position
        if(d == 1) { endPos[c-1] = pos - 1; }
    }

    /* Painting a wall
    For each painting range (a,b) do this
    Given the second integer in a pair: 0 is start and 1 is end
    1.) Find iterator to insert by it1 = lower_bound({a,0}) and it2 = lower_bound({b,1})
    2.) If (a,b) can insert to a set paintInterval, it must meet these criteria
    - it1 and it2 must be the same
    - it1->first is not a or it1->first is not b
    3.) If meets all criteria, insert (a,0) and (b,1) to a set

    Example: startPos = [0,8,2,1,2,3,4] | endPos = [7,9,7,8,6,5,4]
    Insert range (0,7) | paintInterval = {(0,0), (7,1)}
    Insert range (8,9) | paintInterval = {(0,0), (7,1), (8,0), (9,1)}
    Insert range (2,7) | Insertion failed because (7,1) is already exist
    Insert range (1,8) | Insertion failed because *it1 is (0,0) and *it2 is (9,1)
    Insert range (2,6) | paintInterval = {(0,0), (2,0), (6,1), (7,1), (8,0), (9,1)}
    Insert range (3,5) | paintInterval = {(0,0), (2,0), (3,0), (5,1) (6,1), (7,1), (8,0), (9,1)}
    Insert range (4,4) | paintInterval = {(0,0), (2,0), (3,0), (4,0), (4,1), (5,1) (6,1), (7,1), (8,0), (9,1)} */
    paintInterval.insert(make_pair(startPos[0], 0));
    paintInterval.insert(make_pair(endPos[0], 1));
    for(int i = 1; i < M; i++)
    {
        auto it1 = paintInterval.lower_bound(make_pair(startPos[i], 0));
        auto it2 = paintInterval.lower_bound(make_pair(endPos[i], 1));
        if(it1 != it2) continue;
        if(it1->first == startPos[i]) continue;
        if(it1->first == endPos[i]) continue;
        paintInterval.insert(make_pair(startPos[i], 0));
        paintInterval.insert(make_pair(endPos[i], 1));
    }

    /* Find thickness of a wall
    - For each start point, add thickness by 1
    - For each end point, minus thickness by 1
    - thickness initial value is [0]
    Example: paintInterval = {(0,0), (2,0), (3,0), (4,0), (4,1), (5,1) (6,1), (7,1), (8,0), (9,1)}
    > thickness = [0,1,2,3,4,3,2,1,0,1,0] and maxThick = 4 */
    for(auto &[pos, type] : paintInterval)
    {
        if(type == 0) thickness.push_back(thickness.back() + 1);
        if(type == 1) thickness.push_back(thickness.back() - 1);
        if(thickness.back() > maxThick) maxThick = thickness.back();
    }

    // Output
    cout << maxThick;
}