#ifndef FILTERS_H
#define FILTERS_H

#include "image.h"

/* ===== PHASE 1: Edge Detection =====
 * TODO: Implement Sobel operator
 * Hint: Use 3x3 kernels for Gx and Gy, compute gradient magnitude
 */
Image sobel_edge_detection(Image img);

/* TODO: Add more edge detection methods (Canny, Laplacian, etc.)
Image canny_edge_detection(Image img);
Image laplacian_edge_detection(Image img);
*/

/* ===== PHASE 2: Shape Detection =====
 * TODO: Implement shape detection algorithms
Image detect_shapes(Image edges);
Image detect_circles(Image edges);
*/

/* ===== PHASE 3: Video Processing =====
 * TODO: Implement video frame processing
void process_video_frame(Image frame);
*/

/* ===== PHASE 4: Object Tracking =====
 * TODO: Implement object tracking
void track_objects(Image frame);
*/

#endif
