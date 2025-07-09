#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Clock {
public:
    virtual int get_hours() const {
        time_t current_time = time(0);
        tm* local_time = localtime(&current_time);
        int hours = local_time->tm_hour;
        return hours;
    }
    virtual int get_minutes() const {
        time_t current_time = time(0);
        tm* local_time = localtime(&current_time);
        int minutes = local_time->tm_min;
        return minutes;
    }
    string get_time() const {
        int h = get_hours();
        int m = get_minutes();
        return to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m);
    }
};

class WorldClock : public Clock {
private:
    int offset;

public:
    WorldClock(int offset) {
        this->offset = offset;
    }

    int get_hours() const override {
        time_t current_time = time(0);
        tm* local_time = localtime(&current_time);
        int hours = local_time->tm_hour;
        hours = (hours + offset) % 24;
        if (hours < 0) {
            hours += 24;
        }
        return hours;
    }
};

int main() {
    // Testing NY vs CA if I live in CA
    Clock localTime;
    WorldClock ny(3); // 3 hours ahead

    cout << "Local time: " << localTime.get_time() << endl;
    cout << "World time: " << ny.get_time() << endl;

    return 0;
}
