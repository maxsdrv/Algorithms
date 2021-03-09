#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int Process(string &path, const int start, const int end) {
    ifstream in(path);
    int line;
    vector<bool> my_bitset(end - start);
    if (in) {
        while (in >> line) {
            my_bitset[line] = true;
        }
    } else {
        cout << "Error open file" << endl;
    }
    in.close();

    cout << "End of program" << endl;
    for (int i = 0; i < my_bitset.size(); ++i){
        if (!my_bitset[i]){
            return i;
        }
    }

    return -1;
}


int main() {
    size_t start = 1, end = 20;
    string path = "file.txt";
    cout << Process(path, start, end) << endl;

    return 0;
}
