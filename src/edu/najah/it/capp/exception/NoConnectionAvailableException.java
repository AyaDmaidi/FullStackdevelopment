package edu.najah.it.capp.exception;

public class NoConnectionAvailableException extends ProtocolException {

	public NoConnectionAvailableException(String message) {
		super(message);
		// TODO Auto-generated constructor stub
	}

@Override
	
	public String getMessage() {
		return "NoConnectionAvailableException :: "+super.getMessage();
	}
}
