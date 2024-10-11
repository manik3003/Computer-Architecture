#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll correct = 0;
ll incorrect = 0;
ll total = 0;

map<string, vector<pair<string, string> > >BHT;

string calculateHexValue(const string& pc, const string& offset, const string& operation) {
    long pcDec = strtol(pc.c_str(), nullptr, 16);

    char* endPtr;
    long offsetDec = strtol(offset.c_str(), &endPtr, 0);

    if (operation == "+") {
        pcDec += offsetDec;
    } else if (operation == "-") {
        pcDec -= offsetDec;
    }

    stringstream ss;
    ss << hex << "0x" << nouppercase << setw(8) << setfill('0') << pcDec;
    return ss.str();
}


map<string, string> readBranchTargetBuffer(const string& filename) {
    map<string, string> BTB;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return BTB;
    }

    string line;
    while (getline(file, line)&& total < 1e6) {
        total += 1;
        istringstream iss(line);
        string core, core_value, program_counter, instruction_code, i_type, instruction;
        iss >> core >> core_value >> program_counter >> instruction_code >> i_type;
        getline(iss, instruction);
        istringstream instruction_stream(instruction);

        string s, s1, target_address;
        if (i_type[0] == 'b') {
            while (instruction_stream >> s) {
                if (s == "pc") {
                    instruction_stream >> s >> s1;
                    target_address = calculateHexValue(program_counter, s1, s);
                    break;
                }
            }
            if (!file.eof()) {
                string nextline;
                getline(file, nextline);
                istringstream nextiss(nextline);
                string nextcore, nextcore_value, nextcore_pc;
                nextiss >> nextcore >> nextcore_value >> nextcore_pc;
                BTB[program_counter] = target_address;
                file.seekg(-static_cast<long>(nextline.length()) - 1, ios::cur);
                if (target_address == nextcore_pc) {
                    correct += 1;
                    BHT[program_counter].push_back({"T", "T"});
                }else {
                    incorrect += 1;
                    BHT[program_counter].push_back({"T", "NT"});
                }
            }
        }
    }
    file.close();
    return BTB;
}


int main(){
    string filename = "Recursion_test_Lab";
    map<string, string> BTB;
    BTB = readBranchTargetBuffer(filename);
    cout << "Miss : " << incorrect << endl;
    cout << "Hit : " << correct << endl;
    float accuracy = (correct * (1.0)) / ((correct + incorrect) * (1.0));
    cout << "Accuracy : " << accuracy << endl;

    ofstream outputFile;
    outputFile.open("Always_taken_TABLES.txt");

    if (!outputFile) {
        std::cerr << "Unable to open file!" << std::endl;
        return 1;
    }
    outputFile << "BRANCH TARGET BUFFER" << endl;
    outputFile << "CURRENT PC" << "  " << "TARGET ADDRESS" << endl;
    for(auto it: BTB) {
        outputFile << it.first << "  " << it.second << endl;
    }
    outputFile << endl;
    outputFile << "BRANCH HISTORY TABLE" << endl;
    for(auto it:BHT) {
        outputFile << "BHT for PC " << it.first << endl;
        outputFile << "Predicted : ";
        ll r = it.second.size();
        for(int i = 0; i <it.second.size(); i++) {
            if (i < (r-1)) {
                outputFile << it.second[i].first << " | ";
            }else {
                outputFile << it.second[i].first << endl;
            }
        } 
        outputFile << "Actual    : ";
        for(int i = 0; i <it.second.size(); i++) {
            if (i < (r-1)) {
                outputFile << it.second[i].second << " | ";
            }else {
                outputFile << it.second[i].second << endl;
            }
        } 
        outputFile << endl;

    }


    outputFile.close();






    return 0;
}