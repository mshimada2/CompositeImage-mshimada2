#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include "bitmap.h"

using namespace std;

//prototypes

vector <vector <Pixel> > avgRgb(vector <vector <Pixel> > & bmp, vector <string> picList);

bool checkSize(vector <vector <Pixel> >, vector <vector <Pixel> >);


int main()

{

    Bitmap photo;
    Pixel rgb;
    string picFile;
    vector <vector <Pixel> > bmp;
    vector < vector <Pixel> > ogBmp;
    vector <string> picList;
    cout<<"Enter bitmap files to combine"<<endl;

//makes sure the user enters a file 10 times or enters done or DONE

  for(int f = 0; f < 10; f++)  //f = file

  {
  cout << "yeah I got one\n";

    cin>>picFile;

//turns the multiple files into a vector and opens them up and check to see if theyre the correct type of file (.bmp)


    if(picFile == "DONE") break;
    
    photo.open(picFile);



    

    if(photo.isImage())
    
    {
      if(picList.empty())
      {
        ogBmp = photo.toPixelMatrix();
        picList.push_back(picFile);
      }
      else
      {
        bool correctSize;
        bmp = photo.toPixelMatrix();
        correctSize = checkSize(ogBmp,bmp);
        if(correctSize == true)
        {

          picList.push_back(picFile);

        }
      }

    }
  
  else
  {


    cout<<"Error: This is not a bitmap image"<<endl;
    
    return 0;
  }
    
 
  
  if(picList.size() < 2)
  {

    cout << "A conposite image cannot be created." << endl;
  
  }
  
  else
  {
    avgRgb(bmp, picList);
    
    vector <vector <Pixel> > compositeImage = avgRgb(bmp, picList);
    photo.fromPixelMatrix(bmp);
    photo.save("composite-mshimada.bmp");
  }
    
    return 0;


}

vector <vector <Pixel> > avgRgb(vector <vector <Pixel> > & bmp, vector <string> picList)

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

        for(int y = 0; y < bmp[x].size(); y++)

        {


        for (int f = 0; f < picList.size(); f++);

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
    }

return photoComb; 

}

bool checkSize(vector <vector <Pixel> > Matrix1, vector <vector <Pixel> > Matrix2)

{

    int correctHeight;
    int correctWidth;

    correctHeight = Matrix1.size();
    correctWidth = Matrix1[0].size();

    if(correctHeight == Matrix2.size())

    {
    
      if(correctWidth == Matrix2[0].size())
      {
        return true;
      }
      else
      {
        return false;
      }

    }
    else 
    {
      return false;
    }

}
