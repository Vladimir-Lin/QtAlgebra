#include "qtalgebra.h"

typedef struct          {
  int32_t Type          ;
  int32_t Value         ;
  int32_t TeX           ;
  int32_t Description   ;
} AlgebraVariablePacket ;

N::Algebra::Variable:: Variable    ( void      )
                     : Element     (           )
                     , Type        ( Cpp::Void )
                     , TeX         ( ""        )
                     , Description ( ""        )
{
}

N::Algebra::Variable:: Variable    ( QString symbol      )
                     : Element     (                     )
                     , Type        ( Cpp::Symbolic       )
                     , Value       ( QVariant ( symbol ) )
                     , TeX         ( ""                  )
                     , Description ( ""                  )
{
}

N::Algebra::Variable:: Variable    ( char value         )
                     : Element     (                    )
                     , Type        ( Cpp::Char          )
                     , Value       ( QVariant ( value ) )
                     , TeX         ( ""                 )
                     , Description ( ""                 )
{
}

N::Algebra::Variable:: Variable    ( unsigned char value )
                     : Element     (                     )
                     , Type        ( Cpp::Byte           )
                     , Value       ( QVariant ( value )  )
                     , TeX         ( ""                  )
                     , Description ( ""                  )
{
}

N::Algebra::Variable:: Variable    ( short value        )
                     : Element     (                    )
                     , Type        ( Cpp::Short         )
                     , Value       ( QVariant ( value ) )
                     , TeX         ( ""                 )
                     , Description ( ""                 )
{
}

N::Algebra::Variable:: Variable    ( unsigned short value )
                     : Element     (                      )
                     , Type        ( Cpp::UShort          )
                     , Value       ( QVariant ( value )   )
                     , TeX         ( ""                   )
                     , Description ( ""                   )
{
}

N::Algebra::Variable:: Variable    ( int value          )
                     : Element     (                    )
                     , Type        ( Cpp::Integer       )
                     , Value       ( QVariant ( value ) )
                     , TeX         ( ""                 )
                     , Description ( ""                 )
{
}

N::Algebra::Variable:: Variable    ( unsigned int value )
                     : Element     (                    )
                     , Type        ( Cpp::UInt          )
                     , Value       ( QVariant ( value ) )
                     , TeX         ( ""                 )
                     , Description ( ""                 )
{
}

N::Algebra::Variable:: Variable    ( long long value    )
                     : Element     (                    )
                     , Type        ( Cpp::LongLong      )
                     , Value       ( QVariant ( value ) )
                     , TeX         ( ""                 )
                     , Description ( ""                 )
{
}

N::Algebra::Variable:: Variable    ( unsigned long long value )
                     : Element     (                          )
                     , Type        ( Cpp::ULongLong           )
                     , Value       ( QVariant ( value )       )
                     , TeX         ( ""                       )
                     , Description ( ""                       )
{
}

N::Algebra::Variable:: Variable    ( float value        )
                     : Element     (                    )
                     , Type        ( Cpp::Float         )
                     , Value       ( QVariant ( value ) )
                     , TeX         ( ""                 )
                     , Description ( ""                 )
{
}

N::Algebra::Variable:: Variable    ( double value       )
                     : Element     (                    )
                     , Type        ( Cpp::Double        )
                     , Value       ( QVariant ( value ) )
                     , TeX         ( ""                 )
                     , Description ( ""                 )
{
}

N::Algebra::Variable:: Variable    ( long double value  )
                     : Element     (                    )
                     , Type        ( Cpp::LDouble       )
                     , TeX         ( ""                 )
                     , Description ( ""                 )
{
  QByteArray B                                             ;
  B . resize ( sizeof(long double) )                       ;
  ::memcpy ( B . data ( ) , &value , sizeof(long double) ) ;
  Value = QVariant ( B )                                   ;
}

