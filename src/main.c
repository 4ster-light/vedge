#include "image.h"
#include "filters.h"
#include <stdio.h>
#include <string.h>

// ===== CURRENT PHASE =====
// Phase 1: Edge Detection - Implement the Sobel operator in filters.c

int main(int argc, char *argv[]) {
    // Default test image
    const char *input_file = "data/boxes_1.ppm";
    const char *output_file = "dist/output.ppm";

    // TODO: Parse command line arguments for:
    //   - Input image path
    //   - Output file path
    //   - Algorithm selection (edge detection, shapes, etc.)
    //   - Algorithm parameters (threshold, sensitivity, etc.)

    printf("Loading image: %s\n", input_file);
    Image img = load_ppm(input_file);
    printf("Image dimensions: %dx%d\n", img.width, img.height);

    // PHASE 1: Edge Detection
    printf("Detecting edges (Sobel)...\n");
    Image edges = sobel_edge_detection(img);

    printf("Saving result: %s\n", output_file);
    save_ppm(output_file, edges);

    free_image(img);
    free_image(edges);

    printf("Done!\n");

    // TODO: Future phases

    // PHASE 2: Shape Detection

    // PHASE 3: Video Processing

    // PHASE 4: Object Tracking

    return 0;
}
