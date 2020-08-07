
# Unicards

## Summary
Unicards is a game absolutely nothing like [Unstable Unicorns]. (https://unstableunicorns.fandom.com/wiki/Unstable_Unicorns_Wiki "Nothing like this.")

Each player attempts to collect 7 unicorn cards for their 'stable.' Stables can have upgrade or downgrade cards attached to them which affect the stable. Unicorn cards themselves may have powers that affect other players in some way.

## Game Flow
Program start
Connect to an existing game
Host new game

1. Choose # of players
2. Choose deck
3. Choose babies
4. Shuffle
5. Deal cards(based on # of players) into hand
6. Determine who starts
7. Loop(until someone gets win # of unicards
8. Foreach player
	8a. Activate any beginning of turn powers
	8b. Ask about optional card powers
	8c.	Either draw two and skip to the next player OR Draw 1
	8d. Choose and Play a card
		8d1. Pause for neighs
		8d2. if unicorn, check for win cond
		8d3. execute card action (draw, discard, sacrifice, destroy, steal)
		8d4. check for win cond.
		8d5. check for hand limit and discard down


## Related Files
- main2.cpp: Holds main method.
- game
- player
- stable
- card
- cards

## Mechanics

To do: 
Review and make unicorn cards (8.2.20)
