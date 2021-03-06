// File Automatically generated by eLiSe


#include "general/all.h"
#include "private/all.h"
#include "cEqResiduIm2NoDistId.h"


cEqResiduIm2NoDistId::cEqResiduIm2NoDistId():
    cElCompiledFonc(1)
{
   AddIntRef (cIncIntervale("Intr1",0,3));
   AddIntRef (cIncIntervale("Or1",3,9));
   AddIntRef (cIncIntervale("Or2",9,15));
   Close(false);
}



void cEqResiduIm2NoDistId::ComputeVal()
{
   double tmp0_ = mCompCoord[9];
   double tmp1_ = sin(tmp0_);
   double tmp2_ = mCompCoord[10];
   double tmp3_ = mCompCoord[11];
   double tmp4_ = mCompCoord[0];
   double tmp5_ = cos(tmp0_);
   double tmp6_ = sin(tmp3_);
   double tmp7_ = sin(tmp2_);
   double tmp8_ = -(tmp7_);
   double tmp9_ = tmp1_*tmp8_;
   double tmp10_ = cos(tmp3_);
   double tmp11_ = mCompCoord[1];
   double tmp12_ = mCompCoord[4];
   double tmp13_ = mCompCoord[2];
   double tmp14_ = cos(tmp12_);
   double tmp15_ = mCompCoord[5];
   double tmp16_ = mLocXL2-tmp11_;
   double tmp17_ = (tmp16_)/tmp4_;
   double tmp18_ = cos(tmp2_);
   double tmp19_ = mLocYL2-tmp13_;
   double tmp20_ = (tmp19_)/tmp4_;
   double tmp21_ = mLocXL1-tmp11_;
   double tmp22_ = (tmp21_)/tmp4_;
   double tmp23_ = mCompCoord[3];
   double tmp24_ = cos(tmp15_);
   double tmp25_ = sin(tmp23_);
   double tmp26_ = sin(tmp12_);
   double tmp27_ = sin(tmp15_);
   double tmp28_ = mLocYL1-tmp13_;
   double tmp29_ = (tmp28_)/tmp4_;
   double tmp30_ = cos(tmp23_);
   double tmp31_ = -(tmp26_);
   double tmp32_ = tmp25_*tmp31_;
   double tmp33_ = tmp1_*tmp18_;
   double tmp34_ = tmp33_*(tmp17_);
   double tmp35_ = tmp5_*tmp10_;
   double tmp36_ = tmp9_*tmp6_;
   double tmp37_ = tmp35_+tmp36_;
   double tmp38_ = (tmp37_)*(tmp20_);
   double tmp39_ = tmp34_+tmp38_;
   double tmp40_ = -(tmp6_);
   double tmp41_ = tmp5_*tmp40_;
   double tmp42_ = tmp9_*tmp10_;
   double tmp43_ = tmp41_+tmp42_;
   double tmp44_ = tmp39_+tmp43_;
   double tmp45_ = tmp26_*(tmp22_);
   double tmp46_ = tmp14_*tmp27_;
   double tmp47_ = tmp46_*(tmp29_);
   double tmp48_ = tmp45_+tmp47_;
   double tmp49_ = tmp14_*tmp24_;
   double tmp50_ = tmp48_+tmp49_;
   double tmp51_ = (tmp44_)*(tmp50_);
   double tmp52_ = tmp7_*(tmp17_);
   double tmp53_ = tmp18_*tmp6_;
   double tmp54_ = tmp53_*(tmp20_);
   double tmp55_ = tmp52_+tmp54_;
   double tmp56_ = tmp18_*tmp10_;
   double tmp57_ = tmp55_+tmp56_;
   double tmp58_ = tmp25_*tmp14_;
   double tmp59_ = tmp58_*(tmp22_);
   double tmp60_ = tmp30_*tmp24_;
   double tmp61_ = tmp32_*tmp27_;
   double tmp62_ = tmp60_+tmp61_;
   double tmp63_ = (tmp62_)*(tmp29_);
   double tmp64_ = tmp59_+tmp63_;
   double tmp65_ = -(tmp27_);
   double tmp66_ = tmp30_*tmp65_;
   double tmp67_ = tmp32_*tmp24_;
   double tmp68_ = tmp66_+tmp67_;
   double tmp69_ = tmp64_+tmp68_;
   double tmp70_ = (tmp57_)*(tmp69_);
   double tmp71_ = tmp51_-tmp70_;
   double tmp72_ = -(tmp25_);
   double tmp73_ = tmp30_*tmp31_;
   double tmp74_ = -(tmp1_);
   double tmp75_ = tmp5_*tmp8_;
   double tmp76_ = tmp30_*tmp14_;
   double tmp77_ = tmp76_*(tmp22_);
   double tmp78_ = tmp72_*tmp24_;
   double tmp79_ = tmp73_*tmp27_;
   double tmp80_ = tmp78_+tmp79_;
   double tmp81_ = (tmp80_)*(tmp29_);
   double tmp82_ = tmp77_+tmp81_;
   double tmp83_ = tmp72_*tmp65_;
   double tmp84_ = tmp73_*tmp24_;
   double tmp85_ = tmp83_+tmp84_;
   double tmp86_ = tmp82_+tmp85_;
   double tmp87_ = (tmp57_)*(tmp86_);
   double tmp88_ = tmp5_*tmp18_;
   double tmp89_ = tmp88_*(tmp17_);
   double tmp90_ = tmp74_*tmp10_;
   double tmp91_ = tmp75_*tmp6_;
   double tmp92_ = tmp90_+tmp91_;
   double tmp93_ = (tmp92_)*(tmp20_);
   double tmp94_ = tmp89_+tmp93_;
   double tmp95_ = tmp74_*tmp40_;
   double tmp96_ = tmp75_*tmp10_;
   double tmp97_ = tmp95_+tmp96_;
   double tmp98_ = tmp94_+tmp97_;
   double tmp99_ = (tmp98_)*(tmp50_);
   double tmp100_ = tmp87_-tmp99_;
   double tmp101_ = (tmp98_)*(tmp69_);
   double tmp102_ = (tmp44_)*(tmp86_);
   double tmp103_ = tmp101_-tmp102_;
   double tmp104_ = mCompCoord[14];
   double tmp105_ = mCompCoord[8];
   double tmp106_ = tmp104_-tmp105_;
   double tmp107_ = mCompCoord[12];
   double tmp108_ = mCompCoord[6];
   double tmp109_ = tmp107_-tmp108_;
   double tmp110_ = mCompCoord[13];
   double tmp111_ = mCompCoord[7];
   double tmp112_ = tmp110_-tmp111_;
   double tmp113_ = (tmp112_)*(tmp50_);
   double tmp114_ = (tmp106_)*(tmp69_);
   double tmp115_ = tmp113_-tmp114_;
   double tmp116_ = (tmp106_)*(tmp86_);
   double tmp117_ = (tmp109_)*(tmp50_);
   double tmp118_ = tmp116_-tmp117_;
   double tmp119_ = (tmp109_)*(tmp69_);
   double tmp120_ = (tmp112_)*(tmp86_);
   double tmp121_ = tmp119_-tmp120_;

  mVal[0] = (sqrt((tmp71_)*(tmp71_)+(tmp100_)*(tmp100_)+(tmp103_)*(tmp103_))/sqrt((tmp98_)*(tmp98_)+(tmp44_)*(tmp44_)+(tmp57_)*(tmp57_)))*(((tmp115_)*(tmp98_)+(tmp118_)*(tmp44_)+(tmp121_)*(tmp57_))/((tmp115_)*(tmp71_)+(tmp118_)*(tmp100_)+(tmp121_)*(tmp103_)));

}


