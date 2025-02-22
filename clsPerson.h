#pragma once
#include <iostream>
using namespace std;
class clsPerson
{
private:
	string _Fname;
	string _Lname;
	string _Email;
	string _Phone;

public:
	clsPerson(string Fname , string Lname, string Email, string Phone) {
		_Fname = Fname;
		_Lname = Lname;
		_Email = Email;
		_Phone = Phone;
	}
	void setFname(string Fname) {
		_Fname = Fname;
	}
	string getFname() {
		return _Fname;
	}
	__declspec(property(get = getFname, put = setFname)) string Fname;

	void setLname(string Lname) {
		_Lname = Lname;
	}
	string getLname() {
		return _Lname;
	}
	__declspec(property(get = getLname, put = setLname)) string Lname;

	string FullName() {
		return _Fname + " " + _Lname;
	}

	void setEmail(string Email) {
		_Email = Email;
	}
	string getEmail() {
		return _Email;
	}
	__declspec(property(get = getEmail, put = setEmail)) string Email;

	void setPhone(string Phone) {
		_Phone = Phone;
	}
	string getPhone() {
		return _Phone;
	}
	__declspec(property(get = getPhone, put = setPhone)) string Phone;

};

