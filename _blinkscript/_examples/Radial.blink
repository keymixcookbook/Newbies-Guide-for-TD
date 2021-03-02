kernel Radial : ImageComputationKernel<ePixelWise>
{
  Image<eRead,eAccessRandom,eEdgeClamped> src;                        //input image
  Image<eWrite> dst;                                                  //output image

  param:
    float mult;                                                       //mult parameter

  local:
    float cx;                                                         //Horizontal center
    float cy;                                                         //Vertical center
    float xt;                                                         //center X axis
    float yt;                                                         //center Y axis

  void define(){
    defineParam(mult,"mult",1.0f);                                    //mult defaults
  }

  void init(int2 pos){
    xt = src.bounds.x2;                                               //bounds X
    yt = src.bounds.y2;                                               //bounds Y
    cx = xt / 2.0f;                                                   //X center from bounds
    cy = yt / 2.0f;                                                   //Y center from bounds
  }

  void process(int2 pos){
    //distance formula (sphere2D) //  sqrt(r*r + g*g) = sqrt( pow(r,2) + pow(g,2) )
    dst() = sqrt( pow( ( (pos.x-cx) / (xt/mult) ) ,2) + pow( ( (pos.y-cy) / (yt/mult) ),2) );
  }
};
