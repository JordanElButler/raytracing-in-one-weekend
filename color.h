#ifndef COLOR_H
#define COLOR_H

#include "rtweekend.h"

#include <iostream>

void write_color(int* buffer, int i, int j, int image_width, int image_height, color pixel_color, int samples_per_pixel) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    auto scale = 1.0 / samples_per_pixel;
    r = sqrt(scale * r);
    g = sqrt(scale * g);
    b = sqrt(scale * b);
    
    buffer[3 * (i + image_width * j)    ] = static_cast<int>(256 * clamp(r, 0.0, 0.999));
    buffer[3 * (i + image_width * j) + 1] = static_cast<int>(256 * clamp(g, 0.0, 0.999));
    buffer[3 * (i + image_width * j) + 2] = static_cast<int>(256 * clamp(b, 0.0, 0.999));
}

void output_ppm(int *buffer, int image_width, int image_height) {
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            std::cout << buffer[3 * (i + image_width * j)    ] << ' '
                      << buffer[3 * (i + image_width * j) + 1] << ' '
                      << buffer[3 * (i + image_width * j) + 2] << '\n';

        }
    }
}
#endif