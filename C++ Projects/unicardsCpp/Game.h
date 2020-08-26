#pragma once

#include <vector>
#include "Card.h"
#include "Player.h"

using namespace std;

struct Game {
	// When a game is created:
	//	instantiate a new deck
	//	instantiate new players
	//	shuffle the deck and create the drawPile
	//	create the nursery
	Game() {};
	vector<Card> deck;
	vector<Player> players;
	vector<int> drawPile;
	vector<int> discard;
	vector<int> nursery;
	int currentPlayer = 0;
	int currentPhase = 0;

	int handLimit = 5;
	int winCondition = 7;

	bool skipBeg = false,
		skipDraw = false,
		skipAct = false,
		skipEnd = false;

	// Load card information into master deck. This can be a
	// persistant file or array of JSON objects later. A deck file. 
	bool buildDeck() {
		// Fill in the babies and basics
		for (int i = 0; i < 34; i++) {
			if (i <= 12) {
				Card temp("Baby", "PATH", "Baby Unicorn", this);
				deck.push_back(temp);
			}
			else if (i <= 34) {
				Card temp("Basic", "PATH", "Basic Unicorn", this);
				deck.push_back(temp);
			}
		}

		// Section for magic unicorns, magics, upgrades and downgrades


		// Fill in the neighs and super neigh
		for (int i = 112; i <= 126; i++) {
			if (i != 126) {
				Card temp("Neigh", "PATH", "Instantly stop something", this);
				deck.push_back(temp);
			}
			else if (i == 126) {
				Card temp("Super Neigh", "PATH", "Instantly stop something and can't be stopped", this);
				deck.push_back(temp);
			}
		}


	};

	void shuffle(vector<int>& cards) {
		int size = cards.size();
		for (int i = 0; i < size - 1; i++) {
			int j = i + rand() % (size - i);
			swap(cards[i], cards[j]);
		}
	}

	// Search a deck of cards (or hand, etc)
	// If it's there, return the index
	// else return -1
	int searchCards(const vector<int>& cards, int target) {
		for (int i = 0; i < cards.size() - 1; i++) {
			if (cards[i] == target) return i;
		}
		return -1;
	}

	vector<int> searchCards(const vector<int>& cards, string type) {
		int min;
		int max;
		vector<int> result;
		if (type == "unicorn") {
			min = 0;
			max = 64;
		}
		if (type == "baby unicorn") {
			min = 0;
			max = 12;
		}
		if (type == "basic unicorn") {
			min = 13;
			max = 34;
		}
		if (type == "magic unicorn") {
			min = 35;
			max = 64;
		}
		if (type == "magic") {
			min = 65;
			max = 89;
		}
		if (type == "upgrade") {
			min = 90;
			max = 104;
		}
		if (type == "downgrade") {
			min = 105;
			max = 111;
		}
		if (type == "instant") {
			min = 112;
			max = 126;
		}
		for (int i = 0; i < cards.size() - 1; i++) {
			if (cards[i] >= min && cards[i] <= max) {
				result.push_back(i);
			}
		}
		return result;
	}

	void displayTable() {
		for (int i = 0; i < players.size(); i++) {
			players[i].stable.show();
		}
	}

};