package edu.najah.it.capp.exception;

public class ReleaseException extends ProtocolException {

	public ReleaseException(String message) {
		super(message);
		// TODO Auto-generated constructor stub
	}
@Override
	
	public String getMessage() {
		return "ReleaseException :: "+super.getMessage();
	}

}
