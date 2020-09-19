// Think through the memory ownership of the cards. For example, does the card
// exist in the deck, and then is pointed to by hands, stables, discard piles?
//
// Might make more sense to have a master deck with all the cards, then a
// seperate deck that works as a draw pile. The master deck array can be
// divided by range for each card type. The draw pile becomes an int array
// show the indexes in the master deck for the card. All other card containers
// then have pointers to the master index.
//
// If I wanted to get crazy for efficiency I could have each card container be a
// binary vector of MASTERDECK size. 48 cards/bits would be 6B for every 
// container. Otherwise 7 card hand would be at a minimum 7 x 8B integers for 56B
//
// The problem is how to keep two players from having the same card.
// Each card could have 

// Maybe card has a flag for location: draw, discard, player hand, player stable.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int DECKSIZE = 50;
const int WIN_COUNT = 7;


class Power {
	string desc;
	int target;
};

class Card {
	string name;
	string img;
	Player* owner;
	// Type codes:
	// m = magic
	// c = unicorn
	// u = upgrade
	// d = downgrade
	char type;

	bool isActive = true;
	bool mustTrigOnTurn = false;
	bool mustTrigOnLeaveStable = false;
	bool mustTrigOnEnterStable = false;
	string desc;
	void play();
	void trigger();
	void display();
};

class Player {
	string name;
	vector<int> stable;
	vector<int> hand;
	int handLimit;
	int unicorns;

	// Choose a random number from 0 - deck.size()
	// hand.push_back(result);
	// displayHand();
	// while (hand.size() > handlimit) discard();
	bool draw();

	// if hand.size() == 0 return true;
	// displayCards(hand)
	// choose a card
	// loseCard(hand, selection);
	// discard.push_back(selection);
	bool discard();

	// if stable.size() == 0 return true;
	// displayCards(stable)
	// choose a card
	// loseCard(stable, selection);
	// discard.push_back(selection);
	bool sacrifice();

	// choose a player
	// player.displayCards(player.stable);
	// choose card to destroy
	// player.loseCard(stable, selection);
	// discard.push_back(selection);
	bool destroy();

	// choose a player
	// player.displayCards(player.stable);
	// choose card to steal
	// player.loseCard(stable, selection);
	// stable.push_back(selection);
	// if selection == unicorn, unicorns++
	// checkWin();
	bool steal();

	// Clear the display
	// Loop through cards
	//		cards.display();
	void displayCards(vector<int>& cards);
	
	// int temp = cards[selection];
	// cards[selection].erase();
	bool loseCard(vector<int>& cards, int tgt);
	
	// if unicorns >= WIN_COUNT display win message 
	bool checkWin();
};

// Optional
struct Stable {
	vector<int> unicorns;
	vector<int> upgrades;
	vector<int> downgrades;
	int size() {
		return unicorns.size();
	}
	
	// determine card type by range
	// add to appropriate vector
	// if size() >= WIN_COUNT win()
	bool add(int card);

	// Display win message
	// currentPlayer.displayCards(stable)
	void win();

	
	bool remove()


};




int main(int argc, char* argv[]) {
	vector<Card> deck;
	vector<Card> discard;
	// *****Turn
	// Win check after every step
	// Any forced beginning of turn actions trigger
	// Optional triggers
	// *****Draw
	// Draw two, discard down to hand limit

}