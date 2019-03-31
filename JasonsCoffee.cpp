// JasonsCoffee.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Prgrammer:		Jack Morris
// Course:			ITSE-1307 (Intro to C++)
// Description:		Console application to manage sales of a coffee shop. Demonstrates use of user-defined functions.
// Date:			03/29/2019

#include "pch.h"
#include <iostream>
#include <iomanip>

using namespace std;

void menuChoices();
void sellCoffee(int& sm, int& md, int& lg); 
void totalCups_Sold(int sm, int md, int lg);
int get_TotalOunces_Sold(int sm, int md, int lg);
double get_TotalSales(int sm, int md, int lg);
void help(); 

int main()
{
	int sm_Sold = 0, md_Sold = 0, lg_Sold = 0;
	int choice;

	do
	{
		menuChoices();
		cin >> choice;
		cout << endl;

		switch (choice)
		{
			case 1: // Sell Coffee menu
				sellCoffee(sm_Sold, md_Sold, lg_Sold);
				break;
			case 2: // Get daily total cups sold by size 
				totalCups_Sold(sm_Sold, md_Sold, lg_Sold);
				break;
			case 3: // Get daily total ounces of coffee sold
				get_TotalOunces_Sold(sm_Sold, md_Sold, lg_Sold);
				break;
			case 4: // Get daily sales totals
				get_TotalSales(sm_Sold, md_Sold, lg_Sold);
				break;
			case 5: // Help page
				help();
				break;
			case 6: // Exit the program 
				break;
			default:
				cout << "  Invalid input." << endl;
				break;
		} // End of SWITCH

	} while (choice != 6); // End of DO WHILE

	return 0;
} // End of main()

void menuChoices()
{
	cout << endl;
	cout << "\tJason's Coffee Shop\n" << endl;
	cout << "\t    Main Menu\n" << endl;
	cout << "\t1 -- Sell Coffee\n" << endl;
	cout << "\t2 -- Total Cups Sold\n" << endl;
	cout << "\t3 -- Total Ounces Sold\n" << endl;
	cout << "\t4 -- Total Sales\n" << endl;
	cout << "\t5 -- Help\n" << endl;
	cout << "\t6 -- Exit\n" << endl;
	cout << "  Select a menu item: >> ";
}

void sellCoffee(int& sm, int& md, int& lg)
{
	int sm_Qty = 0, md_Qty = 0, lg_Qty = 0;
	double sm_Price = 1.75, md_Price = 1.90, lg_Price = 2.00;
	double sm_Subtotal = 0, md_Subtotal = 0, lg_Subtotal = 0;
	double total;
	int choice;

	cout << fixed << showpoint << setprecision(2);

	do
	{
		cout << endl;
		cout << "\t1 -- Small Coffee\n" << endl;
		cout << "\t2 -- Medium Coffee\n" << endl;
		cout << "\t3 -- Large Coffee\n" << endl;
		cout << "\t4 -- Complete Sale\n" << endl;
		cout << "\t5 -- Return to Main\n" << endl;
		cout << "  Select a munu item: >> ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
			case 1: // Small Order
			cout << "  Small Coffee. Enter qty: >> ";
			cin >> sm_Qty;
			cout << endl;
			sm += sm_Qty;
			sm_Subtotal += (sm_Qty * sm_Price);
			break;

			case 2: // Medium Order
			cout << "  Medium Coffee. Enter qty: >> ";
			cin >> md_Qty;
			cout << endl;
			md += md_Qty;
			md_Subtotal += (md_Qty * md_Price);
			break;

			case 3: // Large Order
			cout << "  Large Coffee. Enter qty: >> ";
			cin >> lg_Qty;
			cout << endl;
			lg += lg_Qty;
			lg_Subtotal += (lg_Qty * lg_Price);
			break;

			case 4: // Complete Purchase
			total = sm_Subtotal + md_Subtotal + lg_Subtotal;
			
			if (sm_Qty > 0)
			{
				cout << "  " << sm_Qty << " Small Coffee(s)" << " $ " << sm_Subtotal << endl;
			}
			if (md_Qty > 0)
			{
				cout << "  " << md_Qty << " Medium Coffee(s)" << " $ " << md_Subtotal << endl;
			}
			if (lg_Qty > 0)
			{
				cout << "  " << lg_Qty << " Large Coffee(s)" << " $ " << lg_Subtotal << endl;
			}
			cout << "  Total" << " $ " << total << endl;

			// **** SYSTEM PAUSE RIGHT HERE ****
			break;
			
			case 5: // Return to Main Menu
			break;

			default: // Invalid Input
			break;
		}
	} while (choice != 4 && choice != 5);
	
} // End of sellCoffee()

void totalCups_Sold(int sm, int md, int lg)
{
	cout << "  Small cups sold today: " << sm << endl;
	cout << "  Medium cups sold today: " << md << endl;
	cout << "  Large cups sold today: " << lg << endl;
} // End of totalCups_Sold()

int get_TotalOunces_Sold(int sm, int md, int lg)
{
	int sm_Ounces = 9, md_Ounces = 12, lg_Ounces = 15;
	int totalOunces_Sold;

	totalOunces_Sold = (sm * sm_Ounces) + (md * md_Ounces) + (lg * lg_Ounces);
	return totalOunces_Sold;

} // End of totalOunces_Sold()

double get_TotalSales(int sm, int md, int lg)
{
	double sm_Price = 1.75, md_Price = 1.90, lg_Price = 2.00;
	double totalSales;

	totalSales = (sm * sm_Price) + (md * md_Price) + (lg_Price);
	return totalSales;

} // End of totalSales()

void help()
{
	cout << "  Enter the number that corresponds with the menu item you wish to select!" << endl;

} // End of help()



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
