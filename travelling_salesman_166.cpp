#include <iostream>
using namespace std;


int costMatrix[3][3];
int vistedCities[3];
int numCity = 3;
int cost = 0;


int tsp(int);
void minCost(int);


int main()
{

	int i;
	int j;


	cout << "\nEnter distance between cities into matrix:  \n";
	for (i = 0; i < numCity; i++)
	{
		cout << "\nEnter distance between City " << i + 1 << " and "<<numCity<<" others respectively: \n "
		;
		for (j = 0; j < numCity; j++)
			cin >> costMatrix[i][j];
	}

	cout << "\nDistances entered into cost matrix:\n";
	for (i = 0; i < numCity; i++)
	{
		cout << endl;
		for (j = 0; j < numCity; j++)
		{
			cout << costMatrix[i][j] << " ";
		}
	}


	cout << "\n\n Optimum Path is: \t ";
	minCost(0);
	cout << "\n Minimum Cost is: \t";
	cout << cost<<"\n";

	system("pause");
	return 0;
}


void minCost(int city)
{
	int nearestCity;
	vistedCities[city] = 1;

	cout << city + 1;
	nearestCity = tsp(city);

	if (nearestCity == 999)
	{
		nearestCity = 0;
		cout << nearestCity + 1;
		cost = cost + costMatrix[city][nearestCity];
		return;
	}
	minCost(nearestCity);
}


int tsp(int city1)
{
	int counter;
	int nearestCity = 999;
	int mini = 999;
	int itemp;

	for (counter = 0; counter < numCity; counter++)
	{
		if ((costMatrix[city1][counter] != 0) && (vistedCities[counter] == 0))
		{
			if (costMatrix[city1][counter] < mini)
			{
				mini = costMatrix[counter][0] + costMatrix[city1][counter];
			}
			itemp = costMatrix[city1][counter];
			nearestCity = counter;
		}
	}
	if (mini != 999)
		cost = cost + itemp;

	return nearestCity;
}
