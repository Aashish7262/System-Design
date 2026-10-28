#include <iostream>
using namespace std;

class Logger {
private:
    Logger() {}

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void log(string message) {
        cout << message << endl;
    }
};

int main() {
    Logger& logger1 = Logger::getInstance();
    Logger& logger2 = Logger::getInstance();

    logger1.log("Application started");
    logger2.log("User logged in");

    cout << "Same object: "
         << (&logger1 == &logger2) << endl;

    return 0;
}