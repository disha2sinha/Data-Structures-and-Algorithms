#include <iostream>
#include<vector>
//Function to Get Change with Greedy Approach 
//Modification can be done according to coins
int get_change(int m) {
 	int coins[]  = {10,5,1};
    int count_for_coins = 0;
    vector<int> coins_used;

    for(int i = 0; i < 3; i++)
    {
        //take as much from coins[i]
        while(m >= coins[i])
        {
            //after taking the coin, reduce the value.
            m -= coins[i];
            count_for_coins++;
            //Also you can push the coins used in a array 
            coins_used.push_back(coins[i]);
        }
        if(m == 0)
        break;
    }
	
    return count_for_coins;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
