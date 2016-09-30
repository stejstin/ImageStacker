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
  //cout << height << " " << width;
}

int stacker::get_total_pixels(){
  int total = (height * width);
  return total;
 }

 void stacker::average(int imageNumber, vector<int> &averagered, vector<int> &averagegreen, vector<int> &averageblue)
 {
//   int totalPixels = (height * width);
//   int counter = 0;
  
//   //cout << counter << " " << totalPixels << endl;
//   for(int j = 0; j < totalPixels; j++)
//   {
//     for(int i = 0; i < imageNumber; i++)
//     {
//       if(i==0)
//       {
// 	//cout << pixels[i].red << " " << pixels[counter].red;
// 	averagered[j] = pixels[j].red + pixels[counter].red;
// 	averageblue[j] = pixels[j].blue + pixels[counter].blue;
// 	averagegreen[j] = pixels[j].green + pixels[counter].green;
// 	counter += totalPixels;
//       }
//       else
//       {
// 	averagered[i] = pixels[j].red + pixels[counter].red;
// 	averageblue[i] = pixels[j].blue + pixels[counter].blue;
// 	averagered[i] = pixels[j].green + pixels[counter].green;
// 	counter += (totalPixels);
//       }
//     }
//     //cout << counter << endl;
//     //cout << "test" << endl;
//     counter = 0;
//   }
//   //cout << "test2" << endl;
//   for(int i = 0; i < totalPixels; i++)
//   {
//     //cout << "did it make it here?" << endl;
//     averagered[i] = (averagered[i]);
//     averageblue[i] = (averageblue[i]);
//     averagegreen[i] = (averagegreen[i]);
//   }
  int totalPixels = (height * width);
  int counter = 0;
  
  //cout << counter << " " << totalPixels << endl;
  for(int j = 0; j < totalPixels; j++)
  {
    counter = j;
    for(int i = 0; i < imageNumber; i++)
    {
      if(i==0)
      {
	counter += (totalPixels);
   
	averagered[j] = (pixels[j].red + pixels[counter].red);
	averageblue[j] = (pixels[j].blue + pixels[counter].blue);
	averagegreen[j] = (pixels[j].green + pixels[counter].green);
      
       }
      
       else
	 {
      counter += (totalPixels);
      averagered[j] = (pixels[j].red + pixels[counter].red);
      averageblue[j] = (pixels[j].blue + pixels[counter].blue);
      averagegreen[j] = (pixels[j].green + pixels[counter].green);

       }
      cout << "j " << averagered[j] << endl;
    }
    cout << averagered[j] << endl;  
    // counter = 0;
  }
 
  
   for(int i = 0; i < totalPixels; i++)
   {
    averagered[i] = averagered[i]/imageNumber;
    averageblue[i] = averageblue[i]/imageNumber;
    averagegreen[i] = averagegreen[i]/imageNumber;
    cout << "i " << i << " " << averagered[i] << endl;
    }
 }

void stacker::save(vector<int> &averagered, vector<int> &averageblue, vector<int> &averagegreen)
{
  ofstream outfile("new_orion.ppm");
  outfile << magic_number << endl;
  outfile << width << " " << height << endl;
  outfile << max_color << endl;

  for(int i = 0; i < (height * width); i++)
  {
    outfile << averagered[i] << " "  << averagegreen[i] << " " << averageblue[i] << endl;
  }
}
  
