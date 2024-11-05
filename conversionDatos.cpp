#include "conversionDatos.h"

//string a int
int conversionDatos::conversionInt(string s) {
    stringstream ss(s);
    int result;
    ss >> result;
    return result;
}

//string a float
float conversionDatos::conversionFloat(string s) {
    stringstream ss(s);
    float result;
    ss >> result;
    return result;
}

//string a bool
bool conversionDatos::conversionBool(string s) {
    return (s == "1" || s == "true");
}

//int a string
string conversionDatos::convInt(int v) {
    stringstream ss;
    ss << v;
    return ss.str();
}

//float a string
string conversionDatos::convFloat(float v) {
    stringstream ss;
    ss << v;
    return ss.str();
}

//bool a string
string conversionDatos::convBool(bool v) {
    return v ? "1" : "0";
}

