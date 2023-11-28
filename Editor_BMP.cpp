#include<bits/stdc++.h>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char tempimage[SIZE][SIZE];


void menu ();
void loadImageMain ();
void loadImageExtra ();
void saveImage ();
void black_white();
void invertImage();
void merge();
void flipImage();
void brightness();
void rotateImage();
void detectEdges();
void enlargeImage();
void shrinkImage();
void mirrorImage();
void shuffleImage();
void blurImage();
void cropImage();
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
    cout<<"2- Invert Filter\n";
    cout<<"3- Merge Filter\n";
    cout<<"4- Flip Image\n";
    cout<<"5- Darken and Lighten Image\n";
    cout<<"6- Rotate Image\n";
    cout<<"7- Detect Image Edges\n";
    cout<<"8- Enlarge Image\n";
    cout<<"9- Shrink Image\n";
    cout<<"a- Mirror 1/2 Image\n";
    cout<<"b- Shuffle Image\n";
    cout<<"c- Blur Image\n";
    cout<<"d- Crop Image\n";
    cout<<"e- Skew Image Right\n";
    cout<<"f- Skew Image Up\n";
    cout<<"0- Exit \n";
    cin>>x;
    if (x=='1'){
        black_white();
        saveImage ();
    }
    if (x=='2'){
        invertImage();
        saveImage ();
    }
    if (x=='3'){
        merge();
        saveImage ();
    }
    if (x=='4'){
        flipImage();
        saveImage ();
    }
    if (x=='5'){
        brightness();
        saveImage ();
    }
    if (x=='6'){
        rotateImage();
        saveImage ();
    }
    if (x=='7'){
        detectEdges();
        saveImage ();
    }
    if (x=='8'){
        enlargeImage();
        saveImage ();
    }
    if (x=='9'){
        shrinkImage();
        saveImage ();
    }
    if (x=='a'){
        mirrorImage();
        saveImage ();
    }
    if (x=='b'){
        shuffleImage();
        saveImage ();
    }
    if (x=='c'){
        blurImage();
        saveImage ();
    }
    if (x=='d'){
        cropImage();
        saveImage ();
    }
    if (x=='e'){
        skewRight();
        saveImage ();
    }
    if (x=='f'){
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
   cout << "Please enter file name of the image to process: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}
//_________________________________________
void loadImageExtra () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Please enter name of image file to merge with: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, tempimage);
}
//_________________________________________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Please enter target file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}
//_________________________________________
void black_white() {
    int sum=0, avr;
    // calculate the average of all the pexels in the picture
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++)
     {
        sum+=image[i][j];
     }
    }
   avr = (sum/(SIZE*SIZE));

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) 
    {
        if (image[i][j] > avr)
        {
            image[i][j] = 255; //white
        }
        else
        {
            image[i][j] = 0; //black
        }
   
    }
  }
}
//_________________________________________
void invertImage() { 
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) 
     {
        image[i][j]=255-image[i][j];
     }
    }
}
//_________________________________________
void merge() { 
  loadImageExtra ();

    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++)
     {
        //the average of the two pictuers
        image[i][j]=(image[i][j]+tempimage[i][j])/2;
     }
    }

}
//_________________________________________
void flipImage() { 
  char c ; 
  cout<<"Flip (h)orizontally or (v)ertically? ";
  cin>>c;

   if (c=='h')
   {
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++)
     {
         // row is same , coloumn changes
        tempimage[i][j]=image[i][SIZE-1-j];
     }
  }
}

  else 
  {
   for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) 
     {
        //coloumn is same , row changer
        tempimage[i][j]=image[SIZE-1-i][j];
     }
  }
 }

