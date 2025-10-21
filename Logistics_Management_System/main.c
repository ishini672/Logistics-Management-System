#include <stdio.h>
#include <stdlib.h>

#define MAX_CITIES 30
#define MAX_DELIVERIES 50


char cityNames[MAX_CITIES][30];
int distance[MAX_CITIES][MAX_CITIES];
int cityCount = 0;

char vehicleNames[3][10] = {"Van", "Truck", "Lorry"};
double ratePerKm[3] = {30, 40, 80};
double avgSpeed[3] = {60, 50, 45};
double fuelEff[3] = {12, 6, 4};
double fuelPrice = 310; // LKR per liter

int fromCity[MAX_DELIVERIES];
int toCity[MAX_DELIVERIES];
int vehicleType[MAX_DELIVERIES];
int dist[MAX_DELIVERIES];
double weight[MAX_DELIVERIES];
double baseCost[MAX_DELIVERIES], fuelUsed[MAX_DELIVERIES];
double fuelCost[MAX_DELIVERIES], totalCost[MAX_DELIVERIES];
double profit[MAX_DELIVERIES], customerCharge[MAX_DELIVERIES];
double timeHrs[MAX_DELIVERIES];
int deliveryCount = 0;








int main()
{

    return 0;
}
