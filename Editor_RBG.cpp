#include<bits/stdc++.h>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE][RGB];
unsigned char tempimage[SIZE][SIZE][RGB];



void menu ();
void loadImageMain ();
void loadExtraImage ();
void saveImage ();
void black_white ();
void gray ();
void invertImage ();
void merge ();
void flipImage();
void rotateImage();
void brightness();
void detectEdges();
void enlargeImage();
void shrinkImage();
void mirrorImage();
void shuffleImage();
void cropImage();
void blurImage();
void skewRight();
void skewUp();



int main()
{
  cout<<"Ahlan ya user ya habibi (^-^) \n";
  loadImageMain();
  menu();
  return 0;
}



void menu () {
  bool end = false; 
  while (!end){
    char x; 
    cout<<"Please select a filter to apply or 0 to exit:\n";
    cout<<"1- Black & White Filter\n";
    cout<<"2- gray Filter\n";
    cout<<"3- Invert Filter\n";
    cout<<"4- Merge Filter\n";
    cout<<"5- Flip Image\n";
    cout<<"6- Darken and Lighten Image\n";
    cout<<"7- Rotate Image\n";
    cout<<"8- Detect Image Edges\n";
    cout<<"9- Enlarge Image\n";
    cout<<"a- Shrink Image\n";
    cout<<"b- Mirror 1/2 Image\n";
    cout<<"c- Shuffle Image\n";
    cout<<"d- Blur Image\n";
    cout<<"e- Crop Image\n";
    cout<<"f- Skew Image Right\n";
    cout<<"g- Skew Image Up\n";
    cout<<"0- Exit \n";
    cin>>x;
    if (x=='1'){
        black_white();
        saveImage ();
    }

    if (x=='2'){
        gray();
        saveImage ();
    }

    if (x=='3'){
        invertImage();
        saveImage ();
    }
    if (x=='4'){
        merge();
        saveImage ();
    }
    if (x=='5'){
        flipImage();
        saveImage ();
    }
    if (x=='6'){
        brightness();
        saveImage ();
    }
    if (x=='7'){
        rotateImage();
        saveImage ();
    }
    if (x=='8'){
        detectEdges();
        saveImage ();
    }
    if (x=='9'){
        enlargeImage();
        saveImage ();
    }
    if (x=='a'){
        shrinkImage();
        saveImage ();
    }
    if (x=='b'){
        mirrorImage();
        saveImage ();
    }
    if (x=='c'){
        shuffleImage();
        saveImage ();
    }
    if (x=='d'){
        blurImage();
        saveImage ();
    }
    if (x=='e'){
        cropImage();
        saveImage ();
    }
    if (x=='f'){
        skewRight();
        saveImage ();
    }
    if (x=='g'){
        skewUp();
        saveImage ();
    }
    if (x=='0'){
        end=true;
    } 
    
  }
   
}

//_________________________________________
void loadImageMain () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, image);
}
//_________________________________________
void loadExtraImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, tempimage);
}
//_________________________________________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, image);
}
//_________________________________________
void black_white () { 
   int sum=0, avr=0;
   // calculate the average of all the pexels in the picture
    for (int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE ; j++)
        {
         sum = image[i][j][0]+image[i][j][1]+image[i][j][2];
         avr+=sum;
        }
    }
    avr/=(256*256*3);

    for (int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE ; j++)
        {
         int t = image[i][j][0]+image[i][j][1]+image[i][j][2];
         if (t/3>(avr)){
            image[i][j][0]=255; //white
            image[i][j][1]=255;
            image[i][j][2]=255;

         }

         else {
            image[i][j][0]=0; //black
            image[i][j][1]=0;
            image[i][j][2]=0;

         }
         
        }
    }
}
//_________________________________________

void gray () { //extra
/*
main idea here is than the average of every pexel's three colors will give us degree of gray representing it
*/
    for (int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE ; j++)
        {
         int t = (image[i][j][0]+image[i][j][1]+image[i][j][2])/3;
         
            image[i][j][0]=t;
            image[i][j][1]=t;
            image[i][j][2]=t;

         }
         
        }
    }

 //_________________________________________