// copy our temp photo into out original photo to print it out
  for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) 
     {
        image[i][j]=tempimage[i][j];
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
        for (int j = 0; j< SIZE; j++)
        {
          if (image[i][j]+(p*image[i][j])>=255) // to make sure not to exceed the highest available value
           {
            image[i][j]=255;
           }
          else 
          {
            image[i][j]=image[i][j]+(p*image[i][j]);
          }
        }
      }
    }
    else 
    {
      for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++)
        {
          if (image[i][j]-(p*image[i][j])<=0) // to make sure not to exceed the lowest available value
            {
            image[i][j]=0;
            }
          else
          { 
            image[i][j]=image[i][j]-(p*image[i][j]);
          }
        }
      }
    }
}
//_________________________________________
void rotateImage() { 
  int c ; cout<<"Rotate (90), (180) or (270) degrees? "; 
  cin>>c;

  if (c==90)
  { 
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) 
      {
        // first row turns to be last column and so on
        tempimage[i][j]=image[SIZE-1-j][i];
      }
    }
  }


  else if (c==180)
  {
   for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++)
     {
        // first row turns to be inverted last row and so on
        tempimage[i][j]=image[SIZE-1-i][SIZE-1-j];
     }
  }
} 

else
{
  for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++)
     {
      // first row turns to be inverted first column and so on
        tempimage[i][j]=image[j][SIZE-1-i];
     }
  }
}

// copy our temp photo into out original photo to print it out
for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++)
     {
        image[i][j]=tempimage[i][j];
     }
  }
}
//_________________________________________
void detectEdges(){
  for(int i=0 ; i<SIZE ; i++){
    for(int j=0 ; j<SIZE ; j++)
    { //checking the difference between pexels to decide if it is an edge or not
      if(abs(image[i][j]-image[i+1][j])>=33 || abs(image[i][j]-image[i+1][j+1])>=33 || abs(image[i][j]-image[i][j+1])>=33)
      {
        image[i][j]=0;
      }
      else
      {
        image[i][j]=255;
      }
    }
  }

}
//_________________________________________
void enlargeImage(){
  cout<<"Which quarter to enlarge 1, 2, 3 or 4? "; 
  int n; cin>>n;
  if (n==1){

  for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) 
      {
        //douple every pexel in its column and row
        tempimage[i][j]=image[i/2][j/2];
      }
    }
}

if (n==2){
  for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) 
      {
        //changing starting point of the copied pexels , and same logic as before
        tempimage[i][j]=image[(i)/2][(j+256)/2];
      }
    }
}

if (n==3){
  for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) 
      {
          tempimage[i][j]=image[(i+256)/2][(j)/2];
      }
  }
}

if (n==4){
  for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) 
      {
        tempimage[i][j]=image[(i+256)/2][(j+256)/2];
      }
  }
}

// copy tempImage into our original image so we can save it
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
        image[i][j]=tempimage[i][j];
     }
}
}

//_________________________________________
void shrinkImage(){

//make temp image all white
  for (int i=0 ; i<SIZE ; i++){
   for (int j = 0; j< SIZE; j++) 
        {
              tempimage[i][j]=255;
        }
}

  cout<<"Shrink to (1/2), (1/3) or (1/4)? "; 
  string n; cin>>n;

if (n=="1/2"){
  for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) 
      {
        // to make sure not to exceed the range available
        if(i*2<=255 && j*2<=255)
        {
          //shrink every pexel to half of its size in every column and row by skipping two pexels every loop
          tempimage[i][j]=image[i*2][j*2];
        }
      }
    }
}

if (n=="1/4"){
  for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) 
      {
        if(i*4<=255 && j*4<=255)
        {
          tempimage[i][j]=image[i*4][j*4];
        }
      }
   }
}

if (n=="1/3"){
  for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) 
      {
            if(i*3<=255 && j*3<=255){
              tempimage[i][j]=image[i*3][j*3];
            }
        }
      }
}

for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
        image[i][j]=tempimage[i][j];
     }
}
}

