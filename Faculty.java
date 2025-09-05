package com.event;

public class Faculty extends Participants{
	private int exp;

	public Faculty(int id, String name, String mobno,int exp) {
		super(id, name, mobno);
		this.exp = exp;
	}

	public String toString() {
		return "Faculty id:"+getId()+" name: "+getName()+" mobno: "+getMobno()+" has experience: "+exp;
	}
	
}
