#include "files.h"



Files::Files()
{
}


Files::~Files()
{
}

void Files::openCSVfile(const string filename)
{
	ifstream filein;
	filein.open(filename, ios::in);
	if (!filein.is_open())
	{
		cout << "read file error:" << filename << endl;
	}
}
