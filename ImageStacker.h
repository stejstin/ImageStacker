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
  int get_total_pixels();
  void loadFile(string file);
  void average(int imageNumber, vector<int> &averagered, vector<int> &averagegreen, vector<int> &averageblue);
  void save( vector<int> &averagered, vector<int> &averagegreen, vector<int> &averageblue);

};





#endif// end of ImageStacker_H
