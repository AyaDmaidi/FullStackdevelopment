package edu.najah.it.capp.exception;

public class ConnectionIsInuse extends ProtocolException {

	public ConnectionIsInuse(String message) {
		super(message);
		// TODO Auto-generated constructor stub
	}
@Override
	
	public String getMessage() {
		return "ConnectionIsInuse :: "+super.getMessage();
	}

}
