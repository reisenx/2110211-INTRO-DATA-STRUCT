#include <iostream>
#include "map_bst_lite.h"
#include "student.h"

int main(){
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    
    CP::map_bst<int,int> m;
    
    int N;
    std::cin >> N;

    for(int i = 0; i < N ; i++){
        int x;
        std::cin >> x;
        m[x] = x;
    }

    int x, y;
    std::cin >> x >> y;

    auto result = m.value_in_key_range(x, y);

    for (auto &val: result) {
        std::cout << val << " ";
    }

    return 0;
}