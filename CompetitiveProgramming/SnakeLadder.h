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

using namespace std;


class Player {

public:
    string name;
    int val = 0;
};


class Game {

private:
    unordered_map<int, int> jump;
    unordered_set<string> userNames;
    queue<Player> _players;
    string gameStatus = "off";
    int _securityKey = rand();

public:
    Game() {
    }

    void addPlayer(Player player) {
        if (userNames.find(player.name) != userNames.end())
            throw("name already taken");
        _players.push(player);
        userNames.insert(player.name);
        return;
    }

    void addJump(int start, int end) {
        if (start < 0 || start > 100 || end < 0 || end > 100 || start == end || start == 100)
            throw "Invalid jump";
        if (gameStatus == "off")
            jump[start] = end;

        return;
    }

    int play(string currPlayerName, int val) {
        if (gameStatus == "finish") {
            return 101;
        }

        if (val < 0 || val > 6) {
            throw "Invalid value";
            return -1;
        }
        Player currPlayer = _players.front();
        if (currPlayer.name != currPlayerName) {
            throw "Invalid player move";
            return -1;
        }

        int nextVal = currPlayer.val + val;
        auto it = jump.find(nextVal);
        if (it != jump.end())
            nextVal = jump[nextVal];
        _players.front().val = nextVal;

        if (nextVal == 100) {
            gameStatus = "finish";
            return 100;
        }

        _players.push(_players.front());
        _players.pop();
        return nextVal;
    }

    Player getWinner() {
        if (gameStatus == "finish")
            return _players.front();
        else
            throw "game not finished";
    }

    int getSecretKey() {
        return _securityKey;
    }

};


class  SnakeLadder {

private:
    unordered_map<int, Game> games;
    int key = 0;
public:
    SnakeLadder() {}
    pair<int, int> addGame() {
        Game game;
        games[key++] = game;
        int secretKey = game.getSecretKey();
        return { key - 1, secretKey };
    }

    void play() {
        while (true) {
            string s; cin >> s;
            if (s == "close program")
                break;

            if (s == "new_game") {
                pair<int, int> ret;
                ret = addGame();
                cout << "lets play" << endl;
                cout << "key " << ret.first << " secet key " << ret.second << endl;
            }

            if (s == "add_jump") {
                int key, secretKey, start, end;
                cin >> key >> secretKey >> start >> end;
                if (games[key].getSecretKey() == secretKey) {
                    games[key].addJump(start, end);
                    cout << "success" << endl;
                }
                else {
                    cout << "Invalid auth" << endl;
                }
            }

            if (s == "add_player") {
                int key, secretKey;
                string name;
                cin >> key >> secretKey >> name;
                if (games[key].getSecretKey() == secretKey) {
                    Player player;
                    player.name = name;
                    games[key].addPlayer(player);
                    cout << "success\n";
                }
                else {
                    cout << "Invalid auth" << endl;
                }
            }

            if (s == "play") {
                int key, secretKey, val;
                string name;
                cin >> key >> secretKey >> name >> val;
                if (games[key].getSecretKey() == secretKey) {
                    int ret = games[key].play(name, val);
                    if (ret < 0) {
                        cout << "Invalid move\n";
                    }
                    else if (ret > 100) {
                        cout << "game already finishe, winner: " << games[key].getWinner().name << endl;
                    }
                    else if (ret == 100)
                        cout << "winner: " << games[key].getWinner().name << endl;
                    else
                        cout << name << " location : " << ret << endl;
                }
                else {
                    cout << "Invalid auth\n";
                }
            }
        }
    }
};