void cEqResiduIm2NoDistId::ComputeValDeriv()
{
   double tmp0_ = mCompCoord[9];
   double tmp1_ = sin(tmp0_);
   double tmp2_ = mCompCoord[10];
   double tmp3_ = mCompCoord[11];
   double tmp4_ = mCompCoord[0];
   double tmp5_ = cos(tmp0_);
   double tmp6_ = sin(tmp3_);
   double tmp7_ = sin(tmp2_);
   double tmp8_ = -(tmp7_);
   double tmp9_ = tmp1_*tmp8_;
   double tmp10_ = cos(tmp3_);
   double tmp11_ = mCompCoord[1];
   double tmp12_ = mCompCoord[4];
   double tmp13_ = mCompCoord[2];
   double tmp14_ = cos(tmp12_);
   double tmp15_ = mCompCoord[5];
   double tmp16_ = mLocXL2-tmp11_;
   double tmp17_ = (tmp16_)/tmp4_;
   double tmp18_ = cos(tmp2_);
   double tmp19_ = mLocYL2-tmp13_;
   double tmp20_ = (tmp19_)/tmp4_;
   double tmp21_ = mLocXL1-tmp11_;
   double tmp22_ = (tmp21_)/tmp4_;
   double tmp23_ = mCompCoord[3];
   double tmp24_ = cos(tmp15_);
   double tmp25_ = sin(tmp23_);
   double tmp26_ = sin(tmp12_);
   double tmp27_ = sin(tmp15_);
   double tmp28_ = mLocYL1-tmp13_;
   double tmp29_ = (tmp28_)/tmp4_;
   double tmp30_ = cos(tmp23_);
   double tmp31_ = -(tmp26_);
   double tmp32_ = tmp25_*tmp31_;
   double tmp33_ = tmp1_*tmp18_;
   double tmp34_ = tmp33_*(tmp17_);
   double tmp35_ = tmp5_*tmp10_;
   double tmp36_ = tmp9_*tmp6_;
   double tmp37_ = tmp35_+tmp36_;
   double tmp38_ = (tmp37_)*(tmp20_);
   double tmp39_ = tmp34_+tmp38_;
   double tmp40_ = -(tmp6_);
   double tmp41_ = tmp5_*tmp40_;
   double tmp42_ = tmp9_*tmp10_;
   double tmp43_ = tmp41_+tmp42_;
   double tmp44_ = tmp39_+tmp43_;
   double tmp45_ = tmp26_*(tmp22_);
   double tmp46_ = tmp14_*tmp27_;
   double tmp47_ = tmp46_*(tmp29_);
   double tmp48_ = tmp45_+tmp47_;
   double tmp49_ = tmp14_*tmp24_;
   double tmp50_ = tmp48_+tmp49_;
   double tmp51_ = (tmp44_)*(tmp50_);
   double tmp52_ = tmp7_*(tmp17_);
   double tmp53_ = tmp18_*tmp6_;
   double tmp54_ = tmp53_*(tmp20_);
   double tmp55_ = tmp52_+tmp54_;
   double tmp56_ = tmp18_*tmp10_;
   double tmp57_ = tmp55_+tmp56_;
   double tmp58_ = tmp25_*tmp14_;
   double tmp59_ = tmp58_*(tmp22_);
   double tmp60_ = tmp30_*tmp24_;
   double tmp61_ = tmp32_*tmp27_;
   double tmp62_ = tmp60_+tmp61_;
   double tmp63_ = (tmp62_)*(tmp29_);
   double tmp64_ = tmp59_+tmp63_;
   double tmp65_ = -(tmp27_);
   double tmp66_ = tmp30_*tmp65_;
   double tmp67_ = tmp32_*tmp24_;
   double tmp68_ = tmp66_+tmp67_;
   double tmp69_ = tmp64_+tmp68_;
   double tmp70_ = (tmp57_)*(tmp69_);
   double tmp71_ = tmp51_-tmp70_;
   double tmp72_ = -(tmp25_);
   double tmp73_ = tmp30_*tmp31_;
   double tmp74_ = -(tmp1_);
   double tmp75_ = tmp5_*tmp8_;
   double tmp76_ = tmp30_*tmp14_;
   double tmp77_ = tmp76_*(tmp22_);
   double tmp78_ = tmp72_*tmp24_;
   double tmp79_ = tmp73_*tmp27_;
   double tmp80_ = tmp78_+tmp79_;
   double tmp81_ = (tmp80_)*(tmp29_);
   double tmp82_ = tmp77_+tmp81_;
   double tmp83_ = tmp72_*tmp65_;
   double tmp84_ = tmp73_*tmp24_;
   double tmp85_ = tmp83_+tmp84_;
   double tmp86_ = tmp82_+tmp85_;
   double tmp87_ = (tmp57_)*(tmp86_);
   double tmp88_ = tmp5_*tmp18_;
   double tmp89_ = tmp88_*(tmp17_);
   double tmp90_ = tmp74_*tmp10_;
   double tmp91_ = tmp75_*tmp6_;
   double tmp92_ = tmp90_+tmp91_;
   double tmp93_ = (tmp92_)*(tmp20_);
   double tmp94_ = tmp89_+tmp93_;
   double tmp95_ = tmp74_*tmp40_;
   double tmp96_ = tmp75_*tmp10_;
   double tmp97_ = tmp95_+tmp96_;
   double tmp98_ = tmp94_+tmp97_;
   double tmp99_ = (tmp98_)*(tmp50_);
   double tmp100_ = tmp87_-tmp99_;
   double tmp101_ = (tmp98_)*(tmp69_);
   double tmp102_ = (tmp44_)*(tmp86_);
   double tmp103_ = tmp101_-tmp102_;
   double tmp104_ = mCompCoord[14];
   double tmp105_ = mCompCoord[8];
   double tmp106_ = tmp104_-tmp105_;
   double tmp107_ = mCompCoord[12];
   double tmp108_ = mCompCoord[6];
   double tmp109_ = tmp107_-tmp108_;
   double tmp110_ = mCompCoord[13];
   double tmp111_ = mCompCoord[7];
   double tmp112_ = tmp110_-tmp111_;
   double tmp113_ = (tmp112_)*(tmp50_);
   double tmp114_ = (tmp106_)*(tmp69_);
   double tmp115_ = tmp113_-tmp114_;
   double tmp116_ = (tmp106_)*(tmp86_);
   double tmp117_ = (tmp109_)*(tmp50_);
   double tmp118_ = tmp116_-tmp117_;
   double tmp119_ = (tmp109_)*(tmp69_);
   double tmp120_ = (tmp112_)*(tmp86_);
   double tmp121_ = tmp119_-tmp120_;
   double tmp122_ = ElSquare(tmp4_);
   double tmp123_ = -(tmp16_);
   double tmp124_ = tmp123_/tmp122_;
   double tmp125_ = -(tmp19_);
   double tmp126_ = tmp125_/tmp122_;
   double tmp127_ = -(tmp21_);
   double tmp128_ = tmp127_/tmp122_;
   double tmp129_ = -(tmp28_);
   double tmp130_ = tmp129_/tmp122_;
   double tmp131_ = (tmp124_)*tmp33_;
   double tmp132_ = (tmp126_)*(tmp37_);
   double tmp133_ = tmp131_+tmp132_;
   double tmp134_ = (tmp133_)*(tmp50_);
   double tmp135_ = (tmp128_)*tmp26_;
   double tmp136_ = (tmp130_)*tmp46_;
   double tmp137_ = tmp135_+tmp136_;
   double tmp138_ = (tmp137_)*(tmp44_);
   double tmp139_ = tmp134_+tmp138_;
   double tmp140_ = (tmp124_)*tmp7_;
   double tmp141_ = (tmp126_)*tmp53_;
   double tmp142_ = tmp140_+tmp141_;
   double tmp143_ = (tmp142_)*(tmp69_);
   double tmp144_ = (tmp128_)*tmp58_;
   double tmp145_ = (tmp130_)*(tmp62_);
   double tmp146_ = tmp144_+tmp145_;
   double tmp147_ = (tmp146_)*(tmp57_);
   double tmp148_ = tmp143_+tmp147_;
   double tmp149_ = (tmp139_)-(tmp148_);
   double tmp150_ = (tmp149_)*(tmp71_);
   double tmp151_ = (tmp142_)*(tmp86_);
   double tmp152_ = (tmp128_)*tmp76_;
   double tmp153_ = (tmp130_)*(tmp80_);
   double tmp154_ = tmp152_+tmp153_;
   double tmp155_ = (tmp154_)*(tmp57_);
   double tmp156_ = tmp151_+tmp155_;
   double tmp157_ = (tmp124_)*tmp88_;
   double tmp158_ = (tmp126_)*(tmp92_);
   double tmp159_ = tmp157_+tmp158_;
   double tmp160_ = (tmp159_)*(tmp50_);
   double tmp161_ = (tmp137_)*(tmp98_);
   double tmp162_ = tmp160_+tmp161_;
   double tmp163_ = (tmp156_)-(tmp162_);
   double tmp164_ = (tmp163_)*(tmp100_);
   double tmp165_ = (tmp159_)*(tmp69_);
   double tmp166_ = (tmp146_)*(tmp98_);
   double tmp167_ = tmp165_+tmp166_;
   double tmp168_ = (tmp133_)*(tmp86_);
   double tmp169_ = (tmp154_)*(tmp44_);
   double tmp170_ = tmp168_+tmp169_;
   double tmp171_ = (tmp167_)-(tmp170_);
   double tmp172_ = (tmp171_)*(tmp103_);
   double tmp173_ = (tmp71_)*(tmp71_);
   double tmp174_ = (tmp100_)*(tmp100_);
   double tmp175_ = tmp173_+tmp174_;
   double tmp176_ = (tmp103_)*(tmp103_);
   double tmp177_ = tmp175_+tmp176_;
   double tmp178_ = sqrt(tmp177_);
   double tmp179_ = (tmp98_)*(tmp98_);
   double tmp180_ = (tmp44_)*(tmp44_);
   double tmp181_ = tmp179_+tmp180_;
   double tmp182_ = (tmp57_)*(tmp57_);
   double tmp183_ = tmp181_+tmp182_;
   double tmp184_ = sqrt(tmp183_);
   double tmp185_ = (tmp159_)*(tmp98_);
   double tmp186_ = (tmp133_)*(tmp44_);
   double tmp187_ = (tmp142_)*(tmp57_);
   double tmp188_ = (tmp115_)*(tmp98_);
   double tmp189_ = (tmp118_)*(tmp44_);
   double tmp190_ = tmp188_+tmp189_;
   double tmp191_ = (tmp121_)*(tmp57_);
   double tmp192_ = tmp190_+tmp191_;
   double tmp193_ = (tmp115_)*(tmp71_);
   double tmp194_ = (tmp118_)*(tmp100_);
   double tmp195_ = tmp193_+tmp194_;
   double tmp196_ = (tmp121_)*(tmp103_);
   double tmp197_ = tmp195_+tmp196_;
   double tmp198_ = (tmp192_)/(tmp197_);
   double tmp199_ = (tmp137_)*(tmp112_);
   double tmp200_ = (tmp146_)*(tmp106_);
   double tmp201_ = tmp199_-tmp200_;
   double tmp202_ = (tmp154_)*(tmp106_);
   double tmp203_ = (tmp137_)*(tmp109_);
   double tmp204_ = tmp202_-tmp203_;
   double tmp205_ = (tmp146_)*(tmp109_);
   double tmp206_ = (tmp154_)*(tmp112_);
   double tmp207_ = tmp205_-tmp206_;
   double tmp208_ = tmp178_/tmp184_;
   double tmp209_ = -(1);
   double tmp210_ = tmp209_*tmp4_;
   double tmp211_ = (tmp210_)/tmp122_;
   double tmp212_ = (tmp211_)*tmp33_;
   double tmp213_ = tmp212_*(tmp50_);
   double tmp214_ = (tmp211_)*tmp26_;
   double tmp215_ = tmp214_*(tmp44_);
   double tmp216_ = tmp213_+tmp215_;
   double tmp217_ = (tmp211_)*tmp7_;
   double tmp218_ = tmp217_*(tmp69_);
   double tmp219_ = (tmp211_)*tmp58_;
   double tmp220_ = tmp219_*(tmp57_);
   double tmp221_ = tmp218_+tmp220_;
   double tmp222_ = (tmp216_)-(tmp221_);
   double tmp223_ = (tmp222_)*(tmp71_);
   double tmp224_ = tmp217_*(tmp86_);
   double tmp225_ = (tmp211_)*tmp76_;
   double tmp226_ = tmp225_*(tmp57_);
   double tmp227_ = tmp224_+tmp226_;
   double tmp228_ = (tmp211_)*tmp88_;
   double tmp229_ = tmp228_*(tmp50_);
   double tmp230_ = tmp214_*(tmp98_);
   double tmp231_ = tmp229_+tmp230_;
   double tmp232_ = (tmp227_)-(tmp231_);
   double tmp233_ = (tmp232_)*(tmp100_);
   double tmp234_ = tmp228_*(tmp69_);
   double tmp235_ = tmp219_*(tmp98_);
   double tmp236_ = tmp234_+tmp235_;
   double tmp237_ = tmp212_*(tmp86_);
   double tmp238_ = tmp225_*(tmp44_);
   double tmp239_ = tmp237_+tmp238_;
   double tmp240_ = (tmp236_)-(tmp239_);
   double tmp241_ = (tmp240_)*(tmp103_);
   double tmp242_ = tmp228_*(tmp98_);
   double tmp243_ = tmp212_*(tmp44_);
   double tmp244_ = tmp217_*(tmp57_);
   double tmp245_ = ElSquare(tmp184_);
   double tmp246_ = tmp214_*(tmp112_);
   double tmp247_ = tmp219_*(tmp106_);
   double tmp248_ = tmp246_-tmp247_;
   double tmp249_ = tmp225_*(tmp106_);
   double tmp250_ = tmp214_*(tmp109_);
   double tmp251_ = tmp249_-tmp250_;
   double tmp252_ = tmp219_*(tmp109_);
   double tmp253_ = tmp225_*(tmp112_);
   double tmp254_ = tmp252_-tmp253_;
   double tmp255_ = ElSquare(tmp197_);
   double tmp256_ = (tmp211_)*(tmp37_);
   double tmp257_ = tmp256_*(tmp50_);
   double tmp258_ = (tmp211_)*tmp46_;
   double tmp259_ = tmp258_*(tmp44_);
   double tmp260_ = tmp257_+tmp259_;
   double tmp261_ = (tmp211_)*tmp53_;
   double tmp262_ = tmp261_*(tmp69_);
   double tmp263_ = (tmp211_)*(tmp62_);
   double tmp264_ = tmp263_*(tmp57_);
   double tmp265_ = tmp262_+tmp264_;
   double tmp266_ = (tmp260_)-(tmp265_);
   double tmp267_ = (tmp266_)*(tmp71_);
   double tmp268_ = tmp261_*(tmp86_);
   double tmp269_ = (tmp211_)*(tmp80_);
   double tmp270_ = tmp269_*(tmp57_);
   double tmp271_ = tmp268_+tmp270_;
   double tmp272_ = (tmp211_)*(tmp92_);
   double tmp273_ = tmp272_*(tmp50_);
   double tmp274_ = tmp258_*(tmp98_);
   double tmp275_ = tmp273_+tmp274_;
   double tmp276_ = (tmp271_)-(tmp275_);
   double tmp277_ = (tmp276_)*(tmp100_);
   double tmp278_ = tmp272_*(tmp69_);
   double tmp279_ = tmp263_*(tmp98_);
   double tmp280_ = tmp278_+tmp279_;
   double tmp281_ = tmp256_*(tmp86_);
   double tmp282_ = tmp269_*(tmp44_);
   double tmp283_ = tmp281_+tmp282_;
   double tmp284_ = (tmp280_)-(tmp283_);
   double tmp285_ = (tmp284_)*(tmp103_);
   double tmp286_ = tmp272_*(tmp98_);
   double tmp287_ = tmp256_*(tmp44_);
   double tmp288_ = tmp261_*(tmp57_);
   double tmp289_ = tmp258_*(tmp112_);
   double tmp290_ = tmp263_*(tmp106_);
   double tmp291_ = tmp289_-tmp290_;
   double tmp292_ = tmp269_*(tmp106_);
   double tmp293_ = tmp258_*(tmp109_);
   double tmp294_ = tmp292_-tmp293_;
   double tmp295_ = tmp263_*(tmp109_);
   double tmp296_ = tmp269_*(tmp112_);
   double tmp297_ = tmp295_-tmp296_;
   double tmp298_ = tmp209_*tmp25_;
   double tmp299_ = tmp298_*tmp24_;
   double tmp300_ = tmp299_+tmp79_;
   double tmp301_ = (tmp300_)*(tmp29_);
   double tmp302_ = tmp77_+tmp301_;
   double tmp303_ = tmp298_*tmp65_;
   double tmp304_ = tmp303_+tmp84_;
   double tmp305_ = tmp302_+tmp304_;
   double tmp306_ = (tmp305_)*(tmp57_);
   double tmp307_ = -(tmp306_);
   double tmp308_ = tmp307_*(tmp71_);
   double tmp309_ = -(tmp30_);
   double tmp310_ = tmp298_*tmp31_;
   double tmp311_ = tmp298_*tmp14_;
   double tmp312_ = tmp311_*(tmp22_);
   double tmp313_ = tmp309_*tmp24_;
   double tmp314_ = tmp310_*tmp27_;
   double tmp315_ = tmp313_+tmp314_;
   double tmp316_ = (tmp315_)*(tmp29_);
   double tmp317_ = tmp312_+tmp316_;
   double tmp318_ = tmp309_*tmp65_;
   double tmp319_ = tmp310_*tmp24_;
   double tmp320_ = tmp318_+tmp319_;
   double tmp321_ = tmp317_+tmp320_;
   double tmp322_ = (tmp321_)*(tmp57_);
   double tmp323_ = tmp322_*(tmp100_);
   double tmp324_ = (tmp305_)*(tmp98_);
   double tmp325_ = (tmp321_)*(tmp44_);
   double tmp326_ = tmp324_-tmp325_;
   double tmp327_ = (tmp326_)*(tmp103_);
   double tmp328_ = (tmp305_)*(tmp106_);
   double tmp329_ = -(tmp328_);
   double tmp330_ = (tmp321_)*(tmp106_);
   double tmp331_ = (tmp305_)*(tmp109_);
   double tmp332_ = (tmp321_)*(tmp112_);
   double tmp333_ = tmp331_-tmp332_;
   double tmp334_ = tmp209_*tmp26_;
   double tmp335_ = -(tmp14_);
   double tmp336_ = tmp335_*tmp25_;
   double tmp337_ = tmp14_*(tmp22_);
   double tmp338_ = tmp334_*tmp27_;
   double tmp339_ = tmp338_*(tmp29_);
   double tmp340_ = tmp337_+tmp339_;
   double tmp341_ = tmp334_*tmp24_;
   double tmp342_ = tmp340_+tmp341_;
   double tmp343_ = (tmp342_)*(tmp44_);
   double tmp344_ = tmp334_*tmp25_;
   double tmp345_ = tmp344_*(tmp22_);
   double tmp346_ = tmp336_*tmp27_;
   double tmp347_ = tmp346_*(tmp29_);
   double tmp348_ = tmp345_+tmp347_;
   double tmp349_ = tmp336_*tmp24_;
   double tmp350_ = tmp348_+tmp349_;
   double tmp351_ = (tmp350_)*(tmp57_);
   double tmp352_ = tmp343_-tmp351_;
   double tmp353_ = (tmp352_)*(tmp71_);
   double tmp354_ = tmp335_*tmp30_;
   double tmp355_ = tmp334_*tmp30_;
   double tmp356_ = tmp355_*(tmp22_);
   double tmp357_ = tmp354_*tmp27_;
   double tmp358_ = tmp357_*(tmp29_);
   double tmp359_ = tmp356_+tmp358_;
   double tmp360_ = tmp354_*tmp24_;
   double tmp361_ = tmp359_+tmp360_;
   double tmp362_ = (tmp361_)*(tmp57_);
   double tmp363_ = (tmp342_)*(tmp98_);
   double tmp364_ = tmp362_-tmp363_;
   double tmp365_ = (tmp364_)*(tmp100_);
   double tmp366_ = (tmp350_)*(tmp98_);
   double tmp367_ = (tmp361_)*(tmp44_);
   double tmp368_ = tmp366_-tmp367_;
   double tmp369_ = (tmp368_)*(tmp103_);
   double tmp370_ = (tmp342_)*(tmp112_);
   double tmp371_ = (tmp350_)*(tmp106_);
   double tmp372_ = tmp370_-tmp371_;
   double tmp373_ = (tmp361_)*(tmp106_);
   double tmp374_ = (tmp342_)*(tmp109_);
   double tmp375_ = tmp373_-tmp374_;
   double tmp376_ = (tmp350_)*(tmp109_);
   double tmp377_ = (tmp361_)*(tmp112_);
   double tmp378_ = tmp376_-tmp377_;
   double tmp379_ = tmp209_*tmp27_;
   double tmp380_ = tmp24_*tmp14_;
   double tmp381_ = tmp380_*(tmp29_);
   double tmp382_ = tmp379_*tmp14_;
   double tmp383_ = tmp381_+tmp382_;
   double tmp384_ = (tmp383_)*(tmp44_);
   double tmp385_ = tmp379_*tmp30_;
   double tmp386_ = tmp24_*tmp32_;
   double tmp387_ = tmp385_+tmp386_;
   double tmp388_ = (tmp387_)*(tmp29_);
   double tmp389_ = -(tmp24_);
   double tmp390_ = tmp389_*tmp30_;
   double tmp391_ = tmp379_*tmp32_;
   double tmp392_ = tmp390_+tmp391_;
   double tmp393_ = tmp388_+tmp392_;
   double tmp394_ = (tmp393_)*(tmp57_);
   double tmp395_ = tmp384_-tmp394_;
   double tmp396_ = (tmp395_)*(tmp71_);
   double tmp397_ = tmp379_*tmp72_;
   double tmp398_ = tmp24_*tmp73_;
   double tmp399_ = tmp397_+tmp398_;
   double tmp400_ = (tmp399_)*(tmp29_);
   double tmp401_ = tmp389_*tmp72_;
   double tmp402_ = tmp379_*tmp73_;
   double tmp403_ = tmp401_+tmp402_;
   double tmp404_ = tmp400_+tmp403_;
   double tmp405_ = (tmp404_)*(tmp57_);
   double tmp406_ = (tmp383_)*(tmp98_);
   double tmp407_ = tmp405_-tmp406_;
   double tmp408_ = (tmp407_)*(tmp100_);
   double tmp409_ = (tmp393_)*(tmp98_);
   double tmp410_ = (tmp404_)*(tmp44_);
   double tmp411_ = tmp409_-tmp410_;
   double tmp412_ = (tmp411_)*(tmp103_);
   double tmp413_ = (tmp383_)*(tmp112_);
   double tmp414_ = (tmp393_)*(tmp106_);
   double tmp415_ = tmp413_-tmp414_;
   double tmp416_ = (tmp404_)*(tmp106_);
   double tmp417_ = (tmp383_)*(tmp109_);
   double tmp418_ = tmp416_-tmp417_;
   double tmp419_ = (tmp393_)*(tmp109_);
   double tmp420_ = (tmp404_)*(tmp112_);
   double tmp421_ = tmp419_-tmp420_;
   double tmp422_ = tmp209_*(tmp50_);
   double tmp423_ = -(tmp422_);
   double tmp424_ = tmp209_*(tmp69_);
   double tmp425_ = tmp209_*(tmp86_);
   double tmp426_ = -(tmp425_);
   double tmp427_ = -(tmp424_);
   double tmp428_ = tmp209_*tmp1_;
   double tmp429_ = tmp428_*tmp10_;
   double tmp430_ = tmp429_+tmp91_;
   double tmp431_ = (tmp430_)*(tmp20_);
   double tmp432_ = tmp89_+tmp431_;
   double tmp433_ = tmp428_*tmp40_;
   double tmp434_ = tmp433_+tmp96_;
   double tmp435_ = tmp432_+tmp434_;
   double tmp436_ = (tmp435_)*(tmp50_);
   double tmp437_ = tmp436_*(tmp71_);
   double tmp438_ = -(tmp5_);
   double tmp439_ = tmp428_*tmp8_;
   double tmp440_ = tmp428_*tmp18_;
   double tmp441_ = tmp440_*(tmp17_);
   double tmp442_ = tmp438_*tmp10_;
   double tmp443_ = tmp439_*tmp6_;
   double tmp444_ = tmp442_+tmp443_;
   double tmp445_ = (tmp444_)*(tmp20_);
   double tmp446_ = tmp441_+tmp445_;
   double tmp447_ = tmp438_*tmp40_;
   double tmp448_ = tmp439_*tmp10_;
   double tmp449_ = tmp447_+tmp448_;
   double tmp450_ = tmp446_+tmp449_;
   double tmp451_ = (tmp450_)*(tmp50_);
   double tmp452_ = -(tmp451_);
   double tmp453_ = tmp452_*(tmp100_);
   double tmp454_ = (tmp450_)*(tmp69_);
   double tmp455_ = (tmp435_)*(tmp86_);
   double tmp456_ = tmp454_-tmp455_;
   double tmp457_ = (tmp456_)*(tmp103_);
   double tmp458_ = (tmp450_)*(tmp98_);
   double tmp459_ = (tmp435_)*(tmp44_);
   double tmp460_ = -(tmp18_);
   double tmp461_ = tmp460_*tmp1_;
   double tmp462_ = tmp209_*tmp7_;
   double tmp463_ = tmp462_*tmp1_;
   double tmp464_ = tmp463_*(tmp17_);
   double tmp465_ = tmp461_*tmp6_;
   double tmp466_ = tmp465_*(tmp20_);
   double tmp467_ = tmp464_+tmp466_;
   double tmp468_ = tmp461_*tmp10_;
   double tmp469_ = tmp467_+tmp468_;
   double tmp470_ = (tmp469_)*(tmp50_);
   double tmp471_ = tmp18_*(tmp17_);
   double tmp472_ = tmp462_*tmp6_;
   double tmp473_ = tmp472_*(tmp20_);
   double tmp474_ = tmp471_+tmp473_;
   double tmp475_ = tmp462_*tmp10_;
   double tmp476_ = tmp474_+tmp475_;
   double tmp477_ = (tmp476_)*(tmp69_);
   double tmp478_ = tmp470_-tmp477_;
   double tmp479_ = (tmp478_)*(tmp71_);
   double tmp480_ = tmp460_*tmp5_;
   double tmp481_ = (tmp476_)*(tmp86_);
   double tmp482_ = tmp462_*tmp5_;
   double tmp483_ = tmp482_*(tmp17_);
   double tmp484_ = tmp480_*tmp6_;
   double tmp485_ = tmp484_*(tmp20_);
   double tmp486_ = tmp483_+tmp485_;
   double tmp487_ = tmp480_*tmp10_;
   double tmp488_ = tmp486_+tmp487_;
   double tmp489_ = (tmp488_)*(tmp50_);
   double tmp490_ = tmp481_-tmp489_;
   double tmp491_ = (tmp490_)*(tmp100_);
   double tmp492_ = (tmp488_)*(tmp69_);
   double tmp493_ = (tmp469_)*(tmp86_);
   double tmp494_ = tmp492_-tmp493_;
   double tmp495_ = (tmp494_)*(tmp103_);
   double tmp496_ = (tmp488_)*(tmp98_);
   double tmp497_ = (tmp469_)*(tmp44_);
   double tmp498_ = (tmp476_)*(tmp57_);
   double tmp499_ = tmp209_*tmp6_;
   double tmp500_ = tmp499_*tmp5_;
   double tmp501_ = tmp10_*tmp9_;
   double tmp502_ = tmp500_+tmp501_;
   double tmp503_ = (tmp502_)*(tmp20_);
   double tmp504_ = -(tmp10_);
   double tmp505_ = tmp504_*tmp5_;
   double tmp506_ = tmp499_*tmp9_;
   double tmp507_ = tmp505_+tmp506_;
   double tmp508_ = tmp503_+tmp507_;
   double tmp509_ = (tmp508_)*(tmp50_);
   double tmp510_ = tmp10_*tmp18_;
   double tmp511_ = tmp510_*(tmp20_);
   double tmp512_ = tmp499_*tmp18_;
   double tmp513_ = tmp511_+tmp512_;
   double tmp514_ = (tmp513_)*(tmp69_);
   double tmp515_ = tmp509_-tmp514_;
   double tmp516_ = (tmp515_)*(tmp71_);
   double tmp517_ = (tmp513_)*(tmp86_);
   double tmp518_ = tmp499_*tmp74_;
   double tmp519_ = tmp10_*tmp75_;
   double tmp520_ = tmp518_+tmp519_;
   double tmp521_ = (tmp520_)*(tmp20_);
   double tmp522_ = tmp504_*tmp74_;
   double tmp523_ = tmp499_*tmp75_;
   double tmp524_ = tmp522_+tmp523_;
   double tmp525_ = tmp521_+tmp524_;
   double tmp526_ = (tmp525_)*(tmp50_);
   double tmp527_ = tmp517_-tmp526_;
   double tmp528_ = (tmp527_)*(tmp100_);
   double tmp529_ = (tmp525_)*(tmp69_);
   double tmp530_ = (tmp508_)*(tmp86_);
   double tmp531_ = tmp529_-tmp530_;
   double tmp532_ = (tmp531_)*(tmp103_);
   double tmp533_ = (tmp525_)*(tmp98_);
   double tmp534_ = (tmp508_)*(tmp44_);
   double tmp535_ = (tmp513_)*(tmp57_);
   double tmp536_ = -(tmp50_);
   double tmp537_ = -(tmp86_);
   double tmp538_ = -(tmp69_);

  mVal[0] = (tmp208_)*(tmp198_);

  mCompDer[0][0] = ((((0.500000*(tmp150_+tmp150_+tmp164_+tmp164_+tmp172_+tmp172_))/tmp178_)*tmp184_-tmp178_*((0.500000*(tmp185_+tmp185_+tmp186_+tmp186_+tmp187_+tmp187_))/tmp184_))/tmp245_)*(tmp198_)+((((tmp201_)*(tmp98_)+(tmp159_)*(tmp115_)+(tmp204_)*(tmp44_)+(tmp133_)*(tmp118_)+(tmp207_)*(tmp57_)+(tmp142_)*(tmp121_))*(tmp197_)-(tmp192_)*((tmp201_)*(tmp71_)+(tmp149_)*(tmp115_)+(tmp204_)*(tmp100_)+(tmp163_)*(tmp118_)+(tmp207_)*(tmp103_)+(tmp171_)*(tmp121_)))/tmp255_)*(tmp208_);
  mCompDer[0][1] = ((((0.500000*(tmp223_+tmp223_+tmp233_+tmp233_+tmp241_+tmp241_))/tmp178_)*tmp184_-tmp178_*((0.500000*(tmp242_+tmp242_+tmp243_+tmp243_+tmp244_+tmp244_))/tmp184_))/tmp245_)*(tmp198_)+((((tmp248_)*(tmp98_)+tmp228_*(tmp115_)+(tmp251_)*(tmp44_)+tmp212_*(tmp118_)+(tmp254_)*(tmp57_)+tmp217_*(tmp121_))*(tmp197_)-(tmp192_)*((tmp248_)*(tmp71_)+(tmp222_)*(tmp115_)+(tmp251_)*(tmp100_)+(tmp232_)*(tmp118_)+(tmp254_)*(tmp103_)+(tmp240_)*(tmp121_)))/tmp255_)*(tmp208_);
  mCompDer[0][2] = ((((0.500000*(tmp267_+tmp267_+tmp277_+tmp277_+tmp285_+tmp285_))/tmp178_)*tmp184_-tmp178_*((0.500000*(tmp286_+tmp286_+tmp287_+tmp287_+tmp288_+tmp288_))/tmp184_))/tmp245_)*(tmp198_)+((((tmp291_)*(tmp98_)+tmp272_*(tmp115_)+(tmp294_)*(tmp44_)+tmp256_*(tmp118_)+(tmp297_)*(tmp57_)+tmp261_*(tmp121_))*(tmp197_)-(tmp192_)*((tmp291_)*(tmp71_)+(tmp266_)*(tmp115_)+(tmp294_)*(tmp100_)+(tmp276_)*(tmp118_)+(tmp297_)*(tmp103_)+(tmp284_)*(tmp121_)))/tmp255_)*(tmp208_);
  mCompDer[0][3] = ((((0.500000*(tmp308_+tmp308_+tmp323_+tmp323_+tmp327_+tmp327_))/tmp178_)*tmp184_)/tmp245_)*(tmp198_)+(((tmp329_*(tmp98_)+tmp330_*(tmp44_)+(tmp333_)*(tmp57_))*(tmp197_)-(tmp192_)*(tmp329_*(tmp71_)+tmp307_*(tmp115_)+tmp330_*(tmp100_)+tmp322_*(tmp118_)+(tmp333_)*(tmp103_)+(tmp326_)*(tmp121_)))/tmp255_)*(tmp208_);
  mCompDer[0][4] = ((((0.500000*(tmp353_+tmp353_+tmp365_+tmp365_+tmp369_+tmp369_))/tmp178_)*tmp184_)/tmp245_)*(tmp198_)+((((tmp372_)*(tmp98_)+(tmp375_)*(tmp44_)+(tmp378_)*(tmp57_))*(tmp197_)-(tmp192_)*((tmp372_)*(tmp71_)+(tmp352_)*(tmp115_)+(tmp375_)*(tmp100_)+(tmp364_)*(tmp118_)+(tmp378_)*(tmp103_)+(tmp368_)*(tmp121_)))/tmp255_)*(tmp208_);
  mCompDer[0][5] = ((((0.500000*(tmp396_+tmp396_+tmp408_+tmp408_+tmp412_+tmp412_))/tmp178_)*tmp184_)/tmp245_)*(tmp198_)+((((tmp415_)*(tmp98_)+(tmp418_)*(tmp44_)+(tmp421_)*(tmp57_))*(tmp197_)-(tmp192_)*((tmp415_)*(tmp71_)+(tmp395_)*(tmp115_)+(tmp418_)*(tmp100_)+(tmp407_)*(tmp118_)+(tmp421_)*(tmp103_)+(tmp411_)*(tmp121_)))/tmp255_)*(tmp208_);
  mCompDer[0][6] = (((tmp423_*(tmp44_)+tmp424_*(tmp57_))*(tmp197_)-(tmp192_)*(tmp423_*(tmp100_)+tmp424_*(tmp103_)))/tmp255_)*(tmp208_);
  mCompDer[0][7] = (((tmp422_*(tmp98_)+tmp426_*(tmp57_))*(tmp197_)-(tmp192_)*(tmp422_*(tmp71_)+tmp426_*(tmp103_)))/tmp255_)*(tmp208_);
  mCompDer[0][8] = (((tmp427_*(tmp98_)+tmp425_*(tmp44_))*(tmp197_)-(tmp192_)*(tmp427_*(tmp71_)+tmp425_*(tmp100_)))/tmp255_)*(tmp208_);
  mCompDer[0][9] = ((((0.500000*(tmp437_+tmp437_+tmp453_+tmp453_+tmp457_+tmp457_))/tmp178_)*tmp184_-tmp178_*((0.500000*(tmp458_+tmp458_+tmp459_+tmp459_))/tmp184_))/tmp245_)*(tmp198_)+((((tmp450_)*(tmp115_)+(tmp435_)*(tmp118_))*(tmp197_)-(tmp192_)*(tmp436_*(tmp115_)+tmp452_*(tmp118_)+(tmp456_)*(tmp121_)))/tmp255_)*(tmp208_);
  mCompDer[0][10] = ((((0.500000*(tmp479_+tmp479_+tmp491_+tmp491_+tmp495_+tmp495_))/tmp178_)*tmp184_-tmp178_*((0.500000*(tmp496_+tmp496_+tmp497_+tmp497_+tmp498_+tmp498_))/tmp184_))/tmp245_)*(tmp198_)+((((tmp488_)*(tmp115_)+(tmp469_)*(tmp118_)+(tmp476_)*(tmp121_))*(tmp197_)-(tmp192_)*((tmp478_)*(tmp115_)+(tmp490_)*(tmp118_)+(tmp494_)*(tmp121_)))/tmp255_)*(tmp208_);
  mCompDer[0][11] = ((((0.500000*(tmp516_+tmp516_+tmp528_+tmp528_+tmp532_+tmp532_))/tmp178_)*tmp184_-tmp178_*((0.500000*(tmp533_+tmp533_+tmp534_+tmp534_+tmp535_+tmp535_))/tmp184_))/tmp245_)*(tmp198_)+((((tmp525_)*(tmp115_)+(tmp508_)*(tmp118_)+(tmp513_)*(tmp121_))*(tmp197_)-(tmp192_)*((tmp515_)*(tmp115_)+(tmp527_)*(tmp118_)+(tmp531_)*(tmp121_)))/tmp255_)*(tmp208_);
  mCompDer[0][12] = (((tmp536_*(tmp44_)+(tmp69_)*(tmp57_))*(tmp197_)-(tmp192_)*(tmp536_*(tmp100_)+(tmp69_)*(tmp103_)))/tmp255_)*(tmp208_);
  mCompDer[0][13] = ((((tmp50_)*(tmp98_)+tmp537_*(tmp57_))*(tmp197_)-(tmp192_)*((tmp50_)*(tmp71_)+tmp537_*(tmp103_)))/tmp255_)*(tmp208_);
  mCompDer[0][14] = (((tmp538_*(tmp98_)+(tmp86_)*(tmp44_))*(tmp197_)-(tmp192_)*(tmp538_*(tmp71_)+(tmp86_)*(tmp100_)))/tmp255_)*(tmp208_);
}


void cEqResiduIm2NoDistId::ComputeValDerivHessian()
{
  ELISE_ASSERT(false,"Foncteur cEqResiduIm2NoDistId Has no Der Sec");
}

void cEqResiduIm2NoDistId::SetXL1(double aVal){ mLocXL1 = aVal;}
void cEqResiduIm2NoDistId::SetXL2(double aVal){ mLocXL2 = aVal;}
void cEqResiduIm2NoDistId::SetYL1(double aVal){ mLocYL1 = aVal;}
void cEqResiduIm2NoDistId::SetYL2(double aVal){ mLocYL2 = aVal;}



double * cEqResiduIm2NoDistId::AdrVarLocFromString(const std::string & aName)
{
   if (aName == "XL1") return & mLocXL1;
   if (aName == "XL2") return & mLocXL2;
   if (aName == "YL1") return & mLocYL1;
   if (aName == "YL2") return & mLocYL2;
   return 0;
}


cElCompiledFonc::cAutoAddEntry cEqResiduIm2NoDistId::mTheAuto("cEqResiduIm2NoDistId",cEqResiduIm2NoDistId::Alloc);


cElCompiledFonc *  cEqResiduIm2NoDistId::Alloc()
{  return new cEqResiduIm2NoDistId();
}


