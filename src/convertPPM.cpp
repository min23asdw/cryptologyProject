#include "convertPPM.h"
#include <iostream>

using std::string;
using std::cout;

void convertPPM::convertToPPM(string& filename)
{
	int length = filename.size();
	int dot = filename.find_last_of('.');
	int slash = filename.find_last_of('/');

	if (dot > 0)
	{
		dot++;
		slash++;
		orgFileType = filename.substr(dot, length);
		name = filename.substr(slash, dot);
		
		string newName = name + ".ppm";

		if (orgFileType != "ppm")
		{
			CImg<unsigned char> image;
			image.load(filename.c_str());
			image.save((ppmFolder + '/' + newName).c_str());
			type = "ppm";
			filename = ppmFolder + '/' + newName;
			pathPPM = filename;
			cout << "\nYour file will be converted to PPM-P6, saved at: " << pathPPM << '\n';
		}
		originalName = name + '.' + orgFileType;
	}
}

void convertPPM::saveToSameFormat()
{
	if (orgFileType == "ppm")
		return;

	if (type == "ppm")
	{
		CImg<unsigned char> image;
		image.load((encodeFolder + '/' + "steg_" + name + '.' + type).c_str());
		image.save((encodeFolder + '/' + "steg_" + name + ".bmp").c_str());
		cout << "Will convert from " << encodeFolder + '/' + "steg_" + name + '.' + type << " to "
			<< encodeFolder + '/' + "steg_" + name + ".bmp" << '\n';
	}
}
