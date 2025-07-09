#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
private:
    string name;
    vector<Person*> friends;

public:
    Person(const string& name) {
        this->name = name;
    }

    void befriend(Person* p) {
        friends.push_back(p);
    }

    void unfriend(Person* p) {
        auto it = remove(friends.begin(), friends.end(), p);
        if (it != friends.end()) {
            friends.erase(it, friends.end());
        }
    }

    string get_friend_names() const {
        string result;
        for (size_t i = 0; i < friends.size(); ++i) {
            result += friends[i]->name;
            if (i < friends.size() - 1) {
                result += " ";
            }
        }
        return result;
    }
};
int main() {
    // Testing
    Person justin("Justin");
    Person joe("Joe");
    Person jack("Jack");

    justin.befriend(&joe);
    justin.befriend(&jack);
    cout << "Justin's friends: " << justin.get_friend_names() << endl;

    justin.unfriend(&jack);
    cout << "After unfriending Jack: " << justin.get_friend_names() << endl;

    return 0;
}
