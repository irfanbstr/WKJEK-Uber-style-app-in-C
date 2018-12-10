/*========================================================================================
				Proyek Algoritma dan Pemrograman (Topik : Ojek Online)
										WKJEK
										
		by Irfan Budi Satria, Nathaniel Nicholas

	In this project : main.c, database.c, database.h, gps.c, gps.h, control.c
	databases : city.dat, user.dat, driver.dat,
	images : bike.wkj
	
==========================================================================================*/

//HEADER FILE DEPENDENCIES

#include<stdio.h>
#include<string.h>
#include<time.h>
#include <math.h>

//#include "graphics.h"

#include "database.c"
#include "control.c"
#include "gps.c"

void delay(int second);
User account;
Ticket *info = NULL;

int main(){
    int pembayaran;
    int rating;
    char *input;
    info = (Ticket *)malloc(sizeof(Ticket));
    
    startup();
    Jemput(info);
    bayar(info);
    SearchDriver();
    printf("Thank you for using our app! :)");
    
}

void delay(int second){
    int milli_seconds = 1000 * second; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds); 
}
void startup(){
	char usermethod[2][10]={"Login","Sign Up"};
	char cursor[2] = {'\0','\0'};
	int option=2;
	while(code!=13)
	{
		system("cls");
		
		printf("===============================================\n");
		printf("\t\t   Welcome to \n");
		printf("	 _       ____ __    __________ __\n");
		printf("	| |     / / //_/   / / ____/ //_/\n");
		printf("	| | /| / / ,< __  / / __/ / ,<   \n");
		printf("	| |/ |/ / /| / /_/ / /___/ /| |  \n");
		printf("	|__/|__/_/ |_/____/_____/_/ |_|  \n\n");
		printf("    Oleh Irfan Budi S. dan Nathaniel Nicholas\n");
		printf("===============================================\n");
		printf("\n");
		printf("Selamat datang di aplikasi WkJek!: \n");
		
		for(int i = 0; i< option; i++)
		{
			if(i == choiceV)
			{
				printf("\033[1;32m");		//ansi code untuk warna hijau
				printf(">");
			} 
		 printf("%c %d. %s\n", cursor[i], i+1, usermethod[i]);
			
			if(i == choiceV)
				printf("\033[0m");			//kembali ke putih
		}	
	
		Controls(option,0);
		
		for(int i = 0; i< option; i++)
		{
			cursor[i] = '\0';
		}	
		
		cursor[choiceV] = '>'; 
	}
	switch(choiceV){
		case 0: {
			int check=1;
			while(check){
				printf("[LOGIN] Masukan username :");
				scanf("%s",account.name);
				printf("[LOGIN] Masukan password :");
				strcpy(account.password,inputPassword());
				check = checkuser(account);
				if(check==1){
					printf("\nWrong username or password. Try again\n");
					system("pause");
				}
			}
			break;
		}
		case 1: {
			printf("[SIGNUP] Masukan username :");
			scanf("%s",account.name);
			printf("[SIGNUP] Masukan sandi anda :");
			strcpy(account.password,inputPassword());
			insertaccount(account);
			printf("[SIGNUP] Akun berhasil dibuat!");
			break;
		}
	}
    
    
    
}
void Jemput(Ticket *info){
	city city_data[nCities];
	city origin, destination;
	
	ImportCity(city_data);
	
	/*=====================================================
		Set lokasi Penjemputan
	=======================================================*/
	
	ResetControls();
	char cursor[nCities];
	
	for(int i = 0; i< nCities; i++)
	{
		cursor[i] = '\0';
	}	

	cursor[0] = '>';
	
	while(code!=13)
	{
		system("cls");
		printf("Pilih Tempat Penjemputan: \n");
		
		for(int i = 0; i< nCities; i++)
		{
			if(i == choiceV)
			{
				printf("\033[1;32m");		//ansi code untuk warna hijau
				printf(">");
			} 
		 printf("%c %d. %s\n", cursor[i], i+1, city_data[i].name);
			
			if(i == choiceV)
				printf("\033[0m");			//kembali ke putih
		}	
	
		Controls(nCities,0);
		
		for(int i = 0; i< nCities; i++)
		{
			cursor[i] = '\0';
		}	
		
		cursor[choiceV] = '>'; 
	}
	
	printf("\nPickup Point set to %s\n\n", city_data[choiceV].name);
	origin = city_data[choiceV];
		
	for(int i = 0; i< nCities; i++)
	{
		cursor[i] = '\0';
	}	
	
	system("pause");
	
	/*=====================================================
		Set lokasi Tujuan
	=======================================================*/
	
	ResetControls();
	cursor[0] = '>';
	
	while(code!=13)
	{
		system("cls");
		printf("Pilih Tempat Penjemputan: \n");
		
		for(int i = 0; i< nCities; i++)
		{
			if(i == choiceV)
			{
				printf("\033[1;32m");		//ansi code untuk warna hijau
				printf(">");
			}
			
			printf("%c %d. %s\n", cursor[i], i+1, city_data[i].name);
			
			if(i == choiceV)
				printf("\033[0m");			//kembali ke putih
		}	
	
		Controls(nCities,0);
		
		for(int i = 0; i< nCities; i++)
		{
			cursor[i] = '\0';
		}	
		
		cursor[choiceV] = '>'; 
	}
	
	printf("\nDestination Point set to %s\n\n", city_data[choiceV].name);
	destination = city_data[choiceV];
	system("pause");
	
	system("cls");
    float dist = distance(origin.latitude, origin.longitude, destination.latitude, destination.longitude);
	printf("The range from origin to destination is %.2lfKM\n\n",dist);
	
    info->jarak = dist;
	system("pause");
	
}
void bayar(Ticket *info){
    system("cls");
	info->biaya = info->jarak * 2000;
    printf("Jarak : %.2f km\nBiaya : IDR %.2f,-\n",info->jarak,info->biaya);
    printf("Pilih metode pembayaran :\n[1] WkWkPay\n[2] Cash\nMetode Pembayaran:");
    scanf("%d",&info->paymentmethod);
}
void SearchDriver(){
	system("cls");
	
	driver myDriver;

	printf("Mencarikan Anda Driver");
	for (int i = 0; i< 30; i++)
	{
		printf(".");
		Sleep(100);
	}
	
	GetRandomDriver(&myDriver);
	printf("\n\n");
	printf("Driver ditemukan!\n");
	
	printf("Nama: %s\nPlat Nomor: %s\nModel Motor: %s\n", myDriver.name, myDriver.platenum, myDriver.bike);
}