N::Algebra::Variable:: Variable    ( vlong value        )
                     : Element     (                    )
                     , Type        ( Cpp::VLong         )
                     , Value       ( QVariant ( value ) )
                     , TeX         ( ""                 )
                     , Description ( ""                 )
{
}

N::Algebra::Variable:: Variable    ( vdouble value      )
                     : Element     (                    )
                     , Type        ( Cpp::VDouble       )
                     , Value       ( QVariant ( value ) )
                     , TeX         ( ""                 )
                     , Description ( ""                 )
{
}

N::Algebra::Variable:: Variable    ( vrational value    )
                     : Element     (                    )
                     , Type        ( Cpp::Rational      )
                     , Value       ( QVariant ( value ) )
                     , TeX         ( ""                 )
                     , Description ( ""                 )
{
}

N::Algebra::Variable:: Variable    ( vcomplex value     )
                     : Element     (                    )
                     , Type        ( Cpp::VComplex      )
                     , TeX         ( ""                 )
                     , Description ( ""                 )
{
  QByteArray B                      ;
  double * vc                       ;
  B . resize ( sizeof(double) * 2 ) ;
  vc = (double *) B . data ( )      ;
  vc [ 0 ] = value.x                ;
  vc [ 1 ] = value.y                ;
  Value = QVariant ( B )            ;
}

N::Algebra::Variable:: Variable    ( vprecision value   )
                     : Element     (                    )
                     , Type        ( Cpp::VPrecision    )
                     , Value       ( QVariant ( value ) )
                     , TeX         ( ""                 )
                     , Description ( ""                 )
{
}

N::Algebra::Variable:: Variable    ( void * pointer )
                     : Element     (                )
                     , Type        ( Cpp::Pointer   )
                     , TeX         ( ""             )
                     , Description ( ""             )
{
  QByteArray B                                          ;
  B . resize ( sizeof(void *) )                         ;
  ::memcpy ( B . data ( ) , &pointer , sizeof(void *) ) ;
  Value = QVariant ( B )                                ;
}

N::Algebra::Variable:: Variable (const Variable & variable)
                     : Element  (                         )
{
  Type        = variable . Type        ;
  Value       = variable . Value       ;
  TeX         = variable . TeX         ;
  Description = variable . Description ;
}

N::Algebra::Variable::~Variable (void)
{
}

int N::Algebra::Variable::type (void) const
{
  return 1 ;
}

N::Algebra::Variable & N::Algebra::Variable::operator = (QString symbol)
{
  Type  = Cpp::Symbolic       ;
  Value = QVariant ( symbol ) ;
  return ME                   ;
}

N::Algebra::Variable & N::Algebra::Variable::operator = (char value)
{
  Type  = Cpp::Char          ;
  Value = QVariant ( value ) ;
  return ME                  ;
}

N::Algebra::Variable & N::Algebra::Variable::operator = (unsigned char value)
{
  Type  = Cpp::Byte          ;
  Value = QVariant ( value ) ;
  return ME                  ;
}

N::Algebra::Variable & N::Algebra::Variable::operator = (short value)
{
  Type  = Cpp::Short         ;
  Value = QVariant ( value ) ;
  return ME                  ;
}

N::Algebra::Variable & N::Algebra::Variable::operator = (unsigned short value)
{
  Type  = Cpp::UShort        ;
  Value = QVariant ( value ) ;
  return ME                  ;
}

N::Algebra::Variable & N::Algebra::Variable::operator = (int value)
{
  Type  = Cpp::Integer       ;
  Value = QVariant ( value ) ;
  return ME                  ;
}

N::Algebra::Variable & N::Algebra::Variable::operator = (unsigned int value)
{
  Type  = Cpp::UInt          ;
  Value = QVariant ( value ) ;
  return ME                  ;
}

N::Algebra::Variable & N::Algebra::Variable::operator = (long long value)
{
  Type  = Cpp::LongLong      ;
  Value = QVariant ( value ) ;
  return ME                  ;
}

