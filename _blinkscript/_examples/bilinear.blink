kernel bilinear_transform : ImageComputationKernel<ePixelWise>
{
    Image<eRead, eAccessRandom, eEdgeClamped> src;
    Image<eWrite> dst;

    param:
        float Scale;

    local:
        float cx;
        float cy;

    void define(){
        defineParam(Scale, "Scale", 1.0f);
    }

    void init(int2 pos){
        cx = src.bounds.x2/2.0f;
        cy = src.bounds.y2/2.0f;
    }

    void process(int2 pos){
        // move src to [0,0], scale, then move back to orig
        dst() = bilinear(src, ((pos.x - cx) / Scale) + cx, (pos.y - cy) / Scale + cy);
    }

};
