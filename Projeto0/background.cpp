#include "background.h"

RGB BackgroundColor::lerp( const RGB &A, const RGB &B, float t ) const{
  float ar = (float)A.r;
  float ag = (float)A.g;
  float ab = (float)A.b;

  float br = (float)B.r;
  float bg = (float)B.g;
  float bb = (float)B.b;

  RGB retorno = {(int)(((1-t)*ar + t*br)),(int)((1-t)*ag + t*bg),(int)((1-t)*ab + t*bb)};
  return retorno;
}
RGB BackgroundColor::sampleUV( real_type u, real_type v ) const{
  return lerp(lerp(corners[tl],corners[tr],u),lerp(corners[bl],corners[br],u),v);
}