N::Algebra::Variable & N::Algebra::Variable::operator = (unsigned long long value)
{
  Type  = Cpp::ULongLong     ;
  Value = QVariant ( value ) ;
  return ME                  ;
}

N::Algebra::Variable & N::Algebra::Variable::operator = (float value)
{
  Type  = Cpp::Float         ;
  Value = QVariant ( value ) ;
  return ME                  ;
}

N::Algebra::Variable & N::Algebra::Variable::operator = (double value)
{
  Type  = Cpp::Double        ;
  Value = QVariant ( value ) ;
  return ME                  ;
}

N::Algebra::Variable & N::Algebra::Variable::operator = (long double value)
{
  QByteArray B                                             ;
  B . resize ( sizeof(long double) )                       ;
  ::memcpy ( B . data ( ) , &value , sizeof(long double) ) ;
  Value = QVariant ( B )                                   ;
  Type  = Cpp::LDouble                                     ;
  return ME                                                ;
}

N::Algebra::Variable & N::Algebra::Variable::operator = (vlong value)
{
  Type  = Cpp::VLong         ;
  Value = QVariant ( value ) ;
  return ME                  ;
}

N::Algebra::Variable & N::Algebra::Variable::operator = (vdouble value)
{
  Type  = Cpp::VDouble       ;
  Value = QVariant ( value ) ;
  return ME                  ;
}

N::Algebra::Variable & N::Algebra::Variable::operator = (vrational value)
{
  Type  = Cpp::Rational      ;
  Value = QVariant ( value ) ;
  return ME                  ;
}

N::Algebra::Variable & N::Algebra::Variable::operator = (vcomplex value)
{
  QByteArray B                      ;
  double * vc                       ;
  B . resize ( sizeof(double) * 2 ) ;
  vc = (double *) B . data ( )      ;
  vc [ 0 ] = value.x                ;
  vc [ 1 ] = value.y                ;
  Value = QVariant ( B )            ;
  Type  = Cpp::VComplex             ;
  return ME                         ;
}

N::Algebra::Variable & N::Algebra::Variable::operator = (vprecision value)
{
  Type  = Cpp::VPrecision    ;
  Value = QVariant ( value ) ;
  return ME                  ;
}

N::Algebra::Variable & N::Algebra::Variable::operator = (void * pointer)
{
  QByteArray B                                          ;
  B . resize ( sizeof(void *) )                         ;
  ::memcpy ( B . data ( ) , &pointer , sizeof(void *) ) ;
  Value = QVariant ( B )                                ;
  Type  = Cpp::Pointer                                  ;
  return ME                                             ;
}

N::Algebra::Variable & N::Algebra::Variable::operator = (Variable & variable)
{
  setVariable ( variable ) ;
  return ME                ;
}

bool N::Algebra::Variable::operator == (Variable & variable)
{
  if ( Type  != variable.Type  ) return false ;
  if ( Value != variable.Value ) return false ;
  return true                                 ;
}

void N::Algebra::Variable::setVariable (Variable & variable)
{
  Type        = variable . Type        ;
  Value       = variable . Value       ;
  TeX         = variable . TeX         ;
  Description = variable . Description ;
}

QByteArray N::Algebra::Variable::toByteArray (void)
{
  QByteArray B      ;
  toByteArray ( B ) ;
  return B          ;
}

