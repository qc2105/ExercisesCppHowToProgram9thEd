#include <iostream>
#include <stdexcept>

using namespace std;

// Reference: https://www.oreilly.com/library/view/c-cookbook/0596007612/ch09s04.html

// Some device
class Device {
public:
    Device(int _devno):
        devno(_devno)
    {
        if (devno == 2)
            throw runtime_error("Big problem");
    }
    ~Device() {
        cout << "Detor of Device " << devno << " has been called\n";
    }
private:
    int devno;
    Device();
};

class Broker {

public:
    Broker(int devno1, int devno2)
        try : dev1_(Device(devno1)),   // Create these in the initializer
        data(devno1 == 0? throw std::invalid_argument("first argument can't be zero") : new char[100]()),
        dev2_(Device(devno2)),
        dev3_(Device(3)){} // list.
    catch (...) {
        throw; // Log the message or translate the error here (see
               // the discussion)
    }
    ~Broker() {}

private:
    Broker();
    Device dev1_;
    char* data;
    Device dev2_;
    Device dev3_;
};

int main() {

    try {
        Broker b(0, 3);
        std::cout << "we can't reach here?\n";
    }
    catch (exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}