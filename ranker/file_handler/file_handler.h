#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <fstream>
#include <vector>

using namespace std;

#define RELATIVE_PATH "../data/"

class FileHandler {
	public:
		vector<string> read_from_file(const string &type, const string &to_read);

		void write_to_file(const string &type, const string &to_write, const vector<string> &lines);
};

#endif
