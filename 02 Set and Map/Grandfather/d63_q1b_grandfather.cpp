#include<iostream>
#include<map>
#include<set>
using namespace std;
int N,M;
map<long long int, long long int> SonFather;
set<long long int> HaveFather;

bool FatherCheck(long long int id1, long long int id2)
{
    if(id1 == id2) return false;
    bool c1 = (HaveFather.find(id1) != HaveFather.end());
    bool c2 = (HaveFather.find(id2) != HaveFather.end());
    if(!c1 || !c2) return false;
    else
    {
        bool c3 = (HaveFather.find(SonFather[id1]) != HaveFather.end());
        bool c4 = (HaveFather.find(SonFather[id2]) != HaveFather.end());
        if(!c3 || !c4) return false;
    }
    return true;
}

bool GrandFatherCheck(long long int id1, long long int id2)
{
    if(FatherCheck(id1, id2)) return SonFather[SonFather[id1]] == SonFather[SonFather[id2]];
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M;
    while(N--)
    {
        long long int father, son;
        cin >> father >> son;
        if(father != son)
        {
            HaveFather.insert(son);
            SonFather[son] = father;
        }
    }
    while(M--)
    {
        long long int id1, id2;
        cin >> id1 >> id2;
        if(GrandFatherCheck(id1, id2)) cout << "YES\n";
        else cout << "NO\n";
    }
}