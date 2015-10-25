int adventurerHandler(int choice1, int choice2, int choice3,
                      struct gameState* state, int handPos, int* bonus);
int smithyHandler(int choice1, int choice2, int choice3,
                  struct gameState* state, int handPos, int* bonus);
int councilRoomHandler(int choice1, int choice2, int choice3, 
                       struct gameState* state, int handPos, int* bonus);
int feastHandler(int choice1, int choice2, int choice3, struct gameState* state, 
                 int handPos, int* bonus);
int mineHandler(int choice1,  // the card to trash
                int choice2,  // the card to gain
                int choice3, struct gameState* state, int handPos,
                int* bonus);
int treasureMapHandler(int choice1, int choice2, int choice3,
                       struct gameState* state, int handPos,
                       int* bonus);