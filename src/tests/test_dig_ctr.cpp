#include "test_dig_ctr.h"

void test_dig_ctr::write( int address, int body ) {

  haddr.write( address );
  hwrite.write( 1 );
  wait( );
  hwdata.write( body );
  wait( );
}

void test_dig_ctr::read( int address, int body ) {

  haddr.write( address );
  hwrite.write( 0 );
  wait( );
  //hrdata.write( body );
  wait( );
}

void test_dig_ctr::demo( ) {

  wait( );
  write( 0x40000ACC, 0xDEADBEEF );
  write( 0x40001CAD, 0xBEEFDEAD );
  wait( );
  read( 0x40000ACC, 0xDEADBEEF );
  read( 0x40001ACC, 0xADBEEFAA );
  read( 0x40002ACC, 0xEADBEEFD );
  wait( );

  sc_stop( );
}

