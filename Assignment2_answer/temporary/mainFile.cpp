//Assignment #2
//Yahya Mubaideen	#20102171058
//I didn't write comments because the code is self-explanatory and I spent some time on improving the special cases.
//And i didn't do any decoration that uses a "delay loop" because the time of delay is different between different machines(computers).
//Turned out that even system("color #") is different between different machines(computers) but still i will keep it.

#include "OrderClass.h"

void main()
{
	cout<<"			*** Hello ***"<<endl;
	cout<<"		Welcome To The Restaurent"<<endl<<endl<<endl<<endl;

	RestaurantMenu theMenu;
	char selectMain;
	char selectSub;
	string s;
	double d;
	string hang;

	do
	{
		cout<<"		Press enter to continue";
		cin.ignore();
		system("CLS");
		system("color 3");

		cout<<"To edit the menu enter m, to make a new order enter o."
			<<endl<<"### any other character to exit ### : "; cin>>selectMain;
		if (selectMain=='m' || selectMain=='M')
		{
			do{
				cout<<"		Press enter to continue";
				cin.ignore();
				cin.ignore();
				system("CLS");
				system("color 42");

				cout<<"Please select one of these options: \n"
				<<"1) if you want to add a new item to the menu. \n"
				<<"2) if you want to delete an item from the menu. \n"
				<<"3) if you want to see the menu. \n"
				<<"### To go back to main enter any other character ### : ";	cin>>selectSub;	cout<<endl;
				switch (selectSub)
				{
					case '1':
						cout<<"enter the name of the meal you want to add: "; cin>>s;
						cout<<"enter the price of the meal that you added: "; cin>>d;
						theMenu.AddToMenu(s,d);
						break;
					case '2':
						cout<<"enter the name of the meal you want to delete: "; cin>>s;
						theMenu.DeleteFromMenu(s);
						break;
					case '3':
						theMenu.ShowMenu();
						break;
				}}while(selectSub=='1' || selectSub=='2' || selectSub=='3');
		}
		else
		{
			if (selectMain=='o' || selectMain=='O')
			{
				RestaurantOrder theOrder;

				do{
					cout<<"		Press enter to continue";
					cin.ignore();
					cin.ignore();
					system("CLS");
					system("color 79");

					cout<<"Please select one of these options: \n"
					<<"1) if you want to add a new item to the order. \n"
					<<"2) if you want to delete an item from the order. \n"
					<<"3) if you want to check-out. \n"
					<<"### To go back to main enter any other character ### : ";	cin>>selectSub;	cout<<endl;
					switch (selectSub)
					{
						case '1':
							cout<<"enter the name of the meal you want to add to your order: "; cin>>s;
							theOrder.AddToOrder(theMenu,s);
							break;
						case '2':
							cout<<"enter the name of the meal you want to delete from your order: "; cin>>s;
							theOrder.DeleteFromOrder(s);
							break;
						case '3':
							cout<<"$$$ Total Price: "<<theOrder.CalculateBill()<<"JD $$$"<<endl;
							break;
					}}while(selectSub=='1' || selectSub=='2' || selectSub=='3');
			}
		}
	}while(selectMain=='m' || selectMain=='M' || selectMain=='o' || selectMain=='O');
}