kernel CustomRelight : ImageComputationKernel<ePixelWise>
{
  Image<eRead, eAccessPoint, eEdgeNone> pos;
  Image<eRead, eAccessPoint, eEdgeNone> normal;
  Image<eWrite> dst;

  param:
    bool spotlight;   // Enables spotlight mode
    bool swizzle;     // Flips axis by 90 degrees so Y-axis is up
    bool spec;        // Turns on specular highlights
    float3 cam_pos;   // Position of camera
    float3 light_pos; // Position of light
    float3 light_rot; // Rotation of spotlight
    float range;      // Range of light
    float intensity;  // Strength of light
    float specFall;   // Falloff of the specular
    float specInt;    // Intensity of the specular
    float cone_angle; // Angle of spotlight
    float penumbra;   // Penumbra of spotlight


  local:
    float3 light_dir; // Normalised vector of light direction (Spotlight only)
    float cone_limit; // Cone angle in radians
    float pen_limit;  // Penumbra in radians


  void define() {
     defineParam( spotlight, "Spotlight", false);
     defineParam( swizzle, "Y-axis Up", true );
     defineParam( spec, "Specular", false );
     defineParam( cam_pos, "Camera Position", float3( 0.0f, 100.0f, 0.0f ) );
     defineParam( light_pos, "Light Position", float3( 0.0f, 0.0f, 0.0f ) );
     defineParam( light_rot, "Light Rotation", float3( 0.0f, 0.0f, 0.0f ) );
     defineParam( range, "Range", 500.0f );
     defineParam( intensity, "Intensity", 1.0f );
     defineParam( specFall, "Specular Falloff", 3.0f );
     defineParam( specInt, "Specular Intensity", 1.0f );
     defineParam( cone_angle, "Cone Angle", 45.0f );
     defineParam( penumbra, "Penumbra", 10.0f );
  }


  void init() {
    if (spotlight) {
      // Degrees to Radians converter
      float degToRad = atan2( 0, -1 ) / 180;

      // Convert to Radians (atan2(0, -1) is equal to pi)
      float3 light_rad;
      for ( int i = 0; i < 3; i++ )
        light_rad[ i ] = light_rot[ i ] * degToRad;

      light_dir = float3(
        sin(light_rad.y) * cos(light_rad.x),
        sin(light_rad.x),
        cos(light_rad.x) * cos(light_rad.y)
      );

      cone_limit = cos( cone_angle * degToRad );
      pen_limit = cos( ( cone_angle + penumbra ) * degToRad );
    }
  }


  float3 flip(float3 f) {
    return float3( f.x, f.z, -f.y );
  }
  

  void process() {

    // Set position
    float3 position = float3( pos(0), pos(1), pos(2) );
    if ( swizzle ) { position = flip( position ); }

    // Get the spread of light from range/intensity settings
    float3 vecToLight = light_pos - position;
    float distance = length( vecToLight );
    float spread = ( ( range - distance ) / range ) * intensity;

    if ( spread <= 0.0f ) {
      for ( int component = 0; component < 3; component++ )
          dst( component ) = 0.0f;
      return;
    }

    // Calculate area to light based on light type
    float target_area = 1.0f;

    if ( spotlight ) {
      float3 vecFromLight = normalize( position - light_pos );
      target_area = dot( vecFromLight, light_dir );
      target_area = ( target_area - pen_limit ) / ( cone_limit - pen_limit );
      target_area = clamp( target_area, 0.0f, 1.0f );

      if ( target_area == 0.0f ) {
        for ( int component = 0; component < 3; component++ )
          dst( component ) = 0.0f;
        return;
      }
    }

    // Normalise and clamp the vector to the light
    vecToLight = vecToLight / distance;

    // Get Normals
    float3 normals = float3( normal(0), normal(1), normal(2) );
    if ( swizzle ) { normals = flip( normals ); }


    // Specular highlights
    float specLight = 0.0f;
    if ( spec ) {
      float3 vecToCam = normalize(cam_pos - position);

      // Get the result of the light bouncing off the normal (angle of incidence)
      float3 bounce = 2.0f * dot( vecToLight, normals ) * normals - vecToLight;
      specLight = pow( max( dot( vecToCam, bounce ), 0.0f ), specFall ) * specInt;
    }

    // Resulting light value
    float light = dot( vecToLight, normals );
    light += max( specLight, 0.0f ) * light;

    // Set Values
    for ( int component = 0; component < 3; component++ )
      dst( component ) = light * spread * target_area; // * pos(3);
  }

};
