// Online C++ compiler to run C++ program online
# include <iostream>
# include <string>
# include<map>

using namespace std;

class singleton {

private:

	static singleton* instance;
	static singleton* instance1;
	static singleton* instance2;
	static singleton* instance3;
	static singleton* instance4;


public:



	static singleton* getinstance(string connectionProtocol);

	string send(string message) { ///////////// send function////////
		return message;
	}

	bool isreleased(string connectionProtocol1) {





		if (instance != 0) {
			instance = 0;
			cout << "True" << endl;
			return true;

		}
		else
		{
			cout << "False" << endl;
			return false;

		}










	}


};




singleton* singleton::instance = 0;
singleton* singleton::instance1 = 0;
singleton* singleton::instance2 = 0;
singleton* singleton::instance3 = 0;
singleton* singleton::instance4 = 0;



/// ////////////////  function getinstance ( string connectionProtocol)//////////////

singleton* singleton::getinstance(string connectionProtocol) {

	string arr = connectionProtocol;
	cout << connectionProtocol << "," << endl;

	/// //////////////////////////////////// the part to give instance //////////////////////////

	if (instance == 0) {
		if (connectionProtocol == "http") {
			instance = new singleton;
			return instance;


		}
	}



	else if (instance1 == 0) {
		if (connectionProtocol == "ssh") {
			instance1 = new singleton;
			return instance1;


		}
	}



	else if (instance2 == 0) {
		if (connectionProtocol == "ftp") {
			instance2 = new singleton;
			return instance2;

		}
	}



	else if (instance3 == 0) {
		if (connectionProtocol == "scp") {
			instance3 = new singleton;
			return instance3;

		}
	}



	else if (instance4 == 0) {
		if (connectionProtocol == "telnet") {
			instance4 = new singleton;
			return instance4;

		}
	}


	/// //////////////////////////////////////////////////////////////////



	/// ///////////////////////////////   check if there's current instance ///////////////

	if (instance4 != 0) {
		return instance4;
	}

	else if (instance3 != 0) {

		return instance3;
	}

	else if (instance2 != 0) {

		return instance2;
	}
	else if (instance1 != 0) {
		return instance1;
	}

	else if (instance != 0) {


		return instance;
	}

	////////////////////////////////////////////////////////
}


void count(string arr[5], string pro[5]) {
	int counter = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (pro[i] == arr[j]) {
				counter++;

			}
		}

	}

	if (counter >= 3) {
		cout << "You can't create more than 3 connections " << endl;
		return;
	}

}









int main() {


	singleton obj;
	string arr89[5] = { "http","ftp","ssh","scp","telnet" };

	string parameter[5] = { "http","ssh","ftp" }; /////// add every protocol you pass it to function to this list/////
	cout <<"give instance (http) :  "<< obj.getinstance("http") << endl;
	cout << "**************************" << endl;
	cout <<"release (http) : "<< obj.isreleased("http") << endl;
	cout << "**************************" << endl;
	cout <<" give instance (http) : "<< obj.getinstance("http") << endl;
	cout << "**************************" << endl;
	cout <<"get instance(http): " <<obj.getinstance("http") << endl;
	cout << "**************************" << endl;


	cout << "give instance (ssh) : "<<obj.getinstance("ssh") << endl;
	cout << "**************************" << endl;

	cout <<"  give instance (ftp) : "<< obj.getinstance("ftp") << endl;
	cout << "**************************" << endl;
	count(arr89, parameter); /// call count function to check if there's more than three connections"
	cout << "**************************************************************" << endl;


	


	return 0;
}