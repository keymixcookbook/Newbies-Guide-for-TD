kernel Custom_Color : ImageComputationKernel<ePixelWise>
{

 	Image<eWrite> dst;
	Image<eRead, eAccessPoint, eEdgeClamped> src;

	param:
		bool Switch;
    	float4 color;

  	void define() {
    	defineParam(color, "Custom color", float4(0.0f,1.0f,0.0f,0.0f));      //defalut value
		defineParam(Switch, "Switch", true);
  	}

  	void process() {
    	dst() = Switch == true ? src() : src() * color;
  }
};
