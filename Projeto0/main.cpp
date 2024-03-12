#include <iostream>
#include <vector>
#include "lodepng.h"
#include "rgb.h"
#include "background.h"
using byte = unsigned char;

float lerp(float a, float b, float t){return ((1-t)*a + t*b);}

void encodeOneStep(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height) {
  //Encode the image
  unsigned error = lodepng::encode(filename, image, width, height);

  //if there's an error, display it
  if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}

int w = 400;
int h = 200;

std::vector<byte> bytes;
int main(){
    std::cout << "P3" << std::endl;
    std::cout << w << " " << h << std::endl;
    std::cout << "255" << std::endl;
    RGB pixel;
    pixel.r = 0;
    pixel.g = 255;
    pixel.b = 51;

    std::vector<RGB> corners{{0,0,51},{0,255,51},{255,255,51},{255,0,51}};

    BackgroundColor bkg = BackgroundColor(corners);

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            //pixel.g = (int)lerp(255,0, float(i)/float(h));
            //pixel.r = (int)lerp(0,255,float(j)/float(w));
            //bytes.push_back(pixel.r);
            //bytes.push_back(pixel.g);
            //bytes.push_back(pixel.b);
            //bytes.push_back(255);
            //std::cout << (int)pixel.r << " " << (int)pixel.g << " " << (int)pixel.b << std::endl;                        
            RGB vez = bkg.sampleUV(float(j)/float(w),float(i)/float(h));
            std::cout << (int)vez.r << " " << (int)vez.g << " " << (int)vez.b << std::endl;            
        }
    }
    //encodeOneStep("image.png", bytes, w, h);
}
