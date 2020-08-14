#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct Node
{	
	char transport[30];
	char firstName[30];
	char familyName[30];
	int age;
	char group[30];
	struct Node *structPtr;
};

typedef struct Node passanger;
//--------------------
void listprint(passanger *);
void addElemToTheEnd(passanger *);
void createNewNode(passanger *, passanger);
int valid();
passanger enter();




//--------------------

int main (void) {
  
 	int counter = 0, controller = 1, n = 2, k = 1, answer = 1, router = 0, router1 = 0;
 	char tempStr[30];
	passanger * head, *tempPointer, *tempEndPointer, *nextPtr;
	passanger temp;
	FILE *file;
	
	//CREATING LINKED LIST TO WORK WITH
	if ((file = fopen("base.txt", "r")) == NULL) printf("file could not be opened for reading");
	else {

		
		while (fscanf (file, "%s%s%s%d%s", temp.transport,temp.firstName,temp.familyName, &(temp.age) ,temp.group) != EOF) {

			if (counter == 0) {
				head = (passanger *)malloc(sizeof(passanger));
				strcpy(head->transport, temp.transport);
				strcpy(head->firstName, temp.firstName);
				head->age = temp.age;
				strcpy(head->familyName, temp.familyName);
				strcpy(head->group, temp.group);
				head->structPtr = NULL;
				tempPointer = head;
				counter = 1;
			} else {
				createNewNode(tempPointer, temp);
				tempPointer = tempPointer->structPtr;
			}	

		}
		
		fclose(file);
	}

	//ROUTING USERS CHOICE
	while (answer != 0) {
		system("cls");
		printf("enter:\n1)to add passanger\n2)to delete passanger\n3)to view whole list\n4)to view one passanger\n5)to view info about group of passangers\n-> ");
		router = valid();

		while (router != 1 && router != 2 && router != 3 && router != 4 && router != 5) {
			printf("\ntry again\n-> ");
			router = valid();
		}

		if (router == 1) { //adding element to the end of the list
			
			tempPointer = head;
			while (tempPointer != NULL) {
				tempEndPointer = tempPointer;
				tempPointer = tempPointer->structPtr;
			}

			while (k < n){
					system("cls");
		            addElemToTheEnd(tempEndPointer);
		            tempEndPointer = tempEndPointer->structPtr;
		            printf("\nwant to continue entering list? 0 - no, else yes: ");
		            controller = valid();
		           if (controller != 0) {
		                n++;
		            }
		            k++;
        	}

		} else if (router == 2) { //deleting element from the list
			system("cls");
			tempPointer = NULL;
		    nextPtr = head;
		    printf("enter first name of passanger you want to delete: ");
		    scanf("%s", tempStr);

		    controller = 0;
		    while (nextPtr != NULL) {

		    	if (strcmp(tempStr, nextPtr->firstName) == 0) {
					tempPointer->structPtr = nextPtr->structPtr;
					free(nextPtr);		
		    		controller = 1;
		    		break;
		    	}
		    	tempPointer = nextPtr;
		    	nextPtr = nextPtr->structPtr;
		    }

		    if (controller == 0) printf("NO SUCH PASSANGER!\n");

		} else if (router == 3) { //printing out whole list of data
			system("cls");
			printf("LIST:\n");
			listprint(head);

		} else if (router == 4) { //viewing one passanger
			system("cls");
			printf("enter first name of passanger you want to view: ");
		    scanf("%s", tempStr);
		    tempPointer = head;
		    controller = 0;
		    while (tempPointer != NULL) {

		    	if (strcmp(tempStr, tempPointer->firstName) == 0) {
					printf("transport:%s  name:%s  family name:%s  age:%d  group:%s \n", tempPointer->transport,tempPointer->firstName,tempPointer->familyName, tempPointer->age, tempPointer->group); 
		    		controller = 1;
		    		break;
		    	}
		    	tempPointer = tempPointer->structPtr;
		    }

		    if (controller == 0) printf("NO SUCH PASSANGER!\n");

		} else if (router == 5) {
			system("cls");
			printf("choose group of passanger:\n1)pensioner\n2)veteran\n3)invalid\n4)none\n-> ");
			router1 = valid();
			while (router1 != 1 && router1 != 2 && router1 != 3 && router1 != 4) {
					printf("\ntry again\n-> ");
					router1 = valid();
				}

			tempPointer = head;
			while (tempPointer != NULL) {

				if (router1 == 1) {
					if (strcmp("pensioner", tempPointer->group) == 0) {
					printf("transport:%s  name:%s  family name:%s  age:%d  group:%s \n", tempPointer->transport,tempPointer->firstName,tempPointer->familyName, tempPointer->age, tempPointer->group); 
		    		controller = 1;
		    		break;
		    		}
		    	
				} else if (router1 == 2) {
					if (strcmp("veteran", tempPointer->group) == 0) {
					printf("transport:%s  name:%s  family name:%s  age:%d  group:%s \n", tempPointer->transport,tempPointer->firstName,tempPointer->familyName, tempPointer->age, tempPointer->group); 
		    		controller = 1;
		    		break;
		    		}


				}else if (router1 == 3) {
					if (strcmp("invalid", tempPointer->group) == 0) {
					printf("transport:%s  name:%s  family name:%s  age:%d  group:%s \n", tempPointer->transport,tempPointer->firstName,tempPointer->familyName, tempPointer->age, tempPointer->group); 
		    		controller = 1;
		    		break;
		    		}
				}
				else if (router1 == 4) {
					if (strcmp("none", tempPointer->group) == 0) {
					printf("transport:%s  name:%s  family name:%s  age:%d  group:%s \n", tempPointer->transport,tempPointer->firstName,tempPointer->familyName, tempPointer->age, tempPointer->group); 
		    		controller = 1;
		    		break;
		    		}
				}
				tempPointer = tempPointer->structPtr;
			}	

			
		}

		//adding changes to the file

		tempPointer = head;
	    if ((file = fopen("base.txt", "w")) == NULL) printf("file could not be opened for appending\n");
	    else {
	    	while (tempPointer != NULL) {
	    		fprintf(file , "%s %s %s %d %s\n", tempPointer->transport,tempPointer->firstName,tempPointer->familyName,tempPointer->age,tempPointer->group);
	    		tempPointer = tempPointer->structPtr;
	    	}
	    	fclose(file);
	    }

	    //asking for continuation
		printf("\n\nwant to continue? 1 - yes, 0 - no: ");
  		answer = valid();
  		printf("\n");


	}
	
  return 0;
}


