package edu.najah.it.capp.exception;

public class ConnectionAlreadyReleasedException extends ProtocolException {

	public ConnectionAlreadyReleasedException(String message) {
		super(message);
		// TODO Auto-generated constructor stub
	}

	
@Override
	
	public String getMessage() {
		return "ConnectionAlreadyReleasedException :: "+super.getMessage();
	}
	
}
