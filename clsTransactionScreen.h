#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h";
#include "clsTotalBalanceScreen.h"
#include "iomanip"
#include <iostream>
using namespace std;
class clsTransactionScreen : clsScreen
{
private:
	enum enTransactionMenue { Deposit = 1, Withdraw = 2, TotalBalance = 3, ShowMainMenue = 4 };
	static short _ReadTransactionMenue() {
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
		short choice = clsInputValidate::ReadShortNumberBetween(1, 4, "Enter Number Between 1 to 4");
		return choice;
	}
	static void _ShowDepositList() {
		clsDepositScreen::ShowDepositScreen();
	}
	static void _ShowWithdrawList() {
		clsWithdrawScreen::ShowWithDrawScreen();
	}
	static void _ShowTotalBalanceList() {
		clsTotalBalanceScreen::ShowTotalBalances();
	}
	static void _GoBackToTransactionsMenue()
	{
		cout << "\n\nPress any key to go back to Transactions Menue...";
		system("pause>0");
		ShowTransactionsMenue();

	}
	static void _PerformTransactionMenue(enTransactionMenue TransactionMenue) {
		switch (TransactionMenue)
		{
		case enTransactionMenue::Deposit:
			system("cls");
			_ShowDepositList();
			_GoBackToTransactionsMenue();
			break;
		case enTransactionMenue::Withdraw:
			system("cls");
			_ShowWithdrawList();
			_GoBackToTransactionsMenue();
			break;
		case enTransactionMenue::TotalBalance:
			system("cls");
			_ShowTotalBalanceList();
			_GoBackToTransactionsMenue();
			break;
		case enTransactionMenue::ShowMainMenue:
			break;
		default:
			break;
		}
	}
public:
	static void ShowTransactionsMenue() {

		system("cls");
		_DrawScreenHeader("\t\tMain Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformTransactionMenue((enTransactionMenue)_ReadTransactionMenue());


			//cout << "\n\nPress any key to go back to Main Menue...";
			//system("pause>0");
			//clsMainScreen::ShowMainMenue();

		}
	

};

