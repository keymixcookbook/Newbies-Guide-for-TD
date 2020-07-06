// Copyright (c) 2012 The Foundry Visionmongers Ltd.  All Rights Reserved.
// Example RIP Kernel

#define kRandMax 32767

/// Platform-consistent PRNG based on SGI rand().
inline int RandI(unsigned int seed) {
  unsigned int next = seed;
  int result;

  next *= 1103515245;
  next += 12345;
  result = (unsigned int) (next / 65536) % 256;

  next *= 1103515245;
  next += 12345;
  result <<= 7;
  result ^= (unsigned int) (next / 65536) % 256;
  return result;
}

inline float RandF(unsigned int seed)
{
  return float(RandI(seed))/float(kRandMax);
}

/// LensFlareKernel: Generates a lens flare on top of the input image.
/// NOTE that this process does not currently vectorize.
kernel LensFlareKernel : ImageComputationKernel<ePixelWise>
{
  Image<eWrite, eAccessPoint> dst;

param:
  float2 flareHandle;
  float2 centre;
  float  size;
  float  spread;
  float  brightness;
  int    nDots;
  int    seed;

local:
  static const int kMaxDots = 10;
  float4 colours[kMaxDots];
  float2 dotCentres[kMaxDots];
  float  invSizeSqr[kMaxDots];
  int actualDots;

  void define() {
    defineParam(centre,      "Centre", float2(400.0f, 400.0f));
    defineParam(flareHandle, "FlareHandle",  float2(800.0f, 800.0f));
    defineParam(size,        "Size",         150.0f);
    defineParam(brightness,  "Brightness",   1.0f);
    defineParam(spread,      "Spread",   0.3f);
    defineParam(nDots,       "NDots",   5);
    defineParam(seed,        "Seed",   0);
  }

  void init() {
    actualDots = nDots > kMaxDots ? kMaxDots : nDots;
    actualDots = actualDots < 0 ? 0 : actualDots;
    float2 dist = centre - flareHandle;
    for(int i = 0; i < actualDots; ++i) {
      float t = float(i) / float(kMaxDots-1);
      dotCentres[i] = flareHandle + dist * spread * RandF(seed + i);
      float thisSize =  RandF(seed + i + 1000) * size;
      invSizeSqr[i] = 1.0f/(thisSize * thisSize);
      colours[i] = float4(RandF(seed + i + 2000),
                          RandF(seed + i + 3000),
                          RandF(seed + i + 4000),
                          RandF(seed + i + 5000));
    }
  }

  float4 flareValue(float2 posf,
                   int index)
  {
    float2 delta = posf - dotCentres[index];
    float dotDelta = dot(delta, delta) * invSizeSqr[index];
    float value = clamp(1.0f - dotDelta, 0.0f, 1.0f);
    value *= value;
    return colours[index] * value;
  }

  void process(int2 pos) {
    float2 posf(pos.x, pos.y);

    SampleType(dst) sample(0.0f);

    float4 value = 0;
    for(int i = 0; i < actualDots; ++i) {
      value += flareValue(posf, i);
    }

    sample.x += value.x * brightness;
    sample.y += value.y * brightness;
    sample.z += value.z * brightness;

    dst() = sample;
  }

};
