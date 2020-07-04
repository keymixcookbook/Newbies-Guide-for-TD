kernel For_Loop : ImageComputationKernel <ePixelWise>
{
  Image<eRead,eAccessRandom,eEdgeClamped> src;                        //input image
  Image<eWrite> dst;                                                  //output image

  param:
    int increments;                                                   //increment param
    int amount;                                                       //amount param

  void define(){
    defineParam(increments,"increments", 1);                          //increment default
    defineParam(amount,"amount",50);                                  //amount default
  }

  void process(int2 pos) {
    int total = 0;                                                    //total initial value

    for (int i = 0; i < increments; i++) {                            //loop
      total += amount;                                                //loop sum
    }

    dst() = src((pos.x + total), pos.y);                              //out
  }
};
