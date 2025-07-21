#include <iostream>
using namespace std ;
class animal {
    public:
    void eat(){
        cout << "eating food ." << endl;
    }
};

class mammal : public animal {
    public:
    void givebirth(){
        cout << "giving birth to younger ones." << endl ;
    }
};

class dog : public mammal {
    public:
    void bark(){
        cout << "barking ." << endl ;
        }
};

int main(){
    dog obj ;
    obj.bark();
    obj.eat();
    obj.givebirth();
    return 0 ;
}