void N::Algebra::Variable::toByteArray (QByteArray & data)
{
  QByteArray              H                                                  ;
  QByteArray              V                                                  ;
  QByteArray              T                                                  ;
  QByteArray              D                                                  ;
  AlgebraVariablePacket * AVP                                                ;
  data . clear                (                               )              ;
  H    . resize               ( sizeof(AlgebraVariablePacket) )              ;
  T    = TeX         . toUtf8 (                               )              ;
  D    = Description . toUtf8 (                               )              ;
  AVP  = (AlgebraVariablePacket * ) H . data ( )                             ;
  #define CVT(TYPEX)                                                         \
    if (Value.canConvert<TYPEX>())                                         { \
      TYPEX vx = Value.value<TYPEX>()                                      ; \
      V.append((const char *)&vx,sizeof(TYPEX))                            ; \
    }                                                                        ;
  switch ( Type )                                                            {
    case Cpp::Void                                                           :
    break                                                                    ;
    case Cpp::Char                                                           :
      CVT ( char               )                                             ;
    break                                                                    ;
    case Cpp::Byte                                                           :
      CVT ( unsigned char      )                                             ;
    break                                                                    ;
    case Cpp::Short                                                          :
      CVT ( short              )                                             ;
    break                                                                    ;
    case Cpp::UShort                                                         :
      CVT ( unsigned short     )                                             ;
    break                                                                    ;
    case Cpp::Integer                                                        :
      CVT ( int                )                                             ;
    break                                                                    ;
    case Cpp::UInt                                                           :
      CVT ( unsigned int       )                                             ;
    break                                                                    ;
    case Cpp::LongLong                                                       :
      CVT ( long long          )                                             ;
    break                                                                    ;
    case Cpp::ULongLong                                                      :
      CVT ( unsigned long long )                                             ;
    break                                                                    ;
    case Cpp::Float                                                          :
      CVT ( float              )                                             ;
    break                                                                    ;
    case Cpp::Double                                                         :
      CVT ( double             )                                             ;
    break                                                                    ;
    case Cpp::LDouble                                                        :
      V = Value . toByteArray ( )                                            ;
    break                                                                    ;
    case Cpp::VLong                                                          :
      V = Value . toByteArray ( )                                            ;
    break                                                                    ;
    case Cpp::VDouble                                                        :
      V = Value . toByteArray ( )                                            ;
    break                                                                    ;
    case Cpp::Rational                                                       :
      V = Value . toByteArray ( )                                            ;
    break                                                                    ;
    case Cpp::VComplex                                                       :
    break                                                                    ;
    case Cpp::VPrecision                                                     :
      V = Value . toByteArray ( )                                            ;
    break                                                                    ;
    case Cpp::pADIC                                                          :
    break                                                                    ;
    case Cpp::Pointer                                                        :
      V = Value . toByteArray ( )                                            ;
    break                                                                    ;
    case Cpp::Symbolic                                                       :
      V = Value . toString ( ) . toUtf8 ( )                                  ;
    break                                                                    ;
  }                                                                          ;
  #undef  CVT
  AVP -> Type         = Type                                                 ;
  AVP -> Value        = V . size ( )                                         ;
  AVP -> TeX          = T . size ( )                                         ;
  AVP -> Description  = D . size ( )                                         ;
  if ( H . size ( ) > 0 ) data . append ( H )                                ;
  if ( V . size ( ) > 0 ) data . append ( V )                                ;
  if ( T . size ( ) > 0 ) data . append ( T )                                ;
  if ( D . size ( ) > 0 ) data . append ( D )                                ;
}

