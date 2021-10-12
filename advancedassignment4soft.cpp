# include <iostream>
# include <string>
#include <list>
#include <vector>
using namespace std;


class protocol {

public:

	static protocol* instancehttp;
	static protocol* instancessh;
	static protocol* instancetelnet;
	static protocol* instancescp;
	static protocol* instanceftp;
	static protocol* instancetftp;
	static string TFTP;
	static string HTTP;
	static string SSH;
	static string TELNET;
	static string SCP;
	static string FTP;
	static int  max;
	static list<string>connections;
	

	protocol* getinstance1(string p1);

	bool isrelease(string connectionprotocol3);



	/// ///// send function ////////////


	void send(string message);



	/// ///////////////// function to return the current connections//////////////////////

	void getcurrentconnection() {

		cout << endl;

		cout << "The cuerrent connections are:" << endl;

		for (string val : connections) {

			cout << val << ',';

			cout << endl;

		}
	}


};


/// /////////////////////////////////////////////////////////////////////////////


class HTTP :public protocol {

public:

	protocol* getinstance1(string p1) {

		if (p1 == "http") {

			if (protocol::max < 3) {

				if (instancehttp == 0) {


					instancehttp = new protocol;
					connections.push_back(p1);
					cout << endl;
					cout << "create new connection" << endl;
					max++;
					return instancehttp;
				}

				else if (instancehttp != NULL) {
					cout << endl;
					cout << "connection already exist " << endl;
					return instancehttp;
				}
			}



			else {
				cout << endl;
				cout << "You can't create more than 3 connections" << endl;
			}
		}
	}






	/// //////////////////////////////////////////////////////////////////////

	bool isrelease(string connectionprotocol3) {

		if (connectionprotocol3 == "http") {

			if (instancehttp != NULL) {

				instancehttp = NULL;
				max--;
				connections.remove(connectionprotocol3);
				cout << endl;
				cout << "The connection delete" << endl;
				return true;
			}


			else {
				cout << endl;
				cout << "This connection does not exist " << endl;
				return false;
			}
		}


	}

	void send(string message) {
		cout << endl;
		cout << "Sending message from HTTP :: " << message << endl;
	}

};

/// ///////////////////////////////////////////////////////////////////////////////////////

class SSH :public protocol {

public:
	protocol* getinstance1(string p1) {

		if (p1 == "ssh") {

			if (protocol::max < 3) {

				if (instancessh == 0) {


					instancessh = new protocol;
					connections.push_back(p1);
					cout << endl;
					cout << "create new connection" << endl;
					max++;
					return instancessh;
				}
				else if (instancessh != NULL) {
					cout << endl;
					cout << "connection already exist " << endl;
					return instancessh;
				}

			}
			else {
				cout << endl;
				cout << "You can't create more than 3 connections" << endl;
			}
		}
	}





	/// ///////////////////////////////////////////////////////////////////////

	bool isrelease(string connectionprotocol3) {

		if (connectionprotocol3 == "ssh") {

			if (instancessh != NULL) {

				instancessh = NULL;
				max--;
				connections.remove(connectionprotocol3);
				cout << endl;
				cout << "The connection delete" << endl;
				return true;
			}


			else {
				cout << endl;
				cout << "This connection does not exist " << endl;
				return false;
			}
		}
	}


	void send(string message) {
		cout << endl;
		cout << "Sending message from SSH :: " << message << endl;
	}
};



/// /////////////////////////////////////////////////////////////////////////////

class FTP :public protocol {

public:
	protocol* getinstance1(string p1) {

		if (p1 == "ftp") {

			if (protocol::max < 3) {

				if (instanceftp == 0) {


					instanceftp = new protocol;
					connections.push_back(p1);
					cout << endl;
					cout << "create new connection" << endl;
					max++;
					return instanceftp;
				}
				else if (instanceftp != NULL) {
					cout << endl;
					cout << "connection already exist " << endl;
					return instanceftp;
				}

			}
			else {
				cout << endl;
				cout << "You can't create more than 3 connections" << endl;

			}
		}
	}

	/// /////////////////////////////////////////////////////////////////////////////////

	bool isrelease(string connectionprotocol3) {

		if (connectionprotocol3 == "ftp") {

			if (instanceftp != NULL) {

				instanceftp = NULL;
				max--;
				connections.remove(connectionprotocol3);
				cout << endl;
				cout << "The connection delete" << endl;
				return true;
			}


			else {
				cout << endl;
				cout << "This connection does not exist " << endl;
				return false;
			}
		}


	}

	void send(string message) {
		cout << endl;
		cout << "Sending message from FTP :: " << message << endl;
	}


};

/// /////////////////////////////////////////////////////////////////////////////////


class SCP :public protocol {

public:
	protocol* getinstance1(string p1) {

