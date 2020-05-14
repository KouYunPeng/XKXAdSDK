//
//  ConfigModel.h
//  DSPAdSDK
//
//  Created by 寇云鹏 on 2019/10/8.
//  Copyright © 2019 上海麒鎏信息科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

/** 焦点图广告视图位置枚举（只针对logo及广告字样） */
typedef NS_ENUM(NSInteger, AdViewLocation) {
    adViewNone = 0,     // 隐藏
    adViewTopLeft,      // 相对于广告左上角
    adViewTopRight,     // 相对于广告右上角
    adViewBottomLeft,   // 相对于广告左下角
    adViewBottomRight   // 相对于广告右下角
};
typedef enum NativeTemplateAdStyle {
    NativeTemplateDefaultStyle = 0,
    NativeTemplateAnimationStyle = 1,
} NativeTemplateAdStyle;

NS_ASSUME_NONNULL_BEGIN

//========================↓↓↓↓ 参数配置模型 ↓↓↓↓========================

/**
 * 参数配置模型
 *
 * @class ConfigModel
 * @abstract 当客户端初始化广告时，设置广告需要的参数配置模型
 */
@interface ConfigModel : NSObject

/** 请求广告位的reqTagid（必填，所有广告请求需要的广告位id，不设置会以错误回调的方式提示用户广告展示失败） */
@property (nonatomic, copy) NSString *reqTagId;
/** 媒体id（非必填，媒体id和广告位id同时存在的时候，作用和requTagid是一样的） */
@property (nonatomic, copy) NSString *mediaId;
/** 广告位id（非必填，媒体id和广告位id同时存在的时候，作用和requTagid是一样的） */
@property (nonatomic, copy) NSString *posId;
/** 客户端传递的参数uuid（非必填，sdk内部叫流程id） */
@property (nonatomic, copy) NSString *processId;
/** 广告整体宽度（必填，不设置无法正常显示广告） */
@property (nonatomic, assign) CGFloat width;
/** 广告整体高度（必填，不设置无法正常显示广告） */
@property (nonatomic, assign) CGFloat height;
/** 设置超时时间 超时时间范围0-10s，超过10秒——默认为10秒（必填项，所有广告设置请求的超时时长，不设置默认取后台设定的超时时长） */
@property (nonatomic, assign) NSTimeInterval timeout;

@end

//========================↑↑↑↑ 参数配置模型 ↑↑↑↑========================


//========================↓↓↓↓ 焦点图广告模型（参数配置模型子类） ↓↓↓↓========================

@interface XKXFocusAdModel : ConfigModel

/** 焦点图广告视图frame（必填，广告视图是广告图片和标题的父视图，改变广告整体大小，其他视图可以相对于该广告视图做自适应布局） */
@property (nonatomic, assign)CGRect focusAdViewFrame;
/** 焦点图广告图片frame (必填，不设置无法正常显示焦点图的广告图片)*/
@property (nonatomic, assign)CGRect focusImageFrame;
/** 焦点图广告标题frame（必填，不设置无法正常显示广告标题） */
@property (nonatomic, assign)CGRect focusTitleFrame;
/** 焦点图广告标题字体大小（非必填，不设置是系统默认的字体大小） */
@property (nonatomic, strong)UIFont *focusTitleFont;
/** 焦点图广告标题字体颜色（非必填，不设置默认是黑色） */
@property (nonatomic, strong)UIColor *focusTitleColor;
/** 焦点图广告标题背景颜色（非必填，不设置默认无背景色） */
@property (nonatomic, strong)UIColor *focusTitleBgColor;
/** 焦点图广告标题内容显示行数（非必填，不设置默认显示一行内容） */
@property (nonatomic, assign)NSInteger numberOfLines;
/** 焦点图广告标题水平对齐方式（非必填，不设置默认是水平方向左对齐） */
@property (nonatomic, assign)NSTextAlignment focusTitleAlignment;
/** 焦点图广告子视图(焦点图的广告字样)相对于广告视图的位置，枚举（非必填，不设置默认是隐藏状态） */
@property (nonatomic, assign)AdViewLocation focusAdLocation;
/** 焦点图广告子视图(焦点图的logo)相对于广告视图的位置，枚举（非必填，不设置默认是隐藏状态）*/
@property (nonatomic, assign)AdViewLocation focusLogoLocation;

@end

//========================↑↑↑↑ 焦点图广告模型（参数配置模型子类） ↑↑↑↑========================


//========================↓↓↓↓ 信息流模板广告模型（参数配置模型子类，支持多个对象，多条广告初始化） ↓↓↓↓========================

@interface XKXNativeTemplateAdModel : ConfigModel

/** 信息流模板广告条数（非必填，不设置默认是1条） */
@property (nonatomic, assign) NSInteger adCount;
/** 信息流模板广告的左边距（非必填，不设置默认是0，即没有左边距）*/
@property (nonatomic, assign) CGFloat adLeading;
/** 信息流模板广告的右边距（非必填，不设置默认是0，即没有右边距） */
@property (nonatomic, assign) CGFloat adTrailing;
/** 信息流模板广告的广告样式 */
@property (nonatomic,assign) NativeTemplateAdStyle adStyle;
/** 信息流模板广告的边框颜色 只针对于adStyle 为NativeTemplateAnimationStyle 的时候 */
@property (nonatomic,assign) UIColor * adMarginColor;

@end

//========================↑↑↑↑ 信息流模板广告模型（参数配置模型子类，支持多个对象，多条广告初始化） ↑↑↑↑========================


//========================↓↓↓↓ 信息流原生广告模型（参数配置模型子类，支持多个对象，多条广告初始化） ↓↓↓↓========================

@interface XKXNativeAdModel : ConfigModel

/** 信息流原生广告条数（非必填，不设置默认是1条） */
@property (nonatomic, assign) NSInteger adCount;

@end

//========================↑↑↑↑ 信息流原生广告模型（参数配置模型子类，支持多个对象，多条广告初始化） ↑↑↑↑========================


NS_ASSUME_NONNULL_END