void N::Algebra::Variable::setByteArray (QByteArray & data)
{
  if ( data.size() < sizeof(AlgebraVariablePacket) ) return                  ;
  AlgebraVariablePacket * AVP = (AlgebraVariablePacket *) data . data ( )    ;
  unsigned char         * DTP = (unsigned char         *) data . data ( )    ;
  QByteArray              BLK                                                ;
  DTP  += sizeof(AlgebraVariablePacket)                                      ;
  Type  = AVP -> Type                                                        ;
  #define CVT(TYPEX)                                                         \
    Value = QVariant ( *( ( TYPEX * ) DTP ) ) ;                              \
    DTP  += sizeof   ( TYPEX                )
  switch ( Type )                                                            {
    case Cpp::Void                                                           :
      Value = QVariant ( )                                                   ;
    break                                                                    ;
    case Cpp::Char                                                           :
      CVT ( char               )                                             ;
    break                                                                    ;
    case Cpp::Byte                                                           :
      CVT ( unsigned char      )                                             ;
    break                                                                    ;
    case Cpp::Short                                                          :
      CVT ( short              )                                             ;
    break                                                                    ;
    case Cpp::UShort                                                         :
      CVT ( unsigned short     )                                             ;
    break                                                                    ;
    case Cpp::Integer                                                        :
      CVT ( int                )                                             ;
    break                                                                    ;
    case Cpp::UInt                                                           :
      CVT ( unsigned int       )                                             ;
    break                                                                    ;
    case Cpp::LongLong                                                       :
      CVT ( long long          )                                             ;
    break                                                                    ;
    case Cpp::ULongLong                                                      :
      CVT ( unsigned long long )                                             ;
    break                                                                    ;
    case Cpp::Float                                                          :
      CVT ( float              )                                             ;
    break                                                                    ;
    case Cpp::Double                                                         :
      CVT ( double             )                                             ;
    break                                                                    ;
    case Cpp::LDouble                                                        :
      BLK   . clear    (                                  )                  ;
      BLK   . append   ( (const char *)DTP , AVP -> Value )                  ;
      Value = QVariant ( BLK                              )                  ;
    break                                                                    ;
    case Cpp::VLong                                                          :
      BLK   . clear    (                                  )                  ;
      BLK   . append   ( (const char *)DTP , AVP -> Value )                  ;
      Value = QVariant ( BLK                              )                  ;
    break                                                                    ;
    case Cpp::VDouble                                                        :
      BLK   . clear    (                                  )                  ;
      BLK   . append   ( (const char *)DTP , AVP -> Value )                  ;
      Value = QVariant ( BLK                              )                  ;
    break                                                                    ;
    case Cpp::Rational                                                       :
      BLK   . clear    (                                  )                  ;
      BLK   . append   ( (const char *)DTP , AVP -> Value )                  ;
      Value = QVariant ( BLK                              )                  ;
    break                                                                    ;
    case Cpp::VComplex                                                       :
      BLK   . clear    (                                  )                  ;
      BLK   . append   ( (const char *)DTP , AVP -> Value )                  ;
      Value = QVariant ( BLK                              )                  ;
    break                                                                    ;
    case Cpp::VPrecision                                                     :
      BLK   . clear    (                                  )                  ;
      BLK   . append   ( (const char *)DTP , AVP -> Value )                  ;
      Value = QVariant ( BLK                              )                  ;
    break                                                                    ;
    case Cpp::pADIC                                                          :
    break                                                                    ;
    case Cpp::Pointer                                                        :
      BLK   . clear    (                                  )                  ;
      BLK   . append   ( (const char *)DTP , AVP -> Value )                  ;
      Value = QVariant ( BLK                              )                  ;
    break                                                                    ;
    case Cpp::Symbolic                                                       :
      BLK   . clear    (                                  )                  ;
      BLK   . append   ( (const char *)DTP , AVP -> Value )                  ;
      Value = QVariant ( QString::fromUtf8(BLK)           )                  ;
    break                                                                    ;
  }                                                                          ;
  #undef  CVT
  DTP += AVP->Value                                                          ;
  if ( AVP -> TeX         > 0 )                                              {
    BLK         . clear  (                                 )                 ;
    BLK         . append ( (const char *) DTP , AVP -> TeX )                 ;
    TeX         = QString::fromUtf8(BLK)                                     ;
    DTP        += AVP -> TeX                                                 ;
  }                                                                          ;
  if ( AVP -> Description > 0 )                                              {
    BLK         . clear  (                                         )         ;
    BLK         . append ( (const char *) DTP , AVP -> Description )         ;
    Description = QString::fromUtf8(BLK)                                     ;
    DTP        += AVP -> Description                                         ;
  }                                                                          ;
}
