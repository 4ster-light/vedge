#include "image.h"
#include <stdio.h>
#include <stdlib.h>

Image load_ppm(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char magic[3];
    int width, height, maxval;
    fscanf(fp, "%s %d %d %d", magic, &width, &height, &maxval);
    if (magic[1] != '6') {
        fprintf(stderr, "Only P6 PPM format supported.\n");
        exit(EXIT_FAILURE);
    }

    Image img = {width, height, malloc(width * height * sizeof(unsigned char))};
    if (!img.data) {
        perror("Image allocation failed");
        exit(EXIT_FAILURE);
    }

    fgetc(fp); // Skip newline
    fread(img.data, sizeof(unsigned char), width * height, fp);
    fclose(fp);
    return img;
}

void save_ppm(const char *filename, Image img) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "P6\n%d %d\n255\n", img.width, img.height);
    fwrite(img.data, sizeof(unsigned char), img.width * img.height, fp);
    fclose(fp);
}

void free_image(Image img) {
    free(img.data);
}
