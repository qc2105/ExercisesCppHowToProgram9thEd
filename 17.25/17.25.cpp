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
    Device dev2_;
    Device dev3_;
};

int main() {

    try {
        Broker b(1, 2);
    }
    catch (exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}