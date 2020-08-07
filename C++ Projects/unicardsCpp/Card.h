#pragma once
#include <string>

class Game;

using namespace std;

class Card {
public: 
	Card() {};
	Card(Game* gm) : g(gm) {};
	Card(string nm, string imgPath, string desc, Game* gm) : name(nm), img(imgPath), desc(desc), g(gm) {};
	string name;
	string img;
	string desc;

	Game* g = nullptr;
	Player* owner = nullptr;

	bool onEnter = false;
	bool onTurn = false;
	bool onExit = false;
	bool onSacr = false;
	bool onDest = false;

	void onEnterAction() {};
	void onTurnAction() {};
	void onExitAction() {};
	void onSacrAction() {};
	void onDestAction() {};

private:
	Player* origOwner = nullptr;
};