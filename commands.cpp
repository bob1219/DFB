// Standard Libraries
#include <cstdio>
#include <iostream>
#include <string>

// Header
#include "constant.h"

using namespace std;
using namespace dfb;

bool command::list()
{
	// open file
	char from_filename[FILENAME_MAX], to_filename[FILENAME_MAX];
	sprintf(from_filename, ".%csetting%cfrom", PATH_BREAK_CHARACTER, PATH_BREAK_CHARACTER);
	sprintf(to_filename, ".%csetting%cto", PATH_BREAK_CHARACTER, PATH_BREAK_CHARACTER);
	ifstream from_fs(from_filename), to_fs(to_filename);
	if(from_fs.fail() || to_fs.fail())
		return false;

	// print result
	cout << "from\tto" << endl;
	string from_line, to_line;
	while(getline(from_fs, from_line) && getline(to_fs, to_line))
		cout << from_line << "\t" << to_line << endl;

	return true;
}

bool command::add(const char *from, const char *to)
{

	// open file
	char from_filename[FILENAME_MAX], to_filename[FILENAME_MAX];
	sprintf(from_filename, ".%csetting%cfrom", PATH_BREAK_CHARACTER, PATH_BREAK_CHARACTER);
	sprintf(to_filename, ".%csetting%cto", PATH_BREAK_CHARACTER, PATH_BREAK_CHARACTER);
	ifstream from_fs(from_filename, ios_base::in | ios_base::app), to_fs(to_filename, ios_base::in | ios_base::app);
	if(from_fs.fail() || to_fs.fail())
		return false;

	// write
	from_fs << from << endl;
	to_fs << to << endl;

	return true;
}