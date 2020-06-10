/*--------------------------
Author: Nishchal Agrawal

Problem Description: 
Given two integer arrays representing weights and profits of ’N’ items, find a subset of these items that will give us maximum profit such that their cumulative weight is not more than a given number ‘C’. 
You can assume an infinite supply of item quantities, so each item can be selected multiple times.

Solution Metrics:
Time Complexity: O(N^2)
Memory: O(N^2)
---------------------------*/

#include <iostream>
#include <vector>

using namespace std;

int knapsack(vector<int> w, vector<int> p, int kweight);

int main() {

  vector<int> w = { 1, 2, 3 };
  vector<int> p = { 15, 20, 50};

  cout << knapsack(w, p, 5) << endl;
}

int knapsack(vector<int> w, vector<int> p, int kweight) {

  vector<int> dp(kweight + 1, 0);

  for (int cw = 1; cw <= kweight; cw++) {

    int maxp = 0;

    for (int cp = 0; cp < p.size(); cp++) {

      int wdiff = cw - w[cp];

      if (wdiff < 0) continue;

      maxp = max(p[cp] + dp[wdiff], maxp);
    }

    dp[cw] = maxp;
  }

  return dp[kweight];
}