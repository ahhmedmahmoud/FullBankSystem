#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <string>
#include "iostream"
class clsWithdrawScreen : protected clsScreen
{
private:
	static string _ReadAccountNumber() {
		cout << "Please Enter Your Account Number To Complete Withdrawing Process\n";
		string AccountNumber = clsInputValidate::ReadString();
		return AccountNumber;
	}
    static void _PrintClient(clsBankClient Client) {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.Fname;
        cout << "\nLastName    : " << Client.Lname;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
public:
    static void ShowWithDrawScreen() {
        _DrawScreenHeader("\t Withdraw Screen");
        string AccountNumber = _ReadAccountNumber();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "The Client With [" << AccountNumber << "] Not Exist, Try Again!\n";
            AccountNumber = _ReadAccountNumber();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);
        double Amount = 0;
        cout << "Enter The Amount of Withdraw\n";
        Amount = clsInputValidate::ReadDblNumber();
        cout << "Are You Sure to want perform this Transaction?\n";
        char Answer = clsInputValidate::ReadChar();
        if (Answer == 'Y' || Answer == 'y') {
            Client.Withdraw(Amount);
            cout << "Amount Withdraw Succsefully :-)" << endl;
            cout << "The New Balance is " << Client.AccountBalance << endl;
            cout << "Thank You! \n";
        }
        else {
            cout << "Operation was Cancelled\n";
        }

    }
};

