package edu.najah.it.capp.exception;

public class BusyException extends ProtocolException {

	public BusyException(String message) {
		super(message);
		// TODO Auto-generated constructor stub
	}
	
	@Override
	
	public String getMessage() {
		return "BusyException :: "+super.getMessage();
	}
	
	
	

}
