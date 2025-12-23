#include <stdio.h>
#include <stdlib.h>

#include "image.h"

Image load_ppm(const char *filename)
{
	printf("Loading PPM image from %s\n", filename);

	FILE *fp = fopen(filename, "rb");
	if (!fp)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	char magic[3];
	int width, height, maxval;

	// Check header
	if (fscanf(fp, "%2s %d %d %d", magic, &width, &height, &maxval) != 4)
	{
		fprintf(stderr, "Invalid PPM header\n");
		exit(EXIT_FAILURE);
	}

	// Check PPM format P6
	if (magic[0] != 'P' || magic[1] != '6')
	{
		fprintf(stderr, "Only P6 PPM format supported.\n");
		exit(EXIT_FAILURE);
	}

	// Create grayscale Image
	Image grayscale = {width, height, malloc(width * height)};
	if (!grayscale.data)
	{
		perror("Image allocation failed");
		exit(EXIT_FAILURE);
	}
	fgetc(fp); // Skip exactly one whitespace character after maxval

	// Convert from RGB
	unsigned char rgb[3];
	for (int i = 0; i < width * height; i++)
	{
		fread(rgb, sizeof(unsigned char), 3, fp);
		grayscale.data[i] = (unsigned char)(0.299f * rgb[0] + 0.587f * rgb[1] + 0.114f * rgb[2]);
	}

	fclose(fp);
	return grayscale;
}

void save_ppm(const char *filename, Image img)
{
	FILE *fp = fopen(filename, "wb");
	if (!fp)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	// Write as P6 (color) so standard image viewers can read it
	// Write the grayscale value to RGB channels
	fprintf(fp, "P6\n%d %d\n255\n", img.width, img.height);
	for (int i = 0; i < img.width * img.height; i++)
	{
		unsigned char gray = img.data[i];
		fputc(gray, fp);
		fputc(gray, fp);
		fputc(gray, fp);
	}
	fclose(fp);
}

void free_image(Image img)
{
	free(img.data);
}
