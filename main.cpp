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
    cout<<"test 1 home";
    srand(time(0));

    war w;
    w.init();
    w.drawDecks();
    w.game();

    cout<<"llala";

    cout<<"Hello from master :)";
    cout<<"Hello from dev";
    cout<<"2"<<endl;


    return 0;
}
