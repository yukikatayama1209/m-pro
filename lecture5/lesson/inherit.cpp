#include <iostream>
using namespace std;

class road_vehicle {
private:
    int wheels;
    int passengers;
public:
    void set_wheels(int num) {
        wheels = num;
    }
    int get_wheels() {
        return wheels;
    }
    void set_pass(int num){
        passengers = num;
    }
    int get_pass() {
        return passengers;
    }
};

class truck : public road_vehicle {
    int cargo;
public:
    void set_cargo(int size){
        cargo = size;
    }
    int get_cargo(){
        return cargo;
    }
    void show(){
        cout << "wheels: " << get_wheels() << endl;
        cout << "passengers: " << get_pass() << endl;
        cout << "cargo size: " << cargo << endl;
    }
};

enum type {car, van, wagon};
class automobile : public road_vehicle{
    enum type car_type;
public:
    void set_type(type t){
        car_type = t;
    }
    enum type get_type(){
        return car_type;
    }
    void show(){
        cout << "wheels: " << get_wheels() << endl;
        cout << "passengers: " << get_pass() << endl;
        cout << "type: ";
        switch (car_type){
            case car: cout << "car" << endl; break;
            case van: cout << "van" << endl; break;
            case wagon: cout << "wagon" << endl; break;
        }
    }

};

int main() {
    truck t1, t2;
    automobile c;

    t1.set_wheels(18);
    t1.set_pass(2);
    t1.set_cargo(3200);
    t1.show();

    t2.set_wheels(6);
    t2.set_pass(3);
    t2.set_cargo(1200);
    t2.show();

    c.set_wheels(4);
    c.set_pass(6);
    c.set_type(van);
    c.show();

    return 0;
}
