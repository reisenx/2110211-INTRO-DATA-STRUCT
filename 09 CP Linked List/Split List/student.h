/*  ---------- Split List ----------
    x = [1,7,9,10,2,6,3] | Size = 7
    - Insert first 4 numbers to list1 (Size = 7 - (7/2) = 4)
    - Insert last 3 numbers to list2  (Size = 7/2 = 3)
    - mSize = 0 | list1.mSize += 4 | list2.mSize += 3
    ---------- List1 Links ----------
    list1 = [98,99] --> list1 = [98,99,<1,7,9,10>]
    Before
    - mHeader->next = 1          | it1 = 10
    - list1.mHeader->next = 98   | list1.mHeader->prev = 99
    - (10)->next = 2             | (99)->next = list1.mHeader | (1)->prev = mHeader
    After
    - mHeader->next = mHeader    | it1 = 10
    - list1.mHeader->next = 98   | list1.mHeader->prev = 10
    - (10)->next = list1.mHeader | (99)->next = 1 | (1)->prev = 99
    ---------- List2 Links ----------
    list2 = [97,98,99] --> list2 = [97,98,99,<2,6,3>]
    Before
    - it2 = 2                    | mHeader->prev = 3
    - list2.mHeader->next = 97   | list2.mHeader->prev = 99
    - (3)->next = mHeader        | (99)->next = list2.mHeader | (2)->prev = 10
    After
    - it2 = 2                    | mHeader->prev = mHeader
    - list2.mHeader->next = 97   | list2.mHeader->prev = 3
    - (3)->next = list2.mHeader  | (99)->next = 2 | (2)->prev = 99
*/

void splitList(list<T>& list1, list<T>& list2) {
    // If this list is empty, do nothing
    if(empty()) return;
    // Iterate forward mSize - (mSize/2) times
    auto it1 = begin(), it2 = begin();
    for(int i = 0; i < mSize - (mSize/2); i++) { it1++; it2++; }
    // Update list1 links
    it1--;
    ((list1.mHeader)->prev)->next = mHeader->next;
    (mHeader->next)->prev = (list1.mHeader)->prev;
    (list1.mHeader)->prev = it1.ptr;
    it1.ptr->next = list1.mHeader;
    mHeader->next = mHeader;
    // Update list2 links
    ((list2.mHeader)->prev)->next = it2.ptr;
    it2.ptr->prev = (list2.mHeader)->prev;
    (list2.mHeader)->prev = mHeader->prev;
    (mHeader->prev)->next = list2.mHeader;
    mHeader->prev = mHeader;
    // Update mSize
    list1.mSize += mSize - (mSize/2);
    list2.mSize += mSize/2;
    mSize = 0;
}
