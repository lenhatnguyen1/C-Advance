#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class Car {
    protected:
        string NAME;
        string CAPACITY;
        string COLOR;
    public:
        void setName(string name) {
            NAME = name;
        }
        void setCapacity(string capacity) {
            CAPACITY = capacity;
        }
        void setColor(string color) {
            COLOR = color;
        }
        virtual void display() = 0;
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
