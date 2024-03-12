#ifndef BACKGROUND_COLOR_H
#define BACKGROUND_COLOR_H

#include "rgb.h"
#include <vector>

using real_type = float;

class BackgroundColor {
  private:
    /// Each corner has a color associated with.
    RGB corners[4]={{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
    /// Corner indices.
    enum Corners_e {
      bl=0, //!< Bottom left corner.
      tl,   //!< Top left corner.
      tr,   //!< Top right corner.
      br    //!< Bottom right corner.
    };

    /// Return the linearly interpolated color in [A;B], based on the parameter \f$0\leq t \leq 1.\f$
    RGB lerp( const RGB &A, const RGB &B, float t ) const;

  public:
    /// Ctro receives a list of four colors, for each corner.
    BackgroundColor( const std::vector< RGB >& colors ){for(int i = 0; i < 4; i++)corners[i] = colors[i];};
    /// Dtro
    ~BackgroundColor() { };
    /// Sample and returns a color, based on the raster coordinate.
    RGB sampleUV( real_type u, real_type v ) const;
};

#endif // BACKGROUND_COLOR_H
