/*  ----------- List Replace -----------
    l = [9,2,2,4,2,7] | x = 2 | y = [3,2,1]
    l = [9,<2>,<2>,4,<2>,7] --> l = [9,<3,2,1>,<3,2,1>,4,<3,2,1>,7]
    Steps:
    1.) Insert <3,2,1> | l = [9,<3,2,1>,<2>,<2>,4,<2>,7]
    2.) Erase 2        | l = [9,<3,2,1>,<2>,4,<2>,7]
    3.) Method erase will return iterator next to the item it erase
*/

void replace(const T& x, list<T>& y) {
  auto it = begin();
  while(it != end())
  {
    if(*it == x)
    {
      for(auto &item : y) { insert(it, item); }
      it = erase(it);
    }
    else it++;
  }
}
