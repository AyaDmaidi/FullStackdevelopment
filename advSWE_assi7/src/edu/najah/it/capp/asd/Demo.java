package edu.najah.it.capp.asd;


import edu.najah.it.capp.asd.constants.ConnectionType;
import edu.najah.it.capp.asd.impl.Ftp;
import edu.najah.it.capp.asd.intf.Protocol;
import edu.najah.it.capp.asd.service.Connection;
import edu.najah.it.capp.exception.ConnectionAlreadyReleasedException;
import edu.najah.it.capp.exception.ProtocolException;
import edu.najah.it.capp.logger.Logger;
import edu.najah.it.capp.exception.BusyException;
import edu.najah.it.capp.exception.ConnectionAlreadyReleasedException;
import edu.najah.it.capp.exception.ConnectionIsInuse;
import edu.najah.it.capp.exception.NoConnectionAvailableException;
import edu.najah.it.capp.exception.ProtocolException;
import edu.najah.it.capp.exception.TimeoutErrorException;
import edu.najah.it.capp.exception.ReleaseException;

import edu.najah.it.capp.exception.UnknownErrorException;




public class Demo {
	private static void sleep(long timeout) throws InterruptedException {
		try {
			Thread.sleep(timeout);
		}catch(InterruptedException e1) {
			e1.printStackTrace();
		}
	}
	
	
	public static void main(String[] args) throws ProtocolException, InterruptedException{
		
		
		
		Connection connection=new Connection();
		int numOfTries=5;
		
		while (numOfTries>0)
		try {
			connection.release("");
			break;
			
		}catch(ConnectionAlreadyReleasedException e){
			System.out.println("ProtocolException :: "+e.getMessage());
			e.printStackTrace();
			break;
		}catch(UnknownErrorException e){
			System.out.println("UnknownErrorException :: "+e.getMessage());}
		catch(ConnectionIsInuse e) {
			System.out.println("ConnectionIsInuse ::"+e.getMessage());
		}
		catch(ReleaseException e) {
			System.out.println("ReleaseException ::"+e.getMessage());
		}
		finally {
			connection.release("");
		}
	
		
		try {
			connection.send("");}
		catch(NoConnectionAvailableException e) {
			
			System.out.println("NoConnectionAvailableException ::"+e.getMessage());
		}catch(TimeoutErrorException e) {
		
			System.out.println("TimeoutErrorException ::"+e.getMessage());
		}
		catch(BusyException e) {
			System.out.println("Number of tries ::"+numOfTries);
			System.out.println("BusyException :: "+e.getMessage());
			numOfTries--;
			sleep(500L);
		}
		finally {
			connection.send("");
		}
		
		
		
		Logger.getInstance().logInfo("This is a info message");
		Logger.getInstance().logDebug("This is a debug message");
		Logger.getInstance().logWarning("This is a warning message");
		Logger.getInstance().logError("This is a error message");
		
		
		
		
		
		
		
		
		
		
		
		
		Protocol ssh = Connection.getInstance(ConnectionType.SSH);
		Protocol ssh2 = Connection.getInstance(ConnectionType.SSH);
		Protocol telnet = Connection.getInstance(ConnectionType.TELNET);
		Protocol scp = Connection.getInstance(ConnectionType.SCP);
		Protocol ftp = Connection.getInstance(ConnectionType.FTP);
		
		
		if(ssh == ssh2) {
			System.out.println(" ssh is equal to ssh2");
		}
		ssh.send(" testing ssh ");
		telnet.send("Testing telnet ");
		scp.send("Testing scp");
		
		
		System.out.println(Connection.getCurrentConnections());
		Connection.release(ConnectionType.SSH);
		System.out.println(Connection.getCurrentConnections());
		
		ftp = Connection.getInstance(ConnectionType.FTP);
		System.out.println(Connection.getCurrentConnections());
		
		
		ssh = Connection.getInstance(ConnectionType.SSH);
		ftp = Connection.getInstance(ConnectionType.FTP);
		ftp = Connection.getInstance(ConnectionType.FTP);
		
		ftp = Connection.getInstance(ConnectionType.FTP);
		ftp.send("Testing FTP");
		Connection.release(ConnectionType.FTP);
		
		Protocol tftp = Connection.getInstance(ConnectionType.TFTP);
		Protocol tftp2 = Connection.getInstance(ConnectionType.TFTP);
		System.out.println(Connection.getCurrentConnections());
		if(tftp == tftp2 ) {
			System.out.println("Same object");
		}
		tftp.send("test the TFTP ");
		tftp2.send("test the TFTP ");

		//ftp = Ftp.getInsatnce();
		Connection.release(ConnectionType.TFTP);
		System.out.println(Connection.getCurrentConnections());//3
		if(ftp == null) {
			System.out.println("FTP is a null");
		} else {
			System.out.println("FTP is not a null");
		}
		ftp.send(" breaking the logic ");
			
		
	}
	

}

