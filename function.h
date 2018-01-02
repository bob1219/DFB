#ifndef _FUNCTION_H_
#define _FUNCTION_H_

namespace dfb
{
	namespace command
	{
		using namespace std;

		bool list();
		bool add(const char *from, const char *to);
		bool clear();
		bool run();
	}
}

#endif
