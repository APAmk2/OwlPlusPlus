#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <bitset>

using namespace std;

void replaceAll(string& str, const string& from, const string& to) {
    if(from.empty())
        return;
    string wsRet;
    wsRet.reserve(str.length());
    size_t start_pos = 0, pos;
    while((pos = str.find(from, start_pos)) != string::npos) {
        wsRet += str.substr(start_pos, pos - start_pos);
        wsRet += to;
        pos += from.length();
        start_pos = pos;
    }
    wsRet += str.substr(start_pos);
    str.swap(wsRet); // faster than str = wsRet;
}

string crypt(string in)
{
    string output;
    for (size_t i = 0; i < in.size(); ++i)
    {
        bitset<8> bits (static_cast<unsigned char> (in[i]));
        string proc = bits.to_string<char,std::string::traits_type,std::string::allocator_type>();
        replaceAll(proc, "0", "У");
        replaceAll(proc, "1", "Г");
        output += proc;
        output += " ";
    }
    return output;
}

string decrypt(string in)
{
    string output;
    replaceAll(in, "У", "0");
    replaceAll(in, "Г", "1");
    stringstream sstream(in);
    while (sstream.good())
    {
        bitset<8> bits;
        sstream >> bits;
        unsigned char out = bits.to_ulong();
        output += out;
    }
    return output;
}
