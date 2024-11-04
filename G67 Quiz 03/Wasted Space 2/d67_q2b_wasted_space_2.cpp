#include<iostream>
using namespace std;
long long int t, mSize = 0, mCap = 1;

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    // Input
    cin >> t;
    while(t--)
    {
        // Input of each operation
        char command;
        long long int n;
        cin >> command >> n;
        // push_back()
        // Add n element (mSize + n)
        if(command == 'p') { mSize += n; }
        // pop_back()
        // Remove n element (mSize - n)
        if(command == 'o') { mSize -= n; }
        // resize()
        // Example: vector<int> v = {5}
        // v.resize(4)    --> v = {5,0,0,0} (default value is added)
        // v.push_back(1) --> v = {5,0,0,0,1}
        if(command == 'r') { mCap = max(n,mCap); mSize = n; }
        // expand() and ensureCapacity()
        while(mSize > mCap) { mCap *= 2; }
    }
    // Output wasted space
    cout << mCap - mSize;
    return 0;
}

// ---------- CP::vector<T> expand() function ---------
// void expand(size_t capacity) {
//     T *arr = new T[capacity]();
//     for(size_t i = 0;i < mSize;i++) { arr[i] = mData[i]; }
//     delete[] mData;
//     mData = arr;
//     mCap = capacity;
// }
// void ensureCapacity(size_t capacity) {
//     if(capacity > mCap) {
//         size_t s = (capacity > 2 * mCap) ? capacity : 2 * mCap;
//         expand(s);
//     }
// }
// ---------- CP::vector<T> push_back() function ---------
// iterator insert(iterator it, const T& element) {
//     size_t pos = it - begin();
//     ensureCapacity(mSize + 1);
//     for(size_t i = mSize;i > pos;i--) { mData[i] = mData[i-1]; }
//     mData[pos] = element;
//     mSize++;
//     return begin()+pos;
// }
// void push_back(const T& element) { insert(end(),element); }
// ---------- CP::vector<T> pop_back() function ---------
// void pop_back() { mSize--; }
// ---------- CP::vector<T> resize() function ---------
// void resize(size_t n) {
//     if(n > mCap) expand(n);
//     if(n > mSize)
//     {
//         T init = T();
//         for (size_t i = mSize;i < n;i++) { mData[i] = init; }
//         mSize = n;
//     }
// }