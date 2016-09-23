
void pixelsort_lr (uint_fast32_t *pixels, uint_fast32_t *clone, Options *opts)
{

    // type: pixelsort

    size_t h = opts->height, w = opts->width, index, x, y;

    std::vector<uint_fast32_t> unsorted(w);
    for (x = 0; x < h; ++x ) {
        for (y = 0; y < w; ++y ) {
            index = x * w + y;
            unsorted[y] = pixels[index];
        }
        // stable sort uses merge sort
        std::stable_sort( unsorted.begin(), unsorted.end());

        for(y = 0; y < w; ++y) {
            index = x * w + y;
            clone[index] = unsorted[y];
        }

    }

}
