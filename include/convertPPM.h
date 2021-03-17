#define cimg_use_jpeg
#define cimg_use_png
#include <CImg.h>
#include <string>

using namespace cimg_library;

class convertPPM
{
private:
	std::string name;
	std::string originalName;
	std::string orgFileType;
	std::string type;
	std::string pathPPM;
	const std::string ppmFolder = "ppm";
	const std::string encodeFolder = "steg";
public:
	void convertToPPM(std::string& filename);
	void saveToSameFormat();
};
