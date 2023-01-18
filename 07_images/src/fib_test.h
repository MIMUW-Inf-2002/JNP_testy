#ifndef FIB_TEST_H
#define FIB_TEST_H

#include "../images.h"
#include "../functional.h"
#include "bmp.h"
#include "color.h"
#include "coordinate.h"


namespace Fibonacci {
    Color simple_colors[16] = {
            {0,0,0},
            {0x80,0,0},
            {0,0x80,0},
            {0x80,0x80,0},
            {0,0,0x80},
            {0x80,0,0x80},
            {0,0x80,0x80},
            {0xc0,0xc0,0xc0},
            {0x80,0x80,0x80},
            {0xff,0,0},
            {0,0xff,0},
            {0xff,0xff,0},
            {0,0,0xff},
            {0xff,0,0xff},
            {0,0xff,0xff},
            {0xff,0xff,0xff}
    };

    Image gradient = [](auto q){
        const Point p = q.is_polar ? from_polar(q) : q;
        const double v = exp(-0.01 * distance(p, {0,-100,false}));
        auto c = static_cast<unsigned char>(255.0 * v);
        return Color{c, c, 0};
    };

    double visor_dist(Point p) {
        double x = p.first - 30.7;
        double y = p.second - 50.2;
        return x*x*x*x + 8.0*y*y*y*y - 1000000.0;
    }

    double body_dist(Point p) {
        double x = p.first;
        double y = p.second;
        return 8.0*x*x*x*x + y*y*y*y - 50000000.0;
    }

    double legs(Point p) {
        double x = p.first;
        return -0.0001 * x * x * x * x -30 - p.second;
    }

    Image amongus(int i) {
        return [=](auto q) {
            const Point p = q.is_polar ? from_polar(q) : q;
            const double epsilon = 4500.0;
            const double epsilon2 = 2;
            const Color border{10,10,10};
            const Color visor{0xe0, 0xd0, 0x90};
            const double vd = visor_dist(p);
            const double bd = body_dist(p);
            const double l = legs(p);
            return vd < -1.0 * epsilon ? visor : (
                    vd < epsilon ? border : (
                            bd > epsilon ? gradient(p) : (
                                    l > epsilon2 ? gradient(p) : (
                                            l > -1*epsilon2 ? border : (
                                                    bd > -1*epsilon ? border : simple_colors[i]
                                            )
                                    )
                            )
                    )
            );
        };
    }

    Region amongus_sil = [](auto q) {
        const Point p = q.is_polar ? from_polar(q) : q;
        const double epsilon = 4500.0;
        const double epsilon2 = 2;
        const double vd = visor_dist(p);
        const double bd = body_dist(p);
        const double l = legs(p);
        return vd < -1.0 * epsilon || vd < epsilon || (bd <= epsilon && l <= epsilon2);
    };

    Vector shift(int i) {
        return {-175 + 50 * ((i-1) % 8), i <= 8 ? 50 : -50};
    }

    Image amongi(int n) {
        Region scaled_sil = scale(amongus_sil, 0.39);
        return [=](auto p) {
            const Vector s = shift(n);
            const Image scaled_amongus = scale(amongus(n-1), 0.39);
            return n==0 ? gradient(p) : (cond(translate(scaled_sil, s), translate(scaled_amongus, s), amongi(n-1)))(p);
        };
    }

    void test() {
        const uint32_t width = 400;
        const uint32_t height = 300;
        create_BMP("fib_hex_polar_checker.bmp",
                   width,
                   height,
                   polar_checker(10, 6, simple_colors[15], simple_colors[10]));
        create_BMP("fib_correct_polar_coordinates.bmp",
                   width,
                   height,
                   [](auto p){
                       Point const q = p.is_polar ? p : to_polar(p);
                       return rotate(vertical_stripe(10, simple_colors[1], simple_colors[2]), 0.7)(q);
                   });
        create_BMP("fib_darken_lighten.bmp",
                   width,
                   height,
                   [](auto p){
                       return darken(lighten(vertical_stripe(21.37, simple_colors[3], simple_colors[6]), checker(17, 0.3, 0.9)),
                                     checker(27, 0.1, 0.8))(p);
                   });
        create_BMP("fib_translate_and_rotate.bmp",
                   width,
                   height,
                   rotate(translate(amongus(4), {-20,40}), 0.2 * M_PI));
        create_BMP("fib_many_region_translate_and_scale.bmp",
                   width,
                   225,
                   amongi(16));
        create_BMP("fib_all_at_once.bmp",
                   width,
                   height,
                   cond(amongus_sil, polar_checker(10, 12, simple_colors[11], simple_colors[0]),
                        lighten(darken(
                                lerp(checker(7.3, 0.2, 0.8),
                                     scale(rotate(translate(amongus(12), {10, 10}), 7.0), 3)
                                        , rings({40, 1.73, true}, 22.222, simple_colors[1], simple_colors[14])),
                                vertical_stripe(30, 0.4, 0.1)), circle({70, 5.0, true}, 40, 0.7, 0.1))));
    }
}

#endif // FIB_TEST_H