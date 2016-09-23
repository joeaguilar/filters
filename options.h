#ifndef IMAGEFILTER_OPTIONS_H
#define IMAGEFILTER_OPTIONS_H

typedef struct Options {
    uint_fast32_t effect;
    uint_fast32_t blend;
    size_t order;
    size_t height;
    size_t width;
    size_t length;
    uint_least8_t channel;
    uint_least8_t threshold;
    double depth;
    uint_least8_t xspace;
    uint_least8_t yspace;
    uint_least8_t stroke;
    uint_least8_t weight;
    uint_least32_t color;
    uint_least8_t r;
    uint_least8_t g;
    uint_least8_t b;
    uint_least8_t light;
    uint_least8_t dark;
};


#endif IMAGEFILTER_OPTIONS_H

