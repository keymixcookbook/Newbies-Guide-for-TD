// Making a grid based on user input

// Declar other functions here

// What happens in the node
kernel GridGenerator : ImageComputationKernel<ePixelWise>
{
    Image<eRead, eAccessPoint, eEdgeClamped> src; // the input image
    Image<eWrite, eAccessRandom> dst; // the output image

    // Initializing variables
    param:
    int2 resolution;
    int1 spacing;
    int2 offset;



  // In define(), parameters can be given labels and default values.
  void define() {
    // Adding parameters to the node
    defineParam(resolution, "Resolution", int2(1920,1080));
    defineParam(spacing, "Spacing", int1(20));
    defineParam(offset, "Offset", int2(0,0));
  }

  // The init() function is run before any calls to process().
  // Local variables can be initialized here.
  void init() {

  }

  void process(int2 pos) {
    // init of the pos variable, begins on the first pixel of the image
    // Offsetting the image based on the offset slider
    pos = (1 + offset.x, 1 + offset.y);

    // while pos.x/y is not over the resolution.x/y
    //  Draw a white px on the position of the pos x & y
    // Then add spacing to x and y and start again
    while (pos.x < resolution.x)
    {
      //pos.y = (1 + offset.x + (rand() % randomness));
      pos.y = (1 + offset.x);
      while (pos.y < resolution.y)
      {

          dst(pos.x, pos.y) = float4(1.0f, 1.0f, 1.0f, 1.0f);


        pos.y = (pos.y + spacing);
      }
      pos.x = (pos.x + spacing);
    }


  }
};
