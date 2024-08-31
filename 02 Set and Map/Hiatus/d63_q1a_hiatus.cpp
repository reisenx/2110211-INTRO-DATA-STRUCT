#include<iostream>
#include<map>
#include<set>
using namespace std;
map<int, set<int>> Publish;
set<int> Years;

bool IsBeforeAllPublish(int year, int month)
{
    int FYear = *(Years.begin());
    int FMonth = *(Publish[FYear].begin());
    if(year < FYear) return true;
    else if(year == FYear && month < FMonth) return true;
    return false;
}

bool IsAfterAllPublish(int year, int month)
{
    int LYear = *(Years.rbegin());
    int LMonth = *(Publish[LYear].rbegin());
    if(year > LYear) return true;
    else if(year == LYear && month > LMonth) return true;
    return false;
}

bool IsPublish(int year, int month)
{
    auto ITRYear = Years.lower_bound(year);
    if(*(ITRYear) > year || ITRYear == Years.end()) return false;
    auto ITRMonth = Publish[year].lower_bound(month);
    if(*(ITRMonth) > month || ITRMonth == Publish[year].end()) return false;
    return true;
}

void LatestPublish(int year, int month)
{
    int PYear, PMonth;
    set<int>::iterator ITRYear, ITRMonth;

    ITRYear = Years.lower_bound(year);
    if(*(ITRYear) > year) ITRYear--;
    PYear = *(ITRYear);

    if(PYear < year) PMonth = *(Publish[PYear].rbegin());
    else if(PYear == year)
    {
        if(month > *(Publish[year].rbegin())) PMonth = *(Publish[year].rbegin());
        else if(month < *(Publish[year].begin()))
        {
            ITRYear--;
            PYear = *(ITRYear);
            PMonth = *(Publish[PYear].rbegin());
        }
        else
        {
            ITRMonth = Publish[year].lower_bound(month);
            ITRMonth--;
            PMonth = *(ITRMonth);
        }
    }
    cout << PYear << " " << PMonth << " ";
}

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m;
    cin >> n >> m;
    while(n--)
    {
        int year, month;
        cin >> year >> month;
        if(Years.find(year) == Years.end())
        {
            Years.insert(year);
            Publish[year] = {month};
        }
        else Publish[year].insert(month);
    }
    while(m--)
    {
        int year, month;
        cin >> year >> month;
        if(IsBeforeAllPublish(year, month)) cout << "-1 -1 ";
        else if(IsPublish(year, month)) cout << "0 0 ";
        else if(IsAfterAllPublish(year, month))
        {
            int LYear = *(Years.rbegin());
            int LMonth = *(Publish[LYear].rbegin());
            cout << LYear << " " << LMonth << " ";
        }
        else LatestPublish(year, month);
    }
}