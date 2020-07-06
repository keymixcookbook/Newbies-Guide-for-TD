//Warning: connecting a large image to the filter input will cause the kernel to run very slowly!
//If running on a GPU connected to a display, this will cause problems if the time taken to
//execute the kernel is longer than your operating system allows. Use with caution!
kernel ConvolutionKernel : public ImageComputationKernel<ePixelWise>
{
  Image<eRead, eAccessRanged2D, eEdgeClamped> src;
  Image<eRead, eAccessRandom> filter;
  Image<eWrite> dst;

local:
  int2 _filterOffset;

  void init()
  {
    //Get the size of the filter input and store the radius.
    int2 filterRadius(filter.bounds.width()/2, filter.bounds.height()/2);

    //Store the offset of the bottom-left corner of the filter image
    //from the current pixel:
    _filterOffset.x = filter.bounds.x1 - filterRadius.x;
    _filterOffset.y = filter.bounds.y1 - filterRadius.y;

    //Set up the access for the src image
    src.setRange(-filterRadius.x, -filterRadius.y, filterRadius.x, filterRadius.y);
  }

  void process() {

    SampleType(src) valueSum(0);
    ValueType(filter) filterSum(0);

    //Iterate over the filter image
    for(int j = filter.bounds.y1; j < filter.bounds.y2; j++) {
      for(int i = filter.bounds.x1; i < filter.bounds.x2; i++) {
        //Get the filter value / weight
        ValueType(filter) filterVal = filter(i, j, 0);

        //Multiply the src value by the corresponding filter weight and accumulate
        valueSum += filterVal * src(i + _filterOffset.x, j + _filterOffset.y);

        //Update the filter sum with the current filter value
        filterSum += filterVal;
      }
    }

    //Normalise the value sum, avoiding division by zero
    if (filterSum != 0)
      valueSum /= filterSum;

    dst() = valueSum;
  }
};
