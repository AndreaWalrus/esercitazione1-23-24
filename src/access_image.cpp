#include "image.h"
#include <cstring>
#include <chrono>
#include <iostream>

// HW0 #1
// const Image& im: input image
// int x,y: pixel coordinates
// int ch: channel of interest
// returns the 0-based location of the pixel value in the data array
int pixel_address(const Image &im, int x, int y, int ch) {
    
    if(x<0){
        x=0;
    }else if(x>im.w-1){
        x=im.w-1;
    }
    if(y<0){
        y=0;
    }else if(y>im.h-1){
        y=im.h-1;
    }

    return x+(y*im.w)+(ch*im.w*im.h);
}

// HW0 #1
// const Image& im: input image
// int x,y,ch: pixel coordinates and channel of interest
// returns the value of the clamped pixel at channel ch
float get_clamped_pixel(const Image &im, int x, int y, int ch) {
    
    if(x<0){
        x=0;
    }else if(x>im.w-1){
        x=im.w-1;
    }
    if(y<0){
        y=0;
    }else if(y>im.h-1){
        y=im.h-1;
    }
    
    return im(x,y,ch);
}


// HW0 #1
// Image& im: input image
// int x,y,ch: pixel coordinates and channel of interest
void set_pixel(Image &im, int x, int y, int c, float value) {
    if(x<0 || x>im.w-1 || y<0 || y>im.h-1 || c<0 || c>im.c-1) return;
    im.data[pixel_address(im,x,y,c)]=value;
}


// HW0 #2
// Copies an image
// Image& to: destination image
// const Image& from: source image
void copy_image(Image &to, const Image &from) {
    // allocating data for the new image
    to.data = (float *) calloc(from.w * from.h * from.c, sizeof(float));
    to.c = from.c;
    to.w = from.w;
    to.h = from.h;
    memcpy(to.data,from.data,to.w*to.h*to.c*sizeof(float));
}
