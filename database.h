/*====================================================
				Header Database
					WKJEK
					
	By Irfan Budi Satria
=====================================================*/

#ifndef DATABASE_H
#define DATABASE_H

typedef struct
{
    char name[30];
    double latitude;
    double longitude;
}city;

typedef struct{
    char name[50];
    char password[50];
}User;

typedef struct
{
    char name[30];
    char platenum[30];
    char bike[30];
    
}driver;

typedef struct{
    float jarak;
    float biaya;
    int paymentmethod;
    
    char origin[30];
    char destination[30];
    
//    Ticket next; 
}Ticket;



#endif

