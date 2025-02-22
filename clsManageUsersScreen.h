#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "clsInputValidate.h"
#include <iostream>
class clsManageUsersScreen : protected clsScreen
{
private:
	enum enManageUsersMenue { enListUsers = 1, enAddUsers = 2, enDeleteUsers = 3, enUpdateUsers = 4, enFindUsers = 5, enMainMenue = 6 };
	static short _ReadManageUsersMenue() {
		short choice = 0;
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		choice = clsInputValidate::ReadShortNumberBetween(1,6," Enter a Number between 1 to 6");
		return choice;
	}
	static void _ShowListUsers() {
		cout << "List User it will be here!\n";
	}
	static void _ShowAddUsers() {
		cout << "Add User it will be here!\n";
	}
	static void _ShowDeleteUsers() {
		cout << "Delete Users it will be here!\n";
	}
	static void _ShowUpdateUsers() {
		cout << "Update Users it will be here!\n";
	}
	static void _ShowFindUsers() {
		cout << "Find Users it will be here!\n";
	}
	static void _GoBackToManageUserMenue() {
		cout << "\n\nPress any key to go back to Manage Users Menue...";
		system("pause>0");
		ShowManageUsersMenue();
	}
	static void _PerformManageUserMenue(enManageUsersMenue ManageUser) {
		switch (ManageUser)
		{
		case enManageUsersMenue::enListUsers:
			system("cls");
			_ShowListUsers();
			_GoBackToManageUserMenue();
			break;
		case enManageUsersMenue::enAddUsers:
			system("cls");
			_ShowAddUsers();
			_GoBackToManageUserMenue();
			break;
		case enManageUsersMenue::enDeleteUsers:
			system("cls");
			_ShowDeleteUsers();
			_GoBackToManageUserMenue();

			break;
		case enManageUsersMenue::enUpdateUsers:
			system("cls");
			_ShowUpdateUsers();
			_GoBackToManageUserMenue();

			break;
		case enManageUsersMenue::enFindUsers:
			system("cls");
			_ShowFindUsers();
			_GoBackToManageUserMenue();
			break;
		case enManageUsersMenue::enMainMenue:

			break;
		default:
			break;
		}
	}
public:
	static void ShowManageUsersMenue() {
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add Users.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Users.\n";
		cout << setw(37) << left << "" << "\t[4] Update Users.\n";
		cout << setw(37) << left << "" << "\t[5] Find Users.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformManageUserMenue((enManageUsersMenue) _ReadManageUsersMenue());
	}
};

