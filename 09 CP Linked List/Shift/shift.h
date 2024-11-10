/*  ----- List Shift -----
    Example: list = [A,B,C,D,E]
    k = 2  | [C,D,E,A,B] | Shift Left 2 times
    k = -2 | [D,E,A,B,C] | Shift Right 2 times
    ----- Algorithm -----
    1.) Get first element by begin()
    2.) If k > 0, iterate forward k times (or k mod mSize times)
        If k < 0, iterate backward k times (or k mod mSize times)
    3.) Set that element to the first element by changing mHeader
*/

void shift(int k) {
    // If k is 0 or mSize is 0 or 1, do nothing
    if(k == 0 || mSize <= 1) return;
    auto a = begin();
    
    // Iterate forward k mod mSize times
    if(k > 0)
    {
        for(int i = 0; i < k % mSize; i++)
    }


}
