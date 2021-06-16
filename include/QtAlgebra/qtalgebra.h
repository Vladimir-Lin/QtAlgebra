/****************************************************************************
 *                                                                          *
 * Copyright (C) 2015 Neutrino International Inc.                           *
 *                                                                          *
 * Author : Brian Lin <lin.foxman@gmail.com>, Skype: wolfram_lin            *
 *                                                                          *
 * Qt Version   : 5.4.1                                                     *
 * CIOS Version : 1.6.0                                                     *
 *                                                                          *
 ****************************************************************************/

#ifndef QT_ALGEBRA_H
#define QT_ALGEBRA_H

#include <QtCore>
#include <Essentials>
#include <QtGMP>
#include <QtGSL>

QT_BEGIN_NAMESPACE

#ifndef QT_STATIC
#  if defined(QT_BUILD_QTALGEBRA_LIB)
#    define Q_ALGEBRA_EXPORT Q_DECL_EXPORT
#  else
#    define Q_ALGEBRA_EXPORT Q_DECL_IMPORT
#  endif
#else
#    define Q_ALGEBRA_EXPORT
#endif

namespace N
{

namespace Algebra
{

class Q_ALGEBRA_EXPORT Element  ;
class Q_ALGEBRA_EXPORT Variable ;

class Q_ALGEBRA_EXPORT Element
{
  public:

    explicit Element (void) ;
    virtual ~Element (void) ;

    virtual int type (void) const = 0 ;

  protected:

  private:

};

class Q_ALGEBRA_EXPORT Variable : public Element
{
  public:

    int      Type        ;
    QVariant Value       ;
    QString  TeX         ;
    QString  Description ;

    explicit   Variable     ( void                        ) ;
               Variable     ( QString            symbol   ) ;
               Variable     ( char               value    ) ;
               Variable     ( unsigned char      value    ) ;
               Variable     ( short              value    ) ;
               Variable     ( unsigned short     value    ) ;
               Variable     ( int                value    ) ;
               Variable     ( unsigned int       value    ) ;
               Variable     ( long long          value    ) ;
               Variable     ( unsigned long long value    ) ;
               Variable     ( float              value    ) ;
               Variable     ( double             value    ) ;
               Variable     ( long double        value    ) ;
               Variable     ( vlong              value    ) ;
               Variable     ( vdouble            value    ) ;
               Variable     ( vrational          value    ) ;
               Variable     ( vcomplex           value    ) ;
               Variable     ( vprecision         value    ) ;
               Variable     ( void             * pointer  ) ;
               Variable     ( const Variable   & variable ) ;
    virtual   ~Variable     ( void                        ) ;

    virtual int type        (void) const ;

    Variable & operator =   (QString symbol) ;
    Variable & operator =   (char value) ;
    Variable & operator =   (unsigned char value) ;
    Variable & operator =   (short value) ;
    Variable & operator =   (unsigned short value) ;
    Variable & operator =   (int value) ;
    Variable & operator =   (unsigned int value) ;
    Variable & operator =   (long long value) ;
    Variable & operator =   (unsigned long long value) ;
    Variable & operator =   (float value) ;
    Variable & operator =   (double value) ;
    Variable & operator =   (long double value) ;
    Variable & operator =   (vlong value) ;
    Variable & operator =   (vdouble value) ;
    Variable & operator =   (vrational value) ;
    Variable & operator =   (vcomplex value) ;
    Variable & operator =   (vprecision value) ;
    Variable & operator =   (void * pointer) ;
    Variable & operator =   (Variable & variable) ;

    bool       operator ==  (Variable & variable) ;
    void       setVariable  (Variable & variable) ;

    QByteArray toByteArray  (void) ;
    void       toByteArray  (QByteArray & data) ;
    void       setByteArray (QByteArray & data) ;

  protected:

  private:

};

}

}

QT_END_NAMESPACE

Q_DECLARE_METATYPE(N::Algebra::Variable)

Q_DECLARE_INTERFACE(N::Algebra::Element , "com.neutrino.math.element" )

#endif
