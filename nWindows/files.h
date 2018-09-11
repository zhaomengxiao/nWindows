#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class Files
{
public:
	Files();
	~Files();
	void openCSVfile(const string filename);
};

