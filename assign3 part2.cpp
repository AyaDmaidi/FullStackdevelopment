# include <iostream>
# include <string>
#include <list>
using namespace std;

class protocol {

public:
	

	static protocol* instancehttp;
	static protocol* instancessh;
	static protocol* instancetelnet;
	static protocol* instancescp;
	static protocol* instanceftp;
	static protocol* instance;
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


	void send(string message) {
		cout << endl;
		cout << "The new connection is :" << message << endl;
	}



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
};
class TFTP :public protocol {

public:
	protocol* getinstance1(string p1) {

		if (p1 == "tftp") {

			if (protocol::max < 3) {

				if (instance == 0) {


					instance = new protocol;
					connections.push_back(p1);
					cout << endl;
					cout << "create new connection" << endl;
					max++;
					return instance;
				}

				else if (instance != NULL) {
					cout << endl;
					cout << "connection already exist " << endl;
					return instance;
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

			if (instance != NULL) {

				instance = NULL;
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
};

///// Legacy component

class TFTPProtocol {
private:
	static TFTPProtocol *instance;
	static bool connected;
	TFTPProtocol() {
		connected = true;
	}

public :
	bool isConnected() {
		return connected;
	}
	static TFTPProtocol *getTFTPInstance(string pro) {
		if (instance == NULL) {
			instance = new TFTPProtocol();
		}
		return instance;
	}

	bool releaseTFTP(string pro4) {
		if (instance != NULL) {
			instance = NULL;
			return true;
		}
		return false;
	}

	void sendMessage(string message) {
		cout<<("I am sending a " + message + " vi TFTP Protocol");

	}

	/// ////////////////////////////////////////////////////////////////////////////////////
};




// adapter class 
class TFTPAdapter : public protocol {
	

public :

	protocol* p3;
	TFTPAdapter(protocol* object1) {
		p3 = object1;
	}

	TFTPProtocol* getTFTPInstance(string pro) {
		p3->getinstance1(pro);
	}
	void sendMessage(string message) {
		p3->send(message);
	}
	bool releaseTFTP(string pro4) {
		p3->isrelease(pro4);
	}
	bool isConnected() {
		return true;
	}



};

TFTPProtocol* TFTPProtocol::instance = 0;
bool TFTPProtocol::connected = false;
int protocol::max = 0;
protocol* protocol::instancehttp = 0;
protocol* protocol::instancessh = 0;
protocol* protocol::instancetelnet = 0;
protocol* protocol::instancescp = 0;
protocol* protocol::instanceftp = 0;
protocol* protocol::instance = 0;
list <string>protocol::connections = list<string>();


int main() {


	HTTP c;
	TELNET c1;
	SCP c2;
	FTP c3;
	SSH c5;

	c.getinstance1("http");

	c.getinstance1("http");

	c1.getinstance1("telnet");

	c1.getcurrentconnection();

	c2.getinstance1("scp");


	c.isrelease("http");
	protocol f;
	f.getcurrentconnection();

	protocol* protocolptr = new protocol;
	TFTPAdapter* adapter = new TFTPAdapter(protocolptr);
	adapter->send("http");
	return 0;
}