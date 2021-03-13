
#include<iostream>
#include<string>
//#include "C:/Users/intel/github/cryptologyProject/CLmgLibrary/CImg.h"
#include"CLmgLibrary/CImg.h"

using namespace std;
// using namespace cimg_library;

//#include "CImg.h"
using namespace cimg_library;

class display{
public:
  void showImage(string, string, int, int);
};

void display::showImage(string filename, string title, int x, int y){
  CImg<unsigned char> image(filename.c_str()), visu(x,y,1,3,0);

  CImgDisplay main_disp(image, title.c_str());
  while (!main_disp.is_closed()) {
    main_disp.wait();
 }
}

// int main() {
//   CImg<unsigned char> image("howitwork.bmp"), visu(422,209,1,3,0);
//
//   CImgDisplay main_disp(image,"howitwork");
//   while (!main_disp.is_closed()) {
//     main_disp.wait();
//  }
//   return 0;
// }
