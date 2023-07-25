#ifndef USERS_HEADER
#define USERS_HEADER

#include <map>
#include <iostream>
#include <string>
#include <list>

using namespace std;
struct Person {
    std::string full_name;
    float account_balance;
    std::string password;
    std::string account_type;
    int account_number;
    int age;

};

class Users {
    private:
        int total_users_count;
        map<int, Person> users;

    public:
        // Print all users created
        void print_all_users();

        // Add and register user to bank
        std::string add_user(std::string name, std::string password, std::string account_type, int account_number, int age, float account_balance);

        // Check if user is already created
        bool user_exist(int account_number);

        // Delete a user from the the database
        void delete_user(int account_number);

        Person find_user(int account_number);

};

#endif