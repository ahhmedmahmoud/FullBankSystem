#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


class clsDeleteClientScreen : protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
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
    static void _ShowDeleteClientScreen()
    {
        _DrawScreenHeader("\t Delete Client Screen");
        string AccountNumber = "";
        cout << "Please Enter account number\n";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "The Account Number is not found, Choose another one!\n";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "Are You Sure to want Delete this Client y/n? " << endl;
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            if (Client1.Delete()) {
                cout << "Client Deleted Successfully!\n";
                _PrintClient(Client1);
            }
            else {
                cout << "Error in Deleting Client.." << endl;
            }
        }

    }
};

