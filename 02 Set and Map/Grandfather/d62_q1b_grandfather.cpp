#include<iostream>
#include<map>
using namespace std;
int N,M;
map<string, string> SonFather;

/* GrandfatherCheck() Function
Returns true, if id1 and id2 both have grandfather
Returns false, if id1 or id2 don't have grandfather
*/
bool GrandfatherCheck(string id1, string id2)
{
    // Same ID (return false)
    if(id1 == id2) return false;

    // Check if, id1 and id2 have father
    bool c1 = (SonFather.find(id1) != SonFather.end());
    bool c2 = (SonFather.find(id2) != SonFather.end());
    // Both has father
    if(c1 && c2)
    {
        // Check if, id1 and id2 have grandfather
        bool c3 = (SonFather.find(SonFather[id1]) != SonFather.end());
        bool c4 = (SonFather.find(SonFather[id2]) != SonFather.end());
        // Both has grandfather
        if(c3 && c4) return true;
    }
    // Some of them don't have father or some of them don't have grandfather
    return false;
}

/* SameGrandfather() Function
Returns true, if id1 and id2 has same grandfather
Returns false, if id1 and id2 has different grandfather
*/
bool SameGrandfather(string id1, string id2)
{
    // Both have grandfather
    if(GrandfatherCheck(id1,id2)) return SonFather[SonFather[id1]] == SonFather[SonFather[id2]];
    // Some of them don't have grandfather
    return false;
}

int main()
{
    // Make std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input son-father relationship
    cin >> N >> M;
    while(N--)
    {
        string son,father;
        cin >> father >> son;
        SonFather[son] = father;
    }

    // Output
    while(M--)
    {
        string id1, id2;
        cin >> id1 >> id2;
        if(SameGrandfather(id1,id2)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}