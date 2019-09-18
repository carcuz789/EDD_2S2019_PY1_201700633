
#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

class HTML {
public:
	void InicioHTML() {
		std::ofstream outfile("IMAGEN.html");
		outfile << "<html>" << std::endl;
		outfile << "<head>" << std::endl;
		outfile << "<link rel=\"stylesheet\" href=\"template.scss\">" << std::endl;
		outfile << "</head>" << std::endl;
		outfile << "<body>" << std::endl;
		outfile << "div class=\"pixel - block\"" << std::endl;
		outfile << "<div class=\"pixelized--heart\">" << std::endl;
		outfile << " </div>" << std::endl;
		outfile << "</div>" << std::endl;
		outfile << "</body>" << std::endl;
		outfile << "</html>" << std::endl;
	}
	void CreateCss() {
		
		std::ofstream outfile("template.scss");
		outfile << "" << std::endl;

	}
};