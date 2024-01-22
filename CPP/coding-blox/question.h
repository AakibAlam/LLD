#include<bits/stdc++.h>
using namespace std;

class Question {
public:
	static int questionId;
	static vector<Question> lowList;
	static vector<Question> mediumList;
	static vector<Question> highList;
	string level;
	int id, score;

	Question(int score, string level) {
		this->id = ++questionId;
		this->score = score;
		this->level = level;
	}

	static void CreateQuestion(int, string);

	static void ListQuestion(string);
};

int Question:: questionId = 0;
vector<Question> Question:: lowList = vector<Question>();
vector<Question> Question:: mediumList = vector<Question>();
vector<Question> Question:: highList = vector<Question>();


void Question:: CreateQuestion(int score, string level) {
	assert((level == "LOW") || (level == "MEDIUM") || (level == "HIGH"));
	Question question(score, level);
	if (level == "LOW")
		lowList.push_back(question);
	else if (level == "MEDIUM")
		mediumList.push_back(question);
	else
		highList.push_back(question);
}

void Question:: ListQuestion(string level = ".") {
	assert((level == ".") || (level == "LOW") || (level == "MEDIUM") || (level == "HIGH"));
	if (level == "." || level == "LOW") {
		for (auto & ques : lowList)
			cout << ques.id << " " << ques.score << "\n";
	}
	if (level == "." || level == "MEDIUM") {
		for (auto & ques : mediumList)
			cout << ques.id << " " << ques.score << "\n";
	}
	if (level == "." || level == "HIGH") {
		for (auto & ques : highList)
			cout << ques.id << " " << ques.score << "\n";
	}
}