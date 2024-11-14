/*  ----- List Shift -----
    Example: list = [<H>,A,B,C,D,E] (Given <H> is a header)
    ----- Algorithm (Shift Left) -----
    k = 7  | [<H>,C,D,E,A,B] | Shift Left 2 times
    1.) Initial List links
    - mHeader->next is A | (A)->prev is mHeader
    - mHeader->prev is E | (E)->next is mHeader
    - (C)->prev is B
    2.) Iterate forward 2 times (7 mod 5 = 2)
    3.) Update List links
    - mHeader->next is C | (C)->prev is mHeader
    - mHeader->prev is B | (B)->next is mHeader
    - (A)->prev is E     | (E)->next is A

    ----- Algorithm (Shift Right) -----
    k = -7 | [<H>,D,E,A,B,C] | Shift Right 2 times
    1.) Initial List links
    - mHeader->next is A | (A)->prev is mHeader
    - mHeader->prev is E | (E)->next is mHeader
    - (D)->prev is C
    2.) Iterate forward 3 times (-7 mod 5 = -2 | 5 - 2 = 3)
    3.) Update List links
    - (A)->prev is E     | (E)->next is A
    - mHeader->next is D | (D)->prev is mHeader
    - mHeader->prev is C | (C)->next is mHeader
*/

void shift(int k) {
    // If k is 0 or mSize is 0 or 1, do nothing
    if(k == 0 || mSize <= 1) return;
    
    // Get inital start node
    auto node = mHeader->next;

    // Calculate how many times to iterate
    // NOTE: size_t has a problem when modulo with negative number (need to use n or (int)mSize)
    int n = mSize;
    int jump = ((k % n) + n) % n;
    // Iterate forward to get a new start node
    while(jump--) { node = node->next; }
    
    // Update list links
    // Set a new state for old start and end node
    (mHeader->next)->prev = mHeader->prev;
    (mHeader->prev)->next = mHeader->next;
    // Set a new state for mHeader
    mHeader->next = node;
    mHeader->prev = node->prev;
    // Set a new state for new start and end node
    (node->prev)->next = mHeader;
    node->prev = mHeader;
}
