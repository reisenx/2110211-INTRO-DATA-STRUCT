#include<iostream>
#include<map>
using namespace std;
int N,maxCount = 0;
string maxWord = "";
map<string, int> wordCount;
int main()
{
    // Make std::cin and std:: cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input words
    cin >> N;
    while(N--)
    {
        string word;
        cin >> word;
        // If 'word' is not in wordCount map yet, initialize count to 1
        // If 'word' is already exist in wordCount map, increase count by 1
        if(wordCount.find(word) == wordCount.end()) wordCount[word] = 1;
        else wordCount[word]++;

        // Find maxCount and maxWord
        if(wordCount[word] > maxCount)
        {
            maxWord = word;
            maxCount = wordCount[word];
        }
        else if(wordCount[word] == maxCount && word > maxWord) maxWord = word;
    }

    // Output
    cout << maxWord << " " << maxCount;
    return 0;
}