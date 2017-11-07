#include "include/MMVII_all.h"

#include <algorithm>
#include <tuple>
#include <typeinfo>
#include <forward_list>
#include <unordered_map>
#include <functional>


#include <boost/config.hpp>
#include <boost/array.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include <cstdio> // remove
#include <boost/config.hpp>
#if defined(BOOST_NO_STDC_NAMESPACE)
namespace std{ 
    using ::remove;
}
#endif

#include <boost/archive/tmpdir.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <list>


#include <boost/config.hpp>
#include <boost/serialization/list.hpp>
#include <boost/optional.hpp>
#include <boost/serialization/optional.hpp>

/*
#include <boost/serialization/collections_save_imp.hpp>
#include <boost/serialization/collections_load_imp.hpp>
#include <boost/serialization/split_free.hpp>
*/



//#include <Eigen/Dense>

namespace MMVII
{

template <class Type> class cMyOpt
{
    public :
      cMyOpt(const Type & aVal) : mVal (aVal) {}
      Type mVal;
    
};

class cMyBoostXmlIArch : public  boost::archive::xml_iarchive
{
     public :
          cMyBoostXmlIArch(std::ifstream & ifs) :
                boost::archive::xml_iarchive (ifs)
          {
              MMVII_INTERNAL_ASSERT_always(mIFS==0,"Nested call to cMyBoostXmlIArch::cMyBoostXmlIArch");
              mIFS = &ifs;
          }

          ~cMyBoostXmlIArch() 
          {
              MMVII_INTERNAL_ASSERT_always(mIFS!=0,"Incoherent call to cMyBoostXmlIArch::cMyBoostXmlIArch");
              mIFS = 0;
          }

          static std::ifstream * mIFS;

};

std::ifstream  * cMyBoostXmlIArch::mIFS = 0;

template<class Archive,class Type>
void serialize(Archive & ar,  cMyOpt<Type> & anE, const unsigned int version)
{
/*
    std::ifstream * ifs = cMyBoostXmlIArch::mIFS ;
    if (ifs)
    {
       std::cout << "cMyBoostXmlIArch " << ifs << "\n";

while(1)
{
       int aC = ifs->get();

       std::cout << "Got A Tag " << aC << " <" << (aC=='<') << "\n";
       getchar();
}
    }
 boost::serialization::make_nvp
*/
// std::string #
 std::cout << "HHHHhhhhhhhhhhhhhhhhhhh "  << BOOST_PP_STRINGIZE(anE.mVal) << "\n";
 // boost::serialization::make_nvp("x",aP.x())
    // ar & BOOST_SERIALIZATION_NVP(anE.mVal) ;
 
    ar & boost::serialization::make_nvp(BOOST_PP_STRINGIZE(anE.mVal), anE.mVal) ;

}


template<class Type>
void serialize(cMyBoostXmlIArch & ar,  boost::optional<Type> & anE, const unsigned int version)
{
     std::cout << "Iiiiiiiiiiiiiiiiii\n"; 
     serialize((boost::archive::xml_iarchive&)ar,anE,version);
}

class cEwelina 
{
	friend std::ostream & operator<<(std::ostream &os, const cEwelina &aE);

	public :
		cEwelina(const int &at,const  std::string& bt) : mLI{1,2,3} , mOI(56) {a=at; b=bt;}
		int a; 
		std::string b;
                std::list<int> mLI;
                boost::optional<double> mD;
                cMyOpt<int>             mOI;

/*
		template<class Archive>
		void serialize(Archive & ar, const unsigned int version)
		{ ar & BOOST_SERIALIZATION_NVP (a)
             	& BOOST_SERIALIZATION_NVP (b); };
*/

	private:
	    	// friend class boost::serialization::access;
};

template<class Archive>
void serialize(Archive & ar, cEwelina & anE, const unsigned int version)
{
    ar & BOOST_SERIALIZATION_NVP(anE.a) & BOOST_SERIALIZATION_NVP(anE.b) & BOOST_SERIALIZATION_NVP(anE.mLI)
       & BOOST_SERIALIZATION_NVP(anE.mD)
       & BOOST_SERIALIZATION_NVP(anE.mOI)
       ;
}



/*************************************************************/
/*                                                           */
/*            cAppli_MMVII_TestBoostSerial                   */
/*                                                           */
/*************************************************************/
template<class Archive>
void serialize(Archive & ar, cPt2dr & aP, const unsigned int version)
{
    ar &     boost::serialization::make_nvp("x",aP.x()) &    boost::serialization::make_nvp("y",aP.y());
    // ar & aP.y();
}


void TestBoostSerial()
{

 // create class instance
    std::ofstream ofs("filename");
    ofs.precision(6);
    ofs << std::setprecision(6);
    // const 
    cPt2dr aP(1,2);

    // save data to archive
    {
        boost::archive::text_oarchive oa(ofs);
        // write class instance to archive
        oa << aP;
        oa << aP;
    	// archive and stream closed when destructors are called
    }

    // ... some time later restore the class instance to its orginal state
    cPt2dr aNewP(0,0);
    {
        // create and open an archive for input
        std::ifstream ifs("filename");
        boost::archive::text_iarchive ia(ifs);
        /// cMyBoostXmlIArch ia(ifs);
        // read class state from archive
        ia >> aNewP;
        ia >> aNewP;
        // archive and stream closed when destructors are called
    }
    std::cout  << " AAATestBoostSerial " << aNewP.x() << " " <<  aNewP.y() << "\n";

if (1)
{
    int i=3;
    std::string j="eeee";
    const cEwelina aER(i,j);
    std::ofstream xml_ofs("filename.xml");
    boost::archive::xml_oarchive oa(xml_ofs);
    oa << BOOST_SERIALIZATION_NVP(aER);
}
    // oa << BOOST_SERIALIZATION_NVP(aNewP);

    cEwelina anE2(22,"33");
    std::ifstream ifs("filename2.xml");
    // boost::archive::xml_iarchive ia(ifs);
    cMyBoostXmlIArch  ia(ifs);
    ia >> BOOST_SERIALIZATION_NVP(anE2);
     
}

class cAppli_MMVII_TestBoostSerial : public cMMVII_Appli
{
     public :
        cAppli_MMVII_TestBoostSerial(int argc,char** argv) ;
        int Exe();
};

cAppli_MMVII_TestBoostSerial::cAppli_MMVII_TestBoostSerial (int argc,char **argv) :
  cMMVII_Appli (argc, argv)
{
  InitParam(mArgObl,mArgFac);
}

int cAppli_MMVII_TestBoostSerial::Exe()
{
    TestBoostSerial();

    return EXIT_SUCCESS;
}

tMMVII_UnikPApli Alloc_MMVII_TestBoostSerial(int argc,char ** argv)
{
   return tMMVII_UnikPApli(new cAppli_MMVII_TestBoostSerial(argc,argv));
}


cSpecMMVII_Appli  TheSpec_TestBoostSerial
(
     "TBS",
      Alloc_MMVII_TestBoostSerial,
      "This command execute some experiments en boost serrialization",
      {eApF::Test},
      {eApDT::None},
      {eApDT::Console}
);



/*
*/




};