void invertImage () { //2
    for (int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE ; j++)
        {
         
            image[i][j][0]=255-image[i][j][0];
            image[i][j][1]=255-image[i][j][1];
            image[i][j][2]=255-image[i][j][2];

         }
         
        }
    }
  
//_________________________________________

void merge () { //3
   loadExtraImage();
    for (int i=0 ; i<SIZE ; i++)
    {
        for(int j=0 ; j<SIZE ; j++)
        {
         
            image[i][j][0]=(image[i][j][0]+tempimage[i][j][0])/2;
            image[i][j][1]=(image[i][j][1]+tempimage[i][j][1])/2;
            image[i][j][2]=(image[i][j][2]+tempimage[i][j][2])/2;

         }
         
        }
    }
//_________________________________________

void flipImage() { //4
  char c ; cout<<"Flip (h)orizontally or (v)ertically ?"; cin>>c;

  if (c=='h')
  { 
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
         for (int k=0 ; k<3 ; k++)
         {
          // row is same , coloumn changes
            tempimage[i][j][k]=image[i][SIZE-1-j][k];
         }
     }
  }

}

else
{
   for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
         for(int k=0 ; k<3 ; k++)
         {
          //coloumn is same , row changer
            tempimage[i][j][k]=image[SIZE-1-i][j][k];
         }
     }
  }
}

for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
         for(int k =0 ; k<3 ; k++)
         {
          // copy our temp photo into out original photo to print it out
            image[i][j][k]=tempimage[i][j][k];
         }
        
     }
  }
 }

//_________________________________________

 void rotateImage() { 
  int c ; cout<<"Rotate (90), (180) or (270) degrees? ?"; cin>>c;

  if (c==90)
  { 
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
         for(int k=0 ; k<3 ; k++)
         {
          // first row turns to be last column and so on
            tempimage[i][j][k]=image[SIZE-1-j][i][k];
         }
        
     }
  }
  }


  else if (c==180)
  {
   for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
         for(int k=0 ; k<3 ; k++)
         {
          // first row turns to be inverted last row and so on
            tempimage[i][j][k]=image[SIZE-1-i][SIZE-1-j][k];
         }
     }
  }
} 

else 
{
  for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
         for(int k=0 ; k<3 ; k++)
         {
          // first row turns to be inverted first column and so on
            tempimage[i][j][k]=image[j][SIZE-1-i][k];
         }
     }
  }
}

// copy our temp photo into out original photo to print it out
for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
         for(int k=0 ; k<3 ; k++)
         {
            image[i][j][k]=tempimage[i][j][k];
         }
     }
  }
  }
//_________________________________________

  void brightness() { 
    char c; float p = 0.50;
    cout<<"Do you want to (d)arken or (l)ighten? ";
    cin>>c;

    if (c=='l')
    {
      for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
         for(int k=0 ; k<3 ; k++)
         {
          // to make sure not to exceed the highest available value
          if (image[i][j][k]+(p*image[i][j][k])>=255)
          {
            image[i][j][k]=255;
          }
          else 
          {
            image[i][j][k]=image[i][j][k]+(p*image[i][j][k]);
          }

         }
          
      }
    }
    }

    else
    {
      for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
         for(int k=0 ; k<3 ; k++)
         {
          // to make sure not to exceed the lowest available value
          if (image[i][j][k]-(p*image[i][j][k])<=0)
          {
            image[i][j][k]=0;
          }
          else
          { 
            image[i][j][k]=image[i][j][k]-(p*image[i][j][k]);
          }
         }
      }
    }
  }
}
//_________________________________________
void enlargeImage() { //8 
int n;
cout<<"Which quarter to enlarge 1, 2, 3 or 4? ";  
cin>>n;
if (n==1)
{
  for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++){
         for(int k=0 ; k<3 ; k++)
         {
          //douple every pexel in its column and row
            tempimage[i][j][k]=image[i/2][j/2][k];
         }
        }
      }
}

if (n==2)
{
  for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++){
         for(int k=0 ; k<3 ; k++)
         {
          //changing starting point of the copied pexels , and same logic as before
            tempimage[i][j][k]=image[(i)/2][(j+256)/2][k];
        }
      }
    }
}

