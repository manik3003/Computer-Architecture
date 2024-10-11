#include<bits/stdc++.h>
#define ll long long int
using namespace std;

unordered_map<string, ll> mlabel;
vector<string> machinecode;
map<string, string> memory;
map<string, string> merror;
ll data_segment = 268435456;
int error_converter = 0;

int error = 0;
string outputerror1 = "";
string outputerror2 = "";


unordered_map<string, string> rc = {
    {"x0", "x0"},
    {"x1", "x1"},
    {"x2", "x2"},
    {"x3", "x3"},
    {"x4", "x4"},
    {"x5", "x5"},
    {"x6", "x6"},
    {"x7", "x7"},
    {"x8", "x8"},
    {"x9", "x9"},
    {"x10", "x10"},
    {"x11", "x11"},
    {"x12", "x12"},
    {"x13", "x13"},
    {"x14", "x14"},
    {"x15", "x15"},
    {"x16", "x16"},
    {"x17", "x17"},
    {"x18", "x18"},
    {"x19", "x19"},
    {"x20", "x20"},
    {"x21", "x21"},
    {"x22", "x22"},
    {"x23", "x23"},
    {"x24", "x24"},
    {"x25", "x25"},
    {"x26", "x26"},
    {"x27", "x27"},
    {"x28", "x28"},
    {"x29", "x29"},
    {"x30", "x30"},
    {"x31", "x31"},
    {"zero", "x0"},
    {"ra", "x1"},
    {"sp", "x2"},
    {"gp", "x3"},
    {"tp", "x4"},
    {"t0", "x5"},
    {"t1", "x6"},
    {"t2", "x7"},
    {"s0", "x8"},
    {"s1", "x9"},
    {"a0", "x10"},
    {"a1", "x11"},
    {"a2", "x12"},
    {"a3", "x13"},
    {"a4", "x14"},
    {"a5", "x15"},
    {"a6", "x16"},
    {"a7", "x17"},
    {"s2", "x18"},
    {"s3", "x19"},
    {"s4", "x20"},
    {"s5", "x21"},
    {"s6", "x22"},
    {"s7", "x23"},
    {"s8", "x24"},
    {"s9", "x25"},
    {"s10", "x26"},
    {"s11", "x27"},
    {"t3", "x28"},
    {"t4", "x29"},
    {"t5", "x30"},
    {"t6", "x31"}
};

string binary_to_hex(string s) {
    bitset<32> bits(s);
    ll decimalnum = bits.to_ulong();
    stringstream ss;
    ss << hex << decimalnum;
    string ans = ss.str();
    while (ans.size() < 8) {
        ans = '0' + ans;
    }
    ans = "0x" + ans;
    return ans;
}

string decimal_to_hex(ll number) {
    stringstream ss;
    ss << hex << number;
    string ans = ss.str();
    ans = "0x" + ans;
    return ans;
}

string decimal_to_hex1(ll number) {
    stringstream ss;
    ss << hex << number;
    string ans = ss.str();
    while (ans.size() < 8) {
        ans = '0' + ans;
    }
    ans = "0x" + ans;
    return ans; 
}

string getopcode(string input) {
    string s ="";
    if(error == 1) {
        return s;
    }
    if (input == "add" || input == "or" || input == "and" || input == "sll" || input == "slt" || input == "sra" || input == "srl" || input =="sub" || input == "xor" || input == "mul" || input == "div" || input == "rem") {
        s += "0110011";
    }else if (input == "addi" || input == "ori" || input == "andi") {
        s += "0010011";
    }else if (input == "lb" || input == "ld" || input == "lh" || input == "lw") {
        s += "0000011";
    }else if (input == "jalr") {
        s += "1100111";
    }else if (input == "sb" || input == "sw" || input == "sd" || input == "sh") {
        s += "0100011";
    }else if (input == "beq" || input == "bne" || input == "bge" || input == "blt") {
        s += "1100011";
    }else if (input == "auipc") {
        s += "0010111";
    }else if (input =="lui") {
        s += "0110111";
    }else if (input == "jal") {
        s += "1101111";
    }
    return s;
}

