#pragma once
#include <iostream>
using namespace std;

enum PaymentMode
{
	CardMode = 0, CashMode
};

class PaymentI
{
public:
	virtual bool makePayment(double amount) = 0;
};

class Card : public PaymentI
{
public:
	bool makePayment(double amount)
	{
		//use REST API to connect to online server for payment
		cout << "Payment of " << amount << " is successfull" << endl;
		return true;
	}
};

class Cash : public PaymentI
{
public:
	bool makePayment(double amount)
	{
		cout << "Payment of " << amount << " is successfull" << endl;
		return true;
	}
};

class PaymentManager
{
public:
	static bool makePayment(PaymentMode mode, double amount)
	{
		unique_ptr<PaymentI> instance;
		if (PaymentMode::CardMode == mode)
		{
			instance = unique_ptr<PaymentI>(new Card);
		}
		else if (PaymentMode::CashMode == mode)
		{
			instance = unique_ptr<PaymentI>(new Cash);
		}
		return instance->makePayment(amount);
	}
};