if (n==3)
{
  for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++){
      for(int k=0 ; k<3 ; k++)
      {
            tempimage[i][j][k]=image[(i+256)/2][(j)/2][k];
      }
    }
  }
}

if (n==4)
{
  for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++){
        for(int k=0 ; k<3 ; k++)
        {
            tempimage[i][j][k]=image[(i+256)/2][(j+256)/2][k];
        }
    }
  }
}

// copy tempImage into our original image so we can save it
for (int i = 0; i < SIZE; i++) {
  for (int j = 0; j< SIZE; j++) {
    for(int k=0 ; k<3 ; k++)
     {
        image[i][j][k]=tempimage[i][j][k];
     }
  }
}

}
//_________________________________________
void shrinkImage() { 

//make temp image all white
for (int i=0 ; i<SIZE ; i++){
  for (int j = 0; j< SIZE; j++){ 
     for(int k =0 ; k<3  ; k++)
        {
              tempimage[i][j][k]=255;
        }
    }
}

string n;
cout<<"Shrink to (1/2), (1/3) or (1/4)? ";
cin>>n;

if (n=="1/2")
{
  for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++){
      for(int k =0 ; k<3  ; k++)
      {
        // to make sure not to exceed the range available
        if(i*2<=255 && j*2<=255)
        {
          //shrink every pexel to half of its size in every column and row by skipping two pexels every loop
          tempimage[i][j][k]=image[i*2][j*2][k];
        }
      }
    }
  }
}

if (n=="1/4")
{
  for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++){
      for(int k =0 ; k<3  ; k++)
      {
        if(i*4<=255 && j*4<=255)
        {
          tempimage[i][j][k]=image[i*2][j*2][k];
        }
      }
    }
  }
}

if (n=="1/3")
{
  for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++){
      for(int k =0 ; k<3  ; k++)
      {
        if(i*3<=255 && j*3<=255)
        {
          tempimage[i][j][k]=image[i*2][j*2][k];
        }
      }
    }
  }
}

