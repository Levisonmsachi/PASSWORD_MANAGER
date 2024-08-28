#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void getPassword(char *password);
void menu(void);
void help(void);
void addPassword(void);
void viewPassword(void);
void createAccount(void);

// A SIMPLE PASSWORD MANAGER PROGRAM DEVELOPED BY LEVVY LIVVIE
// NOTE: COPYING OR EDITING THIS CODE IS STRICTLY PROHIBITED
// @LEVVY LIVVIE 2024

int main(void){
	system("cls");
	char password[20], confirmPassword[20];
	menu();
	
	return 0;
}

/*############################## MAIN MENU FUNCTION #############################*/
void menu(void){
	system("cls");
	char words[65] = "================WELCOME TO PASSWORD MANAGER=================";
	
	one:
	for(int i = 0; i < 60; i ++){
		printf("%c", words[i]);
		Sleep(30);
	}
	
	printf("%s", "\n");
	
	printf("%s", "\t 1 CREATE PASSWORD MANAGER ACCOUNT \n \t 2. ADD PASSWORD TO YOUR PASSWORD MANAGER \n \t 3. VIEW YOUR PASSWORDS \n \t 4. HELP \n");
	
	int choice = 0;
	printf("%s", "======================================================================\n\n");
	
	start:
	printf("%s", "Enter your choice: ");
	if( scanf("%d", &choice) != 1){
		printf("%s", "Error! Please enter a number. Try again. \n\n");
		while(getchar() != '\n');
		goto start;
	}
	
	if(choice < 1 || choice > 4){
		printf("%s", "\nError! Invalid choice. Please enter a correct choice number. \n\n");
		while(getchar() != '\n');
		goto start;
	}
	
	while(getchar() != '\n'); //clear new line character left by scanf
	
	switch(choice){
		case 1:
			createAccount();
			break;
			
		case 2:
			addPassword();
			break;
			
		case 3:
			viewPassword();
			break;
			
		case 4:
			help();
			break;
			
		default:
			printf("%s", "\nOops! Something went wrong. Try again. \n\n");
			while(getchar() != '\n');
			goto one;
	}
}

/* ################################ ADD PASSWORD FUNCTION ######################################*/
void addPassword(void){
	system("cls");
	printf("%s", "\n======================== ADD PASSWORD MENU ==================================\n\n");
	char userName[50], password[50], content[50], new_password[500];
	int line_number = 0, target_line = 2;
	FILE* file;
	
	start:
	printf("%s", "Enter your user name: ");
	fgets(userName, sizeof(userName), stdin);
	userName[strcspn(userName, "\n")] = 0;
	
	char a[500];
	strcpy(a, userName);
	strcat(a, ".txt");
	
	file = fopen(a, "r");
	
	if(file == NULL){
		printf("%s", "\nError! User name not defined. Enter a correct user name. \n\n");
		goto start;
	}
	
	fclose(file);
	
	pp:
	printf("%s", "Enter your password: ");
	getPassword(password);
	password[strcspn(password, "\n")] = 0;
	
	file = fopen(a, "r");
	while(fgets(content, sizeof(content), file)){
		line_number ++;
		
		if(line_number == target_line){
			break;
		}
	}
	
	fclose(file);
	
	content[strcspn(content, "\n")] = 0;
	
	int result = strcmp(password, content);
	
	if(result != 0){
		printf("%s", "\nError! Wrong password. Please enter a correct password. \n\n");
		goto pp;
	}
	
	else{
		ll:
		printf("%s", "\nHow many passwords do you want to add: ");
		int number = 0;
		if(scanf("%d", &number) != 1){
			printf("%s", "\nError! Please enter a number. Try again. \n\n");
			while(getchar() != '\n');
			goto ll;
		}
		
		else if(number < 0){
			printf("%s", "\nSorry! You cannot add %d passwords. Please enter a higher number. \n\n", number);
			while(getchar() != '\n');
			goto ll;
		}
		
		else{
			while(getchar() != '\n');
			printf("%s", "\nLETS GET STARTED THEN: \n");
			for(int i = 1; i <= number; i ++){
				printf("\nEnter password %d that you want to add: ", i);
				fgets(new_password, sizeof(new_password), stdin);
				new_password[strcspn(new_password, "\n")] = 0;
				
				FILE* file;
				
				file = fopen(a, "a");
				
				if(a == NULL){
					printf("%s", "\nOops! file not found. Please enter a correct user name and password. \n\n");
					goto start;
				}
				
				else{
					fprintf(file, "\n%s", new_password);
				}
			}
		}
		
		fclose(file);
		
		rr:
		printf("%s", "\n\nHello there! You have reached the number of passwords that you wanted to add. \n");
		printf("%s", "Do you want to add more passwords? If yes: \n");
		printf("%s", "(Enter 1 to add more passwords or 2 to view passwords or 3 to exit the program): ");
		int an = 0;
		if(scanf("%d", &an) != 1){
			printf("%s", "\nError! Please enter a number. Try again. \n\n");
			while(getchar() != '\n');
			goto rr;
		}
		
		if(an < 1 || an > 3){
			printf("%s", "\nError! Invalid choice. Enter a correct choice number. \n\n");
			while(getchar() != '\n');
			goto rr;
		}
		
		switch(an){
			case 1:
				printf("%s", "\n\n");
				goto ll;
				break;
				
			case 2:
				printf("%s", "\n");
				viewPassword();
				break;
				
			case 3:
				printf("%s", "\nGlad you were here. Hope you will be back. Goodbye!!! \n\n");
				exit(0);
				break;
				
			default:
				printf("%s", "\nOops! Something went wrong. Exiting........ \n\n");
				break;
		}
	}
	
	
}

