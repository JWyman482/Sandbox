#pragma once
#include <string>

class Game;
class Player;

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
	Player* origOwner = nullptr;

	//bool onEnter = false;
	bool canSacrifice = true;
	bool isActive = true;
	bool onTurnOpt = false;
	bool hasEffect = false;
	//bool onExit = false;
	//bool onSacr = false;
	//bool onDest = false;

	// The functions below are all in children
	void onEnterAction() {};
	void onTurnAction() {};
	void onExitAction() {};
	void onSacrAction() {};
	void onDestAction() {};

	void onEnter() {
		if (!isActive) return;
		cout << name << "'s onEnter triggered.\n";
	};
	void onTurn() {
		if (!isActive) return;

		// If the power is optional
		if (onTurnOpt) {
			show();
			cout << "Would you like to use this power (y/n)? ";
			// TODO add char validation
			char decision;
			cin >> decision;

			if (decision != 'y') return;
		}

		onTurnAction();
	};
	void onExit() { 
		if (!isActive) return;
		onExitAction();
		owner = nullptr;
	}
	void onSacr() { onSacrAction(); }
	void onDest() { onDestAction(); }

	void show() {
		cout << name << endl;
		cout << desc << endl;
		cout << endl;
	}

};