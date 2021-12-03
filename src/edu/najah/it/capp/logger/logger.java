package edu.najah.it.capp.logger;

import java.util.logging.Logger;
import java.util.logging.Level;
public class logger {
	private static logger instance; 
	
	private logger() {
		
	}
	private static final logger LOGGER = logger.getInstance();
	public static logger getInstance() {
		if(instance == null) {
			instance = new logger();
		}
		return instance;
	}
	
	public void logInfo(String message) {
		
		System.out.println(java.time.LocalDateTime.now()  + " [INFO] " + message);
		LOGGER.info("This is info message");
	}
	
	public void logDebug(String message) {
		System.out.println(java.time.LocalDateTime.now()  + " [Debug] " + message);
		LOGGER.debug("This is a debug message");

	}
	public void logWarning(String message) {
		System.err.println(java.time.LocalDateTime.now()  + " [Warn] " + message);
		LOGGER.warn("This is a warn message");
	}
	public void logError(String message) {
		System.err.println(java.time.LocalDateTime.now()  + " [Error] " + message);
		LOGGER.error("This is an error message");
	}

}
