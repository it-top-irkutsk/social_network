#ifndef SOCIAL_NETWORK_USER_H
#define SOCIAL_NETWORK_USER_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class User {
private:
    string first_name;
    string last_name;

    vector<User*> followers;
    vector<string> events;
    bool flag_notifications;
    map<User*, vector<string>> followers_notifications;

public:
    User(const string &firstName, const string &lastName) : first_name(firstName), last_name(lastName) {
        flag_notifications = false;
    }

    void AddEvent(string message) {
        events.push_back(message);

        for (auto user : followers) {
            user->GetEvent(this, message);
        }
    }

    void GetEvent(User* sender, string message) {
        flag_notifications = true;
        followers_notifications[sender].push_back(message);
    }

    void Follow(User* user) {
        user->AddNewFollower(this);
        followers_notifications.insert(pair<User*, vector<string>>(user, vector<string>()));
    }

    void AddNewFollower(User* user) {
        followers.push_back(user);
    }

    bool IsNewNotifications() {
        return flag_notifications;
    }

    map<User*, vector<string>> GetNotifications() {
        return followers_notifications;
    }

    string GetFullName() {
        return last_name + " " + first_name;
    }
};


#endif //SOCIAL_NETWORK_USER_H
