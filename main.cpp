#include <iostream>

#include "User.h"

using namespace std;

void PrintNotifications(User* user);

int main() {

    User* user1 = new User("user1", "users");
    User* user2 = new User("user2", "users");
    User* user3 = new User("user3", "users");

    user2->Follow(user1);
    user3->Follow(user1);

    user1->AddEvent("Hi, my friends!");

    PrintNotifications(user2);
    PrintNotifications(user3);

    return 0;
}

void PrintNotifications(User* user) {
    if (user->IsNewNotifications()) {
        for (auto notification : user->GetNotifications()) {
            cout << notification.first->GetFullName() << ":" << endl;
            for (auto message : notification.second) {
                cout << "\t" << message << endl;
            }
            cout << endl;
        }
    }
}
