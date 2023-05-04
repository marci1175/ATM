#include <string>
#include <windows.h>
#include <iostream>
#include <fstream>
int historycompiler(std::string user_name ,std::string recpnam,int balance,int veglegesosszeg, int depositamount, int sendam, int sveglegesosszeg, int sbalance) {
	//veglegesosszeg = depositamount + balance <- structure of how a balance is calculated
	
	//if depositamount is 0 - the transaction wont get to the historycompiler() part :)

	//for money sender strcture -> sveglegesosszeg = sbalance - sendam

	std::fstream myFile;
	//add math logic
	int plussveglegesosszeg;
	plussveglegesosszeg = sbalance + sendam;
	if (sveglegesosszeg < 0){
		myFile.open(user_name + ".history", std::ios::app);
		if (sveglegesosszeg == sbalance + sendam) {
			//myFile << balance << " = " << veglegesosszeg << " + " << depositamount;
			myFile << "\n---------------\n" << "Money before transaction : " << sbalance << std::endl << "Money transacted : +" << sendam << std::endl << "Money after transaction : " << sveglegesosszeg << "\n---------------\n" << std::endl;
		}
		else if (sveglegesosszeg < plussveglegesosszeg) {
			//myFile << balance << " = " << veglegesosszeg << " + " << depositamount;
			myFile << "\n---------------\n" << "Money before transaction : " << sbalance << std::endl << "Money transacted : -" << sendam << std::endl << "Money after transaction : " << sveglegesosszeg << "\n---------------\n" << std::endl;
		}
		myFile.close();
		myFile.flush();
	}
	else {
		int plusveglegesosszeg;
		plusveglegesosszeg = balance + depositamount;
		myFile.open(recpnam + ".history", std::ios::app);
		if (veglegesosszeg == plusveglegesosszeg) {
			//myFile << balance << " = " << veglegesosszeg << " + " << depositamount;
			myFile << "\n---------------\n" << "Money before transaction : " << balance << std::endl << "Money transacted : +" << depositamount << std::endl << "Money after transaction : " << veglegesosszeg << "\n---------------\n" << std::endl;
		}
		else if (veglegesosszeg < plusveglegesosszeg) {
			//myFile << balance << " = " << veglegesosszeg << " + " << depositamount;
			myFile << "\n---------------\n" << "Money before transaction : " << balance << std::endl << "Money transacted : -" << depositamount << std::endl << "Money after transaction : " << veglegesosszeg << "\n---------------\n" << std::endl;
		}
		myFile.close();
		myFile.flush();
	}
	myFile.close();
	myFile.flush();
	return 0;
}