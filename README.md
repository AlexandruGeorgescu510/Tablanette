# Tablanette
 Tablanette / Tablic / Tabinet C++ Simple Implementation
Old university assignment, implement a classic Eastern European game in C++. It is fully playable in the console, using indexes to pick cards.
Rules:
- 2 / 3 / 4 players
- first player can see the first 4 of his cards, if he likes them he can keep them. Otherwise they will be placed on the board.
- after the first player, everyone receives 6 cards, and they start playing taking turns
- during your turn you have to either take one or more cards from the board, or drop one card on the board
- after the start, the only way the board can get more cards is from players
- when the players run out of cards, they get 6 more cards each, or, if the pack does not have that many, the remaining cards are shared as equally as possible
- you can sweep the table for a "tabla" which is an additional point at the end
- if there are cards on the table at the end, the last player who had his turn collects them all.
- 10s, Aces, Jacks, Queens and Kings are worth 1 point
- each collected club card is worth an additonal point
- 10 of Diamonds and 2 of Clubs are called "cows" and are worth 2 points
- the player with most collected cards receives an additional 3 points. If two have tied for the most cards, they both receive the points.
- Winner is the one with most points.