#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <time.h>
#include "globals.h"
#include "draw_char.h"
#include "card.h"
#include "war.h"
using namespace std;

int main()
{
    cout<<"test";
    srand(time(0));

    war w;
    w.init();
    w.drawDecks();
    w.game();

    cout<<"llala";

    cout<<"Hello from master";
    cout<<"Hello from dev";


    return 0;
}
