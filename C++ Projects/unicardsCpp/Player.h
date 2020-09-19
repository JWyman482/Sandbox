#pragma once

#include <vector>
#include <string>
#include "Stable.h"
#include "Game.h"

using namespace std;

class Player {
public: 
	string name;
	Stable stable;
	vector<int> hand;

	int drawPerTurn = 1;
	int discardPerTurn = 0;
	int playPerTurn = 1;
	int handLimit = g->handLimit;
	bool nannyCam = false;

	/*vector<int>onEnterTgts;
	vector<int>onExitTgts;
	vector<int>onSacrTgts;
	vector<int>onDestTgts;
	vector<int>onTurnTgts;*/

	Game* g = nullptr;

	bool draw() {
		
	}
	bool play();
	bool discard();
	bool sacrifice() {
		stable.show();

		int tgt = -1;
		while (tgt < 0 || tgt > 64) {
			cout << "\nChoose a unicorn to sacrifice:  ";
			// TODO add int validation
			cin >> tgt;
			tgt = g->searchCards(stable.unicorns, tgt);
		} // Unicorn in this stable picked

		if (!g->deck[tgt].canSacrifice) return false;
		stable.remove(tgt);
		g->deck[tgt].origOwner = nullptr;
		g->discard.push_back(tgt);
	}
	bool sacrifice(int tgt) {

		//int temp;
		//// temp will hold the card number of the tgt card if it exists, -1 if it does not.
		//if (tgt <= 64) temp = stable.unicorns[g->searchCards(stable.unicorns, tgt)];
		//if (tgt >= 90 && tgt <= 104) temp = g->searchCards(stable.upgrades, tgt);
		//if (tgt >= 105 && tgt <= 110) temp = g->searchCards(stable.downgrades, tgt);

		//// Card wasn't found or was wrong type
		//if (temp < 0) return false;

		if (tgt <= 64) {
			for (int i = 0; i < stable.unicorns.size(); i++) {
				// If the card is a unicorn and exists in the stable
				if (stable.unicorns[i] == tgt) {
					
					// If the player has a 'on sacrifice' or 'on card leaving stable' flag
					
					for (int i = 0; i < onSacrTgts.size(); i++) {
						
					}// TODO complete this
					if (onExitTgts.size() > 0) {}; // TODO complete this

					// If the card has a 'if sacrificed' action
					if (g->deck[tgt].onSacr) g->deck[tgt].onSacrAction();
					
					// TODO test that the correct unicorn is erased
					stable.unicorns.erase(stable.unicorns.begin() + i);
					// Push to the top of the discard pile - back = top
					g->discard.push_back(tgt);
				}
			}
		}
		
		// If tgt is an upgrade
		if (tgt >= 90 && tgt <= 104) {}

		// If tgt is a downgrade
		if (tgt >= 105 && tgt <= 110) {}

	};
	bool steal();
	bool destroy() {
		// Contains the unicorns in play
		vector<int> options;

		// Print table
		for (int i = 0; i < g->players.size(); i++) {
			
			// Skip the current player
			if (g->players[i].name == name) continue;

			cout << g->players[i].name << "'s unicorns: \n";
			for (int unicorn : g->players[i].stable.unicorns) {
				g->deck[unicorn].show();
				options.push_back(unicorn);
			}
			cout << endl;
		}

		// Prompt the user until they choose one of the options
		int tgt = -1;
		while (g->searchCards(options, tgt) < 0) {
			cout << "\nChoose a unicorn to destroy:  ";
			// TODO add int validation
			cin >> tgt;
		}

		// Run the destroy action on the card
		if (tgt > 0) {
			g->deck[tgt].onDest();
			return true;
		}
		else return false;
	};

	bool showHand() {
		cout << name << "'s hand ***********************\n";
		for (int card : hand) {
			cout << "(#" << card << ") ";
			g->deck[card].show();
		}
	};

};