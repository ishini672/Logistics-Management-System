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

void menu();
void addCity();
void showCities();
void enterDistance();
void showDistanceMatrix();
void newDelivery();
void performanceReport();



int main()
{

    int choice;
    for (int i = 0; i < MAX_CITIES; i++)
        for (int j = 0; j < MAX_CITIES; j++)
            distance[i][j] = 0;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) break;
        else if (choice == 1)
            addCity();
        else if (choice == 2)
            showCities();
        else if (choice == 3)
            enterDistance();
        else if (choice == 4)
            showDistanceMatrix();
        else if (choice == 5)
            newDelivery();
        else if (choice == 6)
            performanceReport();
        else printf("Invalid choice!\n");
    }

    printf("\nThank you for using the Delivery Cost Estimation System!\n");

    return 0;

}

void menu() {
    printf("\n===== DELIVERY COST ESTIMATION SYSTEM =====\n");
    printf("1. Add City\n");
    printf("2. Show Cities\n");
    printf("3. Enter/Edit Distances\n");
    printf("4. Show Distance Matrix\n");
    printf("5. New Delivery Request\n");
    printf("6. Performance Report\n");
    printf("7. Exit\n");
}

void addCity() {
    while (cityCount>=MAX_CITIES) {
        printf("City limit reached.\n");
        return;
    }

    printf("Enter city name: ");
    scanf("%s", cityNames[cityCount]);
    cityCount++;

    printf("City added successfully!\n");
}


void showCities() {
    if (cityCount==0) {
        printf("No cities added yet.\n");
        return;
    }

    printf("\nList of Cities: \n");
    for (int i = 0; i < cityCount; i++)
        printf("%d. %s\n", i + 1, cityNames[i]);
}


void enterDistance() {
    if (cityCount<2) {
        printf("Add at least two cities first.\n");
        return;
    }

    showCities();

    int a,b;
    int d;
    printf("Enter first city number: ");
    scanf("%d", &a);
    printf("Enter second city number: ");
    scanf("%d", &b);

    if (a < 1 || b < 1 || a > cityCount || b > cityCount || a == b) {
        printf("Invalid city numbers!\n");
        return;
    }

    printf("Enter distance between %s and %s (km): ", cityNames[a - 1], cityNames[b - 1]);
    scanf("%d", &d);

    distance[a - 1][b - 1] = d;
    distance[b - 1][a - 1] = d;

    printf("Distance updated successfully!\n");
}



void showDistanceMatrix() {
    if (cityCount == 0) {
        printf("No cities added yet.\n");
        return;
    }

    printf("\n Distance Matrix(km):\n        ");
    for (int i = 0; i < cityCount; i++)
        printf("%-10s", cityNames[i]);
    printf("\n");

    for (int i = 0; i < cityCount; i++) {
        printf("%-8s", cityNames[i]);
        for (int j = 0; j < cityCount; j++)
            printf("%-10d ", distance[i][j]);
        printf("\n");
    }
}


void newDelivery() {
    if (cityCount < 2) {
        printf("Add more cities first.\n");
        return;
    }
    if (deliveryCount >= MAX_DELIVERIES) {
        printf("Delivery record full!\n");
        return;
    }

    showCities();

    int from, to, vType;
    double w;

    printf("Enter source city number: ");
    scanf("%d", &from);
    printf("Enter destination city number: ");
    scanf("%d", &to);

    if (from < 1 || to < 1 || from > cityCount || to > cityCount || from == to) {
        printf("Invalid city numbers!\n");
        return;
    }

    printf("Enter vehicle type (1=Van,2=Truck,3=Lorry): ");
    scanf("%d", &vType);
    printf("Enter weight (kg): ");
    scanf("%lf", &w);

    double D = distance[from - 1][to - 1];
    if (D <= 0) {
        printf("Distance not set between these cities.\n");
        return;
    }



    double R = ratePerKm[vType - 1];
    double S = avgSpeed[vType - 1];
    double E = fuelEff[vType - 1];

    double bCost = D * R * (1 + w / 10000.0);
    double fUsed = D / E;
    double fCost = fUsed * fuelPrice;
    double tCost = bCost + fCost;
    double prof = tCost * 0.25;
    double charge = tCost + prof;
    double tHrs = D / S;


    fromCity[deliveryCount] = from - 1;
    toCity[deliveryCount] = to - 1;
    vehicleType[deliveryCount] = vType;
    dist[deliveryCount] = D;
    weight[deliveryCount] = w;
    baseCost[deliveryCount] = bCost;
    fuelUsed[deliveryCount] = fUsed;
    fuelCost[deliveryCount] = fCost;
    totalCost[deliveryCount] = tCost;
    profit[deliveryCount] = prof;
    customerCharge[deliveryCount] = charge;
    timeHrs[deliveryCount] = tHrs;
    deliveryCount++;

    printf("\n========= DELIVERY ESTIMATION =========\n");
    printf("From: %s\nTo: %s\n", cityNames[from - 1], cityNames[to - 1]);
    printf("Vehicle: %s\nWeight: %.2f kg\nDistance: %.2f km\n", vehicleNames[vType - 1], w, D);
    printf("---------------------------------------\n");
    printf("Delivery Cost: %.2f LKR\n", bCost);
    printf("Fuel Used: %.2f L\n", fUsed);
    printf("Fuel Cost: %.2f LKR\n", fCost);
    printf("Operational Cost: %.2f LKR\n", tCost);
    printf("Profit: %.2f LKR\n", prof);
    printf("Customer Charge: %.2f LKR\n", charge);
    printf("Estimated Time: %.2f hours\n", tHrs);
    printf("=======================================\n");
}








