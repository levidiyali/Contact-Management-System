#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct contact{
	char name[50];
	char phone[20];
	char email[50];
	char address[100];
}con[100];

int count = 0;

void AddContact();
void UpdateContact();
void ViewContact();
void DelContact();
void SearchContact();
void SaveToFile();
void LoadToFile();


int main(){
	LoadToFile();
	int choice;
	do{
	printf("==============================================\n");
	printf("\t Contact Management System\n");
	printf("==============================================\n");
	
	printf("Menu:\n");
	printf("1. Add Contact\n");
	printf("2. Update Existing Contact\n");
	printf("3. View Contact\n");
	printf("4. Delete Contact\n");
	printf("5. Search Contact\n");
	printf("6. Exit\n");
	printf("\n");
	printf("Please enter your choice:");
	scanf("%d", &choice);
	getchar();
	
	printf("\n");
	
	switch(choice){
		case 1: AddContact(); break;
		case 2: UpdateContact(); break;
		case 3: ViewContact(); break;
		case 4: DelContact(); break;
		case 5: SearchContact(); break;
		case 6: printf("Exiting program...\n"); break;
		
		default:
			printf("Invalid Choice!");
			}
		}while(choice != 6); 
	
	return 0; 
}

void SaveToFile(){
	FILE *fp = fopen("record.txt", "w");
	
	if (fp == NULL){
		printf("Error opening file...\n");
		return;
	}
	int i;
	for(i=0 ; i<count ; i++){
		fprintf(fp, "%s\n%s\n%s\n%s\n", con[i].name, con[i].phone, con[i].email, con[i].address);
    }
	
	fclose(fp);
}

void LoadToFile(){
	FILE *fp = fopen("record.txt", "r");
	if(fp == NULL){
		printf("Please create a file\n");
		return;
	}
	
	count=0;
	while(fgets(con[count].name, sizeof(con[count].name),fp)){
		con[count].name[strcspn(con[count].name, "\n")] = 0;
		
		fgets(con[count].phone, sizeof(con[count].phone), fp);
		con[count].phone[strcspn(con[count].phone, "\n")] = 0;
		
		fgets(con[count].email, sizeof(con[count].email), fp);
		con[count].email[strcspn(con[count].email, "\n")] = 0;
		
		fgets(con[count].address, sizeof(con[count].address), fp);
		con[count].address[strcspn(con[count].address, "\n")] = 0;
		
		count++;
	}
	
	fclose(fp);
}

void AddContact(){
	if(count >= 100){
		printf("Your Contact List Is Full...\n");
		return;
	}
	printf("-----------------------------------------------\n");
	printf("Adding details:\n");
	printf("\n");
	printf("Enter Name:");
	fgets(con[count].name, sizeof(con[count].name), stdin);
	con[count].name [strcspn(con[count].name , "\n")] = 0;
	
	printf("Enter Phone Number:");
	fgets(con[count].phone, sizeof(con[count].phone), stdin);
	con[count].phone [strcspn(con[count].phone, "\n")] = 0;
	
	printf("Enter Email:");
	fgets(con[count].email, sizeof(con[count].email), stdin);
	con[count].email [strcspn(con[count].email, "\n")] = 0;
	
	printf("Enter Address:");
	fgets(con[count].address, sizeof(con[count].address), stdin);
	con[count].address [strcspn(con[count].address, "\n")] = 0;
	
	count++;
	printf("\n");
	printf("Contact Successfully Added...\n");
	printf("\n");
	
	printf("-----------------------------------------------\n");
	
	SaveToFile();
	printf("\n");
}

void UpdateContact(){
	if(count == 0){
		printf("Error displaying contacts...\n");
		return;
	}
	
	ViewContact();
	int index, choice;
	printf("Enter the number of contact to update:");
	scanf("%d", &index);
	getchar();
	
	index--;
	
	if(index < 0 || index >=count){
		printf("Invalid Choice...\n");
		return;
	}
	
	printf("What do you want to update?\n");
	printf("1. Name\n");
	printf("2. Phone Number\n");
	printf("3. Email\n");
	printf("4. Address\n");
	printf("5. Exit\n");
	printf("\n");
	printf("Enter your choice:");
	scanf("%d", &choice);
	getchar();
	
	if(choice == 1){
		printf("Enter New Name : ");
		fgets(con[index].name, sizeof(con[index].name), stdin);
		con[index].name[strcspn(con[index].name , "\n")] = 0;
	}
	
	else if(choice == 2){
		printf("Enter New Phone Number : ");
		fgets(con[index].phone, sizeof(con[index].phone), stdin);
		con[index].phone[strcspn(con[index].phone , "\n")] = 0;
	}
	
	else if(choice == 3){
		printf("Enter New Email : ");
		fgets(con[index].email, sizeof(con[index].email), stdin);
		con[index].email[strcspn(con[index].email , "\n")] = 0;
	}
	
	else if(choice == 4){
		printf("Enter New Address : ");
		fgets(con[index].address, sizeof(con[index].address), stdin);
		con[index].address[strcspn(con[index].address , "\n")] = 0;
	}
	
	else if(choice == 5){
		printf("Exiting...\n");
		return;
	}
	
	else{
		printf("Invalid Option...\n");
		return;
	}
	
	SaveToFile();
	printf("Contact Updated Successfully...\n");
	
}

void ViewContact(){
	if(count == 0){
		printf("You have no contacts saved...\n");
		return;
	}
	
	printf("-----------------------------------------------\n");
	printf("Saved Contacts:\n");
	printf("\n");
	int i;
	for(i=0 ; i<count ; i++){
		printf("%d. %s\n", i+1, con[i].name);
		printf("Phone Number : %s\n", con[i].phone);
		printf("Email : %s\n", con[i].email);
		printf("Address is %s\n", con[i].address);
		printf("\n");
	}
	printf("-----------------------------------------------\n");
	printf("\n");
}

void DelContact(){
	if(count == 0){
		printf("No contants to delete...\n");
		return;
	}
	
	int index;
	ViewContact();
	printf("Enter the number you want to delete:");
	scanf("%d", &index);
	getchar();
	
	if(index < 1 || index>count){
		printf("Invalid number...");
		return;
	}
	int i;
	for(i = index-1 ; i < count-1 ; i++){
		con[i]=con[i+1];
	}
	count--;
	
	SaveToFile();
	printf("Contact Deleted Successfully\n");
	printf("-----------------------------------------------\n");
}

void SearchContact(){
	char SearchName[50];
	printf("==============================================\n");
	printf("Enter the name you want to search:");
	fgets(SearchName, sizeof(SearchName), stdin);
	SearchName[strcspn(SearchName, "\n")] = 0;
	
	int found = 0;
	int i;
	for (i = 0 ; i < count ; i++){
		if (strcmp(con[i].name, SearchName)==0){
			printf("Contact Found! \n");
			printf("\n");
			printf("Name : %s\n", con[i].name);
			printf("Phone Number : %s\n", con[i].phone);
			printf("Email : %s\n", con[i].email);
			printf("Address : %s\n", con[i].address);
			found = 1;
			break;
		}
	}
	 	
	 	if (!found){
	 		printf("Contact not found...\n");
		 }
	printf("-----------------------------------------------\n");
}
