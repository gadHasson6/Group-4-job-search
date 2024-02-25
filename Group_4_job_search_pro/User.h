//
// Created by LENOVO on 21/02/2024.
//

#ifndef GROUP_4_JOB_SEARCH_PRO_USER_H
#define GROUP_4_JOB_SEARCH_PRO_USER_H
#include <string>
using namespace std;

class User {
    private:
        string name;
        long id;
        int password;
        string feedback;
    public:
        long getId();
        int getPassword();
        string getName();
        string getFeedback();
        void changeName(string newName);
        void changePassword(int newPassword);
        void changeFeedback(string newFeedback);



};


#endif //GROUP_4_JOB_SEARCH_PRO_USER_H