//--------------------


void listprint(passanger *head)
{
  passanger *p;
  p = head;
  do {
    printf("transport:%s  name:%s  family name:%s  age:%d  group:%s \n", 
    	p->transport,p->firstName,p->familyName, p->age, p->group); 
    p = p->structPtr; 
  } while (p != NULL);
}


void addElemToTheEnd(passanger *lst)
{
 

  	passanger *temp;
  	passanger otherTemp;
  	otherTemp = enter();

  	temp = (passanger*)malloc(sizeof(passanger));

	strcpy(temp->transport,otherTemp.transport);

	strcpy(temp->firstName,otherTemp.firstName);

	strcpy(temp->familyName,otherTemp.familyName);

	temp->age = otherTemp.age;

	strcpy(temp->group,otherTemp.group);

	lst->structPtr = temp; 
 
  	temp->structPtr = NULL;
  
}

void createNewNode(passanger *lst, passanger otherTemp){
	
	passanger *temp;
  	temp = (passanger*)malloc(sizeof(passanger));

	strcpy(temp->transport,otherTemp.transport);

	strcpy(temp->firstName,otherTemp.firstName);

	strcpy(temp->familyName,otherTemp.familyName);

	temp->age = otherTemp.age;

	strcpy(temp->group,otherTemp.group);

  lst->structPtr = temp; 
 
  temp->structPtr = NULL;
}


passanger enter() {

	passanger temp;
	char tempStr[29];
	int tempAge, router;

	printf("choose transport of passanger:\n1)metro\n2)minibus\n3)tram\n-> ");
	router = valid();
	while (router != 1 && router != 2 && router != 3) {
			printf("\ntry again\n-> ");
			router = valid();
		}
	if (router == 1) {
		strcpy(temp.transport, "metro");
	} else if (router == 2) {
		strcpy(temp.transport,"minibus");
	}else if (router == 3) {
		strcpy(temp.transport, "tram");
	}

	

	printf("enter name of passanger: ");
	scanf("%29s", tempStr);
	strcpy(temp.firstName,tempStr);

	printf("enter family name of passanger: ");
	scanf("%29s", tempStr);
	strcpy(temp.familyName,tempStr);

	printf("enter age of passanger: ");
	tempAge = valid();
	while (tempAge <= 0) {
		printf("enter positive number:\n->");
		tempAge = valid();
	}
	temp.age = tempAge;

	printf("choose group of passanger:\n1)pensioner\n2)veteran\n3)invalid\n4)none\n-> ");
	router = valid();
	while (router != 1 && router != 2 && router != 3 && router != 4) {
			printf("\ntry again\n-> ");
			router = valid();
		}
	if (router == 1) {
		strcpy(temp.group, "pensioner");
	} else if (router == 2) {
		strcpy(temp.group,"veteran");
	}else if (router == 3) {
		strcpy(temp.group, "invalid");
	}
	else if (router == 4) {
		strcpy(temp.group, "none");
	}

	temp.structPtr = NULL;
	return temp;
}


int valid() {
    int res = 0;
    int error = 0;
    char term;
    
    error = scanf("%d%c", &res, &term);
    fflush(stdin);

    while(error != 2 || term != '\n'){
      printf("enter a number, please:\n->");
      error = scanf("%d%c", &res, &term);
      fflush(stdin);
    }

    return res;
}
