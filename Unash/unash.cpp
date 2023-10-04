//unash.cpp (UNA Shell)

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

string readLine();
char** tokenize(string);
void printTest(char**);
bool execute(char**);

int main() {
    bool flag=1;
    string line;
    char** argList;

    while(flag) {
        cout <<"unash> ";

        line = readLine();
        argList = tokenize(line);
        //IMPORTANT: comment the next line out when done testing tokenize().
        printTest(argList);
        //***
        flag=execute(argList);
    }
}

/*
char** tokenize(string)
    This function is responsible for accepting the command string as a parameter.
    It returns a char** pointer. The function dynamically allocates an array of char* pointers equal to the number of (space delimited) words in the command string.
    Each char* pointer is dynamically allocated to exactly store one word from the command.
    Make sure the array of char* pointers pointed to by the char** pointer is NULL terminated.
    (this is what will be expected by the execvp function.)
*/
char** tokenize(string line) {
    //declare vector of c strings and stringstream object
    stringstream ss(line);
    string token;
    vector<string> tokens;

    while(ss >> token) {
        tokens.push_back(token);
    }

    char** args = new char*[tokens.size()];

    for (size_t i = 0; i < tokens.size(); i++) {
        args[i] = new char[tokens[i].length() + 1]; // +1 for null-terminator
        strcpy(args[i], tokens[i].c_str());
        args[i][tokens[i].length()] = '\0';
    }
    
    args[tokens.size()] = nullptr;
    return args;
}

/*
bool execute(char** args)
    This function accepts the char** that points to the array of poitners to C-strings.
    This function uses the fork() command to form a brand new copy fo itself with a new program.
    Call execvp properly making use of the char**. For the parent process (still running the shell program),
    it waits until the child process is terminated. Make use of waitpid for this.
*/
bool execute(char** args) {
    //PART 3 here
}

string readLine()
{
    string line;
    getline(cin, line);
    return line;
}

void printTest(char** temp) {
    int counter = 0;
    while(temp[counter] != nullptr) {
        cout<<temp[counter]<<endl;
        counter++;
    }
}