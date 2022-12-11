#ifndef BURGERSHOP_MANAGER_H
#define BURGERSHOP_MANAGER_H


#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;


class Manager {

private:
    const char *UserName = "Abbas";
    const char *Password = "Abbas100";


public:
    const char *getUserName() {
        return UserName;
    }

    const char *getPassWord() {
        return Password;
    }

};

#endif