		if (p1 == "scp") {

			if (protocol::max < 3) {

				if (instancescp == 0) {


					instancescp = new protocol;
					connections.push_back(p1);
					cout << endl;
					cout << "create new connection" << endl;
					max++;
					return instancescp;
				}
				else if (instancescp != NULL) {
					cout << endl;
					cout << "connection already exist " << endl;
					return instancescp;
				}

			}
			else {
				cout << endl;
				cout << "You can't create more than 3 connections" << endl;
			}
		}
	}


	/////////////////////////////////////////////////////////////////////////////////////


	bool isrelease(string connectionprotocol3) {

		if (connectionprotocol3 == "scp") {

			if (instancescp != NULL) {

				instancescp = NULL;
				max--;
				connections.remove(connectionprotocol3);
				cout << endl;
				cout << "The connection delete" << endl;
				return true;
			}



			else {
				cout << endl;
				cout << "This connection does not exist " << endl;
				return false;
			}
		}
	}

	void send(string message) {
		cout << endl;
		cout << "Sending message from SCP :: " << message << endl;
	}
};





////////////////////////////////////////////////////////////////////////////////////////////////////



class TELNET :public protocol {

public:
	protocol* getinstance1(string p1) {

		if (p1 == "telnet") {

			if (protocol::max < 3) {

				if (instancetelnet == 0) {


					instancetelnet = new protocol;
					connections.push_back(p1);
					cout << endl;
					cout << "create new connection" << endl;
					max++;
					return instancetelnet;
				}

				else if (instancetelnet != NULL) {
					cout << endl;
					cout << "connection already exist " << endl;
					return instancetelnet;
				}
			}



			else {
				cout << endl;
				cout << "You can't create more than 3 connections" << endl;
			}
		}
	}


	////////////////////////////////////////////////////////////////////


	bool isrelease(string connectionprotocol3) {

		if (connectionprotocol3 == "telnet") {

			if (instancetelnet != NULL) {

				instancetelnet = NULL;
				max--;
				connections.remove(connectionprotocol3);
				cout << endl;
				cout << "The connection delete" << endl;
				return true;
			}



			else {
				cout << endl;
				cout << "This connection does not exist " << endl;
				return false;
			}
		}
	}


	void send(string message) {
		cout << endl;
		cout << "Sending message from TELNET :: " << message << endl;
	}

};
//////////////////////////////////////////////////////////////////////////////////////////////


class TFTP :public protocol {

public:
	protocol* getinstance1(string p1) {

		if (p1 == "tftp") {

			if (protocol::max < 3) {

				if (instancetftp == 0) {


					instancetftp = new protocol;
					connections.push_back(p1);
					cout << endl;
					cout << "create new connection" << endl;
					max++;
					return instancetftp;
				}

				else if (instancetftp != NULL) {
					cout << endl;
					cout << "connection already exist " << endl;
					return instancetftp;
				}
			}



			else {
				cout << endl;
				cout << "You can't create more than 3 connections" << endl;
			}
		}
	}


	////////////////////////////////////////////////////////////////////


	bool isrelease(string connectionprotocol3) {

		if (connectionprotocol3 == "tftp") {

			if (instancetftp != NULL) {

				instancetftp = NULL;
				max--;
				connections.remove(connectionprotocol3);
				cout << endl;
				cout << "The connection delete" << endl;
				return true;
			}



			else {
				cout << endl;
				cout << "This connection does not exist " << endl;
				return false;
			}
		}
	}


	void send(string message) {
		cout << endl;
		cout << "Sending message from TFTP :: " << message << endl;
	}

};

/// //////////////////////////////////////////////////////////////////////////////////////////



/// /////////////////////////////////// proocolactoryclass//////////////////////

class protocolfactory {
public :
	
	
	protocolfactory* createprotocol(string protocoltype) {
		if (protocoltype=="ssh"){
		SSH b1;
		b1.getinstance1("ssh");
		}

		else if (protocoltype == "scp") {
			SCP b2;
			b2.getinstance1("scp");

		}
		else if (protocoltype == "ftp") {
			FTP b3;
			b3.getinstance1("ftp");

		}
		else if (protocoltype == "tftp") {
			TFTP b4;
			b4.getinstance1("tftp");

		}
		return NULL;

	}
	

};


/// ////////////////////////////////////////////////////////////////////////////////////

int protocol::max = 0;
protocol* protocol::instancehttp = 0;
protocol* protocol::instancetftp = 0;
protocol* protocol::instancessh = 0;
protocol* protocol::instancetelnet = 0;
protocol* protocol::instancescp = 0;
protocol* protocol::instanceftp = 0;
list <string>protocol::connections = list<string>();


int main() {
	
	
	//////////////////////////  create oject from class protocolfactory//////////////////

	protocolfactory h;
	h.createprotocol("ssh");
	h.createprotocol("ssh");
	h.createprotocol("scp");
	h.createprotocol("ftp");
	h.createprotocol("tftp");
	return 0;

	
	
}