// copy tempImage into our original image so we can save it
for (int i = 0; i < SIZE; i++) {
  for (int j = 0; j< SIZE; j++) {
    for(int k=0 ; k<3 ; k++)
     {
        image[i][j][k]=tempimage[i][j][k];
     }
  }
}
}
//_________________________________________
void mirrorImage() { 
    cout<<"Mirror (l)eft, (r)ight, (u)pper, (d)own side? "; 
    char x;
    cin>>x;
    if (x=='l')
    {
      for(int i=0 ; i<SIZE ; i++){
        for (int j=0 ; j<128 ; j++){
         for(int k=0 ; k<3 ; k++){
          // copy the remaining part from original image to temp image
            tempimage[i][j][k]=image[i][j][k];
         }
        }
      }

      for(int i=0 ; i<SIZE ; i++){
        for (int j=127 ; j<256 ; j++){
         for(int k=0 ; k<3 ; k++)
         {
          // copy the inverse of the previous part
            tempimage[i][j][k]=tempimage[i][SIZE-2-j][k];
         }
        }
      }
    }
    // same applied technique from above with different indexes

    if (x=='r')
    {
      for(int i=0 ; i<SIZE ; i++){
        for (int j=127 ; j<256 ; j++){
           for(int k=0 ; k<3 ; k++)
          {
            tempimage[i][j][k]=image[i][j][k];
         }
        }
      }

      for(int i=0 ; i<SIZE ; i++){
        for (int j=0 ; j<128 ; j++){
         for(int k=0 ; k<3 ; k++)
         {
            tempimage[i][j][k]=tempimage[i][SIZE-1-j][k];
         }
        }
      }
    }

    if (x=='u')
    {
      for(int i=0 ; i<128 ; i++){
        for (int j=0 ; j<SIZE ; j++){
          for(int k=0 ; k<3 ; k++)
          {
            tempimage[i][j][k]=image[i][j][k];
         }
        }
      }

      for(int i=127 ; i<256 ; i++){
        for (int j=0 ; j<SIZE ; j++){
         for(int k=0 ; k<3 ; k++)
         {
            tempimage[i][j][k]=tempimage[SIZE-2-i][j][k];
         }
        }
      }
    }


    if (x=='d')
    {
      for(int i=127 ; i<256 ; i++){
        for (int j=0 ; j<SIZE ; j++){
          for(int k=0 ; k<3 ; k++)
          {
            tempimage[i][j][k]=image[i][j][k];
         }
        }
      }

      for(int i=0 ; i<128 ; i++){
        for (int j=0 ; j<SIZE ; j++){
         for(int k=0 ; k<3 ; k++)
         {
            tempimage[i][j][k]=tempimage[SIZE-2-i][j][k];
         }
        }
      }
    }

  // copy temp image into original image to save it
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
        for(int k=0 ; k<3 ; k++)
        {
            image[i][j][k]=tempimage[i][j][k];
         }
     }
}
}
//_________________________________________
void shuffleImage() { 
cout<<"New order of quarters? ";  
bool x = true;
int first , second , third , fourth;
cin>>first>>second>>third>>fourth;
while (x)
{ // making sure to take input until it's available
if ((first>4 || first<1) || (second>4 || second<1) || (third>4 || third<1) || (fourth>4 || fourth<1))
{
  cout<<"Wrong input , please inter new order of quarters: ";
  cin>>first>>second>>third>>fourth;
}
else
{
  x=false;
}
}

/* 
every loop checks for every quarter possibility,
then determine which indexes to use and copy them into temp image.
*/

for (int i = 0; i < 128; i++) {
      for (int j = 0; j< 128; j++) {
         for(int k=0 ; k<3 ; k++)
         {
        if(first==1)
        {
          tempimage[i][j][k]=image[i][j][k];
        }
        if(first==2)
        {
          tempimage[i][j][k]=image[i][j+127][k];
        }
        if(first==3)
        {
          tempimage[i][j][k]=image[i+127][j][k];
        }
        if(first==4)
        {
          tempimage[i][j][k]=image[i+127][j+127][k];
        }
       }
     }
    }

    for (int i = 0; i < 128; i++) {
      for (int j = 127; j< 256; j++) {
         for(int k=0 ; k<3 ; k++)
         {
        if(second==1)
        {
          tempimage[i][j][k]=image[i][j-127][k];
        }
        if(second==2)
        {
          tempimage[i][j][k]=image[i][j][k];
        }
        if(second==3)
        {
          tempimage[i][j][k]=image[i+127][j-127][k];
        }
        if(second==4)
        {
          tempimage[i][j][k]=image[i+127][j][k];
        }
        }
     }
    }

    for (int i = 127; i < 256; i++) {
      for (int j = 0; j< 128; j++) {
         for(int k=0 ; k<3 ; k++)
         {
        if(third==1)
        {
          tempimage[i][j][k]=image[i-127][j][k];
        }
        if(third==2)
        {
          tempimage[i][j][k]=image[i-127][j+127][k];
        }
        if(third==3)
        {
          tempimage[i][j][k]=image[i][j][k];
        }
        if(third==4)
        {
          tempimage[i][j][k]=image[i][j+127][k];
        }
        }
     }
    }

    for (int i = 127; i < 256; i++) {
      for (int j = 127; j< 256; j++) {
         for(int k=0 ; k<3 ; k++)
         {
        if(fourth==1)
        {
          tempimage[i][j][k]=image[i-127][j-127][k];
        }
        if(fourth==2)
        {
          tempimage[i][j][k]=image[i-127][j][k];
        }
        if(fourth==3)
        {
          tempimage[i][j][k]=image[i][j-127][k];
        }
        if(fourth==4)
        {
          tempimage[i][j][k]=image[i][j][k];
        }
       }
     }
    }

for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
         for(int k=0 ; k<3 ; k++)
         {
        image[i][j][k]=tempimage[i][j][k];
     }
    }
}
}
//_________________________________________
void cropImage() { 

for (int i=0 ; i<SIZE ; i++){
   for (int j = 0; j< SIZE; j++) {
   for(int k=0 ; k<3 ; k++)
   {
    //make temp image all white
      tempimage[i][j][k]=255;
   }
   }
}

int x , y , l , w ;
cout<<"Please enter x y l w: "; 
cin>>x>>y>>l>>w;

//assigning input values as starting and ending points to keep pexels between them in temp image

for(int i= x ; i<=(x+l) ; i++){
  for(int j=y ; j<=(y+w) ; j++){
   for(int k =0 ; k<3 ; k++)
   {
      tempimage[i][j][k]=image[i][j][k];
   }
  }
}

// to copy temp image into our original image
for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
         for(int k=0 ; k<3 ; k++)
         {
        image[i][j][k]=tempimage[i][j][k];
     }
    }
}
}
//_________________________________________
void blurImage(){
  int avr;
/*
the main idea is to calculate the average of surrounding pexels (as in matrix(3*3))
and assign this average value into the middle pexel
*/
for (int x=0 ; x<5 ; x++){ // to enhance the degree of blur
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
        for(int k=0 ; k<3 ; k++){ 
        // corner conditions
        if(i==0 && j==0)
        {
          avr=(image[i][j][k]+image[i][j+1][k]+image[i+1][j][k]+image[i+1][j+1][k])/4;
        }
        else if(i==0 && j==255)
        {
          avr=(image[i][j][k]+image[i][j-1][k]+image[i-1][j][k]+image[i-1][j-1][k])/4;
        }
        else if(i==255 && j==0)
        {
          avr=(image[i][j][k]+image[i-1][j][k]+image[i][j+1][k]+image[i-1][j+1][k])/4;
        }
        else if(i==255 && j==255)
        {
          avr=(image[i][j][k]+image[i-1][j][k]+image[i][j-1][k]+image[i-1][j-1][k])/4;
        }

        //edge conditions
        else if((i==0 && j!=0) && (i==0 && j!=255))
        {
          avr=(image[i][j][k]+image[i][j+1][k]+image[i+1][j][k]+image[i+1][j+1][k]+image[i-1][j][k]+image[i][j-1][k])/6;
        } 
        else if ((i==255 && j!=0) && (i==255 && j!=255))
        {
          avr=(image[i][j][k]+image[i][j+1][k]+image[i-1][j][k]+image[i-1][j+1][k]+image[i-1][j-1][k]+image[i][j-1][k])/6;
        }
        else if( (i!=0 && j==0) && (i!=255 && j==0))
        {
          avr=(image[i][j][k]+image[i][j+1][k]+image[i-1][j][k]+image[i-1][j+1][k]+image[i+1][j+1][k]+image[i+1][j][k])/6;
        } 
        else if( (i!=0 && j==255) && (i!=255 && j==255))
        {
          avr=(image[i][j][k]+image[i][j-1][k]+image[i-1][j][k]+image[i-1][j-1][k]+image[i+1][j-1][k]+image[i+1][j][k])/6;
        }

        //other pexels
        else
        {
          avr=(image[i][j][k]+image[i][j-1][k]+image[i-1][j][k]+image[i-1][j-1][k]+image[i+1][j][k]+image[i][j+1][k]+image[i+1][j+1][k]+image[i-1][j+1][k]+image[i+1][j-1][k])/9;
        }

        tempimage[i][j][k]=avr; //assigning average value into the pexel in temp image
     }
    }
  }

