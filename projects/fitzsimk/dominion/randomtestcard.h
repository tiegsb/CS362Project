#ifndef RANDOMTESTCARD_H
#define RANDOMTESTCARD_H
int pick_trash_card(struct gameState * state);
int cost_legal(int trash_card, int gain_card);
int test_mine(int seed);
int pick_gain_card(struct gameState * state);
int is_treasure(int card);

#endif