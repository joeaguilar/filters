

void spirility (uint_fast32_t *pixels, uint_fast32_t *clone, Options *opts)
{
  const size_t length = opts->length, h = opts->height, w = opts->width;
  // size_t t = std::max(w, h);
  size_t t = (w > h) ? w : h;
  size_t maxI = t*t;
  // size_t maxDistance = h*w;

  int_fast32_t x = 0, y = 0, dx = 0, dy = -1;
  int_fast32_t a = -(h/2), 
               b = h/2, 
               c = -(w/2), 
               d = w/2;

  size_t cx = b, cy = d;


  for (size_t i = 0, pos = 0; i < maxI; ++i) {

    if ( (a <= x ) && (x <= b) && ( c <= y ) && (y <= d)) {
              
      size_t index = (cx + x) * w + (cy + y);
      
      if (index < 0 || index > length) {
      
        --i;
      
      } else {
      
        if (pos > length) break;
      
        // return pos, then advance
      
        clone[index] = pixels[pos++]; 
      
        // clone[index] = *pixels++;     
      }

    }

    if ((x == y) || ((x < 0) && (x == -y)) || ((x > 0) && (x == 1-y))) {
      
      t=dx; dx=-dy; dy=t;

    }

    x+=dx; y+=dy;

  }


}
