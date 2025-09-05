package com.organiser;
import com.event.*;
import java.util.Scanner;
public class TestOrganization {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter size of organization:");
		int n = sc.nextInt();
		Participants[] part = new Participants[n];
		int ch;
		int counter =0;
		do {
			System.out.println("Enter choice:\n1.Add Student \n2.Add Faculty \n3.Display Participants \n4.Display spcific details\n0.Exit");
			ch = sc.nextInt();
			switch(ch)
			{
			case 1:
				if(counter < n) {
					System.out.println("Enter student details: name mobno gradYear");
					part[counter] = new Student(counter,sc.next(),sc.next(),sc.nextInt());
					counter++;
				}
				else {
					System.out.println("Organization is full !!!");
				}
				
				break;
				
			case 2:
				if(counter < n) {
					System.out.println("Enter faculty details: name mobno experience");
					part[counter] = new Faculty(counter,sc.next(),sc.next(),sc.nextInt());
					counter++;
				}
				else {
					System.out.println("Organization is full!!!");
				}
				
				break;
				
			case 3:
				if(counter > 0) {
					for(Participants p: part) { //0 1..
						System.out.println(p);
					}
				}
				else {
					System.out.println("Organization is empty !!!");
				}
				
				break;
			case 4:
				System.out.println("Enter id to get details:");
				int index = sc.nextInt();
				if(index >= 0 && index < counter)
				{
					System.out.println(part[index].toString());
				}
				else {
					System.out.println("Enter valid index !!!");
				}
				break;
				
			default:
				System.out.println("Enter valid choice !!!");
			}
					
		}while(ch!=0);

	}

}
