#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
	string line;
	ifstream myfile (argv[1]); // ifstream = padrão ios:in
	//ofstream myfile (argv[1]); // ifstream = padrão ios:in
	if (myfile.is_open())
	{
		while (! myfile.eof() ) //enquanto end of file for false continua
		{
			getline (myfile,line); // como foi aberto em modo texto(padrão)
						         //e não binário(ios::bin) pega cada linha
			cout << line << endl;
		}
		myfile.close();
	}

	else cout << "Unable to open file"; 

	return 0;
}
