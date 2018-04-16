#include "file_handler.h"

vector<string> FileHandler::read_from_file(const string &type, const string &to_read) {
        vector<string> lines;

        ifstream file;
        file.open(RELATIVE_PATH + type + "/" + to_read + ".txt");

        string line;
        while (!file.eof()) {
                getline(file, line);

                if (!line.empty()) {
                        lines.push_back(line);
                }
        }

        file.close();

        return lines;
}


void FileHandler::write_to_file(const string &type, const string &to_write, const vector<string> &lines) {
        ofstream file;
        file.open(RELATIVE_PATH + type + "/" + to_write + ".txt");

        for (int i=0; i<lines.size(); ++i) {
                file << lines[i] << endl;
        }

        file.close();
}
