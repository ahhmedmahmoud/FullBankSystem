#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <string>
#include "iostream"
class clsDepositScreen : protected clsScreen
{
private:
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
	static string  _ReadAccountNumber() {
        string AccountNumber = "";
        cout << "Please Enter Your Account Number To Complete Depositing Process\n";
        cin >> AccountNumber;
        return AccountNumber;
	}
public:
	static void ShowDepositScreen() {
		_DrawScreenHeader("\t Deposit Screen");
        string AccountNumber = _ReadAccountNumber();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "The Client With [" << AccountNumber << "] Not Existed, Try Again!" << endl;
            AccountNumber = _ReadAccountNumber();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        double Amount = 0;
        cout << "Please Enter a Deposit Number?" << endl;
        Amount = clsInputValidate::ReadDblNumber();
        cout << "Are You Sure to want perform this Transaction?\n";
        char Answer = clsInputValidate::ReadChar();
        if (Answer == 'Y'  || Answer == 'y' ){
            Client.Deposit(Amount);
            cout << "Amount Deposite Succsefully :-)" << endl;
            cout << "The New Balance is " << Client.AccountBalance << endl;
            cout << "Thank You! \n";
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

	}
};

