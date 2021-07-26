#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
#include <string>
#include <string>
#include<unordered_set>
#include<unordered_map>
#include<math.h>
#include<queue>
#include<stack>


class BinarySearch
{
	public:
	static int upper_bound(int arr[], int left, int right, int target) {

		while (left < right) {
			int mid = left + (right - left) / 2;

			if (arr[mid] > target)
				right = mid;
			else
				left = mid + 1;
		}

		return right;
	}


	static int lower_bound(int arr[], int left, int right, int target) {
		
		while (left < right) {
			int mid = left + (right - left) / 2;

			if (arr[mid] < target)
				left = mid + 1;
			else
				right = mid;
		}
		
		return left;
	}
};

