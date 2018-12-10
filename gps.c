/*========================================================================================
	Program Penghitung Jarak dua tempat menggunakan koordinat latitude dan Longitude Bumi
										WKJEK
		by Irfan Budi Satria

	Notes:    South latitudes are negative, east longitudes are positive       
	
	lat1, lon1 = Latitude and Longitude of point 1 (in decimal degrees) 
    lat2, lon2 = Latitude and Longitude of point 2 (in decimal degrees)  
	code referred from https://www.geodatasource.com/developers/c
==========================================================================================*/

#include "gps.h"

int CekJarak(void)
{
	printf("I will calculate your distance\n\n");
	printf("Enter latitude and longitude for your location:\n");
	printf("latitude: ");
	scanf("%lf", &lat1);
	printf("longitude: ");
	scanf("%lf", &lon1);
	
	printf("\nEnter latitude and longitude for your destination:\n");
	printf("latitude: ");
	scanf("%lf", &lat2);
	printf("longitude: ");
	scanf("%lf", &lon2);
	
	printf("\n\nposisi anda di %.2lf %.2lf dan anda ingin menuju %.2lf %.2lf, benar?\n\n", lat1, lon1, lat2, lon2);
	getch();
	
	dist = distance(lat1, lon1, lat2, lon2);
	
	printf("jarak tempuh adalah %.2lf Kilometer.", dist);
}


double distance(double lat1, double lon1, double lat2, double lon2) 
{  
  double theta, dist;
  
  if ((lat1 == lat2) && (lon1 == lon2)) 
  {
    return 0;
  }
  
  else 
  {
    theta = lon1 - lon2;
    dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
    dist = acos(dist);
    dist = rad2deg(dist);
    dist = dist * 60 * 1.1515;
	dist = dist * 1.609344;		
  }
return dist;

}

/*=====================================
	konversi derajat desimal ke radian
=======================================*/

double deg2rad(double deg) {
  return (deg * pi / 180);
}

/*=====================================
	konversi radian ke derajat desimal
======================================*/

double rad2deg(double rad) {
  return (rad * 180 / pi);
}



