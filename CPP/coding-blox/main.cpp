#include<bits/stdc++.h>
#include "contest.h"
using namespace std;

int main() {

	cout << "Some Users are created!!\n";
	User:: CreateUser("Aakib");
	User:: CreateUser("Navneet");
	User:: CreateUser("Akash");
	User:: CreateUser("Sameer");
	User:: CreateUser("Sharib");
	// User:: LeaderBoard();
	cout << endl;

	cout << "Some Questions are created!!\n";
	Question:: CreateQuestion(100, "LOW");
	Question:: CreateQuestion(140, "LOW");
	Question:: CreateQuestion(120, "LOW");
	Question:: CreateQuestion(150, "MEDIUM");
	Question:: CreateQuestion(150, "MEDIUM");
	Question:: CreateQuestion(200, "HIGH");
	Question:: CreateQuestion(200, "HIGH");
	// Question:: ListQuestion();
	cout << endl;

	cout << "Some Contests are created!!\n";
	Contest:: CreateContest("1", "LOW", "Aakib");
	Contest:: CreateContest("2", "MEDIUM", "Navneet");
	Contest:: CreateContest("3", "HIGH", "Akash");
	// Contest:: ListContest();
	cout << endl;

	Contest:: AttendContest(1, "Navneet");
	Contest:: AttendContest(1, "Akash");
	Contest:: AttendContest(1, "Sharib");
	Contest:: AttendContest(1, "Sameer");
	Contest:: WithdrawContest(1, "Sameer");

	Contest:: RunContest(1, "Aakib");

	cout << "Contest history!!\n";
	Contest:: ContestHistory(1);
	cout << endl;

	User:: LeaderBoard();

	return 0;
}