/* ############################### VIEW PASSWORD FUNCTION ##################################### */
void viewPassword(void){
	system("cls");
	printf("%s", "\n=======================VIEW YOUR PASSWORD MENU===================================\n\n");
	char password[20], userName[50], content[500], saved_password[500];
	int line_number = 0, target_line = 2;
	FILE* file;
	
	start:
	printf("%s", "Enter your user name: ");
	fgets(userName, sizeof(userName), stdin);
	userName[strcspn(userName, "\n")] = 0;
	
	char a[500];
	strcpy(a, userName);
	strcat(a, ".txt");
	
	file = fopen(a, "r");
	
	if(file == NULL){
		printf("%s", "\nError! User name not defined. Enter a correct user name. \n\n");
		goto start;
	}
	
	fclose(file);
	
	pp:
	printf("%s", "Enter your password: ");
	getPassword(password);
	//fgets(password, sizeof(password), stdin);
	password[strcspn(password, "\n")] = 0;
	
	file = fopen(a, "r");
	while(fgets(content, sizeof(content), file)){
		line_number ++;
		
		if(line_number == target_line){
			break;
		}
	}
	
	fclose(file);
	
	content[strcspn(content, "\n")] = 0;
	
	int result = strcmp(password, content);
	
	if(result != 0){
		printf("%s", "\nError! Wrong password. Please enter a correct password. \n\n");
		goto pp;
	}
	
	
	printf("%s", "\nDISPLAYING YOUR SAVED PASSWORDS. PLEASE WAIT");
	char dot[8] = ".......";
	for(int i = 0; i < 8; i ++){
		printf("%c", dot[i]);
		Sleep(170);
	}
	
	printf("%s", "\n\n============================ YOUR SAVED PASSWORDS ============================= \n");
	
	file = fopen(a, "r");
	while(fgets(saved_password, sizeof(saved_password), file)){
		printf("%s", saved_password);
	}
	
	
	printf("%s", "\n======================= THE END OF YOUR SAVED PASSWORDS =========================== \n\n");
	
	cc:
	printf("%s", "\nWould you like to go to the main menu? \nEnter 1 to go to main menu or 2 to quit: ");
	int choice = 0;
	if(scanf("%d", &choice) != 1){
		printf("%s", "\nError! Please enter a number. Try again. \n\n");
		while(getchar() != '\n');
		goto cc;
	}
	
	else if(choice < 1 || choice > 2){
		printf("%s", "Invalid choice. Please enter a correct choice number. \n\n");
		while(getchar() != '\n');
		goto cc;
	}
	
	else{
		switch(choice){
			case 1:
				menu();
				break;
				
			case 2:
				printf("\n\n%s", "\t\t\tEXITING PASSWORD MANAGER PROGRAM. PLEASE WAIT");
				
				char d[8] = ".......";
				for(int i = 0; i < 8; i ++){
					printf("%c", d[i]);
					Sleep(200);
				}
				
				printf("%s", "\n\n");
				
				exit(0);
				break;
				
			default:
				printf("%s", "\nOops! Something went wrong. \nRedirecting you to main menu. \n\n");
				
				char ddd[8] = ".......";
				printf("%s", "LOADING PLEASE WAIT");
				
				for(int i = 0; i < 8; i ++){
					printf("%c", ddd[i]);
					Sleep(200);
				}
				
				printf("%s", "\n\n");
				menu();
				break;
		}
	}
}