string getfunc3(string input) {
    string s ="";
    if(error == 1) {
        return s;
    }
    if (input == "add" || input == "sub" || input == "mul" || input == "addi" || input == "lb" || input == "jalr" || input == "sb" || input == "beq") {
        s += "000";
    }else if (input == "sll" || input == "lh" || input == "sh" || input == "bne") {
        s += "001";
    }else if (input == "slt" || input == "lw" || input == "sw") {
        s += "010";
    }else if (input == "ld" || input == "sd") {
        s += "011";
    }else if (input == "xor" || input == "blt") {
        s += "100";
    }else if (input == "sra" || input == "srl" || input == "bge") {
        s += "101";
    }else if (input == "or" || input == "rem" || input == "ori") {
        s += "110";
    }else if (input == "and" || input == "andi") {
        s += "111";
    }
    return s;
}

string getfunc7(string input) {
    string s = "";
    if(error == 1) {
        return s;
    }
    if (input == "add" || input == "and" || input == "or" || input == "sll" || input == "slt" || input == "xor") {
        s += "0000000";
    }else if (input == "mul" || input == "div" || input == "rem") {
        s += "0000001";
    }else if (input == "sra" || input == "sub") {
        s += "0100000";
    }
    return s;
}


string decimal_to_binary(int num) {
    string s = "";
    while(num > 0) {
        int rem = num % 2;
        if (rem == 0) {
            s += '0';
        }else { 
            s += '1';
        }
        num /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

string getregisternum(string input) {
    string s = "";
    if(error == 1) {
        return s;
    }
    int n = input.size();
    int register_num;
    if (n == 2) {
        register_num = stoi(input.substr(1,1));
    }else {
        register_num = stoi(input.substr(1,2));
    }
    if (register_num >= 32) {
        outputerror1 += "INVALID REGISTER NUMBER";
        error = 1;
    }else {
        s = decimal_to_binary(register_num);
        while (s.size() != 5) {
            s = '0' + s;
        }
    }
    return s;
}

string getimmediate(string input) {
    string s= "";
    if (error == 1) {
        return s;
    }
    int immediate_value;
    if (input.substr(0, 2) == "0x") {
        immediate_value = stoi(input.substr(2), nullptr, 16);
    }else {
        immediate_value = stoi(input);
    }
    if (immediate_value <=2047 && immediate_value >= -2048) {
        if (immediate_value < 0) {
            immediate_value = immediate_value & (0b111111111111);
        }
        string add = decimal_to_binary(immediate_value);
        s += add;
        while (s.size() < 12) {
            s = '0' + s;
        }
    }else {
        outputerror1 += "ERROR IN IMMEDIATE VALUE RANGE";
        error = 1;
    }
    return s;
}


string getimmediateU(string input) {
    string s = "";
    if(error == 1) {
        return s;
    }
    int immediate_value;
    if (input.substr(0, 2) == "0x") {
        immediate_value = stoi(input.substr(2), nullptr, 16);
    }else {
        immediate_value = stoi(input);
    }
    if (immediate_value >= 0 && immediate_value <= 1048575) {
        string add = decimal_to_binary(immediate_value);
        s += add;
        while (s.size() <20) {
            s = '0' + s;
        }
    }else {
        outputerror1 += "ERROR IN IMMEDIATE VALUE RANGE";
        error = 1;
    }
    return s;
}

string getformat(string input) {
    string format = "";
    if (input =="add" || input == "and" || input == "or" || input == "sll" || input =="slt" || input == "sra" || input == "srl" || input =="sub" || input =="xor" || input == "mul" || input == "div" || input == "rem") {
        format = "R";
    }else if (input == "addi" || input == "andi" || input == "ori" || input == "lb" || input == "ld" || input == "lh" || input == "lw" || input == "jalr") {
        format = "I";
    }else if (input == "sb" || input == "sw" || input == "sd" || input == "sh") {
        format = "S";
    }else if (input == "beq" || input == "bne" || input == "bge" || input == "blt") {
        format = "SB";
    }else if (input == "auipc" || input == "lui") {
        format = "U";
    }else if (input == "jal") {
        format = "UJ";
    }
    return format;
}

string R_type(vector<string> &components) {
    string ans = "";
    if (error == 1) {
        return ans;
    }
    int n = components.size();
    if (n > 4) {
        outputerror1 = "Arguments greater than 3";
        error = 1;
    }else if (n < 4) {
        outputerror1 = "Arguments less than 3";
        error = 1;
    }else {
        if (rc.find(components[1]) != rc.end() && rc.find(components[2]) != rc.end() && rc.find(components[3]) != rc.end()) {
            string a = getfunc7(components[0]);
            string b = getfunc3(components[0]);
            string c = getregisternum(rc[components[3]]);
            string d = getregisternum(rc[components[2]]);
            string e = getregisternum(rc[components[1]]);
            string f = getopcode(components[0]);
            ans = a + c + d + b + e + f;
            if (error == 1) {
                return ans;
            }
            ans = binary_to_hex(ans);
        }else {
            outputerror1 = "Invalid Instruction Format";
            error = 1;
        }
    }
    return ans;
}


string I_type(vector<string> &components) {
    string ans = "";
    if (error == 1) {
        return ans;
    }
    int n = components.size();
    if (n > 4) {
        outputerror1 = "Arguments greater than 3";
        error = 1;
    }else if (n < 4) {
        outputerror1 = "Arguments less than 3";
        error = 1;
    }else {
        if (components[0][0] == 'l') {
            if (rc.find(components[1]) != rc.end() && rc.find(components[3]) != rc.end()) {
                string a = getimmediate(components[2]);
                string b = getfunc3(components[0]);
                string c = getregisternum(rc[components[1]]);
                string d = getregisternum(rc[components[3]]);
                string e = getopcode(components[0]);
                ans = a + d + b + c + e;
                ans = binary_to_hex(ans);
            }else {
                outputerror1 = "Invalid Instruction Format";
                error = 1;
            }
        }else {
            if (rc.find(components[1]) != rc.end() && rc.find(components[2]) != rc.end()) {
                string a = getimmediate(components[3]);
                string b = getfunc3(components[0]);
                string c = getregisternum(rc[components[1]]);
                string d = getregisternum(rc[components[2]]);
                string e = getopcode(components[0]);
                ans = a + d + b + c + e;
                ans = binary_to_hex(ans);
            }else {
                outputerror1 = "Invalid Instruction Format";
                error = 1;
            }
        }
    }
    return ans;
}

string SB_type(vector<string> &components, ll pc) {
    string ans = "";
    if (error == 1) {
        return ans;
    }
    int n = components.size();
    if (n > 4) {
        outputerror1 = "Arguments greater than 3";
        error = 1;
    }else if (n < 4) {
        outputerror1 = "Arguments less than 3";
        error = 1;
    }else {
        if (rc.find(components[1]) != rc.end() && rc.find(components[2]) != rc.end()) {
            string e = components[3] + ':';
            string f;
            if(mlabel.find(e) != mlabel.end()) {
                int diff = mlabel[e] - pc;
                string binarystring;
                if (diff < 0) {
                    binarystring = bitset<13> (diff & 0b1111111111111).to_string();
                    binarystring = binarystring.substr(0, 12);
                }else {
                    binarystring = bitset<13> (diff).to_string();
                    binarystring = binarystring.substr(0, 12);
                }
                string a = getregisternum(rc[components[2]]);
                string b = getregisternum(rc[components[1]]);
                string c = getfunc3(components[0]);
                string d = getopcode(components[0]);
                ans =  binarystring[0] + binarystring.substr(2, 6) + a + b + c + binarystring.substr(8, 4) + binarystring[1] + d;
                ans = binary_to_hex(ans);
            }else {
                outputerror1 = "Invalid Label Found";
                error = 1;
            }
        }else {
            outputerror1 = "Invalid Instruction Format";
            error = 1;
        }
    }
    return ans;
}

string S_type(vector<string> &components) {
    string ans = "";
    if (error == 1) {
        return ans;
    }
    int n = components.size();
    if (n > 4) {
        outputerror1 = "Arguments greater than 3";
        error = 1;
    }else if (n < 4) {
        outputerror1 = "Arguments less than 3";
        error = 1;
    }else {
        if (rc.find(components[1]) != rc.end() && rc.find(components[3]) != rc.end()) {
            string a = getimmediate(components[2]);
            string b = getfunc3(components[0]);
            string c = getregisternum(rc[components[3]]);
            string d = getregisternum(rc[components[1]]);
            string e = getopcode(components[0]);
            ans = a.substr(0, 7) + d + c + b + a.substr(7, 5) + e;
            ans = binary_to_hex(ans);
        }else {
            outputerror1 = "Invalid Instruction Format";
            error = 1;
        }
    }
    return ans;
}

string U_type(vector<string> &components) {
    string ans = "";
    if (error == 1) {
        return ans;
    }
    int n = components.size();
    if (n > 3) {
        outputerror1 = "Arguments greater than 2";
        error = 1;
    }else if (n < 3) {
        outputerror1 = "Arguments less than 2";
        error = 1;
    }else {
        if (rc.find(components[1]) != rc.end()) {
            string a = getopcode(components[0]);
            string b = getregisternum(rc[components[1]]);
            string c = getimmediateU(components[2]);
            ans = c + b + a;
            ans = binary_to_hex(ans);
        }else {
            outputerror1 = "Invalid Instruction Format";
            error = 1;
        }
    }
    return ans;
}

string UJ_type(vector<string> &components, ll pc) {
    string ans = "";
    if (error == 1) {
        return ans;
    }
    int n = components.size();
    if (n > 3) {
        outputerror1 = "Arguments greater than 2";
        error = 1;
    }else if (n < 3) {
        outputerror1 = "Arguments less than 2";
        error = 1;
    }else {
        if (rc.find(components[1]) != rc.end()) {
            string a = getopcode(components[0]);
            string b = getregisternum(rc[components[1]]);
            string c = components[2] + ':';
            if (mlabel.find(c) != mlabel.end()) {
                int diff = mlabel[c] - pc;
                string binarystring;
                if (diff < 0) {
                    binarystring = bitset<21> (diff & 0b111111111111111111111).to_string();
                    binarystring = binarystring.substr(0, 20);
                }else {
                    binarystring = bitset<21> (diff).to_string();
                    binarystring = binarystring.substr(0, 20);
                }
                ans = binarystring[0] + binarystring.substr(10, 10) + binarystring[9] + binarystring.substr(1, 8) + b + a;
                ans = binary_to_hex(ans);
            }
        }else {
            outputerror1 = "Invalid Label Found";
            error = 1;
        }
    }
    return ans;
}


string converter(string input, int digits) {
    int n = input.size();
    int number;
    if (input.substr(0, 2) == "0x") {
        number = stoi(input.substr(2), nullptr, 16);
    }else {
        number = stoi(input);
    }
    stringstream ss;
    ss << hex << number;
    string ans = ss.str();
    if (ans.size() > digits) {
        outputerror1 = "ERROR IN DATA SEGMENT";
        error = 1;
        error_converter = 1;
    }else {
        while (ans.size() < digits) {
            ans = '0' + ans;
        }
    }
    return ans;
}

void datasegment(int &contains) {
    string inputFile;
    inputFile = "test.asm";
    ifstream inputfile(inputFile);
    string str, token;
    while (getline(inputfile, str)) {
        str.erase(0, str.find_first_not_of(" \t\r\n"));
        str.erase(str.find_last_not_of(" \t\r\n") + 1);
        if (str.empty() || str[0] == '#') {
            continue;
        }
        if (str.find(".data") != string::npos) {
            contains = 1;
            continue;
        }
        if (str.find(".text") != string::npos) {
            break;
        }
        if (contains == 1) {
            size_t commentpos = str.find('#');
            if(commentpos != string::npos) {
                str = str.substr(0, commentpos);
            }
            if (str.size() == 0) {
                continue;
            }
            istringstream iss(str);
            vector<string> components;
            while (getline(iss, token, ' ')) {
                token.erase(remove(token.begin(), token.end(), ','), token.end());
                token.erase(remove(token.begin(), token.end(), ' '), token.end());
                if (token.size() != 0) {
                    components.push_back(token);
                }
            }
            int n = components.size();
            if (n == 0){
                continue;
            }else {
                string directives = components[0];
                int i = 2;
                if (directives[directives.size()-1] == ':') {
                    if (n >= 2) {
                        directives = components[1];
                        if (directives == ".byte") {
                            while (i < n) {
                                directives = components[i];
                                string stored = converter(directives, 2);
                                if (error_converter == 0) {
                                    string address = decimal_to_hex1(data_segment);
                                    stored = "0x" + stored;
                                    memory[address] = stored;
                                    data_segment += 1;
                                }else {
                                    break;
                                }
                                i++;
                            }
                        }else if (directives == ".word") {
                            while (i < n) {
                                directives = components[i];
                                string a = converter(directives, 8);
                                if (error_converter == 0) {
                                    for (int j = 3; j >= 0; j--) {
                                        string address = decimal_to_hex1(data_segment);
                                        string b = a.substr(2*j, 2);
                                        b = "0x" + b;
                                        memory[address] = b;
                                        data_segment += 1; 
                                    }
                                }else {
                                    break;
                                }
                                i++;
                            }
                        }else if (directives == ".half") {
                            while (i < n) {
                                directives = components[i];
                                string a = converter(directives, 4);
                                if (error_converter == 0) {
                                    for (int j = 1; j >= 0; j--) {
                                        string address = decimal_to_hex1(data_segment);
                                        string b = a.substr(2*j, 2);
                                        b = "0x" + b;
                                        memory[address] = b;
                                        data_segment += 1; 
                                    }
                                }else {
                                    break;
                                }
                                i++;
                            }
                        }else if (directives == ".dword") {
                            while (i < n) {
                                directives = components[i];
                                string a = converter(directives, 16);
                                if (error_converter == 0) {
                                    for (int j = 7; j >= 0; j--) {
                                        string address = decimal_to_hex1(data_segment);
                                        string b = a.substr(2*j, 2);
                                        b = "0x" + b;
                                        memory[address] = b;
                                        data_segment += 1; 
                                    }
                                }else {
                                    break;
                                }
                                i++;
                            }
                        }else if (directives == ".asciz") {
                            while (i < n) {
                                directives = components[i];
                                int m = directives.size();
                                string a = directives.substr(1, m-1);
                                for (int j = 0; j < n-2; j++) {
                                    string address = decimal_to_hex1(data_segment);
                                    int num = int(a[j]);
                                    string c = to_string(num);
                                    string b = converter(c, 2);
                                    b = "0x" + b;
                                    memory[address] = b;
                                    data_segment += 1;
                                }
                                i++;
                            }
                        }else {
                            outputerror1 += "INVALID DIRECTIVE";
                            error = 1;
                            break;
                        }
                    }

                }else {
                    if (n >= 1) {
                        directives = components[0];
                        i = 1;
                        if (directives == ".byte") {
                            while (i < n) {
                                directives = components[i];
                                string stored = converter(directives, 2);
                                if (error_converter == 0) {
                                    string address = decimal_to_hex1(data_segment);
                                    stored = "0x" + stored;
                                    memory[address] = stored;
                                    data_segment += 1;
                                }else {
                                    break;
                                }
                                i++;
                            }
                        }else if (directives == ".word") {
                            while (i < n) {
                                directives = components[i];
                                string a = converter(directives, 8);
                                if (error_converter == 0) {
                                    for (int j = 3; j >= 0; j--) {
                                        string address = decimal_to_hex1(data_segment);
                                        string b = a.substr(2*j, 2);
                                        b = "0x" + b;
                                        memory[address] = b;
                                        data_segment += 1; 
                                    }
                                }else {
                                    break;
                                }
                                i++;
                            }
                        }else if (directives == ".half") {
                            while (i < n) {
                                directives = components[i];
                                string a = converter(directives, 4);
                                if (error_converter == 0) {
                                    for (int j = 1; j >= 0; j--) {
                                        string address = decimal_to_hex1(data_segment);
                                        string b = a.substr(2*j, 2);
                                        b = "0x" + b;
                                        memory[address] = b;
                                        data_segment += 1; 
                                    }
                                }else {
                                    break;
                                }
                                i++;
                            }
                        }else if (directives == ".dword") {
                            while (i < n) {
                                directives = components[i];
                                string a = converter(directives, 16);
                                if (error_converter == 0) {
                                    for (int j = 7; j >= 0; j--) {
                                        string address = decimal_to_hex1(data_segment);
                                        string b = a.substr(2*j, 2);
                                        b = "0x" + b;
                                        memory[address] = b;
                                        data_segment += 1; 
                                    }
                                }else {
                                    break;
                                }
                                i++;
                            }
                        }else if (directives == ".asciz") {
                            while (i < n) {
                                directives = components[i];
                                int m = directives.size();
                                string a = directives.substr(1, m-2);
                                for (int j = 0; j < a.size(); j++) {
                                    string address = decimal_to_hex1(data_segment);
                                    int num = int(a[j]);
                                    string c = to_string(num);
                                    string b = converter(c, 2);
                                    b = "0x" + b;
                                    memory[address] = b;
                                    data_segment += 1;
                                }
                                i++;
                            }
                        }else {
                            outputerror1 += "INVALID DIRECTIVE";
                            error = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
    inputfile.close();
}


void storelabel() {
    set<string> minstruction = {"add", "and", "or", "sll", "slt", "sra", "srl", "sub", "xor", "mul", "div", "rem", "addi", "andi", "ori", "lb", "ld", "lh", "lw", "jalr", "sb", "sw", "sd", "sh", "beq", "bne", "bge", "blt", "auipc", "lui", "jal"};
    ll pc = 0;
    int flag = 0;
    string inputFile;
    inputFile = "test.asm";
    ifstream inputfile(inputFile);
    string str, token;
    while (getline(inputfile, str)) {
        str.erase(0, str.find_first_not_of(" \t\r\n"));
        str.erase(str.find_last_not_of(" \t\r\n") + 1);
        if (str.empty() || str[0] == '#') {
            continue;
        }
        if (str.find(".text") != string::npos) {
            flag = 1;
            continue;
        }
        if (flag == 1) {
            size_t commentpos = str.find('#');
            if(commentpos != string::npos) {
                str = str.substr(0, commentpos);
            }
            if (str.size() == 0) {
                continue;
            }
            istringstream iss(str);
            vector<string> components;
            while (getline(iss, token, ' ')) {
                token.erase(remove(token.begin(), token.end(), ','), token.end());
                token.erase(remove(token.begin(), token.end(), ' '), token.end());
                if (token.size() != 0) {
                    components.push_back(token);
                }
                if (components.size() == 1){
                    string label = components[0];
                    if (minstruction.find(label) == minstruction.end()) {
                        if (label[label.size()-1] == ':') {
                            mlabel[label] = pc;
                        }
                    }
                }
            }
            if (components.size() > 1) {
                pc += 4;
            }
        }
    }
    inputfile.close();
}


int main(){
    set<string> minstruction = {"add", "and", "or", "sll", "slt", "sra", "srl", "sub", "xor", "mul", "div", "rem", "addi", "andi", "ori", "lb", "ld", "lh", "lw", "jalr", "sb", "sw", "sd", "sh", "beq", "bne", "bge", "blt", "auipc", "lui", "jal"};
    set<string> mdirectives = {".data", ".text", ".word", ".half", ".byte", ".dword", ".asciz"};
    ll pc = 0;
    int contains = 0;
    int file_error = 0;
    string inputFile, outputFile;
    inputFile = "test.asm";
    outputFile = "test.mc";
    ifstream inputfile(inputFile);
    if (!inputfile.is_open()) {
        outputerror1 = "Error opening Input File";
        file_error = 1;
        error = 1;
    }else {
        ofstream outputfile(outputFile);
        if (!outputfile.is_open()) {
            outputerror1 = "Error opening Output File";
            file_error = 1;
            error = 1;
            inputfile.close();
        }else {
            inputfile.close();
            outputfile.close();
        }
    }
    if (file_error == 0) {
        datasegment(contains);
        storelabel();
        inputFile = "test.asm";
        outputFile = "test.mc";
        ifstream inputfile(inputFile);
        ofstream outputfile(outputFile);
        string str, token;
        while (getline(inputfile, str)) {
            if (str.size() == 0){
                continue;
            }
            size_t commentpos = str.find('#');
            if (commentpos != string::npos) {
                str = str.substr(0, commentpos);
            }
            if (str.size() == 0){
                continue;
            }
            istringstream iss(str);
            vector<string> components;
            while (getline(iss, token, ' ')) {
                token.erase(remove(token.begin(), token.end(), ' '), token.end());
                token.erase(remove(token.begin(), token.end(), ','), token.end());
                if (token.size() != 0) {
                    components.push_back(token);
                }
            }
            int n = components.size();
            if (n > 0) {
                    string label = components[0];
                
                if (minstruction.find(label) == minstruction.end()) {
                    if (label[label.size()-1] == ':'){
                        continue;
                    }else if (mdirectives.find(label) != mdirectives.end()) {
                        continue;
                    }else {
                        outputerror1 = "Invalid Instruction";
                        error = 1;
                        break;
                    }
                }else {
                    string format = getformat(label);
                    string pchex = decimal_to_hex(pc);
                    if (format == "R") {
                        string ans = R_type(components);
                        string outputstring = pchex + "     " + ans;
                        machinecode.push_back(outputstring);
                        pc += 4;
                    }else if (format == "I") {
                        string ans = I_type(components);
                        string outputstring = pchex + "     " + ans;
                        machinecode.push_back(outputstring);
                        pc += 4;
                    }else if (format == "SB") {
                        string ans = SB_type(components, pc);
                        string outputstring = pchex + "     " + ans;
                        machinecode.push_back(outputstring);
                        pc += 4;
                    }else if (format == "S") {
                        string ans = S_type(components);
                        string outputstring = pchex + "     " + ans;
                        machinecode.push_back(outputstring);
                        pc += 4;
                    }else if (format == "U") {
                        string ans = U_type(components);
                        string outputstring = pchex + "     " + ans;
                        machinecode.push_back(outputstring);
                        pc += 4;
                    }else if (format == "UJ") {
                        string ans = UJ_type(components, pc);
                        string outputstring = pchex + "     " + ans;
                        machinecode.push_back(outputstring);
                        pc += 4;
                    }
                }
            }
        }
        if (error == 1) {
            cout << outputerror1 << endl;
        }else {
            outputfile << "MACHINE CODE STARTS HERE" << endl;
            outputfile << "PC" << "     " << "MACHINE CODE" << endl;
            for (auto it: machinecode) {
                outputfile << it << endl;
            }
            outputfile << endl;
            outputfile << endl;
            outputfile << "MEMORY STARTS HERE" << endl;
            for (auto it: memory) {
                outputfile << it.first << "   " << it.second << endl;
            }

        }
        inputfile.close();
        outputfile.close();
    }else {
        cout << outputerror1 << endl;
    }
    return 0;
}




