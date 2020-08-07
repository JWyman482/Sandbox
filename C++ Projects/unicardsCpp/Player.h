#pragma once

#include <vector>
#include <string>
#include "Stable.h"
#include "Game.h"

using namespace std;

class Player {
public: 
	vector<int> hand;
	Stable stable;
	string name;
	int drawPerTurn = 1;
	int discardPerTurn = 0;

	vector<int>onEnterTgts;
	vector<int>onExitTgts;
	vector<int>onSacrTgts;
	vector<int>onDestTgts;
	vector<int>onTurnTgts;

	Game* g = nullptr;

	bool draw();
	bool play();
	bool discard();
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
	bool destroy(int tgt) {

	};

	bool showCards();

};