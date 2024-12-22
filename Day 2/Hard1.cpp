//Ques 4. On a social network consisting of m users and some friendships between users, two users can communicate with each other if they know a common language.
You are given an integer n, an array languages, and an array friendships where:
There are n languages numbered 1 through n,
languages[i] is the set of languages the ith user knows, and
friendships[i] = [ui, vi] denotes a friendship between the users ui and vi.
You can choose one language and teach it to some users so that all friends can communicate with each other. Return the minimum number of users you need to teach.
Note that friendships are not transitive, meaning if x is a friend of y and y is a friend of z, this doesn't guarantee that x is a friend of z.

Program code:
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;
int minNumberOfUsersToTeach(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
    unordered_map<int, unordered_set<int>> userLanguages;
    for (int i = 0; i < languages.size(); ++i) {
        for (int lang : languages[i]) {
            userLanguages[i + 1].insert(lang);
        }
    }
unordered_set<int> toTeachUsers;
    vector<pair<int, int>> toTeachPairs;
    for (const auto& friendship : friendships) {
        int u = friendship[0], v = friendship[1];
        bool canCommunicate = false;
        for (int lang : userLanguages[u]) {
            if (userLanguages[v].count(lang)) {
                canCommunicate = true;
                break;
            }
        }
        if (!canCommunicate) {
            toTeachPairs.emplace_back(u, v);
            toTeachUsers.insert(u);
            toTeachUsers.insert(v);
        }
    }

    if (toTeachPairs.empty()) {
        return 0; 
    }

    int minTeach = toTeachUsers.size(); 
    for (int lang = 1; lang <= n; ++lang) {
        unordered_set<int> teachSet;
        for (const auto& pair : toTeachPairs) {
            int u = pair.first, v = pair.second;
            if (!userLanguages[u].count(lang)) {
                teachSet.insert(u);
            }
            if (!userLanguages[v].count(lang)) {
                teachSet.insert(v);
            }
        }
        minTeach = min(minTeach, (int)teachSet.size());
    }

    return minTeach;
}

int main() {
    int n = 2;
    vector<vector<int>> languages = {{1}, {2}, {1, 2}};
    vector<vector<int>> friendships = {{1, 2}, {1, 3}, {2, 3}};
    
    cout << "Minimum number of users to teach: " << minNumberOfUsersToTeach(n, languages, friendships) << endl;
    
    return 0;
}
