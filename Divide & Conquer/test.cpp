#include <list>
#include <iostream>
using namespace std;

int main() {
    list<int>  mylist = {0, 1, 2, 3, 4};

    for (auto v : mylist)
        cout << v << "\n";
}