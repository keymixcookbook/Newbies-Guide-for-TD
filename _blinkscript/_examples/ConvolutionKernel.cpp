kernel ConvolutionKernel : public ImageComputationKernel<ePixelWise>
{
  Image<eRead, eAccessRanged2D, eEdgeClamped> src;
  Image<eRead, eAccessRandom,eEdgeConstant> filter;
  Image<eWrite> dst;


  param:
	float2 Resolution;
	float Scale;
	float HoldoutOffset;

local:
  int2 _filterOffset;


  void define() {
	defineParam(HoldoutOffset, "Holdout Offset", float(1));
	defineParam(Scale, "Scale", float(1));
	defineParam(Resolution, "Resolution", float2(1920,1080));
  }


  void init()
  {
	int2 filterRadius(filter.bounds.width()/2, filter.bounds.height()/2);
	_filterOffset[0] = (filter.bounds.x1 - filterRadius[0])*Scale;
	_filterOffset[1] = (filter.bounds.y1 - filterRadius[1])*Scale;
	src.setRange(-filterRadius[0]*Scale, -filterRadius[1]*Scale, filterRadius[0]*Scale, filterRadius[1]*Scale);
  }

  void process(int2 pos) {
	//Definitions
	SampleType(src) valueSum(0);
	ValueType(filter) filterSum(0);
	ValueType(filter) filterVal;
	float2 Offset;
	Offset.x =  filter.bounds.x2*(((pos.x-(Resolution.x/2))/Resolution.x)*HoldoutOffset);
	Offset.y =  filter.bounds.y2*(((pos.y-(Resolution.y/2))/Resolution.x)*HoldoutOffset);
	for(int j = filter.bounds.y1; j < filter.bounds.y2*Scale; j++) {
	  for(int i = filter.bounds.x1; i < filter.bounds.x2*Scale; i++) {
		float4 SourceVal = src(i + _filterOffset[0], j + _filterOffset[1]);
		if (SourceVal.x > 0) {
		  filterVal = filter((i/Scale),(j/Scale), 0);
		  valueSum += (filterVal * bilinear(filter,(i/Scale)+(Offset.x),(j/Scale)+(Offset.y),3) )*SourceVal;
		  filterSum += filterVal;
		}
		else {
		  filterSum += 0.3333333; //1 divided by 3
		}

	  }
	}
	if (filterSum != 0)
	  valueSum /= filterSum;
	dst() = valueSum;
  }
};
