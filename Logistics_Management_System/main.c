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


