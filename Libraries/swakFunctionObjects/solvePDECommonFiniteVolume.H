/*---------------------------------------------------------------------------*\
 ##   ####  ######     |
 ##  ##     ##         | Copyright: ICE Stroemungsfoschungs GmbH
 ##  ##     ####       |
 ##  ##     ##         | http://www.ice-sf.at
 ##   ####  ######     |
-------------------------------------------------------------------------------
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright  held by original author
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is based on OpenFOAM.

    OpenFOAM is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM; if not, write to the Free Software Foundation,
    Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Class
    solvePDECommonFiniteVolume

Description
    Common functionality for functionObjects that solve PDEs - for finite volume

SourceFiles
    solvePDECommonFiniteVolume.C

Contributors/Copyright:
    2011, 2013 Bernhard F.W. Gschaider <bgschaid@ice-sf.at>

 SWAK Revision: $Id:  $ 
\*---------------------------------------------------------------------------*/

#ifndef solvePDECommonFiniteVolume_H
#define solvePDECommonFiniteVolume_H

#include "solvePDECommon.H"

namespace Foam
{

// Forward declaration of classes
class FieldValueExpressionDriver;

class solvePDECommonFiniteVolume
:
    public solvePDECommon
{
    //- Disallow default bitwise copy construct
    solvePDECommonFiniteVolume(const solvePDECommonFiniteVolume&);
    
    //- Disallow default bitwise assignment
    void operator=(const solvePDECommonFiniteVolume&);

protected:

    //- the actual field
    autoPtr<volScalarField> theField_;

    //- the driver that calculates the coefficients
    autoPtr<FieldValueExpressionDriver> driver_;

    //- write specific data
    virtual void writeData();

public:

    //- Runtime type information
    TypeName("solvePDECommonFiniteVolume");


    // Constructors
    
    //- Construct for given objectRegistry and dictionary.
    //  Allow the possibility to load fields from files
    solvePDECommonFiniteVolume
    (
        const word& name,
        const objectRegistry&,
        const dictionary&,
        const bool loadFromFiles = false
    );


    //- Destructor
    virtual ~solvePDECommonFiniteVolume();


    // Member Functions

    //- Read the forces data
    virtual void read(const dictionary&);
    
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif
