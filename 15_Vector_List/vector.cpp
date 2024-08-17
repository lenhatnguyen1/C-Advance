#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> array;
    array.push_back(1);
    array.push_back(6);
    array.push_back(0);
    array.push_back(8);
    array.insert(array.begin() + 4, 2);
    for(int i = 0; i < array.size(); i++) {
        cout << "Element " << i << ": " << array[i] << endl;
    }

    return 0;
}
