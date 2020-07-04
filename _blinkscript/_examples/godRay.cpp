kernel My_First_GodRay : ImageComputationKernel <eComponentWise>
{
  Image<eRead, eAccessRandom, eEdgeClamped> src;
  Image<eWrite> dst;

  param:
    float size;
    float2 center;
    int iterations;

  void process(int2 pos) {
    float2 raypos;
    float raysize;
    float total = 0.0;

    for (int i = 0; i < iterations; i++) {
      raysize = 1+size*i/iterations;
      raypos = (float2(pos.x,pos.y)-center)/raysize+center;
      total += src(raypos.x,raypos.y);
    }

    dst() = total/iterations;
  }
};
