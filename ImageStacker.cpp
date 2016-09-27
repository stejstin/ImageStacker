/* Author: Stephen Stinson
 * Date: 9/22/16
 * Description: The implementation file for the header file.
 */

#include "ImageStacker.h"




//Default constructor.
stacker::stacker(){
  magic_number = "P3";
  width = 0;
  height = 0;
  max_color = 255;

  /*pixel.red = 0;
  pixel.geen = 0;
  pixel.blue = 0;*/
}

/*stacker::push(pixel n){
  
  }*/

void stacker::loadFile(string file){
  ifstream new_input(file.c_str());

 new_input >> magic_number >> width >> height >> max_color;
  for(int i = 0; i < width; i++)
  {
    for(int j = 0; j < height; j++)
      {
	pixel Pixel;
	new_input >> Pixel.red >> Pixel.green >> Pixel.blue;
	pixels.push_back(Pixel);
      }
  }
}
