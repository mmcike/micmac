/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr


    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.

[1] M. Pierrot-Deseilligny, N. Paparoditis.
    "A multiresolution and optimization-based image matching approach:
    An application to surface reconstruction from SPOT5-HRS stereo imagery."
    In IAPRS vol XXXVI-1/W41 in ISPRS Workshop On Topographic Mapping From Space
    (With Special Emphasis on Small Satellites), Ankara, Turquie, 02-2006.

[2] M. Pierrot-Deseilligny, "MicMac, un lociel de mise en correspondance
    d'images, adapte au contexte geograhique" to appears in
    Bulletin d'information de l'Institut Geographique National, 2007.

Francais :

   MicMac est un logiciel de mise en correspondance d'image adapte
   au contexte de recherche en information geographique. Il s'appuie sur
   la bibliotheque de manipulation d'image eLiSe. Il est distibue sous la
   licences Cecill-B.  Voir en bas de fichier et  http://www.cecill.info.


English :

    MicMac is an open source software specialized in image matching
    for research in geographic information. MicMac is built on the
    eLiSe image library. MicMac is governed by the  "Cecill-B licence".
    See below and http://www.cecill.info.

Header-MicMac-eLiSe-25/06/2007*/
#include "StdAfx.h"
#include "TexturePacker/TexturePacker.h"
#include "GraphCut/QPBO-v1.4/QPBO.h"

void LoadTrScaleRotate
     (
          Tiff_Im &aTifIn,
          Tiff_Im &aTifOut,
          const Pt2di & aP1Int,
          const Pt2di & aP2Int,
          const Pt2di & aP1Out,
          double      aScale,  // Par ex 2 pour image 2 fois + petite
          int         aRot
     )
{
    // Tiff_Im aTifIn(aNameIn.c_str());
    // Tiff_Im aTifOut(aNameOut.c_str());

     int aNbCh = aTifIn.nb_chan();
     ELISE_ASSERT(aTifOut.nb_chan()==aNbCh,"LoadTrScaleRotate nb channel diff");


     Pt2dr aVIn = Pt2dr(aP2Int-aP1Int);
     Pt2di aSzOutInit = round_ni(aVIn / aScale);

     std::vector<Im2DGen *>   aVOutInit = aTifOut.VecOfIm(aSzOutInit);

     ELISE_COPY
     (
          aVOutInit[0]->all_pts(),
          StdFoncChScale(aTifIn.in_proj(),Pt2dr(aP1Int),Pt2dr(aScale,aScale)),
          StdOut(aVOutInit)
     );

     std::vector<Im2DGen *> aVOutRotate;
     for (int aK=0 ; aK<int(aVOutInit.size()) ; aK++)
          aVOutRotate.push_back(aVOutInit[aK]->ImRotate(aRot));

     Pt2di aSzOutRotat = aVOutRotate[0]->sz();

     ELISE_COPY
     (
         rectangle(aP1Out,aP1Out+aSzOutRotat),
         trans(StdInput(aVOutRotate), -aP1Out),
         aTifOut.out()
     );
}

//update index in regions list, when a triangle is removed from mesh
void updateIndex(int triIdx, std::vector < cTextRect > &regions)
{
    for (unsigned int cK=0; cK < regions.size();++cK)
    {
        vector <int> vtri = regions[cK].triangles;
        for (unsigned int dK=0; dK < vtri.size();++dK)
        {
            if (vtri[dK] > triIdx) regions[cK].triangles[dK]--;
        }
    }
}

typedef enum
{
  eBasic,
  ePack,
  eLastTM
} eTequilaMode;

typedef enum
{
    eAngle,
    eStretch,
    eLastTC
} eTequilaCrit;

std::string eToString(const eTequilaMode & aVal)
{
   if (aVal==eBasic)
      return  "eBasic";
   if (aVal==ePack)
      return  "ePack";
 std::cout << "Enum = eTequilaMode\n";
   ELISE_ASSERT(false,"Bad Value in eToString for enum value ");
   return "";
}

std::string eToString(const eTequilaCrit & aVal)
{
   if (aVal==eAngle)
      return  "eAngle";
   if (aVal==eStretch)
      return  "eStretch";
 std::cout << "Enum = eTequilaCrit\n";
   ELISE_ASSERT(false,"Bad Value in eToString for enum value ");
   return "";
}

