#include"contact.h"
#include<stdio.h>
#include<string.h>
#include"populate.h"
/*
search=137
list=236
edit=245
delete=665
save=874
*/
void initialize(AddressBook *addressBook)
{
	addressBook->contactCount=0;
	//populateAddressBook(addressBook);
	FILE *fptr;
         fptr=fopen("contacts.csv","r");
         fscanf(fptr,"%d\n",&addressBook->contactCount);
         for(int i=0;i<addressBook->contactCount;i++)
         {
                 fscanf(fptr,"%[^,],%[^,],%[^,\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
         }
         fclose(fptr);
}
//create the contacts in the addressbook
void createContact(AddressBook *addressBook)
{
	char name[50],phone[20],email[50];
	printf("enter the name : \n");
	scanf(" %[^\n]",name);                                               //scaning the name from user
	strcpy(addressBook->contacts[addressBook->contactCount].name,name);  //copying the name into contact
label1:
	printf("enter the mobile number : \n");
	scanf(" %[^\n]",phone);                   //scanning the phone number form user
	int phonelen=0;
	for(int i=0;phone[i];i++)
	{
		phonelen++;                       //calculating the phone number length
	}
	if(phonelen==10)                          //checking if the given phone number is equal to 10 or not
	{
		int i=0;
		while(phone[i])
		{
			if(phone[i]>='0'&&phone[i]<='9')
			{
				i++;
			}
			else
			{
label2:
				printf("1.re-enter the number\n");
				printf("2.exit\n");
				int a;
				scanf("%d",&a);
				switch(a)
				{
					case 1:goto label1;
					       break;
					case 2:return;
					default:printf("enter either 1 or 2");
						goto label2;
				}
			}
		}
		if(phone[i]=='\0')    //checking the given number is already exist or not in contacts
		{
			int j;
			for(j=0;j<addressBook->contactCount;j++)
			{
				if(strstr(addressBook->contacts[j].phone,phone)!=NULL)
				{
label3:
					printf("1.re-enter the number\n");
					printf("2.exit\n");
					int b;
					scanf("%d",&b);
					switch(b)
					{
						case 1:goto label1;
						       break;
						case 2:return;
						default:printf("enter either 1 or 2");
							goto label3;
					}
				}
			}
			if(j==addressBook->contactCount)
			{
				strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);	//copying the number to contacts

label4:
				printf("enter tha mail id :\n");                    
				scanf(" %[^\n]",email);                 //scanning the mailid from user
				if((strstr(email,"@")!=NULL)&&(strstr(email,".com")!=NULL))
				{
					strcpy(addressBook->contacts[addressBook->contactCount].email,email);    //copying the mailid to contacts
					addressBook->contactCount++;
				}
				else
				{
					printf("1.re-enter the mail id\n");
					printf("1.exist\n");
					int c;
					scanf("%d",&c);
label5:
					switch(c)
					{
						case 1:goto label4;
						       break;
						case 2:return;
						default:printf("enter either 1 or 2");
							goto label5;
					}
				}
			}
		}
	}
	else
	{
		printf("1.re enter the number \n");
		printf("2.exit\n");
		int d;
		scanf("%d",&d);
label6:
		switch(d)
		{
			case 1:goto label1;
			       break;
			case 2:return;
			default:printf("enter either 1 or 2");
				goto label6;
		}
	}
}
//search contact in addressbook
void searchContact(AddressBook *addressBook)
{
label1:
	printf("1.name\n");
	printf("2.phone number\n");
	printf("3.emailid\n");
	printf("enter option : ");
	int search;
	char input[50];
	int flag=0;
	scanf("%d",&search);
	switch(search)
	{
		case 1:printf("enter the name : ");
		       scanf(" %[^\n]",input);
		       for(int i=0;i<addressBook->contactCount;i++)
		       {
			       if(strstr(input,addressBook->contacts[i].name)!=NULL)
			       {
				       printf("%s\n%s\n%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
				       flag=1;
			       }
		       }
		       if(flag==0)
		       {
			       printf("data not found");
			       return;
			       
		       }
		       break;
		case 2:printf("enter the phone number : ");
		       scanf(" %[^\n]",input);
		       for(int i=0;i<addressBook->contactCount;i++)
		       {
			       if(strstr(input,addressBook->contacts[i].phone)!=NULL)
			       {
				       printf("%s\n%s\n%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
				       flag=1;			       
			       }
		       }
		       if(flag==0)
		       {
label3:
			       printf("1.re-enter the name\n");
			       printf("2.exit\n");
			       int a;
			       scanf("%d",&a);
			       switch(a)
			       {
				       case 1:goto label1;
				       case 2:return;
				       default:printf("Enter either 1 or 2");
					       goto label3;
			       }
		       }
		       break;
		case 3:printf("enter the mail id : ");
		       scanf(" %[^\n]",input);
		       for(int i=0;i<addressBook->contactCount;i++)
		       {
			       if(strstr(input,addressBook->contacts[i].email)!=NULL)
			       {
				       printf("%s\n%s\n%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
				       flag=1;			       
			       }
		       }
		       if(flag==0)
		       {
label4:
			       printf("1.re-enter the name\n");
			       printf("2.exit\n");
			       int a;
			       scanf("%d",&a);
			       switch(a)
			       {
				       case 1:goto label1;
				       case 2:return;
				       default:printf("Enter either 1 or 2");
					       goto label4;
			       }
		       }
		       break;
		default:printf("not accessible option\n");
			int a;
label5:
			printf("1.re-enter the option\n");
			printf("2.exit\n");
			scanf("%d",&a);
			switch(a)
			{
				case 1:goto label1;
				       break;
				case 2:return;
				default:printf("enter either 1 or 2\n");
					goto label5;
			}	
	}
}
//showing list of contacts
void listContacts(AddressBook* addressBook)
{
	//printf("name----phone number----mailid\n");
	for(int i=0;i<=addressBook->contactCount;i++)
	{
		printf("%s   %s  %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
	}
}
//for edit the contact
void editContact(AddressBook* addressBook)
{
label1:
	printf("1.name\n");
	printf("2.phone number\n");
	printf("3.emailid\n");
	printf("enter option : ");
	int search,index;
	char input[50],edit[50];
	int count=0;
	scanf("%d",&search);
	switch(search)
	{
		case 1:
			printf("enter name:\n");
			scanf(" %[^\n]",input);
			for(int i=0;i<addressBook->contactCount;i++)
			{
				if(strstr(addressBook->contacts[i].name,input)!=NULL)
				{
					printf("%d  %s  %s  %s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
					count=1;
				}
			}
			if(count==0)
			{
				printf("data not found\n");
				return;
			}
label2:
			printf("enter which position to edit");
			scanf("%d",&index);
			printf("1.by name\n");
			printf("2.by phone number\n");
			printf("3.by emial\n");
			int a;
			scanf("%d",&a);
			switch(a)
			{
				case 1:printf("enter name to edit : ");
				       scanf(" %[^\n]",edit);
				       printf("edit position\n");
					       strcpy(addressBook->contacts[index-1].name,edit);
					       printf("name edited successflly\n");
				       break;
				case 2:
label3:
				       printf("enter phone number to edit : ");
				       scanf(" %[^\n]",edit);
				       int phonelen=0;
				       for(int i=0;edit[i];i++)
				       {
					       phonelen++;
				       }
				       if(phonelen==10)
				       {
					       int i=0;
					       while(edit[i])
					       {
						       if(edit[i]>='0'&&edit[i]<='9')
						       {
							       i++;
						       }
						       else
						       {
label4:
							       printf("1.re-enter the number \n");
							       printf("2.exit\n");
							       int b;
							       scanf("%d",&b);
							       switch(b)
							       {
								       case 1:goto label3;
								       case 2:return;
								       default:printf("enter either 1 or 2");
									       goto label4;
							       }
						       }
						       if(edit[i]!='\0')
						       {
							       int j;
							       for(j=0;j<addressBook->contactCount;j++)
							       {
								       if(strstr(addressBook->contacts[j].name,edit)!=NULL)
								       {
label5:
									       printf("1.re-enter the number\n");
									       printf("2.exit\n");
									       int c;
									       scanf("%d",&c);
									       switch(c)
									       {
										       case 1:goto label1;
										       case 2:return;
										       default:printf("enter either 1 or 2");
											       goto label5;
									       }
								       }
							       }
							       if(j==addressBook->contactCount)
							       {
								       strcpy(addressBook->contacts[index-1].phone,edit);
								       printf("phone edited successfully\n");
							       }
						       }

					       }
				       }
				case 3:
label6:
				       printf("enter email to edit : ");
				       scanf(" %[^\n]",edit);
				       if((strstr(edit,"@")!=NULL)&&(strstr(edit,".com")!=NULL))
				       {
					       strcpy(addressBook->contacts[index-1].email,edit);
                                                       printf("email edited successfully");
				       }
				       else
				       {
label7:
					       printf("1.re-enter mail id\n");
					       printf("2.exit\n");
					       int c;
					       scanf("%d",&c);
					       switch(c)
					       {
						       case 1:goto label6;
						       case 2:return;
						       default:printf("enter either 1 or 2 \n");
							       goto label7;
							       break;
					       }
				       }
				       break;
				default:printf("enter either 1 or 2 or 3");
					goto label2;
			}
			break;

		case 2:
			printf("enter phone number:\n");
			scanf(" %[^\n]",input);
			for(int i=0;i<addressBook->contactCount;i++)
			{
				if(strstr(addressBook->contacts[i].phone,input)!=NULL)
				{
					printf("%d  %s  %s  %s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
					count=1;
				}
			}
			if(count==0)
			{
				printf("data not found\n");
				return;
			}
label10:
			printf("enter which position to edit : ");
			scanf("%d",&index);
			printf("1.by name\n");
			printf("2.by phone number\n");
			printf("3.by emial\n");
			int a1;
			scanf("%d",&a1);
			switch(a1)
			{
				case 1:printf("enter name to edit : ");
				       scanf(" %[^\n]",edit);
				       printf("edit position\n");
					       strcpy(addressBook->contacts[index-1].name,edit);
					       printf("name edited successflly\n");
				       break;
				case 2:
label11:
				       printf("enter phone number to edit : ");
				       scanf(" %[^\n]",edit);
				       int phonelen=0;
				       for(int i=0;edit[i];i++)
				       {
					       phonelen++;
				       }
				       if(phonelen==10)
				       {
					       int i=0;
					       while(edit[i])
					       {
						       if(edit[i]>='0'&&edit[i]<='9')
						       {
							       i++;
						       }
						       else
						       {
label12:
							       printf("1.re-enter the number \n");
							       printf("2.exit\n");
							       int b;
							       scanf("%d",&b);
							       switch(b)
							       {
								       case 1:goto label11;
								       case 2:return;
								       default:printf("enter either 1 or 2");
									       goto label12;
							       }
						       }
						       if(edit[i]!='\0')
						       {
							       int j;
							       for(j=0;j<addressBook->contactCount;j++)
							       {
								       if(strstr(addressBook->contacts[j].name,edit)!=NULL)
								       {
label13:
									       printf("1.re-enter the number\n");
									       printf("2.exit\n");
									       int c;
									       scanf("%d",&c);
									       switch(c)
									       {
										       case 1:goto label1;
										       case 2:return;
										       default:printf("enter either 1 or 2");
											       goto label13;
									       }
								       }
							       }
							       if(j==addressBook->contactCount)
							       {
								       strcpy(addressBook->contacts[index-1].phone,edit);
								       printf("phone number edited successfully\n");
							       }
						       }

					       }
				       }
				       break;






				case 3:
label14:
				       printf("enter email to edit : ");
				       scanf(" %[^\n]",edit);
				       if((strstr(edit,"@")!=NULL)&&(strstr(edit,".com")!=NULL))
				       {
						       strcpy(addressBook->contacts[index-1].email,edit);
						       printf("email edited successfully");
				       }
				       else
				       {
label15:
					       printf("1.re-enter mail id\n");
					       printf("2.exit\n");
					       int c;
					       scanf("%d",&c);
					       switch(c)
					       {
						       case 1:goto label14;
						       case 2:return;
						       default:printf("enter either 1 or 2 \n");
							       goto label15;
							       break;
					       }
				       }
				       break;
				default:printf("enter either 1 or 2 or 3");
					goto label10;
			}
			break;



		case 3:
			printf("enter email id :\n");
			scanf(" %[^\n]",input);
			for(int i=0;i<addressBook->contactCount;i++)
			{
				if(strstr(addressBook->contacts[i].email,input)!=NULL)
				{
					printf("%d  %s  %s  %s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
					count=1;
				}
			}
			if(count==0)
			{
				printf("data not found\n");
				return;
			}
label20:
			printf("enter which position to edit : ");
			scanf("%d",&index);
			printf("1.by name\n");
			printf("2.by phone number\n");
			printf("3.by emial\n");
			int a2;
			scanf("%d",&a2);
			switch(a2)
			{
				case 1:printf("enter name to edit : ");
				       scanf(" %[^\n]",edit);
				       printf("edit position\n");
					       strcpy(addressBook->contacts[index-1].name,edit);
					       printf("name edited successflly\n");
				       break;
				case 2:
label21:
				       printf("enter phone number to edit : ");
				       scanf(" %[^\n]",edit);
				       int phonelen=0;
				       for(int i=0;edit[i];i++)
				       {
					       phonelen++;
				       }
				       if(phonelen==10)
				       {
					       int i=0;
					       while(edit[i])
					       {
						       if(edit[i]>='0'&&edit[i]<='9')
						       {
							       i++;
						       }
						       else
						       {
label22:
							       printf("1.re-enter the number \n");
							       printf("2.exit\n");
							       int b;
							       scanf("%d",&b);
							       switch(b)
							       {
								       case 1:goto label21;
								       case 2:return;
								       default:printf("enter either 1 or 2");
									       goto label22;
							       }
						       }
						       if(edit[i]!='\0')
						       {
							       int j;
							       for(j=0;j<addressBook->contactCount;j++)
							       {
								       if(strstr(addressBook->contacts[j].name,edit)!=NULL)
								       {
label23:
									       printf("1.re-enter the number\n");
									       printf("2.exit\n");
									       int c;
									       scanf("%d",&c);
									       switch(c)
									       {
										       case 1:goto label1;
										       case 2:return;
										       default:printf("enter either 1 or 2");
											       goto label23;
									       }
								       }
							       }
							       if(j==addressBook->contactCount)
							       {
								       strcpy(addressBook->contacts[index-1].phone,edit);
								       printf("phone edited successfully\n");
							       }
						       }

					       }
				       }
				       break;






				case 3:
label24:
				       printf("enter email to edit : ");
				       scanf(" %[^\n]",edit);
				       if((strstr(edit,"@")!=NULL)&&(strstr(edit,".com")!=NULL))
				       {
						       strcpy(addressBook->contacts[index-1].email,edit);
						       printf("email edited successfully");
				       }
				       else
				       {
label25:
					       printf("1.re-enter mail id\n");
					       printf("2.exit\n");
					       int c;
					       scanf("%d",&c);
					       switch(c)
					       {
						       case 1:goto label24;
						       case 2:return;
						       default:printf("enter either 1 or 2 \n");
							       goto label25;
							       break;
					       }
				       }
				       break;
				default:printf("enter either 1 or 2 or 3");
					goto label20;
			}
			break;

		default:printf("1.re-enter the option\n");
			printf("2.exit\n");
			int n;
			scanf("%d",&n);
			switch(n)
			{
				case 1:goto label1;
				case 2:return;
				default:printf("enter either 1 or 2");
			}
	}
}
//delete the contact from addressbook
void deleteContact(AddressBook *addressBook)
{
label1:	printf("Choose which data to give\n");
	printf("1.Name\n");
	printf("2.Mobileno\n");
	printf("3.eMailid\n");
	int ch,fact=0,n,j;
	char search[30];
	printf("Enter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("Enter Search Name:");
			scanf(" %[^\n]",search);
			printf("\n");
			for(int i=0;i<addressBook->contactCount;i++)
			{
				if(strstr(addressBook->contacts[i].name,search)!=NULL)
				{
					printf("[%d] %-18s%-15s%-20s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
					fact=1;
				}
			}
			if(fact==0)
			{
				printf("Given Name is not found\n");
				return;
			}
label2:			printf("\nEnter which index data you want to delete:");
			scanf("%d",&n);
			if(n<=addressBook->contactCount)
			{
				if(strstr(addressBook->contacts[n-1].name,search)!=NULL)
				{
					for(j=n-1;j<addressBook->contactCount;j++)
					{
						addressBook->contacts[j]=addressBook->contacts[j+1];
					}
					if(j==addressBook->contactCount)
					{
						printf("\n%d index contact Deleted succesfully!\n",n);
						addressBook->contactCount--;
					}
				}
				else
				{
					printf("\nInvalid index value!\n");
					int ch;
label3:				        printf("1.Re-enter index\n");
					printf("2.Exit\n");
					printf("Enter your choice:");
					scanf("%d",&ch);
					switch(ch)
					{
						case 1:
							goto label2;
							break;
						case 2:
							return;
						default:
							printf("Invalid choice!\n");
							goto label3;
					}
				}
			}
			else
			{
				printf("Invalid Index!\n");
			}
			break;
		case 2:
			printf("Enter Search Mobileno:");
			scanf(" %[^\n]",search);
			printf("\n");
			for(int i=0;i<addressBook->contactCount;i++)
			{
				if(strstr(addressBook->contacts[i].phone,search)!=NULL)
				{
					printf("[%d] %-18s%-15s%-20s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
					fact=1;
				}
			}
			if(fact==0)
			{
				printf("Given Mobileno is not found\n");
				return;
			}
label4:			printf("\nEnter which index data you want to delete:");
			scanf("%d",&n);
			if(n<=addressBook->contactCount)
			{
				if(strstr(addressBook->contacts[n-1].phone,search)!=NULL)
				{
					for(j=n-1;j<addressBook->contactCount;j++)
					{
						addressBook->contacts[j]=addressBook->contacts[j+1];
					}
					if(j==addressBook->contactCount)
					{
						printf("\n%d index contact Deleted succesfully!\n",n);
						addressBook->contactCount--;
					}
				}
				else
				{
					printf("\nInvalid index value!\n");
					int ch;
label5:                                 printf("1.Re-enter index\n");
					printf("2.Exit\n");
					printf("Enter your choice:");
					scanf("%d",&ch);
					switch(ch)
					{
						case 1:
							goto label4;
							break;
						case 2:
							return;
						default:
							printf("Invalid choice!\n");
							goto label5;
					}
				}
			}
			else
			{
				printf("Invalid Index!\n");
			}
			break;
		case 3:
			printf("Enter Search Mailid:");
			scanf(" %[^\n]",search);
			printf("\n");
			for(int i=0;i<addressBook->contactCount;i++)
			{
				if(strstr(addressBook->contacts[i].email,search)!=NULL)
				{
					printf("[%d] %-18s%-15s%-20s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
					fact=1;
				}
			}
			if(fact==0)
			{
				printf("Given Mailid is not found\n");
				return;
			}
label6:			printf("\nEnter which index data you want to delete:");
			scanf("%d",&n);
			if(n<=addressBook->contactCount)
			{
				if(strstr(addressBook->contacts[n-1].email,search)!=NULL)
				{
					for(j=n-1;j<addressBook->contactCount;j++)
					{
						addressBook->contacts[j]=addressBook->contacts[j+1];
					}
					if(j==addressBook->contactCount)
					{
						printf("\n%d index contact Deleted succesfully!\n",n);
						addressBook->contactCount--;
					}
				}
				else
				{
					printf("\nInvalid index value!\n");
					int ch;
label7:                                 printf("1.Re-enter index\n");
					printf("2.Exit\n");
					printf("Enter your choice:");
					scanf("%d",&ch);
					switch(ch)
					{
						case 1:
							goto label6;
							break;
						case 2:
							return;
						default:
							printf("Invalid choice!\n");
							goto label7;
					}
				}
			}
			else
			{
				printf("Invalid Index!\n");
			}
			break;
		default:
label8:			printf("Invalid choice!\n");
			printf("1.Re-enter\n");
			printf("2.Exit\n");
			int ch;
			printf("Enter your choice:");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					goto label1;
					break;
				case 2:
					return;
				default:
					goto label8;
			}
	}
}
//saving the contacts into addressbook
void saveContactsToFile(AddressBook *addressBook)
{
	FILE *fptr;
	fptr=fopen("contacts.csv","w");
	fprintf(fptr,"%d\n",addressBook->contactCount);
	for(int i=0;i<addressBook->contactCount;i++)
	{
		fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
	}
	fclose(fptr);
}
