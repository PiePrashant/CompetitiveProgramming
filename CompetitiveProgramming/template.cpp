#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
#include<unordered_set>
#include<unordered_set>
#include<math.h>
#include<queue>
#include<stack>
#include "BinarySearch.h"
#include "SnakeLadder.h"

using namespace std;

#define pi 3.14159
#define ll long long
#define ull unsigned long long


void solve() {

	// Write your code here
	int arr[7] = { 1, 2, 3, 3, 5, 5, 5 };
	cout << BinarySearch::upper_bound(arr, 0, 7, 5) << endl;
	cout << BinarySearch::lower_bound(arr, 0, 7, 5) << endl;

	return;
}


int main() {

	SnakeLadder game;
	game.play();
	return 0;
}