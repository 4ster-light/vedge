# vedge - Vision & Edge Detection Learning Project

A hands-on C project for learning image processing fundamentals through
implementation. Start with edge detection, then progress to shape detection, and
eventually live video object tracking.

## Learning Path

1. **Phase 1**: Edge Detection (Sobel operator)
2. **Phase 2**: Shape Detection (contour analysis)
3. **Phase 3**: Video Processing (live camera feed)
4. **Phase 4**: Object Tracking (motion & classification)

## Project Structure

```txt
src/
├── main.c       - Entry point (TODO: add options for different algorithms)
├── image.c      - Image I/O (COMPLETE)
├── image.h      - Image structures (COMPLETE)
├── filters.c    - Algorithm implementations (TODO: Sobel, shapes, etc.)
├── filters.h    - Algorithm declarations (TODO: add new algorithms)
data/           - Test images for learning
```

## Building

```sh
make       # Build
make run   # Build and run
make help  # See all commands
```

Output goes to `dist/edge_detector`.

This will process the input image (`data/boxes_1.ppm` by default) and save the
edge detection result to `output.ppm`.

## Test Images

The `data/` directory contains sample image pairs for testing, obtained from a
public assignment of the university of Cornell:

- `boxes_1.ppm`, `boxes_2.ppm`
- `house_1.ppm`, `house_2.ppm`
- `moreboxes_1.ppm`, `moreboxes_2.ppm`
- `sign_1.ppm`, `sign_2.ppm`
- `stop_1.ppm`, `stop_2.ppm`
- `synth_1.ppm`, `synth_2.ppm`
- `tree_1.ppm`, `tree_2.ppm`
- `west_1.ppm`, `west_2.ppm`

You can modify `src/main.c` to test different images.

## Implementation Details

### Sobel Operator

The Sobel operator is a discrete differentiation operator that computes an
approximation of the gradient of the image intensity function. It uses two 3×3
kernels to detect edges in the horizontal and vertical directions.

### Image Format

- **Input**: PPM (Portable Pixmap) format, P6 (binary RGB)
- **Output**: PPM format with grayscale edge map

## Compilation Flags

- `-Wall -Wextra`: Enable all warnings
- `-std=c17`: Use C17 standard
- `-O2`: Optimization level 2 for better performance

## License

This is a computer vision project for educational purposes.
