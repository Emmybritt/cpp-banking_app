#ifndef ACCOUNT_HEADER
#define ACCOUNT_HEADER
 
#include <iostream>
#include <ios>
#include <string>
#include "usersAccount.h"
#include <random>
#include <type_traits>

using namespace std;

class Account {
    private:
        std::string full_name;
        float account_balance;
        std::string password;
        std::string account_type;
        int account_number;
        int option;
        int age;
        Users users;

    public:
        Account();
        ~Account();
        
        // Creates User Accounts
        void open_account(std::string account_name, std::string password);
        void deposit_money(float amount);
        void withdraw_money(int account_number, float amount, std::string password);
        void check_account_balance(int account_number, std::string password);
        void display_account_details(int acount_number, std::string password);

        /* Generates Random Account Number For Users When creating account */
        long int generate_account_number();

        /*Check if value entered is a number*/
        template<typename T> bool isNumber(const T& value);
};

#endif