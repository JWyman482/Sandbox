#include <iostream>
#include <string>

using namespace std;

class Card {
    public:
    string name;
    string desc;
    void play();
    void optionalEffect();
    void mandatoryEffect();
};

struct Rhinocorn : public Card {
    Rhinocorn() {
        name = "Rhinocorn";
        desc = "If this card is in your stable at the beginning of a turn, you may destroy a unicorn card and skip to your end of turn phase.";
    }

};

onTurn() {
    // For each card in hand
    // trigger mandatory effect
    // 
};
int chooseAUnicorn();
void skipToEndOfTurn();

