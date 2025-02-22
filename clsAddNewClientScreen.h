#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsAddNewClientScreen : protected clsScreen
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
	static void ShowAddClientScreen(){
        
        string Title = "\t Add New Client Screen";
        string SubTitle = "\t\tNew Client";
        _DrawScreenHeader(Title, SubTitle);
        string AccountNumber = "";
        cout << "Please Enter an Account Number:\n";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber)) {
            cout << "The Account Number Already Used, Choose another One!\n";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
        _ReadClientInfo(NewClient);
        clsBankClient::enSaveResults SaveResult;
        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Addeded Successfully :-)\n";

            _PrintClient(NewClient);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExist:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;

        }
        }

	}
};

