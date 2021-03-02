// https://aftbit.com/cell-noise-2/

// C++11
const uint rand_multiplier = 48271;
const uint rand_increment  = 0;
const uint rand_modulus    = 2147483647;

static int lcgRandom(int seed)
{
  return abs((seed * rand_multiplier + rand_increment) % rand_modulus);
}

// FNV Hash
const uint OFFSET_BASIS = 2166136261;
const uint FNV_PRIME = 16777619;

static uint hash(uint i, uint j, uint k)
{
  return ((((((OFFSET_BASIS ^ i) * FNV_PRIME) ^ j) * FNV_PRIME) ^ k) * FNV_PRIME);
}

// Poisson Distribution
const uint one   =  393325350;
const uint two   = 1022645910;
const uint three = 1861739990;
const uint four  = 2700834071;
const uint five  = 3372109335;
const uint six   = 3819626178;
const uint seven = 4075350088;
const uint eight = 4203212043;

static uint probLookup(uint value)
{
  if (value < one) return 1;
  if (value < two) return 2;
  if (value < three) return 3;
  if (value < four) return 4;
  if (value < five) return 5;
  if (value < six) return 6;
  if (value < seven) return 7;
  if (value < eight) return 8;
  return 9;
}

// Distance Functions
static float EuclidianDistanceFunc(float3 p1, float3 p2)
{
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z);
}

static float ManhattanDistanceFunc(float3 p1, float3 p2)
{
  return fabs(p1.x - p2.x) + fabs(p1.y - p2.y) + fabs(p1.z - p2.z);
}

static float ChebyshevDistanceFunc(float3 p1, float3 p2)
{
  float3 diff = p1 - p2;
  return max(max(fabs(diff.x), fabs(diff.y)), fabs(diff.z));
}


// Blink Kernel
kernel Worley : ImageComputationKernel<ePixelWise>
{
  Image<eWrite> dst;

  param:
    bool invert;
    float gain;
    float gamma;
    float4 dark_col;
    float4 light_col;
    float4x4 transform;

  local:
    float4x4 transform_inv;
    float z;

  void define()
  {
    defineParam(invert, "Invert", false);
    defineParam(gain, "Gain", 1.0f);
    defineParam(gamma, "Gamma", 1.0f);
    defineParam(dark_col, "Dark Colour", float4(0.0f, 0.0f, 0.0f, 1.0f));
    defineParam(light_col, "Light Colour", float4(1.0f, 1.0f, 1.0f, 1.0f));
  }

  void init()
  {
    transform_inv = transform.invert();
    z = transform_inv[2][3];
  }

  static float3 multVectMatrix(float3 vec, float4x4 M)
  {
    float3 out = float3(
      vec.x * M[0][0] + vec.y * M[0][1] + vec.z * M[0][2] + M[0][3],
      vec.x * M[1][0] + vec.y * M[1][1] + vec.z * M[1][2] + M[1][3],
      vec.x * M[2][0] + vec.y * M[2][1] + vec.z * M[2][2] + M[2][3]
    );

    return out;
  }

  float4 getColour(float a) {
    return dark_col * (1 - a) + light_col * a;
  }

  void process(int2 pos)
  {

    //Declare some values for later use
    int lastRandom, id, numberFeaturePoints;
    float distance = 6666.0f;
    float3 randomDiff, featurePoint;
    int cubeX, cubeY, cubeZ;

    float3 input = float3(float(pos.x), float(pos.y), z);
    input = multVectMatrix(input, transform_inv);

    // Determine which cube the evaluation point is in
    int evalCubeX = floor(input.x);
    int evalCubeY = floor(input.y);
    int evalCubeZ = floor(input.z);

    for (int i = -1; i < 2; ++i)
    {
      for (int j = -1; j < 2; ++j)
      {
        for (int k = -1; k < 2; ++k)
        {
            cubeX = evalCubeX + i;
            cubeY = evalCubeY + j;
            cubeZ = evalCubeZ + k;

            // Generate a reproducible random number generator for the cube
            id = lcgRandom(hash(cubeX, cubeY, cubeZ));
            // Determine how many feature points are in the cube
            numberFeaturePoints = probLookup(id);
            // Check each feature point
            for (uint l = 0; l < numberFeaturePoints; ++l)
            {
              lastRandom = lcgRandom(id);
              randomDiff.x = float(lastRandom) / rand_modulus;

              lastRandom = lcgRandom(lastRandom);
              randomDiff.y = float(lastRandom) / rand_modulus;

              lastRandom = lcgRandom(lastRandom);
              randomDiff.z = float(lastRandom) / rand_modulus;

              featurePoint = float3(randomDiff.x + float(cubeX), randomDiff.y + float(cubeY), randomDiff.z + float(cubeZ));

              distance = min(distance, length(input - featurePoint));
            }
        }
      }
    }

    if (invert)
      distance = 1.0f - distance;
    distance = pow( distance * gain, gamma );
    dst() = getColour(clamp(distance, 0.0f, 1.0f));

  }

};