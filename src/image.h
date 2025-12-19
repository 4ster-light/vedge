#ifndef IMAGE_H
#define IMAGE_H

typedef struct {
    int width, height;
    unsigned char *data;
} Image;

Image load_ppm(const char *filename);
void save_ppm(const char *filename, Image img);
void free_image(Image img);

#endif
