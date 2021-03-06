/*eLiSe06/05/99
  
     Copyright (C) 1999 Marc PIERROT DESEILLIGNY

   eLiSe : Elements of a Linux Image Software Environment

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

  Author: Marc PIERROT DESEILLIGNY    IGN/MATIS  
Internet: Marc.Pierrot-Deseilligny@ign.fr
   Phone: (33) 01 43 98 81 28
eLiSe06/05/99*/



#include "general/all.h"
#include "private/all.h"


int main(int,char**)
{

    Tiff_Im  Tif
    (
	 ELISE_BFI_DATA_DIR "ex.tif",
         Pt2di(100,100),
         GenIm::u_int1,
         Tiff_Im::No_Compr,
         Tiff_Im::BlackIsZero,
         L_Arg_Opt_Tiff()
           + Tiff_Im::AResol(200.0,Tiff_Im::Cm_Unit)
     );

}