int Tequila_main(int argc,char ** argv)
{
    std::string aDir, aPat, aFullName, aOri, aPly, aOut, aTextOut;
    int aTextMaxSize = 4096;
    int aZBuffSSEch = 2;
    int aJPGcomp = 70;
    double aAngleMin = 90.f;
    bool aBin = true;
    std::string aMode = "Pack";
    std::string aCrit = "Angle";

    bool debug = false;
    float defValZBuf = 1e9;

    ElInitArgMain
            (
                argc,argv,
                LArgMain()  << EAMC(aFullName,"Full Name (Dir+Pat)",eSAM_IsPatFile)
                            << EAMC(aOri,"Orientation path",eSAM_IsExistDirOri)
                            << EAMC(aPly,"Ply file", eSAM_IsExistFile),
                LArgMain()  << EAM(aOut,"Out",true,"Textured mesh name (def=plyName+ _textured.ply)")
                            << EAM(aBin,"Bin",true,"Write binary ply (def=true)")
                            << EAM(aTextOut,"Texture",true,"Texture name (def=plyName + _UVtexture.jpg)")
                            << EAM(aTextMaxSize,"Sz",true,"Texture max size (def=4096)")
                            << EAM(aZBuffSSEch,"Scale", true, "Z-buffer downscale factor (def=2)",eSAM_InternalUse)
                            << EAM(aJPGcomp, "QUAL", true, "jpeg compression quality (def=70)")
                            << EAM(aAngleMin, "Angle", true, "Threshold angle, in degree, between triangle normal and image viewing direction (def=90)")
                            << EAM(aMode,"Mode", true, "Mode (def = Pack)", eSAM_None, ListOfVal(eLastTM))
                            << EAM(aCrit,"Crit", true, "Texture choosing criterion (def = Angle)", eSAM_None, ListOfVal(eLastTC))
             );

    if (MMVisualMode) return EXIT_SUCCESS;

    SplitDirAndFile(aDir,aPat,aFullName);

    if (!EAMIsInit(&aOut)) aOut = StdPrefix(aPly) + "_textured.ply";
    if (!EAMIsInit(&aTextOut)) aTextOut = StdPrefix(aPly) + "_UVtexture.tif";

    std::string textureName = StdPrefix(aTextOut) + ".jpg ";
    std::stringstream st;
    st << aJPGcomp;

    cInterfChantierNameManipulateur * aICNM = cInterfChantierNameManipulateur::BasicAlloc(aDir);
    std::list<std::string>  aLS = aICNM->StdGetListOfFile(aPat);

    StdCorrecNameOrient(aOri,aDir);

    float threshold = 0.f;

    if (aCrit == "Angle") threshold = -cos(PI*aAngleMin/180.f); //angle min = cos(180 - 60) = -0.5
    else if (aCrit == "Stretch") threshold = 1e30;
    //cout << "threshold=" << threshold << endl;

    std::vector<CamStenope*> ListCam;

    cout << endl;
    for (std::list<std::string>::const_iterator itS=aLS.begin(); itS!=aLS.end() ; itS++)
    {
        std::string NOri=aICNM->Assoc1To1("NKS-Assoc-Im2Orient@-"+aOri,*itS,true);

        ListCam.push_back(CamOrientGenFromFile(NOri,aICNM));

        cout <<"Image "<<*itS<<", with ori : "<< NOri <<endl;
    }

    cout<<endl;
    cout<<"**************************Reading ply file***************************"<<endl;
    cout<<endl;

    cMesh myMesh(aPly, threshold, aMode=="Pack");

    const int nFaces = myMesh.getFacesNumber();
    printf("Vertex number : %d - faces number : %d - edges number : %d\n\n", myMesh.getVertexNumber(), nFaces, myMesh.getEdgesNumber());

    cout<<"*************************Computing Z-Buffer**************************"<< endl;
    cout<< endl;

    vector <cZBuf> aZBuffers;

    std::list<std::string>::const_iterator itS=aLS.begin();
    const int nCam = ListCam.size();
    for(int aK=0 ; aK<nCam; aK++, itS++)
    {
        CamStenope* Cam = ListCam[aK];
        cout << "Z-buffer " << aK+1 << "/" << ListCam.size() << endl;

        cZBuf aZBuffer(Cam->Sz(), defValZBuf, aZBuffSSEch);

        aZBuffer.BasculerUnMaillage(myMesh, *Cam);

        aZBuffers.push_back(aZBuffer);

        set <unsigned int> *vTri = aZBuffer.getVisibleTrianglesIndexes();

        if (debug)
        {
            std::stringstream ss  ;
            ss << aK;

            aZBuffer.write(StdPrefix(*itS) + "_zbuf" + ss.str() + ".tif");

            aZBuffer.writeImLabel(StdPrefix(*itS) + "_label" + ss.str() + ".tif");

            myMesh.Export(StdPrefix(*itS) + "export" + ss.str() + ".ply", *vTri);
        }

        set <unsigned int>::const_iterator it = vTri->begin();
        for (;it!=vTri->end();++it)
        {
            cTriangle * Triangle = myMesh.getTriangle(*it);

            vector <Pt3dr> Vertex;
            Triangle->getVertexes(Vertex);

            Pt2dr D = Cam->R3toF2(Vertex[0]);             //projection des sommets du triangle
            Pt2dr E = Cam->R3toF2(Vertex[1]);
            Pt2dr F = Cam->R3toF2(Vertex[2]);

            if (Cam->IsInZoneUtile(D) && Cam->IsInZoneUtile(E) && Cam->IsInZoneUtile(F))
            {
                double criter = threshold;

                if (aCrit == "Stretch")
                {
                    Pt2dr v1(Vertex[1].x - Vertex[0].x, Vertex[1].y - Vertex[0].y);
                    Pt2dr v2(Vertex[2].x - Vertex[0].x, Vertex[2].y - Vertex[0].y);

                    double norme = ElMax(euclid(v1), euclid(v2));

                    Pt2dr v1n = v1 / norme;
                    Pt2dr v2n = v2 / norme;

                    //coordonnees du point C dans le plan du triangle (repere orthonorm� defini par Ox = BA )
                    double x = scal(v1n, v2n);
                    double y = sin(acos(x));

                    //AB = B(1,0) - A(0,0)
                    //AC = C(x,y) - A(0,0)

                    Pt2dr DE (E - D);
                    Pt2dr DF (F - D);

                    double det = DE.x * DF.y - DF.x*DE.y;

                    double ni00 =  DF.y / det;
                    double ni10 = -DF.x / det;
                    double ni01 = -DE.y / det;
                    double ni11 =  DE.x / det;

                    //Coefficients de l'affinite
                    Pt2dr aU (ni00 , x*ni00 + y*ni10);
                    Pt2dr aV (ni01 , x*ni01 + y*ni11);

                    double aU2 = square_euclid(aU);
                    double aV2 = square_euclid(aV);
                    double aUV = scal(aU,aV);

                    //le coef d'etirement est sqrt((aU2+aV2+sqrt(ElSquare(aU2-aV2)+4*ElSquare(aUV)))/2)
                    // mais on supprime les calculs superflus => sqrt et /2 strictement monotones

                    criter = aU2+aV2+sqrt(ElSquare(aU2-aV2)+4*ElSquare(aUV));

                    //cout << "criter = " << criter << endl;
                }
                else if (aCrit == "Angle")
                {
                    criter = scal(Triangle->getNormale(true), Cam->DirK()); //Norme de DirK=1
                }

                if((criter < Triangle->getCriter()))
                {
                    Triangle->setCriter(criter);
                    Triangle->setTextureImgIndex(aK);
                }
            }
        }
    }

    std::set <int> index; //liste des index de cameras utilisees

    int valDef = cTriangle::getDefTextureImgIndex();

    for (int aK=0;aK<nFaces; aK++)
    {
        int imgIdx = myMesh.getTriangle(aK)->getTextureImgIndex();
        if(imgIdx != valDef) index.insert(imgIdx);
    }

    cout << endl;
    cout << "Selected images / total : " << index.size() << " / " << aLS.size() << endl;

    cout << endl;
    cout <<"**********************Filtering border faces*************************"<<endl;
    cout << endl;

    myMesh.clean();

    printf("\nVertex number : %d - faces number : %d \n", myMesh.getVertexNumber(), myMesh.getFacesNumber());

    Pt2di aSzMax;
    vector <Tiff_Im> aVT;     //Vecteur contenant les images
    int aNbCh = 0;

    vector <Im2D_REAL4> final_ZBufIm;
    cInterpolateurIm2D<REAL4> * pInterp = new cInterpolBilineaire<REAL4>;
    std::set <int>::const_iterator it = index.begin();
    for (; it != index.end();it++)
    {
        int bK=0;
        for (std::list<std::string>::const_iterator itS=aLS.begin(); itS!=aLS.end() ; itS++, bK++)
        {
            if (*it == bK)
            {
                aVT.push_back(Tiff_Im::StdConvGen(aDir+*itS,-1,false,true));

                if (aZBuffSSEch > 1)
                {
                    Pt2di sz = aVT.back().sz();
                    Im2D_REAL4 * pIm = new Im2D_REAL4(sz.x,sz.y,defValZBuf);
                    Im2D_REAL4 * pZBuf = aZBuffers[*it].get();
                    float **pImData = pIm->data();

                    for (int cK=0; cK < sz.x; cK++)
                        for(int dK=0; dK < sz.y; dK++)
                            pImData[dK][cK] = pZBuf->Get(Pt2dr(cK, dK) / aZBuffSSEch, *pInterp, defValZBuf);

                    final_ZBufIm.push_back(*pIm);
                }
                else
                    final_ZBufIm.push_back(*(aZBuffers[*it].get()));

                aSzMax.SetSup(aVT.back().sz());
                aNbCh = ElMax(aNbCh,aVT.back().nb_chan());
                break;
            }
        }
    }

    if (aMode == "Pack")
    {
        cout << endl;
        cout <<"**********************Getting adjacent triangles*********************"<<endl;
        cout << endl;

        std::vector < cTextRect > regions = myMesh.getRegions();
        cout << "nb regions = " << regions.size() << endl;

        TEXTURE_PACKER::TexturePacker *tp = TEXTURE_PACKER::createTexturePacker();

        for (unsigned int aK=0; aK < regions.size();++aK)
        {
            //cout << "region " << aK << " nb triangles = " << regions[aK].triangles.size() << endl;
            //Calcul de la zone correspondante dans l'image

            int triIdx = regions[aK].triangles[0];
            cTriangle * Tri = myMesh.getTriangle(triIdx);
            int imgIdx = Tri->getTextureImgIndex();

            //cout << "Image index " << imgIdx << endl;

            Pt2dr _min(DBL_MAX, DBL_MAX);
            Pt2dr _max;

            for (unsigned int bK=0; bK < regions[aK].triangles.size(); ++bK)
            {
                int triIdx = regions[aK].triangles[bK];
                cTriangle * Triangle = myMesh.getTriangle(triIdx);

                ElCamera * Cam = ListCam[imgIdx];

                vector <Pt3dr> Vertex;
                Triangle->getVertexes(Vertex);

                Pt2dr Pt1 = Cam->R3toF2(Vertex[0]);             //projection des sommets du triangle
                Pt2dr Pt2 = Cam->R3toF2(Vertex[1]);
                Pt2dr Pt3 = Cam->R3toF2(Vertex[2]);

                if (Cam->IsInZoneUtile(Pt1) || Cam->IsInZoneUtile(Pt2) || Cam->IsInZoneUtile(Pt3))
                {
                    _min = Inf(Pt1, Inf(Pt2, Inf(Pt3, _min)));
                    _max = Sup(Pt1, Sup(Pt2, Sup(Pt3, _max)));
                }
            }

            if (_min != Pt2dr(DBL_MAX, DBL_MAX)) //TODO: gerer les triangles de bord
            {
                //cout << "aK= " << aK << " img= " << imgIdx << " min, max = " << _min.x << ", " << _min.y << "  " <<  _max.x << ", " << _max.y << endl;
                regions[aK].setRect(imgIdx, round_down(_min), round_up(_max));
            }
            else
            {
                //cout << "removing region " << aK << endl;
                regions.erase(std::remove(regions.begin(), regions.end(), regions[aK]), regions.end());
                aK--;
            }
        }

        cout << endl;
        cout <<"***************************Packing textures**************************"<<endl;
        cout << endl;

        tp->setTextureCount(regions.size());

        const int nRegions = regions.size();
        for (int aK=0; aK < nRegions; ++aK)
        {
            Pt2di sz = regions[aK].size();
            //cout << "aK= " << aK << " width - height " << sz.x << " " <<  sz.y << endl;
            tp->addTexture(sz.x, sz.y);
        }

        int width, height;
        int unused_area = tp->packTextures(width, height, false, false);

        cout << "Packed width-height " << width << " " << height << endl;
        printf("Unused_area : %d pixels = %1.2f %%\n", unused_area, (float) 100.f * unused_area / (width*height));

        float Scale = (float) aTextMaxSize / ElMax(width, height) ;

        if (Scale > 1.f) Scale = 1.f;

        printf("Scaling factor = %1.2f\n", Scale);
        if (Scale < 0.2f) cout << "Warning: scaling factor too low, try using higher texture size (Parameter Sz)" << endl;

        int final_width  = round_up(width * Scale);
        int final_height = round_up(height * Scale);

        cout << "Final width-height " << final_width << " " << final_height << endl;

        cout << endl;
        cout <<"***************************Writing texture***************************"<<endl;
        cout << endl;

        Tiff_Im  nFileRes
                (
                    aTextOut.c_str(),
                    Pt2di( final_width, final_height ),
                    GenIm::u_int1,
                    Tiff_Im::No_Compr,
                    Tiff_Im::RGB
                );

        for (int aK=0; aK< nRegions; aK++)
        {
            int x, y, w, h;
            bool rotated = tp->getTextureLocation(aK, x, y, w, h);

            //cout << "Texture " << aK << " at position " << x << ", " << y << " and rotated " << rotated << " width, height = " << w << " " << h << endl;

            int x_scaled = round_ni(x * Scale);
            int y_scaled = round_ni(y * Scale);

            //cout << "image position  scaled = " << x_scaled << " " << y_scaled << endl;

            int w_scaled = round_ni(w * Scale);
            int h_scaled = round_ni(h * Scale);

            //cout << "image dimension scaled = " << w_scaled << " " << h_scaled << endl;

            int p0x_scaled = round_ni(regions[aK].p0.x * Scale);
            int p0y_scaled = round_ni(regions[aK].p0.y * Scale);

            Pt2di p0_scaled(p0x_scaled, p0y_scaled);

            Pt2di xy_scaled(x_scaled, y_scaled);
            Pt2di wh_scaled(w_scaled, h_scaled);

            Pt2di tr = p0_scaled - xy_scaled;

            regions[aK].setTransfo(tr, rotated);

            int imgIdx = regions[aK].imgIdx;
            //cout << "position dans l'image " << imgIdx << " = " << regions[aK].p0.x << " " << regions[aK].p0.y << endl;

            Fonc_Num aF0 = aVT[imgIdx].in_proj() * (final_ZBufIm[imgIdx].in_proj()!=defValZBuf);

            if (rotated)
            {
                std::vector<Im2DGen *> aVOutInit = nFileRes.VecOfIm(Pt2di(h_scaled, w_scaled));

                ELISE_COPY
                (
                     aVOutInit[0]->all_pts(),
                     StdFoncChScale(aF0,Pt2dr(regions[aK].p0),Pt2dr(1.f/Scale,1.f/Scale)),
                     StdOut(aVOutInit)
                );

                std::vector<Im2DGen *>   aVOutRotate;
                for (int aK=0 ; aK<int(aVOutInit.size()) ; aK++)
                     aVOutRotate.push_back(aVOutInit[aK]->ImRotate(3));

                ELISE_COPY
                (
                    rectangle(xy_scaled, xy_scaled + wh_scaled),
                    trans(StdInput(aVOutRotate), -xy_scaled),
                    nFileRes.out()
                );
            }
            else
            {
                Fonc_Num aF = aF0;
                while (aF.dimf_out() < aNbCh)
                    aF = Virgule(aF0,aF);
                aF = StdFoncChScale(aF,Pt2dr(), Pt2dr(1.f/Scale,1.f/Scale));

                ELISE_COPY
                (
                    rectangle(xy_scaled, xy_scaled + wh_scaled),
                    trans(aF, tr),
                    nFileRes.out()
                );
            }
        }

        releaseTexturePacker(tp);

        cout << endl;
        cout <<"********************Computing texture coordinates********************"<<endl;
        cout << endl;

        for (int aK=0; aK < nRegions; ++aK)
        {
            Pt2di PtTemp = -regions[aK].translation;
            bool rotat = regions[aK].rotation;

            Pt2dr coin(regions[aK].p0);
            //cout << "aK= " << aK << " coin = " << coin << endl;

            float tx = round_ni(coin.x * Scale) + PtTemp.x;
            float ty = round_ni(coin.y * Scale) + PtTemp.y + (float) regions[aK].width() * Scale;

            //cout << "ty = " << ty << endl;

            //cout << "nb Triangles = " << regions[aK].size() << endl;

            const int nTriangles = regions[aK].triangles.size();
            for (int bK=0; bK < nTriangles;++bK)
            {
                int triIdx = regions[aK].triangles[bK];

                cTriangle *Triangle = myMesh.getTriangle(triIdx);

                int idx = Triangle->getTextureImgIndex();                //Liaison avec l'image correspondante

                //cout << "image pour le triangle " << i << " = " << idx << endl;

                if (idx != valDef)
                {
                    CamStenope *Cam = ListCam[idx];

                    vector <Pt3dr> Vertex;
                    Triangle->getVertexes(Vertex);

                    Pt2dr Pt1 = Cam->R3toF2(Vertex[0]);             //projection des sommets du triangle
                    Pt2dr Pt2 = Cam->R3toF2(Vertex[1]);
                    Pt2dr Pt3 = Cam->R3toF2(Vertex[2]);

                    if (Cam->IsInZoneUtile(Pt1) || Cam->IsInZoneUtile(Pt2) || Cam->IsInZoneUtile(Pt3))
                    {
                        Pt2dr P1, P2, P3;

                        if(rotat)
                        {
                            Pt2dr v1 = (Pt1 - coin)*Scale;
                            Pt2dr v2 = (Pt2 - coin)*Scale;
                            Pt2dr v3 = (Pt3 - coin)*Scale;

                            P1.x = (tx + v1.y) / final_width;
                            P2.x = (tx + v2.y) / final_width;
                            P3.x = (tx + v3.y) / final_width;

                            P1.y = 1.f - (ty - v1.x) / final_height;
                            P2.y = 1.f - (ty - v2.x) / final_height;
                            P3.y = 1.f - (ty - v3.x) / final_height;

                           /* if (bK== 0)
                            {
                                cout << "Pt1 = " << Pt1 << endl;
                                cout << "Pt2 = " << Pt2 << endl;
                                cout << "Pt3 = " << Pt3 << endl;

                                cout << "v1 = " << v1 << endl;
                                cout << "v2 = " << v2 << endl;
                                cout << "v3 = " << v3 << endl;

                                cout << "p1x = " << v1.y + PtTemp.x << endl;
                                cout << "p2x = " << v2.y + PtTemp.x << endl;
                                cout << "p3x = " << v3.y + PtTemp.x << endl;

                                cout << "p1y = " << y1 << endl;
                                cout << "p2y = " << y2 << endl;
                                cout << "p3y = " << y3 << endl;

                                cout << "rwidth " << rwidth << endl;
                            }*/
                        }
                        else
                        {
                            P1.x = (Pt1.x*Scale+PtTemp.x) / final_width;
                            P2.x = (Pt2.x*Scale+PtTemp.x) / final_width;
                            P3.x = (Pt3.x*Scale+PtTemp.x) / final_width;

                            P1.y = 1.f - (Pt1.y*Scale+PtTemp.y) / final_height;
                            P2.y = 1.f - (Pt2.y*Scale+PtTemp.y) / final_height;
                            P3.y = 1.f - (Pt3.y*Scale+PtTemp.y) / final_height;
                        }

                        if ((P1.x >=0.f) && (P1.x <= 1.f) && (P2.x >=0.f) && (P2.y <= 1.f) && (P3.x >=0.f) && (P3.y <= 1.f))
                            Triangle->setTextureCoordinates(P1, P2, P3);
                        else
                        {
                            myMesh.removeTriangle(*Triangle);
                            updateIndex(triIdx, regions);
                        }
                    }
                    else
                    {
                        myMesh.removeTriangle(*Triangle);
                        updateIndex(triIdx, regions);
                    }
                }
            }
        }
    }
    else if (aMode == "Basic")
    {
        vector <Pt2dr> TabCoor;

        int aNbLine = round_up(sqrt(double(aVT.size())));
        int aNbCol = round_up(aVT.size()/double(aNbLine));

        cout << aNbLine << " rows and "  << aNbCol <<" columns texture, with "<< aVT.size() <<" images. "<< endl;
        cout << endl;

        int full_width  = aSzMax.x * aNbCol;
        int full_height = aSzMax.y * aNbLine;

        float Scale = (float) aTextMaxSize / ElMax(full_width, full_height) ;

        if (Scale > 1.f) Scale = 1.f;

        cout << "Scaling factor = " << Scale << endl;

        int final_width  = round_up(full_width * Scale);
        int final_height = round_up(full_height * Scale);

        Pt2di aSz ( final_width, final_height );

        //cout << "SZ = " << aSz << " :: " << aNbCol << " X " << aNbLine  << "\n";

        Tiff_Im::PH_INTER_TYPE aPhI = aVT[0].phot_interp();
        if (aNbCh==3)
            aPhI = Tiff_Im::RGB;

        Tiff_Im  FileRes
                (
                    aTextOut.c_str(),
                    aSz,
                    GenIm::u_int1,
                    Tiff_Im::No_Compr,
                    aPhI
                    );

        const int nImg = aVT.size();
        for (int aK=0 ; aK< nImg ; aK++)
        {
            Pt2di ptK(aK % aNbCol, aK / aNbCol);

            //std::cout << "WRITE " << aVT[aK].name() << "\n";

            Pt2di aP0 (
                        (ptK.x*aSz.x) / aNbCol,
                        (ptK.y*aSz.y) / aNbLine
                        );

            Pt2di aP1 (
                        ((ptK.x+1)*aSz.x) / aNbCol,
                        ((ptK.y+1)*aSz.y) / aNbLine
                        );

            Fonc_Num aF0 = aVT[aK].in_proj() * (final_ZBufIm[aK].in_proj()!=defValZBuf);
            Fonc_Num aF = aF0;
            while (aF.dimf_out() < aNbCh)
                aF = Virgule(aF0,aF);
            aF = StdFoncChScale(aF,Pt2dr(-aP0.x,-aP0.y)/Scale, Pt2dr(1.f/Scale,1.f/Scale));

            ELISE_COPY
                    (
                        rectangle(aP0,aP1),
                        aF ,
                        FileRes.out()
                        );

            Pt2dr Coord = ptK.mcbyc(aVT[aK].sz())*Scale;

            TabCoor.push_back(Coord);

            /*   cout<<"Ligne : "<<ptK.y+1 << " Colonne : "<<ptK.x+1<<endl;
            cout<<"Position : "<< Coord.x <<" " << Coord.y <<endl;
            cout<<"Nombre d'images traitees : "<<aK+1<<"/"<<aVT.size()<<endl;
            cout<<endl;*/
        }

        cout << endl;
        cout <<"********************Computing texture coordinates********************"<<endl;
        cout << endl;

        //cout << "myMesh.getFacesNumber()= "<< myMesh.getFacesNumber() << endl;
        for(int i=0 ; i< myMesh.getFacesNumber() ; i++)                          //Ecriture des triangles
        {
            cTriangle * Triangle = myMesh.getTriangle(i);

            int idx = Triangle->getTextureImgIndex();                //Liaison avec l'image correspondante

            //cout << "image pour le triangle " << i << " = " << idx << endl;

            if (idx != valDef)
            {
                CamStenope * Cam = ListCam[idx];

                vector <Pt3dr> Vertex;
                Triangle->getVertexes(Vertex);

                Pt2dr Pt1 = Cam->R3toF2(Vertex[0]);             //projection des sommets du triangle
                Pt2dr Pt2 = Cam->R3toF2(Vertex[1]);
                Pt2dr Pt3 = Cam->R3toF2(Vertex[2]);

                if (Cam->IsInZoneUtile(Pt1) || Cam->IsInZoneUtile(Pt2) || Cam->IsInZoneUtile(Pt3))
                {
                    Pt2dr PtTemp = TabCoor[idx];

                    //cout << "PtTemp = " <<  PtTemp << endl;

                    Pt2dr P1, P2, P3;

                    P1.x = ((float)(Pt1.x*Scale)+PtTemp.x) / final_width;
                    P2.x = ((float)(Pt2.x*Scale)+PtTemp.x) / final_width;
                    P3.x = ((float)(Pt3.x*Scale)+PtTemp.x) / final_width;

                    P1.y = 1.f - ((float)(Pt1.y*Scale)+PtTemp.y) / final_height;
                    P2.y = 1.f - ((float)(Pt2.y*Scale)+PtTemp.y) / final_height;
                    P3.y = 1.f - ((float)(Pt3.y*Scale)+PtTemp.y) / final_height;

                    Triangle->setTextureCoordinates(P1, P2, P3);
                }
                else
                {
                    myMesh.removeTriangle(*Triangle);
                    i--;
                }
            }
        }
    }

    cout << endl;
    cout <<"**************************QPBO**************************"<<endl;
    cout << endl;

#ifdef QPBOOOOO

    if (myMesh.getFacesNumber() && myMesh.getEdgesNumber())
    {
        QPBO<float>* q = new QPBO<float>(myMesh.getFacesNumber(), myMesh.getEdgesNumber()); // max number of nodes & edges

        const int nEdges = myMesh.getEdgesNumber();
        for (int aK=0; aK < nEdges; ++aK)
        {
            cEdge *edge = myMesh.getEdge(aK);
            int n1 = edge->n1();
            int n2 = edge->n2();

            cTriangle *tri1 = myMesh.getTriangle(n1);
            cTriangle *tri2 = myMesh.getTriangle(n2);

            int curImgIdx1 = tri1->getTextureImgIndex();
            int curImgIdx2 = tri2->getTextureImgIndex();

            int newImgIdx1 = -1; //TODO
            int newImgIdx2 = -1; //TODO

            float curMean1 = tri1->meanTexture(ListCam[curImgIdx1], aVT[curImgIdx1]);
            float curMean2 = tri2->meanTexture(ListCam[curImgIdx2], aVT[curImgIdx2]);

            float newMean1 = tri1->meanTexture(ListCam[newImgIdx1], aVT[newImgIdx1]);
            float newMean2 = tri2->meanTexture(ListCam[newImgIdx2], aVT[newImgIdx2]);

            float diff11 = newMean1 - curMean1;
            float diff12 = newMean1 - curMean2;
            float diff21 = newMean2 - curMean1;
            float diff22 = newMean2 - curMean2;

            q->AddNode(2); // add two nodes

            q->AddUnaryTerm(n1, tri1->getCriter(), -10); // add term 2*x
            q->AddUnaryTerm(n2, tri2->getCriter(), 6); // add term 3*(y+1)
            q->AddPairwiseTerm(n1, n2, diff11, diff12, diff21, diff22); // add term (x+1)*(y+2)

            /*q->AddNode(2); // add two nodes

            q->AddUnaryTerm(0, 0, -10); // add term 2*x
            q->AddUnaryTerm(1, 3, 6); // add term 3*(y+1)
            q->AddPairwiseTerm(0, 1, 2, 3, 4, 6); // add term (x+1)*(y+2)

            q->Solve();
            q->ComputeWeakPersistencies();

            int x = q->GetLabel(0);
            int y = q->GetLabel(1);
            printf("Solution: x=%d, y=%d\n", x, y);*/
        }
    }
    else
    {
        std::cout << "Walou faces or walou edges" << std::endl;
    }

    //END QPBO

#endif //QPBOOOO


    cout << endl;
    cout <<"***********************Converting texture file***********************"<<endl;
    cout << endl;

    std::string aCom =  g_externalToolHandler.get( "convert" ).callName() + std::string(" -quality ") + st.str() + " "
            + aTextOut + " " + textureName;

    if (debug) cout << "COM= " << aCom << endl;

    system_call(aCom.c_str());

    aCom = std::string(SYS_RM) + " " + aTextOut;
    system_call(aCom.c_str());

    cout << endl;
    cout <<"**************************Writing ply file***************************"<<endl;
    cout << endl;

    myMesh.write(aOut, aBin, textureName);

    cout<<"********************************Done*********************************"<<endl;
    cout<< endl;

    return EXIT_SUCCESS;
}

