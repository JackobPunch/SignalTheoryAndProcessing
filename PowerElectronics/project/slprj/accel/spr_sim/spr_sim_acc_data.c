#include "spr_sim_acc.h"
#include "spr_sim_acc_private.h"
P_spr_sim_T spr_sim_rtDefaultP = { 1.0 , 0.022222222222222445 , 0.0 , 0.0 ,
0.022222222222222445 , 0.0 , 0.0 , 0.0 , 2.2204460492503131E-16 , 1.0E+6 ,
2.2204460492503131E-16 , 1.0E+6 , 2.2204460492503131E-16 , { 1.0 , 0.0 , 0.5
, - 0.5 , 0.8660254037844386 , 0.5 , - 0.5 , - 0.8660254037844386 , 0.5 } ,
0.66666666666666663 , 0.02 , 1.0 , 0.02 , 0.0 , 2.0 , 1.0 , 2.0 , 0.0 , 0.0 ,
3.0 , 0.05 , 0.0 , 1.0 , 3.0 , 0.0 , - 1.0 , 2.0 , - 25.0 ,
0.017453292519943295 , 0.0 , 1.0 , { 0.0 , 0.0 , 0.0 } , { 0.0 , -
2.0943951023931953 , 2.0943951023931953 } , { 0.0 , 2.0943951023931953 , -
2.0943951023931953 } , 65.319726474218086 , 35.0 , 0.017453292519943295 , 2.0
, 1.0 , { 0.0 , 0.0 , 0.0 } , { 0.0 , - 2.0943951023931953 ,
2.0943951023931953 } , { 0.0 , 2.0943951023931953 , - 2.0943951023931953 } ,
48.989794855663554 , 0.017453292519943295 , 0.0 , 0.0 , 0.0 , 0.0 , { 0.0 ,
0.099999750000000026 , 0.099999750000000026 , 0.14999975000000002 ,
0.14999975000000002 , 0.19999975000000003 , 0.19999975000000003 , 1.19999975
} , { 1.0 , 1.0 , 0.8 , 0.8 , 1.2 , 1.2 , 1.0 , 1.0 } , 2.5E-7 , 0.0 , 2.0 ,
1.0 , 0.0 , 1.0 , 0.0 , 1.0 , 2.5E-7 , 0.0 , 0.0 , 0.5 , 6.2831853071795862 ,
0.5 , 2.0 , 0.0 , 3.0 , 4.0 , 0.0 , 0.0 , 4.0 , 1.0 , 4.0 , 2.0 , 0.0 , 1.0 ,
1.0 , 0.0 , 0.0 , 2.0 , 6.2831853071795862 , 10.0 , 0.5 , 0.3 , 0.0 , 0.5 ,
0.0 , { 9.0 , 9.0 } , { 0.65488589347184611 , - 3.9888475552099512E-17 , -
8.2629758070551507E-17 , - 0.41372147336796161 , 0.41372147336796161 , -
2.3737251313854513E-17 , 0.41372147336796156 , - 0.4137214733679615 , -
3.7879313401212311E-18 , 3.9881699288521477E-17 , 0.654885893471846 , -
8.2534890380459025E-17 , - 0.41372147336796161 , - 3.7913194719102483E-18 ,
0.4137214733679615 , 0.41372147336796156 , - 2.3744027577432547E-17 , -
0.4137214733679615 , 2.7547704069902285E-17 , - 5.5016351731394173E-17 ,
0.40391927464170807 , 0.23398654577361808 , 0.23398654577361805 ,
0.233986545773618 , 0.23398654577361805 , 0.233986545773618 ,
0.23398654577361802 , 0.00022984526298220088 , 0.00022984526298220085 , -
0.00058496636443404492 , 0.99912158230843606 , 0.00029296725467354244 ,
0.00029296725467354239 , - 0.00064857242858190655 , 0.000178044623182442 ,
0.000178044623182442 , - 0.00045969052596440166 , 0.00022984526298220083 , -
0.00058496636443404481 , 0.00029296725467354244 , 0.99912158230843606 ,
0.00029296725467354239 , 0.00017804462318244204 , - 0.00064857242858190644 ,
0.000178044623182442 , 0.0002298452629822008 , - 0.00045969052596440166 , -
0.00058496636443404471 , 0.00029296725467354244 , 0.00029296725467354239 ,
0.99912158230843584 , 0.00017804462318244202 , 0.000178044623182442 , -
0.00064857242858190644 , - 0.00022984526298220067 , - 0.00022984526298220091
, - 0.00058496636443404514 , - 0.00064857242858190676 ,
0.00017804462318244204 , 0.00017804462318244193 , 0.999121582308436 ,
0.00029296725467354233 , 0.00029296725467354244 , 0.0004596905259644016 , -
0.00022984526298220085 , - 0.00058496636443404481 , 0.00017804462318244204 ,
- 0.00064857242858190644 , 0.00017804462318244193 , 0.00029296725467354239 ,
0.99912158230843584 , 0.00029296725467354244 , - 0.00022984526298220088 ,
0.00045969052596440182 , - 0.00058496636443404492 , 0.00017804462318244202 ,
0.00017804462318244196 , - 0.00064857242858190633 , 0.00029296725467354244 ,
0.00029296725467354239 , 0.99912158230843606 } , { 9.0 , 15.0 } , { -
460150.216490366 , - 460150.21649036621 , 1.1711026615969578E+6 , -
2.2414077814886589E+6 , - 586520.44385643187 , - 586520.44385643175 ,
1.2984420020209767E+6 , - 356445.3356112488 , - 356445.33561124885 ,
920300.432980732 , - 460150.21649036603 , 1.1711026615969581E+6 , -
586520.44385643187 , - 2.2414077814886584E+6 , - 586520.44385643164 , -
356445.3356112488 , 1.2984420020209767E+6 , - 356445.33561124885 , -
460150.21649036626 , 920300.43298073264 , 1.1711026615969581E+6 , -
586520.443856432 , - 586520.44385643187 , - 2.2414077814886575E+6 , -
356445.33561124868 , - 356445.33561124868 , 1.2984420020209765E+6 ,
460150.21649036574 , 460150.21649036644 , 1.1711026615969585E+6 ,
1.298442002020977E+6 , - 356445.3356112488 , - 356445.33561124856 , -
2.2414077814886579E+6 , - 586520.44385643164 , - 586520.44385643187 , -
920300.432980732 , 460150.21649036609 , 1.1711026615969581E+6 , -
356445.3356112492 , 1.298442002020977E+6 , - 356445.33561124874 , -
586520.44385643222 , - 2.2414077814886575E+6 , - 586520.44385643187 ,
460150.21649036615 , - 920300.43298073229 , 1.1711026615969581E+6 , -
356445.33561124915 , - 356445.3356112488 , 1.2984420020209765E+6 , -
586520.44385643222 , - 586520.44385643175 , - 2.2414077814886575E+6 , -
1838.7621038576062 , - 1838.7621038576069 , 1.8351627605667833E-13 ,
919.38105192880334 , - 459.69052596440162 , - 459.69052596440162 , -
919.38105192880323 , 459.69052596440144 , 459.69052596440173 ,
3677.5242077152129 , - 1838.7621038576069 , - 9.1916250845159946E-14 , -
459.69052596440156 , 919.38105192880334 , - 459.69052596440173 ,
459.6905259644015 , - 919.38105192880312 , 459.69052596440173 , -
1838.7621038576069 , 3677.5242077152138 , - 9.1600025211518383E-14 , -
459.69052596440179 , - 459.69052596440179 , 919.38105192880334 ,
459.69052596440173 , 459.69052596440162 , - 919.38105192880346 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 }
, { 17.0 , 9.0 } , { - 5.1766899355166185E-5 , 5.1766899355166185E-5 ,
5.8512598989680346E-21 , 5.17668993551662E-5 , - 5.1766899355166171E-5 , -
4.7281803077594854E-22 , 0.0 , 0.0 , 0.0 , - 1.7255705326407689E-5 ,
1.7255705326407685E-5 , 2.5243146986819382E-21 , - 8.3170634364967967E-21 , -
1.0328719758818938E-23 , - 2.0686073668398076E-7 , 2.0686073668398076E-7 , -
4.9856359275388116E-24 , - 5.1766899355166191E-5 , - 4.7365885214825629E-22 ,
5.1766899355166178E-5 , 5.17668993551662E-5 , 2.9101879719400093E-21 , -
5.1766899355166171E-5 , 0.0 , 0.0 , 0.0 , - 1.7255705326407695E-5 , -
3.9956479091711708E-21 , 1.72557053264077E-5 , - 2.4347943963157759E-21 , -
1.0316861297557378E-23 , - 2.0686073668398076E-7 , 4.9856359275388116E-24 ,
2.0686073668398076E-7 , 2.9277566539923947E-5 , 2.9277566539923967E-5 ,
2.927756653992395E-5 , 2.9277566539923967E-5 , 2.927756653992395E-5 ,
2.9277566539923967E-5 , 0.0 , 0.0 , 0.0 , - 1.3760326124540195E-21 , -
1.3747315698470369E-21 , 2.7507641823010563E-21 , - 5.8555133079847927E-5 ,
1.7548990933021352E-7 , 3.4342950846425607E-24 , 3.4436124470623577E-24 , -
6.8779075317049192E-24 , 1.400879863430411E-7 , 3.665752774102696E-8 ,
3.6657527741027E-8 , - 8.1152625126311064E-8 , 2.2277833475703076E-8 ,
2.2277833475703043E-8 , 0.0 , 0.0 , 0.0 , 2.2984526298220089E-8 , -
1.1492263149110048E-8 , - 1.1492263149110045E-8 , - 5.8935361216730033E-8 , -
7.3120795554255641E-11 , - 5.7461315745550227E-11 , 2.8730657872775113E-11 ,
2.873065787277511E-11 , 3.6657527741026974E-8 , 1.400879863430411E-7 ,
3.6657527741026974E-8 , 2.2277833475703069E-8 , - 8.1152625126311077E-8 ,
2.2277833475703069E-8 , 0.0 , 0.0 , 0.0 , - 1.1492263149110048E-8 ,
2.2984526298220089E-8 , - 1.1492263149110045E-8 , - 5.8935361216730046E-8 , -
7.3120795554255628E-11 , 2.8730657872775097E-11 , - 5.7461315745550195E-11 ,
2.8730657872775097E-11 , 3.6657527741026993E-8 , 3.6657527741027007E-8 ,
1.400879863430411E-7 , 2.2277833475703069E-8 , 2.2277833475703053E-8 , -
8.1152625126311037E-8 , 0.0 , 0.0 , 0.0 , - 1.149226314911004E-8 , -
1.149226314911004E-8 , 2.2984526298220073E-8 , - 5.8935361216730053E-8 , -
7.312079555425559E-11 , 2.8730657872775091E-11 , 2.8730657872775097E-11 , -
5.7461315745550188E-11 , - 8.1152625126311011E-8 , 2.227783347570302E-8 ,
2.2277833475703043E-8 , 1.4008798634304104E-7 , 3.6657527741027E-8 ,
3.6657527741026974E-8 , 0.0 , 0.0 , 0.0 , - 2.2984526298220083E-8 ,
1.1492263149110035E-8 , 1.1492263149110046E-8 , - 5.8935361216730013E-8 , -
7.3120795554255654E-11 , 5.7461315745550182E-11 , - 2.8730657872775078E-11 ,
- 2.873065787277511E-11 , 2.2277833475703036E-8 , - 8.1152625126311011E-8 ,
2.2277833475703043E-8 , 3.6657527741027007E-8 , 1.4008798634304104E-7 ,
3.6657527741027E-8 , 0.0 , 0.0 , 0.0 , 1.1492263149110031E-8 , -
2.2984526298220079E-8 , 1.1492263149110046E-8 , - 5.8935361216730046E-8 , -
7.31207955542556E-11 , - 2.8730657872775097E-11 , 5.7461315745550195E-11 , -
2.8730657872775097E-11 , 2.2277833475703043E-8 , 2.2277833475703063E-8 , -
8.1152625126311024E-8 , 3.6657527741027013E-8 , 3.6657527741027E-8 ,
1.400879863430411E-7 , 0.0 , 0.0 , 0.0 , 1.1492263149110048E-8 ,
1.1492263149110048E-8 , - 2.2984526298220096E-8 , - 5.8935361216730059E-8 , -
7.3120795554255615E-11 , - 2.8730657872775113E-11 , - 2.8730657872775107E-11
, 5.746131574555022E-11 } , { 17.0 , 15.0 } , { - 280.45614865876826 , -
73.388370537536 , - 73.388370537535991 , 162.46755550287475 , -
44.600222618357471 , - 44.600222618357485 , 0.0 , 0.0 , 0.0 , -
46.015021649036612 , 23.007510824518306 , 23.007510824518306 ,
117.98859315589348 , 0.14638783269961972 , 0.11503755412259152 , -
0.057518777061295746 , - 0.057518777061295774 , - 73.388370537536 , -
280.4561486587682 , - 73.388370537536019 , - 44.60022261835752 ,
162.46755550287469 , - 44.600222618357513 , 0.0 , 0.0 , 0.0 ,
23.0075108245183 , - 46.0150216490366 , 23.0075108245183 , 117.98859315589354
, 0.14638783269961975 , - 0.057518777061295746 , 0.11503755412259149 , -
0.057518777061295753 , - 73.388370537536 , - 73.388370537536 , -
280.45614865876814 , - 44.6002226183575 , - 44.6002226183575 ,
162.46755550287466 , 0.0 , 0.0 , 0.0 , 23.007510824518317 , 23.00751082451832
, - 46.01502164903664 , 117.98859315589348 , 0.14638783269961975 , -
0.0575187770612958 , - 0.057518777061295781 , 0.11503755412259158 ,
162.46755550287475 , - 44.60022261835752 , - 44.600222618357485 , -
280.45614865876831 , - 73.388370537536048 , - 73.388370537536062 , 0.0 , 0.0
, 0.0 , 46.015021649036619 , - 23.0075108245183 , - 23.00751082451832 ,
117.98859315589355 , 0.1463878326996198 , - 0.11503755412259153 ,
0.057518777061295712 , 0.0575187770612958 , - 44.600222618357471 ,
162.46755550287469 , - 44.600222618357478 , - 73.388370537536048 , -
280.4561486587682 , - 73.388370537536048 , 0.0 , 0.0 , 0.0 , -
23.007510824518288 , 46.0150216490366 , - 23.007510824518313 ,
117.98859315589353 , 0.14638783269961972 , 0.057518777061295726 , -
0.11503755412259149 , 0.05751877706129576 , - 44.600222618357485 , -
44.60022261835752 , 162.46755550287466 , - 73.388370537536076 , -
73.388370537536034 , - 280.4561486587682 , 0.0 , 0.0 , 0.0 , -
23.007510824518313 , - 23.007510824518313 , 46.015021649036626 ,
117.98859315589355 , 0.14638783269961975 , 0.057518777061295767 ,
0.057518777061295767 , - 0.11503755412259153 , 0.11503755412259151 , -
0.057518777061295739 , - 0.05751877706129576 , - 0.11503755412259153 ,
0.057518777061295726 , 0.057518777061295746 , 1.0 , 0.0 , 0.0 ,
0.81612378961423926 , 0.091938105192880315 , 0.091938105192880343 ,
1.1946508703125076E-17 , 2.2939534507084789E-20 , 0.0004596905259644016 , -
0.00022984526298220077 , - 0.00022984526298220085 , - 0.057518777061295739 ,
0.11503755412259151 , - 0.057518777061295739 , 0.057518777061295753 , -
0.11503755412259148 , 0.057518777061295746 , 0.0 , 1.0 , 0.0 ,
0.091938105192880315 , 0.81612378961423926 , 0.091938105192880343 , -
1.5777036085197572E-17 , - 1.1489531355644993E-20 , - 0.00022984526298220075
, 0.0004596905259644016 , - 0.00022984526298220085 , - 0.057518777061295781 ,
- 0.05751877706129576 , 0.11503755412259151 , 0.057518777061295774 ,
0.057518777061295753 , - 0.11503755412259149 , 0.0 , 0.0 , 1.0 ,
0.091938105192880343 , 0.091938105192880357 , 0.81612378961423937 ,
3.8305273820724955E-18 , - 1.1450003151439797E-20 , - 0.00022984526298220085
, - 0.00022984526298220085 , 0.00045969052596440171 , - 1.0 , 0.0 , 0.0 , 0.0
, 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0
, 0.0 , - 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0
, 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , -
1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0
, 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , - 1.0 , 0.0 ,
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 } , { 9.0 , 1.0 } ,
{ - 109421.81724391365 , - 95471.379734641989 , 1.1641532182693481E-10 , -
5.1275195350919552E+7 , - 1.1039978020208087E+9 , 1.1552729973717296E+9 ,
5.1275195350919671E+7 , 1.1039978020208089E+9 , - 1.1552729973717296E+9 } ,
0.0 , 0.0 , 0.0 , { 5.7595865315812871 , 4.71238898038469 ,
3.6651914291880927 , 2.6179938779914944 , 1.5707963267948966 ,
0.52359877559829882 } , 6.2831853071795862 , 57.295779513082323 , 0.0 , 5.0 ,
1.0 , 0.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0 ,
1.0 , 3.1415926535897931 , 50.0 , 314.15926535897933 , 0.0 , 0.0 ,
0.022222222222222445 , 0.0 , 0.0 , 180.0 , 3200.0 , 1.0 , - 10000.0 , -
1.0E+8 , 10000.0 , 0.0 , 0.0 , 0.15915494309189535 , 12.0 , - 12.0 ,
0.0020264236728467556 , 0.0 , 0.0 , 1.0 , - 24674.011002723397 , -
222.11060060879836 , 0.0 , 1.0 , 24674.011002723397 , 0.0 , 0.0 , 1.0E+6 ,
2.2204460492503131E-16 , { 1.0 , 0.0 , 0.5 , - 0.5 , 0.8660254037844386 , 0.5
, - 0.5 , - 0.8660254037844386 , 0.5 } , 0.66666666666666663 , 1.0 , 1.0 , {
0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 } , 1.5 , 1.5 , 1.5 , 1.5 , 1.5 , 1.5 , 0.0
, 1.0 , 6.2831853071795862 , 0.02 , 0.0 , 2.0 , 1.0 , 2.0 , 50.0 ,
6.2831853071795862 , 0.0 , 0.017453292519943295 , { 0.0 , -
2.0943951023931953 , 2.0943951023931953 } , 0.0 , 326.59863237109039 , false
, { 'a' , 'a' , 'a' , 'a' , 'a' , 'a' , 'a' } , { { 0.0 , 0.0 } } , { { 0.0 ,
0.0 } } , { { 0.0 , 0.0 } } , { { 0.0 , 0.0 } } } ;