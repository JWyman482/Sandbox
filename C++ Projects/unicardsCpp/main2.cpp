#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#include "Game.h"

using namespace std;

int main() {
	Game g;

	while (true) {
		// Display nanny cammed hands
		for (auto player : g.players) {
			if (player.nannyCam) player.showHand();
			cout << endl;
		}

		g.currentPlayer = ++g.currentPlayer % g.players.size();
		Player* player = &g.players[g.currentPlayer];

		// Beginning of turn phase
		if (!g.skipBeg) {
			cout << player->name << "'s Beginning of Turn Phase *********\n";
			player->stable.onTurn();
		}

		// Draw phase
		if (!g.skipDraw && g.drawPile.size() > 0) {
			cout << player->name << "'s Draw Phase *********\n";
			for (int i = 0; i < player->drawPerTurn; i++) {
				player->hand.push_back(g.drawPile.back());
				g.drawPile.pop_back();
			}
		}
		
		// Action phase
		if (!g.skipAct) {

		}
		
		// End of turn phase
		if (!g.skipEnd) {
			cout << player->name << "'s End of Turn Phase *********\n";
			while (player->hand.size() > player->handLimit) {
				player->discard();
			}
		}
	}
}
