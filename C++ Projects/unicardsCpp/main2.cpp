#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#include "Game.h"

using namespace std;



// 1. Choose # of players
// 2. Choose babies
// 3. Shuffle
// 4. Deal cards(based on # of players) into hand
// 5. Determine who starts
// 6. Loop(until someone gets win # of unicards
// 7. Foreach player
//	7a. Activate any beginning of turn powers
//	7b. Ask about optional card powers
//  7c.	Either draw two and skip to the next player OR Draw 1
//	7d. Choose and Play a card
//		7d1. Pause for neighs
//		7d2. if unicorn, check for win cond
//		7d3. execute card action (draw, discard, sacrifice, destroy, steal)
//		7d4. check for win cond.
//		7d5. check for hand limit and discard down

// Game State
// #/names of players
// each player
	// hand
	// stable
// deck
// draw pile
// discard pile
// nursery
// currentPlayer

int main() {
	Game g;

	while (true) {
		g.currentPlayer = ++g.currentPlayer % g.players.size();
	}
}