/*Footer-MicMac-eLiSe-25/06/2007

Ce logiciel est un programme informatique servant �  la mise en
correspondances d'images pour la reconstruction du relief.

Ce logiciel est régi par la licence CeCILL-B soumise au droit français et
respectant les principes de diffusion des logiciels libres. Vous pouvez
utiliser, modifier et/ou redistribuer ce programme sous les conditions
de la licence CeCILL-B telle que diffusée par le CEA, le CNRS et l'INRIA
sur le site "http://www.cecill.info".

En contrepartie de l'accessibilité au code source et des droits de copie,
de modification et de redistribution accordés par cette licence, il n'est
offert aux utilisateurs qu'une garantie limitée.  Pour les mêmes raisons,
seule une responsabilité restreinte pèse sur l'auteur du programme,  le
titulaire des droits patrimoniaux et les concédants successifs.

A cet égard  l'attention de l'utilisateur est attirée sur les risques
associés au chargement,  �  l'utilisation,  �  la modification et/ou au
développement et �  la reproduction du logiciel par l'utilisateur étant
donné sa spécificité de logiciel libre, qui peut le rendre complexe �
manipuler et qui le réserve donc �  des développeurs et des professionnels
avertis possédant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invités �  charger  et  tester  l'adéquation  du
logiciel �  leurs besoins dans des conditions permettant d'assurer la
sécurité de leurs systèmes et ou de leurs données et, plus généralement,
�  l'utiliser et l'exploiter dans les mêmes conditions de sécurité.

Le fait que vous puissiez accéder �  cet en-tête signifie que vous avez
pris connaissance de la licence CeCILL-B, et que vous en avez accepté les
termes.
Footer-MicMac-eLiSe-25/06/2007*/
