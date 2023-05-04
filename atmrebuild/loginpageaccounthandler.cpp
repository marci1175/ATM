#include "deleteaccount.h"
#include "deposit.h"
#include "modifyaccountcredentials.h"
#include "sendmoney.h"
#include "withdraw.h"
#include "transacionthistory.h"
#include "loginpage.h"
#include "main.h"
#include <iostream>
// 1) Deposit money 2) Withdraw money 3) Send money 4) View transaction history 5)Change account credentials 6)Delete account
int loginpageactionhandler(std::string user_name, int user_login_action) {
	switch(user_login_action)
	{
	case 0:
		system("CLS");
		main();
		break;
	case 1:
		deposit(user_name);
		system("CLS");
		loginpage(user_name);
		break;
	case 2:
		withdraw(user_name);
		system("CLS");
		loginpage(user_name);
		break;
	case 3:
		sendmoney(user_name);
		system("CLS");
		loginpage(user_name);
		break;
	case 4:
		transacionthistory(user_name);
		system("CLS");
		loginpage(user_name);
		break;
	case 5:
		modifyaccountcredentials(user_name);
		system("CLS");
		loginpage(user_name);
		break;
	case 6:
		deleteaccount(user_name);
		system("CLS");
		loginpage(user_name);
		break;
	default:
		system("CLS");
		loginpage(user_name);
		break;
	}


	return 0;
}