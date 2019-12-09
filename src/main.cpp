#include <iostream>
#include "game.h"
#include "agent/human.h"
#include "agent/dqn.h"
#include <torch/torch.h>
#include <ctime>
using namespace std;


int main() {
    Human human_b(BLACK), human_w(WHITE);
    DQN comp_b(BLACK), comp_w(WHITE);
    Agent *player_b, *player_w;
    int count = 0;
    while(true) {
        cout << "Enter a number to select which mode you want to play in:" << endl;
        cout << "1. Human (black) vs Human (white)" << endl;
        cout << "2. Human (black) vs Computer (white)" << endl;
        cout << "3. Computer (black) vs Computer (white)" << endl;
        cout << "0. Quit" << endl;
        int i;
        cin >> i;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        while (cin.fail() || i < 0 || i > 3) {
            cout << "You entered a wrong value. Try again: ";
            cin >> i;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        if(i == 0) break;

        player_b = i != 3 ? (Agent *) &human_b : (Agent *) &comp_b;
        player_w = i == 1 ? (Agent *) &human_w : (Agent *) &comp_w;

        cout << "Game " << ++count << " started!" << endl;
        clock_t begin = clock();

        Game game(player_b, player_w, true);
        game.play();

        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

        cout << "Game " << i << " took " << elapsed_secs << " sec" << endl << endl;
    }
    return 0;
}
