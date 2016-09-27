/*Author: Stephen Stinson
 *Date: 9/22/16
 *Description: header file for the class stacker.
 */
#ifndef ImageStacker_H
#define ImageStacker_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class stacker{
 private:
  string magic_number; //ironically will always be th P3 value for this class.
  int width; // the image width
  int height; // the image height;
  int max_color;// the maximum color depth (this assignment it will be 255)
  
  struct pixel{
    int red;
    int green;
    int blue;
  };// this will be the struct containing the R, G, B values.
  vector <pixel> pixels;//a Vector of pixel structs storing color info. for the image.
public:
  stacker();
  void loadFile(string file);
  // void  vector<pixel> push(pixel n);

};





#endif// end of ImageStacker_H
