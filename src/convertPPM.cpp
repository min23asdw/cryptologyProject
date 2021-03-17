#include "convertPPM.h"

using std::string;

void convertPPM::convertToPPM(string& filename)
{
	int length = filename.size();
	int dot = filename.find_last_of('.');
	int slash = filename.find_last_of('/');

	if (dot > 0)
	{
		orgFileType = filename.substr(dot + 1, length);
		name = filename.substr(slash + 1, dot);
		string newName = name + ".ppm";

		if (orgFileType != "ppm")
		{
			CImg<unsigned char> image;
			image.load(filename.c_str());
			image.save((ppmFolder + '/' + newName).c_str());
			type = "ppm";
			filename = ppmFolder + '/' + newName;
			pathPPM = filename;
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
	}
}
