package com.event;

public class Participants {
	private int id;
	private String name;
	private String mobno;
	public Participants(int id, String name, String mobno) {
		this.id = id;
		this.name = name;
		this.mobno = mobno;
	}
	
	
	
	@Override
	public String toString() {
		return "Participants id=" + id + ", name=" + name + ", mobno=" + mobno + "";
	}
	
	public int getId() {
		return this.id;
	}
	
	public String getName() {
		return this.name;
	}
	
	public String getMobno() {
		return this.mobno;
	}
}
