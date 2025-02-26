#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clString.h"
#include <vector>
#include <fstream>

using namespace std;
class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNew = 2 };
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    double _AccountBalance;
    bool _MarkedForDelete = false;

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

    }

    static  vector <clsBankClient> _LoadClientsDataFromFile() {
        vector  <clsBankClient> vClients;
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);
        if (MyFile.is_open()) {
            string Line;
            while (getline(MyFile, Line)) {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                vClients.push_back(Client);
            }
            MyFile.close();
        }
        return vClients;
    }
    static string _ConverClientObjectToLine(clsBankClient Client , string Sperator = "#//#") {
        string sClientData = "";
        sClientData += Client.Fname + Sperator;
        sClientData += Client.Lname + Sperator;
        sClientData += Client.Email + Sperator;
        sClientData += Client.Phone + Sperator;
        sClientData += Client.AccountNumber() + Sperator;
        sClientData += Client.PinCode + Sperator;
        sClientData += to_string(Client.AccountBalance);
        return sClientData;
    }

    static void _SaveCleintsDataToFile(vector <clsBankClient> vClietns) {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);
        string DataLine;
        if (MyFile.is_open()) {
            for (clsBankClient C : vClietns) {
                if (C.MarkedForDeleted() == false) {
                    DataLine = _ConverClientObjectToLine(C);
                    MyFile << DataLine <<endl;
                }
            }
            MyFile.close();
        }
    }
    void _AddNew()
    {

        _AddDataLineToFile(_ConverClientObjectToLine(*this));
    }
    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

public:


    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }
    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }
    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }


    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;



  
    static clsBankClient Find(string AccountNumber)
    {


        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {



        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExist = 2 };

    enSaveResults Save() {
        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty()) {
                return enSaveResults::svFaildEmptyObject;
            }

        }
        case enMode::UpdateMode:
            _Update();

            return enSaveResults::svSucceeded;
        case enMode::AddNew:
        {
            if (clsBankClient::IsClientExist(AccountNumber())) {
                return enSaveResults::svFaildAccountNumberExist;
            }
            else {
                _AddNew();
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;

            }
        }
        }
       
    }
    static clsBankClient GetAddNewClientObject(string AccountNumber) {
        return clsBankClient(enMode::AddNew, "", "", "", "", AccountNumber, "", 0);
    }

    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }
    void Deposit(double Amount) {
        _AccountBalance += Amount;
        Save();
    }
    void Withdraw(double Amount) {
        _AccountBalance -= Amount;
        Save();
    }
    static double GetTotalBalances() {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        double TotalBalances = 0;
        for (clsBankClient Client : vClients) {
            TotalBalances += Client.AccountBalance;
        }
        return TotalBalances;
    }
    bool Delete()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkedForDelete = true;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

        *this = _GetEmptyClientObject();

        return true;

    }
    static vector <clsBankClient> GetClientsList() {
        return _LoadClientsDataFromFile();
    }

};

