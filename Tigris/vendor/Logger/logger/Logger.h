#pragma once

#define tprint(fc,bc,message,...) printf("\033[1;"bc";"fc"m"message"\033[0m",__VA_ARGS__)
#define _fBlack           "30"  
#define _fRed             "31"  
#define _fGreen           "32"  
#define _fYellow          "33"  
#define _fBlue            "34"  
#define _fMagenta         "35"  
#define _fCyan            "36"  
#define _fWhite           "37"  
#define _fBright Black    "90"  
#define _fBright Red      "91"  
#define _fBright Green    "92"  
#define _fBright Yellow   "93"  
#define _fBright Blue     "94"  
#define _fBright Magenta  "95"  
#define _fBright Cyan     "96"  
#define _fBright White    "97"    
#define _bBlack           "40"  
#define _bRed             "41"  
#define _bGreen           "42"  
#define _bYellow          "43"  
#define _bBlue            "44"  
#define _bMagenta         "45"  
#define _bCyan            "46"  
#define _bWhite           "47"  
#define _bBright Black    "100"  
#define _bBright Red      "101"  
#define _bBright Green    "102"  
#define _bBright Yellow   "9103"  
#define _bBright Blue     "104"  
#define _bBright Magenta  "105"  
#define _bBright Cyan     "106"  
#define _bBright White    "107" 


#define print0(message,...) tprint(_fWhite,_bBlack,message,__VA_ARGS__)
#define print1(message,...) tprint(_fGreen,_bBlack,message,__VA_ARGS__)
#define print2(message,...) tprint(_fYellow,_bBlack,message,__VA_ARGS__)
#define print3(message,...) tprint(_fCyan,_bBlack,message,__VA_ARGS__)
#define print4(message,...) tprint(_fWhite,_bRed,message,__VA_ARGS__)