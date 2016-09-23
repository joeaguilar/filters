
void twistocity (uint_fast32_t *pixels, uint_fast32_t *clone, Options *opts)
{
  const size_t length = opts->length, h = opts->height, w = opts->width;
  const size_t h2 = h/2, w2 = w/2;  
  const size_t qHeight = h / 4;
  const size_t qWidth = w / 4;
  const size_t xCenter = std::floor(h * (opts->xspace * .04)); // x pixel position of center
  const size_t yCenter = std::floor(w * (opts->yspace * .04)); // y pixel position of center
  const size_t radius = opts->threshold;  // approximate radius of circular wave train, in pixels
  const size_t wavelength = opts->weight; // wavelength of ripples, in pixels
  const double trainWidth = opts->depth;  // approximate width of wave train, in wavelengths

  for (size_t x = 0; x < h; ++x) {
    for (size_t y = 0; y < w; ++y) {
      int dx = x - xCenter;
      int dy = y - yCenter;
      double r = (sqrt((double)dx*dx + dy*dy)-radius)/wavelength;
      double k = r - (1-1.5)*r/wavelength ;
      double a = 1 / (1.0+(r/trainWidth)*(r/trainWidth));      double factor = a*sin(k*2*3.14);
      size_t tIndex = x*w+y;
      size_t dIndex = tIndex + (tIndex * factor);

      if (dIndex > length || dIndex < 0) continue;

      clone[x*w+y] = pixels[dIndex];

    }
  }

}