// to copy temp image into our original image
for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
         for(int k=0 ; k<3 ; k++)
         {
        image[i][j][k]=tempimage[i][j][k];
     }
    }
}
}

}

//_________________________________________
void detectEdges(){ // better edge method

  for(int i=0 ; i<SIZE ; i++){
    for(int j=0 ; j<SIZE ; j++)
    {
         int avr , lavr , favr , cavr;
         //  averages to compare with the pexel for every color
         avr=(image[i][j][0]+image[i][j][1]+image[i][j][2])/3;
         lavr=(image[i+1][j][0]+image[i+1][j][1]+image[i+1][j][2])/3;
         favr=(image[i][j+1][0]+image[i][j+1][1]+image[i][j+1][2])/3;
         cavr=(image[i+1][j+1][0]+image[i+1][j+1][1]+image[i+1][j+1][2])/3;

         if(abs(avr-lavr)>=33 || abs(avr-favr)>=33 || abs(avr-cavr)>=33 ){
            image[i][j][0]=0;
            image[i][j][1]=0;
            image[i][j][2]=0;

         }
         else{
            image[i][j][0]=255;
            image[i][j][1]=255;
            image[i][j][2]=255;

         }
         
    }
  }
}

//_________________________________________
void skewRight(){ //vertical  skewRight
cout<<"Please enter degree to skew right: "; 
double degree; 
cin>>degree; 
degree = 90 - degree; 
degree = ( degree*22)/(180*7); // to convert the degree into radian
double x = tan(degree);
double shrinkval= (256 / (1+(1/x))); 
double move = SIZE - shrinkval ;  // starting point of the picture
double step = move / SIZE ;  // change of movement along the picture
shrinkval = shrinkval / SIZE ; 
shrinkval = 1/shrinkval;


for (int i=0 ; i<SIZE ; i++){
   for (int j = 0; j< SIZE; j++) 
        {for(int k=0 ; k<3 ; k++){
          // to make temp image all white
              tempimage[i][j][k]=255;}
        }
}

for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
        if(j*shrinkval<=255)
        {
          // to shrink the picture
        tempimage[i][j][0]=image[i][int(j*shrinkval)][0];
        tempimage[i][j][1]=image[i][int(j*shrinkval)][1];
        tempimage[i][j][2]=image[i][int(j*shrinkval)][2];
        }
     }
    }
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
      for(int k=0 ; k<3 ; k++)
      {// copy rwmp image into original image
        image[i][j][k]=tempimage[i][j][k];
     }}
}

