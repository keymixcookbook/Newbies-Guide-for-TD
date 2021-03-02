//https://raw.githubusercontent.com/hksac/anti_aliasing_blink/master/anti_aliasing_blink
kernel WipeKernel : ImageComputationKernel<eComponentWise>
{
    Image<eRead, eAccessPoint, eEdgeClamped> above;  //image to show above the line
    Image<eRead, eAccessPoint, eEdgeClamped> below;  //image to show below the line
    Image<eWrite> dst;  //the output image

    param:
        float2 origin;
        float  angle;

    local:
        float2 vec;

    //In define(), parameters can be given labels and default values.
    void define() {
        defineParam(origin, "Origin", float2(50.0f, 50.0f));
        defineParam(angle, "Angle", 45.0f);
    }

    //The init() function is run before any calls to process().
    void init() {
        vec.x = cos(angle * PI / 180.0f);
        vec.y = sin(angle * PI / 180.0f);
    }

    //The process function is run at every pixel to produce the output.
    void process(int2 pos) {
        float2 posVec;
        posVec.x = pos.x - origin.x;
        posVec.y = pos.y - origin.y;

        //Z value of cross product
        float val1 = posVec.y * vec.x       - posVec.x * vec.y ;
        float val2 = posVec.y * vec.x       - (posVec.x+1) * vec.y;
        float val3 = (posVec.y + 1) * vec.x - posVec.x * vec.y ;
        float val4 = (posVec.y + 1) * vec.x - (posVec.x+1) * vec.y;

        float list[] = {val1, val2, val3, val4};

        //count means how many angle of corner is bigger than angle in init function.
        int count = 0;
        for (int i=0; i<4; i++){
            if (list[i] > 0.0f){
                count += 1;
            }
        };

        //first quadrant.
        if (fmod(fmod(angle, 360.0f) + 360.0f, 360.0f) >= 0 and fmod(fmod(angle, 360.0f) + 360.0f, 360.0f) < 90){
            if(count == 4) {
                dst() = above();
            }
            else if(count == 3){
                float width  = posVec.y / tan(angle * PI / 180.0f) - posVec.x;
                float height = (1 - width) * tan(angle * PI / 180.0f);
                float ratio  = (1 - width) * height / 2;
                dst()        = (1 - ratio) * above() + ratio * below();
            }
            else if(count == 2){
                float width_bot     = posVec.y     / tan(angle * PI / 180.0f) - posVec.x;
                float width_top     = (pos.y - origin.y + 1) / tan(angle * PI / 180.0f) - posVec.x;
                float ratio         = (2 - width_bot - width_top) / 2;
                if (width_bot > 1 or width_bot <= 0 or width_top > 1 or width_top <= 0){
                    float height_l  = posVec.x     * tan(angle * PI / 180.0f) - posVec.y;
                    float height_r  = (posVec.x + 1) * tan(angle * PI / 180.0f) - posVec.y;
                    ratio           = (height_l + height_r)  / 2;
                }
                dst()        = (1 - ratio) * above() + ratio * below();
            }
            else if(count == 1){
                float width  = (posVec.y + 1) / tan(angle * PI / 180.0f) - posVec.x;
                float height = width * tan(angle * PI / 180.0f);
                float ratio  = 1 - width * height / 2;
                dst()        = (1 - ratio) * above() + ratio * below();
            }
            else{
                dst()        = below();
            }
        }
        //second quadrant.
        if (fmod(fmod(angle, 360.0f) + 360.0f, 360.0f) >= 90.0f and fmod(fmod(angle, 360.0f) + 360.0f, 360.0f) < 180.0f){
            if(count == 4) {
                dst() = above();
            }
            else if(count == 3){
                float width  = (posVec.y + 1) / tan(angle * PI / 180.0f) - posVec.x;
                float height = (1 - width) * tan(angle * PI / 180.0f);
                float ratio  = fabs((1 - width) * height / 2);
                dst()        = (1 - ratio) * above() + ratio * below();
            }
            else if(count == 2){
                float width_bot  = posVec.y       / tan(angle * PI / 180.0f) - posVec.x;
                float width_top  = (posVec.y + 1) / tan(angle * PI / 180.0f) - posVec.x;
                float ratio      = (2 - width_bot - width_top) / 2;
                if (width_bot > 1 or width_bot <= 0 or width_top > 1 or width_top <= 0){
                    float height_l  = (posVec.x)     * tan(angle * PI / 180.0f) - posVec.y;
                    float height_r  = (posVec.x + 1) * tan(angle * PI / 180.0f) - posVec.y;
                    ratio           = (2 - height_l - height_r) / 2;
                }
                dst()        = (1 - ratio) * above() + ratio * below();
            }
            else if(count == 1){
                float width  = posVec.y / tan(angle * PI / 180.0f) - posVec.x;
                float height = fabs(width * tan(angle * PI / 180.0f));
                float ratio  = 1 - width * height / 2;
                dst()        = (1 - ratio) * above() + ratio * below();
            }
            else{
                dst()        = below();
            }
        }
        //third quadrant.
        if (fmod(fmod(angle, 360.0f) + 360.0f, 360.0f) >= 180.0f and fmod(fmod(angle, 360.0f) + 360.0f, 360.0f) < 270.0f){
            if(count == 4) {
                dst() = above();
            }
            else if(count == 3){
                float width  = (posVec.y + 1) / tan(angle * PI / 180.0f) - posVec.x;
                float height = fabs(width * tan(angle * PI / 180.0f));
                float ratio  = fabs(width * height / 2);
                dst()        = (1 - ratio) * above() + ratio * below();
            }
            else if(count == 2){
                float width_bot  = (posVec.y) / tan(angle * PI / 180.0f) - posVec.x;
                float width_top  = (posVec.y + 1) / tan(angle * PI / 180.0f) - posVec.x;
                float ratio = (fabs(width_bot) + fabs(width_top)) / 2;
                if (width_bot > 1 or width_bot <= 0 or width_top > 1 or width_top <= 0){
                    float height_l  = (posVec.x) * tan(angle * PI / 180.0f) - posVec.y;
                    float height_r  = (posVec.x + 1) * tan(angle * PI / 180.0f) - posVec.y;
                    ratio = 1 - (fabs(height_l) + fabs(height_r)) / 2;
                }
                dst()        = (1 - ratio) * above() + ratio * below();
            }
            else if(count == 1){
                float width  = (posVec.y) / tan(angle * PI / 180.0f) - posVec.x;
                float height = fabs((1 - width) * tan(angle * PI / 180.0f));
                float ratio  = 1 - (1 - width) * height / 2;
                dst()        = (1 - ratio) * above() + ratio * below();
            }
            else{
                dst()        = below();
            }
        }
        //fourth quadrant.
        if (fmod(fmod(angle, 360.0f) + 360.0f, 360.0f) >= 270.0f and fmod(fmod(angle, 360.0f) + 360.0f, 360.0f) < 360.0f){
            if(count == 4) {
                dst() = above();
            }
            else if(count == 3){
                float width  = (posVec.y) / tan(angle * PI / 180.0f) - posVec.x;
                float height = fabs(width * tan(angle * PI / 180.0f));
                float ratio  = fabs(width * height / 2);
                dst()        = (1 - ratio) * above() + ratio * below();
            }
            else if(count == 2){
                float width_bot  = (posVec.y) / tan(angle * PI / 180.0f) - posVec.x;
                float width_top  = (posVec.y + 1) / tan(angle * PI / 180.0f) - posVec.x;
                float ratio = fabs(width_bot + width_top) / 2;
                if (width_bot > 1 or width_bot <= 0 or width_top > 1 or width_top <= 0){
                    float height_l  = (posVec.x) * tan(angle * PI / 180.0f) - posVec.y;
                    float height_r  = (posVec.x + 1) * tan(angle * PI / 180.0f) - posVec.y;
                    ratio = fabs(height_l + height_r) / 2;
                }
                dst()        = (1 - ratio) * above() + ratio * below();
            }
            else if(count == 1){
                float width  = (posVec.y + 1) / tan(angle * PI / 180.0f) - posVec.x;
                float height = (1 - width) * tan(angle * PI / 180.0f);
                float ratio  = 1 - fabs((1 - width) * height / 2);
                dst()        = (1 - ratio) * above() + ratio * below();
            }
            else{
                dst()        = below();
            }
        }
    }
};
