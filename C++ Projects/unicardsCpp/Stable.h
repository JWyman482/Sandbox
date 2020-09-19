#pragma once

#include <vector>
#include <functional>

using namespace std;
class Effects {
public: 
	template<typename Function>
	void add(Function&& fn) {
		_functions.push_back(forward<Function>(fn));
	}

	void invoke_all() {
		for (auto&& fn : _functions) fn();
	}

private:
	vector<function<void()>> _functions;
};

struct Stable {
	Stable() {};
	Stable(Game* game, Player* player) : g(game), owner(player) {};
	Game* g = nullptr;
	Player* owner = nullptr;

	vector<int> upgrades;
	vector<int> downgrades;
	vector<int> unicorns;
	vector<int> pandas;

	int stableLimit = g->winCondition;

	// There are scoping problems here. It doesn't seem like
	// you can pass Effects non-static functions
	Effects onEnterStable;
	Effects onLeaveStable;

	bool add(int cardNum) {
		if (cardNum <= 64) {
			unicorns.push_back(cardNum);
			if (unicorns.size() > stableLimit && stableLimit < g->winCondition) {
				owner->sacrifice();
			}
		}
		else if (cardNum >= 90 && cardNum <= 104) {
			upgrades.push_back(cardNum);
		}
		else if (cardNum >= 105 && cardNum <= 111) {
			downgrades.push_back(cardNum);
		}
		// Trigger any "if a card enters the stable" effects

		// Set card owner to this player
		g->deck[cardNum].owner = owner;
		g->deck[cardNum].onEnter();
	};

	bool remove(int cardNum) {
		if (!hasCard(cardNum)) return false;

		g->deck[cardNum].onExit();
		onLeaveStable.invoke_all();

	}

	bool hasCard(int cardNum) {
		if (g->searchCards(upgrades, cardNum) < 0 || g->searchCards(downgrades, cardNum) < 0 || g->searchCards(unicorns, cardNum) < 0) return false;
		return true;
	}

	bool onTurn() {
		for (int cardNum : upgrades) {
			g->deck[cardNum].onTurn();
		}
		for (int cardNum : downgrades) {
			g->deck[cardNum].onTurn();
		}
		for (int cardNum : unicorns) {
			g->deck[cardNum].onTurn();
		}
	}

	void show() {
		cout << owner->name << "'s Stable *************************\n";
		cout << "Unicorns:\n" << endl;
		for (int card : unicorns) {
			cout << "(#" << card << ") " << g->deck[card].name << endl;
			cout << g->deck[card].desc << endl;
			cout << endl;
		}

		cout << "Upgrades:\n" << endl;
		for (int card : upgrades) {
			cout << "(#" << card << ") " << g->deck[card].name << endl;
			cout << g->deck[card].desc << endl;
			cout << endl;
		}

		cout << "Downgrades:\n" << endl;
		for (int card : downgrades) {
			cout << "(#" << card << ") " << g->deck[card].name << endl;
			cout << g->deck[card].desc << endl;
			cout << endl;
		}
	}
};