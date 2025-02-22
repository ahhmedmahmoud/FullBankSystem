#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsUpdateClientScreen : protected clsScreen
{
private:
    static void _ReadClientInfo(clsBankClient& Client) {
        cout << "Enter Your First Name\n";
        Client.Fname = clsInputValidate::ReadString();

        cout << "Enter Your Last Name\n";
        Client.Lname = clsInputValidate::ReadString();

        cout << "Enter Your Email\n";
        Client.Email = clsInputValidate::ReadString();

        cout << "Enter Your Phone\n";
        Client.Phone = clsInputValidate::ReadString();

        cout << "Enter Your Pin Code\n";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "Enter Your Account Balance\n";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }
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
    static void ShowUpdateClientScreen() {
        _DrawScreenHeader("\t Update Client Screen");
        string AccountNumber = "";
        cout << "Please Enter account number\n";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "The Account Number is not found, Choose another one!\n";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "Update Client Info:\n";
        cout << "------------------------\n";
        _ReadClientInfo(Client1);
        clsBankClient::enSaveResults SaveResulst;
        SaveResulst = Client1.Save();
        switch (SaveResulst)
        {
        case clsBankClient::enSaveResults::svFaildEmptyObject:
            cout << "\nError account was not saved because it's Empty";
            break;
        case clsBankClient::enSaveResults::svSucceeded:
            cout << "\nAccount Updated Successfully :-)\n";
            _PrintClient(Client1);
            break;
        default:
            break;
        }

    }
};

