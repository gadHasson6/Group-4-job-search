//
// Created by LENOVO on 13/02/2024.
//

#ifndef JOB_SEARCH_GROUP_4_USER_H
#define JOB_SEARCH_GROUP_4_USER_H

#include "Includes.h"
#include "Defines.h"


class User {
protected:
    int u_id;
    string u_full_name;
    string u_mail;
    string u_password;
    int u_phone_number;
public:
    User(int id, string name, string mail, string pass, int phone_num);

    User();

    virtual ~User();

    virtual void print_user() const = 0;

    virtual void edit_details();

};


#endif //JOB_SEARCH_GROUP_4_USER_H
