// Standard Libraries
#include <iostream>
#include <cstdlib>
#include <cstring>

// Header
#include "function.h"

using namespace std;
using namespace dfb;

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		cerr << "Usage: " << argv[0] << " [command] <arguments>" << endl;
		return EXIT_FAILURE;
	}

	// process
	bool ret;
	if(!strcmp(argv[1], "list"))
		ret = command::list();
	else if(!strcmp(argv[1], "add"))
	{
		if(argc < 4)
		{
			cerr << "Usage: " << argv[0] << " add [from] [to]" << endl;
			return EXIT_FAILURE;
		}

		ret = command::add(argv[2], argv[3]);
	}
	else if(!strcmp(argv[1], "clear"))
		ret = command::clear();
	else if(!strcmp(argv[1], "run"))
		ret = command::run();
	else
	{
		cerr << "Error: Unknown command \"" << argv[1] << "\"." << endl;
		return EXIT_FAILURE;
	}

	// error check
	if(ret)
	{
		cout << "succeeded." << endl;
		return EXIT_SUCCESS;
	}
	else
	{
		cout << "failed." << endl;
		return EXIT_FAILURE;
	}
}
