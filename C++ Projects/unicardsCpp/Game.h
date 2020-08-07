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
		for (int i = 111; i <= 125; i++) {
			if (i != 125) {
				Card temp("Neigh", "PATH", "Instantly stop something", this);
				deck.push_back(temp);
			}
			else if (i == 125) {
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
			max = 110;
		}
		if (type == "instant") {
			min = 111;
			max = 125;
		}
		for (int i = 0; i < cards.size() - 1; i++) {
			if (cards[i] >= min && cards[i] <= max) {
				result.push_back(i);
			}
		}
		return result;
	}

};