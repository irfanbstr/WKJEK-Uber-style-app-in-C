/*====================================================
				Header GPS
					WKJEK
					
	By Irfan Budi Satria
=====================================================*/

#ifndef GPS_H
#define GPS_H

#define pi 3.14159265358979323846

double deg2rad(double);
double rad2deg(double);

double dist, lat1, lon1, lat2, lon2;

double distance(double lat1, double lon1, double lat2, double lon2);

#endif
