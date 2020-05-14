//
//  XKXAdConfigModel.h
//  DSPAdSDKDemo
//
//  Created by 王云龙 on 2019/11/9.
//  Copyright © 2019 上海麒鎏信息科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 侠客行广告配置模型基类
 *
 * @class XKXAdConfigModel
 * @abstract 侠客行广告配置模型基类
*/

@interface XKXAdConfigModel : NSObject
//请求广告位的reqtagid
@property (nonatomic,copy)NSString * reqTagId;
//媒体id
@property (nonatomic,copy)NSString * mediaId;
//广告位id
@property (nonatomic,copy)NSString * posId;
//初始化uuid
@property (nonatomic,copy)NSString * uuid;
/** 广告整体宽度（必填，不设置无法正常显示广告） */
@property (nonatomic, assign) CGFloat width;
/** 广告整体高度（必填，不设置无法正常显示广告） */
@property (nonatomic, assign) CGFloat height;
/** 设置超时时间 超时时间范围0-10s，超过10秒——默认为10秒（必填项，所有广告设置请求的超时时长，不设置默认取后台设定的超时时长） */
@property (nonatomic, assign) NSTimeInterval timeout;

@end

/**
 * 侠客行开屏广告配置模型类
 *
 * @class XKXSplashAdConfigModel
 * @abstract 开屏广告数据模型在基础模型之上添加底部视图adBottomView（可选）及开屏展示时的adWindow（必须传递）
*/

@interface XKXSplashAdConfigModel : XKXAdConfigModel
/**
 * 将获取的广告以半屏形式展示在adWindow的上半部，剩余部分展示传入的adBottomView
   请注意adBottomView需设置好宽高，所占的空间不能过大，并保证高度不超过屏幕高度的 25%
   可选参数
 */
@property (nonatomic,strong)UIView * _Nullable adBottomView;
/**
 * adWindow 广告加载成功时展示的window(必传参数)
*/
@property (nonatomic,strong)UIWindow * adWindow;
@end

//========================↓↓↓↓ 信息流模板广告模型（参数配置模型子类，支持多个对象，多条广告初始化） ↓↓↓↓========================

@interface XKXNativeTempAdModel : XKXAdConfigModel

/** 信息流模板广告条数（非必填，不设置默认是1条） */
@property (nonatomic, assign) NSInteger adCount;
/** 信息流模板广告的左边距（非必填，不设置默认是0，即没有左边距）*/
@property (nonatomic, assign) CGFloat adLeading;
/** 信息流模板广告的右边距（非必填，不设置默认是0，即没有右边距） */
@property (nonatomic, assign) CGFloat adTrailing;

@end

//========================↑↑↑↑ 信息流模板广告模型（参数配置模型子类，支持多个对象，多条广告初始化） ↑↑↑↑========================


NS_ASSUME_NONNULL_END
