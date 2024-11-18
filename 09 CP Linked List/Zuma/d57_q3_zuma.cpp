#include<iostream>
#include<list>
using namespace std;
int N,K,V;
list<int> beads;

/* ----------- Explode Function -----------
    Algorithm
    1.) Get iterator to insert from pos
    2.) Iterate backward until get the start point
    3.) Iterate forward until get the end point (and count the beads)
    4.) If the count < 3, return false
    5.) If the count >= 3, erase them and return true

    Example: [1,1,4,4,4,4,1,1] | pos = begin() + 3
    [1,1,4,<4>,4,4,4,1,1] | Shoot the bead
    [1,1,<4>,4,4,4,4,1,1] | Iterate backwards and get start = begin()+2 and set beadsCount = 0
    [1,1,4,4,4,4,4,<1>,1] | Iterate forward and get stop = begin()+7 and got beadsCount = 5
    [1,1,<4,4,4,4,4>,1,1] | Get range to erase as [begin()+2, begin()+7)
    [1,<1>,1,1]           | Erase and the function returns {true, begin()+1}
    NOTE: erase() return an iterator pointing at the element that follows the last removed element
*/

pair<bool, list<int>::iterator> explode(list<int> &beads, list<int>::iterator pos, int &bead)
{
    // If the list is less than 3, it is impossible to explode
    if(beads.size() < 3) return {false, beads.end()};
    
    // Get start and end point and beads count
    int beadsCount = 0;
    list<int>::iterator start = pos;
    while(start != beads.end() && *(prev(start)) == bead) { start--; }
    list<int>::iterator stop = start;
    while(stop != beads.end() && *stop == bead) { stop++; beadsCount++; }
    
    // If the beads count is less than 3, it is impossible to explode
    if(beadsCount < 3) return {false, beads.end()};
    // Otherwise, explode the beads
    beads.erase(start,stop);
    return {true, prev(stop)};
}

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input beads
    cin >> N >> K >> V;
    while (N--)
    {
        int bead;
        cin >> bead;
        beads.push_back(bead);
    }
    // Shoot and explode the beads
    list<int>::iterator it = beads.insert(next(beads.begin(),K),V);
    pair<bool, list<int>::iterator> result = explode(beads, it, V);
    bool isExplode = result.first;
    it = result.second;
    // If the beads collide, keep explode the beads
    while(isExplode && it != beads.end())
    { 
        result = explode(beads, it, *it);
        isExplode = result.first;
        it = result.second;
    }
    
    // Output
    for(int &bead : beads) { cout << bead << " "; }
    return 0;
}