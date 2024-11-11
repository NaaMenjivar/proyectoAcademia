#ifndef NODOPERIODO_H
#define NODOPERIODO_H
#pragma once
#include "periodo.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class periodo;

class nodoPeriodo {
private:
	periodo* p;
	nodoPeriodo* sig;
public:
	nodoPeriodo(periodo*, nodoPeriodo*);
	~nodoPeriodo();
	periodo* getPeriodo();
	nodoPeriodo* getSig();
	void setPeriodo(periodo*);
	void setSig(nodoPeriodo*);
	string toString();
};

#endif