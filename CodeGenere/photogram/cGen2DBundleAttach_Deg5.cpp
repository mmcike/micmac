// File Automatically generated by eLiSe
#include "StdAfx.h"
#include "cGen2DBundleAttach_Deg5.h"


cGen2DBundleAttach_Deg5::cGen2DBundleAttach_Deg5():
    cElCompiledFonc(2)
{
   AddIntRef (cIncIntervale("CX",0,21));
   AddIntRef (cIncIntervale("CY",21,42));
   Close(false);
}



void cGen2DBundleAttach_Deg5::ComputeVal()
{
   double tmp0_ = mLocPFixV_y-mLocCentrFixV_y;
   double tmp1_ = (tmp0_)/mLocAmplFixV;
   double tmp2_ = mLocPFixV_x-mLocCentrFixV_x;
   double tmp3_ = (tmp2_)/mLocAmplFixV;
   double tmp4_ = ElSquare(tmp1_);
   double tmp5_ = ElSquare(tmp3_);
   double tmp6_ = VCube(tmp1_);
   double tmp7_ = VCube(tmp3_);
   double tmp8_ = VPow4(tmp1_);
   double tmp9_ = VPow4(tmp3_);
   double tmp10_ = VPow5(tmp1_);
   double tmp11_ = VPow5(tmp3_);

  mVal[0] = (mCompCoord[0]+mCompCoord[1]*(tmp1_)+mCompCoord[2]*(tmp3_)+mCompCoord[3]*tmp4_+mCompCoord[4]*(tmp3_)*(tmp1_)+mCompCoord[5]*tmp5_+mCompCoord[6]*tmp6_+mCompCoord[7]*(tmp3_)*tmp4_+mCompCoord[8]*tmp5_*(tmp1_)+mCompCoord[9]*tmp7_+mCompCoord[10]*tmp8_+mCompCoord[11]*(tmp3_)*tmp6_+mCompCoord[12]*tmp5_*tmp4_+mCompCoord[13]*tmp7_*(tmp1_)+mCompCoord[14]*tmp9_+mCompCoord[15]*tmp10_+mCompCoord[16]*(tmp3_)*tmp8_+mCompCoord[17]*tmp5_*tmp6_+mCompCoord[18]*tmp7_*tmp4_+mCompCoord[19]*tmp9_*(tmp1_)+mCompCoord[20]*tmp11_)-mLocFixedV_x;

  mVal[1] = (mCompCoord[21]+mCompCoord[22]*(tmp1_)+mCompCoord[23]*(tmp3_)+mCompCoord[24]*tmp4_+mCompCoord[25]*(tmp3_)*(tmp1_)+mCompCoord[26]*tmp5_+mCompCoord[27]*tmp6_+mCompCoord[28]*(tmp3_)*tmp4_+mCompCoord[29]*tmp5_*(tmp1_)+mCompCoord[30]*tmp7_+mCompCoord[31]*tmp8_+mCompCoord[32]*(tmp3_)*tmp6_+mCompCoord[33]*tmp5_*tmp4_+mCompCoord[34]*tmp7_*(tmp1_)+mCompCoord[35]*tmp9_+mCompCoord[36]*tmp10_+mCompCoord[37]*(tmp3_)*tmp8_+mCompCoord[38]*tmp5_*tmp6_+mCompCoord[39]*tmp7_*tmp4_+mCompCoord[40]*tmp9_*(tmp1_)+mCompCoord[41]*tmp11_)-mLocFixedV_y;

}


