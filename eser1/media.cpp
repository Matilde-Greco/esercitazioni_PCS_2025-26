#include <fstream>
#include <iostream>
#include <string>

using namespace std;


int main(int argc, const char *argv[]) {
	if (argc < 2) {
		cerr <<"Errore: nome del file non dato \n";
	}

	string filename=argv[1];
	ifstream ifs(filename);
	
	if (ifs.is_open()) {
		

		for ( int i=0;i<3;i++) {
			string city;
			double temp1; 
			double temp2;
			double temp3;
			double temp4;

			ifs >> city >> temp1 >> temp2 >> temp3 >> temp4;
			
			
			double somma =temp1+temp2+temp3+temp4;
			double temp =somma/4.0;
			
			cout << city <<"      "<< temp <<"\n";
		}
			
	} else {
			cerr << "errore: non posso aprire file\n";
	}
	return 0;
}