//_________________________________________
void mirrorImage(){
  cout<<"Mirror (l)eft, (r)ight, (u)pper, (d)own side? ";
  char x; cin>>x;
  if (x=='l'){
      for(int i=0 ; i<SIZE ; i++){
        for (int j=0 ; j<128 ; j++)
        {
          // copy the remaining part from original image to temp image
          tempimage[i][j]=image[i][j];
        }
      }

      for(int i=0 ; i<SIZE ; i++){
        for (int j=127 ; j<256 ; j++)
        { 
          // copy the inverse of the previous part
          tempimage[i][j]=tempimage[i][SIZE-2-j];
        }
      }
    }
     // same applied technique from above with different indexes
    if (x=='r'){
      for(int i=0 ; i<SIZE ; i++){
        for (int j=127 ; j<256 ; j++)
        {
          tempimage[i][j]=image[i][j];
        }
      }

      for(int i=0 ; i<SIZE ; i++){
        for (int j=0 ; j<128 ; j++)
        {
          tempimage[i][j]=tempimage[i][SIZE-1-j];
        }
      }
    }

    if (x=='u'){
      for(int i=0 ; i<128 ; i++){
        for (int j=0 ; j<SIZE ; j++)
        {
          tempimage[i][j]=image[i][j];
        }
      }

      for(int i=127 ; i<256 ; i++){
        for (int j=0 ; j<SIZE ; j++)
        {
          tempimage[i][j]=tempimage[SIZE-2-i][j];
        }
      }
    }


    if (x=='d'){
      for(int i=127 ; i<256 ; i++){
        for (int j=0 ; j<SIZE ; j++)
        {
          tempimage[i][j]=image[i][j];
        }
      }

      for(int i=0 ; i<128 ; i++){
        for (int j=0 ; j<SIZE ; j++)
        {
          tempimage[i][j]=tempimage[SIZE-2-i][j];
        }
      }
    }

    // copy temp image into original image to save it
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) 
     {
        image[i][j]=tempimage[i][j];
     }
}
}

//_________________________________________
void shuffleImage(){
  cout<<"New order of quarters ? "; 
  bool x = true;
int first , second , third , fourth;
cin>>first>>second>>third>>fourth;
while (x) // making sure to take input until it's available
{
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
      for (int j = 0; j< 128; j++) 
      {
        if(first==1)
        {
          tempimage[i][j]=image[i][j];
        }
        if(first==2)
        {
          tempimage[i][j]=image[i][j+127];
        }
        if(first==3)
        {
          tempimage[i][j]=image[i+127][j];
        }
        if(first==4)
        {
          tempimage[i][j]=image[i+127][j+127];
        }
     }
    }

    for (int i = 0; i < 128; i++) {
      for (int j = 127; j< 256; j++) 
      {
        if(second==1)
        {
          tempimage[i][j]=image[i][j-127];
        }
        if(second==2)
        {
          tempimage[i][j]=image[i][j];
        }
        if(second==3)
        {
          tempimage[i][j]=image[i+127][j-127];
        }
        if(second==4)
        {
          tempimage[i][j]=image[i+127][j];
        }
     }
    }

    for (int i = 127; i < 256; i++) {
      for (int j = 0; j< 128; j++) 
      {
        if(third==1)
        {
          tempimage[i][j]=image[i-127][j];
        }
        if(third==2)
        {
          tempimage[i][j]=image[i-127][j+127];
        }
        if(third==3)
        {
          tempimage[i][j]=image[i][j];
        }
        if(third==4)
        {
          tempimage[i][j]=image[i][j+127];
        }
     }
    }

    for (int i = 127; i < 256; i++) {
      for (int j = 127; j< 256; j++) 
      {
        if(fourth==1)
        {
          tempimage[i][j]=image[i-127][j-127];
        }
        if(fourth==2)
        {
          tempimage[i][j]=image[i-127][j];
        }
        if(fourth==3)
        {
          tempimage[i][j]=image[i][j-127];
        }
        if(fourth==4)
        {
          tempimage[i][j]=image[i][j];
        }
     }
    }

// to copy temp image into our original image
for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++)
      {
        image[i][j]=tempimage[i][j];
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
        // corner conditions
        if(i==0 && j==0)
        {
          avr=(image[i][j]+image[i][j+1]+image[i+1][j]+image[i+1][j+1])/4;
        }
        else if(i==0 && j==255)
        {
          avr=(image[i][j]+image[i][j-1]+image[i-1][j]+image[i-1][j-1])/4;
        }
        else if(i==255 && j==0)
        {
          avr=(image[i][j]+image[i-1][j]+image[i][j+1]+image[i-1][j+1])/4;
        }
        else if(i==255 && j==255)
        {
          avr=(image[i][j]+image[i-1][j]+image[i][j-1]+image[i-1][j-1])/4;
        }

        //edge conditions
        else if((i==0 && j!=0) && (i==0 && j!=255))
        {
          avr=(image[i][j]+image[i][j+1]+image[i+1][j]+image[i+1][j+1]+image[i-1][j]+image[i][j-1])/6;
        } 
        else if ((i==255 && j!=0) && (i==255 && j!=255))
        {
          avr=(image[i][j]+image[i][j+1]+image[i-1][j]+image[i-1][j+1]+image[i-1][j-1]+image[i][j-1])/6;
        }
        else if( (i!=0 && j==0) && (i!=255 && j==0))
        {
          avr=(image[i][j]+image[i][j+1]+image[i-1][j]+image[i-1][j+1]+image[i+1][j+1]+image[i+1][j])/6;
        } 
        else if( (i!=0 && j==255) && (i!=255 && j==255))
        {
          avr=(image[i][j]+image[i][j-1]+image[i-1][j]+image[i-1][j-1]+image[i+1][j-1]+image[i+1][j])/6;
        }

        //other pexels
        else
        {
          avr=(image[i][j]+image[i][j-1]+image[i-1][j]+image[i-1][j-1]+image[i+1][j]+image[i][j+1]+image[i+1][j+1]+image[i-1][j+1]+image[i+1][j-1])/9;
        }

        tempimage[i][j]=avr; //assigning average value into the pexel in temp image
     }
    }