void cGen2DBundleAttach_Deg5::ComputeValDeriv()
{
   double tmp0_ = mLocPFixV_y-mLocCentrFixV_y;
   double tmp1_ = (tmp0_)/mLocAmplFixV;
   double tmp2_ = mLocPFixV_x-mLocCentrFixV_x;
   double tmp3_ = (tmp2_)/mLocAmplFixV;
   double tmp4_ = ElSquare(tmp1_);
   double tmp5_ = ElSquare(tmp3_);
   double tmp6_ = VCube(tmp1_);
   double tmp7_ = VCube(tmp3_);
   double tmp8_ = VPow4(tmp1_);
   double tmp9_ = VPow4(tmp3_);
   double tmp10_ = VPow5(tmp1_);
   double tmp11_ = VPow5(tmp3_);
   double tmp12_ = (tmp3_)*(tmp1_);
   double tmp13_ = (tmp3_)*tmp4_;
   double tmp14_ = tmp5_*(tmp1_);
   double tmp15_ = (tmp3_)*tmp6_;
   double tmp16_ = tmp5_*tmp4_;
   double tmp17_ = tmp7_*(tmp1_);
   double tmp18_ = (tmp3_)*tmp8_;
   double tmp19_ = tmp5_*tmp6_;
   double tmp20_ = tmp7_*tmp4_;
   double tmp21_ = tmp9_*(tmp1_);

  mVal[0] = (mCompCoord[0]+mCompCoord[1]*(tmp1_)+mCompCoord[2]*(tmp3_)+mCompCoord[3]*tmp4_+mCompCoord[4]*(tmp3_)*(tmp1_)+mCompCoord[5]*tmp5_+mCompCoord[6]*tmp6_+mCompCoord[7]*(tmp3_)*tmp4_+mCompCoord[8]*tmp5_*(tmp1_)+mCompCoord[9]*tmp7_+mCompCoord[10]*tmp8_+mCompCoord[11]*(tmp3_)*tmp6_+mCompCoord[12]*tmp5_*tmp4_+mCompCoord[13]*tmp7_*(tmp1_)+mCompCoord[14]*tmp9_+mCompCoord[15]*tmp10_+mCompCoord[16]*(tmp3_)*tmp8_+mCompCoord[17]*tmp5_*tmp6_+mCompCoord[18]*tmp7_*tmp4_+mCompCoord[19]*tmp9_*(tmp1_)+mCompCoord[20]*tmp11_)-mLocFixedV_x;

  mCompDer[0][0] = 1;
  mCompDer[0][1] = tmp1_;
  mCompDer[0][2] = tmp3_;
  mCompDer[0][3] = tmp4_;
  mCompDer[0][4] = tmp12_;
  mCompDer[0][5] = tmp5_;
  mCompDer[0][6] = tmp6_;
  mCompDer[0][7] = tmp13_;
  mCompDer[0][8] = tmp14_;
  mCompDer[0][9] = tmp7_;
  mCompDer[0][10] = tmp8_;
  mCompDer[0][11] = tmp15_;
  mCompDer[0][12] = tmp16_;
  mCompDer[0][13] = tmp17_;
  mCompDer[0][14] = tmp9_;
  mCompDer[0][15] = tmp10_;
  mCompDer[0][16] = tmp18_;
  mCompDer[0][17] = tmp19_;
  mCompDer[0][18] = tmp20_;
  mCompDer[0][19] = tmp21_;
  mCompDer[0][20] = tmp11_;
  mCompDer[0][21] = 0;
  mCompDer[0][22] = 0;
  mCompDer[0][23] = 0;
  mCompDer[0][24] = 0;
  mCompDer[0][25] = 0;
  mCompDer[0][26] = 0;
  mCompDer[0][27] = 0;
  mCompDer[0][28] = 0;
  mCompDer[0][29] = 0;
  mCompDer[0][30] = 0;
  mCompDer[0][31] = 0;
  mCompDer[0][32] = 0;
  mCompDer[0][33] = 0;
  mCompDer[0][34] = 0;
  mCompDer[0][35] = 0;
  mCompDer[0][36] = 0;
  mCompDer[0][37] = 0;
  mCompDer[0][38] = 0;
  mCompDer[0][39] = 0;
  mCompDer[0][40] = 0;
  mCompDer[0][41] = 0;
  mVal[1] = (mCompCoord[21]+mCompCoord[22]*(tmp1_)+mCompCoord[23]*(tmp3_)+mCompCoord[24]*tmp4_+mCompCoord[25]*(tmp3_)*(tmp1_)+mCompCoord[26]*tmp5_+mCompCoord[27]*tmp6_+mCompCoord[28]*(tmp3_)*tmp4_+mCompCoord[29]*tmp5_*(tmp1_)+mCompCoord[30]*tmp7_+mCompCoord[31]*tmp8_+mCompCoord[32]*(tmp3_)*tmp6_+mCompCoord[33]*tmp5_*tmp4_+mCompCoord[34]*tmp7_*(tmp1_)+mCompCoord[35]*tmp9_+mCompCoord[36]*tmp10_+mCompCoord[37]*(tmp3_)*tmp8_+mCompCoord[38]*tmp5_*tmp6_+mCompCoord[39]*tmp7_*tmp4_+mCompCoord[40]*tmp9_*(tmp1_)+mCompCoord[41]*tmp11_)-mLocFixedV_y;

  mCompDer[1][0] = 0;
  mCompDer[1][1] = 0;
  mCompDer[1][2] = 0;
  mCompDer[1][3] = 0;
  mCompDer[1][4] = 0;
  mCompDer[1][5] = 0;
  mCompDer[1][6] = 0;
  mCompDer[1][7] = 0;
  mCompDer[1][8] = 0;
  mCompDer[1][9] = 0;
  mCompDer[1][10] = 0;
  mCompDer[1][11] = 0;
  mCompDer[1][12] = 0;
  mCompDer[1][13] = 0;
  mCompDer[1][14] = 0;
  mCompDer[1][15] = 0;
  mCompDer[1][16] = 0;
  mCompDer[1][17] = 0;
  mCompDer[1][18] = 0;
  mCompDer[1][19] = 0;
  mCompDer[1][20] = 0;
  mCompDer[1][21] = 1;
  mCompDer[1][22] = tmp1_;
  mCompDer[1][23] = tmp3_;
  mCompDer[1][24] = tmp4_;
  mCompDer[1][25] = tmp12_;
  mCompDer[1][26] = tmp5_;
  mCompDer[1][27] = tmp6_;
  mCompDer[1][28] = tmp13_;
  mCompDer[1][29] = tmp14_;
  mCompDer[1][30] = tmp7_;
  mCompDer[1][31] = tmp8_;
  mCompDer[1][32] = tmp15_;
  mCompDer[1][33] = tmp16_;
  mCompDer[1][34] = tmp17_;
  mCompDer[1][35] = tmp9_;
  mCompDer[1][36] = tmp10_;
  mCompDer[1][37] = tmp18_;
  mCompDer[1][38] = tmp19_;
  mCompDer[1][39] = tmp20_;
  mCompDer[1][40] = tmp21_;
  mCompDer[1][41] = tmp11_;
}


