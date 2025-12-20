#ifndef FILTERS_H
#define FILTERS_H

#include "image.h"

typedef enum {
    FILTER_SOBEL,
    FILTER_CANNY,
    FILTER_LAPLACIAN
} FilterType;

// === PHASE 1: Edge Detection ===

Image sobel_edge_detection(Image img, float threshold, float sensitivity);

Image canny_edge_detection(Image img, float threshold, float sensitivity);

Image laplacian_edge_detection(Image img, float threshold, float sensitivity);

/* === PHASE 2: Shape Detection ===
 * TODO: Implement shape detection algorithms with parameters
 */
// Image detect_shapes(Image edges, float threshold);
// Image detect_circles(Image edges, float min_radius, float max_radius);

/* === PHASE 3: Video Processing ===
 * TODO: Implement video frame processing with parameters
 */
// void process_video_frame(Image frame, FilterType filter, float sensitivity);

/* === PHASE 4: Object Tracking ===
 * TODO: Implement object tracking with parameters
 */
// void track_objects(Image frame, Image previous_frame);

#endif