// to copy temp image into our original image
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
        image[i][j]=tempimage[i][j];
     }
}
}

}
//_________________________________________
void cropImage(){
  //make temp image all white
  for (int i=0 ; i<SIZE ; i++){
   for (int j = 0; j< SIZE; j++) 
        {
              tempimage[i][j]=255;
        }
    }


  cout<<"Please enter x y l w: "; 
  int x , y , l , w ; 
  cin>>x>>y>>l>>w;

//assigning input values as starting and ending points to keep pexels between them in temp image

  for(int i= x ; i<=(x+l) ; i++){
  for(int j=y ; j<=(y+w) ; j++)
  {
    tempimage[i][j]=image[i][j];
  }
}

// to copy temp image into our original image
for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
        image[i][j]=tempimage[i][j];
     }
}
}
//_________________________________________
void skewRight(){ //vertical
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
        {
          // to make temp image all white
              tempimage[i][j]=255;
        }
}

for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
        if(j*shrinkval<=255)
        {
          // to shrink the picture
        tempimage[i][j]=image[i][int(j*shrinkval)];
        }
     }
    }
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) 
      {// copy rwmp image into original image
        image[i][j]=tempimage[i][j];
     }
}

for (int i=0 ; i<SIZE ; i++){
   for (int j = 0; j< SIZE; j++) 
        { //// to make temp image all white
              tempimage[i][j]=255;
        }
}

for (int i=0 ; i<SIZE ; i++){
   for (int j = move; j< SIZE; j++) 
        {
              tempimage[i][j]=image[i][j-int(move)];
        }
        move-=step;
}


for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
        image[i][j]=tempimage[i][j];
     }
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
   for (int j = 0; j< SIZE; j++) 
        {
              tempimage[i][j]=255;
        }
}

for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
        if(i*shrinkval<=255){
        tempimage[i][j]=image[int(i*shrinkval)][j];
        }
     }
    }
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
        image[i][j]=tempimage[i][j];
     }
}

for (int i=0 ; i<SIZE ; i++){
   for (int j = 0; j< SIZE; j++) 
        {
              tempimage[i][j]=255;
        }
}

for (int j=0 ; j<SIZE ; j++){
   for (int i = move; i< SIZE; i++) 
        {
              tempimage[i][j]=image[i-int(move)][j];
        }
        move-=step;
}


for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j< SIZE; j++) {
        image[i][j]=tempimage[i][j];
     }
}
  
}
//_________________________________________

