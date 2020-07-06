// Copyright (c) 2012 The Foundry Visionmongers Ltd.  All Rights Reserved.
// Example RIP Kernel

/// SwirlomaticKernel: does a nice swirl. Amount is in degrees.
kernel Swirlomatic : ImageComputationKernel<ePixelWise> {
  Image<eRead, eAccessRandom, eEdgeClamped> src;
  Image<eWrite, eAccessPoint> dst;

param:
  float amount;
  int size;
  float2 centre;

local:
  float _sizeInv;
  float _cs, _sn;

  void define() {
     defineParam(amount, "Amount", 180.0f);
     defineParam(size, "Size", 640);
     defineParam(centre, "Centre", float2(640.0f, 360.0f));
  }

  void init() {
    _sizeInv = size <= 0 ? 0 : 1.0f/size;
    _sizeInv *= _sizeInv;
  }

  void process(int2 pos) {
    float dx = float(pos.x) - centre.x;
    float dy = float(pos.y) - centre.y;
    float delta = 1.0f - ((dx*dx + dy*dy) * _sizeInv);
    if (delta < 0) delta = 0;

    float cs = cos(delta * amount * 3.1415926535f/180.0f);
    float sn = sin(delta * amount * 3.1415926535f/180.0f);

    float x = centre.x + dx * cs + dy * sn;
    float y = centre.y - dx * sn + dy * cs;

    // dst(0) = bilinear(src, x, y, 0);
    // dst(1) = bilinear(src, x, y, 1);
    // dst(2) = bilinear(src, x, y, 2);
    // dst(3) = bilinear(src, x, y, 3);
	dst()=bilinear(src, x,y);
  }
};
