#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#define MAX_DISCARD 500

    int comp(const void* a, const void* b);
    void randomize_pile(struct gameState* state,int card_idx, int init_val);
    void randomize_basic_cards(struct gameState* state);
    void randomize_kingdom_cards(struct gameState* state, int test_card);
    void reset_deck_discard_hand(struct gameState* state);
    int shuffle_disc(int player, struct gameState *state);
    int shuffle_discard(struct gameState* state);
    int shuffle_deck(struct gameState* state);
    int randomize_supply(struct gameState* state, int test_card);
    void set_hand (struct gameState* state, int test_card);
    void print_deck_discard(struct gameState* state);
    void gen_kindom_cards(int*k,int test_card);
    void free_kc(int*k);

 #endif