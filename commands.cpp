// Standard Libraries
#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>

// Headers
#include "constant.h"
#include "function.h"

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
	cout << "from\t\t\t\t\tto" << endl;
	string from_line, to_line;
	while(getline(from_fs, from_line) && getline(to_fs, to_line))
		cout << from_line << "\t\t\t\t\t" << to_line << endl;

	return true;
}

bool command::add(const char *from, const char *to)
{
	// open file
	char from_filename[FILENAME_MAX], to_filename[FILENAME_MAX];
	sprintf(from_filename, ".%csetting%cfrom", PATH_BREAK_CHARACTER, PATH_BREAK_CHARACTER);
	sprintf(to_filename, ".%csetting%cto", PATH_BREAK_CHARACTER, PATH_BREAK_CHARACTER);
	ofstream from_fs(from_filename, ios_base::in | ios_base::app), to_fs(to_filename, ios_base::in | ios_base::app);
	if(from_fs.fail() || to_fs.fail())
		return false;

	// write
	from_fs << from << endl;
	to_fs << to << endl;

	return true;
}

bool command::clear()
{
	char from_filename[FILENAME_MAX], to_filename[FILENAME_MAX];
	sprintf(from_filename, ".%csetting%cfrom", PATH_BREAK_CHARACTER, PATH_BREAK_CHARACTER);
	sprintf(to_filename, ".%csetting%cto", PATH_BREAK_CHARACTER, PATH_BREAK_CHARACTER);
	fstream from_fs(from_filename, ios_base::out | ios_base::trunc), to_fs(to_filename, ios_base::out | ios_base::trunc);
	if(from_fs.fail() || to_fs.fail())
		return false;

	return true;
}

bool command::run()
{
	// open file
	char from_filename[FILENAME_MAX], to_filename[FILENAME_MAX];
	sprintf(from_filename, ".%csetting%cfrom", PATH_BREAK_CHARACTER, PATH_BREAK_CHARACTER);
	sprintf(to_filename, ".%csetting%cto", PATH_BREAK_CHARACTER, PATH_BREAK_CHARACTER);
	ifstream from_fs(from_filename), to_fs(to_filename);
	if(from_fs.fail() || to_fs.fail())
		return false;

	// backup
	string from_line, to_line;
	char buf[FILE_SIZE_MAX];
	while(getline(from_fs, from_line) && getline(to_fs, to_line))
	{
		cout << "Copying \"" << from_line << "\" -> \"" << to_line << "\"...";
		ifstream backup_from_fs(from_line, ios_base::in | ios_base::binary);
		ofstream backup_to_fs(to_line, ios_base::out | ios_base::binary);
		if(backup_from_fs.fail() || backup_to_fs.fail())
		{
			cout << "Failed." << endl;
			continue;
		}

		backup_to_fs << backup_from_fs.rdbuf();

		cout << "Done." << endl;
	}

	return true;
}
