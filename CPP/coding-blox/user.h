#include<bits/stdc++.h>
using namespace std;

class User {
public:
	static int userId;
	static vector<User> userList;
	static map<string, int> name_to_id;
	string name;
	int id;
	int score;

	User(string name) {
		this->id = ++userId;
		this->name = name;
		this->score = 1500;
	}

	static void CreateUser(string);

	static void LeaderBoard(string);
};

int User:: userId = 0;
vector<User> User:: userList = vector<User>();
map<string, int> User:: name_to_id = map<string, int>();


void User:: CreateUser(string name) {
	User user(name);
	userList.push_back(user);
	name_to_id[user.name] = user.userId;
}

void User:: LeaderBoard(string order = "asc") {
	assert((order == "asc") || (order == "desc"));
	cout << "LeaderBoard !!\n";
	if (order == "asc")
		sort(userList.begin(), userList.end(), [&](User & u1, User & u2) {return u1.score < u2.score;});
	else
		sort(userList.begin(), userList.end(), [&](User & u1, User & u2) {return u1.score > u2.score;});
	for (auto & user : userList)
		cout << user.name << " " << user.score << "\n";
}