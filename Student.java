package com.event;

public class Student extends Participants{
	private int gradYear;
	public Student(int id,String name,String mobno,int gradYear) {
		super(id,name,mobno);
		this.gradYear = gradYear;
	}
	
	public String toString() {
		return "Student :"+getName()+" id:"+getId()+" mobno: "+getMobno()+" graduated in "+gradYear;
	}
}
