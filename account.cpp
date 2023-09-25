#include "account.h"

Account::Account() {
    account_balance = 0;
    while (true)
    {
        /* code */
    
    cout << "******** Welcome To Ulego MFB *********" << endl;
    cout << "1). Create Account: " << endl;
    cout << "2). Deposit Money: " << endl;
    cout << "3). Withdraw Money: " << endl;
    cout << "4). View Account Balance: " << endl;
    cout << "5). Exit: " << endl;
    cin >> option;
    
       switch (option)
       {
       case 1:
        cout << "Get started with creating your account"<< endl;
        cout << "Enter your full name: ";
        getline(cin, full_name);
        
        cout << "Enter a new password: ";
        cin >> password;
        cout << "Enter your age: ";
        cin >> age;
        if (!full_name.empty() && !password.empty())
        {
            open_account(full_name, password);
        }
        break;

        case 2:
        cout << "Enter account number to deposit money: ";
        cin >> account_number;
        float amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        if (amount && account_number)
        {
            deposit_money(amount, account_number);
        }
        
        
        break;

        case 3:
        cout << "Withdrawing money interface here";

        case 4:

        cout << "Enter Your Account Number: ";
        cin >> account_number;
        cout << "Enter your password: ";
        cin >> password;
        check_account_balance(account_number, password);
        break;
       
       default:
       return;
       system("clear");
        break;
       }
    }
    
};

Account::~Account() {
    cout << "Thank you for banking with us" <<endl;
}

void Account::open_account(std::string account_name, std::string password){
    int account_type_opt;
    int newAccountNumber {0};
    cout << "Thank you for creating an account with us" << endl;

    cout << "Please Select An Account Type: " << endl;
    cout << "1) Current Account: " << endl;
    cout << "2) Savings Account: " << endl;
    cout << "3) Fixed Deposit Account: " << endl;
    cout << "4) Cancel Operation: " << endl;
    cin >> account_type_opt;
    cin.ignore();
    switch (account_type_opt)
    {
    case 1:
        account_type = "Current Account";
        break;
    case 2:
        account_type = "Savings Account";
        break;
    case 3:
        account_type = "Fixed Deposit Account";
        break;
    default:
        system("clear");
        return;
        break;
    }
    if (!account_name.empty() && !password.empty() && !account_type.empty())
    {
        const int new_account_number = generate_account_number();
        std::string  msg = users.add_user(account_name, password, account_type, new_account_number, age, account_balance);
        system("clear");
        if (msg == "User created successfully")
        {
            cout << "Hi "<< full_name << " Thank you for creating account with us, your account have been created successfully and your account details are" <<endl;
            cout << "Full name: " << full_name << endl;
            cout << "Password: " << password << endl;
            cout << "Account Type: " << account_type << endl;
            cout << "Account Balance: " << account_balance << endl;
        }
        
    }
    
    
}

void Account::deposit_money(float& amount, int& account_number){
    Person user = users.find_user(account_number);
    if (user.account_number)
    {
        float user_new_act_bal = user.account_balance + amount;
        cout << "your new account balance is: "<< user_new_act_bal << endl;
    }else{
        cout << "nothing"
    }
    
    

}

void Account::withdraw_money(int account_number, float amount, std::string password) {

}

void Account::check_account_balance(int account_number, std::string password) {
    Person user = users.find_user(account_number);
    if (user.password == password)
    {
        cout << "Your account balance is: "<< user.account_balance;    
    }else {
        cout << "Incorrect Password or user does not exist"<< endl;
    };
    
};

void Account::display_account_details(int acount_number, std::string password) {

}

long int Account::generate_account_number(){
    std::random_device rd;
    std::mt19937 gen(rd());

    const long int minRandomNumber {1000000000};
    const long int maxRandomNumber {9999999999};

    std::uniform_int_distribution<long int> distribution(minRandomNumber, maxRandomNumber);
    const long int randomAccountNumber = distribution(gen);
    return randomAccountNumber;
}

template<typename T> bool Account::isNumber(const T& value) {
    return is_arithmetic<T>::value;
}