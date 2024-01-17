using namespace std;

class war
{
public:
    int p1;
    int p2;
    vector<card> Cards;
    vector<card> hCards;
    vector<card> pcCards;
    vector<card> hCardsWar;
    vector<card> pcCardsWar;
    int cardNums=13;

    war() {}
    void init()
    {
        if(DEV)cardNums=5;
        for(int i=0; i<cardNums; i++)
        {
            for(int j=0; j<4; j++)
            {
                Cards.push_back(card(i,j));
            }
        }
        random_shuffle(Cards.begin(),Cards.end());
        for(int i=0; i<cardNums*2; i++)
        {
            hCards.push_back(Cards[i]);
        }
        for(int i=cardNums*2; i<cardNums*4; i++)
        {
            pcCards.push_back(Cards[i]);
        }
    }
    void drawDecks()
    {
        system("color 20");
        int pos;
        bool show=0;
        if(DEV)
        {
            pos=4;
            show=1;
        }
        else pos=0;
        for(int i=pcCards.size()-1; i>0; i--)
        {
            pcCards[i].draw(i*pos+15,5,show);
        }
        for(int i=hCards.size()-1; i>0; i--)
        {
            hCards[i].draw(i*pos+15,25,show);
        }
        SetConsoleCursorPosition(cnsl, {3,6});
        SetConsoleTextAttribute(cnsl,32);
        cout << "OPPONENT:";
        SetConsoleCursorPosition(cnsl, {5,26});
        SetConsoleTextAttribute(cnsl,32);
        cout << "YOU:\n\n\n";
        pcCards[0].draw(50,13,1);
        hCards[0].draw(50,18,1);
    }
    bool warPlay(int pos)
    {
        int br=3;
        bool flag = 0;

        if(pcCards[3].type>hCards[3].type)
        {
            pcCards.push_back(hCards[0]);
            pcCards.push_back(pcCards[0]);
        }
        else if(pcCards[3].type<hCards[3].type)
        {
            hCards.push_back(pcCards[0]);
            hCards.push_back(hCards[0]);
        }
        else
        {
            flag=1;
        }

        while(br>0)
        {
            if(pcCards[3].type>hCards[3].type)
            {
                pcCards.push_back(hCards[br]);
                pcCards.push_back(pcCards[br]);
            }
            else if(pcCards[3].type<hCards[3].type)
            {
                hCards.push_back(pcCards[br]);
                hCards.push_back(hCards[br]);
            }
            pcCards[br].draw(br*4+pos,13,1);
            hCards[br].draw(br*4+pos,18,1);
            pcCards.erase(pcCards.begin()+br);
            hCards.erase(hCards.begin()+br);
            br--;
        }

        pcCards.erase(pcCards.begin());
        hCards.erase(hCards.begin());

        return flag;
    }
    void game()
    {
        while(1)
        {
            if(GetAsyncKeyState(VK_SPACE))
            {
                cls(2);
                drawDecks();
                if(pcCards[0].type>hCards[0].type)
                {
                    pcCards.push_back(hCards[0]);
                    pcCards.push_back(pcCards[0]);
                    hCards.erase(hCards.begin());
                    pcCards.erase(pcCards.begin());
                }
                else if(pcCards[0].type<hCards[0].type)
                {
                    hCards.push_back(pcCards[0]);
                    hCards.push_back(hCards[0]);
                    pcCards.erase(pcCards.begin());
                    hCards.erase(hCards.begin());
                }
                else
                {
                    int i=0;
                    //while(warPlay(i*13 + 50, i)){
                    warPlay(50);
                    //i++;
                    //};


                    /// TODO update vectors
                    /// who wins
                    /// multiple wars
                }
            }
        }
    }

};
