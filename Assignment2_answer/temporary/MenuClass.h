#include <iostream>
#include <string>
using namespace std;

const int C=10;  //I used this constant to change it to a higher value if I wanted(maybe 100)

class RestaurantMenu
{
	double price[C];
	string Menu[C];
	int numMeals;
public:
	RestaurantMenu();
	void AddToMenu(string s, double d);
	void DeleteFromMenu(string s);
	void ShowMenu();
	double FindMeal(string s);
};

RestaurantMenu::RestaurantMenu()
{
	numMeals=0;
	for(int p=0;p<C;p++){Menu[p].clear();	price[p]=0;}

	Menu[0]="Mansaf";
	price[0]=2.7;
		numMeals++;
	Menu[1]="Burger";
	price[1]=1.50;
		numMeals++;
	Menu[2]="Falafel";
	price[2]=0.5;
		numMeals++;
}

void RestaurantMenu::AddToMenu(string s, double d)
{
	for(int p=0;p<C;p++)
		{
			if (Menu[p].empty()){Menu[p]=s;	price[p]=d;	numMeals++;	return;}
		}
}

void RestaurantMenu::DeleteFromMenu(string s)
{
	int p=0;
	while (p<C)
	{
		if (Menu[p]==s){Menu[p].clear();	price[p]=0;	numMeals--;	return;}
		p++;
	}
	cout<<"!?! Meal not found in Today's Menu !?!"<<endl;
}

void RestaurantMenu::ShowMenu()
{
	if (numMeals==0){cout<<"!?! Today's Menu is empty !?!"<<endl;}
	else
	{
		cout<<endl<<" <<< In Today's Menu "<<numMeals<<" Meals >>>"<<endl<<endl;
		for(int p=0;p<C;p++)
		{
			if (!Menu[p].empty()){cout<<Menu[p]<<"		"<<price[p]<<endl;}
		}
	}
}

double RestaurantMenu::FindMeal(string s)
{
	int p=0;
	while (p<C)
	{
		if (Menu[p]==s){return price[p];}
		p++;
	}
	return -1;
}