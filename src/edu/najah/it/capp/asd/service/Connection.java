package edu.najah.it.capp.asd.service;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

import edu.najah.it.capp.asd.impl.TFTPAdpter;
import edu.najah.it.capp.asd.constants.ConnectionType;
import edu.najah.it.capp.asd.impl.Ftp;
import edu.najah.it.capp.asd.impl.ProtocolFactory;
import edu.najah.it.capp.asd.impl.Scp;
import edu.najah.it.capp.asd.impl.Ssh;
import edu.najah.it.capp.asd.impl.Telnet;
import edu.najah.it.capp.asd.intf.Protocol;
import edu.najah.it.capp.exception.ProtocolException;

public class Connection {
	
	
	
	public static Map connections = new HashMap<String, Protocol>();
	//getInstance, createConnection , getConnection 
	
	
	
	public static Protocol getInstance(String connectionType) throws ProtocolException{
		
		
		if(connections.containsKey(connectionType)) {
			System.out.println("Connection is already created!.");
			return (Protocol) connections.get(connectionType);
		} else {
			if(connections.size() >= 3 ) {
				//do not create connection
				System.out.println("Can't create more than 3 connection!!");
				return null;
			}
			Protocol instance = ProtocolFactory.createProcol(connectionType);
			connections.put(connectionType, instance);
			return instance;
			
		}
	}
	
	

	
	

	
		public static boolean release(String connectionType) throws ProtocolException{
			///////////////////////////// Connection is inuse, you can’t release now///////////

         String status=ConnectionType.SSH;
         
        if (status==connectionType) {
	throw new ProtocolException("Connection is inuse, you can’t release now");}

			/////////////// Unable to release the connection because of an unknown error////////
          if(connectionType==ConnectionType.SSH) {
	          throw new ProtocolException("Unable to release the connection because of an unknown error");}



			if(connections.containsKey(connectionType)) {
				connections.remove(connectionType);
				
				ProtocolFactory.createProcol(connectionType).release();
				
				return true;
			}
			
			///////////// Connection is already released///////////////
			if(!connections.containsKey(connectionType)) {
				throw new ProtocolException("Connection is already released");
			}
			
			if (Connection.release(" ")) {
				throw new ProtocolException("Release Exception");
			}
			
			
			return false;
			
		}
		
		
		
		public void send(String message) throws ProtocolException{
			
			//////////////////// system busy////////////////
			if (connections.size()>3) {
				throw new ProtocolException ("System is too busy now");
			}
			
			//////////////////// no connection available /////////
			if (!Connection.getCurrentConnections().contains(ConnectionType.FTP) ) {
				throw new ProtocolException("No connection is available");
			}
			
			////////////// time out error ///////////////////
			long startTime = System.currentTimeMillis();
	        long endTime = 0;

			while (endTime-startTime>4000  ) {
				throw new ProtocolException("Failed to send the data because of a timeout error");
			}
			
			
		}

		
	
		
	
	public static ArrayList<String> getCurrentConnections() {
		Set<String> keys = connections.keySet();
		
		ArrayList<String> myConnection =  new ArrayList<String>();
		
		
		for (String key : keys) {
			myConnection.add(key);
		}
		
		
		return myConnection;
		
		
	}
	
	
	
	

}
