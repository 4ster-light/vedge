#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "filters.h"

// === PHASE 1: Edge Detection ===

Image sobel_edge_detection(Image img, float threshold, float sensitivity)
{
	printf("Using Sobel edge detection.\n");

	Image result = {img.width, img.height, malloc(img.width * img.height)};
	if (!result.data)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	// Sobel kernels
	int Gx[3][3] = {{-1,  0,  1},
					{-2,  0,  2},
					{-1,  0,  1}};
	int Gy[3][3] = {{-1, -2, -1},
					{0,   0,  0},
					{1,   2,  1}};

	// Process each pixel (excluding borders)
	for (int y = 1; y < img.height - 1; y++)
	{
		for (int x = 1; x < img.width - 1; x++)
		{
			int sumX = 0;
			int sumY = 0;

			// Apply kernels
			for (int ky = -1; ky <= 1; ky++)
			{
				for (int kx = -1; kx <= 1; kx++)
				{
					int pixel = img.data[(y + ky) * img.width + (x + kx)];
					sumX += pixel * Gx[ky + 1][kx + 1];
					sumY += pixel * Gy[ky + 1][kx + 1];
				}
			}

			// Compute gradient magnitude with sensitivity
			float magnitude = sqrtf((float)(sumX * sumX + sumY * sumY)) * sensitivity;

			// Apply threshold, if it's below threshold set to 0
			result.data[y * img.width + x] =
				(magnitude < threshold)
					? 0										   // Below threshold
					: (unsigned char)fminf(magnitude, 255.0f); // Above threshold (clamp to 255)
		}
	}

	// Set border pixels to 0
	for (int i = 0; i < img.width; i++)
	{
		result.data[i] = 0;								   // Top row
		result.data[(img.height - 1) * img.width + i] = 0; // Bottom row
	}
	for (int i = 0; i < img.height; i++)
	{
		result.data[i * img.width] = 0;					  // Left column
		result.data[i * img.width + (img.width - 1)] = 0; // Right column
	}

	return result;
}

Image canny_edge_detection(Image img, float threshold, float sensitivity)
{
	printf("Using Canny edge detection.\n");

	Image result = {img.width, img.height, malloc(img.width * img.height)};
	if (!result.data)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	// TODO: Implementation here
	// Placeholder: copy input
	memcpy(result.data, img.data, img.width * img.height);

	return result;
}

Image laplacian_edge_detection(Image img, float threshold, float sensitivity)
{
	printf("Using Laplacian edge detection.\n");

	Image result = {img.width, img.height, malloc(img.width * img.height)};
	if (!result.data)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	// TODO: Implementation here
	// Placeholder: copy input
	memcpy(result.data, img.data, img.width * img.height);

	return result;
}

// === PHASE 2: Shape Detection ===
// TODO: Add shape detection implementations

// === PHASE 3: Video Processing ===
// TODO: Add video frame processing

// === PHASE 4: Object Tracking ===
// TODO: Add object tracking implementations
