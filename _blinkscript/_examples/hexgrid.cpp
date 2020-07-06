# This Blink script will produce a hex grid. Hack at your pleasure.

kernel HexKernel : ImageComputationKernel<ePixelWise>
{
  Image<eWrite> dst;

  param:
    float size;
    float smoothness;
    float thickness;

  void define() {
    defineParam(size, "size", 10.0f);
    defineParam(smoothness, "smoothness", 1.0f);
    defineParam(thickness, "thickness", 0.01f);
  }

  float2 mod(float2 v, float m) {
    return float2( fmod(v.x, m), fmod(v.y, m) );
  }

  float hexGrid(float2 p) {
    p.x *= 2.0f*0.57735f;
    p.y += fmod(floor(p.x), 2.0f)*0.5f;
    p = fabs(mod(p, 1.0f) - 0.5f);
    return fabs(max(p.x*1.5f+p.y, p.y*2.0f)-1.0f);
  }

  float smoothstep(float a, float b, float x) {
    if (x < a)
      return 0.0f;
    if (x >= b)
      return 1.0f;
    x = (x - a) / (b - a);
    return x*x * (3.0f - 2.0f*x);
  }

  void process(int2 xy) {
    float2 pos = float2(float(xy.x)/size, float(xy.y)/size);
    float v = hexGrid(pos);
    v = smoothstep(thickness, thickness+smoothness, v);
    dst() = float4(v, v, v, 1.0f);
  }
};
