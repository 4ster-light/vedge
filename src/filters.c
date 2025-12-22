#include <string.h>
#include <stdio.h>
#include <math.h>

#include "filters.h"

// === PHASE 1: Edge Detection ===

/* TODO: Implement Sobel edge detection
 * Steps:
 * 1. Create output image buffer
 * 2. For each pixel (avoiding borders):
 *    - Apply Sobel Gx kernel (vertical edges)
 *    - Apply Sobel Gy kernel (horizontal edges)
 *    - Compute magnitude: sqrt(Gx^2 + Gy^2)
 *    - Apply threshold and sensitivity
 *    - Clamp to 0-255 range
 * 3. Return edge-detected image
 *
 * Sobel kernels:
 * Gx = [-1 0 +1]   Gy = [-1 -2 -1]
 *      [-2 0 +2]        [ 0  0  0]
 *      [-1 0 +1]        [+1 +2 +1]
 *
 * Parameters:
 *   threshold:  Minimum gradient magnitude to consider as edge
 *   sensitivity: How much to amplify edge magnitudes (0.0-1.0)
 */
Image sobel_edge_detection(Image img, float threshold, float sensitivity)
{
	Image result = {img.width, img.height, malloc(img.width * img.height)};
	if (!result.data)
	{
		perror("Memory allocation failed");
		exit(1);
	}

	// TODO: Implementation here
	// Placeholder: copy input
	memcpy(result.data, img.data, img.width * img.height);

	return result;
}

Image canny_edge_detection(Image img, float threshold, float sensitivity)
{
	Image result = {img.width, img.height, malloc(img.width * img.height)};
	if (!result.data)
	{
		perror("Memory allocation failed");
		exit(1);
	}

	// TODO: Implementation here
	// Placeholder: copy input
	memcpy(result.data, img.data, img.width * img.height);

	return result;
}

Image laplacian_edge_detection(Image img, float threshold, float sensitivity)
{
	Image result = {img.width, img.height, malloc(img.width * img.height)};
	if (!result.data)
	{
		perror("Memory allocation failed");
		exit(1);
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
