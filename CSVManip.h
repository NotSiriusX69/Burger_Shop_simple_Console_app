#ifndef BURGER_SHOP_CSVMANIP_H
#define BURGER_SHOP_CSVMANIP_H

#include <iostream>
#include <vector>
#include "rapidcsv-master/src/rapidcsv.h"

using namespace std;

rapidcsv::Document clientsDoc("C:/Users/User/CLionProjects/Burger_Shop/cmake-build-debug/BurgerShopClients.csv",
                              rapidcsv::LabelParams(0, -1));
rapidcsv::Document chefsDoc("C:/Users/User/CLionProjects/Burger_Shop/cmake-build-debug/BurgerShopChefs.csv",
                            rapidcsv::LabelParams(0, -1));
rapidcsv::Document burgersDoc("C:/Users/User/CLionProjects/Burger_Shop/cmake-build-debug/BurgerShopBurgers.csv",
                              rapidcsv::LabelParams(0, -1));

//Clients
bool OverWriteClientToCSV(int id, string user_name, string first_name, string last_name, string password,string phone_number, int age) {

    ofstream file;
    file.open("BurgerShopClients.csv");
    file << "id" << "," << "user_name" << "," << "first_name" << "," << "last_name" << ","
         << "password" << "," << "phone_number" << "," << "age" << "\n";
    file << id << "," << user_name << "," << first_name << "," << last_name << "," << password << ","
         << phone_number << "," << age << "\n";
    file.close();
    return true;
}
bool InsertClientToCSV(int id, string user_name, string first_name, string last_name, string password, string phone_number,int age) {

    ofstream file;
    file.open("BurgerShopClients.csv", std::ofstream::app);
    file << id << "," << user_name << "," << first_name << "," << last_name << "," << password << ","
         << phone_number << "," << age << "\n";
    file.close();
    return true;
}

//Chefs
bool OverWriteChefsToCSV(int id, string first_name, string last_name, int age, double salary, double rating) {

    ofstream file;
    file.open("BurgerShopChefs.csv");
    file << id << "," << first_name << "," << last_name << "," << age << ","
         << salary << "," << rating << "\n";
    file.close();
    return true;
}
bool InsertChefsToCSV(int id, string first_name, string last_name, int age, double salary, double rating) {

    ofstream file;
    file.open("BurgerShopChefs.csv", std::ofstream::app);
    file << "id" << "," << "first_name" << "," << "last_name" << "," << "age" << "," << "salary" << "," << "rating"
         << "\n";
    file << id << "," << first_name << "," << last_name << "," << age << ","
         << salary << "," << rating << "\n";
    file.close();
    return true;
}

//Burgers
bool OverWriteBurgersToCSV(int id, string name, double price, double rating) {

    ofstream file;
    file.open("BurgerShopBurgers.csv");
    file << "id" << "," << "name" << "," << "price" << "," << "rating" << "\n";
    file << id << "," << name << "," << price << "," << rating << "\n";
    file.close();
    return true;
}
bool InsertBurgersToCSV(int id, string name, double price, double rating) {

    ofstream file;
    file.open("BurgerShopBurgers.csv", std::ofstream::app);
    file << id << "," << name << "," << price << "," << rating << "\n";
    file.close();
    return true;
}

#endif
