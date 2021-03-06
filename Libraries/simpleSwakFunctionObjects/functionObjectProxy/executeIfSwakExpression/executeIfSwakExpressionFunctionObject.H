//  OF-extend Revision: $Id$
/*---------------------------------------------------------------------------*\
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
    executeIfSwakExpressionFunctionObject

Description
    This proxy-functionObject only executs its childrens if a
    swak-expression evaluates to true

SourceFiles
    executeIfSwakExpressionFunctionObject.C

\*---------------------------------------------------------------------------*/

#ifndef executeIfSwakExpressionFunctionObject_H
#define executeIfSwakExpressionFunctionObject_H

#include "conditionalFunctionObjectListProxy.H"

#include "CommonValueExpressionDriver.H"

#include "LogicalAccumulationNamedEnum.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                           Class executeIfSwakExpressionFunctionObject Declaration
\*---------------------------------------------------------------------------*/

class executeIfSwakExpressionFunctionObject
:
    public conditionalFunctionObjectListProxy
{
    // Private Member Functions

    //- Disallow default bitwise copy construct
    executeIfSwakExpressionFunctionObject(const executeIfSwakExpressionFunctionObject&);

    //- Disallow default bitwise assignment
    void operator=(const executeIfSwakExpressionFunctionObject&);

    //- the expression driver
    autoPtr<CommonValueExpressionDriver> driver_;

    //- the logical expression
    string logicalExpression_;

    void readParameters(const dictionary &);

private:
    LogicalAccumulationNamedEnum::value logicalAccumulation_;

protected:

    //- the actual conition that determines whether the FO should be executed
    virtual bool condition();

public:

    //- Runtime type information
    TypeName("executeIfSwakExpression");


    // Constructors

    //- Construct from components
    executeIfSwakExpressionFunctionObject
    (
        const word&,
        const Time&,
        const dictionary&
    );

    bool read(const dictionary& dict);

};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
