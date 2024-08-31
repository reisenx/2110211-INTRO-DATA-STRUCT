#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m;
    std::vector<int> start, end;
    
    cin >> n >> m;
    while(n--)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        start.push_back(temp1);
        end.push_back(temp2);
    }
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    while(m--)
    {
        int temp;
        cin >> temp;
        int StartIND = lower_bound(start.begin(), start.end(), temp) - start.begin();
        int EndIND = lower_bound(end.begin(), end.end(), temp) - end.begin();
        
        if(EndIND == end.size()) cout << 0 << " ";
        else
        {
            if(StartIND == EndIND)
            {
                if(temp >= start[StartIND] && temp <= end[EndIND]) cout << 1 << " ";
                else cout << 0 << " ";
            }
            else
            {
                if((StartIND - 1) == EndIND)
                {
                    if(temp >= start[StartIND - 1] && temp <= end[EndIND]) cout << 1 << " ";
                    else cout << 0 << " ";
                }
                else cout << 0 << " ";
            }
        }
    }
}