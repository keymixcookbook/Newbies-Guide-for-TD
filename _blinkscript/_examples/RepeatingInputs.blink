// core BlinkScript code for DotMatrix

kernel DotMatrixDisplay : ImageComputationKernel <ePixelWise>
{
    Image <eRead, eAccessRandom, eEdgeClamped> src;
    Image <eRead, eAccessRandom, eEdgeNone> tex;
    Image <eWrite> dst;

    local:
        float2 texSize;
        float2 format;
        float2 patternSize;

    param:
        float2 gap;
        float2 translate;
        bool pixelateOnly;
        int center_bias;
        bool smoothSubsample;

    void init() {
        format = float2(src.bounds.x2, src.bounds.y2);
        texSize = float2(tex.bounds.x2, tex.bounds.y2);
        patternSize = texSize + gap;
    }

    void define() {
        defineParam(translate, "translate", float2(0, 0));
    }

    void process(int2 pos) {
        float2 pos2d = float2(pos.x, pos.y);

        float2 texSamplePos = fmod(fmod((pos2d - translate), patternSize) + patternSize, patternSize);  // position within texture for sample

        float2 srcSamplePos = pos2d - texSamplePos + texSize/2;

        // sample the color behind this texture tile
        float4 colorsample;
        if (smoothSubsample) {
            colorsample = (bilinear(src, srcSamplePos.x, srcSamplePos.y) * (1 + center_bias)
                              + bilinear(src, srcSamplePos.x - texSize.x/2, srcSamplePos.y - texSize.y/2)
                              + bilinear(src, srcSamplePos.x - texSize.x/2, srcSamplePos.y + texSize.y/2)
                              + bilinear(src, srcSamplePos.x + texSize.x/2, srcSamplePos.y - texSize.y/2)
                              + bilinear(src, srcSamplePos.x + texSize.x/2, srcSamplePos.y + texSize.y/2)
                          )/(5 + center_bias);

        }  else {
            colorsample = bilinear(src, srcSamplePos.x, srcSamplePos.y);
        }


        if (pixelateOnly) {  // only show the pixelated color
            dst() = colorsample;

        }  else {  // show texture multiplied by the pixelated color
            if ((texSamplePos.x < texSize.x) && (texSamplePos.y < texSize.y)) {
                dst() = bilinear(tex, texSamplePos.x, texSamplePos.y) * colorsample;
            }  else {dst() = 0;}
        }
    }
};
