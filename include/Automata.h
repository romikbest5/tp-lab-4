#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

typedef int money;
using namespace std;

enum STATES{
    OFF, COOK, WAIT, ACCEPT, CHECK, ERROR, FINISH
};

class Automata{

private:

    vector<string> menu, choices;
    money choiceCash, cash, profit;
    unordered_map<string, money> prices;
    STATES state;
    ostream * message;
    string states[7] = {"OFF", "COOK", "WAIT", "ACCEPT", "CHECK", "ERROR", "FINISH"};

    void ignore ();
    bool check(const string &);
    void reset ();
    void finish();

public:

    explicit Automata (const string &, ostream *);

    void setMenu (const string &);

    STATES getState();

    void on();

    void off();

    void coin(money d);

    void printMenu();

    void printState();

    bool choice (int);

    bool choice (string);

    void cancel();

    void cook();

    money getProfit();

};
