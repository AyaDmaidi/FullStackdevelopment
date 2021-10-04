# include <iostream>
# include <string>
#include <list>
using namespace std;


class protocol {

private:
	static protocol* instancehttp;
	static protocol* instancessh;
	static protocol* instancetelnet;
	static protocol* instancescp;
	static protocol* instanceftp;
	static string HTTP;
	static string SSH;
	static string TELNET;
	static string SCP;
	static string FTP;

	static int  max;
	static list<string>connections;





public:







	protocol* getinstance1(string p1) {
		if (p1 == "http") {
			if (max < 3) {
				if (instancehttp == 0) {


					instancehttp = new protocol;
					connections.push_back(p1);
					cout << "create new connection" << endl;
					max++;
					return instancehttp;
				}

			}
			else {
				cout << "You can't create more than 3 connections" << endl;

			}
		}


		else if (p1 == "ssh") {
			if (max < 3) {
				if (instancessh == 0) {



					instancessh = new protocol;
					connections.push_back(p1);
					cout << "create new connection" << endl;
					max++;
					return instancessh;


				}
			}
			else {
				cout << "You can't create more than 3 connections" << endl;

			}

		}


		else if (p1 == "ftp") {
			if (max < 3) {
				if (instanceftp == 0) {



					instanceftp = new protocol;
					connections.push_back(p1);
					cout << "create new connection" << endl;
					max++;
					return instanceftp;
				}
			}
			else {
				cout << "You can't create more than 3 connections" << endl;
			}
		}


		else if (p1 == "scp") {
			if (max < 3) {
				if (instancescp == 0) {


					instancescp = new protocol;
					connections.push_back(p1);
					cout << "create new connection" << endl;
					max++;
					return instancescp;
				}
			}
			else {
				cout << "You can't create more than 3 connections" << endl;
			}
		}


		else if (p1 == "telnet") {
			if (max < 3) {

				if (instancetelnet == 0) {

					instancetelnet = new protocol;
					connections.push_back(p1);
					cout << "create new connection" << endl;
					max++;
					return instancetelnet;
				}
			}
			else {
				cout << "You can't create more than 3 connections" << endl;
				return 0;
			}
		}





	}









	void send(string message) {

		cout << "The new connection is :" << message << endl;
	}



	void getcurrentconnection() {
		cout << "The cuerrent connections are:" << endl;
		for (string val : connections) {
			cout << val << ',';
			cout << endl;
		}
	}




	bool isrelease(string connectionprotocol3) {

		if (connectionprotocol3 == "http") {
			if (instancehttp != NULL) {

				instancehttp = NULL;
				max--;
				connections.remove(connectionprotocol3);
				cout << "The connection delete" << endl;
				return true;
			}
			else {
				cout << "This connection does not exist " << endl;
				return false;
			}
		}


		else if (connectionprotocol3 == "scp") {
			if (instancescp != NULL) {

				instancescp = NULL;
				max--;
				connections.remove(connectionprotocol3);
				cout << "The connection delete" << endl;
				return true;
			}
			else {
				cout << "This connection does not exist " << endl;
				return false;
			}

		}

		else if (connectionprotocol3 == "telnet") {
			if (instancetelnet != NULL) {

				instancetelnet = NULL;
				max--;
				connections.remove(connectionprotocol3);
				cout << "The connection delete" << endl;
				return true;
			}
			else {
				cout << "This connection does not exist " << endl;
				return false;
			}

		}

		else if (connectionprotocol3 == "ftp") {
			if (instanceftp != NULL) {

				instanceftp = NULL;
				max--;
				connections.remove(connectionprotocol3);
				cout << "The connection delete" << endl;
				return true;
			}
			else {
				cout << "This connection does not exist " << endl;
				return false;
			}

		}

		else if (connectionprotocol3 == "ssh") {
			if (instancessh != NULL) {

				instancessh = NULL;
				max--;
				connections.remove(connectionprotocol3);
				cout << "The connection delete";
				return true;
			}
			else {
				cout << "This connection does not exist " << endl;
				return false;
			}

		}

		return false;
	}
};

int protocol::max = 0;
protocol* protocol::instancehttp = 0;
protocol* protocol::instancessh = 0;
protocol* protocol::instancetelnet = 0;
protocol* protocol::instancescp = 0;
protocol* protocol::instanceftp = 0;


string protocol::HTTP = "http";
string protocol::SSH = "ssh";
string protocol::TELNET = "telnet";
string protocol::SCP = "scp";
string protocol::FTP = "ftp";

list <string>protocol::connections = list<string>();


int main() {


	protocol c;



	c.getinstance1("http");

	c.getinstance1("ssh");
	c.getinstance1("ftp");

	c.isrelease("ftp");
	c.getinstance1("telnet");
	c.getinstance1("scp");
	c.isrelease("ftp");

	return 0;
}