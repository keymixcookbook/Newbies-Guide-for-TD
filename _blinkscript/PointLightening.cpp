inline float3 mix(float3 A, float3 B, float amount){
  return A*(1.0f-amount) + B*amount;
}

kernel PointLighning : ImageComputationKernel<ePixelWise>
{
 	Image<eRead, eAccessRandom> format;
  	Image<eWrite, eAccessRandom> dst;

	param:
	float3 start, end;

  	void process(int2 pos) {
	    if (pos.x || pos.y ) {
	      return;
	    }
    	// Here we're going to add our code
	    int number_of_points = 50;
	    int number_of_branches = 50;
		float gradient;
		float3 position;
		for (int x = 0; x < number_of_branches; x++) {
		    for (int y = 0; y < number_of_points; y++) {
				gradient = y / float(number_of_points - 1);
				position = mix(start, end, gradient);
				position += float3(x, 0.0f, 0.0f);
		  		dst(x,y) = float4(position.x, position.y, position.z, gradient);
		    }
		}
  }
};
