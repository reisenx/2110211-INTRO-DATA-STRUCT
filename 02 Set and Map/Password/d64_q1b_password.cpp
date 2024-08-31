#include<iostream>
#include<set>
#include<map>
using namespace std;
int N, M, L, k[55];
set<string> database;
string alpha = "abcdefghijklmnopqrstuvwxyz";
map<char, int> char2num;
int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    for(int i = 0; i < 26; i++) { char2num[alpha[i]] = i; }
    cin >> N >> M >> L;
    for(int i = 0; i < L; i++) {cin >> k[i];}
    for(int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        database.insert(temp);
    }
    for(int i = 0; i < M; i++)
    {
        string password;
        cin >> password;
        for(int j = 0; j < L; j++)
        {
            password[j] = alpha[ (char2num[password[j]] + k[j])%26 ];
        }
        if(database.find(password) != database.end()) cout << "Match\n";
        else cout << "Unknown\n";
    }
}