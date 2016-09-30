/* Author: Stephen Stinson
 * Date: 9/22/16
 * Description: main driver for the program. a work in progress.
 */

#include "ImageStacker.h"



int main(){
  stacker test;
  string image;
  int number_of_images;
  stringstream itoa;
  string my_string;
  vector<int> average_red;
  vector<int> average_green;
  vector<int> average_blue;
  
  cout << "Enter the image you wish to stack: " << endl;
  cin >> image;
  cout << "Please enter the number of images you wish to stack: " << endl;
  cin >> number_of_images;

  if(image == "orion")
  {
    for(int i = 1; i <= number_of_images; i++)
    {
      if(i < 10){
	itoa << i;
	my_string = itoa.str();
	test.loadFile("./orion/orion_00" + my_string + ".ppm");
	cout <<"./orion/orion_00" + my_string + ".ppm" << endl;
	itoa.str("");
      }
      else if(i == 10){
	itoa << i;
	my_string = itoa.str();
	test.loadFile("./orion/orion_0" + my_string + ".ppm");
	cout << "./orion/orion_0" + my_string + ".ppm" << endl;
	itoa.str("");
	}
    }
  }
  
  for(int i = 0; i < test.get_total_pixels(); i++)
  {
    average_red.push_back(i);
    average_blue.push_back(i);
    average_green.push_back(i);
    }
  
   test.average(number_of_images,average_red, average_blue, average_green);
   test.save(average_red, average_blue, average_green);
  return 0; 
}








  
