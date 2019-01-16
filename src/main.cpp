#include "Automata.h"
#include <tchar.h>

int _tmain(int argc, _TCHAR* argv[])
{
	Automata a;

	while (true)
	{
		printf("\n");
		a.printState();

		printf("Actions:\n");
		printf("1 On. 2 Off. 3 Coin. 4. Cancel. 5 Choice. 6 Check. 7 Cook. 8 Finish. 9 Quit\n");
		printf("Select action: ");
		int t;
		scanf_s("%d", &t);

		if ((t == 9) | (t == 0)) break;

		if (t == 1) a.on();
		if (t == 2) a.off();
		if (t == 3) a.coin();
		if (t == 4) a.cancel();
		if (t == 5) a.choice();
		if (t == 6) a.check();
		if (t == 7) a.cook();
		if (t == 8) a.finish();
	}
	return 0;
}

