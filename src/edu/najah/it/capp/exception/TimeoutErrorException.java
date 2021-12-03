package edu.najah.it.capp.exception;

public class TimeoutErrorException extends ProtocolException {

	public TimeoutErrorException(String message) {
		super(message);
		// TODO Auto-generated constructor stub
	}
@Override
	
	public String getMessage() {
		return "TimeoutErrorException :: "+super.getMessage();
	}
}
