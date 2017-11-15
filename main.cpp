#include<iostream>
#include<string>
#include<vector>
#include "bitmap.h"

using namespace std;

//prototypes

vector <vector <Pixel> > avgRgb(vector <string>);

bool correctBmp(string);

bool correctSize(string, string);

int xSize(Bitmap);

int ySize(Bitmap);


int main()

{
    //variables
    
    Bitmap photo;
       
    int size;
    
    string picFile1;
    
    string picFile2;
    
    vector <string> picList;
    
    bool validBmp1;
    
    bool validBmp2;
    
    bool validBmp3;
    
//checks for the parameters and sees if the 

    do     
    
    {
    
    cout<<"Enter bitmap files to combine"<<endl;
    
    cin>>picFile2;
    
    validBmp1 == correctBmp(picFile2);

    if (validBmp1 == false)

    {

    cout<<"Error: File type is invalid or does not exist. Please try again. "<<endl;

    }

    else

    {

    picList.push_back(picFile2);

    }


    }

  while(validBmp1 == false);

     //next while loop takes care of the other files that come after the first one  
       
  while(picList.size() < 10 || picFile1 == "Done")
       
  {


    if(picList.size() < 10)

    {
      cout<<"Please enter another file or type in DONE to start combining files"<<endl;
      cin>>picFile1;


      if(picFile1 == "DONE")

      {

      cout<<"You have entered DONE. Start combining images"<<endl;

      break;

      }


      else if(picList.size() < 10 && picFile1 != "DONE")

      {
        validBmp2 = correctBmp(picFile1);
      
      if(validBmp2 == true)
        
      {

        validBmp3 = correctSize(picFile1, picFile2);

        if(validBmp3 == true)

        {

        picList.push_back(picFile1);


        }

    else

    {

    cout<<"Error: The file you entered is invalid and/or does not exist. Please try again. "<<endl;


    }

   }

  }

  else

  {

    cout<<"The amount of files uploaded has reached its limit of 10"<<endl;

    break;


  }
}      
 
    
    vector <vector <Pixel> > compositeImage = avgRgb(picList);
 
    if(picList.size() >= 2)
    
    {   
    
    photo.fromPixelMatrix(compositeImage);
    photo.save("composite-mshimada2.bmp");
    
    }

  else

  {
    cout<<"Error: You need at least 2 images for this program to run. Please try again. "<<endl;

  }

    return 0;

}

bool correctBmp(string picFile)

 {
    bool validBmp;
    
    Bitmap photo;

    picture.open(picFile);

    validBmp = photo.isImage();

    return validBmp;

  }


bool correctSize(string picFile1, string picFile2)

{
    Bitmap p1;
    Bitmap p2;
    
    p1.open(picFile1);
    p2.open(picFile2);

    int correctHeight1 = xSize(p1);
    int correctWidth1 = ySize(p1);
    
    int correctHeight2 = xSize(p2);
    int correctWidth2 = ySize(p2);


    if(correctHeight1 == correctHeight2)

    {
    
      return true;
      
      }


    
    if(correctWidth1 == correctWidth2)

    {

    return true;

    }

    else
    
    {

    return false;

    }



int xSize(Bitmap x)

{
    vector <vector <Pixel> > row = x.toPixelMatrix();
    
    return row.size();

 }



 int ySize(Bitmap y)

 {

    vector <vector <Pixel> > column = y.toPixelMatrix();
    return column.size();

 }

}

    vector <vector <Pixel> > avgRgb( vector <string> picRgb)

{

    vector < vector <Pixel> > photoComb;
    vector < vector <Pixel> > photoAvg;
    Bitmap bmpComb1;
    Bitmap bmpComb2;
    Pixel rgb1;
    Pixel rgb2;

    bmpComb1.open(picList[0]);
    photoComb = bmpComb1.toPixelMatrix();

    for(int x = 0; x < bmp.size(); x++)
    {

        bmpComb2.open(picList[x]);
        photoAvg = bmpComb2.toPixelMatrix();

        for(int y = 0; y < photoComb.size(); y++)

        {


        for (int f = 0; f < picList[y].size(); f++);

        {

            rgb1 = photoComb[x][y];
            rgb2 = photoAvg[x][y];

            rgb1.red = rgb1.red +rgb2.red;
            rgb1.green = rgb1.green + rgb2.green;
            rgb1.blue = rgb1.blue + rgb2.blue;
            photoComb[x][y] = rgb1;
            
        }

        }
        cout<<"The file "<< x+1<<" of "<<picList.size()<<" has been combined."<<endl;

    }

    return photoComb;
 

}


