#include "MenuClass.h"

class RestaurantOrder
{
	double Bill[C];
	string order[C];
public:
	RestaurantOrder();
	~RestaurantOrder();
	void AddToOrder(RestaurantMenu obj, string s);
	void DeleteFromOrder(string s);
	double CalculateBill();
};

RestaurantOrder::RestaurantOrder()
{
	for(int p=0;p<C;p++){order[p].clear();	Bill[p]=0;}
}

RestaurantOrder::~RestaurantOrder()
{
	cout<<endl<<"			*** Come Again ***"<<endl<<endl;
					cin.ignore();
}

void RestaurantOrder::AddToOrder(RestaurantMenu obj, std::string s)
{	
	if (static_cast<int>(obj.FindMeal(s))==-1)
		cout<<"!?! Not in Today's Menu !?!"<<endl;
	else
	{
		for(int p=0;p<C;p++)
		{
			if (order[p].empty()){order[p]=s;	Bill[p]=obj.FindMeal(s);	return;}
		}
	}
}

void RestaurantOrder::DeleteFromOrder(string s)
{
	int p=0;
	while (p<C)
	{
		if (order[p]==s){order[p].clear();	Bill[p]=0;	return;}
		p++;
	}
	cout<<"!?! Not in Your Order !?!"<<endl;
}

double RestaurantOrder::CalculateBill()
{
	double billSum=0;

	for (int p=0; p<C; p++){billSum+=Bill[p];}
	return billSum;
}

