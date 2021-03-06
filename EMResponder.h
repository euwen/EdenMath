//
//  EMResponder.h
//  EdenMath
//
//  Created by admin on Thu Feb 21 2002.
//  Copyright (c) 2002-2013 Edenwaith. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>

typedef enum Op_Type 
{
    NO_OP		= 0,
    ADD_OP		= 1,
    SUBTRACT_OP = 2,
    MULTIPLY_OP = 3, 
    DIVIDE_OP 	= 4,       
    EXPONENT_OP = 5,
    XROOT_OP 	= 6,
    MOD_OP		= 7,
    EE_OP		= 8,
    NPR_OP		= 9,
    NCR_OP		= 10
} OpType;

typedef enum Angle_Type
{
    DEGREE		= 0,
    RADIAN		= 1,
    GRADIENT 	= 2
} AngleType;

@interface EMResponder : NSObject 
{
    double currentValue;		// the current number (which is being edited)
    double previousValue;		// the other operand (previous operand)
    double eValue;				// the number e
    OpType opType;		        // the current operator
    AngleType angleType;	   	// type of angle used (radian, degree, gradient)
    int trailingDigits;			// used in decimal number input
    BOOL isNewDigit;           	// allow new number in display
}

// class method prototypes

- (double)getCurrentValue;
- (int)getTrailingDigits;
- (void)setCurrentValue:(double)num;
- (void)setState:(NSDictionary *)stateDictionary;
- (NSDictionary *)state;

- (void)newDigit:(int)digit;
- (void)period;
- (void)pi;
- (void)trigConstant: (double) trigConst;
- (void)e;

- (void)clear;
- (void)operation:(OpType)newOpType;
- (void)enter;

// Algebraic functions
- (void)reverseSign;
- (void)percentage;

- (void)squared;
- (void)cubed;
- (void)squareRoot;
- (void)cubedRoot;
- (void)ln;
- (void)binaryLogarithm;
- (void)logarithm;
- (void)factorial;
- (double) factorial: (double) n;

- (void)powerE;
- (void)power2;
- (void)power10;
- (void)inverse;

// Trigometric functions
- (void)setAngleType:(AngleType)aType;
- (double)degToRad:(double)degrees;
- (double)radToDeg:(double)radians;
- (double)gradToRad:(double)gradients;
- (double)radToGrad:(double)radians;
- (void)sine;
- (void)cosine;
- (void)tangent;
- (void)arcsine;
- (void)arccosine;
- (void)arctangent;

// Probability functions
- (double)generateRandomNum;
- (void)randomNum;


@end
