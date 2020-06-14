kernel UV : ImageComputationKernel<ePixelWise>
{
    Image<eRead, eAccessRandom, eEdgeClamped> src;
    Image<eWrite> dst;

    param:
        float width;
        float height;
        bool man;

    local:
        float src_width;
        float src_height;

    void init() {
        src_width = src.bounds.x2;
        src_height = src.bounds.y2;
    }

    void define() {
        defineParam(man, "Custom Dimensions", false);
        defineParam(width, "width", 256.0f);
        defineParam(height, "height", 256.0f);
    }

    void process(int2 pos) {
        if (man == false) {
            dst(0) = pos.x / src_width;
            dst(1) = pos.y / src_height;
        } else {
            dst(0) = pos.x / width;
            dst(1) = pos.y / height;
            /* code */
        }
        dst(2) = 0.0f;
        dst(3) = 0.0f;
    }
};
