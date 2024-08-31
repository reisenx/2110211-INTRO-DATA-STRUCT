#include<iostream>
#include<map>
#include<set>
using namespace std;
int Rounds = 0, n,m;
bool Lose = false;
set<int> Cards;
map<int, int> CardsCount;
bool LoseBattle(int Enemy) { return Cards.upper_bound(Enemy) == Cards.end(); }
void CardBattle(int Enemy)
{
    int Player = *(Cards.upper_bound(Enemy));
    CardsCount[Player] -= 1;
    if(CardsCount[Player] == 0) Cards.erase(Player);
}

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    cin >> n >> m;
    while(n--)
    {
        int temp;
        cin >> temp;
        if(Cards.find(temp) == Cards.end())
        {
            Cards.insert(temp);
            CardsCount[temp] = 1;
        }
        else CardsCount[temp] += 1;
    }
    while(m--)
    {
        Rounds += 1;
        int num;
        cin >> num;
        while(num--)
        {
            int enemy;
            cin >> enemy;
            if(LoseBattle(enemy)) { Lose = true; break; }
            else { CardBattle(enemy); }
        }
        if(Lose) break;
    }
    if(!Lose) Rounds += 1;
    cout << Rounds;
}