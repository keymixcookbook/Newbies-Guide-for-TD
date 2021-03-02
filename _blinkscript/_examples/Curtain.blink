kernel CurtainKernel : ImageComputationKernel<eComponentWise>
{
  Image<eRead, eAccessRanged1D, eEdgeConstant> src;
  Image<eWrite, eAccessPoint> dst;

param:
  float amplitudePixels;
  float phaseRadians;
  float periodPixels;

local:
  float angularFrequency;

  void define() {
    defineParam(amplitudePixels, "amplitude", 100.0f);
    defineParam(phaseRadians, "phase", PI);
    defineParam(periodPixels, "period", 500.0f);
  }

  void init() {
     src.setRange(-amplitudePixels, amplitudePixels);
     src.setAxis(eX);
     angularFrequency = 2.0f*PI/periodPixels;
  }

  void process(int3 pos) {
    int offset = amplitudePixels * sin( pos.y * angularFrequency + phaseRadians );
    dst() = src(offset);
  }
};
