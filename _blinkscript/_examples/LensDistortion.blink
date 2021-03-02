kernel LensDistortion : ImageComputationKernel<eComponentWise>
{
  Image<eRead, eAccessRandom, eEdgeClamped> src;  //the input image
  Image<eWrite> dst;  //the output image


  param:
    float lens;
    bool pincushion;


  local:
    float2 center;
    float max_dist;


  void define() {
    defineParam( lens, "Lens Distortion", 0.1f );
    defineParam( pincushion, "Barrel -> Pincushion", false );
  }


  void init() {
    center = float2( src.bounds.x2 / 2, src.bounds.y2 / 2 );
    max_dist = length( center );
  }


  void process( int2 pos ) {

    // d = u * ( 1 - k * pow( u, 2 ) );
    // u = d / ( 1 - k * pow( d, 2 ) );

    float2 pos_f = float2( pos.x, pos.y );
    float2 dir = center - pos_f;
    float dist = length( dir );
    float n_dist = dist / max_dist;

    float target_dist;

    if ( pincushion )
      target_dist = dist * ( 1 - lens * pow( n_dist, 2) );
    else
      target_dist = dist / ( 1 - lens * pow( n_dist, 2) );

    float2 undistort_pos = center - normalize( dir ) * target_dist;

    dst() = bilinear( src, undistort_pos.x, undistort_pos.y );
  }
};