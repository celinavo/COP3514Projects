/*
Celina Vo
COP 3514
Problem 2: Tool Rental
Calculates the price of renting a tool for certain number of hours
*/

#include <stdio.h>

int main(){

/*initializing variables*/
int tool_selected = 0, hours = 0;
int minimum = 0, rate = 0, maximum = 0, excess_hours = 0, days = 0;
int price = 0;

/*prints selection menu*/
printf("Please select from the following menu: "); 
printf("1. Electric Pressure Washer, ");
printf("2. Commercial Carpet Extractor, ");
printf("3. Battery Powered Chainsaw, ");
printf("4. Drain Cleaner. \n");

/*asks for user to select tool*/
printf("Enter tool selection: ");
scanf("%d", &tool_selected);

/*if tool selected is valid, proceed to ask for number of hours*/
if (tool_selected <= 4 && tool_selected >= 1){
	printf("Enter hours rented: ");
	scanf("%d", &hours);

	switch (tool_selected){ /*sets price rate depending on tool selected*/
		case 1:{
			minimum = 28;
			rate = 4;
			maximum = 41;
			break;
			}
		case 2:{
			minimum = 25;
			rate = 3;
			maximum = 35;
			break;
			}
		case 3:{
			minimum = 32;
			rate = 5;
			maximum = 48;
			break;
			}
		case 4:{
			minimum = 51;
			rate = 6;
			maximum = 78;
			break;
			}
		default: break;
		}

	if (hours > 4) { /*if tool rental exceeds four hour minimum*/
		days = hours / 24;
		excess_hours = hours % 24;
		
		if (days != 0) { /* if rental extends multiple days*/
			if ((excess_hours * rate) > maximum) {
				/*if hours rented in a day exceeds maximum rental price*/
				price = maximum + (days * maximum);
				printf("Amount due ($): %d\n", price);
				}
			else {
				/*if hours rented within one day is less than maximum rental price*/
				price = (excess_hours * rate) + (days * maximum);
				printf("Amount due ($): %d\n", price);
				}
			}
		else { /* if rental does not last full day and is greater than four hours*/
			excess_hours = hours - 4; /*subtract price from minimum 4 hours*/
			price = minimum + (excess_hours * rate);
			if (price > maximum) price = maximum;
			printf("Amount due ($): %d\n", price);
			}
		}
			
	else { /*print minimum rental price*/
		price = minimum;
		printf("Amount due ($): %d\n", price);
		}

	}
else {
	printf("Invalid input. The input should be in the range of 1 to 4.\n");
	}
return 0;
}
