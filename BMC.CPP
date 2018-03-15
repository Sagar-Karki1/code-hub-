#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct account{
	int rate;
	int roll;
	int grade;
	int clas;
	int cost;
	int p_mon;
	int rem_mon;
	int id;
	char name[20];
	char address[20];
	char status[6];
}accdata;
struct account d;

void add_fee(){
	clrscr();
	int total;
	char c;
	printf("student id: ");
	scanf("%d",&d.id);
	printf("student name: ");
	scanf("%s",d.name);
	printf("address: ");
	scanf("%s",d.address);
	printf("addmission of grade: ");
	scanf("%d",&d.clas);
	printf("addmission fee cost: ");
	scanf("%d",&d.cost);
	printf("payment status: ");
	scanf("%s",d.status);
	total+=d.cost;
	printf("Amount to be paid:%d ",total);

	FILE *fptr;
	fptr=fopen("record.txt","a");
	if(fptr==NULL){
		printf("file not found!!!");
		exit(0);
	}
	fprintf(fptr,"%d %s %s %d %d %d %s",d.id,d.name,d.address,d.clas,d.cost,total,d.status);
	clrscr();
	printf("id   name    address    class    addmission-fee   total-amt  status\n");
	printf("------------------------------------------------------------------------");
	printf("\n%d\t\t %d\t %d\t %s\t %s\t %s\n",d.id,d.name,d.address,d.clas,d.cost,total,d.status);
	printf("\n");
	fclose(fptr);
	printf("do you want to continue:(y/n)");
	c=getch();
	if(c=='y'){
		add_fee();
	}
	if(c=='n'){
		exit(0);
	}
}

view_addtrans(){
	clrscr();
	int total;
	FILE *fptr;
	fptr=fopen("record.txt","r");
	if(fptr==NULL){
		printf("file does not exits!!!");
		exit(0);
	}
	printf("id   name    address   class  addmission-fee  total  payment-status\n");
	printf("------------------------------------------------------------------");

	while(feof!=NULL){
		fscanf(fptr,"\n%d\t %s\t %s\t %d\t %d\t %d\t %s\n",d.id,d.name,d.address,d.clas,d.cost,total,d.status);
		printf("%d\t %d\t %d\t %s\t %s\t %s",d.id,d.name,d.address,d.clas,d.cost,total,d.status);
	}
	fclose(fptr);
}

//function of monthly fee//
void month_fee(){
	clrscr();
	int c;
	int due=0;
	printf("student id: ");
	scanf("%d",&d.id);
	printf("student name: ");
	scanf("%s",d.name);
	printf("grade: ");
	scanf("%d",&d.grade);
	printf("roll no: ");
	scanf("%d",&d.roll);
	printf("address: ");
	scanf("%s",d.address);
	printf("monthly fee: ");
	scanf("%d",&d.rate);
	printf("month till which fee is paid: ");
	scanf("%d",&d.p_mon);
	printf("no of months whose fee is to be paid: ");
	scanf("%d",&d.rem_mon);
	due=d.rem_mon*d.rate;
	printf("amount to be paid: %d",due);

	FILE *file;
	file=fopen("data.txt","a");
	if(file==NULL){
		printf("file does not exits!!!");
		exit(0);
	}
	fprintf(file,"%d %s %d %d %s %d %d %d %d",d.id,d.name,d.grade,d.roll,d.address,d.rate,d.p_mon,d.rem_mon,due);
	clrscr();
	printf("id  name  grade  roll-no  address  monthly-fee  paid-month  rem-month  total-due");
	printf("\n%d\t %s\t %d\t %d\t %s\t %d\t %d\t %d\t %d\n",d.id,d.name,d.grade,d.roll,d.address,d.rate,d.p_mon,d.rem_mon,due);
	printf("\n");
	fclose(file);
	printf("do you want to continue(y/n): ");
	c=getch();
	if(c=='y'){
		month_fee();
	}
	if(c=='n'){
		exit(0);
	}
}

int main(){
	clrscr();
	int menu;
	printf("\t\t\tMenu");
	printf("\n1.Admission fee.");
	printf("\n2.view addmission fee transaction.");
	printf("\n3.monthly fee.");
	printf("\nview monthly fee transaction.");
	printf("\nselect payment type: ");
	scanf("%d",&menu);
	switch(menu){
		case 1:
			add_fee();
			break;
		case 2:
			view_addtrans();
			break;

		case 3:
			month_fee();
			break;
		case 4:
			exit(0);
	}
	getch();
	return 0;
}