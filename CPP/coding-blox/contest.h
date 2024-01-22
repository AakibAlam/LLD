#include<bits/stdc++.h>
#include "question.h"
#include "user.h"
using namespace std;

class Contest {
public:
	static int id;
	static vector<Contest> contestList;
	int contestId;
	string name;
	string level;
	string owner;
	vector<int> score;
	vector<string> users;
	vector<vector<int>> history;

	Contest(string name, string level, string owner) {
		this->contestId = ++id;
		this->name = name;
		this->level = level;
		this->owner = owner;
		score.clear();
		history.clear();
		this->users.push_back(owner);
	}

	static void CreateContest(string, string, string);

	static void ListContest(string);

	static void AttendContest(int, string);

	static void RunContest(int, string);

	static void WithdrawContest(int, string);

	static void ContestHistory(int);

};

int Contest:: id = 0;
vector<Contest> Contest:: contestList = vector<Contest>();


void Contest:: CreateContest(string name, string level, string owner) {
	Contest contest(name, level, owner);
	contestList.push_back(contest);
}

void Contest:: ListContest(string level = ".") {
	assert((level == ".") || (level == "LOW") || (level == "MEDIUM") || (level == "HIGH"));
	for (auto & contest : contestList) {
		if ((level == ".") || (contest.level == level))
			cout << contest.contestId << " " << contest.level << " " << contest.owner << "\n";
	}
}

void Contest:: AttendContest(int contestId, string user_name) {
	contestList[contestId - 1].users.push_back(user_name);
}

void Contest:: RunContest(int contestId, string owner) {
	if (contestList[contestId - 1].owner != owner) {
		cout << "User " << owner << " doesn't have access to start the contest " << contestId << "\n";
		return;
	}
	if (contestList[contestId - 1].level == "LOW") {
		int num_of_question = static_cast<int>(Question:: lowList.size());
		vector<int> random_array(num_of_question);
		iota(random_array.begin(), random_array.end(), 0);
		for (auto & user : contestList[contestId - 1].users) {
			if (num_of_question == 0) continue;
			int score = 0;
			vector<int> ques;
			random_shuffle(random_array.begin(), random_array.end());
			int num_of_question_solved = rand() % num_of_question;
			for (int i = 0; i < num_of_question_solved; i++) {
				ques.push_back(Question:: lowList[random_array[i]].id);
				score += Question:: lowList[random_array[i]].score;
			}
			contestList[contestId - 1].score.push_back(score);
			contestList[contestId - 1].history.push_back(ques);
			User:: userList[User:: name_to_id[user] - 1].score += (score - 50);
		}
	}
	if (contestList[contestId - 1].level == "MEDIUM") {
		int num_of_question = static_cast<int>(Question:: mediumList.size());
		vector<int> random_array(num_of_question);
		iota(random_array.begin(), random_array.end(), 0);
		for (auto & user : contestList[contestId - 1].users) {
			if (num_of_question == 0) continue;
			int score = 0;
			vector<int> ques;
			random_shuffle(random_array.begin(), random_array.end());
			int num_of_question_solved = rand() % num_of_question;
			for (int i = 0; i < num_of_question_solved; i++) {
				ques.push_back(Question:: mediumList[random_array[i]].id);
				score += Question:: mediumList[random_array[i]].score;
			}
			contestList[contestId - 1].score.push_back(score);
			contestList[contestId - 1].history.push_back(ques);
			User:: userList[User:: name_to_id[user] - 1].score += (score - 30);
		}
	}
	if (contestList[contestId - 1].level == "HIGH") {
		int num_of_question = static_cast<int>(Question:: highList.size());
		vector<int> random_array(num_of_question);
		iota(random_array.begin(), random_array.end(), 0);
		for (auto & user : contestList[contestId - 1].users) {
			if (num_of_question == 0) continue;
			int score = 0;
			vector<int> ques;
			random_shuffle(random_array.begin(), random_array.end());
			int num_of_question_solved = rand() % num_of_question;
			for (int i = 0; i < num_of_question_solved; i++) {
				ques.push_back(Question:: highList[random_array[i]].id);
				score += Question:: highList[random_array[i]].score;
			}
			contestList[contestId - 1].score.push_back(score);
			contestList[contestId - 1].history.push_back(ques);
			User:: userList[User:: name_to_id[user] - 1].score += (score - 0);
		}
	}
}

void Contest:: WithdrawContest(int contestId, string user_name) {
	vector<string> &users = contestList[contestId - 1].users;
	if (find(users.begin(), users.end(), user_name) != users.end())
		users.erase(find(users.begin(), users.end(), user_name));
}

void Contest:: ContestHistory(int contestId) {
	vector<pair<int, pair<string, vector<int>>>> temp;
	for (int i = 0; i < (int)contestList[contestId - 1].users.size(); i++) {
		temp.push_back({contestList[contestId - 1].score[i], {contestList[contestId - 1].users[i], contestList[contestId - 1].history[i]}});
	} sort(temp.begin(), temp.end());
	for (auto & elem : temp) {
		cout << elem.second.first << ": " << elem.first << " [";
		for (int i = 0; i < (int)elem.second.second.size(); i++)
			cout << elem.second.second[i] << ", "[i < (int)elem.second.second.size()];
		cout << "]\n";
	}
}