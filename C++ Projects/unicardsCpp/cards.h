#pragma once
#include <string>
#include <iostream>
#include "Card.h"
#include "Game.h"
#include "Player.h"

using namespace std;

// TODO add magic unicorn cards

// 
class Rhinocorn : public Card {
	Rhinocorn(Game* g) {
		name = "Rhinocorn";
		img = "PATH";
		desc = " If this card is in your Stable at the beginning of your turn, you may DESTROY a Unicorn, then end your turn immediately.";
		onTurn = true;
		Card::g = g;
	};

	void onTurnAction() {
		cout << "Choose a unicorn to destroy.\n";
		// TODO add int validation
		int tgt;
		cin >> tgt;
		Player* tgtOwner = g->deck[tgt].owner;


		// if tgtOwner is null the unicorn is in the deck or discard. If searchCards
		// turns up negative then the card is in the player's hand and not their stable.
		while (tgtOwner != nullptr && (g->searchCards(tgtOwner->stable.unicorns, tgt) >= 0)) {
			cout << "The unicorn: " << g->deck[tgt].name << " is not valid. Please try another." << endl;
			cin >> tgt;
			tgtOwner = g->deck[tgt].owner;
		}
		
		tgtOwner->destroy(tgt);
	}
};
