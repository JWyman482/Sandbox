#pragma once
#include <string>
#include <iostream>
#include "Card.h"
#include "Game.h"
#include "Player.h"

using namespace std;

// TODO add magic unicorn cards
class Rhinocorn : public Card {
	Rhinocorn(Game* g) {
		name = "Rhinocorn";
		img = "PATH";
		desc = " If this card is in your Stable at the beginning of your turn, you may DESTROY a Unicorn, then end your turn immediately.";
		onTurnOpt = true;
		Card::g = g;
	};

	void onEnterAction() { cout << name << " entered a stable\n"; }
	void onTurnAction() {
		owner->destroy();

		// End the turn immediately
		g->skipDraw = true;
		g->skipAct = true;

	}
	void onExitAction() { cout << name << " exited a stable\n"; }
	void onSacrAction() { cout << name << " was sacrificed\n"; }
	void onDestAction() { cout << name << " was destroyed\n"; }

};

// TODO: Figure out how to implement BarbedWire.
class BarbedWire : public Card {
public:
	BarbedWire(Game* g) {
		name = "Barbed Wire";
		img = "PATH";
		desc = "Each time a Unicorn card enters or leaves your stable, DISCARD a card.";
		hasEffect = true;
		Card::g = g;
	};

	void onEnterAction() {

	}

	void onExitAction() {

	}

};

