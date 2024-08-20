#include<iostream>
#include<map>
#include<vector>
#include<iomanip>
using namespace std;
map<string, vector<int>> subject2score, prof2score;
int main()
{
    // Set decimal precision to 2 decimal places
    cout << std::fixed << std::setprecision(2);

    // Input data in a map
    int N;
    cin >> N;
    while(N--)
    {
        string subject, prof;
        int score;
        cin >> subject >> prof >> score;

        // Input data to subject map
        if(subject2score.find(subject) == subject2score.end())
        {
            subject2score[subject] = {score, 1};
        }
        else
        {
            subject2score[subject][0] += score;
            subject2score[subject][1] += 1;
        }

        // Input data to professor map
        if(prof2score.find(prof) == prof2score.end())
        {
            prof2score[prof] = {score, 1};
        }
        else
        {
            prof2score[prof][0] += score;
            prof2score[prof][1] += 1;
        }
    }
    
    // Output
    for(map<string, vector<int>>::iterator it = subject2score.begin(); it != subject2score.end(); it++)
    {
        string subject = it->first;
        float score = (it->second[0] + 0.0)/it->second[1];
        cout << subject << " " << score << endl;
    }
    for(map<string, vector<int>>::iterator it = prof2score.begin(); it != prof2score.end(); it++)
    {
        string prof = it->first;
        float score = (it->second[0] + 0.0)/it->second[1];
        cout << prof << " " << score << endl;
    }
    return 0;
}