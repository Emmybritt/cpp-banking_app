#include "usersAccount.h"

void Users::print_all_users() {
    for (auto user: users)
    {
        cout << "********Account number: " << user.first << "***********" <<endl;
        cout << "Full Name: "<< user.second.full_name << endl;
        cout << "Age: " << user.second.age << endl;
        cout << "Accout Balance" << user.second.account_balance << endl;
        cout << "******************===*********************" << endl;
    };
    
};

bool Users::user_exist(int account_number){
    return users.find(account_number) != users.end();
}

void Users::delete_user(int account_number) {
    users.erase(account_number);
    cout << "User with account number "<< account_number << " deleted successfully" << endl;
}

std::string Users::add_user(std::string name, std::string password, std::string account_type, int account_number, int age, float account_balance = 0) {
    std::string msg;
    if (name.empty())
    {
        msg = "Error 400 name is required!!!";
    }else if (password.empty())
    {
        msg = "Error 400 Password is required!!!";
    }else if (account_type.empty())
    {
        msg = "Error 400 account_type is required!!!";
    } else if (!age)
    {
        msg = "Error 400 account_type is required!!!";
    }else if(user_exist(account_number)) {
        msg = "Failed to create new account as user already exist.";
    }else {
        Person newUser;
        newUser.full_name = name;
        newUser.account_balance= account_balance;
        newUser.account_number = account_number;
        newUser.age = age;
        newUser.password = password;
        newUser.account_type = account_type;
        users.insert(pair<int, Person>(account_number, newUser));
        msg = "User created successfully";
    }
    
    
    return msg;
    
};

Person Users::find_user(int account_number){
    auto it = users.find(account_number);
    if (it != users.end())
    {
        const Person& foundUser = it->second;
        return foundUser;
    }else {
        cout << "User does not exits";
        return Person();
    }
    
}