/* ################################# HELP MENU FUNCTION ######################################## */
void help(void){
	system("cls");
	printf("%s", "\n============================== HELP MENU ==================================== \n\n");
	
	printf("%s", "What problem are you facing? Please choose your problem on the list below. \n");
	
	printf("%s", "\n========================== SUGGESTED USER PROBLEMS ============================= \n");
	printf("%s", "\t 1. Forgot password \n\t 2. Not all passwords showing \n\t 3. Forgot user name \n");
	printf("%s", "================================================================================ \n");
	
	printf("%s", "If your problem is not listed here. Please contact us via email: levisonmsachi03@gmail.com \n\n");
	
	start:
	printf("%s", "Enter your problem number: ");
	int problem = 0;
	if(scanf("%d", &problem) != 1){
		printf("%s", "Error! Invalid entry. Please enter a number. \n\n");
		while(getchar() != '\n');
		goto start;
	}
	
	if(problem < 1 || problem > 3){
		printf("%s", "\nOops! Wrong choice. Try again. \n\n");
		while(getchar() != '\n');
		goto start;
	}
	
	if(problem == 1){
		printf("%s", "\nYour password was sent via the email you used when opening the account. Thank you. \n\n");
		exit(0);
	}
	
	else if(problem == 2){
		printf("%s", "\nPlease login again. And all Your passwords will be displayed. Thank you. \n\n");
		exit(0);
	}
	
	else if(problem == 3){
		printf("%s", "\nContact us via email @: levisonmsachi03@gmail. \n");
		printf("%s", "Please include your email you used when creating your account. and your password if you can remeber. \n");
		printf("%s", "We will send your creadentials via the email you used when creating your account. \n");
		printf("%s", "Thank you for your patience and understanding. We will get back to you shortly. \n\n");
		exit(0);
	
	}
	
	else{
		printf("%s", "Oops! Something went wrong. Exiting the program............... \n\n");
		exit(0);
	}
	
}

/* ################################# CREATE ACCOUNT FUNCTION #################################### */
void createAccount(void){
	system("cls");
	printf("%s", "\n\n=============WELCOME TO PASSWORD MANAGER PROGRAM. A PERFECT PLACE TO STORE YOUR PASSWORDS!=========== \n\n");
	printf("%s", "\t\t\tRemember one password to unlock all passwords!!!!! \n\n");
	
	char userName[50], password[50], confirmPassword[50], email[70];
	
	scanf("");
	printf("%s", "Enter your user name: ");
	fgets(userName, sizeof(userName), stdin);
	userName[strcspn(userName, "\n")] = 0;
	
	printf("%s", "Enter your email address: ");
	fgets(email, sizeof(email), stdin);
	email[strcspn(email, "\n")] = 0;
	
	while(1){
		printf("%s", "Enter your password: ");
		getPassword(password);
		
		if(strlen(password) == 0){
			printf("%s", "\nError! Password cant be null. Please try again. \n\n");
			continue;
		}
		
		else if(strlen(password) < 5){
			printf("%s", "\nOops! Password too short. Try again. \n\n");
			continue;
		}
		
		printf("%s", "Confirm your password: ");
		getPassword(confirmPassword);
		
		if(strcmp(password, confirmPassword) == 0){
			printf("%s", "\nPassword confirmed successfully! \n\n");
			
			printf("%s", "CREATING ACCOUNT PLEASE WAIT");
			char dd[8] = ".......";
			for(int i = 0; i < 8; i ++){
				printf("%c", dd[i]);
				Sleep(200);
			}
			
			break;
		}
		
		else{
			printf("%s", "\nOops! Passwords do not match. Please try again. \n\n");
		}
	}
	
	FILE* file;
	char a[100];
	
	strcpy(a, userName);
	strcat(a, ".txt");
	
	file = fopen(a, "a");
	
	if(file == NULL){
		printf("%s", "\nErro! File not created! \n\n");
	}
	
	else{
		fprintf(file, "%s\n", userName);
	    fprintf(file, "%s\n", password);
	    fprintf(file, "%s\n", email);
	}
	
	fclose(file);
	
	printf("%s", "\n");
	
	menu();
}

/* ########### GET PASSWORD FUNCTION(HIDES PASSWORD WHEN TYPING) ############# */
void getPassword(char *password){
	int index = 0;
	char ch;
	
	while( (ch = _getch()) != '\r'){
		if(ch == '\b'){
			if(index > 0){
				index --;
				printf("\b \b");
			}
		}
		
		else if(index < 20){
			password[index ++] = ch;
			printf("*");
		}
	}
	
	password[index] = '\0';
	printf("%s", "\n");
}