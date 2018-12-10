#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
#include<windows.h>

#include "database.h"

#define nCities 10
#define nDrivers 10

char* inputPassword(){

    char *pass;
    pass = malloc (sizeof (char) * 50);
    int i = 0;
    while ((pass[i] = getch()) != '\n' && pass[i] != '\r' && i < 49){
        putchar(' ');
        i++;
    }

    pass[i] = '\0';
    return pass;
}

void hitungjarak(Ticket *info){
    info->jarak = 1;
    info->biaya = 100000;
}

void insertaccount(User account){
    FILE *userfile;
    userfile = fopen("user.dat","a");
    fprintf(userfile,"%s %s ",account.name,account.password);
    fclose(userfile);
}

int checkuser(User account){
    FILE *userfile;
    userfile = fopen("user.dat","r");
    User local[20];

    int i=0;
    while (EOF != fscanf(userfile, "%s %s ", &local[i].name, &local[i].password))
    {
        i++;
    }

    fclose(userfile);

    for(int j=0;j<i;j++){
        if(strcmp(local[j].name,account.name)==0){
            if(strcmp(local[j].password,account.password)==0){
                return 0;
            }
            else return 1;
        }
    };
    return 1;
}

void GetRandomDriver(driver *mydriverdata){
	
	srand(time(NULL));   // Initialization, should only be called once.
	
	FILE *driverfile;
    int i = 0;
	int j = rand() %10;
	driver driverslist[nDrivers];
	
    driverfile = fopen("driver.dat", "r");

	if(driverfile==NULL)
    {
        printf("error: can't read file\n");
        getch();
    }
    
    while (EOF != fscanf(driverfile, "%s %s %s", &driverslist[i].name, &driverslist[i].platenum, &driverslist[i].bike))
    {
        i++;
    }
    
    strcpy(mydriverdata->name, driverslist[j].name);
    strcpy(mydriverdata->platenum, driverslist[j].platenum);
    strcpy(mydriverdata->bike, driverslist[j].bike);
    
    fclose(driverfile);
}
void ImportCity(city mycitydata[nCities])
{
    FILE *cityfile;
    int i = 0;
	
    cityfile = fopen("city.dat", "r");

	if(cityfile==NULL)
    {
        printf("error: can't read file\n");
        getch();
    }
    
    while (EOF != fscanf(cityfile, "%s %lf %lf", &mycitydata[i].name, &mycitydata[i].latitude, &mycitydata[i].longitude))
    {
        i++;
    }
    
    fclose(cityfile);
}
