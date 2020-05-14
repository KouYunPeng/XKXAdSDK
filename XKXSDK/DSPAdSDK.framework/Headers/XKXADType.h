//
//  XKXADType.h
//  DSPAdSDK
//
//  Created by 王云龙 on 2019/11/19.
//  Copyright © 2019 上海麒鎏信息科技有限公司. All rights reserved.
//

#ifndef XKXADType_h
#define XKXADType_h
/**
 * 广告类型枚举,用户各种广告类型的回掉中，告知用户广告类型。
 */

typedef NS_ENUM(NSInteger, XKXADType)
{
    //未定义类型
    XKXADTypeUndefined   = 0,
    //自渲染
    XKXADTypeNMG         = -1,
    //百度广告
    XKXADTypeBaidu       = 1,
    //广点通
    XKXADTypeGDT         = 2,
    //穿山甲
    XKXADTypeCSJ         = 3,
};

#endif /* XKXADType_h */