void cGen2DBundleAttach_Deg5::ComputeValDerivHessian()
{
  ELISE_ASSERT(false,"Foncteur cGen2DBundleAttach_Deg5 Has no Der Sec");
}

void cGen2DBundleAttach_Deg5::SetAmplFixV(double aVal){ mLocAmplFixV = aVal;}
void cGen2DBundleAttach_Deg5::SetCentrFixV_x(double aVal){ mLocCentrFixV_x = aVal;}
void cGen2DBundleAttach_Deg5::SetCentrFixV_y(double aVal){ mLocCentrFixV_y = aVal;}
void cGen2DBundleAttach_Deg5::SetFixedV_x(double aVal){ mLocFixedV_x = aVal;}
void cGen2DBundleAttach_Deg5::SetFixedV_y(double aVal){ mLocFixedV_y = aVal;}
void cGen2DBundleAttach_Deg5::SetPFixV_x(double aVal){ mLocPFixV_x = aVal;}
void cGen2DBundleAttach_Deg5::SetPFixV_y(double aVal){ mLocPFixV_y = aVal;}



double * cGen2DBundleAttach_Deg5::AdrVarLocFromString(const std::string & aName)
{
   if (aName == "AmplFixV") return & mLocAmplFixV;
   if (aName == "CentrFixV_x") return & mLocCentrFixV_x;
   if (aName == "CentrFixV_y") return & mLocCentrFixV_y;
   if (aName == "FixedV_x") return & mLocFixedV_x;
   if (aName == "FixedV_y") return & mLocFixedV_y;
   if (aName == "PFixV_x") return & mLocPFixV_x;
   if (aName == "PFixV_y") return & mLocPFixV_y;
   return 0;
}


cElCompiledFonc::cAutoAddEntry cGen2DBundleAttach_Deg5::mTheAuto("cGen2DBundleAttach_Deg5",cGen2DBundleAttach_Deg5::Alloc);


cElCompiledFonc *  cGen2DBundleAttach_Deg5::Alloc()
{  return new cGen2DBundleAttach_Deg5();
}

