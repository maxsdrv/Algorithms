#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const auto odd ([](int i) {return i % 2 != 0;});

int main() {
    vector<int> v {1, 2, 3, 2, 5, 2, 6, 2, 4, 8};
    const auto new_end(remove(begin(v), end(v), 2));
    cout << "Vector size= " << v.size() << endl;
    v.erase(new_end, end(v));
    for (const auto& i : v){
        cout << i << ", ";
    }
    cout << endl;
    v.erase(remove_if(begin(v), end(v), odd), end(v));
    v.shrink_to_fit();
    for (const auto& i : v){
        cout << i << ", ";
    }
    cout << endl;
    cout << "Vector size= " << v.size() << endl;

    return 0;
}
