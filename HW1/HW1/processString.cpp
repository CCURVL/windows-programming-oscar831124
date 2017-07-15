﻿#include <iostream>
#include <string>
#include <vector>

#include <gtest\gtest.h>

using namespace std;


// getAscendingStr Function requirement
//
// Take space seperated digit string (ex. "1 2 3 5 4") and 
//   modify input string to ascending order ("1 2 3 4 5").
//
// return 0 if success, (empty string)
//       -1 if exception occur (ex. string containing non-digit character)
int getAscendingStr(string& inputStr){
	string out = inputStr;
	int q = 0;
	for (q = 0; q < inputStr.length(); q++){
		if (!(isdigit(inputStr[q]) || inputStr[q] == ' ' || inputStr[q]== '-')) {
			return -1;
		}
	}
	stringstream ss(out);
	string sub_str;
	int ans[100];
	int c = 0;
	int n;
	while (getline(ss, sub_str, ' ')) {
		cout << sub_str+" ";
		ans[c] = atoi(sub_str.c_str());
		c++;
	}
	cout << endl;
	sort(ans, ans + c);
	for (n = 0; n < c; n++) {
		printf("%d ", ans[n]);
	}
	printf("\n");
	return 0;
	
}

// solveQ Function requirement
// 
// solve quadratic function ax^2 + bx + c = 0
//
// return 1 if equation has two different real number root 
//          (return vector size should be 2 containing 2 solution.  
//          Greater value should put into smaller vector index)
//        0 there is only one possible solution to the quadratic equation 
//          (return vector size should be 1)
//       -1 complex roots 
//          (return vector size should be 0)
int solveQ(vector<double> &x, double a, double b, double c)
{
	if (b*b - (4*a*c) > 0) {
		double x1 = -1 * b + sqrt(b*b - (4 * a*c)) / (a + a);
		double x2 = -1 * b - sqrt(b*b - (4 * a*c)) / (a + a);
		x.push_back(x1);
		x.push_back(x2);

		return 1;
	}
	else if (b*b - (4 * a*c) == 0) {
		double x3 = -1 * b + sqrt(b*b - (4 * a*c)) / (a + a);
		x.push_back(x3);

		return 0;
	}
	else {
		return -1;
	}
	
}

int main(int argc, char*argv[]) {
	
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;
}

TEST(getAscendingStr, SimpleAscending)
{//Simple ascending test case

	string inputStr = "1 -3 2195 4 50";
	string tmpStr = inputStr;
	int err = getAscendingStr(tmpStr);
	EXPECT_EQ(tmpStr, "-3 1 4 50 2195");
	EXPECT_EQ(err, 0);
}

TEST(getAscendingStr, handleNonDigit)
{//getAscendingStr function should handle non digit case
	string tmpStr = "1 3 2 4 a 7f415";
	int err = getAscendingStr(tmpStr);
	EXPECT_EQ(err, -1);
}

TEST(solveQ, twoSolution)
{
	vector<double> sol;
	int iSol = solveQ(sol, 1, 2, -3);
	EXPECT_EQ(iSol, 1);
	EXPECT_EQ(sol.size(), 2);
	EXPECT_EQ(sol.at(0), 1);
	EXPECT_EQ(sol.at(1), -3);
}

TEST(solveQ, oneSolution)
{
	vector<double> sol;
	int iSol = solveQ(sol, 1, -8, 16);
	EXPECT_EQ(iSol, 0);
	EXPECT_EQ(sol.size(), 1);
	EXPECT_EQ(sol.at(0), 4);
}

TEST(solveQ, noSolution)
{
	vector<double> sol;
	int iSol = solveQ(sol, 1, 1, 16);
	EXPECT_EQ(iSol, -1);
	EXPECT_EQ(sol.size(), 0);
}
