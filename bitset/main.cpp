#include <iostream>
#include <fstream>
#include <bitset>
#include <string>

using namespace std;

template<typename T>
void CreateBitset(string &path, const T start, const T end){
    T size_bitset = end - start + 1;
    bitset<size_bitset> my_bitset;

}
void Process() {
    ifstream in("file.txt");
    int line;
    if (in) {
        while (in >> line) {
            cout << line << " ";
        }
    } else {
        cout << "Error open file" << endl;
    }
    in.close();

    cout << "End of program" << endl;
}


int main() {



    return 0;
}
