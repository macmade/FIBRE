/*******************************************************************************
 * Copyright (c) 2011, Jean-David Gadina - www.xs-labs.com
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

/* $Id $ */

/*!
 * @file        
 * @copyright   (c) 2011 - Jean-David Gadina - www.xs-labs.com
 * @abstract    
 */

#include "fibre.h"

/*!
 * @function    main
 * @abstract    Program's entry point
 * @param       argc    The number of CLI arguments
 * @param       argv    A array with the CLI arguments
 * @result      The program's exit status
 */
int main( int argc, char * argv[] )
{
    fibre_cli_args args;
    FILE         * source;
    FILE         * destination;
    
    fibre_get_cli_args( argc, argv, &args );
    
    if( args.interval == 0 || args.source == NULL || args.destination == NULL )
    {
        printf
        (
            "\n"
            "USAGE: %s [OPTIONS] SOURCE DESTINATION\n"
            "\n"
            "Options:\n"
            "\n"
            "    -i:    Byte interval (mandatory)\n"
            "\n",
            argv[ 0 ]
        );
        
        return EXIT_SUCCESS;
    }
    
    source      = fopen( args.source,      "rb" );
    destination = fopen( args.destination, "wb" );
    
    if( source == NULL )
    {
        printf( "Error: unable to open source file for reading.\n" );
        
        return EXIT_FAILURE;
    }
    
    if( destination == NULL )
    {
        printf( "Error: unable to open destination file for writing.\n" );
        
        return EXIT_FAILURE;
    }
    
    libfibre_encode( source, destination, args.interval );
    
    return EXIT_SUCCESS;
}