for (int i=0 ; i<SIZE ; i++){
   for (int j = 0; j< SIZE; j++){ 
   for(int k=0 ; k<3 ; k++)
        { //// to make temp image all white
              tempimage[i][j][k]=255;}
        }
}

for (int i=0 ; i<SIZE ; i++){
   for (int j = move; j< SIZE; j++) 
        {
              tempimage[i][j][0]=image[i][j-int(move)][0];
              tempimage[i][j][1]=image[i][j-int(move)][1];
              tempimage[i][j][2]=image[i][j-int(move)][2];
        }
        move-=step;
}


for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
      for(int k=0 ; k<3 ; k++)
      {// copy rwmp image into original image
        image[i][j][k]=tempimage[i][j][k];
     }}
}



}
//_________________________________________
void skewUp(){ //horizontal
/*
all same as in skew right except that we loop in opposite direction to make it horizontal not vertical
*/
cout<<"Please enter degree to skew Up: "; 
double degree; 
cin>>degree; 
degree = 90 - degree; 
degree = ( degree*22)/(180*7); 
double x = tan(degree);
double shrinkval= (256 / (1+(1/x))); 
double move = SIZE - shrinkval ;  
double step = move / SIZE ; 
shrinkval = shrinkval / SIZE ; 
shrinkval = 1/shrinkval;


for (int i=0 ; i<SIZE ; i++){
   for (int j = 0; j< SIZE; j++){ 
   for(int k=0 ; k<3 ; k++)
        { //// to make temp image all white
              tempimage[i][j][k]=255;}
        }
}

for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
        
        if(i*shrinkval<=255){
        tempimage[i][j][0]=image[int(i*shrinkval)][j][0];
        tempimage[i][j][1]=image[int(i*shrinkval)][j][1];
        tempimage[i][j][2]=image[int(i*shrinkval)][j][2];
        }
        
     }
    }

for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
      for(int k=0 ; k<3 ; k++)
      {// copy rwmp image into original image
        image[i][j][k]=tempimage[i][j][k];
     }}
}

for (int i=0 ; i<SIZE ; i++){
   for (int j = 0; j< SIZE; j++){ 
   for(int k=0 ; k<3 ; k++)
        { //// to make temp image all white
              tempimage[i][j][k]=255;}
        }
}

for (int j=0 ; j<SIZE ; j++){
   for (int i = move; i< SIZE; i++) 
        { 
              tempimage[i][j][0]=image[i-int(move)][j][0];
               tempimage[i][j][1]=image[i-int(move)][j][1];
                tempimage[i][j][2]=image[i-int(move)][j][2];
        
        }
        move-=step;
}


for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
      for(int k=0 ; k<3 ; k++)
      {// copy rwmp image into original image
        image[i][j][k]=tempimage[i][j][k];
     }}
}
  
}
