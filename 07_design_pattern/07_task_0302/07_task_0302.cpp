#include <iostream>
#include "Observer.h"

int main()
{
	Observed obj_m;
	ObserverOnWarning obj_w1;
	ObserverOnWarning obj_w2;
	ObserverOnError obj_e1("ObserverOnError.txt");
	ObserverOnError obj_e2("ObserverOnError.txt");
	ObserverOnFatalError obj_fe1("ObserverOnFatalError.txt");
	ObserverOnFatalError obj_fe2("ObserverOnFatalError.txt");

	obj_m.addObserver(&obj_w1).addObserver(&obj_w2)
		.addObserver(&obj_e1).addObserver(&obj_e2)
		.addObserver(&obj_fe1).addObserver(&obj_fe2);

	obj_m.warning("Something not good");
	obj_m.error("Something bad");
	obj_m.fatalError("Something very bad");

	obj_m.removeObserver(&obj_w1)
		.removeObserver(&obj_e1)
		.removeObserver(&obj_fe1);

	return 0;
}